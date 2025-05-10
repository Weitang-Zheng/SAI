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
 * @file    saimediachannel.h
 * @brief   This module defines the media channel for the SAI
 */

#if !defined (__SAIMEDIACHANNEL_H_)
#define __SAIMEDIACHANNEL_H_

#include <saitypes.h>

/**
 * @defgroup SAIMEDIACHANNEL SAI - media channel specific API definitions
 *
 * @{
 */

/**
 * @brief The attenuation control modes on a media channel.
 */
typedef enum _sai_media_channel_attenuation_control_mode_t
{
    SAI_MEDIA_CHANNEL_ATTENUATION_CONTROL_MODE_ATTENUATION_FIXED_LOSS,
    SAI_MEDIA_CHANNEL_ATTENUATION_CONTROL_MODE_ATTENUATION_DYNAMIC_LOSS,
    SAI_MEDIA_CHANNEL_ATTENUATION_CONTROL_MODE_ATTENUATION_DYNAMIC_LOSS_DAMPED,
    SAI_MEDIA_CHANNEL_ATTENUATION_CONTROL_MODE_MAX,
} sai_media_channel_attenuation_control_mode_t;

/**
 * @brief Media channel attribute IDs
 */
typedef enum _sai_media_channel_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_MEDIA_CHANNEL_ATTR_START,

    /**
     * @brief ID
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_MEDIA_CHANNEL_ATTR_ID = SAI_MEDIA_CHANNEL_ATTR_START,

    /**
     * @brief Lower frequency
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     */
    SAI_MEDIA_CHANNEL_ATTR_LOWER_FREQUENCY,

    /**
     * @brief Upper frequency
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     */
    SAI_MEDIA_CHANNEL_ATTR_UPPER_FREQUENCY,

    /**
     * @brief Admin status
     *
     * @type sai_admin_state_t
     * @flags CREATE_AND_SET
     */
    SAI_MEDIA_CHANNEL_ATTR_ADMIN_STATE,

    /**
     * @brief Super channel
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_MEDIA_CHANNEL_ATTR_SUPER_CHANNEL,

    /**
     * @brief Super channel parent
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_MEDIA_CHANNEL_ATTR_SUPER_CHANNEL_PARENT,

    /**
     * @brief Attenuation control mode
     *
     * @type sai_media_channel_attenuation_control_mode_t
     * @flags CREATE_AND_SET
     */
    SAI_MEDIA_CHANNEL_ATTR_ATTENUATION_CONTROL_MODE,

    /**
     * @brief Operational state
     *
     * @type sai_oper_status_t
     * @flags READ_ONLY
     */
    SAI_MEDIA_CHANNEL_ATTR_OPER_STATUS,

    /**
     * @brief Attenuation value
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags CREATE_AND_SET
     */
    SAI_MEDIA_CHANNEL_ATTR_ATTENUATION_VALUE,

    /**
     * @brief Wait to restore time
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_MEDIA_CHANNEL_ATTR_WAIT_TO_RESTORE_TIME,

    /**
     * @brief Target power
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags CREATE_AND_SET
     */
    SAI_MEDIA_CHANNEL_ATTR_TARGET_POWER,

    /**
     * @brief End of attributes
     */
    SAI_MEDIA_CHANNEL_ATTR_END,

    /** Custom range base value */
    SAI_MEDIA_CHANNEL_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_MEDIA_CHANNEL_ATTR_CUSTOM_RANGE_END

} sai_media_channel_attr_t;

/**
 * @brief Media channel stat IDs
 */
typedef enum _sai_media_channel_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_MEDIA_CHANNEL_STAT_START,

    /**
     * @brief Actual attenuation
     *
     * @type sai_uint64_t
     * @precision precision2
     * @unit dB
     * @iscounter false
     */
    SAI_MEDIA_CHANNEL_STAT_ACTUAL_ATTENUATION = SAI_MEDIA_CHANNEL_STAT_START,

    /**
     * @brief Input power
     *
     * @type sai_uint64_t
     * @precision precision2
     * @unit dBm
     * @iscounter false
     */
    SAI_MEDIA_CHANNEL_STAT_INPUT_POWER,

    /**
     * @brief Output power
     *
     * @type sai_uint64_t
     * @precision precision2
     * @unit dBm
     * @iscounter false
     */
    SAI_MEDIA_CHANNEL_STAT_OUTPUT_POWER,

    /**
     * @brief End of statistics
     */
    SAI_MEDIA_CHANNEL_STAT_END,

} sai_media_channel_stat_t;

/**
 * @brief Create media channel.
 *
 * Allocates and initializes a media channel.
 *
 * @param[out] media_channel_id Media channel id
 * @param[in] switch_id Switch id on which the media channel exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_media_channel_fn)(
        _Out_ sai_object_id_t *media_channel_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove media channel
 *
 * @param[in] media_channel_id Media channel id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_media_channel_fn)(
        _In_ sai_object_id_t media_channel_id);

/**
 * @brief Set media channel attribute
 *
 * @param[in] media_channel_id Media channel id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_media_channel_attribute_fn)(
        _In_ sai_object_id_t media_channel_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get media channel attribute
 *
 * @param[in] media_channel_id Media channel id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_media_channel_attribute_fn)(
        _In_ sai_object_id_t media_channel_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get media channel statistics.
 *
 * @param[in] media_channel_id Media channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_media_channel_stats_fn)(
        _In_ sai_object_id_t media_channel_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ uint64_t *counters);

/**
 * @brief Get media channel statistics extended.
 *
 * @param[in] media_channel_id Media channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_media_channel_stats_ext_fn)(
        _In_ sai_object_id_t media_channel_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ uint64_t *counters);

/**
 * @brief Clear media channel statistics counters.
 *
 * @param[in] media_channel_id Media channel id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_media_channel_stats_fn)(
        _In_ sai_object_id_t media_channel_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_media_channel_api_t
{
    sai_create_media_channel_fn                create_media_channel;
    sai_remove_media_channel_fn                remove_media_channel;
    sai_set_media_channel_attribute_fn         set_media_channel_attribute;
    sai_get_media_channel_attribute_fn         get_media_channel_attribute;
    sai_get_media_channel_stats_fn             get_media_channel_stats;
    sai_get_media_channel_stats_ext_fn         get_media_channel_stats_ext;
    sai_clear_media_channel_stats_fn           clear_media_channel_stats;
} sai_media_channel_api_t;

/**
 * @}
 */
#endif /** __SAIMEDIACHANNEL_H_ */
