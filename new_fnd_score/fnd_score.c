//"100  "-> 유지하다가    깜빡"100 -5","99 -4","98 -3", "97 -3", "96 -2", "95 -1"깜빡       "95    "->유지
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "fnd.h"

#define MAX_FND_NUM			6
#define FND_DATA_BUFF_LEN	(MAX_FND_NUM + 2)
#define FND_DRIVER_NAME "/dev/perifnd"
#define BLINK_DELAY_MS 500
int mode = 0; // static display
int c_score = 100; //처음 점수는 만점
int testfail, number, counter;
char buffer[7];
char zero[7] = "      ";
int minuspoint=0;

//c_score변수는 100이고 minuspoint 변수에 5를 받았을때
int main() {

	fndDisp(c_score,0);
	while (testfail == 1) //실격일때, wasted
	{
		char ch[7] = "wasted";
		fndDisp_ch(ch);

	}
	while (minuspoint != 0) // minuspoint 변수에 0이 아닌 숫자가 들어온다릿
	{
		if (minuspoint == 5) //-5 포인트가 되었을때,
		{
			for (int i = 0; i < 6; i++) { //0~5까지 6번 돌아

				snprintf(buffer, sizeof(buffer), "%d -%d", c_score, minuspoint);
				fndDisp_ch(buffer);
				usleep(500000); // 0.5초 = 500000 마이크로초
				fndDisp_ch(zero);
				fndDisp(minuspoint, 0);
				usleep(500000); // 0.5초 = 500000 마이크로초
					minuspoint--;
					c_score--;
			}

		}
		else if (minuspoint == 7)
		{
			for (int i = 0; i < 7; i++) { //0~6까지 7번 돌아

				snprintf(buffer, sizeof(buffer), "%d -%d", c_score, minuspoint);
				fndDisp_ch(buffer); //(현재점수 -까일점수)
				usleep(500000); // 0.5초 = 500000 마이크로초
				fndDisp_ch(zero);
				fndDisp(minuspoint, 0); //다 꺼짐
				usleep(500000); // 0.5초 = 500000 마이크로초
					minuspoint--;
					c_score--;
			}
		}
		else if (minuspoint == 10)
		{
			for (int i = 0; i < 10; i++) { //0~9까지 10번 돌아

				snprintf(buffer, sizeof(buffer), "%d -%d", c_score, minuspoint);
				fndDisp_ch(buffer); //(현재점수 -까일점수)
				usleep(500000); // 0.5초 = 500000 마이크로초
				fndDisp_ch(zero);
				fndDisp(minuspoint, 0); //다 꺼짐
				usleep(500000); // 0.5초 = 500000 마이크로초
				minuspoint--;
				c_score--;
			}
		}

	}
}