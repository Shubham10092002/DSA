#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr){

	//vector<vector<int>>ans;
	set<vector<int>>st;


	for(int i=0; i<n; i++){

		set<int>hashset;

		for(int j=i+1; j<n; j++){

			int third = -(arr[i]+arr[j]);
			if(hashset.find(third)!=hashset.end()){
				vector<int>temp={arr[i],arr[j],third};
				sort(temp.begin(),temp.end());
				st.insert(temp);
			}

			hashset.insert(arr[j]);
		}

		

	}

	vector<vector<int>>ans(st.begin(),st.end());
	return ans;
}

int lowerBound(vector<int> arr,int n ,int x){

	int low=0;
	int high=n-1;
	int mid=low+(high-low)/2;
	int ans=-1;

	while(low<high){

		if(arr[mid] >= x){
			ans=mid;
			high=mid-1;
		}
		else{

			low=mid+1;
		}

		mid=low+(high-low)/2;
	}

	return ans;

}

int upperBound(vector<int >arr,int n,int x){
	int low=0;
	int high=n-1;
	int mid= low+(high-low)/2;
	int ans=-1;

	while(low<high){
		if(arr[mid] > x){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}

		mid=low+(high-low)/2;
	}
	return ans;
}

int firstoccurance(vector<int> arr,int n ,int x){

	int low=0;
	int high=n-1;
	int mid= low+(high-low)/2;

	int ans=-1;

	while(low<high){

		if(arr[mid]==x){
			ans=mid;
			high=mid-1;
		}
		else if(arr[mid] > x){
			high=mid-1;
		}
		else{
			low=mid+1;
		}

		mid=low+(high-low)/2;


	}

	return ans;
}

bool searchInARotatedSortedArrayII(vector<int>&arr, int k){

	int n=arr.size();
	int low=0;
	int high=n-1;
	int mid=low+(high-low)/2;

	bool ans=false;

	while(low <high){
		if(arr[mid]==k){

			ans=true;
			break;
		}


		if(arr[low] <= arr[mid]){

			if(arr[low] >=k && arr[mid]>=k){
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}

		else{

			if(arr[mid]  <= k && arr[high] >= k){
				low=mid+1;
			}
			else{
				high=mid-1;
			}
		}

		mid=low+(high-low)/2;
	}

	return ans;

}

int floorSqrt( int x ){
	int ans;

	int low=1; int high=x;
	int mid=low+(high-low)/2;

	while(low<=high){
		if(mid*mid==x){
			ans=mid;
			break;
		}
		else if(mid*mid>x){
			high=mid-1;
		}
		else{
			ans=mid;
			low=mid+1;
		}

		mid=low+(high-low)/2;
	}

	return ans;
}

//find  k diff pair

int bs(vector<int>nums,int start,int x){

	int end = nums.size()-1;
	int mid=start+(end-start)/2;
	int ans=-1;

	while(start < end ){

		if(nums[mid]==x){
			ans=1;
			break;
		}

		else if(nums[mid] >x){
			end=mid-1;
		}

		else{
			start=  mid+1;
		}

		mid=start+(end-start)/2;
	}

	return ans;
}

int findpair(vector<int >nums,int k){

	sets<pair<int,int>>st;

	for(int i=0; i<nums.size(); i++){

		if( bs(nums,i+1,nums[i]+k) !=-1){
			st.insert(nums[i],nums[i]+k);
		}

	}
	return ans.size();

}

//exponential search

int bs(vector<int>arr,int start,int end,int x){
	int mid=start+(end-start)/2;

	int ans=-1;

	while(start<end){
		if(arr[mid]==x){
			ans=mid;
			break;
		}
		else if(arr[mid] >x){
			end=mid-1;
		}
		else{
			start=mid+1;
		}

		mid=start+(end-start)/2;
	}
	return ans;
}


int exponentialsearch(vector<int>arr,int x){
		if(arr[0]==x)return 0;

		int i=1;
		while(i<arr.size() && arr[i]<x){
			i*=2;
		}
		return bs(arr,i/2,min(i,n-1),x);
}

int main(){


    int n = 36;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;


}