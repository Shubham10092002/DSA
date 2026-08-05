
// painting fence algorithm
// cant paint a color k consecutive times on the fence
#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n, int k)
{

  if (n == 1)
  {
    return k;
  }

  if (n == 2)
  {
    return (k + k * (k - 1));
  }

  int ans = (solveUsingRecursion(n - 2, k) + solveUsingRecursion(n - 1, k)) * (k - 1);

  return ans;
}

int solveUsingMem(int n, int k, vector<int> &dp)
{
  if (n == 1)
  {
    return k;
  }
  if (n == 2)
  {
    return (k + k * (k - 1));
  }

  if (dp[n] != -1)
    return dp[n];

  dp[n] = (solveUsingMem(n - 2, k, dp) + solveUsingMem(n - 1, k, dp)) * (k - 1);
  return dp[n];
}

int solveUsingTab(int n, int k)
{
  vector<int> dp(n + 1, 0);
  dp[1] = k;
  dp[2] = (k + k * (k - 1));

  for (int i = 3; i <= n; i++)
  {

    dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
  }
  return dp[n];
}

int solveSO(int n, int k)
{

  int prev2 = k;
  int prev1 = (k + k * (k - 1));

  for (int i = 3; i <= n; i++)
  {

    int curr = (prev2 + prev1) * (k - 1);

    // shhift -> yaha hi galti karunga ya karungi
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}

int main()
{

  int n = 4;
  int k = 3;

  // int ans = solveUsingRecursion(n, k);

  // vector<int> dp(n+1, -1);
  // int ans = solveUsingMem(n, k,dp);

  int ans = solveSO(n, k);
  cout << "ans: " << ans << endl;

  return 0;
}

gfg(Get Minimum Squares)

    // Given a number n, find the minimum number of perfect squares (square of an integer) that sum up to n.

    // Examples:

    // Input: n = 100
    // Output: 1
    // Explanation: 10 * 10 = 100
    // Input: n = 6
    // Output: 3
    // Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6

    class Solution
{
public:
  int solve(int n, int rem, vector<int> &dp)
  {
    if (rem < 0)
      return INT_MAX;

    if (rem == 0)
        return 0;

    if (dp[rem] != -1)
      return dp[rem];

   
 int minstep = INT_MAX;
    int ans = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
      int res = solve(n, rem - i * i, dp);

      minstep = min(minstep, res);
    }

    if (minstep != INT_MAX)
    {
      dp[rem] = minstep + 1;
      return minstep + 1;
    }

    else
    {
      dp[rem] = INT_MAX;
      return INT_MAX;
    }
  }

  int tab(int n, int rem)
  {
    vector<int> dp(n + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
      int minstep = INT_MAX;
      int ans = 0;
      for (int j = 1; j * j <= n; j++)
      {

        if (i - j * j >= 0)
        {
          int res = dp[i - j * j];

          minstep = min(minstep, res);
        }
        dp[i] = minstep + 1;
      }
    }

    return dp[n];
  }
  int MinSquares(int n)
  {
    // Code here
    int num = sqrt(n);
    vector<int> dp(n + 1, -1);
    int ans = solve(n, n, dp);
    return ans;

    // int ans =  tab( n,n);

    // return ans;
  }
};

// gfg (Largest square formed in a matrix)

// Given a binary matrix mat, find out the maximum length of a side of a square sub-matrix with all 1s.
// Examples:

// Input: mat = [[0, 1, 1, 0, 1],
//               [1, 1, 0, 1, 0],
//               [0, 1, 1, 1, 0],
//               [1, 1, 1, 1, 0],
//               [1, 1, 1, 1, 1],
//               [0, 0, 0, 0, 0]]
// Output: 3
// Explanation:

// The maximum length of a side of the square sub-matrix is 3 where every element is 1.
// Input: mat = [[1, 1],
//               [1, 1]]
// Output: 2

class Solution
{
public:
  int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
  {
    if (i >= mat.size() || j >= mat[0].size())
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int right = solve(mat, i, j + 1, maxi, dp);
    int diagnol = solve(mat, i + 1, j + 1, maxi, dp);
    int down = solve(mat, i + 1, j, maxi, dp);

    if (mat[i][j] == 1)
    {
      int ans = 1 + min(right, min(diagnol, down));
      maxi = max(ans, maxi);
      dp[i][j] = ans;
      return ans;
    }
    
    else
    {
      return dp[i][j] = 0;
    }
  }

  int solveTab(vector<vector<int>> &mat, int &maxi)
  {

    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        int right = dp[i][j + 1];
        int diagnol = dp[i + 1][j + 1];
        int down = dp[i + 1][j];

        if (mat[i][j] == 1)
        {
          dp[i][j] = 1 + min(right, min(diagnol, down));
          maxi = max(dp[i][j], maxi);
          // dp[i][j] = ans;
          // return ans;
        }
        else
        {
          dp[i][j] = 0;
        }
      }
    }

    return dp[0][0];
  }

  int maxSquare(vector<vector<int>> &mat)
  {
    // code here
    // int n = mat.size();
    // int m = mat[0].size();

    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    // int maxi = 0;
    // solve(mat,0,0,maxi,dp);
    int maxi = 0;
    solveTab(mat, maxi);
    return maxi;
  }
};
