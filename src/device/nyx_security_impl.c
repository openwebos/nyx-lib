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

/********************************************************************************
 * @file nyx_security_impl.c
 *
 * @brief This is the nyx security lib implementation
 ********************************************************************************/

#include "nyx_device_impl.h"
#include <nyx/module/nyx_device_internal.h>
#include <nyx/client/nyx_security.h>

nyx_error_t nyx_security_create_aes_key(nyx_device_handle_t handle, int keylen,
                                        int *key_index)
{
	nyx_execute_return_function(security_create_aes_key, SECURITY, CREATE_AES_KEY,
	                            handle, keylen, key_index);
}

nyx_error_t nyx_security_crypt_aes(nyx_device_handle_t handle, int key_index,
                                   nyx_security_aes_block_mode_t mode, int encrypt, const char *src, int srclen,
                                   char *dest, int *destlen, int *ivlen)
{
	nyx_execute_return_function(security_crypt_aes, SECURITY, CRYPT_AES, handle,
	                            key_index, mode, encrypt, src, srclen, dest, destlen, ivlen);
}

nyx_error_t nyx_security_create_rsa_key(nyx_device_handle_t handle, int keylen,
                                        int *key_index)
{
	nyx_execute_return_function(security_create_rsa_key, SECURITY, CREATE_RSA_KEY,
	                            handle, keylen, key_index);
}

nyx_error_t nyx_security_crypt_rsa(nyx_device_handle_t handle, int key_index,
                                   int encrypt, const char *src, int srclen, char *dest, int *destlen)
{
	nyx_execute_return_function(security_crypt_rsa, SECURITY, CRYPT_RSA, handle,
	                            key_index, encrypt, src, srclen, dest, destlen);
}

nyx_error_t nyx_security_init_hash(nyx_device_handle_t handle,
                                   const char *hash_algo)
{
	nyx_execute_return_function(security_init_hash, SECURITY, INIT_HASH, handle,
	                            hash_algo);
}

nyx_error_t nyx_security_update_hash(nyx_device_handle_t handle,
                                     const char *src, int srclen)
{
	nyx_execute_return_function(security_update_hash, SECURITY, UPDATE_HASH, handle,
	                            src, srclen);
}

nyx_error_t nyx_security_finalize_hash(nyx_device_handle_t handle, char *dest)
{
	nyx_execute_return_function(security_finalize_hash, SECURITY, FINALIZE_HASH,
	                            handle, dest);
}

nyx_error_t nyx_security_finalize_and_save_hash(nyx_device_handle_t handle,
        int *index)
{
	nyx_execute_return_function(security_finalize_and_save_hash, SECURITY,
	                            FINALIZE_AND_SAVE_HASH, handle, index);
}

nyx_error_t nyx_security_load_hash(nyx_device_handle_t handle,
                                   const char *hash_algo, int index, char *dest)
{
	nyx_execute_return_function(security_load_hash, SECURITY, LOAD_HASH, handle,
	                            hash_algo, index, dest);
}

nyx_error_t nyx_security_save_certificate(nyx_device_handle_t handle,
        int *index, const char *x509)
{
	nyx_execute_return_function(security_save_certificate, SECURITY,
	                            SAVE_CERTIFICATE, handle, index, x509);
}

nyx_error_t nyx_security_load_certificate(nyx_device_handle_t handle, int index,
        char **x509)
{
	nyx_execute_return_function(security_load_certificate, SECURITY,
	                            LOAD_CERTIFICATE, handle, index, x509);
}
