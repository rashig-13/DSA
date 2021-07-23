There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x k cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on...
Return the minimum cost to paint all houses.

For ref, see Paint house I
//O(n.k^2) DP
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size(),m=costs[0].size();
        for(int i=n-2;i>=0;i--){
            
            for(int j=0;j<m;j++){
                int mn=INT_MAX;
                for(int k=0;k<m;k++){
                    if(j==k) continue;
                    mn=min(mn,costs[i+1][k]);
                }
                costs[i][j]+=mn;
            }
           
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++)
            ans=min(ans,costs[0][j]);
        return ans;
    }
};

//O(n.k) Optimised DP from editorial
We need only first min and 2nd min from the prev state.
class Solution {

    public int minCostII(int[][] costs) {

        if (costs.length == 0) return 0;
        int k = costs[0].length;
        int n = costs.length;

        for (int house = 1; house < n; house++) {

            // Find the minimum and second minimum color in the PREVIOUS row.
            int minColor = -1; int secondMinColor = -1;
            for (int color = 0; color < k; color++) {
                int cost = costs[house - 1][color];
                if (minColor == -1 || cost < costs[house - 1][minColor]) {
                    secondMinColor = minColor;
                    minColor = color;
                } else if (secondMinColor == -1 || cost < costs[house - 1][secondMinColor]) {
                    secondMinColor = color;
                }
            }

            // And now calculate the new costs for the current row.
            for (int color = 0; color < k; color++) {
                if (color == minColor) {
                    costs[house][color] += costs[house - 1][secondMinColor];
                } else {
                    costs[house][color] += costs[house - 1][minColor];
                }
            }
        }

        // Find the minimum in the last row.
        int min = Integer.MAX_VALUE;
        for (int c : costs[n - 1]) {
            min = Math.min(min, c);
        }
        return min;
    }
}