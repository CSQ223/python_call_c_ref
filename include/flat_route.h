#ifndef PYTHON_CALL_C_REF_PYTHON_CALL_C_REF_C_OBJECT_H
#define PYTHON_CALL_C_REF_PYTHON_CALL_C_REF_C_OBJECT_H

#include "c_lib.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* flat_route_t;

LIB_API flat_route_t flat_route_new();

LIB_API int flat_route_exec(flat_route_t flat_route, int data);

LIB_API int flat_route_size(flat_route_t flat_route);

LIB_API int flat_route_get(flat_route_t flat_route, int index);

LIB_API void flat_route_free(flat_route_t flat_route);

#ifdef __cplusplus
}
#endif

#endif // PYTHON_CALL_C_REF_PYTHON_CALL_C_REF_C_OBJECT_H
