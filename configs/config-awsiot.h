/*
 *  Minimal configuration for TLS 1.2 with PSK and AES-CCM ciphersuites
 *
 *  Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */
/*
 * Minimal configuration for TLS 1.2 with PSK and AES-CCM ciphersuites
 * Distinguishing features:
 * - no bignum, no PK, no X509
 * - fully modern and secure (provided the pre-shared keys have high entropy)
 * - very low record overhead with CCM-8
 * - optimized for low RAM usage
 *
 * See README.txt for usage instructions.
 */
#ifndef __MBEDTLS_CONFIG_H__
#define __MBEDTLS_CONFIG_H__


/* System support */
//#define MBEDTLS_HAVE_TIME /* Optionally used in Hello messages */
/* Other MBEDTLS_HAVE_XXX flags irrelevant for this configuration */
//#define MBEDTLS_DEBUG_C
//#define MBEDTLS_PLATFORM_C

/* mbed TLS feature support */
#define MBEDTLS_CIPHER_MODE_CBC
#define MBEDTLS_PKCS1_V15
#define MBEDTLS_KEY_EXCHANGE_RSA_ENABLED
#define MBEDTLS_SSL_PROTO_TLS1_2

/* mbed TLS modules */
#define MBEDTLS_AES_C
#define MBEDTLS_AES_ALT
#define MBEDTLS_ASN1_PARSE_C
#define MBEDTLS_BIGNUM_C
#define MBEDTLS_CIPHER_C
//#define MBEDTLS_CTR_DRBG_C
//#define MBEDTLS_ENTROPY_C
#define MBEDTLS_MD_C
#define MBEDTLS_MD5_C
//#define MBEDTLS_NET_C
#define MBEDTLS_OID_C
#define MBEDTLS_SHA1_C
#define MBEDTLS_SHA1_ALT
#define MBEDTLS_SHA256_C
#define MBEDTLS_SHA256_ALT
#define MBEDTLS_PK_C
#define MBEDTLS_PK_PARSE_C
#define MBEDTLS_RSA_C
#define MBEDTLS_RSA_ALT
#define MBEDTLS_SSL_CLI_C
// #define MBEDTLS_SSL_SRV_C
#define MBEDTLS_SSL_TLS_C
#define MBEDTLS_X509_CRT_PARSE_C
#define MBEDTLS_X509_USE_C
//#define MBEDTLS_BASE64_C
#define MBEDTLS_CERTS_C
//#define MBEDTLS_PEM_PARSE_C

/* Save RAM at the expense of ROM */
//#define MBEDTLS_AES_ROM_TABLES

/* Save some RAM by adjusting to your exact needs */
#define MBEDTLS_PSK_MAX_LEN    16 /* 128-bits keys are generally enough */

/*
 * You should adjust this to the exact number of sources you're using: default
 * is the "platform_entropy_poll" source, but you may want to add other ones
 * Minimum is 2 for the entropy test suite.
 */
//#define MBEDTLS_ENTROPY_MAX_SOURCES 128

/*
 * Use only CCM_8 ciphersuites, and
 * save ROM and a few bytes of RAM by specifying our own ciphersuite list
 */
#define MBEDTLS_SSL_CIPHERSUITES  \
        MBEDTLS_TLS_RSA_WITH_AES_256_CBC_SHA

/*
 * Save RAM at the expense of interoperability: do this only if you control
 * both ends of the connection!  (See comments in "mbedtls/ssl.h".)
 * The optimal size here depends on the typical size of records.
 */
#define MBEDTLS_SSL_MAX_CONTENT_LEN             (3 * 1024)
//#define MBEDTLS_DEBUG_C
#if !defined (MBEDTLS_DEBUG_C)
 /*reduce readonly date size*/
#define CK_REMOVE_UNUSED_FUNCTION_AND_DATA
#endif

#include "mbedtls/check_config.h"

#endif /* MBEDTLS_CONFIG_H */
