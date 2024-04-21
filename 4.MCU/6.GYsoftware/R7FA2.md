# RA2

## 概述

![](imgR7FA2/RA2.png)

![](imgR7FA2/R7FA2E1.png)

R7FA2E1A92DFM：

- flash：128KB。
- -40°C~86°C。
- Consumer applications。
- 64Pin——0.5mm。

## 开发工具与烧录

RA系列开发与调试工具：

- e2 stdio：可用图形化配置工具，生成的代码也简洁高效。（选择快速安装即可，默认）
- Keil。

RA系列库：FSP库（灵活配置软件包）。

实时操作系统：支持FreeRTOS。

烧录：J-Link或串口烧录。



## 存储

存储：

- RAM：程序运行内存。
- Flash：保存程序。
- 寄存器：保存芯片功能状态，配置和操作芯片功能。

存储器映射：给存储器分配地址的过程，通常是产家规定好的。

存储器重映射：重复的映射，即给存储空间再分配一个地址。

寄存器：有特定的功能的内存单元，该内存单元内的每一位通常都有相对应的控制功能。

寄存器映射：给已分配好地址(通过存储器映射实现)的有特定功能的内存单元取别名的过程。

>寄存器映射是在存储器映射的基础上进行的。
>
>以STM32为例，操作硬件本质上就是操作寄存器。**在存储器片上外设区域，四字节为一个单元，每个单元对应不同的功能。**当我们控制这些单元时就可以驱动外设工作，我们可以找到每个单元的起始地址，然后通过C 语言指针的操作方式来访问这些单元。但若每次都是通过这种方式访问地址，不好记忆且易出错。**这时我们可以根据每个单元功能的不同，以功能为名给这个内存单元取一个别名，这个别名实质上就是寄存器名字。给已分配好地址(通过存储器映射实现)的有特定功能的内存单元取别名的过程就叫寄存器映射。**
>
>原文链接：https://blog.csdn.net/FRIGIDWINTER/article/details/106826511

32位CPU：

>32 位和 64 位中的“位”，也叫字长，是 CPU 通用寄存器的数据宽度，是数据传递和处理的基本单位。字长是 CPU 的主要技术指标之一，指的是 CPU 一次能并行处理的二进制位数。32位平台中，CPU内部寄存器和寻址总线是32位，CPU一次最多只能同时处理32bit的数据。

为什么能通过地址去访问存储单元？

>地址，表示了地址总线上各线路高低电平状态，可以理解为通过地址总线输入一些数据经译码器解析后来寻址到具体的存储单元，然后通过控制器来控制对这些存储单元进行读或写操作，数据经数据总线写入或读出。
>
>**总结：地址总线控制访问哪个存储单元，控制器控制写入或读出，数据总线是数据进出的通道。**（通常一个地址对应一个存储单元，一个存储单元即1byte=8bit。但有的硬件会做特殊处理，如STM32会把一片内存映射成位带，一个地址对应1位。）
>
>32位平台下是32位地址（$2^{32个}地址$），$2^{32}=4*2^{30}=4GB$，即最大可支持4GB的线性地址空间。

瑞萨RA2单片机中，一个地址对应1bit，存储器片上外设区域，四字节为一个内存单元。

```c
/* 指向存储int类型数据的内存区域的指针 */
/* 指向的内存区域为从 0x40040020~0x4004003F */
*(uint32_t*)(0x40040000+0x0020*1) |= 0x00000101;   //  通过绝对地址访问寄存器
```



## 寄存器开发

通过指针直接访问寄存器进行功能开发。

寄存器到库的转变：

- 通过枚举封装地址常量、端口、引脚、功能配置参数、常用常量等。
- 通过结构体封装外设的所有初始化参数。
- 通过初始化函数来封装对外设初始化的具体操作。
- 通过函数来封装对外设寄存器的数据的读取操作。



## FSP库

### 介绍

