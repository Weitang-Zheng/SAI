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
 * @file    saiotn.h
 * @brief   This module defines the OTN for the SAI
 */

#if !defined (__SAIOTN_H_)
#define __SAIOTN_H_

#include <saitypes.h>

/**
 * @defgroup SAIOTN SAI - OTN specific API definitions
 *
 * @{
 */

/** @brief Tributary slot granularity for OTN logical channels */
typedef enum _sai_otn_tributary_slot_granularity_t
{
    /**< The tributary slot with a bandwidth of approximately 1.25 Gigabyte/s */
    SAI_OTN_TRIBUTARY_SLOT_GRANULARITY_1_25G,

    /**< The tributary slot with a bandwidth of approximately 2.5 Gigabyte/s */
    SAI_OTN_TRIBUTARY_SLOT_GRANULARITY_2_5G,

    /**< The tributary slot with a bandwidth of approximately 5 Gigabyte/s */
    SAI_OTN_TRIBUTARY_SLOT_GRANULARITY_5G,
} sai_otn_tributary_slot_granularity_t;

/** @brief Delay measurement mode */
typedef enum _sai_otn_delay_measurement_mode_t
{
    SAI_OTN_DELAY_MEASUREMENT_MODE_LOOPBACK,
    SAI_OTN_DELAY_MEASUREMENT_MODE_MEASURE,
} sai_otn_delay_measurement_mode_t;

/** @brief Maintenance */
typedef enum _sai_otn_maintenance_t
{
    SAI_OTN_MAINTENANCE_AIS,
    SAI_OTN_MAINTENANCE_LCK,
    SAI_OTN_MAINTENANCE_OCI,
    SAI_OTN_MAINTENANCE_NONE,
} sai_otn_maintenance_t;

/**
 * @brief OTN attribute IDs
 */
typedef enum _sai_otn_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OTN_ATTR_START,

    /**
     * @brief The logical channel ID
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_ATTR_CHANNEL_ID = SAI_OTN_ATTR_START,

    /**
     * @brief Trail trace identifier (TTI) message transmitted
     *
     * @type char
     * @flags CREATE_AND_SET
     * @default empty
     */
    SAI_OTN_ATTR_TTI_MSG_TRANSMIT,

    /**
     * @brief Trail trace identifier (TTI) message expected
     *
     * @type char
     * @flags CREATE_AND_SET
     * @default empty
     */
    SAI_OTN_ATTR_TTI_MSG_EXPECTED,

    /**
     * @brief Trail trace identifier (TTI) message received
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OTN_ATTR_TTI_MSG_RECV,

    /**
     * @brief Remote defect indication (RDI) message received
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OTN_ATTR_RDI_MSG,

    /**
     * @brief Trail trace identifier (TTI) transmit message automatically created.
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_OTN_ATTR_TTI_MSG_AUTO,

    /**
     * @brief Delay measurement enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_OTN_ATTR_DELAY_MEASUREMENT_ENABLED,

    /**
     * @brief Delay measurement mode
     *
     * @type sai_otn_delay_measurement_mode_t
     * @flags CREATE_AND_SET
     */
    SAI_OTN_ATTR_DELAY_MEASUREMENT_MODE,

    /**
     * @brief Maintenance
     *
     * @type sai_otn_maintenance_t
     * @flags CREATE_AND_SET
     */
    SAI_OTN_ATTR_MAINTENANCE,

    /**
     * @brief End of attributes
     */
    SAI_OTN_ATTR_END,

    /** Custom range base value */
    SAI_OTN_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OTN_ATTR_CUSTOM_RANGE_END

} sai_otn_attr_t;

/**
 * @brief OTN counter IDs in sai_get_otn_stats() call
 *
 * @flags Contains flags
 */
