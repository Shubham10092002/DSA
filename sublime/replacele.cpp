#include<bits/stdc++.h>

using namespace std;

  class compare{
    public:
    
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.first>b.first;
    }
    
};
vector<int> replaceWithRank(vector<int> &arr, int N){
        vector<int>temp (N, 0);
        

          priority_queue<pair<int,int>, vector<pair<int,int>>,compare> pq;
          
          for(int i=0; i<N; i++){
              pair<int,int> p = make_pair(arr[i],i);
              pq.push(p);
          }
          
          int prevele=-1;
          int prevrank = -1;
          int rank = 0;
          
          
          while(!pq.empty()){
              pair<int, int> topele = pq.top();
              pq.pop();
              int currele = topele.first;
              int index = topele.second;
              
              if(currele == prevele){
                  temp[index] = prevrank;
              }
              else{
                  rank++;
                  temp[index]=rank;
                  
              }
              prevele = currele;
              prevrank =rank;
              
          }
          
          return temp;

    }


int main(int argc, char const *argv[])
{
	/* code */

	int n ; 
	 cin >> n; 
	 vector<int>arr(n);

	 for(int i=0; i<n; i++){
	 	cin >> arr[i];
	 }


	 vector<int> ans = replaceWithRank(arr, n);
	 for(int i=0; i<n; i++){
	 	cout << ans[i] << " ";
	 }
	return 0;
}