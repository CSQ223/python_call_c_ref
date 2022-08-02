#include "flat_route.h"

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

typedef struct _flat_route {
  int size;
  int* route;
} * _flat_route_t;

static std::vector<int> alns(int data) {
  std::vector<int> vec(data);
  for (int i = 0; i < data; i++) {
    vec[i] = rand();
  }
  std::sort(vec.begin(), vec.end());
  return vec;
}

LIB_API flat_route_t flat_route_new() {
  _flat_route_t flat_route = (_flat_route_t)malloc(sizeof(struct _flat_route));
  flat_route->size = 0;
  flat_route->route = NULL;

  return flat_route;
}

LIB_API int flat_route_exec(flat_route_t _flat_route, int data) {
  if (data <= 0)
    return -1;

  _flat_route_t flat_route = (_flat_route_t)_flat_route;
  if (NULL == flat_route)
    return -2;

  flat_route->route = (int*)malloc(sizeof(int) * data);
  if (NULL == flat_route->route)
    return -2;

  auto vec = alns(data);
  for (int i = 0; i < vec.size(); i++) {
    flat_route->route[i] = vec[i];
  }
  flat_route->size = vec.size();

  return 0;
}

LIB_API int flat_route_size(flat_route_t _flat_route) {
  _flat_route_t flat_route = (_flat_route_t)_flat_route;
  if (NULL == flat_route)
    return -2;

  return flat_route->size;
}

LIB_API int flat_route_get(flat_route_t _flat_route, int index) {
  _flat_route_t flat_route = (_flat_route_t)_flat_route;
  if (NULL == flat_route)
    return -2;
  if (NULL == flat_route->route)
    return -2;

  if (index < 0 || index >= flat_route->size)
    return -1;

  return flat_route->route[index];
}

LIB_API void flat_route_free(flat_route_t _flat_route) {
  _flat_route_t flat_route = (_flat_route_t)_flat_route;
  if (NULL != flat_route) {
    free(flat_route->route);
  }
  free(flat_route);
}
