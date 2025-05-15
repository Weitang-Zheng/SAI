/**
 * Copyright (c) 20XX Microsoft Open Technologies, Inc.
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
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saiopticalport.h
 * @brief   This module defines the optical port for the SAI
 */

#if !defined(__SAIOPTICALPORT_H_)
#define __SAIOPTICALPORT_H_

#include <saitypes.h>

/**
 * @defgroup SAIOPTICALPORT SAI - Optical Port specific API definitions
 *
 * @{
 */

/**
 * @brief Optical Port attribute IDs
 */
typedef enum _sai_optical_port_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OPTICAL_PORT_ATTR_START,

    /**
     * @brief Optical port ID.
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OPTICAL_PORT_ATTR_OPTICAL_PORT_ID = SAI_OPTICAL_PORT_ATTR_START,

    /**
     * @brief Optical port type
     *
     * @type sai_optical_port_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OPTICAL_PORT_ATTR_OPTICAL_PORT_TYPE,

    /**
     * @brief Operational status
     *
     * @type sai_oper_status_t
     * @flags READ_ONLY
     */
    SAI_OPTICAL_PORT_ATTR_OPER_STATUS,

    /**
     * @brief Admin state
     *
     * @type sai_admin_state_t
     * @flags CREATE_AND_SET
     */
    SAI_OPTICAL_PORT_ATTR_ADMIN_STATE,

    /**
     * @brief Rx CD range
     *
     * @type sai_s32_range_t
     * @flags CREATE_AND_SET
     */
    SAI_OPTICAL_PORT_ATTR_RX_CD_RANGE,

    /**
     * @brief Roll off parameter
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_OPTICAL_PORT_ATTR_ROLL_OFF,

    /**
     * @brief Los threshold
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @precision precision2
     */
    SAI_OPTICAL_PORT_ATTR_LOS_THRESHOLD,

    /**
     * @brief Equipment failure
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_OPTICAL_PORT_ATTR_EQUIPMENT_FAILURE,

    /**
     * @brief Equipment mismatch
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_OPTICAL_PORT_ATTR_EQUIPMENT_MISMATCH,

    /**
     * @brief Low threshold
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @precision precision2
     */
    SAI_OPTICAL_PORT_ATTR_LOW_THRESHOLD,

    /**
     * @brief High threshold
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @precision precision2
     */
    SAI_OPTICAL_PORT_ATTR_HIGH_THRESHOLD,

    /**
     * @brief Input offset
     *
     * @type sai_uint64_t
     * @flags READ_ONLY
     * @precision precision2
     */
    SAI_OPTICAL_PORT_ATTR_INPUT_OFFSET,

    /**
     * @brief Output offset
     *
     * @type sai_uint64_t
     * @flags READ_ONLY
     * @precision precision2
     */
    SAI_OPTICAL_PORT_ATTR_OUTPUT_OFFSET,

    /**
     * @brief End of attributes
     */
    SAI_OPTICAL_PORT_ATTR_END,

    /** Custom range base value */
    SAI_OPTICAL_PORT_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OPTICAL_PORT_ATTR_CUSTOM_RANGE_END

} sai_optical_port_attr_t;

/**
 * @brief Optical port stat IDs
 */
typedef enum _sai_optical_port_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_OPTICAL_PORT_STAT_START,

    /**
     * @brief Input power
     *
     * @type sai_uint64_t
     * @unit dBm
     * @iscounter false
     * @precision precision2
     */
    SAI_OPTICAL_PORT_STAT_INPUT_POWER = SAI_OPTICAL_PORT_STAT_START,

    /**
     * @brief Output power
     *
     * @type sai_uint64_t
     * @unit dBm
     * @iscounter false
     * @precision precision2
     */
    SAI_OPTICAL_PORT_STAT_OUTPUT_POWER,

    /**
     * @brief OSC input power
     *
     * @type sai_uint64_t
     * @unit dBm
     * @iscounter false
     * @precision precision2
     */
    SAI_OPTICAL_PORT_STAT_OSC_INPUT_POWER,

    /**
     * @brief OSC output power
     *
     * @type sai_uint64_t
     * @unit dBm
     * @iscounter false
     * @precision precision2
     */
    SAI_OPTICAL_PORT_STAT_OSC_OUTPUT_POWER,

    /**
     * @brief End of statistics
     */
    SAI_OPTICAL_PORT_STAT_END,
} sai_optical_port_stat_t;

/**
 * @brief Create optical port.
 *
 * Allocates and initializes a port.
 *
 * @param[out] optical_port_id Optical port id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_optical_port_fn)(
        _Out_ sai_object_id_t *optical_port_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove optical port
 *
 * @param[in] optical_port_id Optical port id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_optical_port_fn)(
        _In_ sai_object_id_t optical_port_id);

/**
 * @brief Set optical port attribute
 *
 * @param[in] optical_port_id Optical port id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_optical_port_attribute_fn)(
        _In_ sai_object_id_t optical_port_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get optical port attribute
 *
 * @param[in] optical_port_id Optical port id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_optical_port_attribute_fn)(
        _In_ sai_object_id_t optical_port_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get optical port statistics.
 *
 * @param[in] optical_port_id Optical port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_optical_port_stats_fn)(
        _In_ sai_object_id_t optical_port_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ uint64_t *counters);

/**
 * @brief Get optical port statistics extended.
 *
 * @param[in] optical_port_id Optical port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_optical_port_stats_ext_fn)(
        _In_ sai_object_id_t optical_port_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ uint64_t *counters);

/**
 * @brief Clear optical port statistics.
 *
 * @param[in] optical_port_id Optical port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_optical_port_stats_fn)(
        _In_ sai_object_id_t optical_port_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Optical port methods table retrieved with sai_api_query()
 */
typedef struct _sai_optical_port_api_t
{
    sai_create_optical_port_fn          create_optical_port;
    sai_remove_optical_port_fn          remove_optical_port;
    sai_set_optical_port_attribute_fn   set_optical_port_attribute;
    sai_get_optical_port_attribute_fn   get_optical_port_attribute;
    sai_get_optical_port_stats_fn       get_optical_port_stats;
    sai_get_optical_port_stats_ext_fn   get_optical_port_stats_ext;
    sai_clear_optical_port_stats_fn     clear_optical_port_stats;
} sai_optical_port_api_t;

/**
 * @}
 */
#endif /** __SAIOPTICALPORT_H_ */