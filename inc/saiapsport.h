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
 * @brief   This module defines the APSPORT for the SAI
 */

#if !defined (__SAIAPSPORT_H_)
#define __SAIAPSPORT_H_

#include <saitypes.h>

/**
 * @defgroup SAIAPSPORT SAI - APSPORT specific API definitions
 *
 * @{
 */

/** @brief APSPORT port type */
typedef enum _sai_apsport_port_type_t
{
    SAI_APSPORT_PORT_TYPE_LINE_PRIMARY_IN,
    SAI_APSPORT_PORT_TYPE_LINE_SECONDARY_IN,
    SAI_APSPORT_PORT_TYPE_COMMON_IN,
    SAI_APSPORT_PORT_TYPE_LINE_PRIMARY_OUT,
    SAI_APSPORT_PORT_TYPE_LINE_SECONDARY_OUT,
    SAI_APSPORT_PORT_TYPE_COMMON_OUTPUT
} sai_apsport_port_type_t;

/**
 * @brief APSPORT attribute IDs
 */
typedef enum _sai_apsport_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_APSPORT_ATTR_START,

    /**
     * @brief ID
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_APSPORT_ATTR_ID = SAI_APSPORT_ATTR_START,

    /**
     * @brief Port type
     *
     * @type sai_apsport_port_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_APSPORT_ATTR_PORT_TYPE,

    /**
     * @brief Power LOS threshold
     *
     * @type sai_double_t
     * @flags READ_ONLY
     */
    SAI_APSPORT_ATTR_POWER_LOS_THRESHOLD,

    /**
     * @brief Power low threshold
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_APSPORT_ATTR_POWER_LOW_THRESHOLD,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_APSPORT_ATTR_ENABLED,

    /**
     * @brief Target attenuation
     *
     * @type sai_double_t
     * @flags CREATE_AND_SET
     */
    SAI_APSPORT_ATTR_TARGET_ATTENUATION,

    /**
     * @brief End of attributes
     */
    SAI_APSPORT_ATTR_END,

    /** Custom range base value */
    SAI_APSPORT_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_APSPORT_ATTR_CUSTOM_RANGE_END

} sai_apsport_attr_t;

/**
 * @brief APSPORT stat IDs
 *
 * @flags Contains flags
 */
typedef enum _sai_apsport_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_APSPORT_STAT_START,

    /**
     * @brief Optical power
     *
     * @type sai_double_t
     * @unit dBm
     * @iscounter false
     */
    SAI_APSPORT_STAT_OPTICAL_POWER = SAI_APSPORT_STAT_START,

    /**
     * @brief Attenuation
     *
     * @type sai_double_t
     * @unit dB
     * @iscounter false
     */
    SAI_APSPORT_STAT_ATTENUATION,

    /**
     * @brief End of statistics
     */
    SAI_APSPORT_STAT_END,

} sai_apsport_stat_t;

/**
 * @brief Create APSPORT.
 *
 * Allocates and initializes a APSPORT.
 *
 * @param[out] apsport_id APSPORT id
 * @param[in] linecard_id Linecard id on which the APSPORT exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_apsport_fn)(
        _Out_ sai_object_id_t *apsport_id,
        _In_ sai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove APSPORT
 *
 * @param[in] apsport_id APSPORT id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_apsport_fn)(
        _In_ sai_object_id_t apsport_id);

/**
 * @brief Set APSPORT attribute
 *
 * @param[in] apsport_id APSPORT id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_apsport_attribute_fn)(
        _In_ sai_object_id_t apsport_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get APSPORT attribute
 *
 * @param[in] apsport_id APSPORT id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_apsport_attribute_fn)(
        _In_ sai_object_id_t apsport_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get APSPORT statistics.
 *
 * @param[in] apsport_id APSPORT id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_apsport_stats_fn)(
        _In_ sai_object_id_t apsport_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Get APSPORT statistics extended.
 *
 * @param[in] apsport_id APSPORT id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_apsport_stats_ext_fn)(
        _In_ sai_object_id_t apsport_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Clear APSPORT statistics counters.
 *
 * @param[in] apsport_id APSPORT id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_apsport_stats_fn)(
        _In_ sai_object_id_t apsport_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_apsport_api_t
{
    sai_create_apsport_fn                create_apsport;
    sai_remove_apsport_fn                remove_apsport;
    sai_set_apsport_attribute_fn         set_apsport_attribute;
    sai_get_apsport_attribute_fn         get_apsport_attribute;
    sai_get_apsport_stats_fn             get_apsport_stats;
    sai_get_apsport_stats_ext_fn         get_apsport_stats_ext;
    sai_clear_apsport_stats_fn           clear_apsport_stats;
} sai_apsport_api_t;

/**
 * @}
 */
#endif /** __SAIAPSPORT_H_ */
