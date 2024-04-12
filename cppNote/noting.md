# 1. 引用

## 函数返回值作引用

1. 若返回局部变量的引用，不能成为其他引用的初始值，不能当作左值使用

> 当一个函数返回一个局部变量的引用时，这个引用指向的内存空间将在函数调用结束后被释放。因此，返回局部变量的引用不能安全地作为其他引用的初始值，也不能被用作左值。这是因为在离开函数后，局部变量的内存将不再有效。

```cpp
int& returnLocalVariable() {
    int x = 42;
    return x;  // 错误！返回了局部变量 x 的引用
}

int main() {
    int& ref = returnLocalVariable();  // 危险！ref 引用的是已释放的内存
    // 这里的 ref 是无效的，可能导致未定义的行为
    return 0;
}
```



2. 若返回全局变量或静态变量的引用时：
   - 可以成为其他引用的初始值
   - 既可以作为右值使用，也可以作为左值使用

```cpp
int globalVariable = 42;

int& returnGlobalVariable() {
    return globalVariable;  // 返回全局变量的引用
}

int main() {
    int& ref = returnGlobalVariable();  // 合法！ref 引用的是全局变量 globalVariable
    ref = 100;  // 合法！修改了全局变量的值
    return 0;
}
```



3. 返回形参作引用

> 返回函数形参的引用是合法的，但需要注意形参的生命周期。如果形参是局部变量，那么同样存在返回局部变量引用的问题。如果形参是全局变量或静态变量，返回引用是安全的。

```cpp
int globalParam = 42;

int& returnParameter(int& param) {
    return param;  // 合法，返回形参的引用
}

int main() {
    int& ref = returnParameter(globalParam);  // 合法！ref 引用的是全局变量 globalParam
    ref = 200;  // 合法！修改了全局变量的值
    return 0;
}
```

+ 当返回形参的引用时，如果形参是局部变量，那么同样会存在问题。

```cpp
int& returnLocalParameter() {
    int x = 42;
    return x;  // 错误！返回了局部变量 x 的引用
}

int main() {
    int y = 10;
    int& ref = returnLocalParameter(y);  // 危险！ref 引用的是已释放的内存
    // 这里的 ref 是无效的，可能导致未定义的行为
    return 0;
}
```







# 2. 函数

## 2.1 内联函数

+ 空间换时间

在C++中，内联函数是一种对编译器的请求，它提示编译器在调用函数的地方直接展开函数体，而不是生成一个函数调用。

这样做的目的是为了减少函数调用的开销，提高程序的执行效率。内联函数通常适用于函数体较小且频繁调用的情况。

要定义内联函数，可以在函数声明和定义前面加上`inline`关键字。这只是对编译器的建议，编译器可以选择是否真正内联函数。下面是一个简单的例子：

```cpp
#include <iostream>

// 函数定义
inline int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(3, 4);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

//展开后：
#include <iostream>
using namespace std;

int main() {
    int a = 3;
    int b = 4;
    cout << a + b << endl; // 内联函数被直接展开为函数体

    return 0;
}

```

在这个例子中，`add`函数被声明为内联函数，它将两个整数相加。在`main`函数中调用了`add`函数，但编译器可能会选择直接在调用点展开`add`的函数体，而不是生成一个函数调用。这样有助于减少函数调用的开销，特别是当函数体很小而且在程序中频繁调用时。

值得注意的是，内联函数并非在所有情况下都适用。内联函数的展开会增加代码的体积，可能导致代码膨胀。因此，通常建议将内联函数用于简单的、短小的函数，并在适当的情况下进行测试和分析以确保性能提升。
