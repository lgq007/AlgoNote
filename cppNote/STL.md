# STL

Standard Template Library

+ 容器
+ 迭代器
+ 算法

## 1. 容器

## `1.1 vector`

### 1.1.1构造

1. 默认构造函数，采用模板实现，此时容器为空

```cpp
vector<T> v = vector<T> (); //显式
//等价于vector<T> v;
```

2. 带有初始大小和初始值的构造

```cpp
vector<T> v = vector(int n , T element);
//等价于vector<T> v(int n , T element);
```

3. 使用迭代器范围构造（可对一个容器、数组指定的范围深拷贝）

```cpp
vector<T> v(beginIterator, endIterator)
```

4. 使用另一个容器拷贝构造

```cpp
vector<T> v(const vector& vec);
```

5. 初始化列表构造

```cpp
vector<T> v = {value1, value2, value3, ...};
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &a) {
	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;
}
int main() {

	vector<int> v1;
	printVector(v1); //

	vector<int> v2 = vector<int>(10, 8);
	printVector(v2); //8 8 8 8 8 8 8 8 8 8

	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v3(a, a + 5); //左闭右开[left, right)
	printVector(v3); //0 1 2 3 4

	vector<int>::iterator it = v2.begin();
	vector<int> v4(it, it + 5);
	printVector(v4); //8 8 8 8 8

	vector<int> v5(v3);
	printVector(v5); //0 1 2 3 4

	vector<int> v6 = {1, 3, 5, 7, 9};
	printVector(v6); //1 3 5 7 9


	return 0;
}
```

### 1.1.2 赋值

1. **使用重载运算符 `=` 运算符进行拷贝赋值：**

   ```cpp
   vector& operator=(const vector& vec);
   
   vector<T> V1 = {value1, value2, value3};
   vector<T> V2(V1); // 拷贝赋值
   ```

2. **使用 `assign` 方法进行范围赋值：**

   ```cpp
   vector<T> V;
   V.assign(beginIterator, endIterator); // 范围赋值
   ```

3. **使用 `assign` 方法进行重复元素赋值：**

   ```cpp
   vector<T> V;
   V.assign(int count, T value); // 重复元素赋值
   ```

4. **使用 `operator[]` 或 `at` 方法进行单个元素赋值：**

   ```cpp
   vector<T> V = {value1, value2, value3};
   V[0] = newValue; // 通过索引赋值
   // 或
   V.at(1) = newValue; // 使用 at 方法赋值
   ```

5. **使用 `swap` 方法交换两个 `std::vector` 的内容：**

   ```cpp
   vector<T> V1 = {value1, value2, value3};
   vector<T> V2 = {newValue1, newValue2};
   V1.swap(V2); // 交换两个 vector 的内容
   ```

```cpp
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &a) {
	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;
}
int main() {

	vector<int> v1 = {0, 1, 2, 3, 4, 5, 6};
	vector<int> v2 = v1;
	printVector(v2); //0 1 2 3 4 5 6

	int a[] = {1, 3, 5, 7, 9, 11, 13};
	vector<int> v3(a + 3, a + 7);
	printVector(v3); //7 9 11 13

	vector<int> v4(v1.begin(), v1.begin() + 5);
	printVector(v4); //0 1 2 3 4

	vector<int> v5;
	v5.assign(a + 3, a + 7);
	printVector(v5); //7 9 11 13

	v5.assign(v1.begin(), v1.begin() + 5);
	printVector(v5); //0 1 2 3 4

	vector<int> v6 = {0, 1, 2, 3, 4, 5, 6};
	v6[2] = 20;
	v6.at(6) = 60;
	printVector(v6); //0 1 20 3 4 5 60

	vector<int> v7 = {1, 2, 3, 4, 5};
	vector<int> v8 = {10, 20, 30, 40, 50, 60, 70};
	v7.swap(v8);
	printVector(v7); //10 20 30 40 50 60 70
	printVector(v8); //1 2 3 4 5


	return 0;
}
```



### 1.1.3插入

1. **使用`push_back()`方法在尾部插入元素：**

   ```cpp
   vector<T> v = {value1, value2, value3};
   v.push_back(newValue); // 在尾部插入元素
   ```

2. **使用迭代器在指定位置插入元素：**

   ```cpp
   vector<T> v = {value1, value2, value3};
   auto iterator = v.begin() + 1;
   v.insert(iterator, newValue); // 在指定位置插入元素
   ```

3. **使用迭代器范围插入元素：**

   ```cpp
   vector<T> v = {value1, value2, value3};
   auto iterator = v.begin() + 1;
   v.insert(iterator, beginIterator, endIterator); // 在指定位置插入迭代器范围的元素
   ```



### 1.1.4 删除

1. **使用`pop_back()`方法删除尾部元素：**

   ```cpp
   vector<T> v = {value1, value2, value3};
   v.pop_back(); // 删除尾部元素
   ```

2. **使用迭代器删除指定位置的元素：**

   ```cpp
   vector<T> v = {value1, value2, value3};
   auto iterator = v.begin() + 1;
   v.erase(iterator); // 删除指定位置的元素
   ```

3. **使用迭代器范围删除元素：**

   ```cpp
   vector<T> v = {value1, value2, value3};
   auto startIterator = v.begin() + 1;
   auto endIterator = v.begin() + 2;
   v.erase(startIterator, endIterator); // 删除指定范围内的元素
   ```

4. **使用 `clear` 方法清空所有元素：**

   ```cpp
   vector<T> v = {value1, value2, value3};
   v.clear(); // 清空所有元素
   ```



### 1.1.5 其他

+ **`front()`方法返回容器中的第一个元素**

```cpp
vector<int> v;
int tmp = v.front();
```

+ **`back()`方法返回容器中的最后一个元素**

```cpp
vector<int> v;
int tmp = v.back();
```

+ **`size()`方法返回容器中元素的个数**

```cpp
vector<int> v;
int count = v.size()
```

+ **`empty()`方法返回一个布尔值判断容器是否为空**

```cpp
vector<int> v;
if(v.empty()){
  cout << "empty vector!" << endl;
}
```

+ **`resize(int nums)`方法重新指定容器的长度**

```cpp
vector<int> v = {0, 1, 2};
cout << v.size() << endl; //3

v.resize(15); //指定容器的长度为15
```

**若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。**

```cpp
v.resize(int num，T elem); 
```

**重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。**



+ **`capacity()`方法返回容器的容量，容器的容量大于等于容器的长度**



