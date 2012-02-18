#include "pocl_cl.h"
CL_API_ENTRY cl_int CL_API_CALL
clEnqueueTask(cl_command_queue   command_queue,
              cl_kernel          kernel,
              cl_uint            num_events_in_wait_list,
              const cl_event *   event_wait_list,
              cl_event *         event ) CL_API_SUFFIX__VERSION_1_0
{
    const size_t globalWS=1; 
    const size_t localWS=1; 
    return clEnqueueNDRangeKernel( command_queue,
                                   kernel, 
                                   1 /*work_dim*/,
                                   NULL /*global_work_offset*/,
                                   &globalWS,
                                   &localWS,
                                   num_events_in_wait_list,
                                   event_wait_list,
                                   event);
}

