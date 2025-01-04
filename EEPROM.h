// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

/**
 *  @file
 *
 *  @brief Platform EEPROM Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_EEPROM EEPROM
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_EEPROM_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef EEPROM_H_
    #define EEPROM_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include <stdint.h>

    #include "EEPROM_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief EEPROM Operation Status
     *
     *  @enum EEPROM_Status_t
     */
    typedef enum EEPROM_Status
    {
        EEPROM_Status_Success = 0,     ///< Success
        EEPROM_Status_ArgumentInvalid, ///< Invalid Argument
        EEPROM_Status_NotSupported,    ///< Not Supported
        EEPROM_Status_Error,           ///< General Error
        EEPROM_Status_Busy,            ///< Busy
        EEPROM_Status_Timeout,         ///< Timeout
    } EEPROM_Status_t;

    /**
     *  @brief EEPROM Address Type
     */
    typedef uint32_t EEPROM_Address_t;

    /**
     *  @brief EEPROM Data Type
     */
    typedef uint8_t EEPROM_Data_t;

    /**
     *  @brief EEPROM Data Length Type
     */
    typedef uint32_t EEPROM_DataLength_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize EEPROM instance
     *
     *  @note MUST BE called before using any EEPROM API
     *
     *  @param[in] EEPROMx Instance
     *
     *  @return EEPROM_Status_t
     */
    EEPROM_Status_t EEPROM_Initialize( EEPROM_t EEPROMx );

    /**
     *  @brief Cycle EEPROM instance
     *
     *  @param[in] EEPROMx Instance
     *
     *  @return EEPROM_Status_t
     */
    EEPROM_Status_t EEPROM_Cycle( EEPROM_t EEPROMx );

    /**
     *  @brief DeInitialize EEPROM instance
     *
     *  @param[in] EEPROMx Instance
     *
     *  @return EEPROM_Status_t
     */
    EEPROM_Status_t EEPROM_DeInitialize( EEPROM_t EEPROMx );

    /**
     *  @brief Writes data starting from address
     *
     *  @param[in] EEPROMx    EEPROM to use
     *  @param[in] Address    Starting address
     *  @param[in] Data       Data pointer
     *  @param[in] DataLength Length of data
     *
     *  @return EEPROM_Status_t
     */
    EEPROM_Status_t EEPROM_Write( EEPROM_t EEPROMx, EEPROM_Address_t Address, EEPROM_Data_t * Data, EEPROM_DataLength_t DataLength );

    /**
     *  @brief Reads data starting from address
     *
     *  @param[in] EEPROMx    EEPROM to use
     *  @param[in] Address    Starting address
     *  @param[in] Data       Data pointer
     *  @param[in] DataLength Length of data
     *
     *  @return EEPROM_Status_t
     */
    EEPROM_Status_t EEPROM_Read( EEPROM_t EEPROMx, EEPROM_Address_t Address, EEPROM_Data_t * Data, EEPROM_DataLength_t DataLength );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char EEPROM_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* EEPROM_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
