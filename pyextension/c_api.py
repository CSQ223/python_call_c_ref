from ctypes import CDLL
import sys

print(sys.prefix)

_flat_lib = None
if sys.platform == "win32":
    _flat_lib = CDLL("./bin/c_api.dll")
elif sys.platform == "linux":
    _flat_lib = CDLL("./bin/libc_api.so")


class FlatRoute(object):
    flat_lib = _flat_lib

    @staticmethod
    def exec(data: int) -> int:
        status = FlatRoute.flat_lib.c_api_exec(data)
        return status

    @staticmethod
    def get_num_nodes() -> int:
        return FlatRoute.flat_lib.c_api_get_num_nodes()

    @staticmethod
    def get_node(index: int) -> int:
        return FlatRoute.flat_lib.c_api_get_node(index)

    def __del__(self):
        FlatRoute.flat_lib.c_api_exit()


if __name__ == "__main__":
    flat_route = FlatRoute()
    print(flat_route.exec(10))
    num_nodes = flat_route.get_num_nodes()
    print(num_nodes)
    for i in range(num_nodes):
        print("route[{}]={}".format(i, flat_route.get_node(i)))
