/* @@@LICENSE
*
*      Copyright (c) 2010-2013 LG Electronics, Inc.
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
 * @file nyx_touchpanel.h
 *
 */

/**
 * @brief Nyx's public API for accessing a touchpanel
 * device and the events it generates.
 *
 */
#ifndef __NYX_TOUCHPANEL_H__
#define __NYX_TOUCHPANEL_H__

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_touchpanel_common.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
* @defgroup nyx_touchpanel_public Touchpanel
* @ingroup nyx_public
* @{
*/

/**
 * Get the active scan rate of the touchpanel.
 *
 * @param[in]   handle - the event handle
 * @param[out]  active_scan_rate_out_ptr - pointer to store active scan rate
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_touchpanel_get_active_scan_rate(
    nyx_device_handle_t handle, uint32_t *active_scan_rate_out_ptr);

/**
 * Get the idle scan rate of the touchpanel.
 *
 * @param[in]   handle - the event handle
 * @param[out]  idle_scan_rate_out_ptr - pointer to store idle scan rate
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_touchpanel_get_idle_scan_rate(
    nyx_device_handle_t handle, uint32_t *idle_scan_rate_out_ptr);

/**
 * Set the active scan rate of the touchpanel.
 *
 * @param[in]   handle - the event handle
 * @param[in]   active_scan_rate_in - active scan rate to be set
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_touchpanel_set_active_scan_rate(
    nyx_device_handle_t handle, uint32_t active_scan_rate_in);

/**
 * Set the idle scan rate of the touchpanel.
 *
 * @param[in]   handle - the event handle
 * @param[in]   idle_scan_rate_in - idle scan rate to be set
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_touchpanel_set_idle_scan_rate(
    nyx_device_handle_t handle, uint32_t idle_scan_rate_in);

/**
 * Get the current mode of the touchpanel.
 *
 * @param[in]   handle - the event handle
 * @param[out]  mode_mask_out_ptr - pointer to store current mode(s)
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_touchpanel_get_mode(nyx_device_handle_t handle,
        int32_t *mode_mask_out_ptr);

/**
 * Set the current mode of the touchpanel.
 *
 * @param[in]   handle - the event handle
 * @param[in]   mode_mask - mode(s) to be set
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_touchpanel_set_mode(nyx_device_handle_t handle,
        int32_t mode_mask);

/**
 * Get the type of a touchpanel event.
 *
 * @param[in]   handle - the event handle
 * @param[out]  type_out_ptr - pointer to store type of touchpanel event
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_touchpanel_event_get_type(
    nyx_event_handle_t handle, nyx_touchpanel_event_type_t *type_out_ptr);

/**
 * Get the array of touches associated with the touchpanel event.
 *
 * @param[in]   handle - the event handle
 * @param[out]  touches_out_ptr - pointer to store array of touches
 * @param[out]  count_out_ptr - number of valid touches in the array
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_touchpanel_event_get_touches(
    nyx_event_handle_t handle, nyx_touchpanel_event_item_t **touches_out_ptr,
    int32_t *count_out_ptr);

/** @} */
#ifdef __cplusplus
}
#endif

#endif // __NYX_TOUCHPANEL_H__

