#include <stdio.h>
#include <stdlib.h>
#ifdef RTI_VX653
#include <vThreadsData.h>
#endif
#include "accident.h"
#include "accidentSupport.h"
#include "ndds/ndds_cpp.h"

extern int user_o;  //user_o = 0 if it is operator; else = 1
extern int on_bus;  // 0 = on_bus,  1 = wait for bus
extern int loop_over;  // 0= arrive destination
extern int finish;     //check whether go to destination
extern char route[10];
extern char currentbus[6];
extern int start_stop,end_stop;
extern int accident_stop; // if  accident happen, then set accident_stop to stop number ;no accident will be 0
extern int debug;  //debug = 0 to show debug message
extern int n_stops;

class AccidentListener : public DDSDataReaderListener {
  public:
    virtual void on_requested_deadline_missed(
        DDSDataReader* /*reader*/,
        const DDS_RequestedDeadlineMissedStatus& /*status*/) {}

    virtual void on_requested_incompatible_qos(
        DDSDataReader* /*reader*/,
        const DDS_RequestedIncompatibleQosStatus& /*status*/) {}

    virtual void on_sample_rejected(
        DDSDataReader* /*reader*/,
        const DDS_SampleRejectedStatus& /*status*/) {}

    virtual void on_liveliness_changed(
        DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {}

    virtual void on_sample_lost(
        DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {}

    virtual void on_subscription_matched(
        DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus& /*status*/) {}

    virtual void on_data_available(DDSDataReader* reader);
};
