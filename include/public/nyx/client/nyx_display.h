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
 * @file nyx_display.h
 *
 */

#ifndef _NYX_DISPLAY_H_
#define _NYX_DISPLAY_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_display_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Get the display metrics: pixels, dpi, aspect ratio.
 *
 * @param[in]   handle - handle to the device.
 * @param[out]  metrics_out_ptr - the structure, which contains display related metrics.
 *
 * @return error that will be NYX_ERROR_NONE if operation is
 * successful or an actual error if operation did not succeed.
 *
 */
NYX_API_EXPORT nyx_error_t nyx_display_get_metrics(nyx_device_handle_t handle,
        nyx_display_metrics_t *metrics_out_ptr);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_DISPLAY_H_ */
