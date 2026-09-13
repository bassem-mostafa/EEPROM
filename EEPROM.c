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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "EEPROM.h"
#include "EEPROM_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

EEPROM_Status_t EEPROM_Initialize( EEPROM_t EEPROMx )
{
    EEPROM_Status_t Status = EEPROM_Status_Success;

    do
    {
        EEPROM_Trace( "%s( EEPROMx=%d )", __FUNCTION__, EEPROMx );

        if ( ( Status = EEPROM_Port_Initialize( EEPROMx ) ) != EEPROM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

EEPROM_Status_t EEPROM_Cycle( EEPROM_t EEPROMx )
{
    EEPROM_Status_t Status = EEPROM_Status_Success;

    do
    {
        EEPROM_Trace( "%s( EEPROMx=%d )", __FUNCTION__, EEPROMx );

        if ( ( Status = EEPROM_Port_Cycle( EEPROMx ) ) != EEPROM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

EEPROM_Status_t EEPROM_DeInitialize( EEPROM_t EEPROMx )
{
    EEPROM_Status_t Status = EEPROM_Status_Success;

    do
    {
        EEPROM_Trace( "%s( EEPROMx=%d )", __FUNCTION__, EEPROMx );

        if ( ( Status = EEPROM_Port_DeInitialize( EEPROMx ) ) != EEPROM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

EEPROM_Status_t EEPROM_Write( EEPROM_t EEPROMx, EEPROM_Address_t Address, EEPROM_Data_t * Data, EEPROM_DataLength_t DataLength )
{
    EEPROM_Status_t Status = EEPROM_Status_Success;

    do
    {
        EEPROM_Trace( "%s( EEPROM=%d, Address=%08X, Data=%p, Length=%d )", __FUNCTION__, EEPROMx, Address, Data, DataLength );

        if ( ( Status = EEPROM_Port_Write( EEPROMx, Address, Data, DataLength ) ) != EEPROM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

EEPROM_Status_t EEPROM_Read( EEPROM_t EEPROMx, EEPROM_Address_t Address, EEPROM_Data_t * Data, EEPROM_DataLength_t DataLength )
{
    EEPROM_Status_t Status = EEPROM_Status_Success;

    do
    {
        EEPROM_Trace( "%s( EEPROM=%d, Address=%08X, Data=%p, Length=%d )", __FUNCTION__, EEPROMx, Address, Data, DataLength );

        if ( ( Status = EEPROM_Port_Read( EEPROMx, Address, Data, DataLength ) ) != EEPROM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char EEPROM_VERSION[] = "0.0.0.v20260913-1832";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
