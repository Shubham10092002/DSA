#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<limits.h>
using namespace std;


class graph {
	public:
	unordered_map<int, list<pair<int,int> > > adjList;

	void addEdge(int u, int v, int wt, bool direction) {
		//direction = 1 -> undirected graph
		//direction => 0 -> directed graph;
		adjList[u].push_back({v,wt});
		if(direction == 1) {
			adjList[v].push_back({u,wt});
		}
	}

	void printAdjList() {
		for(auto i: adjList) {
			cout << i.first <<"-> ";
			for(auto j: i.second) {
				cout << "(" << j.first<<", "<<j.second<<"), ";
			}
			cout << endl;
		}
	}

	void shortestPathBfs(int src, int dest) {
		queue<int> q;
		unordered_map<int,bool> visited;
		unordered_map<int,int> parent;

		//inital steps for src
		q.push(src);
		visited[src] = 1;
		parent[src] = -1;

		while(!q.empty()) {
			int fNode = q.front();
			q.pop();

			for(auto nbr: adjList[fNode]) {
				if(!visited[nbr.first]) {
					q.push(nbr.first);
					visited[nbr.first] = 1;
					parent[nbr.first] = fNode;
				}
			}
		}

		//store path in ans, after traversing in the parent array
		vector<int> ans;
		int node = dest;
		while(node != -1) {
			ans.push_back(node);
			node = parent[node];
		}

		reverse(ans.begin(), ans.end());

		cout << "printing ANs: " << endl;
		for(auto i: ans) {
			cout << i<<", ";
		}
		cout << endl;
		
	}


	void topoSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& ans) {
		
		visited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour.first] ) {
				topoSortDfs(neighbour.first, visited, ans);
			}
		}

		//while returning, store the node in stack
		cout << "Pushing " << src << endl;
		ans.push(src);
	}

 	void shortestpathDfs(int dest, stack<int> topoOrder, int n) {
		vector<int> dist(n, INT_MAX);

		int src = topoOrder.top();
		topoOrder.pop();
		dist[src] = 0;


		for(auto nbr: adjList[src]) {
			if(dist[src] + nbr.second < dist[nbr.first]) {
				dist[nbr.first] = dist[src] + nbr.second;
			}
		}		
			

		while(!topoOrder.empty()) {

			int topElement = topoOrder.top();
			topoOrder.pop();

			if(dist[topElement] != INT_MAX) {
				for(auto nbr: adjList[topElement]) {
					if(dist[topElement] + nbr.second < dist[nbr.first]) {
						dist[nbr.first] = dist[topElement] + nbr.second;
					}
				}
			}
		}

		cout << "Printing Ans: " << endl;
		for(int i=0; i<n; i++) {
			cout << i <<"-> " << dist[i] << endl;
		}
		
		
	}

	void shortestDistDijkstra(int src, int n) {
		vector<int> dist(n,INT_MAX);
		set<pair<int,int> > st;
		//intiial steps
		dist[src] = 0;
		st.insert(make_pair(0,src));

		while(!st.empty() ) {
			//fetch the smallest or first eklement from set
			auto topElement = *(st.begin());
			int nodeDistance = topElement.first;
			int node = topElement.second;

			//pop from set
			st.erase(st.begin());

				//neighbour traverse
			for(auto nbr: adjList[node]) {
				if(nodeDistance + nbr.second < dist[nbr.first]) {  
					//mujhe distance update krna h 
					//finding entry in set
					auto result = st.find(make_pair(dist[nbr.first], nbr.first));
					//if found, then remove
					if(result != st.end()) {
						st.erase(result);
					}
					//updation in dist array and set
					dist[nbr.first] = nodeDistance + nbr.second;
					st.insert(make_pair(dist[nbr.first], nbr.first));
				}
			}  			
		}

		cout << "printing ans:" << endl;
		for(int i=0; i<n; i++) {
			cout << dist[i] <<", ";
		}cout << endl;
		
	}

};

