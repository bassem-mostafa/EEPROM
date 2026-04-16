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

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef EEPROM_INTERNAL_H_
    #define EEPROM_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "EEPROM_Port.h"
    #include "driver/M95P32/EEPROM_M95P32.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef EEPROM_TIM
        #define EEPROM_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef EEPROM_LOG
        #define EEPROM_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define EEPROM_NAME       "EEPROM"
    #define EEPROM_LOG_PREFIX UTIL_StringConcatenateConstant( EEPROM_NAME, "> " )

    #ifdef DEBUG
        #define EEPROM_Raw( Level, Format, ... ) LOG_Raw( EEPROM_LOG, Level, Format, ##__VA_ARGS__ )
        #define EEPROM_Trace( Format, ... )      LOG_Trace( EEPROM_LOG, UTIL_StringConcatenateConstant( EEPROM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define EEPROM_Debug( Format, ... )      LOG_Debug( EEPROM_LOG, UTIL_StringConcatenateConstant( EEPROM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define EEPROM_Info( Format, ... )       LOG_Info( EEPROM_LOG, UTIL_StringConcatenateConstant( EEPROM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define EEPROM_Warning( Format, ... )    LOG_Warning( EEPROM_LOG, UTIL_StringConcatenateConstant( EEPROM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define EEPROM_Error( Format, ... )      LOG_Error( EEPROM_LOG, UTIL_StringConcatenateConstant( EEPROM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define EEPROM_Fatal( Format, ... )      LOG_Fatal( EEPROM_LOG, UTIL_StringConcatenateConstant( EEPROM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define EEPROM_Raw( Level, Format, ... )
        #define EEPROM_Trace( Format, ... )
        #define EEPROM_Debug( Format, ... )
        #define EEPROM_Info( Format, ... )
        #define EEPROM_Warning( Format, ... )
        #define EEPROM_Error( Format, ... )
        #define EEPROM_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct EEPROM_InstanceContext_t EEPROM_InstanceContext_t;

    typedef struct EEPROM_Instance
    {
        EEPROM_t EEPROMx;

        union
        {
            EEPROM_InstanceContext_t * Context;
            EEPROM_M95P32_Instance_t * M95P32;
        };
    } EEPROM_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    EEPROM_Status_t EEPROM_IsValid( EEPROM_t EEPROMx );

    EEPROM_Status_t EEPROM_Instance_Initialize( EEPROM_Instance_t * Instance );
    EEPROM_Status_t EEPROM_Instance_Cycle( EEPROM_Instance_t * Instance );
    EEPROM_Status_t EEPROM_Instance_DeInitialize( EEPROM_Instance_t * Instance );

    EEPROM_Status_t EEPROM_Instance_Write( EEPROM_Instance_t * Instance, EEPROM_Address_t Address, EEPROM_Data_t * Data, EEPROM_DataLength_t DataLength );
    EEPROM_Status_t EEPROM_Instance_Read( EEPROM_Instance_t * Instance, EEPROM_Address_t Address, EEPROM_Data_t * Data, EEPROM_DataLength_t DataLength );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* EEPROM_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
