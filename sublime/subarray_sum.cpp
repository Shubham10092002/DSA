#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums ,int sum , int i,int &maxi){
	if(i>=nums.size()){
		maxi = max(maxi,sum);
		return ;
	}

	 //include
	solve(nums,sum+nums[i],i+1,maxi);
	solve(nums,sum,i+1,maxi);

}

void sellstocks(vector<int> nums ,int &ans,int index,int &mini){
	if(index > nums.size())
		return ;
	mini = min(mini,nums[index]);
	int profit = nums[index] - mini;
	 ans  = max(ans,profit);

	sellstocks(nums,ans,index+1,mini);



}

int main(){

	vector<int> nums = { 7,6,4,3,1};
	//arr = [-2,1,-3,4,-1,2,1,-5,4] 
	int maxi= INT_MIN;
	solve(nums,0,0,maxi);
	cout << maxi << " " << endl;
	int ans =0;
	int mini =nums[0];
	sellstocks(nums,ans,0,mini);
	
	cout << ans << endl;

	return 0;

}