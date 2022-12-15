#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

vector<int> pai, _rank;

void _union (int x, int y) {

    if (_rank[x] >= _rank[y]) 
    {
        pai[y] = x;
        if (_rank[x] == _rank[y]) 
        {
           _rank[x]++;
        }
    }
    else 
    {
        pai[x] = y;   
    }
}

int find (int x) {
    if (pai[x] != x) {
        pai[x] = find(pai[x]);
    }
    return pai[x];
}

void make_set (int x) {
    pai[x] = x;
    _rank[x] = 0;

    return;
}

vector<tuple<int, int, int>> kruskal (vector<tuple<int, int, int>> adj, int n) {

    vector<tuple<int, int, int>> T; 

    vector<int> vec (n, 0);
    pai = vec;
    _rank = vec;
    
    for (int i = 0; i < n; i++) 
    {
        make_set(i);
    }

    int m = adj.size();
    for (int j = 0; j < m; j++) 
    {        
        if (find(get<1>(adj[j])) != find(get<2>(adj[j]))) 
        {
            T.push_back(adj[j]);
            _union(find(get<1>(adj[j])), find(get<2>(adj[j])));
        } 
    }

    return T;
}

int main () {

    vector<tuple<int, int, int>> adj;
    
    int n, m;
    cin >> n >> m;

    int p, ve, vs;
    for (int i = 0; i < m; i++) 
    {
        cin >> ve >> vs >> p;
        adj.push_back(make_tuple(p, ve - 1, vs - 1));
    }

    sort(adj.begin(), adj.end());

    vector<tuple<int, int, int>> T;
    T = kruskal(adj, n);

    cout << "Arestas que geram a árvore geradora minima:\n";

    int tn = T.size();
    int custo = 0;
    for (int i = 0; i < tn; i++) 
    {
        cout << "(" << get<1>(T[i]) + 1 << "," << get<2>(T[i]) +1 << ") ";

        custo = custo + get<0>(T[i]);
    }
    cout << "\nCusto total:\n" << custo << endl;

    return 0;    
}
