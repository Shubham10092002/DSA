#include<bits/stdc++.h>
using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
   // int ans=-1;
    int n=gas.size();
    int count=0;
    int maxi=0;
    int index=-1;
     int totalgas=0;


    for(int i=0; i < n; i++){
        if( (gas[i] - cost[i] ) > maxi){
            index=i;
            totalgas=gas[i];
        }
    }


    if(index==-1){
        return -1;
    }
    
    int i=index;
   
    while(count< n){

       if(totalgas >=cost[i]){
           totalgas=totalgas-cost[i];
           i++;
           count++;

           if(i>=n){
               i=0;
               totalgas+=gas[i];
           }

           else{ 
             //  totalgas=totalgas-cost[i];
                totalgas+=gas[i];
           }
       }


       else{
           index=-1;
           count=n;
       }

      
    }
    
    return index;


    }


int main(){ 

	/*int arr[]={2,5,8,9,6};

	int diff_arr[6]={0};

	for(int i=0;i<5; i++){
		if(i==0)
			diff_arr[i]=arr[i];

		else{
			diff_arr[i]=arr[i]-arr[i-1];
		}
	}


	int q;
	cin >> q;

	while(q--){
		int l,r,k;

		cin >> l >> r >> k;

		diff_arr[l]+=k;
		diff_arr[r+1]-=k;

	}


	for(int i=0; i<5; i++){
		if(i==0){
			diff_arr[i]=diff_arr[i];
			cout<<diff_arr[i] << " ";

		}


	else{
			diff_arr[i]+=diff_arr[i-1];
			cout << diff_arr[i] << " ";		
		}
	}*/

/*char num='c';
int c=num;

cout << c << " " << endl;
cout << "hello world";*/

	vector<int> gas = {1,2,3,4,5};
	vector<int> cost = {3,4,5,1,2};


cout << canCompleteCircuit( gas, cost) << endl;
	return 0;
} 


