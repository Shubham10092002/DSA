#include <bits/stdc++.h>

using namespace std;

/*
void checkKey(string& str,int i, int& n, char& key, int& count) {
        //base case
        if(i >= n) {
                //key not found
                return ;
        }
        //1 case solve krdo
        if(str[i] == key) {
                ///store in vector
              //ans.push_back(i);
              count++;
        }
               
        //baaki recursion sambhal lega
        checkKey(str, i+1, n, key, count);
}

int main() {
        string str = "lovebabbar";
        int n = str.length();

        char key = 'b';

        int i = 0;
        //vector<int> ans;
        int count = 0;

        checkKey(str,i, n, key, count);
        cout << count << endl;
        // cout << "printing ans" << endl;
        // for(auto val: ans) {
        //         cout << val << " " ;
        // }
        // cout << endl;
        

        return 0;
}

*/

/*

int atmost(vector <int> nums, int goal){
        if(goal<0)
            return 0;

        int count=0;
        int i=0,r=0;
        int ans=0;

        while(r<nums.size()){
            count+=nums[r];

            while(count > goal){
                count = count - nums[i];
                i++;
            }

            ans+=r-i+1;
               r++;
        }

        return ans;
    }

  int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atmost(nums,goal) - atmost(nums,goal-1);

    }
*/
int characterReplacement(string s, int k) {

        int i=0,j=0;
        int ans=1;
        int maxcount=0;

        unordered_map<char,int>mp;

        while(i<s.size()){
                
                mp[s[i]]++;
                maxcount = max(maxcount ,mp[s[i]]);

                while(i-j+1 - maxcount > k){
                        mp[s[j]]--;
                        j++;
                        
                }
                ans= max(ans,i-j+1);
                i++;
        }

        return ans;
        
    }


    int main(){

       /* vector<int> nums = {1,0,1,0,1};
        int goal = 2;
         int ans = numSubarraysWithSum(nums,goal);
         cout << ans << " ";*/

        string s = "ABAB" ;
        int k = 2;

        int ans = characterReplacement(s,k);
         cout << ans << " ";

         return 0;
    }