#include <iostream>
#include <vector>

using namespace std;

void print_path (int v1, int v2, vector<vector<int>> p) {

    if (p[v1][v2] == -1) 
    {
        cout << "Nenhum caminho disponivel!" << endl;
        return;
    }

    cout << v1 + 1 << " -> ";

    while (p[v1][v2] != v1 + 1) 
    {

        cout << p[v1][v2] << " -> ";

        v1 = p[v1][v2] - 1;
    }

    cout << v2 + 1 << endl;

    return;
}

void floyd_warshall(vector<vector<int>> d, vector<vector<int>> p) {

    int n = d.size();
    for(int k = 0; k < n; k++) 
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i != j)
            {           
                cout << "min_dist(" << i + 1 << "," << j + 1 << "): " << d[i][j] << ", p: ";
                print_path(i, j, p);
            }
        }
    }

    return;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> d(n, vector<int>(n, 999999));
    vector<vector<int>> pi(n, vector<int>(n, -1));

    for(int i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    int u, v, p;
    for(int k = 0; k < m; k++) {
        
        cin >> u >> v >> p;

        d[u-1][v-1] = p;
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {   
            if (i != j && d[i][j] < 999999) 
            {
                pi[i][j] = i + 1;
            }

        }
    }
    
    floyd_warshall(d, pi);

    return 0;
}
