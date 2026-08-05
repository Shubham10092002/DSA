#include<bits/stdc++.h>
using namespace std;

void solve(string &s,int left,int right,set<string>&st,int &count){
    //int count =0;
    string str="";
    int i = left;
    while( left >=0 && right <s.size() && s[left]==s[right]){
        count++;
        if(left == right){
            str = s[left];
        }
        else
            str = s[left]+ str + s[right];

            st.insert(str);
            cout << str << " ";
            left--;
            right++;
    }
}

int main(){
    string str= "abaacd";
    set<string>st;
    int count=0;
    cout << "palindromic substring are : " << endl;
    for(int center=0; center < str.size(); center++){
        solve(str,center,center,st,count);
        solve(str,center,center+1,st,count);
    }cout << endl << endl;
    
    for(auto it : st){
        cout << it << " ";
    }

    cout << endl;
    cout << "Number of Palindromic Substring: " << count << endl;
    cout << endl;
    cout << "Number of unique Palindromic Substring: " << st.size() << endl;
    
    return 0;
}