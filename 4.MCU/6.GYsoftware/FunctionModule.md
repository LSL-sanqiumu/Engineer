# 裸机程序架构

状态机＋时间片前后台：

- 状态机：任务状态分解。
- 前后台：主轮询和定时器中断。（时间片前后台系统）

## 时间片

TMT和MultiTimer。

1. 硬件定时器提供时间基准：tick_1ms、tick_10ms、tick_100ms。
2. 定时中断中对时间进行计数：如果定时中断为1ms进入一次，那么计数到10就表示时间轴上的10ms处。
3. 对时间的不同的计数值对应不同的任务，当计数值到达后，就允许执行相应任务，并且将当前技术值归0。（相当于一个状态标志一样，例如时间轴上10ms这个点到了，然后置个标志位，通知相应任务可以去执行了，只不过要注意一个时间片内必须执行完任务，或者加入状态机进行更细致的控制。）

```c
static unsigned char flag_1ms;
static unsigned char flag_10ms;
static unsigned char flag_100ms;
static unsigned char flag_1000ms;
// 时间片：1ms
void timer_irq() //1ms中断中调用
{
	static unsigned char tick_1ms;
	static unsigned char tick_10ms;
	static unsigned char tick_100ms;
	tick_1ms++;
	if(tick_1ms >= 10)
	{
		tick_1ms = 0;
		flag_10ms = 1;
		tick_10ms++;
		if(tick_10ms >= 10)
		{
			tick_10ms = 0;
			flag_100ms = 1;
			tick_100ms++;
			if(tick_100ms >= 10)
			{
				tick_100ms = 0;
				flag_1000ms = 1;
			}
		}
	}
}

void timer_loop()// while(1)大循环中调用
{
	if(flag_1ms == 1)
	{
		flag_1ms = 0;
		// 1ms时间片程序
	}
	if(flag_10ms == 1)
	{
		flag_10ms = 0;
		// 10ms时间片程序
	}
	if(flag_100ms == 1)
	{
		flag_100ms = 0;
		// 100ms时间片程序
	}
	if(flag_1000ms == 1)
	{
		flag_1000ms = 0;
		// 1000ms时间片程序
	}
}
```





## 状态机

状态机四要素：状态、状态转移、转移条件、动作。

从大到小，大任务包含小任务，大状态机包含小状态机。





# 实时操作系统













# 超低功耗方案

就一个思路，工作时、休眠时电流要尽可能地小。

1. 不影响使用体验的情况下，外接模块能关则关。
2. 软件，尽量使用中断驱动，去唤醒主控。
3. 合适的主频，不影响实时性的情况下，可以关掉一些时钟、调低主频。
4. 主控的低功耗支持——睡眠休眠等。







# 软件框架











# Module

## 面向对象





## 触摸&背光

硬件：

- 触摸芯片GTX314L。
- 背光 —— 高亮LED。

>这份文档是针对使用GTX314L,GTX312L芯片做智能锁产品的时候的设计建议和注意事项，根据项目形态不同会略有差异，可以根据客户实际情况进行调整。
>
>硬件设计注意事项：
>
>1）VDD供电要稳定，电池通过LDO后单独拉线供电,建议不要和主控和其他芯片串在一起供电。
>
>2）RIN 脚的电容挂10PF左右，智能锁上现有客户主要都是挂6.8PF和10PF为主。
>
>3）芯片VDD电压和外围上拉的VDD要一致，不一致的时候和请单独咨询。
>
>4）从芯片的SIN脚到按键焊盘的走线尽量短，SIN线和SIN线之间的间距越大越好，平行走线数量越少越好。
>
>5）SIN线上的电阻靠近芯片，也可以根据版型情况去掉这个电阻。
>
>6）SIN和RIN线的旁边和底层不要有地，旁边的地和底层的地要和SIN线的距离保持 0.5mm以上，越大越好，若是无法保证0.5mm以上间距的时候也可以缩短，请具体咨询技术支持人员。
>
>7）SIN线和天线的间距越大越好，SIN线和天线不管是在同一层或者不同层，平行走的距离越短越好，SIN线和天线在不同层之间可以交叉走线,SIN线和天线走线尽量不要重叠，稍微重叠一点没关系,但不要完全重叠。
>
>8）音频线不要走芯片下面,晶振尽量不要放在芯片和按键焊盘背面。

电容式触摸按键原理：

- 金属板与地之间有一个杂散电容，人也相当于一个电容，当人手指按到金属板时，金属板对地总电容就为杂散电容加上人体等效电容。电容分压，按按键后电压值会变低，根据这个状态变化，再利用ADC来检测出高低压，这样就能知道是否触摸。
- （注：电容触摸原理就两种，一种是检测交流信号的幅值，另一种是检测交流信号的频率。）

GTX314的使用：

- I2C通讯。



触摸按键使用面向对象来写：

- 结构体：struct TouchKey。
- 属性：从机地址、设备ID号。
- 方法：I2C方法——指定地址写、指定地址读，读取按键状态。
- [BS814A触摸芯片用法，IIC(I2C)使用讲解以及实例代码基于C语言-CSDN博客](https://blog.csdn.net/weixin_47869185/article/details/121377166)
- [C语言，在定时器中断模式中，单个按键 连续按下两次（开关灯） 和长时间按下（开关灯）功能_再次按下用c语言怎么表达-CSDN博客](https://blog.csdn.net/weixin_47869185/article/details/117412440?spm=1001.2014.3001.5502)



背光灯使用宏与FSP库方法来写。

https://blog.csdn.net/qq_43499622/article/details/97164881





https://www.cnblogs.com/debugdabiaoge/p/15772780.html



# 瑞萨电容触摸按键



