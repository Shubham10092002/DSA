class Solution
{
public:
    int solveUsingRecursion(vector<int> &coins, int amount)
    {
        // base case
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return INT_MAX;
        }

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveUsingRecursion(coins, amount - coins[i]);
            if (ans != INT_MAX)
            {
                mini = min(mini, 1 + ans);
            }
        }
        return mini;
    }

    int solveMem(vector<int> &coins, int amount, vector<int> &dp)
    {
        // base case
        if (amount == 0)
        {
            return 0;
        }

        if (amount < 0)
        {
            return INT_MAX;
        }
        // ans already exists
        if (dp[amount] != -1)
        {
            return dp[amount];
        }

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveMem(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
            {
                mini = min(mini, 1 + ans);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int solveTab(vector<int> &coins, int amount)
    {
        // step1: create dp array
        vector<int> dp(amount + 1, INT_MAX);
        // step2: base case dekho
        dp[0] = 0;
        // step3: check the range and flow of top down approach and code accordingly
        for (int target = 1; target <= amount; target++)
        {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++)
            {
                if (target - coins[i] >= 0)
                {
                    int ans = dp[target - coins[i]];
                    if (ans != INT_MAX)
                    {
                        mini = min(mini, 1 + ans);
                    }
                }
            }
            dp[target] = mini;
        }

        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        // int ans = solveUsingRecursion(coins, amount);
        // if(ans == INT_MAX)
        //     return -1;
        // else
        //     return ans;

        // vector<int> dp(amount+1, -1);
        // int ans = solveMem(coins,amount, dp);
        // if(ans == INT_MAX)
        //     return -1;
        // else
        //     return ans;

        int ans = solveTab(coins, amount);
        if (ans == 1e9)
        {
            return -1;
        }

        else
            return ans;
    }
};

// You are given an integer array a of size 4 and another integer array b of size at least 4.
//  You need to choose 4 indices i0, i1, i2, and i3 from the array b such that i0 < i1 < i2 < i3.
// Your score will be equal to the value a[0] * b[i0] + a[1] * b[i1] + a[2] * b[i2] + a[3] * b[i3].
//  Return the maximum score you can achieve.

class Solution
{
public:
    long long solve(vector<int> &a, vector<int> &b, int i, int j, vector<vector<long long>> &dp)
    {
        if (i == 4)
        {
            return 0;
        }
        if (j >= b.size())
        {
            return INT_MIN;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        long long take = (long long)a[i] * b[j] + solve(a, b, i + 1, j + 1, dp);
        long long not_take = solve(a, b, i, j + 1, dp);

        return dp[i][j] = max(take, not_take);
    }

public:
    long long maxScore(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        vector<vector<long long>> dp(n, vector<long long>(100005, -1));
        return solve(a, b, 0, 0, dp);
    }
};

long long solve(vector<int> &a, vector<int> &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == 4)
        return 0;
    if (j >= b.size())
        return INT_MIN;

    if (dp[i][j] != -1)
        return dp[i][j];

    long long take = a[i] * b[j] + solve(a, b, i + 1, j + 1, dp);
    long long not_take = solve(a, b, i, j + 1, dp);

    return dp[i][j] = max(takke, not_take);
}
