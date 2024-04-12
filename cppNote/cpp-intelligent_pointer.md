# C++智能指针

## 为什么使用智能指针？

> 如果我们把分配的动态内存都交给有生命周期的对象来处理，当对象的生命周期结束时，自动调用对象的析构函数删除删除该对象指向的内存，可有效解决内存泄漏的问题。





```cpp
#include <iostream>
using namespace std;

void memory_leak_demo_1() {
	string* str = new string("这是一段动态分配在堆区的内存，不要忘记手动释放内存！");
	cout << *str << endl;//str作为局部变量存储在栈区，当函数的调用结束后会自动释放。
	delete str;
	return;
}

void memory_noleak_demo_1() {
	string str("这是也一段分配在堆区的内存，但当str的生命周期结束时，会自动执行析构函数自动释放该块内存~~~");
	cout << str << endl; //str作为局部变量存储在栈区，当函数的调用结束后会自动释放。
}

int main() {
	memory_leak_demo_1();
	memory_noleak_demo_1();
	return 0;
}
```



## `auto_ptr`（C++98）

在C++中，`auto_ptr` 已被弃用（deprecated），并且在C++11标准中被 `unique_ptr` 替代。因此，推荐使用 `unique_ptr` 代替 `auto_ptr`。

## `unique_ptr`(C++11)

- `std::unique_ptr` 是独占所有权的智能指针，用于管理动态分配的单一对象。当 `std::unique_ptr` 被销毁时，它将自动释放所管理的内存。

- 示例：

   ```cpp
   #include <memory>
   
   int main() {
       std::unique_ptr<int> myUniquePtr = std::make_unique<int>(42);
     
       // 使用myUniquePtr操作资源
     
       return 0; // 在main函数结束时，myUniquePtr会自动释放内存
   }
   ```

## `shared_ptr`(C++11)

- `std::shared_ptr` 允许多个智能指针共享同一个对象，它使用引用计数来跟踪对象的引用数。当最后一个 `std::shared_ptr` 被销毁时，它会自动释放所管理的内存。

- 示例：

   ```cpp
   #include <memory>
   
   int main() {
       std::shared_ptr<int> mySharedPtr1 = std::make_shared<int>(42);
       std::shared_ptr<int> mySharedPtr2 = mySharedPtr1; // 共享所有权
     
       // 使用mySharedPtr1和mySharedPtr2操作资源
     
       return 0; // 在main函数结束时，引用计数减为零，内存会被释放
   }
   ```

## `weak_ptr`(C++11)

- `std::weak_ptr` 用于解决 `std::shared_ptr` 的循环引用问题。它不增加引用计数，允许观察被 `std::shared_ptr` 管理的对象，但不拥有所有权。

- 示例：

   ```cpp
   #include <memory>
   
   int main() {
       std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);
       std::weak_ptr<int> weakPtr = sharedPtr;
   
       if (auto sharedPtrFromWeak = weakPtr.lock()) {
           // 使用sharedPtrFromWeak操作资源
       }
   
       // 不影响sharedPtr的引用计数
       return 0;
   }
   ```