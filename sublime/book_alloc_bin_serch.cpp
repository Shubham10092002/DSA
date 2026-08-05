#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int>nums,int n,int m, int sol){
	int pagesum=0;
	int c=1;

	for(int i=0; i<n; i++){

		if(nums[i] >sol){
			return false;
		}
		if(pagesum + nums[i] >sol){
			c++;
			pagesum=nums[i];
			if(c>m){
				return false;
			}
		}

		else{
			pagesum+=nums[i];
		}
	}

	return true;
}

int findpage(vector<int>nums,int n,int m){

	int s=0;
						
d
	if(m>n){
		return -1;
	}

	int ans=-1;
	while(s<=e){
		int mid=s+(e-s)/2;

		if(ispossible(nums,n,m,mid)){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}

	return ans;
}

int main(){

vector<int>nums={12,34,67,90};
int n=4;
int m=2;
int ans=findpage(nums,n,m);
//int ans=accumulate(v.begin(),v.end(),0);
cout << ans << endl;

}
								


 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
               int length1=nums1.size();
                 int length2=nums2.size();
                vector<int> vec(length2);

                vector<int> ans(length1);

                stack<int>st;
                st.push(-1);

                for(int i=length2-1; i>=0; i--){

                    int curr=nums2[i];
                    while(st.top()<=curr){
                        if(st.top()==-1)
                            break;

                         else
                            st.pop();
                    }
                    vec[i]=st.top();
                    st.push(curr);
                }

                for(int i=0; i<length1; i++){
                    auto it=find(nums2.begin(),nums2.end(),nums1[i]);
                    int index = it - nums2.begin();
                    ans[i]=(vec[index]);
                }