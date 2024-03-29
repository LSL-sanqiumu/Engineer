# 自我介绍

问题一：“请你自我介绍一下” 
思路： 
1、这是面试的必考题目。
2、介绍内容要与个人简历相一致。
3、表述方式上尽量口语化。
4、要切中要害，不谈无关、无用的内容。
5、条理要清晰，层次要分明。
6、事先最好以文字的形式写好背熟。 
权重：高
备注：可以说自己的项目经验、喜欢不断学习、爱挑战、负责任。（学业、技术、项目、岗位要求、规划）

各位面试官好，下面我从学业、技术栈、个人项目、往后个人规划这四方面来简单介绍一下自己。

首先是学业方面，吧啦吧啦吧啦......

关于个人技术栈，吧啦吧啦吧啦......

关于自己做的这几个项目，吧啦吧啦吧啦......

关于个人规划方面，吧啦吧啦吧啦......

>参考：
>
>面试官你好，我叫xxx，今年xx岁，家乡是xx省xx市。20xx年毕业后一直从事软件测试工作，到现在已经x年了。
>
>目前为止，经历过x家公司。第一份工作是在xxx公司，工作了大概x年，岗位是测试工程师，主要负责公司的web和APP项目的功能测试；第二份工作是在xxx公司。。。 
>
>工作这几年，我积累了丰富的功能测试经验，可以独立负责项目的功能测试。另外还负责过服务端的接口测试，可以用测试工具实现基本的接口自动化。其他的像Linux和SQL工作中用的也比较多。代码方面会一些Python基础，现在正在持续学习中。 
>
>以上就是我的一些基本情况，谢谢！
>

# C语言

## C特点及编译过程

**1、C语言的核心特征？**

- 可移植性很强。
- 模块化能力很强。
- 灵活性很高。
- 加载速度和执行速度都很好。
- 可扩展性很强。

**2、编译器的作用。**

编译器就是将一种语言（通常为**高级语言**）翻译为另一种语言（通常为**低级语言**）的程序。一个现代编译器的主要工作流程：源代码(.c)→ 预处理器(.i) → 编译器 (.s)→ 目标代码 (.o)→ 链接器 → 可执行程序 。

**3、C语言程序编译的流程是什么？**

（1）预处理：根据以字符#开头的命令修给原始的C程序，结果得到另一个C程序，通常以.i作为文件扩展名。主要是进行文本替换、宏展开、删除注释这类简单工作。

```c
对应的命令：linux> gcc -E hello.c hello.i
```

（2）编译：编译器将文本文件hello.i翻译成hello.s，包含相应的汇编语言程序。

```c
对应的命令：linux> gcc -S hello.c hello.s
```

（3）汇编：将.s文件翻译成机器语言指令，把这些指令打包成一种叫做可重定位目标程序的格式，并将结果保存在目标文件.o中(把汇编语言翻译成机器语言的过程)。

把一个源程序翻译成目标程序的工作过程分为五个阶段：词法分析；语法分析；语义检查和中间代码生成；代码优化；目标代码生成。主要是进行词法分析和语法分析，又称为源程序分析，分析过程中发现有语法错误，给出提示信息。

```c
对应的命令：linux> gcc -c hello.c hello.o
```

（4）链接：将静态库和动态库的库函数连接到可执行程序中。静态库是指编译链接时，把库文件的代码全部加入到可执行文件中，因此生成的文件比较大，但在运行时也就不再需要库文件了。其后缀名一般为.a。动态库与之相反，在编译链接时并没有把库文件的代码加入到可执行文件中，而是在程序执行时由运行时链接文件加载库，这样可以节省系统的开销。动态库一般后缀名为.so，gcc在编译时默认使用动态库。

## 内存与堆栈

**1、C语言内存分配方式：**

- 静态存储区分配。
- 栈上分配。
- 堆上分配。

**2、一个由C/C++编译的程序占用的内存分为以下几个部分：**

①栈区 —— 局部变量 —— 向低地址生长 —— 自动释放 —— 其操作方式类似于数据结构中的栈。

②堆区 —— 向高地址生长 —— 手动分配、释放的存储区 —— malloc,free —— 它与数据结构中的堆是两回事，分配方式倒是类似于链表

③静态存储区 —— 全局变量，静态变量，程序运行结束后自动释放。

④常量存储区 —— const 、常量字符串储存在这里。储存在常量区的**只读不可写**。程序运行结束后自动释放。

⑤代码区 —— 存放函数体的二进制代码。

> 静态内存分配：编译时分配，包括：全局、静态全局、静态局部。
>
> 动态内存分配：运行时分配：包括：栈（局部变量），堆（C语言常用到的变量被动态地分配到内存当中：malloc，calloc，realloc，free函数）

——> const修饰的全局变量也储存在常量区；const修饰的局部变量依然在栈上。

```c
int a = 0; //全局初始化区 
char *p1; //全局未初始化区 
main() { 
    int b; //栈 
    char s[] = "abc"; //栈 
    char *p2; //栈 
    char *p3 = "123456"; //123456\0在常量区，p3在栈上。 
    static int c =0； //全局（静态）初始化区 
    p1 = (char *)malloc(10); 
    p2 = (char *)malloc(20); //分配得来得10和20字节的区域就在堆区。
    strcpy(p1, "123456"); //123456\0放在常量区，编译器可能会将它与p3所指向的"123456"优化成一个地方。 
}
```



**3、heap的优点和缺点是什么？**

在heap上存放数据，要比在stack上存放数据要慢。

但是使用heap的主要优势是灵活性。这是因为内存的访问, 分配以及删除可以按照任意顺序来执行。

通过好的算法和设计可以规避heap速度慢的问题。