+ **`reserve(int len)`方法使容器预留`len`个元素长度，预留位置不初始化，元素不可访问。**

但并不改变容器的大小。这样做的目的是为了减少因动态扩容导致的内存重新分配次数，从而提高性能。

```cpp
vector<T> myVector;
myVector.reserve(newCapacity);
```

其中，`myVector` 是要操作的 `std::vector` 对象，`newCapacity` 是希望容器能够容纳的元素数量。调用 `reserve` 后，并不会改变 `myVector` 的大小，但会确保容器有足够的内存空间，以便能够存储至少 `newCapacity` 个元素。



## `1.2 string`

### 1.2.1 string的构造函数

1. **无参构造**

```cpp
string str = string(); //显式创建一个空的字符串，也可以隐式:string str;
```

2. **使用一个string对象初始化另一个string对象**

```cpp
string str = string(const string& s);
```

3. **使用C风格字符串初始化**

```cpp
string str = string(const char* s);
```

4. **使用n个字符初始化**

```cpp
string str = string(int n, char c);
```

```cpp
#include <iostream>
using namespace std;
int main() {
	string str1 = string();
	cout << str1 << endl;
  
	str1 = "hello";
	string str2 = string(str1);
	cout << str2 << endl;
  
	string str3 = string("hello world");
	cout << str3 << endl;
  
	string str4 = string(5, 'a');
	cout << str4 << endl;
  
	const char *s = "cpp learning";
	string str5 = string(s);
	cout << str5 << endl;
  
	return 0;
}
/*output:

hello
hello world
aaaaa
cpp learning
*/
```

### 1.2.2 基本赋值操作

+ 使用运算符重载赋值

1. 将C风格字符串赋值给当前字符串

```cpp
string& operator= (const char* s);
```

2. 将一个字符串赋值给当前字符串

```cpp
string& operator= (const string& s);
```

3. 将字符赋值给当前字符串

```cpp
string& operator= (const char c);
```

+ 使用`assign()`方法

4. 将C风格字符串赋值给当前字符串

```cpp
string& assign(const char* s);
```

5. 将C风格字符串的前n个字符赋值给当前字符串

```cpp
string& assign(const char* s, int n);
```

6. 将一个字符串赋值给当前字符串

```cpp
string& assign(const string& s);
```

7. 将n个字符a赋值给当前字符串

```cpp
string& assign(int n, char c);
```

8. 将一个字符串的第start位开始的n个字符赋值给当前字符串

```cpp
string& assign(const string& s, int start, int n);
```



```cpp
#include <iostream>
using namespace std;
int main() {

	string str1 = "hello world";
	cout<<"str1:	"<<str1<<endl;
	
	const char*s = "hello cpp";
	string str2 = s;
	cout<<"str2:	"<<str2<<endl;
	
	string str3 = str1;
	cout<<"str3:	"<<str3<<endl;
	
	string str4 = "a";
	cout<<"str4:	"<<str4<<endl;
	
	string str5;
	str5.assign("i love cpp");
	cout<<"str5:	"<<str5<<endl;
	
	string str6;
	str6.assign(s);
	cout<<"str6:	"<<str6<<endl;
	
	string str7;
	str7.assign(s, 5);
	cout<<"str7:	"<<str7<<endl;
	
	string str8;
	str8.assign(str7);
	cout<<"str8:	"<<str8<<endl;
	
	string str9;
	str9.assign(5,'a');
	cout<<"str9:	"<<str9<<endl;
	
	string str10;
	str10.assign(s, 6, 3);
	cout<<"str10:	"<<str10<<endl;
	
	
	
	
	return 0;
}
/*output:
str1:   hello world
str2:   hello cpp
str3:   hello world
str4:   a
str5:   i love cpp
str6:   hello cpp
str7:   hello
str8:   hello
str9:   aaaaa
str10:  cpp
*/
```



### 1.2.3 字符存取操作

+ 使用下标访问

```cpp
string& operator[] (int n);
```

+ 使用`at`方法

```cpp
string& at(int n);
```

```cpp
#include <iostream>
using namespace std;
int main() {

	string str = "hello world";
	cout<<str[4]<<endl;
	cout<<str.at(4)<<endl;

	return 0;
}
/*output:
o
o
*/
```

---

用string类定义字符串时，字符串是可变长的，涉及到内存地址的重新分配，应尽可能尽量减少对string对象中某个字符的引用，因为引用的字符的地址是可能会发生改变的，造成不可预期的结果。

### 1.2.4 拼接操作

#### 1.2.4.1 使用重载运算符拼接

1. 字符串拼接一个C风格字符串

```cpp
string& operator+=(const char* s);
```

2. 字符串拼接另一个字符串

```cpp
string& operator+=(const string& s);
```

3. 字符串连接一个字符

```cpp
string& operator+=(const char c);
```



#### 1.2.4.2 使用`append()`方法拼接

4. 拼接一个C风格字符串

```cpp
string& append(const char* s);
```

5. 拼接一个C风格字符串的前n位字符

```cpp
string& append(const char* s, int n);
```

6. 拼接一个字符串

```cpp
string& append(const string& s);
```

7. 拼接一个字符串，从这个字符串的start位置开始连续的n个字符

```cpp
string& append(const string& s, int start, int n);
```

8. 拼接n个字符a

```cpp
string& append(int n, char a);
```



```cpp
#include <iostream>
using namespace std;
int main() {

	string str1 = "hello ";
	cout << str1 + "world" << endl;

	string str2 = "c and cpp";
	cout<<str1+str2<<endl;
	
	cout<<str1+'a'<<endl;

	str1.append("world");
	cout<<str1<<endl;
	
	string str3 = "hello ";
	const char* s = "c and cpp";
	cout<<str3.append(s, 1)<<endl;
	
	string str4 = "hello ";
	cout<<str4.append(str2)<<endl;
	
	string str5 = "hello ";
	cout<<str5.append(str2, 6, 3)<<endl;
	
	cout<<str5.append(1, 'c')<<endl;
	return 0;
}
/*output:
hello world
hello c and cpp
hello a
hello world
hello c
hello c and cpp
hello cpp
hello cppc
*/
```



### 1.2.5 查找和替换操作

#### 1.2.5.1 使用`find()`方法查找

```cpp
int find(const string& str, int pos = 0) const;
```

+ 查找字符串中str第一次出现的位置下标，从pos开始查找

```cpp
int find(const char* s, int pos = 0) const;
```

