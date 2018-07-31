

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from accident.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif        

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "accident.h"

#include <new>

/* ========================================================================= */
const char *AccidentTYPENAME = "Accident";

DDS_TypeCode* Accident_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Accident_g_tc_timestamp_string = DDS_INITIALIZE_STRING_TYPECODE((255));
    static DDS_TypeCode Accident_g_tc_route_string = DDS_INITIALIZE_STRING_TYPECODE((255));
    static DDS_TypeCode Accident_g_tc_vehicle_string = DDS_INITIALIZE_STRING_TYPECODE((255));
    static DDS_TypeCode_Member Accident_g_tc_members[4]=
    {

        {
            (char *)"timestamp",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"route",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"vehicle",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"stopNumber",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Accident_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Accident", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            Accident_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Accident*/

    if (is_initialized) {
        return &Accident_g_tc;
    }

    Accident_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&Accident_g_tc_timestamp_string;

    Accident_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&Accident_g_tc_route_string;

    Accident_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&Accident_g_tc_vehicle_string;

    Accident_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &Accident_g_tc;
}

RTIBool Accident_initialize(
    Accident* sample) {
    return Accident_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Accident_initialize_ex(
    Accident* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Accident_initialize_w_params(
        sample,&allocParams);

}

RTIBool Accident_initialize_w_params(
    Accident* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory){
        sample->timestamp= DDS_String_alloc ((255));
        if (sample->timestamp == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->timestamp!= NULL) { 
            sample->timestamp[0] = '\0';
        }
    }

    if (allocParams->allocate_memory){
        sample->route= DDS_String_alloc ((255));
        if (sample->route == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->route!= NULL) { 
            sample->route[0] = '\0';
        }
    }

    if (allocParams->allocate_memory){
        sample->vehicle= DDS_String_alloc ((255));
        if (sample->vehicle == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->vehicle!= NULL) { 
            sample->vehicle[0] = '\0';
        }
    }

    if (!RTICdrType_initLong(&sample->stopNumber)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void Accident_finalize(
    Accident* sample)
{

    Accident_finalize_ex(sample,RTI_TRUE);
}

void Accident_finalize_ex(
    Accident* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Accident_finalize_w_params(
        sample,&deallocParams);
}

void Accident_finalize_w_params(
    Accident* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->timestamp != NULL) {
        DDS_String_free(sample->timestamp);
        sample->timestamp=NULL;

    }
    if (sample->route != NULL) {
        DDS_String_free(sample->route);
        sample->route=NULL;

    }
    if (sample->vehicle != NULL) {
        DDS_String_free(sample->vehicle);
        sample->vehicle=NULL;

    }

}

void Accident_finalize_optional_members(
    Accident* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Accident_copy(
    Accident* dst,
    const Accident* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyStringEx (
            &dst->timestamp, src->timestamp, 
            (255) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyStringEx (
            &dst->route, src->route, 
            (255) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyStringEx (
            &dst->vehicle, src->vehicle, 
            (255) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->stopNumber, &src->stopNumber)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Accident' sequence class.
*/
#define T Accident
#define TSeq AccidentSeq

#define T_initialize_w_params Accident_initialize_w_params

#define T_finalize_w_params   Accident_finalize_w_params
#define T_copy       Accident_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

