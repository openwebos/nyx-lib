/* @@@LICENSE
*
*      Copyright (c) 2013 LG Electronics, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */

/**
 * @file nyx_security_common.h
 *
 */


#ifndef _NYX_SECURITY_COMMON_H_
#define _NYX_SECURITY_COMMON_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_security_public Security
* @ingroup nyx_public
* @brief Nyx's public security API.
* @{
*/

/**
 * @brief AES cipher block modes
 */
typedef enum {
	NYX_SECURITY_AES_ECB,
	NYX_SECURITY_AES_CBC,
	NYX_SECURITY_AES_OFB,
	NYX_SECURITY_AES_CFB,
	NYX_SECURITY_AES_CTR
}
nyx_security_aes_block_mode_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_security_COMMON_H_ */

