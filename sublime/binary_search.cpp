#include <bits/stdc++.h>
using namespace std;

int minelement(vector<int> &arr)
{
	int low = 0;

	int high = arr.size() - 1;

	int mid, minele = INT_MAX;
	int index;

	while (low <= high)
	{

		mid = low + (high - low) / 2;

		if (arr[mid] >= arr[low])
		{
			if (minele > arr[mid])
			{
				minele = min(minele, arr[low]);
				index = low;
			}

			low = mid + 1;
		}
		else
		{

			if (minele > arr[mid])
			{
				minele = arr[mid];
				index = mid;
			}
			// minele=min(minele,arr[mid]);
			// index=mid;
			high = mid - 1;
		}
	}

	// return minele;
	return index;
}

int main()
{

	vector<int> arr = {3, 4, 5, 1, 2};

	int ans = minelement(arr);
	cout << ans << endl;

	return 0;
}
