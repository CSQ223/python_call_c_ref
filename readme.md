1. 编译动态库及测试文件

```
mkdir build
cd build
cmake ..
make
```


2. 执行python测试文件

```
cd ..
python3 pytest/c_api_test.py
python3 pytest/flat_route_test.py
```
