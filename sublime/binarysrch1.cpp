#include<bits/stdc++.h>
using namespace std;

void insertAtPosition(stack<int>&st,int target){
	if(st.empty()){

		st.push(target);
		return;
	}

	if(st.top()>=target){

		st.push(target);
		return;
	}
	int temp=st.top();
	st.pop();
	insertAtPosition(st,target);

	
	
}

void sortstack(stack<int>&st){
	if(st.empty())
		return;

	int temp=st.top();
	st.pop();
	sortstack(st);
	insertatbottom(st,temp);
}

int main(){

	//int n; cin >> n;
	//int k;
	//cin >> k;
	int arr[]= {7,1,5,3,6,4};
	
	//sort(arr,arr+n);
	int buyprice=arr[0];;
	int j=1;
	int sum=0;
	int maxi=0;



	while(j<6){

		

	}

	cout << maxi << endl;
	return 0;
}