/**
 * @file HwAbstractionLayerI2cInterface.h
 * @author Aniket Sedhai (aniketsedhai@gmail.com)
 * @brief This file defines the Hardware Abstraction Layer Interface for I2C.
 * @version 0.1
 * @date 2024-10-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef HARDWARE_ABSTRACTION_LAYER_I2C_INTERFACE_H
#define HARDWARE_ABSTRACTION_LAYER_I2C_INTERFACE_H

/* ====================================================================================================================
 * INCLUDES
 * ====================================================================================================================
 */

#include <cstddef>
#include <cstdint>
#include <cstdbool>

namespace HwAbstractionLayerI2cInterfaceNamespace
{
    /* ================================================================================================================
     * PUBLIC ENUMERATIONS
     * ================================================================================================================
     */

    enum class hal_i2c_status_e
    {
        HAL_I2C_STATUS_SUCCESS = 0,
        HAL_I2C_STATUS_NULL_POINTER_ERROR,
    };
}

/* ====================================================================================================================
 * CLASS DECLARATION
 * ====================================================================================================================
 */

class HwAbstractionLayerI2cInterface
{
    public:

        virtual HwAbstractionLayerI2cInterfaceNamespace::hal_i2c_status_e hal_i2c_init(
            int32_t* ret_platform_specific_status_p) = 0;

        virtual HwAbstractionLayerI2cInterfaceNamespace::hal_i2c_status_e hal_i2c_set_frequency(
            uint32_t frequency_in_hz,
            int32_t* ret_platform_specific_status_p) = 0;

        virtual bool hal_i2c_is_initialized(void) = 0;

        virtual HwAbstractionLayerI2cInterfaceNamespace::hal_i2c_status_e hal_i2c_read_from_slave(
            uint32_t slave_address,
            uint32_t number_of_bytes_to_read,
            uint8_t* data_buffer_p,
            uint32_t size_of_buffer,
            bool repeated_reading = false) = 0;

        virtual HwAbstractionLayerI2cInterfaceNamespace::hal_i2c_status_e hal_i2c_write_to_slave(
            uint32_t slave_address,
            uint8_t* input_data_p,
            uint32_t number_of_bytes_to_write,
            bool repeated_writing) = 0;

        virtual HwAbstractionLayerI2cInterfaceNamespace::hal_i2c_status_e hal_i2c_create_start_condition(void) = 0;

        virtual HwAbstractionLayerI2cInterfaceNamespace::hal_i2c_status_e hal_i2c_create_stop_condition(void) = 0;

};


#endif /*HARDWARE_ABSTRACTION_LAYER_I2C_INTERFACE_H*/