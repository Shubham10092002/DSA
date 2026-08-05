#include<bits/stdc++.h>
using namespace std;

void printsubarray_util(vector<int>nums,int start,int end){
	if(end>=nums.size()){
	return;
	}

	for(int i=start; i<end; i++){
		cout << nums[i] ;
	}

	printsubarray_util(nums,start,end+1);
}


void printsuarray(vector<int>nums){
	for(start=0; start<nums.size(); start++){
		int end=start;
		printsubarray_util(nums,start,end);
	}
}

int main(){
	vector<int>nums={1,2,3,4,5};

	printsubarry(nums);

	return 0;



}