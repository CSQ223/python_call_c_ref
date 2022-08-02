#ifndef PYTHON_CALL_C_REF_PYTHON_CALL_C_REF_C_API_H
#define PYTHON_CALL_C_REF_PYTHON_CALL_C_REF_C_API_H

#include "c_lib.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /// run algorithm
    LIB_API int c_api_exec(int data);

    /// get the number of nodes
    LIB_API int c_api_get_num_nodes();

    /// get then node at index
    LIB_API int c_api_get_node(int index);

    /// clear
    LIB_API void c_api_exit();

#ifdef __cplusplus
}
#endif

#endif // PYTHON_CALL_C_REF_PYTHON_CALL_C_REF_C_API_H
