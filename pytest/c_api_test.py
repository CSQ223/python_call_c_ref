from pyextension.c_api import FlatRoute

if __name__ == "__main__":
    flat_route = FlatRoute()
    print(flat_route.exec(10))
    num_nodes = flat_route.get_num_nodes()
    print(num_nodes)
    for i in range(num_nodes):
        print("route[{}]={}".format(i, flat_route.get_node(i)))
