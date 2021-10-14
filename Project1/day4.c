#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ROW 21
#define COL 21

int y;
int x;
int step;
int success;

struct node {
    int y, x;
    struct node* next;
};
struct node* last;//전역변수 last지정->stack에서 top을 의미함.

int maze[ROW][COL];

void mazescript();
void Push();
void Pop();
void findroute(X, Y);

int maze[ROW][COL] =
{
         {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
         {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
         {1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1},
         {1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1},
         {1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1},
         {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1},
         {1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1},
         {1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1},
         {1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1},
         {1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1},
         {1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1},
         {1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1},
         {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1},
         {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1},
         {1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
         {1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
         {1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1},
         {1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1},
         {1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
         {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,2},
         {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void mazescript() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (maze[i][j] == 10) {
                printf("%d", 0);
            }
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}//미로 출력 먼저

void Push() {
    struct node* next_node;
    next_node = malloc(sizeof(struct node));
    if (next_node != NULL) {
        next_node->y = y;
        next_node->x = x;
        next_node->next = last;
        last = next_node;
    }
}//미로 해답 찾을 때 필요한 함수 중 하나로 stack에 insert하는 함수로 push에 해당

void Pop() {
    int y, x;
    struct node* cell;
    cell = last->next;
    y = last->y;
    x = last->x;
    maze[y][x] = 10;
    free(last);
    last = cell;

}//미로 해답 찾을 때 필요한 함수 중 하나로 stack에 delete하는 함수로 pop에 해당

void findroute(int Y, int X) {
    if (maze[Y - 1][X - 1] == 1) {
        printf("시작점을 다시 설정하시오.\n");
    }
    else if (maze[Y - 1][X - 1] == 0) {
        Push();
        x = X - 1;
        y = Y - 1;
        while (last->next != NULL || (last->x == 0 && last->y == 0)) {
            if (last->x != 0 || last->y != 0) {
                y = last->y;
                x = last->x;
            }
            
            if (maze[y + 1][x] == 0) {
                Push();
                y++;
                maze[y + 1][x] = 3;
                step = 1;
                mazescript();
            }
            else if (maze[y - 1][x] == 0) {
                Push();
                y--;
                maze[y - 1][x] = 3;
                step = 1;
                mazescript();
            }

            else if (maze[y][x + 1] == 0) {
                Push();
                x++;
                maze[y][x + 1] = 3;
                step = 1;
                mazescript();
            }
            else if (maze[y][x - 1] == 0) {
                Push();
                x--;
                maze[y][x - 1] = 3;
                step = 1;
                mazescript();
            }
            else if (maze[y + 1][x] == 2 || maze[y - 1][x] == 2 || maze[y][x + 1] == 2 || maze[y][x - 1] == 2) {
                mazescript();
                printf("미로를 탈출했습니다!\n");
                success = 1;
                break;
            }
            if (step != 1) {
                Pop();
            }
        }
    }
}//미로 해답 찾는 함수 

int main() {
    int Y, X;
    mazescript();
    printf("시작점 y좌표: ");
    scanf("%d", &Y);
    printf("시작점 x좌표: ");
    scanf("%d", &X);
    findroute(Y, X);
    if (success != 1) {
        printf("길이 없습니다.\n");
    }
    return 0;
}//위의 모든 함수를 실시하는 main함수로 미로의 해답을 찾는 findroute함수를 실행 수 성공시 해답과 출력 완료 신호를, 실패시 실패를 출력함.