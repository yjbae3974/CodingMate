#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

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
	//github commit 실험용
	int a, b;
	int times;
	int init;
	printf("숫자 두 개를 입력해주세요(ex. '3 5'):");
	scanf("%c %c", &a, &b);
	printf("배수를 알고 싶은 숫자를 입력해주세요:");
	scanf("%d", &times);
	int min = findMin(a, b);
	int max = findMax(a, b);
	//for (int i = 0;;i++) {
	//	if (((min + i) % times) == 0) {
	//		init = min + i;
	//		break;
	//	}
	//	else {
	//		continue;
	//	}
	//}
	//for (int i = init; i <= max; i += times) {
	//	printf("%d ", i);
	//}
	for (int i = min; i <= max; i++) {
		if (i % times == 0) {
			printf("%d ", i);
		}
	}
}