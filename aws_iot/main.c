#include "mxos.h"

#define app_log(M, ...)       MXOS_LOG(CONFIG_APP_DEBUG, "iot", M, ##__VA_ARGS__)

#ifndef USE_AUTO_WIFI_CONFIG
#define SSID "GP_01"
#define PASSPHRASE "1234567890"
#else
#endif

extern merr_t start_aws_iot_shadow( void );

static mos_semphr_id_t wait_sem = NULL;

/* MICO system callback: Restore default configuration provided by application */
void appRestoreDefault_callback( void * const user_config_data, uint32_t size )
{
    memset( user_config_data, 0x0, size );
}

static void micoNotify_WifiStatusHandler( WiFiEvent status, void* const inContext )
{
    switch ( status )
    {
        case NOTIFY_STATION_UP:
            if( wait_sem != NULL ){
                mos_semphr_release( wait_sem );
            }
            break;
        case NOTIFY_STATION_DOWN:
            case NOTIFY_AP_UP:
            case NOTIFY_AP_DOWN:
            break;
    }
}

int main( void )
{
    merr_t err = kNoErr;

    wait_sem = mos_semphr_new(1);

    /*Register user function for MiCO nitification: WiFi status changed */
    err = mxos_system_notify_register(mxos_notify_WIFI_STATUS_CHANGED,
                                      (void *)micoNotify_WifiStatusHandler, NULL);
    require_noerr(err, exit);

    /* Start MiCO system functions according to mxos_config.h */
    err = mxos_system_init();
    require_noerr(err, exit);

#ifndef USE_AUTO_WIFI_CONFIG
    app_log("Use WiFi SSID set in module");
    app_log("connecting to %s...", SSID);
    mwifi_connect(SSID, PASSPHRASE, strlen(PASSPHRASE), NULL, NULL);
#else
    app_log("Use default auto wifi config");
#endif
    /* Wait for wlan connection*/
    mos_semphr_acquire(wait_sem, MOS_WAIT_FOREVER);
    app_log("wifi connected successful");

    start_aws_iot_shadow();

    exit:
    mxos_system_notify_remove( mxos_notify_WIFI_STATUS_CHANGED,
                               (void *) micoNotify_WifiStatusHandler );
    mos_semphr_delete( wait_sem );
    mos_thread_delete( NULL );
    return err;
}

