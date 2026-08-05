
#include<bits/stdc++.h>
using namespace std;

int main(){

	string str1 ="daabcbaabcbc";
	string part ="abc";
	int pos = str.find(part);
	
	while(pos != string::npos){

		str1.erase(pos,part.length());
		pos = str.find(part);

	}

	 cout << str << endl;
	 return 0;


}

