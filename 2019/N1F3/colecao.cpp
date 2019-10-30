#include <iostream>
#include <list>
#include <algorithm>

#define MAXN 100100

using namespace std;

int main() {
    int N, M;
    bool upas[MAXN];
    list<int> n_combina[MAXN];

    cin >> N >> M;
    fill(upas, upas+MAXN, true);

    while(M--) {
        int U, V;
        cin >> U >> V;

        n_combina[U].push_back(V);
        n_combina[V].push_back(U);
    }

    for(int i=N; i>=1; i--)
        if(upas[i]) 
            for(list<int>::iterator it = n_combina[i].begin(); it != n_combina[i].end(); it++)
                upas[*it] = false;
    
    int ctd=0;
    for(int i=1; i<=N; i++)
        if(upas[i])
            ctd++;
    cout << ctd << endl;

    
    for(int i=1; i<=N; i++)
        if(upas[i])
            cout << i << ' ';
    cout << endl;

    return 0;
}