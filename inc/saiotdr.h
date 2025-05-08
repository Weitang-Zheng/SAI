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
 * @file    saiotdr.h
 * @brief   This module defines the OTDR for the SAI
 */

#if !defined (__SAIOTDR_H_)
#define __SAIOTDR_H_

#include <saitypes.h>

/**
 * @defgroup SAIOTDR SAI - OTDR specific API definitions
 *
 * @{
 */

/**
 * @brief Enum defining OTDR event types.
 */
typedef enum _sai_otdr_event_type_t
{
    SAI_OTDR_EVENT_TYPE_START,
    SAI_OTDR_EVENT_TYPE_END,
    SAI_OTDR_EVENT_TYPE_REFLECTION,
    SAI_OTDR_EVENT_TYPE_NON_REFLECTION,
    SAI_OTDR_EVENT_TYPE_FIBER_SECTION,
    SAI_OTDR_EVENT_TYPE_UNKOWN,
} sai_otdr_event_type_t;

/** @brief Scanning status */
typedef enum _sai_scanning_status_t
{
    SAI_SCANNING_STATUS_ACTIVE,
    SAI_SCANNING_STATUS_INACTIVE,
} sai_scanning_status_t;

typedef struct _sai_otdr_event_t
{
    sai_otdr_event_type_t type;

    /** Event distance or fiber section length in km */
    sai_uint64_t length;

    /** Event loss in dB */
    sai_uint64_t loss;

    /** Event reflection in dB */
    sai_uint64_t reflection;

    /** Accumulated loss at the event point */
    sai_uint64_t accumulate_loss;
} sai_otdr_event_t;

typedef struct _sai_otdr_event_list_t
{
    uint32_t count;
    sai_otdr_event_t *list;
} sai_otdr_event_list_t;

typedef struct _sai_otdr_events_t
{
    /** Total length in km */
    sai_uint64_t span_distance;

    /** Total loss in dB */
    sai_uint64_t span_loss;

    sai_otdr_event_list_t events;

} sai_otdr_events_t;

typedef struct _sai_otdr_scanning_profile_t
{
    sai_uint64_t scan_time;

    /** Distance range in km */
    sai_uint32_t distance_range;

    /** Pulse width in nanosecond */
    sai_uint32_t pulse_width;

    /** Average time of each scanning in second */
    sai_uint32_t average_time;

    /** The output frequency in MHz of the OTDR */
    sai_uint64_t output_frequency;

} sai_otdr_scanning_profile_t;

typedef struct _sai_otdr_result_trace_t
{
    sai_uint64_t update_time;
    sai_u8_list_t data;
} sai_otdr_result_trace_t;

typedef struct _sai_otdr_result_t
{
    sai_otdr_scanning_profile_t scanning_profile;
    sai_otdr_events_t events;
    sai_otdr_result_trace_t trace;
} sai_otdr_result_t;

/**
 * @brief OTDR attribute IDs
 */