**4、堆栈空间分配区别？**

栈（操作系统）：由操作系统（编译器）自动分配释放 ，存放函数的参数值，局部变量的值等。其操作方式类似于数据结构中的栈。

堆（操作系统）： 一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收，分配方式倒是类似于链表。

**5、堆栈缓存方式区别？**

栈使用的是一级缓存， 它们通常都是被调用时处于存储空间中，调用完毕立即释放。

堆则是存放在二级缓存中，生命周期由虚拟机的垃圾回收算法来决定（并不是一旦成为孤儿对象就能被回收）。所以调用这些对象的速度要相对来得低一些。

**6、进程和线程的区别？**

进程：是执行中一段程序，即一旦程序被载入到内存中并准备执行，它就是一个进程。进程是表示资源分配的的基本概念，又是调度运行的基本单位，是系统中的并发执行的单位。

线程：单个进程中执行中每个任务就是一个线程。线程是进程中执行运算的最小单位。

一个线程只能属于一个进程，但是一个进程可以拥有多个线程。多线程处理就是允许一个进程中在同一时刻执行多个任务。

**7、C++内存管理**

分为代码段、数据段、BSS段、堆区、栈区、文件映射区

- 代码段：分为只读区和文本区，只读取储存字符串常量，文本区储存机器代码。

- 数据段：储存以及初始化的全局变量和静态变量。

- BSS段：储存未初始化的全局变量和静态变量，以及初始化为0的全局和静态。

- 堆区：手动分配的内存。

- 栈：局部变量、参数、返回值等。

- 映射区：储存动态链接库，mmap函数的文件映射。

**8、内存泄漏与内存溢出：**

内存泄漏：由程序造成的内存无法再被使用的情况，这些无法再次被使用的内存就是泄漏的内存。

- 申请了内存，使用完毕后没有释放。
- 申请了内存，但没有任何指针指向它。

内存泄漏到一定程度 —— 耗尽了内存资源的时候，就是内存溢出了。

避免内存泄漏的方法：

- 方法一：分配的内存以链表管理，使用完毕后从链表删除，程序结束的时候检查链表。
- 方法二：良好的编程习惯，在设计内存的程序段，检验出内存泄漏，使用了内存分配的函数，使用完毕后将使用的相应函数释放掉。
- 方法三：C++的智能指针。



## 头文件

1、C语言中的头文件有什么用？

一般C语言程序项目中的头文件后缀名都为 .h，h 是 header 的缩写。头文件的使用一般和 #include 结合使用，例如在 main.c 文件中写下：

```c
#include"header.h"
```

意味着在该处将 header.h 中的内容展开到此。所以C语言中的头文件中一般包含程序需要使用的函数定义和原型，也可以包含相关的数据结构类型定义。

2、 使用头文件时双引号和尖括号的区别是什么?

使用双引号时，首先要在当前工作目录中查找这个头文件，如果找不到的话就会在内置的include path里面找。

使用尖括号时，只会在当前工作目录中查找这个头文件。



## 运算符

1、对于自增、自减的使用？

## 关键字

### volatile





### static

1、修饰函数、修饰全局变量、修饰局部变量？

- 使用static声明的，作用域将被限定在块中或一个翻译单元内。
- 修饰函数则表示函数只在该模块内使用，修饰全局变量也是限定了该全局变量在该模块内使用。
- 修饰局部变量，则局部变量的存储期延长到程序结束运行的时候，但作用域不变。

2、static修饰的全局变量（函数）与普通的相比：

① 存储类别、生命周期、作用域都一样。

② 差别在于：static修饰后的链接属性变为了内部链接属性，不能再被其它模块所调用。

### extern

extern意为外部的，其用处如下：

- 引用另一个文件中的变量，格式为`extern 数据类型 变量名;`。
- 引用另一个文件中的函数，使用extern来声明就不用将头文件包含进来便可以调用函数了。

### const

**1、const和define的区别？**

const关键字：const 是定义只读变量的关键字，常用于修饰变量、修饰形参、修饰返回值。

- 数据类型：const修饰的变量有明确的类型，而宏没有明确的数据类型。

- 安全方面：const修饰的变量会被编译器检查，而宏没有安全检查。

- 内存分配：const修饰的变量只会在第一次赋值时分配内存，而宏是直接替换，每次替换后的变量都会分配内存。

- 作用场所：const修饰的变量作用在编译、运行的过程中，而宏作用在预编译中。

- 代码调试：const方便调试，而宏在预编译中进行所以没有办法进行调试。

define是一个预处理指令，进行的是文本替换的操作；const声明只读变量，存在类型检查，通常倾向于使用const来声明常量。

### #typedef和#define

1、都是替对象起一个别名，增强程序的可读性。

2、define为预处理指令，不做正确性检查，只有带入之后才能发现。

3、typedef用来定义类型别名，不止包含内部类型还包含自定义类型（与机器无关），方便记忆。

4、define不仅可以给类型取别名，还能定义常量、变量、编译开关。

5、define没有作用域限制，typedef有。

总结：define是一个预处理指令，进行的操作是文本的替换；typedef是对类型起别名，有作用域的限制。

### struct 和 union区别

联合体：

- 联合体公用一块地址空间，联合体变量长度等于最长的成员的长度。
-  对不同成员赋值，会将其他成员重写。

### sizeof和strlen

sizeof是一个运算符，用于计算目标对象占用空间的大小，单位为字节，计算表达式的时候可以不加括号，计算基本数据类型的时候需要加上括号（`sizeof()`）。

strlen是一个字符串函数，用于对字符串的有效长度进行计数，只能对char*指针类型的并且以`\0`结尾的字符串进行计数，即只能对字符串进行计算，计算结果中不包括`\0`。