+ 查找C风格数组第一次出现的位置下标，从pos开始查找

```cpp
int find(const char* s, int pos, int n) const;
```

+ 从字符串的pos位置查找s的前n个字符中第一次出现的位置

```cpp
int find(const char c, int pos = 0) const;
```

+ 从字符串中的第pos位置开始查找字符c

---

```cpp
int rfind(const string& s, int pos = npos) const;
```

+ 查找s在字符串中最后一次出现的位置坐标，也可以理解为从右向左查找子串s第一次出现的位置坐标，从pos位置开始向左查找

```cpp
int rfind(const char* s, int pos = npos) const;
```

+ 查找C风格字符串s在字符串中最后一次出现的位置坐标，也可以理解为从右向左查找子串s第一次出现的位置坐标，从pos位置开始向左查找

```cpp
int find(const char*s, int pos, int n) const;
```

+ 查找C风格字符串s的前n个字符在字符串中最后一次出现的位置坐标，也可以理解为从右向左查找子串s第一次出现的位置坐标，从pos位置开始向左查找

```cpp
int find(const char c, int pos = npos) const;
```

+ 查找字符c最后一次出现的位置

```cpp
#include <iostream>
using namespace std;
int main() {

	string str1 = "hello world";
	string str_1 = "world";
	cout << str1.find(str_1, 0) << endl; //6

	const char *t = "world";
	cout << str1.find(t, 0) << endl; //6

	string str3 = "hello world";
	const char* s = "word";
	cout << str3.find(s, 0, 3) << endl;//6

	string str4 = "abcdefghijklmnopqrstuvwxyz";
	cout << str4.find('z', 0) << endl; //25

	string str5 = "hello world hello cpp helx";
	cout << str5.rfind("hello", str5.length()) << endl; //12

	const char* a = "hello";
	cout << str5.rfind(a, str5.length()) << endl; //12

	cout << str5.rfind(a, str5.length(), 3) << endl; //22

	string str6 = "abcddcba";
	cout << str6.rfind('b', str6.length()) << endl; //6
	cout << str6.rfind('b', 4) << endl; //1


	return 0;
}
```

#### 1.2.5.2 使用`replace()`方法替换

1. 从pos位置开始的连续n个字符替换为字符串str

```cpp
string& replace(int pos, int n, const string& str);
```

1. 从pos位置开始的连续n个字符替换为C风格字符串

```cpp
string& replace(int pos, int n, const char* s);
```

```cpp
#include <iostream>
using namespace std;
int main() {

	string str = "hello world";
	string str2 = "cpp";
	cout << str.replace(6, 5, str2) << endl;
	cout << "str after replacing:" << str << endl;

	string str3 = "hello c";
	const char* s = "cpp";
	cout << str3.replace(6, 1, s) << endl;
	cout << "str3 after replacing:" << str3 << endl;
	return 0;
}
/*output:
hello cpp
str after replacing:hello cpp
hello cpp
str3 after replacing:hello cpp
*/
```



### 1.2.6 比较操作

在C语言中可以直接将两个字符数组进行比较，比较的依据是数组中字符的字典序，结果返回一个bool类型的值，即0或1

```c
char a[4] = "abc";
char b[4] = "abe";
bool bool_ = a > b;
cout<<boo_l<<endl; //1
```


在C语言中，`strcmp` 是一个用于比较两个字符串的标准库函数。函数原型如下：

```c
int strcmp(const char *str1, const char *str2);
```

- 如果 `str1` 等于 `str2`，则返回值为 0。
- 如果 `str1` 小于 `str2`，则返回值为负数。
- 如果 `str1` 大于 `str2`，则返回值为正数。

比较是按字典顺序逐个比较字符串中的字符，直到找到不相等的字符或者其中一个字符串的结束符 `\0`。函数会比较两个字符串对应位置上的字符的 ASCII 值。

以下是一个简单的例子：

```c
#include <stdio.h>
#include <string.h>

int main() {
	const char *str1 = "Hello";
	const char *str2 = "World";

	int result = strcmp(str1, str2);

	printf("%d", result); //-1

	return 0;
}
```

**在C++中，有一个用于比较两个字符串的成员函数是`compare()`，它是`std::string`类的一部分。`compare()`函数有多个重载版本，其中最常用的版本有以下几种：**

1. 比较两个字符串的整体大小（字典序）：

   ```cpp
   #include <iostream>
   #include <string>
   
   int main() {
       std::string str1 = "Hello";
       std::string str2 = "World";
   
       int result = str1.compare(str2);
   
   		std::cout << result << std::endl; //-1
       return 0;
   }
   ```

2. 比较两个字符串的一部分：

   ```cpp
   #include <iostream>
   #include <string>
   
   int main() {
       std::string str1 = "Hello";
       std::string str2 = "Hell";
   
       int result = str1.compare(0, 4, str2); // 比较str1的前4个字符和str2
   
   		std::cout << result << std::endl; //0
   
       return 0;
   }
   ```


`compare()`函数的返回值的含义与`strcmp`相似。如果返回值为0，表示两个字符串相等；如果返回值小于0，表示调用该函数的字符串小于传递给它的字符串；如果返回值大于0，表示调用该函数的字符串大于传递给它的字符串。



### 1.2.7 子串获取操作

```cpp
string substr(int pos = 0, int n = npos) const; //返回从pos开始的n个连续字符
```

```cpp
#include <iostream>
using namespace std;
int main() {

	string str = "hello world i love cpp";
	cout << str.substr(12, 10) << endl; //i love cpp
	return 0;
}
```



### 1.2.8 字符插入和删除操作

#### 1.2.8.1 使用`insert()`方法插入

```cpp
string& insert(int pos, const char* s);
```

+ 在字符串中的pos位置开始插入C风格字符串

```cpp
string& insert(int pos, const string& s);
```

+ 在字符串中的pos位置开始插入新的字符串

```cpp
string& insert(int pos, int n, char c);
```

+ 在字符串的pos位置开始插入n个字符c

```cpp
#include <iostream>
using namespace std;

int main() {
	string str1 = "hello world hello cpp";
	cout << str1.insert(17, " c and") << endl; //hello world hello c and cpp

	string str2 = "hello world";
	string str3 = "cpp ";
	cout << str2.insert(6, str3) << endl; //hello cpp world

	cout << str2.insert(6, 3, 'g') << endl; //hello gggcpp world
	return 0;
}
```

#### 1.2.8.2 使用`erase()`方法删除子串

