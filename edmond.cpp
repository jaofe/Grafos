#include <iostream>
#include <limits.h>
#include <queue>
#include <vector> 

using namespace std;

int n;

int bfs(vector<vector<int>> f, int s, int t, int pai[])
{
    
    queue<int> q;
	vector<int> pre (n, 0);

	q.push(s);
	pre[s] = 1;
	pai[s] = -1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < n; v++) {
			if (pre[v] == 0 && f[u][v] > 0) {

				pre[v] = 1;
				pai[v] = u;
                q.push(v);

				if (v == t) 
                {
					return 1;
				}
			}
		}
	}

	return 0;
}

void edmond(vector<vector<int>> f, int s, int t)
{
	int u, v;
	int pai[n]; 
	int fluxom = 0; 

	while (bfs(f, s, t, pai)) {

		int cf = INT_MAX;
		for (v = t; v != s; v = pai[v]) {
			u = pai[v];
			cf = min(cf, f[u][v]);
		}

		for (v = t; v != s; v = pai[v]) {
			u = pai[v];
			f[u][v] -= cf;
			f[v][u] += cf;
		}

		fluxom += cf;
	}

    cout << fluxom << endl;

	return;
}

int main(int argc, char** argv) {
    int m, i, l;

	cin >> i >> l;
	i--;
	l--;

    cin >> n >> m;
    vector<vector<int>> adj (n, vector<int>(n, 0));

    int u, v, p;
    for(int k = 0; k < m; k++) {
        
        cin >> u >> v >> p;

        adj[u-1][v-1] = p;
    }

	edmond(adj, i, l);
    return 0;
}
