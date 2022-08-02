from ctypes import *
import sys


_flat_lib = None
if sys.platform == "win32":
    _flat_lib = CDLL("./bin/flat_route.dll")
elif sys.platform == "linux":
    _flat_lib = CDLL("./bin/libflat_route.so")


_flat_lib.flat_route_new.restype = c_void_p
_flat_lib.flat_route_exec.argtypes = (c_void_p, c_int)
_flat_lib.flat_route_size.argtypes = (c_void_p,)
_flat_lib.flat_route_get.argtypes = (c_void_p, c_int)
_flat_lib.flat_route_free.argtypes = (c_void_p,)


class FlatRoute(object):
    def __init__(self) -> None:
        self.flat_route = _flat_lib.flat_route_new()

    def __del__(self):
        _flat_lib.flat_route_free(self.flat_route)

    def exec(self, data: int) -> int:
        return _flat_lib.flat_route_exec(self.flat_route, data)

    def get_num_nodes(self) -> int:
        return _flat_lib.flat_route_size(self.flat_route)

    def get_node(self, index) -> int:
        return _flat_lib.flat_route_get(self.flat_route, index)


if __name__ == "__main__":
    flat_route = FlatRoute()
    print(flat_route.exec(10))
    num_nodes = flat_route.get_num_nodes()
    print(num_nodes)
    for i in range(num_nodes):
        print("route[{}]={}".format(i, flat_route.get_node(i)))
