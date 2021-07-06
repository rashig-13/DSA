There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.


Logic: 1) Use Floyd-Warshall's algorithm to compute any-point to any-point distances.
       2) For each city calculate the number of reachable cities within the threshold, then search for the optimal city.

     class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresold) {
     int a[n][n];
        int INF=10000000;
        // inialised matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) a[i][j]=0;
                else
                    a[i][j]=INF;
            }
        }
      
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0],y=edges[i][1],w=edges[i][2];
            //undirected graph
            a[x][y]=w;
            a[y][x]=w;
        }
        Floyd-Warshall algo
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(a[i][j] > (a[i][k]+a[k][j]) && (a[i][k]!=INF && a[j][k]!=INF))
                        a[i][j] = a[i][k]+a[k][j];
                }
            }
        }
        int city,mn=INT_MAX;
        //find ans
       for(int i=0;i<n;i++){
           int c=0;
            for(int j=0;j<n;j++){
               if(a[i][j]<=thresold) 
                   c++;
            }
           if(c<=mn){
               city=i;
               mn=c;
           }
        }
        return city;
    }
};