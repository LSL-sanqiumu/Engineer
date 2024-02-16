

# 学嵌入式？

我属于半路出家，之前专业是电气，到目前为止，做单片机开发有12年时间了，做过的行业和技术涉及比较杂，智能楼宇、智能家居、智能安防、电表、车载产品、Lora、WiFi、4G、GSM、蓝牙等等，大大小小产品做过几十个。

做过单片机开发的，相对纯软件程序员，最有意思的是，我能搞出来一个实实在在的东西，而且这个东西，自己从硬件到软件都很通透，不像做纯软件做应用的，底层全部现成的，你只是个调库侠。

如果你经常阅读嵌入式怎么学的文章，你会有一种错觉，这个行业要学得东西太多了，觉得门槛很高，收入和付出不成正比。

从事行业越久，我越发现这个行业涉及的知识确实无穷无尽，一辈子也学不完。

但是如果你的目标仅仅是找份工作，并不需要学很多东西，4-6个月左右完全可以达到找工作水平。

很多东西，你前期的时候并不需要深入学习，甚至都不需要学。

下面根据我从业多年经验，给大家总结一个比较靠谱的学习路线，让你少看几十G教程。

## 一、硬件需要学习的内容

1.做嵌入式开发，需要对硬件有一定了解，能看得懂电路图就可以了，不需要会设计的程度。

特别是不要纠结模拟电路，否则你会死得很惨，这个不是新手阶段能学得懂的。

以前我就是在模拟电路上浪费了很多时间，学不懂、工作以后才发现模电的知识实际用得也很少。

2.先学习常用的元器件，比如电阻、电容、电感、二极管、三极管、MOS管原理及作用。
可以参照一些硬件基础课目录学习：

1. 电阻
2. 电容
3. 电感
4. 二极管
5. 三极管
6. MOS管
7. 

这些内容，基本上就是刚需中的刚需，产品中最常用的了。


3.学完常用元器件，再通过开发板或者项目学单片机最小系统电路和功能性模块电路（LED驱动、按键检测、数码管显示、屏显示、蜂鸣器驱动、存储电路等），不断积累。

4.学完这个再学1个画图工具，我最开始学的是Protel99se，不过现在已经过时了，目前一般用AD、Allegro、Pads、Cadence等等，学会其中一款，能用它看原理图就可以了，先别学PCB，这是硬件工程师干的活。



## 二、软件学习

做嵌入式单片机开发，软件是我们学习的主力，也是花费时间最多的地方。

### 1.C语言

单片机支持C语言和汇编两种语言，目前产品开发主流是C语言，所以先学C语言就可以了。

前期学学基本语法就够了，可以参考这个课程目录：

1. 单片机是什么？
2. 单片机资源有哪些？
3. 二进制和十六进制。
4. C51点亮LED灯。
5. 变量的定义和应用。
6. C语言算术运算符。
7. C语言关系运算符。
8. C语言位运算符。
9. if语句、while语句、switch语句、for语句、break、continue、goto语句。
10. C语言逻辑运算符。
11. C语言赋值运算符。
12. C语言函数定义和调用。
13. include、sfr、sbit关键字的用法。
14. C语言条件编译命令。
15. 数组定义和赋值。
16. 多维数组定义和赋值。

不用学得太深，这个阶段甚至指针都可以先不学。

> 书籍：《C Programming Language》；《C和指针》、《C专家编程》、《C陷阱与缺陷》这三本的内容挑着看，研究哪部分内容就看哪部分。
>
> 啥叫会编程？**会编程，是指在应对各种不同的业务需求时，都能很快的将业务逻辑转化成编程逻辑，并且编码实现的能力。**
>
> 编程能力提升：阅读开源代码、做项目、写算法。
>
> 比如Linux系统的源码，举例：
>
> ```c
> // 对比两数大小，一个宏实现，一个函数实现
> #define MAX( a, b) ( (a) > (b)?(a) : (b) )  
> int max( int a, int b)
> {
> 　　return ((a > b)? a : b);
> }
> ```
>
> 



ANSI C 、POSIX C、GNU C到底是啥？之间到底有啥关系？

### 2.51单片机

我是先学了STC89C51单片机，我也建议零基础的从51单片机开始学习，比较好上手，直接淘个开发板跟着教程学，基本没什么技巧。

C语言和单片机可以同时学习，正好边学边实操，实操才是重点，这个技术光看是学不会的。

### 3.做小项目

学完51单片机以后，先不要急着学STM32或者性能更高的单片机，不然你后面会学得很吃力，问题比你学得知识还多。

先用51单片机做几个小项目，比如智能小车、电子时钟、温湿度智控之类的。

这一步很关键，也是最多人跳过的一步，为什么？

