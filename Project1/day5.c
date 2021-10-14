#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a = 0;
	while (1) {	//while문 내부에서 자체적으로 main 함수를 종료할 수 있게끔 하여 조건문은 항상 돌아가도록 함.
		printf("2부터 9사이 숫자를 입력해주세요(1을 누르면 프로그램이 종료됩니다):");
		scanf("%d", &a);
		if (a >= 2 && a <= 9) {
			for (int i = 1; i <= 9; i++) {
				printf("%d X %d = %d\n", a, i, a * i);
			}
		}
		else if (a == 1) {
			printf("프로그램이 종료됩니다.");
			return 0;
		}
		else {
			printf("예외 발생\n");
		}
	}
}