```cpp
string& erase(int pos, int n = npos);
```

+ 删除从pos位置开始的n个字符

```cpp
#include <iostream>
using namespace std;

int main() {
	string str = "hello world";
	cout << str.erase(5) << endl; //hello
	str = "hello cand cpp";
	cout << str.erase(6, 1) << endl;  //hello and cpp
	return 0;
}
```

### 1.2.9 string和C风格字符串转换

+ string转`char *`

```cpp
string str = "hello world";
const char* s  = str.c_str();
```

+ `char *`转`string`

```cpp
const char *s = "hello cpp";
string str = string(s);  //隐式转换
```

```cpp
#include <iostream>
using namespace std;

int main() {
	string str = "hello world";
	const char* s  = str.c_str();
	cout << s << endl;

	const char *s1 = "hello cpp";
	string str1 = string(s1);
	cout << str1 << endl;
	return 0;
}
```



## `1.3 deque`

### 1.3.1 deque简介

**Vector容器是单向开口的连续内存空间，deque则是一种双向开口的连续线性空间。**

![img](../../../typora_scn/deque.png) 

 

+ **deque允许对头端进行元素的插入和删除操作。**
+ deque没有容量的概念，因为它是动态的以分段连续空间组合而成，随时可以增加一段新的空间并链接起来，换句话说，像vector那样，”旧空间不足而重新配置一块更大空间，然后复制元素，再释放旧空间”这样的事情在deque身上是不会发生的。也因此，deque没有必须要提供所谓的空间保留(reserve)功能.

+ deque容器也提供了Random Access Iterator,但是它的迭代器并不是普通的指针，其复杂度和vector不是一个量级，除非有必要，尽可能的使用vector，而不是deque。对deque进行的排序操作，为了最高效率，可将deque先完整的复制到一个vector中，对vector容器进行排序，再复制回deque.



### 1.3.2 deque容器常用操作

1. deque构造函数

   ```cpp
   deque<T> deqT;//默认构造形式
   
   deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
   
   deque(n, elem);//构造函数将n个elem拷贝给本身。
   
   deque(const deque &deq);//拷贝构造函数。
   ```

   

2. deque赋值操作

   ```c++
   assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
   
   assign(n, elem);//将n个elem拷贝赋值给本身。
   
   deque& operator=(const deque &deq); //重载等号操作符
   
   swap(deq);// 将deq与本身的元素互换
   ```

   

3. deque大小操作

   ```c++
   deque.size();//返回容器中元素的个数
   
   deque.empty();//判断容器是否为空
   
   deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
   
   deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
   ```

   

4. deque双端操作和删除

   ```c++
   push_back(elem);//在容器尾部添加一个数据
   
   push_front(elem);//在容器头部插入一个数据
   
   pop_back();//删除容器最后一个数据
   
   pop_front();//删除容器第一个数据
   ```

   

5. deque数据存取

   ```c++
   at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
   
   operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
   
   front();//返回第一个数据。
   
   back();//返回最后一个数据
   ```

   

6. deque插入操作

   ```c++
   insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
   
   insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
   
   insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
   ```

   

7. deque删除操作

   ```c++
   clear();//移除容器的所有数据
   
   erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
   
   erase(pos);//删除pos位置的数据，返回下一个数据的位置。
   ```



## `1.4 stack`

### 1.4.1 stack概念

stack是一种先进后出(`First In Last Out,FILO`)的数据结构，它只有一个出口，形式如图所示。

+ stack容器允许新增元素，移除元素，取得栈顶元素，
+ 除了最顶端外，没有任何其他方法可以存取stack的其他元素。
+ stack不允许有遍历行为。
+ 有元素推入栈的操作称为:`push`
+ 元素推出stack的操作称为`pop`

<img src="https://shawn-qianfeng.oss-cn-beijing.aliyuncs.com/img/202209100051973.png" alt="image-20220910005106859" style="zoom:33%;" />

**stack是没有迭代器的：**

**Stack所有元素的进出都必须符合”先进后出”的条件，只有stack顶端的元素，才有机会被外界访问。Stack不提供遍历功能，也不提供迭代器。**



### 1.4.2 stack容器常用操作

1. 构造函数

   ```c++
   stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式
   
   stack(const stack &stk);//拷贝构造函数
   ```

   

2. 赋值操作

   ```c++
   stack& operator=(const stack &stk);//重载等号操作符
   ```

   

3. 数据存取操作

   ```c++
   push(elem);//入栈
   
   pop();//出栈
   
   top();//返回栈顶元素
   ```

   

4. 大小操作

   ```c++
   empty();//判断堆栈是否为空
   size();//返回堆栈的大小
   ```

   

## `1.5. queue`

### 1.5.1. queue容器概念

Queue是一种先进先出(`First In First Out,FIFO`)的数据结构，它有两个出口，**queue容器允许从一端新增元素，从另一端移除元素。**

<img src="https://shawn-qianfeng.oss-cn-beijing.aliyuncs.com/img/202209100054997.png" alt="image-20220910005436890" style="zoom:25%;" />

**queue容器没有迭代器：Queue所有元素的进出都必须符合”先进先出”的条件，只有queue的顶端元素，才有机会被外界取用。Queue不提供遍历功能，也不提供迭代器。**



### 1.5.2 queue容器常用操作

1. 构造函数

   ```c++
   queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式
   
   queue(const queue &que);//拷贝构造函数
   ```

   

2. 存取、插入、删除操作

   ```c++
   push(elem);//入队
   
   pop();//出队
   
   back();//返回最后一个元素
   
   front();//返回第一个元素
   ```

   

3. 赋值操作

   ```c++
   queue& operator=(const queue &que);//重载等号操作符
   ```

   

4. 大小操作

   ```c++
   empty();//判断队列是否为空
   size();//返回队列的大小
   ```

   

## `1.6 list`

### 1.6.1 list概念

+ 链表是一种物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。
+ 链表由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。
+ 每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。

**相较于vector的连续线性空间，list就显得复杂许多，它的好处是每次插入或者删除一个元素，就是配置或者释放一个元素的空间。因此，list对于空间的运用有绝对的精准，一点也不浪费。而且，对于任何位置的元素插入或元素的移除，list永远是常数时间。**

+ List容器是一个双向链表。

<img src="https://shawn-qianfeng.oss-cn-beijing.aliyuncs.com/img/202209100102384.png" alt="image-20220910010227282" style="zoom:25%;" />

