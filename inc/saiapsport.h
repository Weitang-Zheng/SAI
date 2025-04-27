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
 * @file    saiapsport.h
 * @brief   This module defines the APS port for the SAI
 */

#if !defined (__SAIAPSPORT_H_)
#define __SAIAPSPORT_H_

#include <saitypes.h>

/**
 * @defgroup SAIAPSPORT SAI - APS Port specific API definitions
 *
 * @{
 */

/** @brief APS port type */
typedef enum _sai_aps_port_type_t
{
    SAI_APS_PORT_TYPE_LINE_PRIMARY_IN,
    SAI_APS_PORT_TYPE_LINE_SECONDARY_IN,
    SAI_APS_PORT_TYPE_COMMON_IN,
    SAI_APS_PORT_TYPE_LINE_PRIMARY_OUT,
    SAI_APS_PORT_TYPE_LINE_SECONDARY_OUT,
    SAI_APS_PORT_TYPE_COMMON_OUTPUT
} sai_aps_port_type_t;

/**
 * @brief APS port attribute IDs
 */
typedef enum _sai_aps_port_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_APS_PORT_ATTR_START,

    /**
     * @brief ID
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_APS_PORT_ATTR_ID = SAI_APS_PORT_ATTR_START,

    /**
     * @brief Port type
     *
     * @type sai_aps_port_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_APS_PORT_ATTR_PORT_TYPE,

    /**
     * @brief Power LOS threshold
     *
     * @type sai_double_t
     * @flags READ_ONLY
     */
    SAI_APS_PORT_ATTR_POWER_LOS_THRESHOLD,

    /**
     * @brief Power low threshold
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_PORT_ATTR_POWER_LOW_THRESHOLD,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_APS_PORT_ATTR_ENABLED,

    /**
     * @brief Target attenuation
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_APS_PORT_ATTR_TARGET_ATTENUATION,

    /**
     * @brief End of attributes
     */
    SAI_APS_PORT_ATTR_END,

    /** Custom range base value */
    SAI_APS_PORT_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_APS_PORT_ATTR_CUSTOM_RANGE_END

} sai_aps_port_attr_t;

/**
 * @brief APS port stat IDs
 *
 * @flags Contains flags
 */
typedef enum _sai_aps_port_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_APS_PORT_STAT_START,

    /**
     * @brief Optical power
     *
     * @type sai_double_t
     * @unit dBm
     * @iscounter false
     */
    SAI_APS_PORT_STAT_OPTICAL_POWER = SAI_APS_PORT_STAT_START,

    /**
     * @brief Attenuation
     *
     * @type sai_double_t
     * @unit dB
     * @iscounter false
     */
    SAI_APS_PORT_STAT_ATTENUATION,

    /**
     * @brief End of statistics
     */
    SAI_APS_PORT_STAT_END,

} sai_aps_port_stat_t;

/**
 * @brief Create APS port.
 *
 * Allocates and initializes a APS port.
 *
 * @param[out] aps_port_id APS port id
 * @param[in] switch_id switch id on which the APS port exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_aps_port_fn)(
        _Out_ sai_object_id_t *aps_port_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove APS port
 *
 * @param[in] aps_port_id APS port id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_aps_port_fn)(
        _In_ sai_object_id_t aps_port_id);

/**
 * @brief Set APS port attribute
 *
 * @param[in] aps_port_id APS port id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_aps_port_attribute_fn)(
        _In_ sai_object_id_t aps_port_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get APS port attribute
 *
 * @param[in] aps_port_id APS port id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_aps_port_attribute_fn)(
        _In_ sai_object_id_t aps_port_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get APS port statistics.
 *
 * @param[in] aps_port_id APS port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_aps_port_stats_fn)(
        _In_ sai_object_id_t aps_port_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Get APS port statistics extended.
 *
 * @param[in] aps_port_id APS port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_aps_port_stats_ext_fn)(
        _In_ sai_object_id_t aps_port_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Clear APS port statistics counters.
 *
 * @param[in] aps_port_id APS port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_aps_port_stats_fn)(
        _In_ sai_object_id_t aps_port_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_aps_port_api_t
{
    sai_create_aps_port_fn                create_aps_port;
    sai_remove_aps_port_fn                remove_aps_port;
    sai_set_aps_port_attribute_fn         set_aps_port_attribute;
    sai_get_aps_port_attribute_fn         get_aps_port_attribute;
    sai_get_aps_port_stats_fn             get_aps_port_stats;
    sai_get_aps_port_stats_ext_fn         get_aps_port_stats_ext;
    sai_clear_aps_port_stats_fn           clear_aps_port_stats;
} sai_aps_port_api_t;

/**
 * @}
 */
#endif /** __SAIAPSPORT_H_ */
