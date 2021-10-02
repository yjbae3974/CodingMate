#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
//반복문과 조건문을 활용하여 2021년 3월의 달력을 출력해보세요
//조건1: 3월의 마지막 날은 31일이며, 3월 1일은 월요일입니다. 조건2: 달력은 일요일부터 시작되며 날짜위에
//요일 표시를 출력해야 합니다.

int BLUE = 9;
int RED = 12;
int WHITE = 15;

void setColor(int color) {	//글씨 색상 변경함수
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



int main() {
	//각 칸마다 총 4칸을 차지한다고 가정하고 작성하겠습니다.
	printf("\t\t\t\t<3월 달력>\n\n");
	setColor(RED);
	printf("\t일   ");
	setColor(WHITE);	//이런 방식으로 앞으로 콘솔창에서 사용할 색상을 지정!

	printf("월   화   수   목   금   ");		//띄어쓰기 3칸, 총 4칸차지
	setColor(BLUE);
	printf("토\n");
	setColor(WHITE);
	for (int i = 0; i < 32; i++) {
		if (i == 0) {
			printf("\t     ");
			continue;
		}
		else if (i % 7 == 0) {	//일요일일 때
			setColor(RED);
			printf("\t%-5d", i);	//한글은 총 2칸 차지하므로 출력할때는 총 5칸을 차지하도록 함.
			setColor(WHITE);
		}
		else if (i % 7 == 6) {	//토요일일 때
			setColor(BLUE);
			printf("%-5d\n", i);
			setColor(WHITE);
		}
		else {					//평일일 때
			printf("%-5d", i);
		}
	}
}