**单片机只是工具，更高端的单片机，只能代表这个工具能做更复杂的项目，但是能不能把项目做出来，不在于工具本身，而是用工具的人，取决于你的编程思路和编程水平，这两东西只能通过项目去锻炼出来。**

### 4.学习C语言高阶用法

这个阶段深入学指针、结构体、枚举，以及它们的实际应用是最佳时机。

后面STM32的库，会大量使用这些玩意。

### 5.学STM32

STM32对于初学者来说就是噩梦，我在学STM32的时候已经工作了大概半年了，用过STC15系列和NXP的单片机改过项目程序。

即便如此，研究起来还是会有点吃力，STM32主要就是学库的使用，如果你深入寄存器去学习，虽然学得比较透彻，但会遥遥无期。

其实STM32很多外设可以先不用学习，除了给初学者学习的开发板，大多数项目只会用到它部分外设资源，并非全部。

所以，我们前期只需要学一些常用的外设就可以了，比如说GPIO、Systick、Timer、USART、NVIC、EXTI、DMA、ADC、SPI、IIC。

这些外设基本上是产品的刚需。

### 6.持续做项目

前面学得那些就是基础技能，接下来就需要不断做项目提升，成长速度和高度由项目数量和质量决定。

如果你从事开发很多年，会发现，真正让你成长最大的就是工作以后，因为工作内容基本就是做项目，做项目，做项目，还有一点很关键，就是身边有领导或同事能指导你。

如果你学完STM32，找工作处处碰壁，也是正常的，毕竟光会基础技能毫无竞争力，就是看运气。

**解决办法就是可以自己去网上找些项目做**，如果自己摸索太慢，想办法找人指导，这样成长快点。

### 7.RTOS

实时操作系统，我认为在你没碰到需求之前，可以先不用学，毕竟不是刚需，当然，你学了也可以作为一个加分项。

不过我建议在你没做过任何基于STM32项目的时候，不要去学，不然可能会耗费你1-2个时间。

因为你的经验和编程底子太薄，去理解RTOS的知识占用时间太长，而且RTOS的很多东西，你不知道它们到底用在哪里，学得云里雾里。

核心还是先通过项目不断提升编程思维和代码水平，干它3-4个项目以后，RTOS对你来说就是水到渠成的事情，可能1-2周就上手了。



# 初学者怎样提高C/C++编程能力？

    	首先、什么算你所谓的编程能力？
    	我们对一项技能的掌握程度往往很难量化，对于编程能力的考量可能比较抽象，我们来类比比较直观的其他技能。比如说什么叫会弹吉他？我们说一个人吉他玩的好，这个人会弹吉他，是指他会弹《小星星》？还是会弹岸部真明的《time travel》？（力荐，好听！）恐怕都不是，我们对于会弹吉他的认知，应当是随手给他一个不熟悉的谱子，你也能很快的用吉他精彩的演奏，我们才说这个人吉他玩的真6。那编程也是，我们所希望的编程能力，指的是会写双向链表还是会写二叉树？恐怕都不是，我们所指的会编程，是指他在应对各种不同的业务需求时，都能很快的将业务逻辑转化成编程逻辑，并且编码实现的能力。
    
        那么、如何来锻炼这种能力？
    
        前段时间在罗胖的《得到app》上听的一篇精品课，非常受启发。一位老师讲如何高效地学习一项技能，他用两年的时间就从零基础达到了专业级的弹指吉他大师的水平，他所使用的方法很值得借鉴。内容大概是这样：他一开始接触吉他，没有从基础开始练，而是直接挑战难度极高的世界名曲开始演奏。可想而知这难度是极大的，没有任何基础的他，很多和弦都压不住。尤其对与刚玩吉他的人，十指连心啊，压弦的那只手是钻心的疼。一开始一句完整的都弹不下来，更别提什么扫弹，闷音，切音的技巧。就这样一节一节地弹，经过不懈的努力，他把这首曲子拿了下来。
    
         巨大的成就感是自然的，但对于优秀的渴望使得这位大佬感到仍然不能满足。怎么办呢？请教名师！这时候老师告诉他：“一禅呐！所谓知之者不如好之者、好之者不如乐之者，你现在已经能够从弹奏吉他中获得喜悦，现在，请再回过头，从基础开始学起。”这下子他才开始从最基础的乐理开始，什么叫节奏、什么叫旋律、什么叫音阶、什么C调G调F调。原来之前练到手指快疼死的的指法叫F和弦？原来之前的曲子里变调是这个意思？
    
       和上去就啃吉他基础教学不一样，这波儿基础的学习让他任督二脉蹭的一下就通了，仿佛杨过一身雄厚的内劲得黄药师点化一番，实力大增。不但能将那首世界名曲演绎的更加纯熟，对于其他没有演奏过乐曲，只要稍加练习，就能够德芙般顺滑地弹奏下来。
    
        同样的方法，映射到编程上，就是我想说的学习方法。我很不建议一开始就从基础开始啃，有多少人从大一刚入学立志将来做一个IT大佬，抱着一本《C++ Primer》开始啃，最后啃不到200页就去LOL上分冲段位了。所以我的建议是，一开始只要会点儿基础语法，就定一个小目标去实现就好了，不必强求每一行代码都是亲自手写。遇到问题就查，百度也可以查书也可以，我一开始写个五子棋小游戏的时候，连数组的声明语法都是查书的。把你遇到的问题从业务逻辑定位成代码逻辑，然后知道从哪儿可以找到想要的答案，这个能力在未来的工作、编程和面试中非常重要。
    
        一两个完整的程序做下来之后，再回过头来从变量、语法、表达式、流程控制、函数....重新去学习这门编程语言，这时候你会不断地发现原来这个地方这么写的原因是这样？原来这个地方是这么实现的，那个地方我还可以这么写。一本枯燥的语法书籍你会很流畅地读下来，甚至还可能读出快感和兴趣，这样一顿操作之后，你可以算真正掌握了一门编程语言，有了自己的理解在里面，并且有对应的应用经验，未来的面试中也可以讲的头头是道。

