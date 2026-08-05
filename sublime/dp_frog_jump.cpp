#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,int n,vector<int>&dp){

		if(n==0)
			return 0;
		
		 

		 if(dp[n]!=-1)
		 	return dp[n];

	//	int mini=INT_MAX;

		int ans1 = solve(arr,n-1,dp) +abs(arr[n] -arr[n-1]);
		int ans2;
		if(n>1)
		 ans2 = solve(arr,n-2,dp) + abs(arr[n]- arr[n-2]);

	//	mini = min(ans1,ans2) ;
		return dp[n]=min(ans1,ans2) ;
		//return dp[n];
		//return mini;

		//int ans = min(solve())
}

int main(){

 int n=4;
 vector<int> arr={10,20,30,10};
 vector<int> dp(n+1,-1);
 int ans = solve(arr,n-1,dp);

 cout  << ans << endl;




	return 0;
}