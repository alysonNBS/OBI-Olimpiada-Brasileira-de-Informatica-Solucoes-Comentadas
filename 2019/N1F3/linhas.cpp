#include <iostream>
#include <queue>
#include <list>
#include <utility>
#include <algorithm>

#define MAXL 510
#define MAXT 510
#define mk(a, b) make_pair(a, b)

using namespace std;

typedef pair<int,int> pii;

list<int> linhas[MAXL];
list<int> terminais[MAXT];
int T, L, O, D;

int bfs() {
    bool visitados[MAXT];
    queue< pair<int, int> > fila;
    pair<int, int> atual;

    fill(visitados, visitados+MAXT, false);
    atual = mk(O, 0);

    while(atual.first != D) {
        int u = atual.first;
        int v = atual.second;
        visitados[u] = true;

        for(list<int>::iterator it_t = terminais[u].begin(); it_t != terminais[u].end(); it_t++)
            for(list<int>::iterator it_l = linhas[*it_t].begin(); it_l != linhas[*it_t].end(); it_l++)
                if(!visitados[*it_l])
                    fila.push(mk(*it_l, v+1));
        
        atual = fila.front();
        fila.pop();
    }

    return atual.second;
}

int main() {
    scanf("%d%d%d%d", &T, &L, &O, &D);

    for(int i=1; i<=L; i++) {
        int C;
        scanf("%d", &C);

        while(C--) {
            int t;
            scanf("%d", &t);

            linhas[i].push_back(t);
            terminais[t].push_back(i);
        }
    }

    cout << bfs() << endl;

    return 0;
}