## 语句

1、循环语句？

C语言中有4种循环类型。

- while、for、do while、nested loop（嵌套循环）。

2、什么是nested loop？

一个循环包含在另一个循环中称为nested loop（嵌套循环）。第1个循环成为外循环。里面的循环称为内循环。内循环执行的次数作为总循环的次数。

3、控制流程语句：if else语句、switch语句。



## 数组

1、构建动态数组？





## 指针

**1、C语言中的悬空指针？**

C语言中的指针可以指向一块内存，如果这块内存稍后被操作系统回收（被释放），但是指针仍然指向这块内存，那么，此时该指针就是“悬空指针”。下面这段C语言代码是一个例子，请看：

```c
void*p =malloc(size);
assert(p);
free(p);        // 现在 p 是“悬空指针”
```

C语言中的“悬空指针”会引发不可预知的错误，而且这种错误一旦发生，很难定位。这是因为在 free(p) 之后，p 指针仍然指向之前分配的内存，如果这块内存暂时可以被程序访问并且不会造成冲突，那么之后使用 p 并不会引发错误。

最难调试的 bug 总是不能轻易复现的 bug，对不？

所以在实际的C语言程序开发中，为了避免出现“悬空指针”引发不可预知的错误，在释放内存之后，常常会将指针 p 赋值为 NULL：

```c
void* p = malloc(size);
assert(p);
free(p);
// 避免“悬空指针” 
p = NULL;
```

这么做的好处是一旦再次使用被释放的指针 p，就会立刻引发“段错误”，程序员也就能立刻知道应该修改C语言代码了。

**2、C语言中的“野指针”是什么？**

“悬空指针”是指向被释放内存的指针，“野指针”则是不确定其具体指向的指针。“野指针”最常来自于未初始化的指针，例如下面这段C语言代码：

```c
void* p;	// 此时 p 是“野指针”
```

因为“野指针”可能指向任意内存段，因此它可能会损坏正常的数据，也有可能引发其他未知错误，所以C语言中的“野指针”危害性甚至比“悬空指针”还要严重。在实际的C语言程序开发中，定义指针时，一般都要尽量避免“野指针”的出现（赋初值）：

```c
void* p = NULL;
void* data = malloc(size);
```

**3、C语言中的指针可以做加法运算吗？**

C语言中的指针包含地址详细信息，一般是不可以直接做加法运算的，例如下面这段C语言代码：

```C
void* p1 = (void*)1;
void* p2 = (void*)2; 
// 下面是非法的
void* p = p1 + p2;
```

读者可自行尝试，指针 p1 和指针 p2 是无法直接相加的，否则编译器就会报错。但是如果想对指针 p1 和 p2 的地址值相加，可以将其强制转换为整数类型，例如：

```C
void* p1 = (void*)1;
void* p2 = (void*)2;
longp = (long)p1 + (long)p2;
```

应该确保强制转换的整数类型宽度大于指针类型宽度，否则可能会因为数值截断导致得到错误的结果。

虽然C语言中的指针不能直接与指针相加，但是却可以与其他整数相加，例如下面这段C语言代码：

```C
char* p1 = (char*)1;
char* p = p1 + 1;
```

指针p1 指向地址 1，因此指针 p 指向地址 2，这没什么好说的。但是，读者应该注意下面这样的“陷阱”：

```C
int* p1 = (int*)1;
int* p = p1 + 1;
```

与上面的C语言代码例子相比，这里仅仅将 char 换成 int。那么，指针 p 指向哪个地址呢？编写打印代码：

```c
int* p1 = (int*)1;
int* p = p1 + 1;
printf("p1=%p, p=%p\n", p1, p);
```

编译并执行上面这段C语言代码，会发现输出如下：

```C
p1=0x1, p=0x5
```

可见，“1+1”并不等于 2，而是等于 5 了。这其实是因为C语言中的指针是有其自己的含义的，不同的指针类型索引内存的大小也往往不同，我的机器上 int 类型占用 4 个字节内存空间，因此指针 p1+1 实际上是往后移动了 4 个字节。

**4、各种指针？**

数组指针、指针数组、常量指针、指针常量、函数指针等。

**5、什么时候会用到空指针？**

有三种情况，在c语言中会用到空指针。

1. 作为一个错误值。

2. 作为一个监测值。

3. 在一个递归数据结构中终止indirection。

NULL==ptr

**5、内存泄漏？**

> 内存泄漏（**memory leak**）是指你向系统申请分配内存进行使用（new/malloc），然后系统在堆内存中给这个对象申请一块内存空间，但当我们使用完了却没有释放这些内存（没有delete/free），导致这个不使用的对象一直占据内存单元，造成系统不能再把它分配给需要的程序。 
>
> 一次内存泄漏的危害可以忽略不计，但是内存泄漏堆积则后果很严重，无论多少内存，迟早会被占完，造成内存泄漏。

内存泄漏（**memory leak**）：向系统申请分配内存（new/malloc）进行使用，当使用完毕后没有释放这些内存（没有delete/free），导致这些内存变为了无法分配的内存。这就是内存泄漏。（内存泄漏，相当于丢失 —— 丢失了一些内存）

内存泄漏不断堆积，直到消耗完系统的内存，就会导致内存溢出。

内存溢出：简单来说，就是没有内存可用了。为什么会导致内存溢出？那就是申请内存后没有及时地释放，待这些申请后没有释放的内存越堆越多直到消耗完系统的内存的时候，就是内存溢出了，内存溢出会导致整个系统崩溃。



## 函数

1、解释一下c语言的原型函数？

原型函数是对一个函数的声明，它包含函数名，返回值和参数类型列表。

2、