**采用动态存储分配，不会造成内存浪费和溢出**

**链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素**

**链表灵活，但是空间和时间额外耗费较大**



### 1.6.2 list的迭代器

+ List容器不能像vector一样以普通指针作为迭代器，因为其节点不能保证在同一块连续的内存空间上。List迭代器必须有能力指向list的节点，并有能力进行正确的递增、递减、取值、成员存取操作。所谓”list正确的递增，递减、取值、成员取用”是指，递增时指向下一个节点，递减时指向上一个节点，取值时取的是节点的数据值，成员取用时取的是节点的成员。

+ list是一个双向链表，迭代器必须能够具备前移、后移的能力，所以list容器提供的是**`Bidirectional Iterators`**
+ **List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效。这在vector是不成立的，因为vector的插入操作可能造成记忆体重新配置，导致原有的迭代器全部失效，甚至List元素的删除，也只有被删除的那个元素的迭代器失效，其他迭代器不受任何影响。**



### 1.6.3 list容器常用操作

1. 构造函数

   ```c++
   list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
   
   list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
   
   list(n,elem);//构造函数将n个elem拷贝给本身。
   
   list(const list &lst);//拷贝构造函数。
   ```

   

2. 元素插入和删除操作

   ```c++
   push_back(elem);//在容器尾部加入一个元素
   
   pop_back();//删除容器中最后一个元素
   
   push_front(elem);//在容器开头插入一个元素
   
   pop_front();//从容器开头移除第一个元素
   
   insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
   insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
   insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
   
   clear();//移除容器的所有数据
   
   erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
   erase(pos);//删除pos位置的数据，返回下一个数据的位置。
   
   remove(elem);//删除容器中所有与elem值匹配的元素。
   ```

   

3. 大小操作

   ```c++
   size();//返回容器中元素的个数
   
   empty();//判断容器是否为空
   
   resize(num);//重新指定容器的长度为num，
   // 若容器变长，则以默认值填充新位置。
   // 如果容器变短，则末尾超出容器长度的元素被删除。
   
   resize(num, elem);//重新指定容器的长度为num，
   // 若容器变长，则以elem值填充新位置。
   // 如果容器变短，则末尾超出容器长度的元素被删除。
   ```

   

4. 赋值操作

   ```c++
   assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
   
   assign(n, elem);//将n个elem拷贝赋值给本身。
   
   list& operator=(const list &lst);//重载等号操作符
   
   swap(lst);//将lst与本身的元素互换。
   ```

   

5. 数据存取操作

   ```c++
   front();//返回第一个元素。
   back();//返回最后一个元素
   ```

   

6. 反转、排序

   ```c++
   reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
   sort(); //list排序
   ```

   

## `1.7 set/multiset`

### 1.7.1 set/multiset容器概念

**Set的特性是。所有元素都会根据元素的值自动被排序。Set不允许两个元素有相同的值。**

+ 我们可以通过set的迭代器改变set元素的值吗？不行，因为set元素值就是其值，关系到set元素的排序规则。如果任意改变set元素值，会严重破坏set组织。换句话说，**set的iterator是一种const_iterator.**

set拥有和list某些相同的性质，当对容器中的元素进行插入操作或者删除操作的时候，操作之前所有的迭代器，在操作完成之后依然有效，被删除的那个元素的迭代器必然是一个例外。

+ multiset特性及用法和set完全相同，唯一的差别在于它**允许值重复**。set和multiset的底层实现是**红黑树**。



### 1.7.2 set/multiset容器常用操作

1. 构造函数

   ```c++
   set<T> st;//set默认构造函数
   
   mulitset<T> mst; //multiset默认构造函数:
   
   set(const set &st);//拷贝构造函数
   ```

   

2. set赋值

   ```c++
   set& operator=(const set &st);//重载等号操作符
   
   swap(st);//交换两个集合容器
   ```

   

3. set大小操作

   ```c++
   size();//返回容器中元素的数目
   
   empty();//判断容器是否为空
   ```

   

4. 插入和删除操作

   ```c++
   insert(elem);//在容器中插入元素。
   
   clear();//清除所有元素
   
   erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
   
   erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
   
   erase(elem);//删除容器中值为elem的元素。
   ```

   

5. 查找操作

   ```c++
   find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
   
   count(key);//查找键key的元素个数
   
   lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
   
   upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
   
   equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
   ```



## `1.8 pair`

对组(`pair`)**将一对值组合成一个值，这一对值可以具有不同的数据类型，两个值可以分别用pair的两个公有属性first和second访问。**



```c++
//第一种方法创建一个对组
pair<string, int> pair1(string("name"), 20);
cout << pair1.first << endl; //访问pair第一个值
cout << pair1.second << endl;//访问pair第二个值

//第二种
pair<string, int> pair2 = make_pair("name", 30);
cout << pair2.first << endl;
cout << pair2.second << endl;

//pair=赋值
pair<string, int> pair3 = pair2;
cout << pair3.first << endl;
cout << pair3.second << endl;
```



## `1.9  map/multimap`

### 1.9.1 map/multimap基本概念

**Map的特性是：**

+ **所有元素都会根据元素的键值自动排序。**
+ **Map所有的元素都是pair,同时拥有实值和键值，pair的第一元素被视为键值，第二元素被视为实值。**
+ **map不允许两个元素有相同的键值。**

> 可以通过map的迭代器改变map的键值吗？答案是不行，因为map的键值关系到map元素的排列规则，任意改变map键值将会严重破坏map组织。如果想要修改元素的实值，那么是可以的。

Map和list拥有相同的某些性质，当对它的容器元素进行新增操作或者删除操作时，操作之前的所有迭代器，在操作完成之后依然有效，当然被删除的那个元素的迭代器必然是个例外。

**Multimap和map的操作类似，唯一区别multimap键值可重复。**

Map和multimap都是以红黑树为底层实现机制。

### 1.9.2 map/multimap常用操作

1. 构造函数

   ```c++
   map<T1, T2> mapTT;//map默认构造函数: 
   
   map(const map &mp);//拷贝构造函数
   ```

   

2. 赋值操作

   ```c++
   map& operator=(const map &mp);//重载等号操作符
   
   swap(mp);//交换两个集合容器
   ```

   

3. 大小操作

   ```c++
   size();//返回容器中元素的数目
   
   empty();//判断容器是否为空
   ```

   