>**瑞萨电子灵活配置软件包** (FSP) 是用于嵌入式系统设计的高质量增强型软件包，支持瑞萨电子 RA 产品家族 Arm 微控制器，提供用户友好的界面且可灵活扩展，确保从入门级到高性能的整个 RA 微控制器的软件兼容性。
>
>FSP 全称为 “Flexible Software Package”，中文译为“灵活配置软件包”。FSP 旨在以较低的内存占用量提供快速高效的驱动程序和协议栈。 FSP 集成了中间件协议栈、独立于 RTOS 的硬件抽象层（HAL）驱动程序， 以及最基础的板级支持包（BSP）驱动程序。FSP 还支持 FreeRTOS™ 实时操作系统（RTOS）。
>
>FSP基于C99编写。

### 架构

![](imgR7FA2/fsp_arch1.png)

![](imgR7FA2/fsp_struct.png)

### 开发

1. 创建工程。
2. 通过图形化界面配置引脚。
3. 通过开发帮助找到相关FSP库函数。
4. src里面建立模块文件夹，创建模块的头文件和源文件，结合FSP库函数编写功能代码。
5. `hal_entry()`函数里调用功能函数以实现各种功能。



# 工程创建

File → New → 瑞萨C/C++项目 → Renesas RA → Renesas RA C/C++ Project → 项目名称 → 选择芯片型号（RA2E1A92DFM） → Executable → Bare Metal - Minimal  → Finish。



# 启动文件

启动文件是系统上电复位后执行的第一个程序。主要做了以下工作：

1. 初始化堆栈。
2. 使能FPU（float-point unit，即浮点单元）。
3. 定位中断向量表。
4. 配置系统时钟。
5. 启用CORTEX-M33栈监视器。
6. 初始化C语言运行环境。
7. 初始化变量SystemCoreClock，这个变量存放的是处理器时钟的频率。
8. 初始化用于触发NVIC中断的ELC（Event Link Controller）事件。
9. **初始化IO口。**

瑞萨RA单片机，启动文件是C编写的，名称为`startup.c`，进行的操作主要如以下：

- 复位程序。
- 栈区初始化。
- 堆区初始化。
- 中断向量表初始化。



## SystemInit()







# CGC

RA2E1的时钟：

- 主时钟（MOSC）：1~20MHz。（需外接晶体振荡器）
- 副时钟（SOSC）：32.768kHz。（需外接晶体振荡器，通常为RTC准备的）
- 高速片上振荡器（HOCO）：24、32、48、64MHz。
- 中速片上振荡器（MOCO）：8MHz。
- 低俗片上振荡器（LOCO）：32.768kHz。（RTC）
- HOCO、MOCO、LOCO时钟微调功能：
- IWTD专用片上振荡器：15kHz。
- 支持时钟信号输出。

CGC：clock generation circuit，即时钟生成电路，通常称之为“时钟控制电路”。

# IO

寄存器：

`r_ioport.h`、`r_ioport.c`：

```c
fsp_err_t R_IOPORT_Open(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);
fsp_err_t R_IOPORT_Close(ioport_ctrl_t * const p_ctrl);
fsp_err_t R_IOPORT_PinsCfg(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);
fsp_err_t R_IOPORT_PinCfg(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, uint32_t cfg);
fsp_err_t R_IOPORT_PinEventInputRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_event);
fsp_err_t R_IOPORT_PinEventOutputWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t pin_value);
fsp_err_t R_IOPORT_PinRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_value);
fsp_err_t R_IOPORT_PinWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t level);
fsp_err_t R_IOPORT_PortDirectionSet(ioport_ctrl_t * const p_ctrl,
                                    bsp_io_port_t         port,
                                    ioport_size_t         direction_values,
                                    ioport_size_t         mask);
fsp_err_t R_IOPORT_PortEventInputRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * event_data);
fsp_err_t R_IOPORT_PortEventOutputWrite(ioport_ctrl_t * const p_ctrl,
                                        bsp_io_port_t         port,
                                        ioport_size_t         event_data,
                                        ioport_size_t         mask_value);
fsp_err_t R_IOPORT_PortRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_port_value);
fsp_err_t R_IOPORT_PortWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t value, ioport_size_t mask);
```



# ICU

ICU（Interrupt Controller Unit），中断控制单元。

## NVIC









## 中断向量表





# 系统滴答定时器











# SCI













# SPI









# DTC







# I2C









# 低功耗模式

