**内部函数：**只能被本文件中的其他函数调用。定义内部函数时，在函数名、函数类型前加static。

**外部函数：**可供其他文件调用。定义外部函数时，在函数首部左端加上extern。若定义函数时省略extern，则默认为外部函数。

3、三种参数传递的方式：传值、传指针、传引用。形参的存储空间是函数被调用时才分配的。



## 结构体





## 枚举





## 作用域





## 标准库

**1、 getch和getche, 这两个函数的区别是什么？**

前者是把用户的输入分配给一个变量。

后者是把用户的输入打印到屏幕上，同时分配给一个变量。



**2、文本文件和二进制文件的区别是什么？**

文本文件存放的是人类可以阅读的内容，它包含字母数字和其他的字符。

而二进制文件存放的是1和0，只有电脑才能够读懂。



**3、如何用随机访问的方法在一个数据文件中搜索数据?**

fseek()，在文件打开以后提供三个参数给这个函数：一个是文件的指针，一个是要搜索的字节数，再一个是文件中的搜索起点。

**4、内置的排序函数？**

qsort

**5、字符串转为数字？**

atoi、atof。使用c语言里面的内置函数可以做到。也可以自己写函数。

6、字符串相关函数？



7、内存分配相关函数？

 malloc：分配n个字节；calloc：分配n*size个字节。

free()。



## 类

C语言如何实现C++ 中的类？

```c
#include <stdio.h>
//C 语言没有类，但可以用结构体充当一个类
//与类不同，结构体只能定义变量，不能够定义函数，可以通过函数指针的方法来实现其功能 
//定义“类 ”的成员变量以及方法 
typedef struct Person{
	char name;
	int age;
	void (*EatFunction)(struct Person this, int num);
}Person; 
 
//定义函数功能 
void EatFunction(struct Person this, int num){
	printf("Test\n");
} 
 
//定义“类 ”的构造函数
//与面向对象不同，C语言的“类”的 构造函数不能放在“类”中，只能放在“类”外
//构造函数主要完成 变量的初始化，以及函数指针的赋值 
Person *NewPerson(Person *this){
	this->name = 'A';
	this->age = 18;
	this->EatFunction = EatFunction;
} 
 
//主函数调用 
int main(){
	Person person;
	NewPerson(&person);
	person.EatFunction(person,0);
	return 0;
} 
```



# STM32

## 单片机

**1、都用过哪些单片机？ 单片机的特点？**

①、8 位单片机
这类单片机的控制功能较强，品种最为齐全，由于其片内资源丰富和功能强大，主要在工业控制、智能仪表、家用电器和办公自动化系统中应用。

②、16位单片机
CPU是16 位的，运算速度普遍高于8 位机，有的单片机的寻址能力高达1MB，片内含有A/D 和D/A转换电路，支持高级语言。

③、32位单片机
32位单片机的字长为32位，是单片机的顶级产品，具有极高的运算速度。代表产品有Intel公司的MCS-80960系列、Motorola公司的M68300系列、Hitachi公司的Super H(简称SH)系列等。

单片机的特点：
①、低功耗3种低功耗模式
休眠，停止，待机模式。为RTC和备份寄存器供电的VBAT。

②、调试模式
串行调试(SWD)和JTAG接口。

③、DMA
12通道DMA控制器。支持的外设：定时器，ADC，DAC，SPI，IIC和UART。3个12位的us级的A/D转换器(16通道)

④、A/D测量范围
0-3.6V。双采样和保持能力。片道上集成一个温度传感器。

2、为什么MCU不能运行Linux？为什么需要虚拟地址？







## 最小系统

1、什么是单片机的最小系统？



## 存储

1、嵌入式系统中ROM、RAM、Register的概念和作用是什么？

- ROM是只读存储器,断电后能保证数据不会丢失。（硬盘）
- RAM是随机存储器,断电后数据会丢失.（内存）
- Register是寄存器，用来暂时存放相关指令信息或数据信息的硬件设备。

2、Cortex-M3 的存储空间可以分为哪几个部分，每一部分的地址范围是怎样的？

程序存储器、数据存储器、寄存器和输入输出端口被组织在同一个4GB的线性地址空间内，Cortex-M3最大支持4GB的存储空间，但在实际的不同STM32不一样；

1. 在0xE0000000到0xFFFFFFFF的512MB的地址存储空间是用于NVIC、MPU及调试组件等使用；
2. 在0xA0000000到0xDFFFFFFF的1GB的地址存储空间是用于片外外设扩展；
3. 在0x60000000到0x9FFFFFFF的1GB的地址存储空间是用于扩展片外存储器；
4. 在0x40000000到0x5FFFFFFF的512MB的地址存储空间是用于片上外设；
5. 在0x20000000到0x3FFFFFFF的512MB的地址存储空间是片上SRAM；STM32F103VET处理器64kB，起始地址是0x20000000到0x20010000。
6. 在0x00000000到0x1FFFFFFF的512MB的地址存储空间是代码区；STM32F103VET处理器512kB，起始地址是0x80000000到0x1FFFFFFF。



## 程序烧录

**1、程序烧录方式。**

[单片机三种烧录方式ICP、IAP和ISP详解 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/69237591)

1. 一种为ICP（在线编程），适用于JTAG或SWD协议下的烧写程序。
2. 另一种称为IAP（在应用编程），适用于很多接口（USB，串口，CAN）下载到存储器中，IAP允许在程序运行时重新烧写FLASH。

**2、程序烧录文件：HEX文件和bin文件的区别**







## Bootloader





## 时钟树

1、STM32有几个时钟源？

STM32 有5个时钟源——HSI、HSE、LSI、LSE、PLL：

