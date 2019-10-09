/**
 ******************************************************************************
 * @file    mico_config.h
 * @author  
 * @version V1.0.0
 * @date    
 * @brief   This file provide constant definition and type declaration for MICO
 *          running.
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2016 MXCHIP Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ******************************************************************************
 */

#ifndef __MXOS_CONFIG_H__
#define __MXOS_CONFIG_H__

/**
 *  USE_AUTO_WIFI_CONFIG: define if need to use wifi configure with mobile APP
 */
#define USE_AUTO_WIFI_CONFIG

#ifndef USE_AUTO_WIFI_CONFIG
#define MXOS_WLAN_CONNECTION_ENABLE              0
#define MXOS_WLAN_AUTO_CONFIG                    0
#else
#define MXOS_WLAN_AUTO_CONFIG                    1
/**
 *  WIFI_CONFIG_MODE: wlan configuration mode, Default: EasyLink
 */
#define WIFI_CONFIG_MODE                   WIFI_CONFIG_MODE_AWS
/**
 *  EasyLink_TimeOut: Easylink configuration timeout, Default: 60 secs
 */
#define EasyLink_TimeOut                        60000
/**
 *  EasyLink_ConnectWlan_Timeout: Connect to wlan after wlan is configured
 *  Restart wlan configuration mode after timeout. Default: 20 seconds.
 */
#define EasyLink_ConnectWlan_Timeout            20000 
#endif

#endif