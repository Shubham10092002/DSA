#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int n){

	if(n==1 || n==0){
		cout << -1 << endl;
	}

	int small=INT_MAX, second_small=INT_MAX;
	int large=INT_MIN, second_large=INT_MIN; 

	for(int i=0; i<n; ++i){

		small=min(arr[i],small);
		large=max(arr[i],large);


	}

	for(int i=0; i<n; ++i){

		if(arr[i] < second_small && arr[i]!=small)

			second_small=arr[i];

		if(arr[i] > second_large && arr[i]!=large)

			second_large=arr[i];
	}

	cout << second_small << " " << second_large << endl;
}

int main(){

	int arr[10],n;

	//cout << " enter the size of array " << endl;

	cin >> n;

	//cout << enter 

	for(int i=0; i<n; ++i){

		cin >> arr[i];

	}

	solve(arr,n);

	return 0;


}