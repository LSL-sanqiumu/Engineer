#include "stm32f10x.h"                  // Device header

#include "OLED.h"
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

// 静态内存中的初始化函数,初始化GPIO口
static void LED_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

static TaskHandle_t AppTaskCreate_Handle;
static TaskHandle_t LED_Task_Handle;

/* 空闲任务任务堆栈 */  
static StackType_t Idle_Task_Stack[configMINIMAL_STACK_SIZE];
/* 定时器任务堆栈 */ 
static StackType_t Timer_Task_Stack[configTIMER_TASK_STACK_DEPTH];
/* 空闲任务控制块 */
static StaticTask_t Idle_Task_TCB;
/* 定时器任务控制块 */
static StaticTask_t Timer_Task_TCB; 

/* AppTaskCreate 任务任务堆栈 */
static StackType_t AppTaskCreate_Stack[128];
/* LED 任务堆栈 */
static StackType_t LED_Task_Stack[128];
/* AppTaskCreate 任务控制块 */
static StaticTask_t AppTaskCreate_TCB;
/* LED 任务控制块 */
static StaticTask_t LED_Task_TCB;

static void LED_Task(void* parameter);
static void AppTaskCreate(void);
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, 
StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize);
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, 
StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize);

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4	
    
	OLED_Init();
    LED_Init();
	OLED_ShowString(1,1,"FreeRTOSv9.0.0s");
	/* 静态创建任务 start */
    AppTaskCreate_Handle= xTaskCreateStatic((TaskFunction_t)AppTaskCreate,
    (const char*)"AppTaskCreate",(uint32_t)128,(void*)NULL,(UBaseType_t)3,
    (StackType_t*)AppTaskCreate_Stack,
    (StaticTask_t*)&AppTaskCreate_TCB);
    if (NULL != AppTaskCreate_Handle)
    vTaskStartScheduler();
    /* 静态创建任务 end */
	while(1);

}
// 定义任务函数
static void LED_Task(void* parameter)
{
    while(1)
    {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        vTaskDelay(500);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		vTaskDelay(500);
    }
}
/* 用于创建任务 */
static void AppTaskCreate(void)
{
    taskENTER_CRITICAL(); //进入临界区
    /* 创建 LED_Task 任务 */
    LED_Task_Handle = xTaskCreateStatic((TaskFunction_t)LED_Task, //任务函数
    (const char*)"LED_Task",//任务名称
    (uint32_t)128, //任务堆栈大小
    (void* )NULL, //传递给任务函数的参数
    (UBaseType_t)4, //任务优先级
    (StackType_t*)LED_Task_Stack,//任务堆栈
    (StaticTask_t*)&LED_Task_TCB);//任务控制块
    if (NULL != LED_Task_Handle) /* 创建成功 */
        OLED_ShowString(2,1,"success");
    else
        OLED_ShowString(2,1,"fail");
    
    vTaskDelete(AppTaskCreate_Handle); //删除 AppTaskCreate 任务
    
    taskEXIT_CRITICAL(); //退出临界区
}
/* 空闲任务堆栈函数实现 */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, 
StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize) 
{ 
    *ppxIdleTaskTCBBuffer = &Idle_Task_TCB;           /* 任务控制块内存 */ 
    *ppxIdleTaskStackBuffer = Idle_Task_Stack;        /* 任务堆栈内存 */ 
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE; /* 任务堆栈大小 */ 
}
// 定时器任务堆栈函数实现
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, 
StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize) 
{ 
    *ppxTimerTaskTCBBuffer=&Timer_Task_TCB;             /* 任务控制块内存 */ 
    *ppxTimerTaskStackBuffer=Timer_Task_Stack;          /* 任务堆栈内存 */ 
    *pulTimerTaskStackSize=configTIMER_TASK_STACK_DEPTH;/* 任务堆栈大小 */ 
}
 


