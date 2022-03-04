#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // Making this a global array this time
int a[7][7] = {                         // Making this a global graph this time
    // 0  1  2  3  4  5  6
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i){
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j]== 1 && !visited[j])
        {
            DFS(j);
        }
        
    }
    
}

int main()
{
    // DFS IMPLEMENTATION
    DFS(6);
    return 0;
}