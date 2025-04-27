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
 * @file    sailldp.h
 * @brief   This module defines the lldp for the SAI
 */

#if !defined (__SAILLDP_H_)
#define __SAILLDP_H_

#include <saitypes.h>

/**
 * @defgroup SAILLDP SAI - LLDP specific API definitions
 *
 * @{
 */

/** @brief LLDP chassis id type */
typedef enum _sai_lldp_chassis_id_type_t
{
    SAI_LLDP_CHASSIS_ID_TYPE_CHASSIS_COMPONENT,
    SAI_LLDP_CHASSIS_ID_TYPE_INTERFACE_ALIAS,
    SAI_LLDP_CHASSIS_ID_TYPE_PORT_COMPONENT,
    SAI_LLDP_CHASSIS_ID_TYPE_MAC_ADDRESS,
    SAI_LLDP_CHASSIS_ID_TYPE_NETWORK_ADDRESS,
    SAI_LLDP_CHASSIS_ID_TYPE_INTERFACE_NAME,
    SAI_LLDP_CHASSIS_ID_TYPE_LOCAL,
} sai_lldp_chassis_id_type_t;

/** @brief LLDP port id type */
typedef enum _sai_lldp_port_id_type_t
{
    SAI_LLDP_PORT_ID_TYPE_INTERFACE_ALIAS,
    SAI_LLDP_PORT_ID_TYPE_PORT_COMPONENT,
    SAI_LLDP_PORT_ID_TYPE_MAC_ADDRESS,
    SAI_LLDP_PORT_ID_TYPE_NETWORK_ADDRESS,
    SAI_LLDP_PORT_ID_TYPE_INTERFACE_NAME,
    SAI_LLDP_PORT_ID_TYPE_AGENT_CIRCUIT_ID,
    SAI_LLDP_PORT_ID_TYPE_LOCAL,
} sai_lldp_port_id_type_t;

/**
 * @brief LLDP attribute IDs
 */
typedef enum _sai_lldp_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_LLDP_ATTR_START,

    /**
     * @brief The logical channel which lldp belongs to
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_LLDP_ATTR_CHANNEL_ID = SAI_LLDP_ATTR_START,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_LLDP_ATTR_ENABLED,

    /**
     * @brief Snooping
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_LLDP_ATTR_SNOOPING,

    /**
     * @brief Neighbor system name
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_SYSTEM_NAME,

    /**
     * @brief Neighbor system description
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_SYSTEM_DESCRIPTION,

    /**
     * @brief Neighbor chassis ID
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_CHASSIS_ID,

    /**
     * @brief Neighbor chassis ID type
     *
     * @type sai_lldp_chassis_id_type_t
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_CHASSIS_ID_TYPE,

    /**
     * @brief Neighbor ID
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_ID,

    /**
     * @brief Neighbor last update
     *
     * @type sai_int64_t
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_LAST_UPDATE,

    /**
     * @brief Neighbor port ID
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_PORT_ID,

    /**
     * @brief Neighbor port ID type
     *
     * @type sai_lldp_port_id_type_t
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_PORT_ID_TYPE,

    /**
     * @brief Neighbor port description
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_PORT_DESCRIPTION,

    /**
     * @brief Neighbor management address
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_MANAGEMENT_ADDRESS,

    /**
     * @brief Neighbor management address type
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_LLDP_ATTR_NEIGHBOR_MANAGEMENT_ADDRESS_TYPE,

    /**
     * @brief End of attributes
     */
    SAI_LLDP_ATTR_END,

    /** Custom range base value */
    SAI_LLDP_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_LLDP_ATTR_CUSTOM_RANGE_END

} sai_lldp_attr_t;

/**
 * @brief LLDP stat IDs
 */
typedef enum _sai_lldp_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_LLDP_STAT_START,

    /**
     * @brief A placeholder
     *
     * @type sai_uint64_t
     */
    SAI_LLDP_STAT_NOT_USE = SAI_LLDP_STAT_START,

    /**
     * @brief End of statistics
     */
    SAI_LLDP_STAT_END,

} sai_lldp_stat_t;

/**
 * @brief Create LLDP.
 *
 * Allocates and initializes a lldp.
 *
 * @param[out] lldp_id LLDP id
 * @param[in] switch_id switch id on which the lldp exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_lldp_fn)(
        _Out_ sai_object_id_t *lldp_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove lldp
 *
 * @param[in] lldp_id LLDP id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_lldp_fn)(
        _In_ sai_object_id_t lldp_id);

/**
 * @brief Set lldp attribute
 *
 * @param[in] lldp_id LLDP id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_lldp_attribute_fn)(
        _In_ sai_object_id_t lldp_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get lldp attribute
 *
 * @param[in] lldp_id LLDP id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_lldp_attribute_fn)(
        _In_ sai_object_id_t lldp_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get lldp statistics.
 *
 * @param[in] lldp_id LLDP id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_lldp_stats_fn)(
        _In_ sai_object_id_t lldp_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Get lldp statistics extended.
 *
 * @param[in] lldp_id LLDP id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_lldp_stats_ext_fn)(
        _In_ sai_object_id_t lldp_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Clear lldp statistics counters.
 *
 * @param[in] lldp_id LLDP id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_lldp_stats_fn)(
        _In_ sai_object_id_t lldp_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_lldp_api_t
{
    sai_create_lldp_fn                create_lldp;
    sai_remove_lldp_fn                remove_lldp;
    sai_set_lldp_attribute_fn         set_lldp_attribute;
    sai_get_lldp_attribute_fn         get_lldp_attribute;
    sai_get_lldp_stats_fn             get_lldp_stats;
    sai_get_lldp_stats_ext_fn         get_lldp_stats_ext;
    sai_clear_lldp_stats_fn           clear_lldp_stats;
} sai_lldp_api_t;

/**
 * @}
 */
#endif /** __SAILLDP_H_ */
