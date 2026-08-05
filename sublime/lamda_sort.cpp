#include<bits/stdc++.h>
using namespace std;


int findOnebits(int a){
	return __builtin_popcount(a); //O(1)
}

int main(){
	vector<int>temp = {2,6,8,4,7,3,5};

	// auto lambda = [](int &a, int &b){
	// 	//return a<b; // asce
	// 	//return b>a//desc
	// 	int CA = findOnebits(a);
	// 	int CB= findOnebits(b);

	// 	if(CA == CB){
	// 		return a < b; // asce
	// 	}


	// 	return CA < CB;  // asce on basis of int
	// };

	auto lambda = [] (pair<int, int> &a, pair<int, int> &b){

			if(a.first == b.first){
				return a.second > b.second;
			}

			return a.first > b.first;
	};


priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lambda)> pq(lambda);
	sort(temp.rbegin(), temp.rend() );


	// for(int i= 0; i <5; i++){
	// 	int freq ;
	// 	cin >> freq;
	// 	int ele;
	// 	cin >> ele;
	// 	pair<int, int> p =make_pair(freq, ele);
	// 	pq.push(p);
	// }

	pq.push({1, 10});
    pq.push({2, 5});
    pq.push({3, 20});
	pq.push({1,8});
	pq.push({1, 12});



	while(!pq.empty()){
		pair < int, int> p = pq.top();
		pq.pop();

		int freq = p.first;
		int ele = p.second;

		cout << freq << " " << ele << endl;
	}

	cout << endl;

	for(int i=0; i<temp.size(); i++){
		cout << temp[i] << " ";
	}

	cout << endl;
	return 0;
}


// #include <queue>
// #include <vector>
// #include<iostream>

// using namespace std;
// int main() {
//     // Compare pairs by their second element (min-heap)
//     auto pair_cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
//         return a.second > b.second;
//     };

//     std::priority_queue<
//         std::pair<int, int>,
//         std::vector<std::pair<int, int>>,
//         decltype(pair_cmp)
//     > pq(pair_cmp);

//     pq.push({1, 5});
//     pq.push({2, 3});
//     pq.push({3, 7});

//     while(!pq.empty()){
//     	cout << pq.top().first << " "<< pq.top().second << endl;
//     	pq.pop();
//     }

//     // Order: {2,3}, {1,5}, {3,7}
//     return 0;
// }