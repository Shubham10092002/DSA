

#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
	if(n==1)
		return false;

	for(int i=2; i*i <=n; i++){

		if(n%i==0)
			return false;
	}

	return true;

}

 //prime number for a range  

//time comlexity O(nlog log n)

vector<bool> seive(int n){
vector<bool> isPrime(n+1,true);

	//int maxN=1000000;

	for(int i=1; i<= n; i++){
		 isPrime[i]=1;
	}

	isPrime[0]=isPrime[1]=0;

	for(int i=2; i*i <=n; i++){
		if(isPrime[i]){
			for(int j=i*i; j<n; j+=i){
				isPrime[j]=0;
			}
		}
	}

	return isPrime;


}


int main(){

      //finding prime number using square root method 
	 //time complexity O(n^1/2)


    cout << isprime(6) << endl;

    vector<bool> ans=seive(100);

 	for(int i=0; i<100; i++){

 		cout << i << " " << ans[i] << endl;

 	}

	return 0;
}