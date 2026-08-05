// 621. Task Scheduler


// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. 
// Each CPU interval can be idle or allow the completion of one task. 
// Tasks can be completed in any order, but there's a constraint: 
// there has to be a gap of at least n intervals between two tasks with the same label.

// Return the minimum number of CPU intervals required to complete all tasks.

 

// Example 1:

// Input: tasks = ["A","A","A","B","B","B"], n = 2

// Output: 8

// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

// After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

// Example 2:

// Input: tasks = ["A","C","A","B","D","B"], n = 1

// Output: 6




class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       

        vector<int>mp(26,0);

        for(char &ch : tasks){
            mp[ch -'A']++;
        }
        int time =0;

        
        priority_queue<int>pq;
        for(int i=0; i<26; i++){
            if(mp[i]>0){
                pq.push(mp[i]);
            }
        }

        while(!pq.empty()){
            vector<int> temp;

            for(int i=1; i<=n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &f: temp){
                if(f>0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                time+=temp.size();

            }else{
               time += n+1;
            }
        }

        return time;
        
        
    }
};