#include "stm32f10x.h"
 
 
static void LED_GPIO_Init(void);
static void delay(int n);
 
int main(void)
{
    LED_GPIO_Init();
    while(1){
        GPIO_SetBits(GPIOC,GPIO_Pin_13);
        delay(100);
        GPIO_ResetBits(GPIOC,GPIO_Pin_13);
        delay(100);
    }

}
 
 
static void LED_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_13;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStruct);
}
 
 
static void delay(int n)
{
 
    int i;
   
    while(n--){
      for(i = 0;i<0xFFFF;i++);
    }
}