1. HSI是高速内部时钟，RC振荡器，频率为8MHz，精度不高。
2. HSE是高速外部时钟，可接石英/陶瓷谐振器，或者接外部时钟源，频率范围为4MHz~16MHz。
3. LSI是低速内部时钟，RC振荡器，频率为40kHz，提供低功耗时钟。　
4. LSE是低速外部时钟，接频率为32.768kHz的石英晶体。
5. PLL为锁相环倍频输出，其时钟输入源可选择为HSI/2、HSE或者HSE/2。倍频可选择为2~16倍，但是其输出频率最大不得超过72MHz。

2、简述设置系统时钟的基本流程？

1. 打开HSE，等待就绪后，设置Flash等待操作。
2. 设置AHB、APB1、APB2的分频系数，确定他们各自和系统时钟的关系。
3. 设置CFGR寄存器确定PLL的时钟来源和倍频系数(HSE外部8M*9倍=72MHz)。
4. 使能PLL，将系统时钟源切换到PLL.







## 启动过程

1、介绍一下STM32的启动过程？

1. 通过Boot引脚设定，寻找初始地址。
2. 初始化栈指针 __initial_sp。
3. 指向复位程序 Reset_Hander。
4. 设置异常中断 HardFault_Handler。
5. 设置系统时钟 SystemInit。
6. 调用C库函数 _main。

## GPIO

1、STM32的GPIO的操作及8种模式？

GPIO_Mode_AIN 模拟输入
GPIO_Mode_IN_FLOATING 浮空输入
GPIO_Mode_IPD 下拉输入
GPIO_Mode_IPU 上拉输入
GPIO_Mode_Out_OD 开漏输出
GPIO_Mode_Out_PP 推挽输出
GPIO_Mode_AF_OD 复用开漏输出
GPIO_Mode_AF_PP 复用推挽输出



## 中断

1、嵌入式中断系统的概念、并举例说明中断的执行过程？

中断是指计算机运行过程中，出现某些意外情况需主机干预时，机器能自动停止正在运行的程序并转入处理新情况的程序，处理完毕后又返回原被暂停的程序继续运行。

2、STM32的中断控制器支持多少个外部中断？



3、中断服务函数列表？

IO口外部中断在中断向量表中只分配了7个中断向量，也就是只能使用7个中断服务函数。

- EXTI0_IRQHandler
- EXTI1_IRQHandler
- EXTI2_IRQHandler
- EXTI3_IRQHandler
- EXTI4_IRQHandler
- EXTI9_5_IRQHandler
- EXTI15_10_IRQHandler

4、串口中断TXE和TC的区别：

 其实很明显，一个是发送寄存器空标志，一个是发送完成标志。因为串口在发送的时候首先需要把发送寄存器中的数据移位到移位寄存器（影子寄存器）后再串行发送出去。所以当发送寄存器DR空时说明现在可能正在往外面发送数据，数据可能还没有发送完。但是发送完成不一样，他是在移位寄存器将本次数据全部移位完成后设置的标志位（也就是发送完了停止位）。这么看来：TXE允许程序有更充裕的时间填写TDR寄存器，保证发送的数据流不间断。TC可以让程序知道发送结束的确切时间，有利于程序控制外部数据流的时序。

5、定时器中断溢出更新时间：Tout=((arr+1)*(psc+1))/Tclk，ARR为自动装载寄存（1~65535）、PSC为分频系数，TCLK为输入时钟频率（Mhz）。

6、PWM1和PWM2模式的区别仅在于相位的180度。前者高电平时，后者低电平。

7、定时器输入捕捉有一个滤波器，顾名思义滤波器起到的就是滤波的作用，在捕捉外部信号时，信号可能不稳定，此时需要滤波：当检测到有外部输入时，需要再连续采样N次如果确定为高电平/低电平，则触发响应中断（如果开启了的话）。



## TIM



## DAC

DAC有两个寄存器，一个是DHR（Data HoldingRegister）数据保持寄存器，一个DOR（Data Output Register）数据输出寄存器。真正起作用的是DOR寄存器，该寄存器把值给数模转换发生单元输出以VREF+为参考电压的电压值。如果是硬件触发转换，系统将在1个ABP时钟周期后把值给DOR，如果是软件触发转换，时间为3个APB时钟周期。然后，均等待Tsetting时间（Typical为3us,Max为4us）后真正输出电压值。


## DMA

1、DMA介绍？

直接存储器存取（DMA）：用来提供在外设和存储器之间或者存储器和存储器之间的高速数据传输。无须CPU干预，数据可以通过DMA快速地移动，这就节省了CPU的资源来做其他操作。

2、DMA传输模式有几种？

- DMA_Mode_Circular 循环模式
- DMA_Mode_Normal 正常缓存模式

应用场景：GPS、蓝牙，都是用的循环采集，即使用DMA_Mode_Circular模式。







## USART

1、串行通信方式介绍？

同步通信：I2C 半双工，SPI 全双工
异步通信：RS485 半双工、RS232 全双工

2、串口设置的一般步骤可以总结为如下几个步骤：

1. 串口时钟使能，GPIO时钟使能。
2. 串口复位。
3. GPIO端口模式设置：TX的GPIO工作模式为：`GPIO_Mode_AF_PP;//复用推挽输出`。RX的GPIO工作模式为：`GPIO_Mode_IN_FLOATING;//浮空输入`。
4. 串口参数初始化：主要包含——波特率设置（115200）、8个数据位、1个停止位、无奇偶校验位、无硬件数据流控制、收发模式。
5. 开启中断并且初始化NVIC（如果需要开启中断才需要这个步骤）。
6. 使能串口。
7. 编写中断处理函数。

3、USART主要特点？

