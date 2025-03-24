

#ifndef USER_APP_SENSOR_H_
#define USER_APP_SENSOR_H_

#define USING_APP_SENSOR

#define USING_APP_SENSOR_DEBUG

#define TIME_RESEND_WARNING         5
#define NUMBER_SAMPLING_SS          10


#include "event_driven.h"
#include "user_util.h"

typedef enum
{
    _EVENT_SENSOR_ENTRY,
    _EVENT_SENSOR_STATE_PH,
    _EVENT_SENSOR_STATE_CLO,
    _EVENT_SENSOR_STATE_EC,
    _EVENT_SENSOR_STATE_TURBIDITY,
    
    _EVENT_SENSOR_END,
}eKindEventSensor;

extern sEvent_struct        sEventAppSensor[];
/*=============== Function handle ================*/

uint8_t     AppSensor_Task(void);
void        Init_AppSensor(void);

void Log_EventWarnig(uint8_t Obis, uint8_t LengthData, uint8_t *aDataWaring);
void Save_TimeWarningSensor(uint8_t Duration);
void Init_TimeWarningSensor(void);

void AT_CMD_Get_Time_Warning_Sensor(sData *str, uint16_t Pos);
void AT_CMD_Set_Time_Warning_Sensor (sData *str_Receiv, uint16_t Pos);

void quickSort_Sampling(int16_t array_stt[],int16_t array_sampling[], uint8_t left, uint8_t right);
void quickSort_Sampling_pH(void);
void quickSort_Sampling_Clo(void);
void quickSort_Sampling_EC(void);
void quickSort_Sampling_Turbidity(void);
#endif
