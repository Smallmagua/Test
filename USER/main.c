#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
 
/************************************************
 ALIENTEK��ӢSTM32������ʵ��4
 ���� ʵ��   
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
void GPIO_LED(void);
 int main(void)
 {		
 	u16 t;  
	u16 len;	

	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	 
 	printf("����ͣ��λ\r\n");
 	while(1)
	{
		if(USART_RX_BUF[0] == '1')
			{
				printf("OK\r\n");
				GPIO_ResetBits(GPIOB,GPIO_Pin_13);
			}
		else if(USART_RX_BUF[0] == '2')
		{ 
			GPIO_SetBits(GPIOB,GPIO_Pin_13);
		}			
	}	
 }
 
 void GPIO_LED(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB , ENABLE); 						 
//=============================================================================
//LED -> PB13
//=============================================================================			 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_ResetBits(GPIOB, GPIO_Pin_13);
	GPIO_ResetBits(GPIOB, GPIO_Pin_15);
}

