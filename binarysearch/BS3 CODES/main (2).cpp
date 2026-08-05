#include <iostream>
using namespace std;

int solve(int dividend, int divisor) {
  int s = 0;
  int e = abs(dividend);
  int ans = 0;
  int mid = s + (e-s)/2;
  
  while(s <= e) {
    //perfect solution
    if( abs(mid*divisor) == abs(dividend)) {
      ans = mid;
      break;
    }
    //not perfect sol
    if(abs(mid*divisor) > abs(dividend)) {
      //left
      e = mid - 1;
    } 
  else {
      //ans store
      ans = mid;
        //right search
      s = mid + 1;
    }
    mid = s + (e-s)/2;
  }

  if((divisor<0 && dividend<0) || (divisor>0 && dividend>0))
    return ans;
  else {
    return -ans;
  }

}

int main() {
  int dividend = -21;
  int divisor = -7;

  int ans = solve(dividend, divisor);
  cout << "Ans is-> " << ans << endl;
  return 0;
}



// Problem statement
// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



// You are also given an integer 'k' which denotes the number of aggressive cows.



// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



// Print the maximum possible minimum distance.



// Example:
// Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

// Output: 2

// Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
// Sample Input 1 :
// 6 4
// 0 3 4 7 10 9


// Sample Output 1 :
// 3




bool isassigning(vector<int> &stalls,int &mid,int &k){
    int count = 1;
    int next_stall = stalls[0];

    for(int i =1; i<stalls.size(); i++){
        if(next_stall + mid <= stalls[i]){
            next_stall = stalls[i];
            count++;
        }
    }
    if(count>=k)
        return true;
    else 
        return false;
}





int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.

     if(k>stalls.size())
     return 0;

    int s = 0;
    int e = *max_element(stalls.begin(), stalls.end());
    int ans = 0;
     sort(stalls.begin(),stalls.end());

     while(s<=e){
         int mid = s + (e-s)/2;

         if(isassigning(stalls, mid, k)){
             s = mid+1;
             ans = mid;
         }
         else{
             e = mid - 1;
         }
     }

     return ans;
}
