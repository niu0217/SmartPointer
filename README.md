# SmartPointer

## 参考资料

https://zhuanlan.zhihu.com/p/354849447



## 自己实现unique_ptr

[MyUniquePtr.cpp](https://github.com/niu0217/SmartPointer/blob/main/code/MyUniquePtr.cpp)

根据C++的规则，我们提供了移动构造而没有提供拷贝构造，那拷贝构造就自动被禁用。
