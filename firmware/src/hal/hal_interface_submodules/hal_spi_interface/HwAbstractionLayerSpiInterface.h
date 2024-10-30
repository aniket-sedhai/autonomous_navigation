/**
 * @file HwAbstractionLayerSpiInterface.h
 * @author Aniket Sedhai (aniketsedhai@gmail.com)
 * @brief This file defines the hardware abstraction layer interface for SPI
 * @version 0.1
 * @date 2024-10-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef HARDWARE_ABSTRACTION_LAYER_SPI_INTERFACE_H
#define HARDWARE_ABSTRACTION_LAYER_SPI_INTERFACE_H

/* ====================================================================================================================
 * INCLUDES
 * ====================================================================================================================
 */

#include <cstdint>

namespace HwAbstractionLayerUartInterfaceNamespace
{
    /* ================================================================================================================
     * PUBLIC ENUMERATIONS
     * ================================================================================================================
     */

    enum class hal_spi_status_e
    {
        HAL_SPI_STATUS_SUCCESS = 0,
        HAL_SPI_STATUS_NULL_POINTER_ERROR,
    };
}

/* ====================================================================================================================
 * CLASS DECLARATION
 * ====================================================================================================================
 */

class HwAbstractionLayerSpiInterface
{
    public:

        /**
         * @brief HAL function for initializing SPI interface
         * 
         * @param is_spi_master 
         * @param ret_platform_specific_status_p 
         * @return HwAbstractionLayerUartInterfaceNamespace::hal_spi_status_e 
         */
        virtual HwAbstractionLayerUartInterfaceNamespace::hal_spi_status_e hal_spi_init(
            bool is_spi_master,
            int32_t* ret_platform_specific_status_p) = 0;

        virtual bool hal_spi_is_initialized(void) = 0;

        virtual HwAbstractionLayerUartInterfaceNamespace::hal_spi_status_e hal_spi_enable(
            int32_t* ret_platform_specific_status_p) = 0;

        virtual HwAbstractionLayerUartInterfaceNamespace::hal_spi_status_e hal_spi_disable(
            int32_t* ret_platform_specific_status_p) = 0;

        virtual HwAbstractionLayerUartInterfaceNamespace::hal_spi_status_e hal_spi_transaction(
            const uint8_t* spi_wrt_buffer_p,
            uint32_t spi_wrt_buf_size,
            uint8_t* spi_read_buffer_p,
            uint32_t spi_read_buffer_size,
            int32_t* ret_platform_specific_status_p) = 0;

        /**
         * @brief Destroy the Hw Abstraction Layer Spi Interface object
         * 
         */
        virtual ~HwAbstractionLayerSpiInterface(){}

    protected:
        
        /**
         * @brief Default constructor for a new Hw Abstraction Layer Spi Interface object.
         * 
         */
        HwAbstractionLayerSpiInterface(){}

    private:

        // NONE
};

#endif /*HARDWARE_ABSTRACTION_LAYER_SPI_INTERFACE_H*/