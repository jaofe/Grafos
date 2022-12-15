#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>


using namespace std;

void bellman_ford (vector<vector<tuple<int, int>>> adj) {
    int n = adj.size();
    
    vector<vector<int>> min_dist (n, vector<int> (n, 999999));
    min_dist[0][0] = 0;

    for(int i = 1; i < n; i++) 
    {
        for(int k = 0; k < n; k++)
        {
            int min_temp = INT_MAX;
            for (auto j: adj[k]) 
            {

                if (min_temp > get<1>(j) + min_dist[i-1][get<0>(j)]){

                    min_temp =  get<1>(j) + min_dist[i-1][get<0>(j)];
                }
            }

            min_dist[i][k] = min(min_dist[i-1][k], min_temp);
        }
    }
    
    for (int i = 1; i < n; i++) {
        cout << "min_dist(1," << i + 1 << "):";
        if (min_dist[n-1][i] < 900000) {
            cout << min_dist[n-1][i] << " ";
        } 
        else {
            cout << "INF ";
        }
    }
    cout << endl;

    return;
}

int main () {

    int n, m;
	cin >> n >> m;
    vector<vector<tuple<int, int>>> adj;
   
	for(int i =0; i< n; i++)
	{
        vector<tuple<int, int>> temp;
		adj.push_back(temp);
    }

	int u, v, p;
    for(int i =0; i< m; i++)
	{
		cin >> u >> v >> p;
		adj[v - 1].push_back(make_tuple(u - 1, p));
	}

    bellman_ford(adj);

    return 0;
}
