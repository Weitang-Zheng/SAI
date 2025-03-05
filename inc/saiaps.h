/**
 * Copyright (c) 2021 Alibaba Group.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 * @file    saiaps.h
 * @brief   This module defines the APS for the SAI
 */

#if !defined (__SAIAPS_H_)
#define __SAIAPS_H_

#include <saitypes.h>

/** @brief APS type */
typedef enum _sai_aps_type_t
{
    SAI_APS_TYPE_APS,
} sai_aps_type_t;

/** @brief APS force to port */
typedef enum _sai_aps_force_to_port_t
{
    SAI_APS_FORCE_TO_PORT_NONE,
    SAI_APS_FORCE_TO_PORT_PRIMARY,
    SAI_APS_FORCE_TO_PORT_SECONDARY,
} sai_aps_force_to_port_t;

/** @brief APS active path */
typedef enum _sai_aps_active_path_t
{
    SAI_APS_ACTIVE_PATH_PRIMARY,
    SAI_APS_ACTIVE_PATH_SECONDARY,

} sai_aps_active_path_t;

typedef enum _sai_olp_switch_reason_t
{
    SAI_OLP_SWITCH_REASON_AUTO_ABSOLUTE,
    SAI_OLP_SWITCH_REASON_AUTO_RELATIVE,
    SAI_OLP_SWITCH_REASON_MANUAL_CMD,
    SAI_OLP_SWITCH_REASON_FORCE_CMD,
    SAI_OLP_SWITCH_REASON_BUTTON_TRIGGER,

} sai_olp_switch_reason_t;

typedef enum _sai_olp_switch_operate_t
{
    SAI_OLP_SWITCH_OPERATE_PRIMARY_TO_SECONDARY,
    SAI_OLP_SWITCH_OPERATE_SECONDARY_TO_PRIMARY,

} sai_olp_switch_operate_t;

typedef enum _sai_olp_switch_interval_t
{
    SAI_OLP_SWITCH_INTERVAL_1MS,
    SAI_OLP_SWITCH_INTERVAL_2MS,
    SAI_OLP_SWITCH_INTERVAL_10MS,

} sai_olp_switch_interval_t;

typedef struct _sai_olp_switch_power_info_t
{
    sai_double_t common_out;
    sai_double_t primary_in;
    sai_double_t secondary_in;
} sai_olp_switch_power_info_t;

typedef struct _sai_olp_switch_info_t
{
    sai_uint16_t index;
    sai_olp_switch_reason_t reason;
    sai_olp_switch_operate_t operate;
    sai_uint64_t time_stamp;
    sai_olp_switch_power_info_t before[40];
    sai_olp_switch_power_info_t switching;
    sai_olp_switch_power_info_t after[40];
} sai_olp_switch_info_t;

typedef struct _sai_olp_switch_t
{
    sai_uint8_t num;
    sai_uint8_t type;
    sai_uint8_t interval;
    sai_uint16_t pointers;
    sai_uint8_t channel_id;
    sai_olp_switch_info_t info[10];
} sai_olp_switch_t;

/**
 * @brief APS report switch info notification
 *
 * @param[in] aps_id APS Id
 * @param[in] switch_info Switch info
 */
typedef void (*sai_aps_report_switch_info_fn)(
        _In_ sai_object_id_t aps_id,
        _In_ sai_olp_switch_t switch_info);

/**
 * @defgroup SAIAPS SAI - APS specific API definitions
 *
 * @{
 */

/**
 * @brief APS attribute IDs
 */
