#include <stdio.h>
#include <stdbool.h>

#define MAXN 1010
#define MAXM 1010

#define existe(x, y) ( 0 <= x && x < N && 0 <= y && y <= M )

int grid[MAXN][MAXM];
bool visitado[MAXN][MAXM];
int N, M;

void dfs(int x, int y) {
    int d[][2] = { {1,0},
                   {-1,0},
                   {0,1},
                   {0,-1} };
    
    visitado[x][y] = true;

    for(int i=0; i<4; i++)
        if(existe(x+d[i][0], y+d[i][1]) && !visitado[x+d[i][0]][y+d[i][1]] && 
            grid[x+d[i][0]][y+d[i][1]])
            dfs(x+d[i][0], y+d[i][1]);
}

int main() {
    int manchas = 0;
    scanf("%d%d", &N, &M);

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", &grid[i][j]);

    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(!visitado[i][j] && grid[i][j])
                manchas++,
                dfs(i, j);
    
    printf("%d\n", manchas);

    return 0;
}