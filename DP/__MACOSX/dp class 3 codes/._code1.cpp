// 1039. Minimum Score Triangulation of Polygon

// You have a convex n-sided polygon where each vertex has an integer value. 
//You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.
// Polygon triangulation is a process where you divide a polygon into a set of triangles 
// and the vertices of each triangle must also be vertices of the original polygon. 
// Note that no other shapes other than triangles are allowed in the division. 
// This process will result in n - 2 triangles.

// You will triangulate the polygon. For each triangle, 
// the weight of that triangle is the product of the values at its vertices. 
// The total score of the triangulation is the sum of these weights over all n - 2 triangles.

// Return the minimum possible score that you can achieve with some triangulation of the polygon.

// Example 2:

// Input: values = [3,7,4,5]

// Output: 144

// Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
// The minimum score is 144.

// Example 3:

// Input: values = [1,3,1,4,1,5]

// Output: 13

// Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.



class Solution {
public:
int solve(vector<int>& v,int i , int j,vector<vector<int>>&dp){
    if(i+1 == j)
        return 0;
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = INT_MAX;
    for(int k =i+1; k<j; k++){

        ans =  min(ans, v[i] * v[j]* v[k] + solve(v,i,k,dp)+solve(v , k, j,dp));


    }
    return dp[i][j] = ans;
}

//tabulation method
int solveTab(vector<int>& v){
    int n = v.size();
    vector<vector<int>>dp(n,vector<int>(n,0));

    for(int i =n-1; i>=0; i--){
        for(int j=i+2; j<n; j++){
            int ans = INT_MAX;

            for(int k =i+1; k<j; k++){

                ans =  min(ans, v[i] * v[j]* v[k] + 
                dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][n-1];

}


    int minScoreTriangulation(vector<int>& values) {
        // int n = values.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        // return solve(values, 0, n-1,dp);

        return solveTab(values);

    }
};