​        （1）全双工操作（相互独立的接收数据和发送数据）；
​        （2）同步操作时，可主机时钟同步，也可从机时钟同步；
​        （3）独立的高精度波特率发生器，不占用定时/计数器；
​        （4）支持5、6、7、8和9位数据位，1或2位停止位的串行数据桢结构；
​        （5）由硬件支持的奇偶校验位发生和检验；
​        （6）数据溢出检测；
​        （7）帧错误检测；
​        （8）包括错误起始位的检测噪声滤波器和数字低通滤波器；
​        （9）三个完全独立的中断，TX发送完成、TX发送数据寄存器空、RX接收完成；
​        （10）支持多机通信模式；
​        （11）支持倍速异步通信模式。

4、UART没有时钟线，那接收方如何知道何时接收？





## I2C

1、I2C 总线在传送数据过程中共有三种类型信号？
（1）开始信号：SCL 为高电平时，SDA 由高电平向低电平跳变，开始传送数据。
（2）结束信号：SCL 为高电平时，SDA 由低电平向高电平跳变，结束传送数据。
（3）应答信号：接收数据的 IC 在接收到 8bit 数据后，向发送数据的 IC 发出特定的低电平脉冲，表示已收到数据。CPU 向受控单元发出一个信号后，等待受控单元发出一个应答信号，CPU 接收到应答信号后，根据实际情况作出是否继续传递信号的判断。若未收到应答信号，由判断为受控单元出现故障

2、I2C配置主机模式端口该怎么配置？
硬件模式：复用开漏输出、既不上拉也不下拉。（快速模式：400 Kbit/s）
软件模拟：推挽输出、配置上拉电阻。

3、I2C仲裁机制？
遵循“低电平优先”的原则，即谁先发送低电平谁就会掌握对总线的控制权。



## SPI

1、SPI需要几根线？

SPI 接口一般使用 4 条线通信：

- MISO 主设备数据输入，从设备数据输出。
- MOSI 主设备数据输出，从设备数据输入。
- SCLK 时钟信号，由主设备产生。
- CS 从设备片选信号，由主设备控制。

2、12.SPI通信的四种模式？

SPI 有四种工作模式，各个工作模式的不同在于 SCLK 不同, 具体工作由 CPOL，CPHA 决定。

CPOL: (Clock Polarity)，时钟极性：

SPI的CPOL，表示当SCLK空闲idle的时候，其电平的值是低电平0还是高电平1：
CPOL=0，时钟空闲idle时候的电平是低电平，所以当SCLK有效的时候，就是高电平，就是所谓的active-high；
CPOL=1，时钟空闲idle时候的电平是高电平，所以当SCLK有效的时候，就是低电平，就是所谓的active-low；

3、如何确定使用SPI的哪种模式来进行通信？

- 先确认从机需求的 SCLK 极性，不工作时是在低电位还是高电位，由此确认 CPOL 为 0 或 1。看原理图，我们设置串行同步时钟的空闲状态为高电平所以我们选择 SPI_CPOL_High，也就是CPOL为1。
- 再由slave芯片 datasheet 中的时序图确认 slave 芯片是在 SCLK 的下降沿采集数据，还是在SCLK的上升沿。

4、模拟SPI和硬件SPI的区别是什么？

硬件 SPI是芯片的外设功能，而模拟的SPI是用GPIO实现的。

硬件SPI因为有专用的寄存器支持，所以很少占用CPU资源，但是并不是每一款处理器都能提供SPI，而且有时候即使有SPI硬件接口，可能因为数量不够或者管脚被占用，导致硬件SPI不能使用，这时候就可以使用GPIO模拟SPI通讯，这样的好处是可以使用任意GPIO管脚实现SPI通讯，并且代码通用性很强，可以在不同处理器甚至不同架构之间移植，比较方便。





## RTC



## CAN

1、CAN总结介绍一下？

CAN控制器根据 CAN_L 和 CAN_H上 的电位差来判断总线电平。总线电平分为显性电平和隐性电平，二者比居其一。发送方通过使总线电平发生变化，将消息发送给接收方。

2、CAN初始化配置步骤?

1. 配置相关引脚的复用功能，使能CAN时钟。
2. 设置CAN工作模式及波特率等（CAN初始化环回模式,波特率500Kbps ）。
3. 设置滤波器。

3、CAN发送数据格式?

- CanTxMsg TxMessage;
- TxMessage.StdId=0x12; // 标准标识符
- TxMessage.ExtId=0x12; // 设置扩展标示符
- TxMessage.IDE=CAN_Id_Standard; // 标准帧
- TxMessage.RTR=CAN_RTR_Data; // 数据帧
- TxMessage.DLC=len; // 要发送的数据长度 发送8个字节
- for(i=0;i<len;i++)
- TxMessage.Data[i]=msg[i]; //数据





## 看门狗





## 汉字

常用的汉字内码系统有GB2313、GB13000、GBK、BIG5(繁体)。其中GB2313只有几千个汉字，而GBK则有2万多汉字。



# 物联网

1、物联网的架构分为几层？每一层都负责哪些功能？

分三层，物联网从架构上面可以分为感知层、网络层和应用层：