typedef enum _sai_otdr_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OTDR_ATTR_START,

    /**
     * @brief Id
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTDR_ATTR_ID = SAI_OTDR_ATTR_START,

    /**
     * @brief Refractive index
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_REFRACTIVE_INDEX,

    /**
     * @brief Backscatter index
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_BACKSCATTER_INDEX,

    /**
     * @brief Reflection threshold
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_REFLECTION_THRESHOLD,

    /**
     * @brief Splice loss threshold
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_SPLICE_LOSS_THRESHOLD,

    /**
     * @brief End of fiber threshold
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_END_OF_FIBER_THRESHOLD,

    /**
     * @brief Distance range
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_DISTANCE_RANGE,

    /**
     * @brief Pulse width
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_PULSE_WIDTH,

    /**
     * @brief Average time
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_AVERAGE_TIME,

    /**
     * @brief Output frequency
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_OUTPUT_FREQUENCY,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_ENABLED,

    /**
     * @brief Scan
     *
     * @type bool
     * @flags SET_ONLY
     * @isrecoverable false
     */
    SAI_OTDR_ATTR_SCAN,

    /**
     * @brief Start time
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_START_TIME,

    /**
     * @brief Period
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_OTDR_ATTR_PERIOD,

    /**
     * @brief Dynamic range
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     */
    SAI_OTDR_ATTR_DYNAMIC_RANGE,

    /**
     * @brief Distance accuracy
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags READ_ONLY
     */
    SAI_OTDR_ATTR_DISTANCE_ACCURACY,

    /**
     * @brief Sampling resolution
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags READ_ONLY
     */
    SAI_OTDR_ATTR_SAMPLING_RESOLUTION,

    /**
     * @brief Loss dead zone
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags READ_ONLY
     */
    SAI_OTDR_ATTR_LOSS_DEAD_ZONE,

    /**
     * @brief Reflection dead zone
     *
     * @type sai_uint64_t
     * @precision precision2
     * @flags READ_ONLY
     */
    SAI_OTDR_ATTR_REFLECTION_DEAD_ZONE,

    /**
     * @brief Scanning status
     *
     * @type sai_scanning_status_t
     * @flags READ_ONLY
     */
    SAI_OTDR_ATTR_SCANNING_STATUS,

    /**
     * @brief The operational state of the OTDR
     *
     * @type sai_oper_status_t
     * @flags READ_ONLY
     */
    SAI_OTDR_ATTR_OPER_STATUS,

    /**
     * @brief End of attributes
     */
    SAI_OTDR_ATTR_END,

    /** Custom range base value */
    SAI_OTDR_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OTDR_ATTR_CUSTOM_RANGE_END

} sai_otdr_attr_t;

/**
 * @brief OTDR stat IDs
 */
typedef enum _sai_otdr_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_OTDR_STAT_START,

    /**
     * @brief A placeholder
     *
     * @type sai_uint64_t
     */
    SAI_OTDR_STAT_NOT_USE = SAI_OTDR_STAT_START,

    /**
     * @brief End of statistics
     */
    SAI_OTDR_STAT_END,

} sai_otdr_stat_t;

/**
 * @brief OTDR scan result notification
 *
 * @param[in] switch_id Switch Id
 * @param[in] otdr_id OTDR Id
 * @param[in] otdr_result OTDR result
 */
typedef void (*sai_otdr_scan_result_notification_fn)(
        _In_ sai_object_id_t switch_id,
        _In_ sai_object_id_t otdr_id,
        _In_ sai_otdr_result_t otdr_result);

/**
 * @brief Create OTDR.
 *
 * Allocates and initializes a OTDR.
 *
 * @param[out] otdr_id OTDR id
 * @param[in] switch_id Switch id on which the OTDR exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_otdr_fn)(
        _Out_ sai_object_id_t *otdr_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OTDR
 *
 * @param[in] otdr_id OTDR id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_otdr_fn)(
        _In_ sai_object_id_t otdr_id);

/**
 * @brief Set OTDR attribute
 *
 * @param[in] otdr_id OTDR id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_otdr_attribute_fn)(
        _In_ sai_object_id_t otdr_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OTDR attribute
 *
 * @param[in] otdr_id OTDR id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otdr_attribute_fn)(
        _In_ sai_object_id_t otdr_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get OTDR statistics.
 *
 * @param[in] otdr_id OTDR id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otdr_stats_fn)(
        _In_ sai_object_id_t otdr_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ uint64_t *counters);

/**
 * @brief Get OTDR statistics extended.
 *
 * @param[in] otdr_id OTDR id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otdr_stats_ext_fn)(
        _In_ sai_object_id_t otdr_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ uint64_t *counters);

/**
 * @brief Clear OTDR statistics counters.
 *
 * @param[in] otdr_id OTDR id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_otdr_stats_fn)(
        _In_ sai_object_id_t otdr_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_otdr_api_t
{
    sai_create_otdr_fn                create_otdr;
    sai_remove_otdr_fn                remove_otdr;
    sai_set_otdr_attribute_fn         set_otdr_attribute;
    sai_get_otdr_attribute_fn         get_otdr_attribute;
    sai_get_otdr_stats_fn             get_otdr_stats;
    sai_get_otdr_stats_ext_fn         get_otdr_stats_ext;
    sai_clear_otdr_stats_fn           clear_otdr_stats;
} sai_otdr_api_t;

/**
 * @}
 */
#endif /** __SAIOTDR_H_ */