4. 插入操作

   ```c++
   map.insert(...); //往容器插入元素，返回pair<iterator,bool>
   map<int, string> mapStu;
   // 第一种 通过pair的方式插入对象
   mapStu.insert(pair<int, string>(3, "小张"));
   
   // 第二种 通过pair的方式插入对象
   mapStu.inset(make_pair(-1, "校长"));
   
   // 第三种 通过value_type的方式插入对象
   mapStu.insert(map<int, string>::value_type(1, "小李"));
   
   // 第四种 通过数组的方式插入值
   mapStu[3] = "小刘";
   mapStu[5] = "小王";
   ```

   

5. 删除元素

   ```c++
   clear();//删除所有元素
   erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
   erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
   erase(keyElem);//删除容器中key为keyElem的对组。
   ```

   

6. 查找操作

   ```c++
   find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
   count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
   
   lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
   upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
   equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
   ```

   





## 2. 迭代器

C++标准模板库（STL）的迭代器是一种使程序员能够访问容器（如数组、链表、映射等）中元素的对象，而无需关心容器的具体实现细节。迭代器抽象了对容器元素的访问方式，使得通过相同的接口访问不同类型的容器成为可能。在深入了解迭代器之前，先了解一些基本概念对理解很有帮助。

### 2.1 迭代器的分类

迭代器主要分为五大类：

1. **输入迭代器（Input Iterators）**：只能向前移动（单次递增），一次只能读取一个元素，主要用于从容器中读取数据。
2. **输出迭代器（Output Iterators）**：只能向前移动（单次递增），一次只能写入一个元素，主要用于向容器中写入数据。
3. **前向迭代器（Forward Iterators）**：支持多次读写同一个元素，只能向前移动。
4. **双向迭代器（Bidirectional Iterators）**：除了具有前向迭代器的所有能力外，还可以向后移动。
5. **随机访问迭代器（Random Access Iterators）**：具有双向迭代器的所有功能，还可以进行跳跃访问，支持迭代器加减常数、迭代器之间的距离计算等操作，功能最为强大。



#### 2.1.1. 输入迭代器（Input Iterators）

输入迭代器主要用于从容器中读取数据。`istream_iterator`是输入迭代器的一个常见例子，它从输入流中读取数据。

```cpp
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Enter numbers (EOF to stop): ";
    std::istream_iterator<int> start(std::cin), end;
    std::vector<int> numbers(start, end);

    std::cout << "Numbers read: ";
    std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
```

#### 2.1.2. 输出迭代器（Output Iterators）

输出迭代器主要用于向容器中写入数据。`ostream_iterator`是输出迭代器的一个示例，它可以用来向输出流写数据。

```cpp
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::ostream_iterator<int> out_it(std::cout, ", ");
    std::copy(numbers.begin(), numbers.end(), out_it);
    std::cout << std::endl;
    return 0;
}
```

#### 2.1.3. 前向迭代器（Forward Iterators）

前向迭代器支持向前遍历容器中的元素。`forward_list`使用前向迭代器进行迭代。

```cpp
#include <forward_list>
#include <iostream>

int main() {
    std::forward_list<int> flist = {10, 20, 30, 40};
    for(auto it = flist.begin(); it != flist.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

#### 2.1.4. 双向迭代器（Bidirectional Iterators）

双向迭代器可以向前和向后遍历容器中的元素。**`list` 和 `set` 容器提供了双向迭代器。**

```cpp
#include <list>
#include <iostream>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    for(auto it = lst.rbegin(); it != lst.rend(); ++it) { // 反向遍历
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

#### 2.1.5. 随机访问迭代器（Random Access Iterators）

