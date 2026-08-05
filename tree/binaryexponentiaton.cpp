#include<bits/stdc++.h>
using namespace std;


//brute force approach

/*int power(int base, int n){

	int res=1;

	for(int i=1; i<=n; i++){
		res=res*base;

	}

	return res;
}*/

//another approach

int power(int a, int n){
	
	int res=1;

	while(n){
		if(n % 2)
			res*=a ,n--;

		else
			a*=a ,n/=2;
	}

	return res;
}


int main(){

	int base,n;

	cin >> base >> n;
	 cout << power(base,n) << endl;

	return 0;
}