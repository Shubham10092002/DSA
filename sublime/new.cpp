// #include <iostream>
// #include<vector>
// #include<limits.h>
// using namespace std;

// /*
// int solve(vector<int>& arr, int target) {
//   //base case
//   if(target == 0) {
//     return 0;
//   }
//   if(target < 0) {
//     return INT_MAX;
//   }

//   //let's solve 1 case
//   int mini = INT_MAX;
//   for(int i=0; i<arr.size(); i++) {
//     int ans = solve(arr, target - arr[i]);
//     if(ans != INT_MAX)
//     mini = min(mini, ans + 1);
//   }

//   return mini;

// }

// int main() {
//   vector<int> arr{1,2};
//   int target = 5; 

//   int ans = solve(arr, target);
//   cout << "Answer is: " << ans << endl;
//   return 0;
// }*/



// //solving using dp






// int solve(vector<int>& arr, int target,vector<int> &dp) {
//   //base case
//   if(target == 0) {
//    // dp[0]=0;
//     return 0;
//   }
//   if(target < 0) {
//     return INT_MAX;
//   }
//   if(dp[target]!=-1)
//     return dp[target];

//   //let's solve 1 case
//   int mini = INT_MAX;
//   for(int i=0; i<arr.size(); i++) {
//     int ans = solve(arr, target - arr[i],dp);
//     if(ans != INT_MAX)
//         mini = min(mini, ans + 1);
   
//   }
  
//   dp[target] = mini;
//   //return mini;
//   return dp[target];
// }

// int main(){
//  // vector<int>arr=

 

//  vector<int> arr{1,2};
//   int target = 5; 
//    vector<int> dp(target+1,-1);

//   int ans = solve(arr, target ,dp);
//   if(ans == INT_MAX){
//     ans=-1;
//   }

//   cout << "Answer is: " << ans << endl;
//   return 0;
// }






// bool bfscycycliccheck(unordered_map<int, list<int > > adjList, int src, 
//   unordered_map<int, bool>& visited){
//   queue<int>q;

//   unordered_map<int, int>parent;
//   q.push(src);
//   visited[src] = true;
//   parent[src] = -1;

//   while(!q.empty()){
//     int topnode = q.front();
//     q.pop();

//     for(auto nbr: adjList[topnode]){
//       if(!visited[nbr]){
//         q.push(nbr);
//         parent[nbr] = topnode;
//         visited[nbr] = true;
//       }
//       else if(visited[nbr] && nbr != parent[topnode])
//         return true;
      
//     }

//   }

//   return false;

// }





// bool dfscycliccheck(unordered_map<int, list<int > > adjList, int src, 
//   unordered_map<int, bool>& visited,int parent){
//    visited[src] = true;

//    for(auto nbr: adjList[src]){
//     if(!visited[nbr]){
//       bool ans = dfscycliccheck(adjList, nbr,visited,src);

//       if(ans == true)
//         return true;
//     }
//   else if(visited[nbr] && nbr != parent)
//     return true;
//    }


//    return false;
// }







// bool dfsdirectedcycliccheck(unordered_map<int, list<int > > adjList, int src,
//   unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsvisited){


//   visited[src] = true;
//   dfsvisited[src] = true;

//   for(auto nbr : adjList[src]){
//     if(!visited[nbr]){
//       bool ans =dfsdirectedcycliccheck(adjList,src,visited,dfsvisited);
//       if(ans == true)
//       return true;

//     }
//     else if(visited[nbr] && dfsvisited[nbr])
//       return true;
//   }

//   return false;
// }



#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans,int index){
	if(index >= nums.size()){

		ans.push_back(nums);
		return;
	}

	for(int j =index; j<nums.size(); j++){
		swap(nums[index], nums[j]);
		solve(nums, ans, index+1);
		swap(nums[index], nums[j]);
	}
}


vector<vector<int>> permutation(vector<int> &nums){
	vector<vector<int>> ans;
	int index =0;
	 solve(nums,ans, index);

	 return ans;
}


int main(){
	vector<int> nums;
	int size ;
	cin >> size;
	for(int i=0; i<size; i++){
		cin >> nums[i];
	}

	sort(nums.begin(),nums.end());
	
	vector<vector<int>> ans = permutation(nums);

	for(int i=0; i<ans.size();i++){
		for(int j=0; j<ans[0].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}