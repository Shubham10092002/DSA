
#include<bits/stdc++.h>
using namespace std;

//brute force approach

// complexity O(n)

/*void primefactor(int n){

	for(int i=2; i<=n; i++){
 
		if(n%i==0){

			int cnt=0;
			while(n%i==0){
				cnt++;
				n/=i;

			}

			cout << i << "^" << cnt << endl;

		}


}
}*/

//optimized approach
// if n is a composite number then there is a least 1 prime divisor of n below sqrt(n)


void primefactor(int n){
		for(int i=0; i*i <=n; i++){
			if(n%i==0){
				int cnt=0;
				while(n%i==0)
					cnt++,n/=i;

				cout << i << "^" << cnt << endl;
			}


		}

		if(n>1)
				cout << n << "^" << 1  << endl;

}

/*

gcd(a,b)=gcd(a-b,b)=gcd(a,b-a)
gcd(a,b)=gcd(b,a)
gcd(a,0)=a
gcd(0,a)=a
*/

int gcd(int a, int b){

	/*if(b==0){
		return a;

	}

	else
		return gcd(b,a%b);

		*/

	//another aooroach

	if(a==0){
		return b;
	}
	 else if(a>b){
	 	return gcd(a-b,b);
	 }
	 else{
	 	gcd(b-a,a);
	 }
}


int main(){

	//int n;

//	cin >> n;

	//primefactor(n);

int a,b;
cin >> a >> b;


 cout << gcd(a,b) << endl;


	return 0;
}