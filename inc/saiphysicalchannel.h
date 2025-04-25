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
 * @file    saiphysicalchannel.h
 * @brief   This module defines the physical channel for the SAI
 */

#if !defined (__SAIPHYSICALCHANNEL_H_)
#define __SAIPHYSICALCHANNEL_H_

#include <saitypes.h>

/**
 * @defgroup SAIPHYSICALCHANNEL SAI - Physical channel specific API definitions
 *
 * @{
 */

/**
 * @brief Physical channel attribute IDs
 */
typedef enum _sai_physicalchannel_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_PHYSICALCHANNEL_ATTR_START,

    /**
     * @brief Port ID.
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_PHYSICALCHANNEL_ATTR_PORT_ID = SAI_PHYSICALCHANNEL_ATTR_START,

    /**
     * @brief Optical port type
     *
     * @type sai_optical_port_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_PHYSICALCHANNEL_ATTR_PORT_TYPE,

    /**
     * @brief Lane ID.
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_PHYSICALCHANNEL_ATTR_LANE_ID,

    /**
     * @brief Tx laser
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_PHYSICALCHANNEL_ATTR_TX_LASER,

    /**
     * @brief The frequency in MHz of the individual physical channel
     *
     * @type sai_uint64_t
     * @flags READ_ONLY
     */
    SAI_PHYSICALCHANNEL_ATTR_OUTPUT_FREQUENCY,

    /**
     * @brief End of attributes
     */
    SAI_PHYSICALCHANNEL_ATTR_END,

    /** Custom range base value */
    SAI_PHYSICALCHANNEL_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_PHYSICALCHANNEL_ATTR_CUSTOM_RANGE_END

} sai_physicalchannel_attr_t;

/**
 * @brief Physical channel stat IDs in sai_get_physicalchannel_stats() call
 *
 * @flags Contains flags
 */
typedef enum _sai_physicalchannel_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_PHYSICALCHANNEL_STAT_START,

    /**
     * @brief Output power
     *
     * @type sai_double_t
     * @unit dBm
     * @iscounter false
     */
    SAI_PHYSICALCHANNEL_STAT_OUTPUT_POWER = SAI_PHYSICALCHANNEL_STAT_START,

    /**
     * @brief Input power
     *
     * @type sai_double_t
     * @unit dBm
     * @iscounter false
     */
    SAI_PHYSICALCHANNEL_STAT_INPUT_POWER,

    /**
     * @brief Laser bias current
     *
     * @type sai_double_t
     * @iscounter false
     */
    SAI_PHYSICALCHANNEL_STAT_LASER_BIAS_CURRENT,

    /**
     * @brief End of statistics
     */
    SAI_PHYSICALCHANNEL_STAT_END,

} sai_physicalchannel_stat_t;

/**
 * @brief Create physical channel.
 *
 * Allocates and initializes a physical channel.
 *
 * @param[out] physicalchannel_id Physical channel id
 * @param[in] switch_id switch id on which the physical channel exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_physicalchannel_fn)(
        _Out_ sai_object_id_t *physicalchannel_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove physical channel
 *
 * @param[in] physicalchannel_id Physical channel id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_physicalchannel_fn)(
        _In_ sai_object_id_t physicalchannel_id);

/**
 * @brief Set physical channel attribute
 *
 * @param[in] physicalchannel_id Physical channel id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_physicalchannel_attribute_fn)(
        _In_ sai_object_id_t physicalchannel_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get physical channel attribute
 *
 * @param[in] physicalchannel_id Physical channel id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_physicalchannel_attribute_fn)(
        _In_ sai_object_id_t physicalchannel_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get physical channel counters. Deprecated for backward compatibility.
 *
 * @param[in] physicalchannel_id Physical channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_physicalchannel_stats_fn)(
        _In_ sai_object_id_t physicalchannel_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Get physical channel statistics counters extended.
 *
 * @param[in] physicalchannel_id Physical channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_physicalchannel_stats_ext_fn)(
        _In_ sai_object_id_t physicalchannel_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Clear physical channel statistics counters.
 *
 * @param[in] physicalchannel_id Physical channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_physicalchannel_stats_fn)(
        _In_ sai_object_id_t physicalchannel_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_physicalchannel_api_t
{
    sai_create_physicalchannel_fn              create_physicalchannel;
    sai_remove_physicalchannel_fn              remove_physicalchannel;
    sai_set_physicalchannel_attribute_fn       set_physicalchannel_attribute;
    sai_get_physicalchannel_attribute_fn       get_physicalchannel_attribute;
    sai_get_physicalchannel_stats_fn           get_physicalchannel_stats;
    sai_get_physicalchannel_stats_ext_fn       get_physicalchannel_stats_ext;
    sai_clear_physicalchannel_stats_fn         clear_physicalchannel_stats;
} sai_physicalchannel_api_t;

/**
 * @}
 */
#endif /** __SAIPHYSICALCHANNEL_H_ */
