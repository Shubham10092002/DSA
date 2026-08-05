//fibonacci\\

// solving using top down memoisation

int topdown(int n, vector<int> & dp){

	if(n==0 || n==1){
		return n;
	}
	if(dp[n]!=-1){
		return -1;
	}

	int ans = topdown(n-1,dp) + topdown(n-2,dp);
	dp[n] = ans;
	return dp[n];
}

//solving using bottom upapproach

int bottomupapproach(int n){
	vector<int> dp(n+1,-1);

	dp[0]=0;
	if(n==0)
		return dp[0];

	dp[1]=1;

	for(int i=2; i< n; i++){
		dp[i] = dp[i-1] +dpo[i-2];
	}

	return dp[n];
}

int spaceopt(int n){
	int prev2=0;
	int prev1 = 1;
	if(n==0)
		return prev2;
	if(n==1)
		return prev1;

	 int curr;

	for(int i=2; i<n; i++){
		  curr = prev2 + prev1;
		 prev2 = prev1;
		 prev1 = curr ;
	}

	return curr;
}

//include exclude patter
int solveusingmemorundum(vector<int> &num ,int n,vector<int> &dp){
	if(n<0)
		return 0;

	if(n==0)
		return nums[0];
	if(dp[n]!= -1)
		return dp[n];

	int include = solveusingmemorundum(nums,n,dp);
	int exclude = solveusingmemorundum(nums,n-1;dp);
	 dp[n] = max(include || exclude);
	 return dp[n];
	//return  max(include || exclude);

}

int bottomup(int n){
	if(n<0)
		return 0;
	vector<int> dp(n+1,-1);

	if(n==0)
		dp[0] = nums[0];
	for(int i=1; i<=n; i++){
		int temp =0;

		int include = bottomup(n-1) + nums[i];;
		int exclude


	}

	if(n==)
}


//minimum coin require to get theb target amount

int solvemem(vector<int> coin, int target, vector<int> & dp){

	if(target == 0)
		return 0;
	if(target < 0){
		return INT_MAX;
	}

	if(dp[target]!= -1)
		return dp[target];

		int mini = INT_MAX;

	for(int  i=0; i< coin.size(); i++){
		if(ans! = INT_MAX)
		int ans = solvemem(coin,target-coin[i], dp); 

		mini = min(mini ,1+ ans);
	}
	dp[target] = mini ;
	return dp[target];
}
int bottomup(vector<int> coins,int target){
	vector<int> dp(n+1,-1);

	dp[0] =0;
	for(int i =1; i<target; i++){

		int mini =INT_MAX;
		int ans

	}

}