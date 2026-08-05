#include<bits/stdc++.h>
using namespace std;

void printsubarray_util(vector<int>nums,int start,int end){
    if(end>=nums.size()){

        if(start+1 <=nums.size()-1)
            printsubarray_util(nums,start+1,start+1);

        else{
            return;
        }
    }

    for(int i=start; i<=end; i++){
        cout << nums[i] <<" " ;
    }

    cout << endl;


    printsubarray_util(nums,start,end+1);

}


/*void printsubarray(vector<int>nums){
    for(int start=0; start<nums.size(); start++){
        int end=start;
        printsubarray_util(nums,start,end);
    }
}
*/
int main(){
    vector<int>nums={1,2,3,4,5};

    printsubarray_util(nums,0,0);

    return 0;



}
