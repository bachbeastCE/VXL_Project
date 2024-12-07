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
//						if (isButtonPressed(modify_button)==1){
//							status1 = RED_GREEN_MAN;
//							status2 = RED_LED_SET;
//							count1 = 10;
//							count2 = 1;
//						}
//						if (isButtonPressed(mode_button)==1){
//							count3=1;
//							status1 = RED_LED_SET;
//							status2 = RED_LED_SET;
//							count1 = 2; //Mode
//							count2 = time_red; //Value
//							ResetLight1();
//							ResetLight2();
//						}
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
}

