//generate all permutation
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans,int index){
	if(index >= nums.size()){

		ans.push_back(nums);
		return;
	}

	for(int j =index; j<nums.size(); j++){
		swap(nums[index], nums[j]);
		solve(nums, ans, index+1);
		swap(nums[index], nums[j]);
	}
}


vector<vector<int>> permutation(vector<int> &nums){
	vector<vector<int>> ans;
	int index =0;
	 solve(nums,ans, index);

	 return ans;
}


int main(){
	vector<int> nums;
	int size ;
	cin >> size;
	for(int i=0; i<size; i++){
		cin >> nums[i];
	}

	sort(nums.begin(),nums.end());
	
	vector<vector<int>> ans = permutation(nums);

	for(int i=0; i<ans.size();i++){
		for(int j=0; j<ans[0].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}