int main() {
	graph g;

	g.addEdge(6,3,2,1);
	g.addEdge(6,1,14,1);
	g.addEdge(3,1,9,1);
	g.addEdge(3,2,10,1);
	g.addEdge(1,2,7,1);
	g.addEdge(2,4,15,1);
	g.addEdge(4,3,11,1);

	g.addEdge(6,5,9,1);
	g.addEdge(4,5,6,1);
 

	g.printAdjList();

	g.shortestDistDijkstra(6,7);

	// stack<int> topoOrder;
	// unordered_map<int, bool> visited;
	// g.topoSortDfs(0, visited, topoOrder);

	

	// g.shortestpathDfs(3, topoOrder,5);
	
	

	// int src = 0;
	// // int dest = 4;

	// g.shortestPathBfs(src, dest);


	return 0;
}


#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<algorithm> 

using namespace std;

class graph{
public:
	unordered_map<int, list<pair<int, int>>> adjlist;
	void addedge(int u, int v, int wt,bool direction){
		//direction = -> 1 undirected graph
		//direction 0 for directed graph
		adj[u].push_back({v,wt});
		if(direction == 0){
			adjlist[v].push_back({u,wt});
		}

	}

	void printadjlist(){
		for(auto i: adjList){
			cout << i.first << "->";
			for(auto nbr: i.second){
				cout << "(" << j.first << ", " << j.second<<"), ";			}
		}
	}

	void shortestPathBfs(int src, int dest ){
		queue<int> q;
		unordered_map<int, bool>visited;
		unordered_map<int,int> parent;
		q.push(src);
		visited[src] = true;
		parent[src]= -1;

		while(!q.empty()){
			int fnode = q.front();
			q.pop();
			for(auto nbr : adjlist[fnode]){
				if(!visited[nbr.first]){
					q.push(nbr.first);
					visited[nbr.first] = 1;
					parent[nbr.first] = fnode;
				}

			}
		}

vector<int> ans;
int node = dest;
while(node!=-1){
	ans.push_back(node);
	node = parent[node];
}

reverse(ans.begin(), ans.end());
cout << "shortestpath is : "
for(auto i: ans){
	cout<< i "-> ";
}


	}
};

int main(){
	graph g;

	return 0;
}


void topologySort(int src, unordered_map<int, bool> &visited, stack<int> &ans){
	visited[src] = true;

	for(nbr : adjlist[src]){
		if(!visited[nbr]){
			topologySort(nbr,visited, ans);
		}
	}

	ans.push(src);

}


void shortestpathDfs(int dest, int n, stack<int> toposort){
	vector<int> ans(n,INT_MAX);

	int src = toposort.top();
	toposort.pop();

	ans[src] = 0;

	for(nbr : adjlist[src]){
		ans[nbr.first] = nbr.second;
	}

	while(!toposort.empty()){
		int node = toposort.top();
		toposort.pop();

		// int node  = src.first;
		// int distance = ans[node];

		for(nbr : adjlist[node]){
			if(ans[node] + nbr.second < ans[nbr.first]){
				ans[nbr.first] = distance + nbr.second;
			}
		}
	}

}

 void shortestDistDijkstra(int src, int n) {
 	vector<int> dist(n, INT_MAX);

 	set<pair<int, int>> st;

 	st.insert({0,src});
 	dist[src] = 0;

 	while(!st.empty()){

 		auto topnode = *(st.begin());
 		int distance = topnode.first;
 		int src = topnode.second;

 		st.erase(st.begin());

 		for(nbr : adjlist[src]){
 			if(dist[src] != INT_MAX){
 				if(dist[src] + nbr.second < dist[nbr.first]){
 					

 					if(st.find({dist[nbr.first], nbr.first}) != st.end()){
 						st.erase({dist[nbr.first], nbr.first});
 					}
 					
 					dist[nbr.first] = dist[src] + nbr.second;
 					st.insert({dist[nbr.first], nbr.first});
 				}
 			}
 		}

 	}
 }