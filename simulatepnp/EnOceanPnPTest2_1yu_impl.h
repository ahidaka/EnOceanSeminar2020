/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.9.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 2020/06/08
 ***********************************************************************************************/

#ifndef ENOCEANPNPTEST2_1YU_IMPL
#define ENOCEANPNPTEST2_1YU_IMPL

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "azure_c_shared_utility/xlogging.h"
#include "azure_c_shared_utility/threadapi.h"
#include "parson.h"

/**
* Type definition
*/

typedef enum ENOCEANPNPTEST2_SENSOR_ACCELERATIONSTATUS_TAG
{
    ENOCEANPNPTEST2_SENSOR_ACCELERATIONSTATUS_periodicupdate = 0,
    ENOCEANPNPTEST2_SENSOR_ACCELERATIONSTATUS_threshold1Exceeded = 1,
    ENOCEANPNPTEST2_SENSOR_ACCELERATIONSTATUS_threshold2exceeded = 2,
    ENOCEANPNPTEST2_SENSOR_ACCELERATIONSTATUS_UNDEFINED
} ENOCEANPNPTEST2_SENSOR_ACCELERATIONSTATUS;

typedef enum ENOCEANPNPTEST2_SENSOR_CONTACT_TAG
{
    ENOCEANPNPTEST2_SENSOR_CONTACT_open = 0,
    ENOCEANPNPTEST2_SENSOR_CONTACT_close = 1,
    ENOCEANPNPTEST2_SENSOR_CONTACT_UNDEFINED
} ENOCEANPNPTEST2_SENSOR_CONTACT;

/**
* Device telemetries related methods.
*/

double EnOceanPnPTest2_sensor_Telemetry_ReadTemperature();

double EnOceanPnPTest2_sensor_Telemetry_ReadHumidity();

double EnOceanPnPTest2_sensor_Telemetry_ReadIllumination();

ENOCEANPNPTEST2_SENSOR_ACCELERATIONSTATUS EnOceanPnPTest2_sensor_Telemetry_ReadAccelerationstatus();

double EnOceanPnPTest2_sensor_Telemetry_ReadAccelerationx();

double EnOceanPnPTest2_sensor_Telemetry_ReadAccelerationy();

double EnOceanPnPTest2_sensor_Telemetry_ReadAccelerationz();

ENOCEANPNPTEST2_SENSOR_CONTACT EnOceanPnPTest2_sensor_Telemetry_ReadContact();

/**
* Device properties related methods.
*/

char* DeviceInformation_5kj_Property_GetManufacturer();

char* DeviceInformation_5kj_Property_GetModel();

char* DeviceInformation_5kj_Property_GetSwVersion();

char* DeviceInformation_5kj_Property_GetOsName();

char* DeviceInformation_5kj_Property_GetProcessorArchitecture();

char* DeviceInformation_5kj_Property_GetProcessorManufacturer();

long DeviceInformation_5kj_Property_GetTotalStorage();

long DeviceInformation_5kj_Property_GetTotalMemory();

/**
* Device commands related methods.
*/

// Callbacks to handle the confirmation result of sending telemetry
void SendTelemetry_Succeeded_Callback(const char* interfaceName);
void SendTelemetry_Error_Callback(const char* interfaceName);

// Callbacks to handle the confirmation result of reporting property
void ReportProperty_Succeeded_Callback(const char* interfaceName, const char* propertyName);
void ReportProperty_Error_Callback(const char* interfaceName, const char* propertyName);

#ifdef __cplusplus
}
#endif

#endif // ENOCEANPNPTEST2_1YU_IMPL
