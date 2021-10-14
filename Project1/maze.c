#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define ROW 21
#define COL 21
int saveWay[400] = { 0 };
int cnt = 0;

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
void drawMaze() {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
}
int findtwo(int row, int col) {
    if (col + 1 < 21 && maze[row][col + 1] == 2) {
        return 1;
    }
    else if (col - 1 >= 0 && maze[row][col - 1] == 2) {
        return 1;
    }
    else if (row < 21 && maze[row + 1][col] == 2) {
        return 1;
    }
    else if (row - 1 >= 0 && maze[row - 1][col] == 2) {
        return 1;
    }
    else {
        return 0;
    }
}

int impossible(int row, int col) {
    if (maze[row + 1][col] == 1 && maze[row - 1][col] == 1 && maze[row][col + 1] == 1 && maze[row][col - 1] == 1) {
        printf("막힘\n");
        return 1;
    }
    else {
        return 0;
    }
}


int find(int row, int col) {
    if (impossible(row, col)) {
        return 0;
    }
    if (findtwo(row, col)) {
        printf("%d %d\n", row, col);
        printf("탈출성공\n");
        return 0;
    }
    maze[row][col] = 1;
    printf("%d %d\n", row, col);
    if (col + 1 < 21 && maze[row][col + 1] != 1 && maze[row][col + 1] == 0) {
        find(row, col + 1);
    }
    if (col - 1 >= 0 && maze[row][col - 1] != 1 && maze[row][col - 1] == 0) {
        find(row, col + 1);
    }
    if (row < 21 && maze[row + 1][col] != 1 && maze[row + 1][col] == 0) {
        find(row + 1, col);
    }
    if (row - 1 >= 0 && maze[row - 1][col] != 1 && maze[row - 1][col] == 0) {
        find(row - 1,col);
    }
    
}
int main() {
    
    drawMaze();
    int startRow, startCol;
    printf("출발점의 y,x 좌표를 입력하세요: ");
    scanf("%d %d", &startRow, &startCol);
    find(startRow, startCol);
   
}