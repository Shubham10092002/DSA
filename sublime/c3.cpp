#include<bits/stdc++.h>

using namespace std;

int main(){
   int t;
   cin >> t;

   while(t--){
    int n,s;
     cin >>n >> s;
     int sum =0;
     int zero =0,one =0,two =0;

     vector<int>a(n);

     for(int i=0; i<n; i++){
        cin >> a[i]; sum+=a[i];

        if(a[i] == 0)zero++;
        else if(a[i] == 1) one++;
        else two++;

     }

     int T = s - sum;

     if( T<0 || T == 1){
        bool f = true;
        for(int i=0; i<zero; i++){
            if(!f) cout <<" ";
            cout<< 0;
            f = false;
        }
        for(int i=0; i<two; i++){
            if(!f) cout << " " ;
            cout<< 2;
            f = false;
        }

        for(int i=0; i<one; i++){
            if(!f) cout << " ";
            cout << 1 ;
            f = false;
        }

        cout << endl;
     }else{
        cout << -1 << endl;
     }

    }

    return 0;
}

