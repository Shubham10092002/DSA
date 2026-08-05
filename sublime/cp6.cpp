#include<bits/stdc++.h>
using namespace std;



vector<int> prevSmallerElement(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        //left to right -> prev smaller
        for(int i=0; i<input.size(); i++) {
                int curr = input[i];

                //apka answer stack me 
                while(s.top() != -1 && input[s.top()] >= curr) {
                        s.pop();
                }

                //chotta element mil chuka h -> ans store
                ans[i] = s.top();

                //push krdo curr element ko
                s.push(i);
        }
        return ans;
}

int main(){

        vector<int>input={2,6,4,8,5,1,6};

        vector<int> ans=prevSmallerElement(input);

        for(int i=0; i<input.size(); i++){
                cout << ans[i] << " ";
        }

        return 0;
}