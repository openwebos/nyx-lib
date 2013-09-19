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
 * @file nyx_device.h
 *
 */

/**
 * @brief Nyx's public API for dealing with any device.
 *
 */

#ifndef _NYX_DEVICE_H_
#define _NYX_DEVICE_H_

#include <stdbool.h>
#include <stdint.h>

#include <nyx/common/nyx_macros.h>
#include <nyx/common/nyx_error.h>
#include <nyx/common/nyx_event.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_device_public Device
* @ingroup nyx_public
* @{
*/

/**
 * Defines all valid Nyx device types.
 */
typedef enum {
	NYX_DEVICE_ILLEGAL_DEVICE = 0,
	NYX_DEVICE_BATTERY,
	NYX_DEVICE_BLUETOOTH_INPUT_DETECT,
	NYX_DEVICE_CHARGER,
	NYX_DEVICE_DEVICE_INFO,
	NYX_DEVICE_DISPLAY,
	NYX_DEVICE_FIRMWARE_UPDATE,
	NYX_DEVICE_GENERIC,
	NYX_DEVICE_HAPTICS,
	NYX_DEVICE_KEYS,
	NYX_DEVICE_LED,
	NYX_DEVICE_LED_CONTROLLER,
	NYX_DEVICE_MEMORY,
	NYX_DEVICE_SENSOR_FIRST,    /* all psc sensors */
	NYX_DEVICE_SENSOR_ACCELERATION = NYX_DEVICE_SENSOR_FIRST,
	NYX_DEVICE_SENSOR_ALS,
	NYX_DEVICE_SENSOR_ANGULAR_VELOCITY,
	NYX_DEVICE_SENSOR_BEARING,
	NYX_DEVICE_SENSOR_GRAVITY,
	NYX_DEVICE_SENSOR_LINEAR_ACCELERATION,
	NYX_DEVICE_SENSOR_MAGNETIC_FIELD,
	NYX_DEVICE_SENSOR_ORIENTATION,
	NYX_DEVICE_SENSOR_PROXIMITY,
	NYX_DEVICE_SENSOR_ROTATION,
	NYX_DEVICE_SENSOR_SHAKE,
	NYX_DEVICE_SENSOR_LAST = NYX_DEVICE_SENSOR_SHAKE,
	NYX_DEVICE_TOUCHPANEL,
	NYX_DEVICE_SYSTEM,
	NYX_DEVICE_MEDIA_CAMERA,
	NYX_DEVICE_MASS_STORAGE_MODE,
	NYX_DEVICE_OS_INFO,
	NYX_DEVICE_SECURITY,
}
nyx_device_type_t;

/**
 * Set of flags that determine which Nyx modules will be included in the iterator
 * returned by @ref nyx_device_get_iterator()
 */
typedef enum
{
    NYX_FILTER_DEFAULT = 0,             /**< include default set of devices */
    NYX_FILTER_INCLUDE_MOCK_DEVICES = 0x1,      /**< include the mock devices in the iterator */
    NYX_FILTER_INCLUDE_STATIC_DEVICES = 0x2,    /**< include the static devices in the iterator */
    NYX_FILTER_INCLUDE_MOCK_AND_STATIC_DEVICES = NYX_FILTER_INCLUDE_MOCK_DEVICES | NYX_FILTER_INCLUDE_STATIC_DEVICES,
    NYX_FILTER_ALL = 0xffff,
} nyx_device_filter_t;

/**
* Defines all valid operating modes for a Nyx module
*/
typedef enum
{
    NYX_OPERATING_MODE_UNKNOWN = -1,
    NYX_OPERATING_MODE_OFF,             /**< Device is not operational */
    NYX_OPERATING_MODE_ON,              /**< Device is operational */
} nyx_operating_mode_t;

struct nyx_device;
typedef struct nyx_device *nyx_device_handle_t;
typedef const char *nyx_device_id_t;

struct nyx_device_iterator;
typedef struct nyx_device_iterator *nyx_device_iterator_handle_t;

/**
 * Defines the possible statuses of a worker thread.
 *
 * This status is passed as a parameter to the callback function (@ref nyx_device_callback_function_t).
 */
typedef enum
{
    NYX_CALLBACK_STATUS_UNDEFINED = 0,      /**< Status of worker thread is unknown */
    NYX_CALLBACK_STATUS_DONE,           /**< Worker thread has finished */
    NYX_CALLBACK_STATUS_ASYNC,
    NYX_CALLBACK_STATUS_HARDWARE_ASYNC,
    NYX_CALLBACK_STATUS_FAILED,         /**< Worker thread has finished but got an error */
    NYX_CALLBACK_STATUS_CANCELLED,          /**< Worker thread was cancelled before finishing */
    NYX_CALLBACK_STATUS_PREEMPTED,          /**< Another request/event arrived that replaces (preempts) the worker thread */
} nyx_callback_status_t;

/**
 * Typedef that defines the function signature for a callback routine.
 */
typedef void (*nyx_device_callback_function_t)(nyx_device_handle_t,
        nyx_callback_status_t, void *);

/**
 * Defines all valid poll rates for sensors.
 *
 * Each sensor module that polls for events defines a corresponding rate (in samples per second)
 * for each of these values.
 */
typedef enum
{
    NYX_REPORT_RATE_UNKNOWN = -1,           /**< Report rate is unknown */
    NYX_REPORT_RATE_DEFAULT = 0,            /**< Default reporting rate for sensor when user has not requested specific rate */
    NYX_REPORT_RATE_LOW,                /**< Slow rate of reporting sensor events */
    NYX_REPORT_RATE_MEDIUM,             /**< Medium rate of reporting sensor events */
    NYX_REPORT_RATE_HIGH,               /**< Fast rate of reporting sensor events */
    NYX_REPORT_RATE_HIGHEST,            /**< Fastest rate of reporting sensor events */
    NYX_REPORT_RATE_COUNT,              /* Must always be last */
} nyx_report_rate_t;


/**
 * Create a new device iterator.
 *
 * @param[in]   type - device type
 * @param[in]   filter - flags defining what kind of devices to return
 * @param[out]  iterator_out_ptr - pointer to where to store handle to the
 *          iterator. Will be NULL if no matching devices are found. If not NULL,
 *          it has to be released with the call to @ref nyx_device_release_iterator.
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_get_iterator(nyx_device_type_t type,
        nyx_device_filter_t filter, nyx_device_iterator_handle_t *iterator_out_ptr);

/**
 * Obtain an id for the next device.
 *
 * @param[in]   iterator - iterator from which to obtain the next device
 * @param[out]  id_out_ptr - pointer to where to store device id; it must be
 *              released with the call to nyx_release_device_id
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_iterator_get_next_id(
    nyx_device_iterator_handle_t iterator, nyx_device_id_t *id_out_ptr);

/**
 * Release memory associated with the nyx_device_iterator_handle_t generated by the call to
 * @ref nyx_device_get_iterator.
 *
 * @param[in]   iterator - iterator to be released
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_release_iterator(
    nyx_device_iterator_handle_t iterator);

/**
 * Create a new device of a known type and and id.
 *
 * @param[in]   type - device type
 * @param[in]   id - device id
 * @param[out]  handle_ptr - pointer to a handle to store handle for the
 *              newly created device
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_open(nyx_device_type_t type,
        nyx_device_id_t id, nyx_device_handle_t *handle_ptr);

/**
 * Close the device associated with a handle and release all of its resources.
 * After this call, assume that the handle is no longer valid.
 *
 * @param[in]   handle - handle to the device to be destroyed
 *
 * @return error (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_close(nyx_device_handle_t handle);

/**
 * Set the operating mode of the device.
 *
 * @param[in]   handle - handle to the device
 * @param[in]   mode - operating mode to set
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_set_operating_mode(
    nyx_device_handle_t handle, nyx_operating_mode_t mode);

/**
 * Get the operating mode of the device.
 *
 * @param[in]   handle - handle to the device
 * @param[out]  mode_out_ptr - pointer to where to store current operating mode
 *          of the device
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_get_operating_mode(
    nyx_device_handle_t handle, nyx_operating_mode_t *mode_out_ptr);

/**
 * Get the file descriptor for the event source.
 *
 * @param[in]   handle - handle to the device
 * @param[out]  source_out_ptr - pointer to where to store file descriptor for
 *          the event source
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_get_event_source(nyx_device_handle_t
        handle, int32_t *source_out_ptr);

/**
 * Get the current event for the device.
 *
 * @param[in]   handle - handle to the device
 * @param[out]  event_out_ptr - pointer to where to store the event handle
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_get_event(nyx_device_handle_t handle,
        nyx_event_handle_t *event_out_ptr);

/**
 * Release an event.
 *
 * @param[in]   handle - handle to the device
 * @param[in]   event_handle - handle to the event
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_release_event(nyx_device_handle_t handle,
        nyx_event_handle_t event_handle);

/**
 * Set the reporting rate of a device.
 *
 * @param[in]   handle - the device handle
 * @param[in]   rate - report rate from a predefined set of rates for a sensor
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_set_report_rate(nyx_device_handle_t
        handle, nyx_report_rate_t rate);

/**
 * Get the reporting rate of a device.
 *
 * @param[in]   handle - the device handle
 * @param[out]  rate_out_ptr - pointer to where to store current reporting rate
 *          (as defined in #nyx_report_rate_t) of a sensor
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_get_report_rate(nyx_device_handle_t
        handle, nyx_report_rate_t *rate_out_ptr);

/**
 * Set a property of a device.
 *
 * @param[in]   handle - the device handle
 * @param[in]   property_name_in - property name
 * @param[in]   property_value_in_ptr - pointer to the property value to store
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_set_property(nyx_device_handle_t handle,
        const char *property_name_in, void *property_value_in_ptr);

/**
 * Get a property of a device.
 *
 * @param[in]   handle - the device handle
 * @param[in]   property_name_in - property name
 * @param[out]  property_value_out_ptr - pointer to where to store the pointer
 *          to the property value originally passed to nyx_device_set_property()
 *
 * @return error code (NYX_ERROR_NONE if operation is successful)
 *
 */
NYX_API_EXPORT nyx_error_t nyx_device_get_property(nyx_device_handle_t handle,
        const char *property_name_in, void **property_value_out_ptr);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_DEVICE_H_ */
