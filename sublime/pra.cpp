

/*#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, vector<int> &nums)
{
	unordered_map<int, int> mp;
	int ans = 0;

	for (int i = 0; i < k; i++)
	{
		mp[nums[i]]++;
	}
	int i = 1;
	while (ans < n)
	{

		if (mp.find(i) == mp.end())
		{
			ans++;
		}
		i++;
	}

	return ans;
}

int main()
{
	//	vector<int> nums ={};

	cout << "hello world" << endl;
	cout << "count number" << endl;
	int i = 1;

	while (i <= 10)
	{
		cout << i << " ";
		i++;
	}
	cout << " kaise ho" << endl;
	return 0;
}*/
//calculating all problems on windows lap-top 

#include <iostream>
#include<vector>
using namespace std;

void printSubsequences(string str, int n, string output, int i, vector<string>& v) {
  //base case
  if(i == n ) {
    v.push_back(output);
    return;
  }

  //include
  printSubsequences(str,n, output + str[i], i+1,v);

  //exclude
  printSubsequences(str,n, output, i+1,v);


}

int main() {
  string str = "abcd";
  string output = "";
  vector<string> v;
  int i = 0;
  int n = str.length();
  printSubsequences(str,n, output, i, v);

  cout << "Printing all subsequences " << endl;
  for(auto val: v) {
    cout << val << " " ; 
  }

  cout << endl << "Size of vector is: " << v.size() << endl;

  return 0;
}