随机访问迭代器提供了最丰富的功能，包括随机访问容器中的任何元素。**`vector` 和 `deque` 提供了随机访问迭代器。**

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    auto it = vec.begin() + 3; // 直接访问第四个元素
    std::cout << "The fourth element is " << *it << std::endl;

    // 使用随机访问迭代器进行排序
    std::sort(vec.begin(), vec.end());
    for(int& x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### 2.2 迭代器的操作

迭代器支持多种操作，这些操作依赖于迭代器的类别。常见操作包括：

- `operator*`（解引用）：访问迭代器当前指向的元素。
- `operator++`（递增）：将迭代器移动到容器的下一个元素。
- `operator--`（递减，仅限双向及随机访问迭代器）：将迭代器移动到容器的上一个元素。
- `operator+` 和 `operator-`（仅限随机访问迭代器）：将迭代器向前或向后移动多个位置。
- `operator==` 和 `operator!=`（比较）：比较两个迭代器是否指向容器中的同一个元素。

### 2.3. 迭代器失效

**在使用迭代器时，需要注意迭代器失效的问题。如果容器在迭代过程中发生了结构性改变（如元素的添加或删除），可能会导致已有的迭代器失效。在继续使用失效的迭代器访问元素之前，必须重新获取有效的迭代器。**





## 3. 算法

### 3.1. 函数对象

**重载函数调用操作符的类，其对象常称为函数对象（function object），即它们是行为类似函数的对象，也叫仿函数(functor),其实就是重载“()”操作符，使得类对象可以像函数那样调用。**

注意:

1.函数对象(仿函数)是一个类，不是一个函数。

**2.函数对象(仿函数)重载了”() ”操作符使得它可以像函数一样调用。**



### 3.2. 谓语



**谓词是指普通函数或重载的operator()返回值是bool类型的函数对象(仿函数)。如果operator接受一个参数，那么叫做一元谓词,如果接受两个参数，那么叫做二元谓词，谓词可作为一个判断式。**

```c++
class GreaterThenFive
{
public:
	bool operator()(int num)
	{
		return num > 5;
	}

};
//一元谓词
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10;i ++)
	{
		v.push_back(i);
	}
	
	 vector<int>::iterator it =  find_if(v.begin(), v.end(), GreaterThenFive());
	 if (it == v.end())
	 {
		 cout << "没有找到" << endl;
	 }
	 else
	 {
		 cout << "找到了: " << *it << endl;
	 }
}

//二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(90);
	v.push_back(60);

	//默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;
	//使用函数对象改变算法策略，排序从大到小
	sort(v.begin(), v.end(),MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

```



### 3.3. 内建函数对象

STL内建了一些函数对象。分为:算数类函数对象,关系运算类函数对象，逻辑运算类仿函数。这些仿函数所产生的对象，用法和一般函数完全相同，当然我们还可以产生无名的临时对象来履行函数功能。使用内建函数对象，需要引入头文件 #include。

6个算数类函数对象,除了negate是一元运算，其他都是二元运算。

***template***<***\*class\**** T> T plus<T>**//加法仿函数**
***template\****<***\*class\**** T> T minus<T>**//减法仿函数**
***template\****<***\*class\**** T> T multiplies<T>**//乘法仿函数**
***\*template\****<***\*class\**** T> T divides<T>**//除法仿函数**
***\*template\****<***\*class\**** T> T modulus<T>**//取模仿函数**
***\*template\****<***\*class\**** T> T negate<T>**//取反仿函数**

6个关系运算类函数对象,每一种都是二元运算。

***\*template\****<***\*class\**** T> bool equal_to<T>**//等于**
***\*template\****<***\*class\**** T> bool not_equal_to<T>**//不等于**
***\*template\****<***\*class\**** T> bool greater<T>**//大于**
***\*template\****<***\*class\**** T> bool greater_equal<T>**//大于等于**
***\*template\****<***\*class\**** T> bool less<T>**//小于**
***\*template\****<***\*class\**** T> bool less_equal<T>**//小于等于**

逻辑运算类运算函数,not为一元运算，其余为二元运算。

***\*template\****<***\*class\**** T> bool logical_and<T>**//逻辑与**
***\*template\****<***\*class\**** T> bool logical_or<T>**//逻辑或**
***\*template\****<***\*class\**** T> bool logical_not<T>**//逻辑非**

内建函数对象举例:

```c++
//取反仿函数
void test01()
{
	negate<int> n;
	cout << n(50) << endl;
}

//加法仿函数
void test02()
{
	plus<int> p;
	cout << p(10, 20) << endl;
}

//大于仿函数
void test03()
{
	vector<int> v;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++){
		v.push_back(rand() % 100);
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

}
```



#### 3.3.1. 函数对象适配器

```c++
//函数适配器bind1st bind2nd
//现在我有这个需求 在遍历容器的时候，我希望将容器中的值全部加上100之后显示出来，怎么做？
//我们直接给函数对象绑定参数 编译阶段就会报错
//for_each(v.begin(), v.end(), bind2nd(myprint(),100));
//如果我们想使用绑定适配器,需要我们自己的函数对象继承binary_function 或者 unary_function
//根据我们函数对象是一元函数对象 还是二元函数对象
class MyPrint :public binary_function<int,int,void>
{
public:
	void operator()(int v1,int v2) const
	{
		cout << "v1 = : " << v1 << " v2 = :" <<v2  << " v1+v2 = :" << (v1 + v2) << endl;	
	}
};
//1、函数适配器
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "请输入起始值：" << endl;
	int x;
	cin >> x;

	for_each(v.begin(), v.end(), bind1st(MyPrint(), x));
	//for_each(v.begin(), v.end(), bind2nd( MyPrint(),x ));
}
//总结：  bind1st和bind2nd区别?
//bind1st ： 将参数绑定为函数对象的第一个参数
//bind2nd ： 将参数绑定为函数对象的第二个参数
//bind1st bind2nd将二元函数对象转为一元函数对象


class GreaterThenFive:public unary_function<int,bool>
{
public:
	bool operator ()(int v) const
	{
		return v > 5;
	}
};

//2、取反适配器
void test02()
{
	vector <int> v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	
// 	vector<int>::iterator it =  find_if(v.begin(), v.end(), GreaterThenFive()); //返回第一个大于5的迭代器
//	vector<int>::iterator it = find_if(v.begin(), v.end(),  not1(GreaterThenFive())); //返回第一个小于5迭代器
	//自定义输入
	vector<int>::iterator it = find_if(v.begin(), v.end(), not1 ( bind2nd(greater<int>(),5)));
	if (it == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到" << *it << endl;
	}

	//排序  二元函数对象
	sort(v.begin(), v.end(), not2(less<int>()));
	for_each(v.begin(), v.end(), [](int val){cout << val << " "; });

}
//not1 对一元函数对象取反
//not2 对二元函数对象取反

void MyPrint03(int v,int v2)
{
	cout << v + v2<< " ";
}

//3、函数指针适配器   ptr_fun
void test03()
{
	vector <int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	// ptr_fun( )把一个普通的函数指针适配成函数对象
	for_each(v.begin(), v.end(), bind2nd( ptr_fun( MyPrint03 ), 100));
}


//4、成员函数适配器
class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

	//打印函数
	void ShowPerson(){
		cout << "成员函数:" << "Name:" << m_Name << " Age:" << m_Age << endl;
	}
	void Plus100()
	{
		m_Age += 100;
	}
public:
	string m_Name;
	int m_Age;
};

void MyPrint04(Person &p)
{
	cout << "姓名：" <<  p.m_Name << " 年龄：" << p.m_Age << endl;

};

void test04()
{
	vector <Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//for_each(v.begin(), v.end(), MyPrint04);
	//利用 mem_fun_ref 将Person内部成员函数适配
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::ShowPerson));
// 	for_each(v.begin(), v.end(), mem_fun_ref(&Person::Plus100));
// 	for_each(v.begin(), v.end(), mem_fun_ref(&Person::ShowPerson));
}

void test05(){

	vector<Person*> v1;
	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);

	for_each(v1.begin(), v1.end(), mem_fun(&Person::ShowPerson));
}

//如果容器存放的是对象指针，  那么用mem_fun
//如果容器中存放的是对象实体，那么用mem_fun_ref
```



### 3.4. 常用算法

#### 3.4.1. for_each遍历算法

```c++
/*
    遍历算法 遍历容器元素
	@param beg 开始迭代器
	@param end 结束迭代器
	@param _callback  函数回调或者函数对象
	@return 函数对象
*/
for_each(iterator beg, iterator end, _callback);
```

```c++
/*template<class _InIt,class _Fn1> inline
void for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
{
	for (; _First != _Last; ++_First)
		_Func(*_First);
}
*/

//普通函数
void print01(int val){
	cout << val << " ";
}
//函数对象
struct print001{
	void operator()(int val){
		cout << val << " ";
	}
};

//for_each算法基本用法
void test01(){
	

vector<int> v;
for (int i = 0; i < 10;i++){
	v.push_back(i);
}

//遍历算法
for_each(v.begin(), v.end(), print01);
cout << endl;

for_each(v.begin(), v.end(), print001());
cout << endl;

}

struct print02{
	print02(){
		mCount = 0;
	}
	void operator()(int val){
		cout << val << " ";
		mCount++;
	}
	int mCount;
};

//for_each返回值
void test02(){

vector<int> v;
for (int i = 0; i < 10; i++){
	v.push_back(i);
}

print02 p = for_each(v.begin(), v.end(), print02());
cout << endl;
cout << p.mCount << endl;

}

struct print03 : public binary_function<int, int, void>{
	void operator()(int val,int bindParam) const{
		cout << val + bindParam << " ";
	}
};

//for_each绑定参数输出
void test03(){
	

vector<int> v;
for (int i = 0; i < 10; i++){
	v.push_back(i);
}

for_each(v.begin(), v.end(), bind2nd(print03(),100));

}
```



#### 3.4.2. transform算法

```c++
/*
	transform算法 将指定容器区间元素搬运到另一容器中
	注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
	@param beg1 源容器开始迭代器
	@param end1 源容器结束迭代器
	@param beg2 目标容器开始迭代器
	@param _cakkback 回调函数或者函数对象
	@return 返回目标容器迭代器
*/
transform(iterator beg1, iterator end1, iterator beg2, _callbakc);
```

```c++
//transform 将一个容器中的值搬运到另一个容器中
/*
	template<class _InIt, class _OutIt, class _Fn1> inline 
	_OutIt _Transform(_InIt _First, _InIt _Last,_OutIt _Dest, _Fn1 _Func)
	{	

		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Func(*_First);
		return (_Dest);
	}

	template<class _InIt1,class _InIt2,class _OutIt,class _Fn2> inline
	_OutIt _Transform(_InIt1 _First1, _InIt1 _Last1,_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
	{	
		for (; _First1 != _Last1; ++_First1, ++_First2, ++_Dest)
			*_Dest = _Func(*_First1, *_First2);
		return (_Dest);
	}
*/

struct transformTest01{
	int operator()(int val){
		return val + 100;
	}
};
struct print01{
	void operator()(int val){
		cout << val << " ";
	}
};
void test01(){

	vector<int> vSource;
	for (int i = 0; i < 10;i ++){
		vSource.push_back(i + 1);
	}

	//目标容器
	vector<int> vTarget;
	//给vTarget开辟空间
	vTarget.resize(vSource.size());
	//将vSource中的元素搬运到vTarget
	vector<int>::iterator it = transform(vSource.begin(), vSource.end(), vTarget.begin(), transformTest01());
	//打印
	for_each(vTarget.begin(), vTarget.end(), print01()); cout << endl;
	
}

//将容器1和容器2中的元素相加放入到第三个容器中
struct transformTest02{
	int operator()(int v1,int v2){
		return v1 + v2;
	}
};
void test02(){

	vector<int> vSource1;
	vector<int> vSource2;
	for (int i = 0; i < 10; i++){
		vSource1.push_back(i + 1);	
	}

	//目标容器
	vector<int> vTarget;
	//给vTarget开辟空间
	vTarget.resize(vSource1.size());
	transform(vSource1.begin(), vSource1.end(), vSource2.begin(),vTarget.begin(), transformTest02());
	//打印
	for_each(vTarget.begin(), vTarget.end(), print01()); cout << endl;
}
```



#### 3.4.3. 常用查找算法(`find` `find_if` `adjacent_find` `binary_search` `count` `count_if`)

```c++
/*
	find算法 查找元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 查找的元素
	@return 返回查找元素的位置
*/
find(iterator beg, iterator end, value)
   
/*
	find_if算法 条件查找
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  callback 回调函数或者谓词(返回bool类型的函数对象)
	@return bool 查找返回true 否则false
*/
find_if(iterator beg, iterator end, _callback);


/*
	adjacent_find算法 查找相邻重复元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
	@return 返回相邻元素的第一个位置的迭代器
*/
adjacent_find(iterator beg, iterator end, _callback);

/*
	binary_search算法 二分查找法
	注意: 在无序序列中不可用
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 查找的元素
	@return bool 查找返回true 否则false
*/
bool binary_search(iterator beg, iterator end, value);

/*
	count算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  value回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
*/
count(iterator beg, iterator end, value);

/*
count_if算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  callback 回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
*/
count_if(iterator beg, iterator end, _callback);
```



#### 3.4.4. 常用排序算法(`merge` `sort` `random_shuffle` `reverse`)

```c++
/*
	merge算法 容器元素合并，并存储到另一容器中
	注意:两个容器必须是有序的
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
*/
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
   
/*
	sort算法 容器元素排序
	@param beg 容器1开始迭代器
	@param end 容器1结束迭代器
	@param _callback 回调函数或者谓词(返回bool类型的函数对象)
*/
sort(iterator beg, iterator end, _callback)
   
/*
	random_shuffle算法 对指定范围内的元素随机调整次序
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
*/
random_shuffle(iterator beg, iterator end)
   
/*
	reverse算法 反转指定范围的元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
*/
reverse(iterator beg, iterator end)
```



#### 3.4.5. 常用拷贝和替换算法(`copy` `replace` `replace_if` `swap`)

```c++
/*
	copy算法 将容器内指定范围的元素拷贝到另一容器中
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param dest 目标起始迭代器
*/
copy(iterator beg, iterator end, iterator dest)
   
/*
	replace算法 将容器内指定范围的旧元素修改为新元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param oldvalue 旧元素
	@param oldvalue 新元素
*/
replace(iterator beg, iterator end, oldvalue, newvalue)
   
/*
	replace_if算法 将容器内指定范围满足条件的元素替换为新元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param callback函数回调或者谓词(返回Bool类型的函数对象)
	@param oldvalue 新元素
*/
replace_if(iterator beg, iterator end, _callback, newvalue)
   
/*
	swap算法 互换两个容器的元素
	@param c1容器1
	@param c2容器2
*/
swap(container c1, container c2)
```



#### 3.4.6. 常用算数生成算法(`accumlate` `fill`)

```c++
/*
	accumulate算法 计算容器元素累计总和
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value累加值
*/
accumulate(iterator beg, iterator end, value)
   
/*
	fill算法 向容器中添加元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value t填充元素
*/
fill(iterator beg, iterator end, value)
```



#### 3.4.7. 常用集合算法(`set_intersection` `set_union` `set_difference`)

```c++
/*
	set_intersection算法 求两个set集合的交集
	
	注意:两个集合必须是有序序列
	
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
*/
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
   
   
/*
	set_union算法 求两个set集合的并集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
*/
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
/*
	set_difference算法 求两个set集合的差集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
*/
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
```





