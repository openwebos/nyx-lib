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
 * @file nyx_device_internal.h
 *
 * @brief Definition of the data structures and functions and function types
 * used by the NYX's internal implementation and modules implementing particular
 * device.
 *
 */

#ifndef _NYX_DEVICE_INTERNAL_H_
#define _NYX_DEVICE_INTERNAL_H_

#include <nyx/module/nyx_event_internal.h>
#include <nyx/module/nyx_event_sensor_als_internal.h>
#include <nyx/module/nyx_event_sensor_proximity_internal.h>
#include <nyx/module/nyx_event_touchpanel_internal.h>

#ifdef __cplusplus
extern "C" {
#endif
/* NOTE: always add new methods to the end */
typedef enum {
	NYX_NONE_MODULE_METHOD,
	/* generic module functions */
	NYX_SET_OPERATING_MODE_MODULE_METHOD,
	NYX_GET_OPERATING_MODE_MODULE_METHOD,
	NYX_GET_EVENT_SOURCE_MODULE_METHOD,
	NYX_GET_EVENT_MODULE_METHOD,
	NYX_RELEASE_EVENT_MODULE_METHOD,
	NYX_SET_REPORT_RATE_MODULE_METHOD,
	NYX_GET_REPORT_RATE_MODULE_METHOD,
	NYX_SET_PROPERTY_MODULE_METHOD,
	NYX_GET_PROPERTY_MODULE_METHOD,
	/* led module functions */
	NYX_LED_SET_BRIGHTNESS_MODULE_METHOD,
	NYX_LED_GET_BRIGHTNESS_MODULE_METHOD,
	/* led controller module functions */
	NYX_LED_CONTROLLER_EXECUTE_EFFECT_MODULE_METHOD,
	NYX_LED_CONTROLLER_STOP_MODULE_METHOD,
	NYX_LED_CONTROLLER_GET_STATE_MODULE_METHOD,
	NYX_LED_CONTROLLER_SET_ABL_STATE_MODULE_METHOD,
	/* haptics module functions */
	NYX_HAPTICS_VIBRATE_MODULE_METHOD,
	NYX_HAPTICS_CANCEL_MODULE_METHOD,
	NYX_HAPTICS_CANCEL_ALL_MODULE_METHOD,
	NYX_HAPTICS_GET_EFFECT_ID_MODULE_METHOD,
	/* charger module functions */
	NYX_CHARGER_QUERY_CHARGER_STATUS_MODULE_METHOD,
	NYX_CHARGER_REGISTER_CHARGER_STATUS_CALLBACK_MODULE_METHOD,
	NYX_CHARGER_ENABLE_CHARGING_MODULE_METHOD,
	NYX_CHARGER_DISABLE_CHARGING_MODULE_METHOD,
	NYX_CHARGER_REGISTER_STATE_CHANGE_CALLBACK_MODULE_METHOD,
	NYX_CHARGER_QUERY_CHARGER_EVENT_MODULE_METHOD,
	/* battery module functions */
	NYX_BATTERY_QUERY_BATTERY_STATUS_MODULE_METHOD,
	NYX_BATTERY_REGISTER_BATTERY_STATUS_CALLBACK_MODULE_METHOD,
	NYX_BATTERY_AUTHENTICATE_BATTERY_MODULE_METHOD,
	NYX_BATTERY_GET_CTIA_PARAMETERS_MODULE_METHOD,
	NYX_BATTERY_SET_WAKEUP_PARAMETERS_MODULE_METHOD,
	/* firmware_update module functions */
	NYX_FIRMWARE_UPDATE_QUERY_CURRENT_VERSION_MODULE_METHOD,
	NYX_FIRMWARE_UPDATE_GET_AVAILABLE_VERSIONS_ITERATOR_MODULE_METHOD,
	NYX_FIRMWARE_UPDATE_GET_NEXT_AVAILABLE_VERSION_MODULE_METHOD,
	NYX_FIRMWARE_UPDATE_RELEASE_AVAILABLE_VERSIONS_ITERATOR_MODULE_METHOD,
	NYX_FIRMWARE_UPDATE_FLASH_MODULE_METHOD,
	/* touchpanel module functions */
	NYX_TOUCHPANEL_GET_ACTIVE_SCAN_RATE_MODULE_METHOD,
	NYX_TOUCHPANEL_SET_ACTIVE_SCAN_RATE_MODULE_METHOD,
	NYX_TOUCHPANEL_GET_IDLE_SCAN_RATE_MODULE_METHOD,
	NYX_TOUCHPANEL_SET_IDLE_SCAN_RATE_MODULE_METHOD,
	NYX_TOUCHPANEL_GET_MODE_MODULE_METHOD,
	NYX_TOUCHPANEL_SET_MODE_MODULE_METHOD,
	/* system module functions */
	NYX_SYSTEM_SET_ALARM_MODULE_METHOD,
	NYX_SYSTEM_QUERY_NEXT_ALARM_MODULE_METHOD,
	NYX_SYSTEM_QUERY_RTC_TIME_MODULE_METHOD,
	NYX_SYSTEM_SUSPEND_MODULE_METHOD,
	NYX_SYSTEM_SHUTDOWN_MODULE_METHOD,
	NYX_SYSTEM_REBOOT_MODULE_METHOD,
	NYX_SYSTEM_ERASE_PARTITION_MODULE_METHOD,
	/* bearing sensor module functions */
	NYX_SENSOR_BEARING_GET_LOCATION_MODULE_METHOD,
	NYX_SENSOR_BEARING_SET_LOCATION_MODULE_METHOD,
	/* orientation sensor module functions */
	NYX_SENSOR_ORIENTATION_GET_THRESHOLD_MODULE_METHOD,
	NYX_SENSOR_ORIENTATION_SET_THRESHOLD_MODULE_METHOD,
	/* device info module functions */
	NYX_DEVICE_INFO_GET_INFO_MODULE_METHOD,
	/* Mass Storage Mode module functions */
	NYX_MASS_STORAGE_MODE_SET_MODE_MODULE_METHOD,
	NYX_MASS_STORAGE_MODE_GET_STATE_MODULE_METHOD,
	NYX_MASS_STORAGE_MODE_REGISTER_CHANGE_CALLBACK_MODULE_METHOD,
	/* OS info module function*/
	NYX_OS_INFO_QUERY_MODULE_METHOD,
	/* security module functions */
	NYX_SECURITY_CREATE_AES_KEY_MODULE_METHOD,
	NYX_SECURITY_CRYPT_AES_MODULE_METHOD,
	NYX_SECURITY_CREATE_RSA_KEY_MODULE_METHOD,
	NYX_SECURITY_CRYPT_RSA_MODULE_METHOD,
	NYX_SECURITY_INIT_HASH_MODULE_METHOD,
	NYX_SECURITY_UPDATE_HASH_MODULE_METHOD,
	NYX_SECURITY_FINALIZE_HASH_MODULE_METHOD,
	NYX_SECURITY_FINALIZE_AND_SAVE_HASH_MODULE_METHOD,
	NYX_SECURITY_LOAD_HASH_MODULE_METHOD,
	NYX_SECURITY_SAVE_CERTIFICATE_MODULE_METHOD,
	NYX_SECURITY_LOAD_CERTIFICATE_MODULE_METHOD,
	/* device info module function */
	NYX_DEVICE_INFO_QUERY_MODULE_METHOD,
}
module_method_t;

typedef void *nyx_instance_t;
typedef struct nyx_device nyx_device_t;

typedef nyx_error_t (*nyx_open_function_t)(nyx_instance_t, nyx_device_t **);
typedef nyx_error_t (*nyx_close_function_t)(nyx_device_t *);

struct nyx_device
{
	nyx_device_type_t type;
	char *name;
	char *description;

	void *module_ptr;
	nyx_open_function_t open_ptr;
	nyx_close_function_t close_ptr;

	/* we need a pointer to the structure that keeps the data
	 * but since we want the API to be not aware of the actual
	 * implementation but we need to convey the size we will
	 * give it a void* definition.
	 */
	void *method_hash_table;
};

typedef nyx_error_t (*nyx_set_operating_mode_function_t)(nyx_device_t *,
        nyx_operating_mode_t);
typedef nyx_error_t (*nyx_get_operating_mode_function_t)(nyx_device_t *,
        nyx_operating_mode_t *);
typedef nyx_error_t (*nyx_get_event_source_function_t)(nyx_device_t *,
        int32_t *);
typedef nyx_error_t (*nyx_get_event_function_t)(nyx_device_t *, nyx_event_t **);
typedef nyx_error_t (*nyx_release_event_function_t)(nyx_device_t *,
        nyx_event_t *);
typedef nyx_error_t (*nyx_set_event_report_rate_function_t)(nyx_device_t *,
        nyx_report_rate_t);
typedef nyx_error_t (*nyx_get_event_report_rate_function_t)(nyx_device_t *,
        nyx_report_rate_t *);

typedef nyx_error_t (*nyx_set_report_rate_function_t)(nyx_device_t *,
        nyx_report_rate_t);
typedef nyx_error_t (*nyx_get_report_rate_function_t)(nyx_device_t *,
        nyx_report_rate_t *);

typedef nyx_error_t (*nyx_set_scan_rate_function_t)(nyx_device_t *, uint32_t);
typedef nyx_error_t (*nyx_get_scan_rate_function_t)(nyx_device_t *, uint32_t *);

typedef nyx_error_t (*nyx_set_int_function_t)(nyx_device_t *, int32_t);
typedef nyx_error_t (*nyx_get_int_function_t)(nyx_device_t *, int32_t *);

typedef nyx_error_t (*nyx_led_set_brightness_function_t)(nyx_device_t *,
        int32_t);
typedef nyx_error_t (*nyx_led_get_brightness_function_t)(nyx_device_t *,
        int32_t *);

typedef nyx_error_t (*nyx_set_property_function_t)(nyx_device_t *, const char *,
        void *);
typedef nyx_error_t (*nyx_get_property_function_t)(nyx_device_t *, const char *,
        void **);

typedef nyx_error_t (*nyx_led_controller_execute_effect_function_t)(
    nyx_device_t *,  nyx_led_controller_effect_t);
typedef nyx_error_t (*nyx_led_controller_stop_function_t)(nyx_device_t *,
        nyx_led_controller_led_t);
typedef nyx_error_t (*nyx_led_controller_get_state_function_t)(nyx_device_t *,
        nyx_led_controller_led_t, nyx_led_controller_state_t *);
typedef nyx_error_t (*nyx_led_controller_set_abl_state_function_t)(
    nyx_device_t *, nyx_led_controller_led_t, nyx_led_controller_abl_state_t);


typedef nyx_error_t (*nyx_haptics_vibrate_function_t)(nyx_device_t *,
        nyx_haptics_configuration_t configuration);
typedef nyx_error_t (*nyx_haptics_cancel_function_t)(nyx_device_t *, int32_t);
typedef nyx_error_t (*nyx_haptics_cancel_all_function_t)(nyx_device_t *);

typedef nyx_error_t (*nyx_charger_query_charger_status_function_t)(
    nyx_device_t *, nyx_charger_status_t *);
typedef nyx_error_t (*nyx_charger_register_charger_status_callback_function_t)(
    nyx_device_t *, nyx_device_callback_function_t, void *context);
typedef nyx_error_t (*nyx_charger_enable_charging_function_t)(nyx_device_t *,
        nyx_charger_status_t *);
typedef nyx_error_t (*nyx_charger_disable_charging_function_t)(nyx_device_t *,
        nyx_charger_status_t *);
typedef nyx_error_t (*nyx_charger_register_state_change_callback_function_t)(
    nyx_device_t * , nyx_device_callback_function_t, void *context);
typedef nyx_error_t (*nyx_charger_query_charger_event_function_t)(
    nyx_device_t *, nyx_charger_event_t *);

typedef nyx_error_t (*nyx_battery_query_battery_status_function_t)(
    nyx_device_t *, nyx_battery_status_t *);
typedef nyx_error_t (*nyx_battery_register_battery_status_callback_function_t)(
    nyx_device_t *, nyx_device_callback_function_t, void *context);
typedef nyx_error_t (*nyx_battery_authenticate_battery_function_t)(
    nyx_device_t *, bool *);
typedef nyx_error_t (*nyx_battery_get_ctia_parameters_function_t)(
    nyx_device_t *, nyx_battery_ctia_t *);
typedef nyx_error_t (*nyx_battery_set_wakeup_percentage_function_t)(
    nyx_device_t *, int32_t);
typedef nyx_error_t (*nyx_firmware_update_query_current_version_function_t)(
    nyx_device_t *, char **);
typedef nyx_error_t (
    *nyx_firmware_update_get_available_versions_iterator_function_t)(nyx_device_t *,
            nyx_firmware_update_iterator_handle_t *);
typedef nyx_error_t (*nyx_firmware_update_get_next_available_version_function_t)
(nyx_device_t *, nyx_firmware_update_iterator_handle_t,
 nyx_firmware_version_info_handle_t *);
typedef nyx_error_t (
    *nyx_firmware_update_release_available_versions_iterator_function_t)(
        nyx_device_t *, nyx_firmware_update_iterator_handle_t);
typedef nyx_error_t (*nyx_firmware_update_flash_function_t)(nyx_device_t *,
        nyx_firmware_version_info_handle_t, bool, int32_t *,
        nyx_device_callback_function_t, void *);

typedef nyx_error_t (*nyx_system_set_alarm_function_t)(nyx_device_t *, time_t,
        nyx_device_callback_function_t, void *);
typedef nyx_error_t (*nyx_system_query_next_alarm_function_t)(nyx_device_t *,
        time_t *);
typedef nyx_error_t (*nyx_system_query_rtc_time_function_t)(nyx_device_t *,
        time_t *);
typedef nyx_error_t (*nyx_system_suspend_function_t)(nyx_device_t *, bool *);
typedef nyx_error_t (*nyx_system_shutdown_function_t)(nyx_device_t *,
        nyx_system_shutdown_type_t, const char *);
typedef nyx_error_t (*nyx_system_reboot_function_t)(nyx_device_t *,
        nyx_system_shutdown_type_t, const char *);
typedef nyx_error_t (*nyx_system_erase_partition_function_t)(nyx_device_t *,
        nyx_system_erase_type_t);

typedef nyx_error_t (*nyx_bearing_get_location_function_t)(nyx_device_t *,
        nyx_sensor_bearing_location_t *);
typedef nyx_error_t (*nyx_bearing_set_location_function_t)(nyx_device_t *,
        const nyx_sensor_bearing_location_t *);
typedef nyx_error_t (*nyx_orientation_get_threshold_function_t)(nyx_device_t *,
        nyx_sensor_orientation_threshold_t *);
typedef nyx_error_t (*nyx_orientation_set_threshold_function_t)(nyx_device_t *,
        const nyx_sensor_orientation_threshold_t *);

typedef nyx_error_t (*nyx_device_info_get_info_function_t)(nyx_device_t *,
        nyx_device_info_type_t type, char *dest, size_t dest_len);
typedef nyx_error_t (*nyx_device_info_query_function_t)(nyx_device_t *,
        nyx_device_info_type_t type, const char **dest);

typedef nyx_error_t (*nyx_mass_storage_mode_set_mode_function_t)(nyx_device_t *,
        nyx_mass_storage_mode_action_t, nyx_mass_storage_mode_return_code_t *);
typedef nyx_error_t (*nyx_mass_storage_mode_get_state_function_t)(
    nyx_device_t *, nyx_mass_storage_mode_state_t *);
typedef nyx_error_t (*nyx_mass_storage_mode_register_change_callback_function_t)
(nyx_device_t *, nyx_device_callback_function_t, void *);

typedef nyx_error_t (*nyx_os_info_query_function_t)(nyx_device_t *,
        nyx_os_info_query_t type, const char **val);
typedef nyx_error_t (*nyx_security_create_aes_key_function_t)(
    nyx_device_handle_t handle, int keylen, int *key_index);
typedef nyx_error_t (*nyx_security_crypt_aes_function_t)(
    nyx_device_handle_t handle, int key_index, nyx_security_aes_block_mode_t mode,
    int encrypt, const char *src, int srclen, char *dest, int *destlen, int *ivlen);
typedef nyx_error_t (*nyx_security_create_rsa_key_function_t)(
    nyx_device_handle_t handle, int keylen, int *key_index);
typedef nyx_error_t (*nyx_security_crypt_rsa_function_t)(
    nyx_device_handle_t handle, int key_index, int encrypt, const char *src,
    int srclen, char *dest, int *destlen);
typedef nyx_error_t (*nyx_security_init_hash_function_t)(
    nyx_device_handle_t handle, const char *hash_algo);
typedef nyx_error_t (*nyx_security_update_hash_function_t)(
    nyx_device_handle_t handle, const char *src, int srclen);
typedef nyx_error_t (*nyx_security_finalize_hash_function_t)(
    nyx_device_handle_t handle, char *dest);
typedef nyx_error_t (*nyx_security_finalize_and_save_hash_function_t)(
    nyx_device_handle_t handle, int *index);
typedef nyx_error_t (*nyx_security_load_hash_function_t)(
    nyx_device_handle_t handle, const char *hash_algo, int index, char *dest);
typedef nyx_error_t (*nyx_security_save_certificate_function_t)(
    nyx_device_handle_t handle, int *index, const char *x509);
typedef nyx_error_t (*nyx_security_load_certificate_function_t)(
    nyx_device_handle_t handle, int index, char **x509);

#ifdef __cplusplus
}
#endif

#endif /* _NYX_DEVICE_INTERNAL_H_ */
