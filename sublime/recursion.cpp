#include<bits/stdc++.h>
using namespace std;

void solve(int n,string output){


	if(output.size()==n){

		cout << output << endl;

		return;
	}

	int len=output.size();

	if(len==0){
		solve(n,output+'0');
		solve(n,output+'1');
	}
	
	else{
		
		/*if(output[len-1]=='1'){
			solve(n,output+'0');
		}*/

		
			solve(n,output+'0');
			solve(n,output+'1');
		
	}
	
}


int main(){

int n; cin >> n;

solve(n,"");
	return 0;
}
