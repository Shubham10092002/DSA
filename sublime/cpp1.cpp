#include<bits/stdc++.h>
using namespace std;

  int minAnagramLength(string s) {
        int mini=0;

        for(int i=0; i<s.size()/2; i++){
        	//string str1;
        	//string str2;
        	string str1=s.substr(0,i+1);
        	sort(str1.begin(),str1.end());
        	//int len= str1.size();
        	string str2=s.substr(i+1,i+1);
        	sort(str2.begin(),str2.end());

        	int x = str1.compare(str2);

        	if(x==0)
        		mini=max(mini,i+1);

        }

        if(mini!=0){
        	return mini;
        }
       
        return s.size();
    }
    

int main(){
	//string src="cdef";

int ans=minAnagramLength("cdef");
//string dest;
//strncpy(dest, src + 1, strlen(src) - 2);
//dest=src.substr(2,2);
cout << ans << endl;


	return 0;
}
/*
int main(){
   cout << "hello";
   return 0;
}*/