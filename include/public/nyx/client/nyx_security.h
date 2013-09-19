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
 * @file nyx_security.h
 *
 */

/**
 * @brief Nyx's public API for accessing security module
 *
 */

#ifndef _NYX_SECURITY_H_
#define _NYX_SECURITY_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_security_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nyx_security_public Security
 * @ingroup nyx_public
 * @{
 */

/**
 * @defgroup nyx_security_aes AES
 * @ingroup nyx_security_public
 * @{
 */

/**
 * @brief Create AES key
 *
 * @param[in] handle - handle to the device
 * @param[in] keylen - key length in bits (128, 256, ...)
 * @param[in,out] key_index - index to key
 *                in: -1: device assign new index, >=0 overwrite existing index)
 *                out: device assigned index
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_create_aes_key(nyx_device_handle_t handle, int keylen,
                            int *key_index);

/**
 * @brief Encrypt/decrypt data
 *
 * Encryption is required to generate IV and return it at front of dest buffer.
 * Decryption requires that IV is at front of src buffer.
 * Destination buffer size need to have space for encrypted data + IV + block size of used cipher.
 *
 * @param[in] handle - handle to the device
 * @param[in] encrypt - encrypt != 0, decrypt = 0
 * @param[in] key_index - index to key
 * @param[in] mode - block cipher mode
 * @param[in] src - buffer to crypt
 * @param[in] srclen - length of src buffer (includes IV in decrypt)
 * @param[in] dest - crypted data
 * @param[out] destlen - length of crypted data (includes IV in encrypt)
 * @param[in,out] ivlen - length of IV
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_crypt_aes(nyx_device_handle_t handle, int key_index,
                       nyx_security_aes_block_mode_t mode, int encrypt, const char *src, int srclen,
                       char *dest, int *destlen, int *ivlen);

/** @} */

/**
 * @defgroup nyx_security_rsa RSA
 * @ingroup nyx_security_public
 * @{
 */

/**
 * @brief Create RSA key
 *
 * @param[in] handle - handle to the device
 * @param[in] keylen - length of RSA key (1024, 2048, 4096, ...)
 * @param[in,out] key_index - index to key
 *                in: -1: device assign new index, >=0 overwrite existing index)
 *                out: device assigned index
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_create_rsa_key(nyx_device_handle_t handle, int keylen,
                            int *key_index);

/**
 * @brief Encrypt/decrypt data
 *
 * @param[in] handle - handle to the device
 * @param[in] encrypt - encrypt != 0, decrypt = 0
 * @param[in] key_index - index to key
 * @param[in] src - buffer to crypt
 * @param[in] srclen - length of src buffer
 * @param[in] dest - crypted data
 * @param[out] destlen - length of crypted data
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_crypt_rsa(nyx_device_handle_t handle, int key_index, int encrypt,
                       const char *src, int srclen, char *dest, int *destlen);

/** @} */

/**
 * @defgroup nyx_security_hash Hash
 * @ingroup nyx_security_public
 * @{
 */

/**
 * @brief Calculate hash from given buffer to memory
 *
 * @param[in] handle - handle to the device
 * @param[in] hash_algo - hash algorithm type (as in openssl/obj_mac.h)
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_init_hash(nyx_device_handle_t handle, const char *hash_algo);

/**
 * @brief Update hash calculation
 *
 * @param[in] handle - handle to the device
 * @param[in] src - buffer for hash calculation
 * @param[in] srclen - src buffer length
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_update_hash(nyx_device_handle_t handle, const char *src,
                         int srclen);

/**
 * @brief Finalize hash calculation and write result to memory
 *
 * @param[in] handle - handle to the device
 * @param[out] dest - calculated hash as base64 encoded (NULL terminated) string
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_finalize_hash(nyx_device_handle_t handle, char *dest);

/**
 * @brief Finalize hash calculation and write result to device
 *
 * @param[in] handle - handle to the device
 * @param[in,out] index - in,out: hash->index (-1: device assign new index, >=0: overwrite existing index)
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_finalize_and_save_hash(nyx_device_handle_t handle, int *index);

/**
 * @brief Load hash from device
 *
 * @param[in] handle - handle to the device
 * @param[in] hash_algo - hash algorithm type (as in openssl/obj_mac.h)
 * @param[in] index - index in device
 * @param[out] dest - hash from device as base64 encoded string
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_load_hash(nyx_device_handle_t handle, const char *hash_algo,
                       int index, char *dest);

/** @} */

/**
 * @defgroup nyx_security_certificate Certificate
 * @ingroup nyx_security_public
 * @{
 */

/**
 * @brief Set certificate
 *
 * @param[in] handle - handle to the device
 * @param[in,out] index - certificate index (-1: device assign new index, >=0 assign to index)
 * @param[in] x509 - certificate in X.509 format
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_save_certificate(nyx_device_handle_t handle, int *index,
                              const char *x509);

/**
 * @brief Get certificate
 *
 * @param[in] handle - handle to the device
 * @param[in] index - certificate index
 * @param[out] x509 - certificate in X.509 format, malloc by device
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security_load_certificate(nyx_device_handle_t handle, int index,
                              char **x509);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_SECURITY_H_ */
