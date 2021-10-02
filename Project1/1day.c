#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void swap(int *a,int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int a, b;
	printf("숫자를 입력해주세요: ");
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d", a, b);
}