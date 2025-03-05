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
 * @file    saiosc.h
 * @brief   This module defines the OSC for the SAI
 */

#if !defined (__SAIOSC_H_)
#define __SAIOSC_H_

#include <saitypes.h>

/**
 * @defgroup SAIOSC SAI - OSC specific API definitions
 *
 * @{
 */

/**
 * @brief OSC attribute IDs
 */
typedef enum _sai_osc_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OSC_ATTR_START,

    /**
     * @brief ID
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OSC_ATTR_ID = SAI_OSC_ATTR_START,

    /**
     * @brief Removable
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_REMOVABLE,

    /**
     * @brief Serial no
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_SERIAL_NO,

    /**
     * @brief Equipment failure
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_EQUIPMENT_FAILURE,

    /**
     * @brief Equipment mismatch
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_EQUIPMENT_MISMATCH,

    /**
     * @brief Location
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_LOCATION,

    /**
     * @brief Hardware version
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_HARDWARE_VERSION,

    /**
     * @brief Admin state
     *
     * @type sai_admin_state_t
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_ADMIN_STATE,

    /**
     * @brief Operational status
     *
     * @type sai_oper_status_t
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_OPER_STATUS,

    /**
     * @brief Part no
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_PART_NO,

    /**
     * @brief Mfg name
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_MFG_NAME,

    /**
     * @brief Manufacture date
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_MFG_DATE,

    /**
     * @brief Empty
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_EMPTY,

    /**
     * @brief Software version
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_SOFTWARE_VERSION,

    /**
     * @brief Firmware version
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_FIRMWARE_VERSION,

    /**
     * @brief Output frequency
     *
     * @type sai_uint64_t
     * @flags READ_ONLY
     */
    SAI_OSC_ATTR_OUTPUT_FREQUENCY,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_OSC_ATTR_ENABLED,

    /**
     * @brief Rx low threshold
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_OSC_ATTR_RX_LOW_THRESHOLD,

    /**
     * @brief Rx high threshold
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_OSC_ATTR_RX_HIGH_THRESHOLD,

    /**
     * @brief Tx low threshold
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_OSC_ATTR_TX_LOW_THRESHOLD,

    /**
     * @brief End of attributes
     */
    SAI_OSC_ATTR_END,

    /** Custom range base value */
    SAI_OSC_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OSC_ATTR_CUSTOM_RANGE_END

} sai_osc_attr_t;

/**
 * @brief OSC stat IDs
 *
 * @flags Contains flags
 */
typedef enum _sai_osc_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_OSC_STAT_START,

    /**
     * @brief Input power
     *
     * @type sai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_INPUT_POWER = SAI_OSC_STAT_START,

    /**
     * @brief Temperature
     *
     * @type sai_double_t
     * @precision precision1
     * @iscounter false
     */
    SAI_OSC_STAT_TEMPERATURE,

    /**
     * @brief Output power
     *
     * @type sai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_OUTPUT_POWER,

    /**
     * @brief Input offset primary-line rx
     *
     * @type sai_double_t
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_INPUT_OFFSET_LINEP_RX,

    /**
     * @brief Output offset primary-line tx
     *
     * @type sai_double_t
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_OUTPUT_OFFSET_LINEP_TX,

    /**
     * @brief Input offset secondary-line rx
     *
     * @type sai_double_t
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_INPUT_OFFSET_LINES_RX,

    /**
     * @brief Output offset secondary-line tx
     *
     * @type sai_double_t
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_OUTPUT_OFFSET_LINES_TX,

    /**
     * @brief Laser bias current
     *
     * @type sai_double_t
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_LASER_BIAS_CURRENT,

    /**
     * @brief Panel input power primary-line rx
     *
     * @type sai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_PANEL_INPUT_POWER_LINEP_RX,

    /**
     * @brief Panel output power primary-line tx
     *
     * @type sai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_PANEL_OUTPUT_POWER_LINEP_TX,

    /**
     * @brief Panel input power secondary-line rx
     *
     * @type sai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_PANEL_INPUT_POWER_LINES_RX,

    /**
     * @brief Panel output power secondary-line tx
     *
     * @type sai_double_t
     * @unit dBm
     * @precision precision2
     * @iscounter false
     */
    SAI_OSC_STAT_PANEL_OUTPUT_POWER_LINES_TX,

    /**
     * @brief End of statistics
     */
    SAI_OSC_STAT_END,

} sai_osc_stat_t;

/**
 * @brief Create OSC.
 *
 * Allocates and initializes a OSC.
 *
 * @param[out] osc_id OSC id
 * @param[in] linecard_id Linecard id on which the OSC exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_osc_fn)(
        _Out_ sai_object_id_t *osc_id,
        _In_ sai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OSC
 *
 * @param[in] osc_id OSC id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_osc_fn)(
        _In_ sai_object_id_t osc_id);

/**
 * @brief Set OSC attribute
 *
 * @param[in] osc_id OSC id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_osc_attribute_fn)(
        _In_ sai_object_id_t osc_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OSC attribute
 *
 * @param[in] osc_id OSC id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_osc_attribute_fn)(
        _In_ sai_object_id_t osc_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get OSC statistics.
 *
 * @param[in] osc_id OSC id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_osc_stats_fn)(
        _In_ sai_object_id_t osc_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Get OSC statistics extended.
 *
 * @param[in] osc_id OSC id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_osc_stats_ext_fn)(
        _In_ sai_object_id_t osc_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Clear OSC statistics counters.
 *
 * @param[in] osc_id OSC id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_osc_stats_fn)(
        _In_ sai_object_id_t osc_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_osc_api_t
{
    sai_create_osc_fn                create_osc;
    sai_remove_osc_fn                remove_osc;
    sai_set_osc_attribute_fn         set_osc_attribute;
    sai_get_osc_attribute_fn         get_osc_attribute;
    sai_get_osc_stats_fn             get_osc_stats;
    sai_get_osc_stats_ext_fn         get_osc_stats_ext;
    sai_clear_osc_stats_fn           clear_osc_stats;
} sai_osc_api_t;

/**
 * @}
 */
#endif /** __SAIOSC_H_ */
