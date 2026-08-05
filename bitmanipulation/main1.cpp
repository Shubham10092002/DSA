// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.
//   Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
 __builtin_Popcount(num);

  int singleNumber(vector<int>& nums) {
        int result  =0;
        for(int i=0; i<32; i++){
            int temp = (1 << i);

            int countzeros=0, countones =0;
            for(int &num : nums){
                if((num & temp) == 0){
                    countzeros++;
                }
                else{
                    countones++;
                }
            }

            if((countones%3) == 1){
                result = (result | temp);
            }
        }

        return  result;

    }

    //Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
    //ans[i] is the number of 1's in the binary representation of i.
    int countsetbit(int num){
    int count =0;
    while(num!=0){
        if(num & 1)
        count++;
        num = num>>1;
    }
    return count;
}
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        if( n== 0)
            return {0};
        for(int i=0; i<=n; i++){
            //ans.push_back(__builtin_popcount(i));
            //int count = countsetbit(i);
            //ans.push_back(count);
            if(i%2!=0){
                ans[i] = ans[i/2] + 1;
            }
            else{
                ans [i] = ans[i/2];
            }
        }
        return ans;
    }


//     You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:

// pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
// Note that ^ denotes the bitwise-xor operation.

// It can be proven that the answer is unique.

 

// Example 1:

// Input: pref = [5,2,0,3,1]
// Output: [5,7,2,3,2]
// Explanation: From the array [5,7,2,3,2] we have the following:
// - pref[0] = 5.
// - pref[1] = 5 ^ 7 = 2.
// - pref[2] = 5 ^ 7 ^ 2 = 0.
// - pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
// - pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.
// Example 2:


     vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        ans.push_back(pref[0]);
        for(int i= 1; i<pref.size(); i++){
            int ele = pref[i] ^ pref[i-1];
            ans.push_back(ele);
        }
        return ans;
    }


    //find the number which appeaar single times

    int singlenumber(vector<int> &nums){
        int result = 0 ;
        for(int i=0; i<32; i++){
            int temp = (1<<i);

            int countones = 0;
            for(auto num : &nums){
                if((nums & temp ) == 1)
                    countones++;
            }

            if(countones % 3 == 1){
                result = (result | temp);
            }
        }

        return result;

    }
    // count the sets bit
    int countsetbit(int n){
        int count =0;
        while(n!=0){
            if((n & 1))
                count++;

            n = n >> 1;
        }
        return count;
    }

    vector<int> setbit(int n){
        vector<int> ans(n+1);

        if(n == 0)
            return {0};

        for(int i=0; i<=n; i++){
            //ans.push_back(__builtin_popcount(i));
            int count = countsetbit(i);
            ans.push_back(count);
        }
        return ans;
    } 