1. 感知层： 负责信息采集和物物之间的信息传输，信息采集的技术包括传感器、条码和二维码、 RFID射频技术、音视频等多媒体信息，信息传输包括远近距离数据传输技术、自组织组网技术、协同信息处理技术、信息采集中间件技术等传感器网络。感知层是实现物联网全面感知的核心能力，是物联网中包括关键技术、标准化方面、产业化方面亟待突破的部分，关键在于具备更精确、更全面的感知能力，并解决低功耗、小型化和低成本的问题。
2. 网络层： 是利用无线和有线网络对采集的数据进行编码、认证和传输，广泛覆盖的移动通信网络是实现物联网的基础设施，是物联网三层中标准化程度昀高、产业化能力昀强、昀成熟的部分，关键在于为物联网应用特征进行优化和改进，形成协同感知的网络。
3. 应用层： 提供丰富的基于物联网的应用，是物联网发展的根本目标，将物联网技术与行业信息化需求相结合，实现广泛智能化应用的解决方案集，关键在于行业融合、信息资源的开发利用、低成本高质量的解决方案、信息安全的保障以及有效的商业模式的开发。

# Git的使用

1、列举工作中常用的几个git命令？

- 新增文件的命令：git add file或者git add .
- 提交文件的命令：git commit –m或者git commit –a
- 查看工作区状况：git status –s
- 拉取合并远程分支的操作：git fetch/git merge或者git pull
- 查看提交记录命令：git reflog

2、提交时发生冲突，你能解释冲突是如何产生的吗？你是如何解决的？

开发过程中，我们都有自己的特性分支，所以冲突发生的并不多，但也碰到过。诸如公共类的公共方法，我和别人同时修改同一个文件，他提交后我再提交就会报冲突的错误。
发生冲突，在IDE里面一般都是对比本地文件和远程分支的文件，然后把远程分支上文件的内容手工修改到本地文件，然后再提交冲突的文件使其保证与远程分支的文件一致，这样才会消除冲突，然后再提交自己修改的部分。特别要注意下，修改本地冲突文件使其与远程仓库的文件保持一致后，需要提交后才能消除冲突，否则无法继续提交。必要时可与同事交流，消除冲突。

发生冲突，也可以使用命令：

- 通过git stash命令，把工作区的修改提交到栈区，目的是保存工作区的修改；
- 通过git pull命令，拉取远程分支上的代码并合并到本地分支，目的是消除冲突；
- 通过git stash pop命令，把保存在栈区的修改部分合并到最新的工作空间中；

3、如果本次提交误操作，如何撤销？

如果想撤销提交到索引区的文件，可以通过git reset HEAD file；如果想撤销提交到本地仓库的文件，可以通过git reset –soft HEAD^n恢复当前分支的版本库至上一次提交的状态，索引区和工作空间不变更；可以通过git reset –mixed HEAD^n恢复当前分支的版本库和索引区至上一次提交的状态，工作区不变更；可以通过git reset –hard HEAD^n恢复当前分支的版本库、索引区和工作空间至上一次提交的状态。

4、如果我想修改提交的历史信息，应该用什么命令？

如果修改最近一次提交的历史记录，就可以用**git commit –amend**命令；vim编辑的方式；如果修改之前提交的历史记录，就需要按照下面的步骤：

1. 首先查看前三次的提交历史记录：`git log -3`。
2. 执行命令`git rebase –i HEAD~3`，会把前3次的提交记录按照倒叙列出来。
3. 根据提示，执行`git commit –amend`命令，进入vim编辑器并修改提交信息。
4. 然后执行git rebase –continue命令。
5. 查看修改结果：`git log -3`。

5、你使用过git stash命令吗？你一般什么情况下会使用它？

命令git stash是把工作区修改的内容存储在栈区。
以下几种情况会使用到它：

- 解决冲突文件时，会先执行git stash，然后解决冲突；
- 遇到紧急开发任务但目前任务不能提交时，会先执行git stash，然后进行紧急任务的开发，然后通过git stash pop取出栈区的内容继续开发；
- 切换分支时，当前工作空间内容不能提交时，会先执行git stash再进行分支切换。

6、如何查看分支提交的历史记录？查看某个文件的历史记录呢？

查看分支的提交历史记录：

- 命令git log –number：表示查看当前分支前number个详细的提交历史记录；
- 命令git log –number –pretty=oneline：在上个命令的基础上进行简化，只显示sha-1码和提交信息；
- 命令git reflog –number: 表示查看所有分支前number个简化的提交历史记录；
- 命令git reflog –number –pretty=oneline：显示简化的信息历史信息；
  如果要查看某文件的提交历史记录，直接在上面命令后面加上文件名即可。
  注意：如果没有number则显示全部提交次数。

7、能不能说一下git fetch和git pull命令之间的区别？

简单来说：git fetch branch是把名为branch的远程分支拉取到本地；而git pull branch是在fetch的基础上，把branch分支与当前分支进行merge；因此pull = fetch + merge。

8、使用过git merge和git rebase吗？它们之间有什么区别？

简单的说，git merge和git rebase都是合并分支的命令。
git merge branch会把branch分支的差异内容pull到本地，然后与本地分支的内容一并形成一个committer对象提交到主分支上，合并后的分支与主分支一致；
git rebase branch会把branch分支优先合并到主分支，然后把本地分支的commit放到主分支后面，合并后的分支就好像从合并后主分支又拉了一个分支一样，本地分支本身不会保留提交历史。

9、能说一下git系统中HEAD、工作树和索引之间的区别吗？

- HEAD文件包含当前分支的引用（指针）；
- 工作树是把当前分支检出到工作空间后形成的目录树，一般的开发工作都会基于工作树进行；
- 索引index文件是对工作树进行代码修改后，通过add命令更新索引文件；GIT系统通过索引index文件生成tree对象。

10、之前项目中是使用的GitFlow工作流程吗？它有什么好处？

GitFlow可以用来管理分支。GitFlow工作流中常用的分支有下面几类：

