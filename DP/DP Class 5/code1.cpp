
//375. Guess Number Higher or Lower II
// We are playing the Guessing Game. The game will work as follows:

// I pick a number between 1 and n.
// You guess a number.
// If you guess the right number, you win the game.
// If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
// Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
// Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.


class Solution {
public:

    int solveUsingRecursion(int start, int end) {
        if(start >= end)
            return 0;
        
        int ans = INT_MAX;
        for(int i=start; i<=end; i++) {
            ans = min(ans, i + max(solveUsingRecursion(start,i-1),solveUsingRecursion(i+1, end)));
        }
        return ans;
    }

    int solveUsingMem(int start, int end, vector<vector<int> >& dp) {
        if(start >= end)
            return 0;

        if(dp[start][end] != -1) {
            return dp[start][end];
        }
        
        int ans = INT_MAX;
        for(int i=start; i<=end; i++) {
            ans = min(ans, i + max(solveUsingMem(start,i-1, dp),solveUsingMem(i+1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    int solveUsingTab(int n) {
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));

        for(int start=n; start >= 1; start-- ) {
            for(int end = 1; end<=n; end++) {
                
                if(start>=end)
                    continue;
                else {
                    int ans = INT_MAX;
                    for(int i=start; i<=end; i++) {
                        ans = min(ans, i + max(dp[start][i-1],dp[i+1][end]));
                    }
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];

    }

    int getMoneyAmount(int n) {
        //int ans = solveUsingRecursion(1,n);
        // vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(1, n, dp);

        int ans = solveUsingTab(n);
        return ans;
    }
};


int solve(int start, int end){
    if(start>= end)
        return 0;

    int ans = INT_MAX;

    for(int i= start; i<=end; ++i){
        ans = min(ans, i + max(solve(i+1, end), solve(start, i-1)));
    }

    return ans;
}