————————————————
版权声明：本文为CSDN博主「CodingPs」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/CodingPs/article/details/103460891

# C艹

作者：Skiiii
链接：https://www.zhihu.com/question/390717188/answer/1184954255
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



算了吧，过来人告诉你，大学里面那堆项目，99%是没有任何技术含量的廉价劳动力，我觉得只有毫无目标且焦虑的人才会觉得做点大学的项目是在锻炼你。

我自己读研的时候只想推掉所有分给我的实验室的项目，避免让这些东西占我自己瞎搞的时间。

后来工作面试遇到过各种做大学导师垃圾C艹项目的人，结果你问他一个C艹虚函数怎么实现的（没有标准答案，你能说出来可行的方案就行），一无所知。反而背了一大堆 mfc 的 API，简直不忍直视。

说真的，找对路线，进互联网公司做个平凡的码农(BAT级别)简直太简单了，随便列举一个有脑子就行的弱鸡路线:

1.  大一大二打好基础，操作系统，网络，任意一门C系带面向对象的语言吃透(基本的底层实现，一般一本语法，3本进阶就够了)，基本的算法数据结构(真的很基本)，Linux 基本 API 和机制。
2.  大三去看看开源项目，有感兴趣的研究研究，吃透一两个开源库的源码（要我推荐就是 leveldb，不仅学习 lsm tree，顺便看看人家怎么设计 C++ 模块的）。
3.  跟 1、2 并行的，每天刷一道 leetcode，学完什么数据结构/算法，就去刷什么题，这样三年下来，怎么也刷了4、500道题了。

上面的按部就班做完，还找不到工作的话你可以上知乎发简历给我，我帮你内推啊 。

# 硬件

一个实际电路的原理图是怎样设计出来的？ - HANs的回答 - 知乎 https://www.zhihu.com/question/358059963/answer/920402590

>打工迷途小菜菜
>
>评论：电路板，首先有需求过来，我们的电路板要完成这些需求，就要有对应的功能，功能来满足需求，这个是源头。比如你家里的交换机，需要网口，这就需要交换芯片和PHY芯片，这些需要电源芯片，时钟芯片，电阻，电容一堆东西才能工作，然后你的交换机（比如带wifi的），你要设置密码，这就需要WiFi无线相关的电路和芯片，还需要cup芯片去接收密码，以及下配置到相应芯片去使密码生效。这些芯片要正常工作的话，还需要电源模块，我们进去的是220V交流电，但是我们的芯片是需要低压直流供电的。你看，电路图就是这样出来的。需求-》方案-》原理图设计（CPU芯片+各种功能的芯片+时钟芯片+电源芯片+一堆电阻电容电感磁珠等等+PCB板，再加上SMT焊接，焊接插接件），回板之后静态阻抗测试（防止电源短路），上电硬件调试，看各个电源电压是否正常，时钟波形有没有出来，再之后和软件联调，用jtag线看能不能扫到CPU（这个很关键，否则板子就是一块砖头），扫到后下载准备好的程序（就是底层驱动代码），用cpu开始调试外围期间（SPI，I2C等，或者牛一点的PCIE等），所有外围芯片都扫到后，开始调试功能，再到后期的测试+软件+硬件，进行解决测试发现的问题，再然后电路板出货。这个是数字电路板的基本流程。模拟电路板差不多，就是不太好调试，原理图设计时，电路仿真要做好，否则后期就是坑。

# 嵌入式之路

> 作者：绿帽蝙蝠侠
> 链接：https://www.zhihu.com/question/623422508/answer/3227565506
> 来源：知乎
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

劝你还是专心搞机械吧，你这路子已经走歪了。