- master分支：最为稳定功能比较完整的随时可发布的代码，即代码开发完成，经过测试，没有明显的bug，才能合并到 master 中。请注意永远不要在 master 分支上直接开发和提交代码，以确保 master 上的代码一直可用；
- develop分支；用作平时开发的主分支，并一直存在，永远是功能最新最全的分支，包含所有要发布 到下一个 release 的代码，主要用于合并其他分支，比如 feature 分支； 如果修改代码，新建 feature 分支修改完再合并到 develop 分支。所有的 feature、release 分支都是从 develop 分支上拉的。
- feature分支；这个分支主要是用来开发新的功能，一旦开发完成，通过测试没问题（这个测试，测试新功能没问题），我们合并回develop 分支进入下一个 release
- release分支；用于发布准备的专门分支。当开发进行到一定程度，或者说快到了既定的发布日，可以发布时，建立一个 release 分支并指定版本号(可以在 finish 的时候添加)。开发人员可以对 release 分支上的代码进行集中测试和修改bug。（这个测试，测试新功能与已有的功能是否有冲突，兼容性）全部完成经过测试没有问题后，将 release 分支上的代码合并到 master 分支和 develop 分支
- hotfix分支；用于修复线上代码的bug。**从 master 分支上拉。**完成 hotfix 后，打上 tag 我们合并回 master 和 develop 分支。

GitFlow主要工作流程：

1. 初始化项目为gitflow , 默认创建master分支 , 然后从master拉取第一个develop分支。
2. 从develop拉取feature分支进行编码开发(多个开发人员拉取多个feature同时进行并行开发 , 互不影响)。
3. feature分支完成后 , 合并到develop(不推送 , feature功能完成还未提测 , 推送后会影响其他功能分支的开发)；合并feature到develop , 可以选择删除当前feature , 也可以不删除。但当前feature就不可更改了，必须从release分支继续编码修改。
4. 从develop拉取release分支进行提测 , 提测过程中在release分支上修改BUG
5. release分支上线后 , 合并release分支到develop/master并推送；合并之后，可选删除当前release分支，若不删除，则当前release不可修改。线上有问题也必须从master拉取hotfix分支进行修改；
6. 上线之后若发现线上BUG , 从master拉取hotfix进行BUG修改；
7. hotfix通过测试上线后，合并hotfix分支到develop/master并推送；合并之后，可选删除当前hotfix ，若不删除，则当前hotfix不可修改，若补丁未修复，需要从master拉取新的hotfix继续修改；
8. 当进行一个feature时 , 若develop分支有变动 , 如其他开发人员完成功能并上线 , 则需要将完成的功能合并到自己分支上，即合并develop到当前feature分支；
9. 当进行一个release分支时 , 若develop分支有变动 , 如其他开发人员完成功能并上线 , 则需要将完成的功能合并到自己分支上，即合并develop到当前release分支 (!!! 因为当前release分支通过测试后会发布到线上 , 如果不合并最新的develop分支 , 就会发生丢代码的情况)；

GitFlow的好处：为不同的分支分配一个明确的角色，并定义分支之间如何交互以及什么时间交互；可以帮助大型项目理清分支之间的关系，简化分支的复杂度。

11、使用过git cherry-pick，有什么作用？

命令git cherry-pick可以把branch A的commit复制到branch B上。
在branch B上进行命令操作：

- 复制单个提交：`git cherry-pick commitId`。
- 复制多个提交：`git cherry-pick commitId1…commitId3`。
- 注意：复制多个提交的命令不包含`commitId1.`。

12、git跟其他版本控制器有啥区别？

> 分布式与集中式的区别

GIT是分布式版本控制系统，其他类似于SVN是集中式版本控制系统。
分布式区别于集中式在于：每个节点的地位都是平等，拥有自己的版本库，在没有网络的情况下，对工作空间内代码的修改可以提交到本地仓库，此时的本地仓库相当于集中式的远程仓库，可以基于本地仓库进行提交、撤销等常规操作，从而方便日常开发。

13、我们在本地工程常会修改一些配置文件，这些文件不需要被提交，而我们又不想每次执行git status时都让这些文件显示出来，我们该如何操作？

首先利用命令touch .gitignore新建文件：`touch .gitignore`。

然后往文件中添加需要忽略哪些文件夹下的什么类型的文件：

```
$ vim .gitignore
$ cat .gitignore
/target/class
.settings
.imp
*.ini
```

注意：忽略/target/class文件夹下所有后缀名为.settings、.imp的文件，忽略所有后缀名为.ini的文件。

14、如何把本地仓库的内容推向一个空的远程仓库？

首先确保本地仓库与远程之间是连同的。如果提交失败，则需要进行下面的命令进行连通：

```c
git remote add origin XXXX  // XXXX是远程仓库地址
```

如果是第一次推送，则进行下面命令：

```c
git push -u origin master   // -u 是指定origin为默认主分支
```

提交：

```c
git push origin master     // 
```

# FreeRTOS









# 数据结构









# 算法





# C++

# 项目参考

项目就是你参与做过的产品，你说的彩灯控制器、电子钟、自动售水机...都符合项目(小作品)的说法，不过你这样回答只说了表面，等于没说。核心应该说你在其中负责的开发部分，涉及或者学到了什么知识，才是对方想知道的。以电子钟为例，涉及到定时器的处理，时间的计数，可能用到中断，如果有显示界面，可能还有显示屏的驱动，菜单的实现，能够把这些说清楚，先不管产品多小，至少你对整个开发有清晰的思路，这才是面试想考察的东西。如果还不清晰，可以看我前段时间的分享[https://www.cnblogs.com/zc110747/p/](https://link.zhihu.com/?target=https%3A//www.cnblogs.com/zc110747/p/10739703.html)

> 作者：听心跳的声音
> 链接：https://www.zhihu.com/question/320068468/answer/674220759
> 来源：知乎
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。