typedef enum _sai_aps_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_APS_ATTR_START,

    /**
     * @brief ID
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_APS_ATTR_ID = SAI_APS_ATTR_START,

    /**
     * @brief Empty
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_EMPTY,

    /**
     * @brief Removable
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_REMOVABLE,

    /**
     * @brief Serial no
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_SERIAL_NO,

    /**
     * @brief Equipment failure
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_EQUIPMENT_FAILURE,

    /**
     * @brief Equipment mismatch
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_EQUIPMENT_MISMATCH,

    /**
     * @brief Hardware version
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_HARDWARE_VERSION,

    /**
     * @brief Admin state
     *
     * @type sai_admin_state_t
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_ADMIN_STATE,

    /**
     * @brief Operational status
     *
     * @type sai_oper_status_t
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_OPER_STATUS,

    /**
     * @brief Part no
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_PART_NO,

    /**
     * @brief Mfg name
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_MFG_NAME,

    /**
     * @brief Manufacture date
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_MFG_DATE,

    /**
     * @brief Software version
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_SOFTWARE_VERSION,

    /**
     * @brief Firmware version
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_APS_ATTR_FIRMWARE_VERSION,

    /**
     * @brief Type
     *
     * @type sai_aps_type_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_TYPE,

    /**
     * @brief Revertive
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_REVERTIVE,

    /**
     * @brief Wait to restore time
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_WAIT_TO_RESTORE_TIME,

    /**
     * @brief Hold off time
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_HOLD_OFF_TIME,

    /**
     * @brief Primary switch threshold
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_PRIMARY_SWITCH_THRESHOLD,

    /**
     * @brief Primary switch hysteresis
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_PRIMARY_SWITCH_HYSTERESIS,

    /**
     * @brief Secondary switch threshold
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_SECONDARY_SWITCH_THRESHOLD,

    /**
     * @brief Relative switch threshold
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_RELATIVE_SWITCH_THRESHOLD,

    /**
     * @brief Relative switch threshold offset
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_RELATIVE_SWITCH_THRESHOLD_OFFSET,

    /**
     * @brief Force to port
     *
     * @type sai_aps_force_to_port_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_FORCE_TO_PORT,

    /**
     * @brief Active path
     *
     * @type sai_aps_active_path_t
     * @flags CREATE_AND_SET
     * @isrecoverable false
     */
    SAI_APS_ATTR_ACTIVE_PATH,

    /**
     * @brief Alarm hysteresis
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_ATTR_ALARM_HYSTERESIS,

    /**
     * @brief Switch info notify
     *
     * @type sai_pointer_t sai_aps_report_switch_info_fn
     * @flags CREATE_ONLY
     * @default NULL
     */
    SAI_APS_ATTR_SWITCH_INFO_NOTIFY,

    /**
     * @brief Collect switch info
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    SAI_APS_ATTR_COLLECT_SWITCH_INFO,

    /**
     * @brief End of attributes
     */
    SAI_APS_ATTR_END,

    /** Custom range base value */
    SAI_APS_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_APS_ATTR_CUSTOM_RANGE_END

} sai_aps_attr_t;

/**
 * @brief APS stat IDs
 *
 * @flags Contains flags
 */
typedef enum _sai_aps_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_APS_STAT_START,

    /**
     * @brief A placeholder
     *
     * @type sai_uint64_t
     */
    SAI_APS_STAT_NOT_USE = SAI_APS_STAT_START,

    /**
     * @brief End of statistics
     */
    SAI_APS_STAT_END,

} sai_aps_stat_t;

/**
 * @brief Create APS.
 *
 * Allocates and initializes a APS.
 *
 * @param[out] aps_id APS id
 * @param[in] linecard_id Linecard id on which the APS exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_aps_fn)(
        _Out_ sai_object_id_t *aps_id,
        _In_ sai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove APS
 *
 * @param[in] aps_id APS id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_aps_fn)(
        _In_ sai_object_id_t aps_id);

/**
 * @brief Set APS attribute
 *
 * @param[in] aps_id APS id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_aps_attribute_fn)(
        _In_ sai_object_id_t aps_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get APS attribute
 *
 * @param[in] aps_id APS id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_aps_attribute_fn)(
        _In_ sai_object_id_t aps_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get APS statistics.
 *
 * @param[in] aps_id APS id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_aps_stats_fn)(
        _In_ sai_object_id_t aps_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Get APS statistics extended.
 *
 * @param[in] aps_id APS id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_aps_stats_ext_fn)(
        _In_ sai_object_id_t aps_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Clear APS statistics counters.
 *
 * @param[in] aps_id APS id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_aps_stats_fn)(
        _In_ sai_object_id_t aps_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_aps_api_t
{
    sai_create_aps_fn                create_aps;
    sai_remove_aps_fn                remove_aps;
    sai_set_aps_attribute_fn         set_aps_attribute;
    sai_get_aps_attribute_fn         get_aps_attribute;
    sai_get_aps_stats_fn             get_aps_stats;
    sai_get_aps_stats_ext_fn         get_aps_stats_ext;
    sai_clear_aps_stats_fn           clear_aps_stats;
} sai_aps_api_t;

/**
 * @}
 */
#endif /** __SAIAPS_H_ */