搞[嵌入式](https://www.zhihu.com/search?q=嵌入式&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})，无非单片机和嵌入式Linux两个方向。

单片机用不到C++，只用C就够了，I2C、SPI、CAN等各种[通信协议](https://www.zhihu.com/search?q=通信协议&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})代码，每一步写法都是固定的，顺序变了就不正确了。完全死记硬背，跟默写课文一样，没编程基础也没关系，反正有没有基础，都是背。

因为[单片机](https://www.zhihu.com/search?q=单片机&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})的重点根本不在编程。而在于搞清楚各种[电子元件](https://www.zhihu.com/search?q=电子元件&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})的作用，并利用这些电子元件画出[原理图](https://www.zhihu.com/search?q=原理图&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})和PCB。

这需要学好[电子电路基础](https://www.zhihu.com/search?q=电子电路基础&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})，然后进行长期缓慢的积累，熟悉市面上各种型号、各种封装的电子元件。

只有先搞清楚每种元件的作用、性能与[价格](https://www.zhihu.com/search?q=价格&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})，区分它们的相同点与不同点，才能基于它们来设计电路。

硕士毕业啥岁数了？积累到能画PCB又啥岁数了？

如果要走单片机路线，个人建议重点放在电路本身，别把太多精力花在代码上。毕竟单片机绝大部分代码都是固定的。至少在理论上，任何固定代码，都可以一键生成。

就算今天不能生成，但万一哪天能了呢？

很多人担心自己的工作会被人工智能取代，对于单片机方向的所谓[嵌入式软件工程师](https://www.zhihu.com/search?q=嵌入式软件工程师&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})来说，这些担忧太早、太着急了。

因为生成固定代码，连人工智能都不需要。在汽车行业的Autosar上，今天已经有单片机[控制程序](https://www.zhihu.com/search?q=控制程序&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})的全自动生成方案了。

案板上躺着的还没开始慌，牧场里跑着的慌什么？

------

至于[嵌入式Linux](https://www.zhihu.com/search?q=嵌入式Linux&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})，分为[三大件](https://www.zhihu.com/search?q=三大件&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})。

Bootloader，通常是用U-Boot。

Kernel，也就是内核。

RootFiles，中文名叫[根文件系统](https://www.zhihu.com/search?q=根文件系统&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})。

这些东西里面确实包含C++代码，但这些代码不需要你写，而是[理查德](https://www.zhihu.com/search?q=理查德&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})·[斯托曼](https://www.zhihu.com/search?q=斯托曼&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})、[林纳斯·托瓦兹](https://www.zhihu.com/search?q=林纳斯·托瓦兹&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})等人的工作。

你要做的，是把它们的源码下载下来，进行一些自定义设置，然后用[交差编译器](https://www.zhihu.com/search?q=交差编译器&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})编译到ARM开发板里。

而需要自己写的，是硬件驱动，也是C。

所以说，无论你走哪条路线，前期都只用C，用不到C++。

那什么时候需要写[C++](https://www.zhihu.com/search?q=C%2B%2B&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})？

只有两种情况需要手写C++，其中每一种情况，又能分别细分成两种情况。所以也可以说有四种:

第一种情况，是做嵌入式UI，也就是QT，但这需要在完成源码编译，搞完驱动，[设备树](https://www.zhihu.com/search?q=设备树&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})，屏幕驱动之后才会涉及。另外呢，近几年有些新变化。目前[嵌入式方向](https://www.zhihu.com/search?q=嵌入式方向&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})有一个很火的[图形库](https://www.zhihu.com/search?q=图形库&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})，名叫LVGL，它有取代QT的趋势。最大的原因在于，LVGL是纯C图形库，不依赖C++。这样可以直接调用Linux本身的IO命令，因为Linux的IO接口也是纯C的。因此即便在UI方面，C++也可能会在未来几年逐渐被C取代。

第二种情况，跟UI同理，是对接一些应用库，如OpenCV等，也同样要编译完三大件、写好驱动之后才涉及。

如果你能在嵌入式工作中做到这两步的话，某种程度上来说，你已经算高手了。

第三种情况，就是在Windows桌面上搞QT、OpenCV，这些不需要你懂Linux，也不需要交差编译，什么UBoot、内核、根文件系统，一样也不用学。但这跟嵌入式也没半点关系。

第四种情况，跟第三种同理，那就是用各种派。[树莓派](https://www.zhihu.com/search?q=树莓派&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})、Nano派等玩QT、OpenCV。

解释起来可以很简单，但也可以很麻烦。

因为外行通常搞不清各种派和[Iinux开发板](https://www.zhihu.com/search?q=Iinux开发板&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})有什么区别。解释的太简单，评论区容易炸。所以只好多费点口舌。

如前面所说，使用Linux[开发板](https://www.zhihu.com/search?q=开发板&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})，你需要自己编译三大件，再自己编写硬件驱动。这样做的根本目的，其实是对Linux进行移植、裁剪、DIY。

嵌入式Linux开发，就是以Linux为基础，DIY出能适配所需设备的专用操作系统。

比如，我自己画了一块板子，名叫[XX1号](https://www.zhihu.com/search?q=XX1号&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})。然后可以通过配置三大件和编写驱动，diy出一套适配XX1号的操作系统，然后把它烧录到XX1号上面运行起来，这个过程叫“嵌入”。

而各种派，是把三大件和[驱动程序](https://www.zhihu.com/search?q=驱动程序&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})封装成了固件，傻瓜式一键烧录即可运行。其实就是把“嵌入”步骤整个跳过，官方直接给你提供了“已嵌入”的[操作系统](https://www.zhihu.com/search?q=操作系统&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})固件。

这也就导致板子的整体结构、板载设备、接口类型、接口数量不能有任何变动，不能手动编译三大件，也不能自己写驱动。

这之间的差别，正是普通用户与开发者之间的差别。

所以使用各种派，跟使用Windows一样，都是对操作系统进行常规使用，完全不涉及“嵌入”。

------

一般正常的单片机路线。。。。

是先复习物理电学，就是中学那些[欧姆定律](https://www.zhihu.com/search?q=欧姆定律&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})，串联并联。接着学数电和模电，然后学C，搞单片机。

期间熟悉各种电容、电阻、Mos管、二极管、[三极管](https://www.zhihu.com/search?q=三极管&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})的规格，并学习用它们搭建电路。

然后学习焊接元件，画板子，其实就是电工那一套。

至于常见的嵌入式Linux路线嘛。。。。

需要先买开发板，主流是I.MX6ull，芯片以前是[飞思卡尔](https://www.zhihu.com/search?q=飞思卡尔&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})(摩托罗拉)的，现在是[恩智浦](https://www.zhihu.com/search?q=恩智浦&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})的。

这款芯片按照今天的标准，性能可谓非常垃圾，价格也不算便宜，但依然只推荐这款芯片。

因为当你遇到问题，上网搜索别人的例子，会发现十之八九都是以I.MX6ull举例说明的。初学不选它，包你后悔。

在我初学的时候，买的迅为的板子，质量没的说。被我虐待六七年，外设换了好几茬，蓝板子虐成了黑板子，怎么看都像个破烂。但各项功能依旧正常，稳如老狗。不植入广告宣传一下，我都觉得自己没良心。[只是不知道](https://www.zhihu.com/search?q=只是不知道&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})迅为公司今天还活着没有。。。

现在最常见的是正点原子[阿尔法](https://www.zhihu.com/search?q=阿尔法&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})系列的板子。或者B站有个叫[韦东山](https://www.zhihu.com/search?q=韦东山&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})的UP主，自己打板子在[淘宝](https://www.zhihu.com/search?q=淘宝&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})卖，口碑也很好。

总之，无论谁家的板子，只要是基于[I.MX6ull](https://www.zhihu.com/search?q=I.MX6ull&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})的开发板就行，都能相互兼容，教程也通用。我六七年前买的时候，全套带液晶屏七百出头，今天差不多还是这价。不仅没降价，可能还涨了。

只要把这块板子玩明白，以后换成任何板子都能直接上手。

前期学习Linux基础，TFTP、NFS通信，搭建[交叉编译环境](https://www.zhihu.com/search?q=交叉编译环境&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})。

然后学习在开发板上编译三大件，学习编写驱动。Linux驱动粗分有三种，细分有五种。

分别是[字符设备](https://www.zhihu.com/search?q=字符设备&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})、[块设备](https://www.zhihu.com/search?q=块设备&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})、[网络设备](https://www.zhihu.com/search?q=网络设备&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})。

细分之下，又有杂项设备和[虚拟设备](https://www.zhihu.com/search?q=虚拟设备&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3227565506})。

每种都很重要，全要学，也全是用C。

把这些都学完之后，你才能在开发板上编程来控制硬件。

等把全部功能开发完成，设备调试一切正常之后，可以给控制功能加个UI界面。到这一步，才会用到C++。

总之吧，嵌入式有路线差异。有些路线，你永远用不到C++。

至于能用到C++的路线，当你能用到它的时候，你早已经是高手了。

如果你还不是嵌入式高手，却已经开始写C++了，说明你还是比较适合专心搞机械。

# 懒惰

作者：涛叔随笔
链接：https://www.zhihu.com/question/572947292/answer/3233922440
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



活了30多年，我终于明白，我们这一代人真的陷入了一个[陷阱](https://www.zhihu.com/search?q=陷阱&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})。

在外面努力工作，抛弃妻儿，四处奔波，甚至透支身体，只是为了赚两块钱，不求人，体面生活。

结果我赚了血汗钱，还了房贷，还了[车贷](https://www.zhihu.com/search?q=车贷&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})，去了医院，舍不得吃，舍不得喝，舍不得穿。我的生活仍然很紧张，我的生活充满了鸡毛。

就算以后有了孩子，他们长大后，又何尝不是走上了我们的老路。

这么循环，整天忙忙碌碌，精疲力尽。没时间考虑为什么？有了学区，在旁边的学校上学，能不能跨班？醒醒吧！社会已经是受益者了！

是时候让我们考虑一下了，我们拼命赚钱究竟是为了什么？

为养家糊口，还房贷，还车贷，把身体累垮了再去医院，治好了再继续干，好不了就死了！

我发现有些人就是愿意憋大招，[卧薪尝胆](https://www.zhihu.com/search?q=卧薪尝胆&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})，想着年轻时吃苦老了就享受快乐，你不觉得这句话很傻吗？

三年级努力考上高中就容易了，三年级再努力考上大学就容易了，工作时努力，[升职加薪](https://www.zhihu.com/search?q=升职加薪&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})就容易了！

刚开始买房买车压力很大，还房贷就容易了！孩子需要在家里为结婚买单。我们存钱几年，孩子赚的多，我们就放松了。

孙子出生的时候，我们帮忙照顾他们。孙子上幼儿园的时候，我很放松。现在我70岁了，我会帮助我的孩子。再过几年，我就放松上天堂了。

当你年轻的时候，你可以承受屈辱的负担。当你老了，你可以承受[荣华富贵](https://www.zhihu.com/search?q=荣华富贵&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})吗？你觉得老板每天给你画饼不够。你必须为自己画一个老年饼吗？

你们现在过的是多么不快乐才能让你们觉得[风烛残年](https://www.zhihu.com/search?q=风烛残年&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})时可以弥补？

无论你选择[朝九晚五](https://www.zhihu.com/search?q=朝九晚五&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})还是游荡天涯，我都不会传达所谓的不良[价值观](https://www.zhihu.com/search?q=价值观&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})，不要把希望和焦虑都放在未来。

老了以后也许会孤独，所以我现在要做些什么！老了以后也许会有荣华富贵，所以说我现在应该做些什么。

永远不要这样，你对未来所有的焦虑和希望都放在今天，你的过去都是假的！你们的未来也未必会到来。

你们只要摸摸自己的良心，问问自己，你们今天过得怎么样啊，到此为止，你们多想一想就是[愚蠢](https://www.zhihu.com/search?q=愚蠢&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})。

千万不要相信西方那一套做了很多好事的S之后就可以上天堂了。今天只要你活在这[24小时](https://www.zhihu.com/search?q=24小时&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})里，你现在就在天堂！

如果你不相信，你可以想象一下。

假如你这辈子[不谈恋爱](https://www.zhihu.com/search?q=不谈恋爱&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})，不结婚，不买房，不生孩子，那你真正遇到的困难是什么？

在中国，真正阻止你做你想做的事情的主要问题不是你没有钱。真正困难的是你害怕周围人对你的评价，就像学生担心考试不及格一样。如果你考试不及格，你就考不好。如果你考试不及格，下次再考是件大事。

实际上，她害怕的并非考试不及格，她害怕的是老师父母的失望和批评。

很多人害怕做自己想做的事情，因为他想做的事情很可能会让别人不满意。你可能[不想结婚](https://www.zhihu.com/search?q=不想结婚&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})生子，但别人会说不孝应该是最大的。你可能想去诗和远方，但别人会说你的父母还活着，你有什么资格适合远方？

你可能想换工作，换伴侣，做这件事，但你不敢。这些事情本身并不可怕。你害怕的是被别人认为不负责任，不孝顺。

你们害怕的事情多了，自然就活得累了。

[儒家文化](https://www.zhihu.com/search?q=儒家文化&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})是造成这一现象的主要原因。

为何中国人不能懒惰？

因为在儒家文化中，人不是为自己而活，而是为父母和家人而活，甚至可以说人是为了自己的社会评价而活。

因此，身处[儒家文化圈](https://www.zhihu.com/search?q=儒家文化圈&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})的中日韩人，家庭关系更加复杂和艰苦。

事实上，大多数人只要不在乎社会的评价，即使一个月赚几千块钱，日子也可以过得很舒服。

如今，社会越来越原子化，社会评价逐渐淡化。压力主要来自父母。父母仍然是[熟人社会](https://www.zhihu.com/search?q=熟人社会&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})。他们非常关心社会评价。

其实就拿不结婚生子来说，别人的评价其实没有杀伤力，也没关系，但是父母的一句话:为了你的事，我可以让你妥协，因为我担心整夜睡不着。

但是，我们来到这个世界，不应该是为了当牛做马还30年的房贷，繁衍后代。

相反，我们来看看花是怎么开的，水是怎么流的。太阳是怎么升起的，夕阳是什么时候落下的。我生活在这个世界上，只是想明白一些道理，遇到一些有趣的事情。生活是一个偶然，[我在其中](https://www.zhihu.com/search?q=我在其中&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})寻找因果。

在《明朝那些事》中有一句话

我写徐霞客的原因是想告诉你：所谓[千秋霸业](https://www.zhihu.com/search?q=千秋霸业&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})，万古流芳，与一件事相比，其实算不了什么。

这个问题就是用你喜欢的方式度过一生。

整个明朝，无论是朱元璋、朱棣、[朱由检](https://www.zhihu.com/search?q=朱由检&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})、张居正、王阳明等。，这些人都被时代所困。他们可能在政治上，也可能在思想上占据巅峰，在[漫长的人生](https://www.zhihu.com/search?q=漫长的人生&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})中，他们真的幸福吗？

最起码，徐霞客真的很开心。

在同朝别人执著于财富和名利的时候，徐霞客却坐在[黄山](https://www.zhihu.com/search?q=黄山&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})绝顶，听了一整天雪花融化的声音。

尽管如今我们都知道长江的来源是[可可西里羌塘](https://www.zhihu.com/search?q=可可西里羌塘&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A3233922440})的腹地，但是那时我们开始寻找是多么的毅力和勇气........

就写到这儿吧，絮絮叨叨也蛮多了。

# 毕业生

> [现在经济不好，互联网大量裁员，而学校又大批涌入计算机专业，预计2-3年后，相关待遇会不会下降？](https://www.zhihu.com/question/622943986/answer/3252504280)
>
> 作者：技术王
> 链接：https://www.zhihu.com/question/622943986/answer/3252504280
> 来源：知乎
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



**毕业生**

我面试毕业生，算法方面，数据结构没得说了，几大基本排序算法就没有不会默写的学生，我喜欢考一些冷门一点的归并排序，基本上没有人答不出来，至于算法复杂度你就别想了，他们可以在a4纸上跟你演算出来。红黑树以前是我最怕的，我毕业的时候连这个东西有什么用都不知道，现在的应届生你说旋转他就跟你旋转，你说插入他就可以跟你插入，回答起来非常丝滑。当然，我还喜欢问一些数学方面的问题，像什么默克尔，像什么卡塔兰，汉诺塔九连环这种就没得说了，有的同学作品就是直接演示了汉诺塔。甚至我引以为傲的人机博弈算法，也有很多人能跟我过两招。

网络方面，我现在都不敢问了，我问也只能问tcp相关的，问这个就是等着被吊打吧，他们可以跟你从一次握手聊到4次握手，你晕不晕？tcp方面的协议头，每个位他们都是非常清楚的，有次我问有个人，什么时候tcp会发送一个rst的位给客户端？结果我感觉是正中下怀了。我大学的时候还记得有个叫码分复用的非常经典，所以我又问了，结果都能回答上来，所以我感觉网络方面我真不是很擅长了。

数据库方面？不用想了，他们早就把Oracle数据库的方方面面都挖透了，估计是他们觉得这个数据库才是真数据库吧，什么段区块，实例崩溃具体细节，事物槽事物表回滚段， hint 等等，有个牛学生，简历上居然用sql 能写出傅里叶变换的程序，还好大学只有4年，否则的话真怕他干出什么事来。

当然，操作系统就不用多说了，他们动辄和你讨论unix系列的操作系统，网络操作系统，我差点都把这个概念忘掉了。内部命令有哪些，外部命令又怎么使用，进程标识，内存管理、MMU、TLB，slab、mmap，文件系统等等。注意，我说的这些都是我会的，我不会的我没问！

不过他们也有短板，java的很多东西不是很清晰，类加载器这些概念模糊，jvm估计是没经验，感觉他们都学不会，框架就知道个spring大部分只能砍到依赖注入和控制反转这个地步了，但是其实这些都不重要，也不影响我对他们的好评。

**你猜工资要多少？**或者也可以这么说吧，这样的优秀应届生能给他们多少？10k左右！比我那个时候多不了多少。

**5年经验**

5年经验当然这些没那么扎实了，我就问很多八股文了。

Java调优是真香，他们的很多项目可能就个位数的qps，扯起高并发高可用来头头是道，我这个经历了这么多高并发的都不一定懂他这么多优化经验，至于字节码，内存，多线程就不用多说了，估计是啃了不少书，在硬盘上玩了不少。jvm的调优参数，我估计是有个表，他们每天都会背诵这个表，jvm参数我记得大概有好几百个吧，其实我也没用过多少，我能数得出来的以及用过的，不超过20个，但是他们好像都是比较清楚的.

秒杀系统必问必会，几乎就没有谁裤裆里没有秒杀系统的。优化真是达到了极致，层层限流，都达到要在ng这一层，通过写lua脚本来限流了，说实话我真没遇到过这样的情况，但是这个操作确实没毛病，流量要尽可能在前端就限制掉，如果不在ng这一层做，无效的流量打到应用层，确实会给应用造成资源损耗，他们这种硬盘上的极致追求，我真担心他们会在四层复杂均衡器那里动脑筋做限流了。

框架？spring和设计模式是我最大的短板，说句真的，到现在我这个架构师都不是很清楚设计模式，那些设计模式到底用在哪了，也有可能这些年做监控方面的架构了，业务上的架构师还真不是很擅长。这些小朋友们对spring这个东西就没有不阅读过源码的，虽然互联网上的公开课，技术博客这些都很多，资料齐全，但是也要很努力才能学好，要把spring源码在面试官面前大致背诵一遍，也是颇为不容易的。

中间件就不用说了，一上来谈原理，消息推送是我见过最多的，个位数的QPS，也要用kafka集群了，具体项目是做点餐推送的，但是这两年这种点餐系统的公司都死了很多，我面试过一个最大的点餐系统开发者，大约有10w+的商户数量了，其实很不错了就已经，但是他们用的是rmq也能撑住，当然，我是技术面，他既然说是用kafka，那我肯定会问kafaka方面的问题了，不过他都回答上来了。redis就没的说了，很多小伙子都动手实现了简约版的redis，他们不熟悉C，就使用java实现了一版，简历上是这么写的，我没做过不太敢问，我一般是问redis的集群、哨兵、主从、过期机制、数据结构、队列等一些相对基础性的问题，大部分人都是对答如流的。有时候我也会把我裤裆里存了好几年的redis小技术拿来问问，比如HyperLogLog 这个数据结构的原理及其应用，能回答上来的一半左右吧，可能对于我来说是裤裆，对于别人来说根本不算事。工作5年的就不再说自己熟悉Oracle了，都是精通MySQL，SQL优化每个人聊起来都是一套一套的，我看着他们说的时候像吐糍粑一样，当时差点让我笑场。《高性能MySQL》里面的招数就不用多说了，我感觉他们真的达到了DBA的水平。

记得有一位同学，我印象特别深刻，也是小厂的朋友，技术是真扎实，他说他懂安全方面的问题，他说他为公司省了一笔钱，SSL证书是好几千一年的，他用RSA+DES算法，自己给公司设计了一套加密算法，公司还是使用HTTP，但是用他的这套加密别人也无法破解。听到这个我是真的差点笑场了，一个能招聘程序员的公司几千块的SSL证书都不舍得，再说你这个加密也加密不了请求头，怎么能叫加密了？当然，我不能戳穿了，因为我看到他的简历我是知道他们项目的状况的，我更关心的是他对技术的理解，很显然，他征服了我，RSA+DES这套组合还真是解决了密钥交换和性能双重问题，当然，如果有懂安全的朋友可以评论指点下我。

当然，上面说的都是很多小厂的同学，大厂的同学是不需要去做这些捏造的，技术的扎实性其实都差不太多，真正小厂和大厂的区别就是见识不一样而已。

**你猜工资要多少？**2个w左右，也可以这么理解，公司只能给2个w左右。

**10年经验**

10年经验的我面试的比较少，因为10年左右其实跟我的水平差不了太多了。不过也勉强面试过几个。

闭环、管理、效率、成本、打通、串联、聚合、下钻是他们吊在嘴巴的上的词汇了，他们开口闭口是行业情况，目前的技术的业内瓶颈怎么样，一说他们的日志中心建设，说能在二流的大厂排名多少，跟一流的大厂差距在哪些地方，真是感觉研究别人比研究自己还多。

10年经验左右的就不多少了，一来我面试的比较少，二来我自己也比这个水平高不了多少。

**你猜工资要了多少**？5个w，当然，也有可能公司只能给得起这个价吧。

如果是十多年前我刚毕业的时候，能达到这个水平的应届生，也能拿到10k左右了，但是十多年前10k，对比现在的10k，大家可以自行比对下，当然，5年和10年的都大部分也是这个价，十多年前就是这个价了，现在还是这个价，**你告诉我，相关待遇会不会下降？？**

# 电机学

>中国：[胡敏强](https://www.zhihu.com/search?q=胡敏强&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A2932148374})
>
>美国：查普曼，[乌曼](https://www.zhihu.com/search?q=乌曼&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A2932148374})（[两本书](https://www.zhihu.com/search?q=两本书&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A2932148374})）
>
>推荐看完以上三本[电机学](https://www.zhihu.com/search?q=电机学&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A2932148374})课本再看一遍[汤蕴璆](https://www.zhihu.com/search?q=汤蕴璆&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A2932148374})的电机学课本，如果这几本书都能掌握，推荐电机方向深造。
>
>查普曼 → 乌曼 → 汤。

