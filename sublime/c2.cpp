
#include <iostream>
#include <vector>

std::vector<int> find_permutation(int n)
{
    if (n == 1)
    {
        return {1};
    }
    else if (n == 2)
    {
        return {-1};
    }
    else
    {
        std::vector<int> permutation;
        permutation.push_back(n);
        for (int i = 1; i < n; i++)
        {
            if (i % 2 == 1)
            {
                permutation.push_back(i);
            }
            else
            {
                permutation.insert(permutation.begin() + 1, i);
            }
        }
        if (n % 2 == 0)
        {
            permutation.push_back(n - 1);
        }
        else
        {
            permutation.insert(permutation.begin() + 1, n - 1);
        }
        return permutation;
    }
}

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
        std::vector<int> permutation = find_permutation(n);
        if (permutation[0] == -1)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << permutation[j] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

/*
int binarysearch(vector<int>nums,int s,int e, int target){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(nums[mid]==target)
            return mid;

        else if(nums[mid]>target){
                e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

 int exponantialsearch(vector<int>nums,int n,int target){
    if(nums[0]==target) return 0;

    int i=1;

    while(i<n && nums[i] <=target){
        i*=2;
    }
    return binarysearch(nums,i/2,min(i,n-1),target);
 }



int main(){
    vector<int> nums={2,4 ,5,6 ,8,10,12,15,16   };

    int n=nums.size();
    int target= 10;
    int ans=exponantialsearch(nums,n,target);
    cout << ans << endl;
    vector<vector<int>>v={{1,2},{4,5},{6,8}};
    int ans2=v.size();
    cout << endl << ans2 << endl;
}*/

int solve(vector<int> a, vector<int> b, int n)
{

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            count++;
            a[i] = b[i];
            int k = n - 1;
            while (k > i)
            {
                a[k] = a[k - 1];
                k--;
            }
        }
    }

    cout << count << endl;

    return count;
}
