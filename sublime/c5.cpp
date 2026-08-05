// 



// #include <bits/stdc++.h>
// using namespace std;
//         int solve(long long  n, long long i , long long k , long long x){

//             if(i>n)
//                 return 0;

//             if(k==0 && x ==0 )
//                 return 1;

//             if(x==0 && k!=0)
//                 return 0;

//             if(x!=0 && k == 0)
//                 return 0; 





//             int include =  solve(n, i+1, k-1, x-i);
//             int exclude = solve(n, i+1 , k, x);

//             return (include || exclude);
//         }

//         int main() {

//             int t;
//             cin >> t;
//             while (t--) {
//               long long  n,k,x;
//                cin >> n >> k >> x;

//                int ans =  solve(n, 1, k, x);

//                ans == 1 ? cout <<"YES" : cout <<"No";

//                cout << endl;



//             }

//             return 0;
                
                
//         }

// 12
// 5 3 10
// 5 3 3
// 10 10 55
// 6 5 20
// 2 1 26
// 187856 87856 2609202300
// 200000 190000 19000000000
// 28 5 2004
// 2 2 2006
// 9 6 40
// 47202 32455 613407217
// 185977 145541 15770805980


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
     long long n; 
     cin >> n;

     vector<long long> a(n);
     long long count  = 0;

     for(int i=0; i<n; i++)
        cin >>a[i];

    for(int i=0; i<n; i++){
        if(a[i] == 0)
            count++;
    }
    bool founnd_zero = false;

    int left = 0;
    int right = n-1;

    while(a[left] == 0)
        left++;

    while(a[right] == 0)
        right--;

    for(int i=left; i<=right; i++){
        if(a[i] == 0)
            founnd_zero = true;
    }

    if(count == n)
        cout<< 0 << endl;
    else if(founnd_zero == false)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    }

    return 0;
        
        
}
