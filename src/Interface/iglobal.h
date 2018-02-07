#ifndef IGLOBAL_H
#define IGLOBAL_H

#include "RTData/irtdata.h"
#include "AlarmData/ialarmdata.h"
#include "Drivers/idrivermgr.h"

class iGlobal{

public:
    explicit iGlobal(){}
    virtual ~iGlobal(){}

    virtual iRTData* RTData()const=0;
    virtual iDriverMgr* DriverMgr()const=0;

#ifdef APPSERVER_WITH_ALARMDATA
    virtual iAlarmData* AlarmData()const=0;
#endif

#ifdef APPSERVER_WITH_WEBSERVER
//    iAppWebServer* AppWebServer()const=0;
#endif
};
#endif // IGLOBAL_H