typedef enum _sai_otn_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_OTN_STAT_START,

    /**
     * @brief Error-ed seconds
     *
     * The number of seconds that at least one error-ed blocks
     * occurs, at least one code violation occurs, loss of sync is
     * detected or loss of signal is detected.
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_ERRORED_SECONDS = SAI_OTN_STAT_START,

    /**
     * @brief Severely error-ed seconds
     *
     * The number of seconds that loss of frame is detected OR
     * the number of error-ed blocks, code violations, loss of sync
     * or loss of signal is detected exceeds a predefined
     * threshold.
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_SEVERELY_ERRORED_SECONDS,

    /**
     * @brief Unavailable seconds
     *
     * The number of seconds during which the link is unavailable
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_UNAVAILABLE_SECONDS,

    /**
     * @brief Error-ed blocks
     *
     * The number of error-ed blocks. Error detection codes are
     * capable to detect whether one or more errors have occurred
     * in a given sequence of bits.
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_ERRORED_BLOCKS,

    /**
     * @brief FEC uncorrectable blocks
     *
     * The number of blocks that were uncorrected by the FEC
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_FEC_UNCORRECTABLE_BLOCKS,

    /**
     * @brief FEC corrected bytes
     *
     * The number of bytes that were corrected by the FEC
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_FEC_CORRECTED_BYTES,

    /**
     * @brief FEC corrected bits
     *
     * The number of bits that were corrected by the FEC
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_FEC_CORRECTED_BITS,

    /**
     * @brief Background block errors
     *
     * The number of background block errors
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_BACKGROUND_BLOCK_ERRORS,

    /**
     * @brief Electrical signal to noise ratio
     *
     * @type sai_double_t
     * @unit dB
     * @precision precision2
     * @iscounter false
     */
    SAI_OTN_STAT_ESNR,

    /**
     * @brief Bit error rate before forward error correction
     *
     * @type sai_double_t
     * @precision precision18
     * @iscounter false
     */
    SAI_OTN_STAT_PRE_FEC_BER,

    /**
     * @brief Quality value (factor) in dB of a channel
     *
     * @type sai_double_t
     * @unit dB
     * @precision precision2
     * @iscounter false
     */
    SAI_OTN_STAT_Q_VALUE,

    /**
     * @brief Bit error rate after forward error correction
     *
     * @type sai_double_t
     * @precision precision18
     * @iscounter false
     */
    SAI_OTN_STAT_POST_FEC_BER,

    /**
     * @brief Delay
     *
     * @type sai_uint64_t
     * @iscounter false
     */
    SAI_OTN_STAT_DELAY,

    /**
     * @brief SM BIP8
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_SM_BIP8,

    /**
     * @brief SM BEI
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_SM_BEI,

    /**
     * @brief Q margin
     *
     * @type sai_double_t
     * @unit dB
     * @precision precision2
     * @iscounter false
     */
    SAI_OTN_STAT_Q_MARGIN,

    /**
     * @brief Input FEC corrected bits
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_INPUT_FEC_CORRECTED_BITS,

    /**
     * @brief Input FEC uncorrectable block
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_INPUT_FEC_UNCORRECTABLE_BLOCKS,

    /**
     * @brief Input SM BIP8
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_INPUT_SM_BIP8,

    /**
     * @brief Input SM BEI
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_INPUT_SM_BEI,

    /**
     * @brief Code violations
     *
     * @type sai_uint64_t
     * @iscounter true
     */
    SAI_OTN_STAT_CODE_VIOLATIONS,

    /**
     * @brief End of statistics
     */
    SAI_OTN_STAT_END,

} sai_otn_stat_t;

/**
 * @brief Create OTN.
 *
 * Allocates and initializes a OTN.
 *
 * @param[out] otn_id OTN id
 * @param[in] linecard_id Linecard id on which the OTN exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_otn_fn)(
        _Out_ sai_object_id_t *otn_id,
        _In_ sai_object_id_t linecard_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OTN
 *
 * @param[in] otn_id OTN id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_otn_fn)(
        _In_ sai_object_id_t otn_id);

/**
 * @brief Set OTN attribute
 *
 * @param[in] otn_id OTN id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_otn_attribute_fn)(
        _In_ sai_object_id_t otn_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OTN attribute
 *
 * @param[in] otn_id OTN id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_attribute_fn)(
        _In_ sai_object_id_t otn_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get OTN counters. Deprecated for backward compatibility.
 *
 * @param[in] otn_id OTN id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_stats_fn)(
        _In_ sai_object_id_t otn_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Get OTN statistics counters extended.
 *
 * @param[in] otn_id OTN id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_stats_ext_fn)(
        _In_ sai_object_id_t otn_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ sai_stat_value_t *counters);

/**
 * @brief Clear OTN statistics counters.
 *
 * @param[in] otn_id OTN id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_otn_stats_fn)(
        _In_ sai_object_id_t otn_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief OTN methods table retrieved with sai_api_query()
 */
typedef struct _sai_otn_api_t
{
    sai_create_otn_fn                create_otn;
    sai_remove_otn_fn                remove_otn;
    sai_set_otn_attribute_fn         set_otn_attribute;
    sai_get_otn_attribute_fn         get_otn_attribute;
    sai_get_otn_stats_fn             get_otn_stats;
    sai_get_otn_stats_ext_fn         get_otn_stats_ext;
    sai_clear_otn_stats_fn           clear_otn_stats;
} sai_otn_api_t;

/**
 * @}
 */
#endif /** __SAIOTN_H_ */
