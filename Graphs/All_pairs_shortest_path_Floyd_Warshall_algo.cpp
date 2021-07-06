The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. 
The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. 
Tc: O(n^3)
//node 0 to n-1
void Solution::solve(int n, vector<vector<int> > &v){
    int dist[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
            dist[i][j] =0;
            else
            dist[i][j] =INF;
        }
    }
    for(int i=0;i<v.size();i++){
        int x=v[i][0],v[i][1],w=v[i][2];
        dist[x][y] = w;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j] > (dist[i][k]+dist[k][j] && dist[i][k]!=INF && dist[k][j]!=INF))
                dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}