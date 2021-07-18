Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
return the maximum number of points that lie on the same straight line.

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<double,int> mp;
        int ans=0;
        for(int i=0;i<n-1;i++){
            int c=1;
            for(int j=i+1;j<n;j++){
                int x1=points[i][0],y1=points[i][1];
                int x2=points[j][0],y2 =points[j][1];
                if(x2==x1){
                    mp[INT_MAX-2]++;
                   ans=max(mp[INT_MAX-2],ans);
                }
                else{
                    double slope=(double)(y2-y1)/(double)(x2-x1);
                     mp[slope]++;
                    ans=max(mp[slope],ans);
                }
                
            }
            mp.clear();
        }
        
        return ans+1;
    }
};


