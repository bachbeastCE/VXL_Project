#include "fsm_automatic.h"
void run_automatic(){
	switch(status1){
				case INIT:{
						ResetLight1();
						status1 = RED_LED_AUTO;
						count1 = time_red;
						break;
					}
				case RED_LED_AUTO:{
						RedLight1();
						if (count1 == 0){
							status1 = GREEN_LED_AUTO;
							count1 = time_green;
						}
						if (isButtonLongPressed(up_button)==1){
							HAL_GPIO_TogglePin(GPIOA, LED_PINK);
							status1 = RED_GREEN_MAN;
							status2 = RED_GREEN_MAN;
							count1 = 10*scale;
							count2 = 1;
						}
						break;
					}
				case YELLOW_LED_AUTO:{
						YellowLight1();
						if (count1==0){
							status1 = RED_LED_AUTO;
							count1 = time_red;
						}
						break;
					}
				case GREEN_LED_AUTO:{
						GreenLight1();
						if (count1==0)	{
							status1 = YELLOW_LED_AUTO;
							count1 = time_yellow;
						}
						break;
					}
				default:
						break;
			}

		switch(status2){
					case INIT:{
							ResetLight2();
							status2 = GREEN_LED_AUTO;
							count2 = time_green;
							break;
						}
					case RED_LED_AUTO:{
							RedLight2();
							if (count2==0){
								status2 = GREEN_LED_AUTO;
								count2 = time_green;
							}
							break;
						}
					case YELLOW_LED_AUTO:{
							YellowLight2();
							if (count2==0){
								status2 = RED_LED_AUTO;
								count2 = time_red;
							}
							break;
						}
					case GREEN_LED_AUTO:{
							GreenLight2();
							if (count2 == 0)	{
								status2 = YELLOW_LED_AUTO;
								count2 = time_yellow;
							}
							break;
						}
					default:
							break;
				}

		if((status1/10)==1 && count1>0 )count1--;
		if((status2/10)==1 && count2>0 )count2--;
		if((status1/10)==1 && count3>0 ){
			count3--;
			if(count3 ==0){
				count3 = scale;
				//LCD + UART HERE
		        char str[40];
		        sprintf(str, "Count1: %d - Count2: %d\n\r", count1/10,count2/10);
		        HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 100);
			}
		}
}

