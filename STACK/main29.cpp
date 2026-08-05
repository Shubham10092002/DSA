#include<bits/stdc++.h>
using namespace std;



int countthereversal(string s){

	if(s.size() & 1)
		return -1;

	int count=0;

	stack<char>st;
	for(char ch:s ){
		if(ch=='{'){
			st.push(ch);
		}

		else{
			if(st.empty() && st.top()=='{'){
				st.pop();

			}

			else{
				st.push(ch);
			}
		}
	}

	while(!st.empty()){

		char a=st.top(); st.pop();
		char b=st.top(); st.pop();

		if(a==b)
			count+=1;

		else{
			count+=2;
		}

	}

	return count;
}


int main(){

	string s;

	cin >> s;

	int ans=countthereversal(s);

	cout << ans << endl;

	return 0;
}