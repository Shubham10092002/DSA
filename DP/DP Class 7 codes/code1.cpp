class Solution {
public:
    int solveUsingRecursion(vector<int>& arr, int curr, int prev) {
        if(curr >= arr.size()) {
            return 0;
        }

        //include
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev])
            include = 1 + solveUsingRecursion(arr, curr+1, curr);

        //excude
        int exclude = 0 + solveUsingRecursion(arr, curr+1, prev);

        int ans = max(include, exclude);
        return ans;

    }

    int solveUsingMem(vector<int>& arr, int curr, int prev, vector<vector<int> >& dp) {
        if(curr >= arr.size()) {
            return 0;
        }

        if(dp[curr][prev + 1] != -1)
            return dp[curr][prev+1];

        //include
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev])
            include = 1 + solveUsingMem(arr, curr+1, curr, dp);

        //excude
        int exclude = 0 + solveUsingMem(arr, curr+1, prev, dp);

        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];

    }

    int solveUsingTab(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev])
                    include = 1 + dp[curr+1][curr + 1];

                //excude
                int exclude = 0 + dp[curr+1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);   
            }
        }
        return dp[0][0];
    }
    
    int solveOptimal(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        vector<int> ans;
        ans.push_back(arr[0]);

        for(int i=1; i<arr.size(); i++) {
            if(arr[i] > ans.back()) {
                //include
                ans.push_back(arr[i]);
            }
            else {
                //overwrite
                //find index of just bada element
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }


int solveUsingTabSO(vector<int>& arr) {
        int n = arr.size();
        //vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev])
                    include = 1 + nextRow[curr + 1];

                //excude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);   
            }
            //shift
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        
        int curr = 0;
        int prev = -1;
        // int ans = solveUsingRecursion(nums, curr, prev );
        int n = nums.size();
        //vector<vector<int> > dp(n, vector<int>(n+1, -1));
        //int ans = solveUsingMem(nums, curr, prev, dp);
        int ans = solveOptimal(nums);
        return ans;
        
    }
};



983. Minimum Cost For Tickets

// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

 

// Example 1:

// Input: days = [1,4,6,7,8,20], costs = [2,7,15]
// Output: 11
// Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
// On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
// On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
// On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
// In total, you spent $11 and covered all the days of your travel.



class Solution {
public:
int solve(int n, vector<int>& days, vector<int>& cost, int index,vector<int>&dp){
    if(index>= n) return 0;

    if(dp[index] != -1)
    return dp[index];

     //  1 ady pass
     int opt1 = cost[0] + solve(n,days,cost,index+1,dp);

     //7 days pass
      int i;
      for( i= index; i<n && days[i] < days[index] + 7; i++);

      int opt2 = cost[1] + solve(n,days,cost,i,dp);

      // 30 days pass
      for( i= index; i<n && days[i] < days[index] + 30; i++);
      int opt3 = cost[2] + solve(n,days,cost,i,dp);

      dp[index] = min(opt1,min(opt2,opt3));
      return dp[index];


}



int solveTab(int n, vector<int>& days, vector<int>& cost){
        vector<int> dp(n+1, INT_MAX);
        dp[n] =0;

        for(int i= n-1; i>=0; i--){
            int opt1 = cost[0] + dp[i+1];

           int j;
            for( j= i; j<n && days[j] < days[i] + 7; j++);
            int opt2 = cost[1] + dp[j];

            // 30 days pass
            for( j= i; j<n && days[j] < days[i] + 30; j++);
            int opt3 = cost[2] + dp[j];

             dp[i] = min(opt1,min(opt2,opt3));
           
        }

       return dp[0];
}





    int mincostTickets(vector<int>& days, vector<int>& costs) {
          int n = days.size();
        // vector<int> dp(n+1, -1);
      

        // return solve(n,days,costs,0,dp);
       return solveTab(n,days,costs);
    }
};