#include "fsm_setting.h"

int tmp_red=0;
int tmp_yellow=0;
int tmp_green=0;

void run_setting(){
	if ((status1/10)!=3){
		if(isButtonLongPressed(set_button)){
			count3=1*scale;
			status1 = RED_LED_SET;
			status2 = RED_LED_SET;
			count1 = 2; //Mode
			count2 = time_red; //Value
			ResetLight1();
			ResetLight2();
		}
	}
	switch (status1){
	case RED_LED_SET:{
		if(count3==0){
			count3=1*scale;
			HAL_GPIO_TogglePin(GPIOA, LED_RED_1);
			HAL_GPIO_TogglePin(GPIOA, LED_RED_2);
		}
		if(isButtonLongPressed(set_button)==1){
			status1 = YELLOW_LED_SET;
			count1 = 3;
			count2 = time_yellow;
			ResetLight1();
			ResetLight2();
		}
		if(isButtonPressed(up_button)==1){
			count2++;
			if(count2 > 99)count2 =1;
		}
		if(isButtonPressed(set_button)==1){
			tmp_red = count2;
		}
		break;
	}
	case YELLOW_LED_SET:{
		if(count3==0){
			count3=1*scale;
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_1);
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_2);
		}
		if(isButtonLongPressed(set_button)==1){
			status1 = GREEN_LED_SET;
			count1 = 4;
			count2 = time_green;
			ResetLight1();
			ResetLight2();
		}
		if(isButtonPressed(up_button)==1){
			count2++;
			if(count2 > 99)count2 =1;
		}
		if(isButtonPressed(set_button)==1){
			tmp_yellow = count2;
		}
		break;
	}
	case GREEN_LED_SET:{
		if(count3==0){
			count3=1*scale;
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN_1);
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN_2);
		}
		if(isButtonLongPressed(set_button)==1){
			if(tmp_red == tmp_green + tmp_yellow){
				time_red=tmp_red;
				time_yellow=tmp_yellow;
				time_green=tmp_green;
			}
			status1 = INIT;
			status2 = INIT;
			count1 = 0;
			count2 = 0;
		}
		if(isButtonPressed(up_button)==1 ){
			count2++;
			if(count2 > 99)count2 =1;
		}
		if(isButtonPressed(set_button)==1){
			tmp_green = count2;
		}
		break;
	}
	default:
			break;
	}
	if((status1/10)==3 && count3>0)count3--;

}
