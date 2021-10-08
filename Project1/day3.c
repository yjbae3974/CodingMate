#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>	//strtok 함수를 불러오기 위한 헤더
#include<stdlib.h>	//atoi 함수를 불러오기 위한 헤더
//공백으로 구분된 문자열 형태의 두 숫자를 입력받고, n을 입력받아 두 숫자 사이에 존재하는 n의
//배수를 구해보시오.
//조건1: 숫자 두개는 공백(스페이스 바)로 구분되어 입력됩니다.
//조건2: 숫자 두개는 문자열 형태로 입력됩니다.
//조건3: 입력된 숫자를 포함하여 배수를 출력해보시오.

int findMin(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}

int findMax(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	char s[20];		//공백을 포함한 문자열을 받기 위한 변수. 공간은 임의로 20으로 설정함.
	char* s1 = NULL;
	char* s2 = NULL;
	char* tmp = NULL;
	int a, b;
	int times;
	int init;
	printf("숫자 두 개를 입력해주세요(ex. '3 5'):");
	scanf("%[^\n]s", s);	//이로 인해 공백을 포함한 문자열을 입력받음.
	s1 = strtok(s, " ");	//공백을 null문자로 치환하여 문자열의 끝으로 인식하도록 함. 이때 s도 바뀜.
	s2 = strtok(NULL, " ");
	a = atoi(s1);
	b = atoi(s2);
	printf("배수를 알고 싶은 숫자를 입력해주세요:");
	scanf("%d", &times);
	int min = findMin(a, b);
	int max = findMax(a, b);
	for (int i = min; i <= max; i++) {
		if (i % times == 0) {
			printf("%d ", i);
		}
	}
}