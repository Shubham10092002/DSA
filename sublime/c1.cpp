
//first and last index of target and  totaloccurance 

/*#include<bits/stdc++.h>
using namespace std;

int firstindex(int arr[], int n, int key){

    int s=0,e=n-1;

    int mid=s+(e-s)/2;

    int ans=-1;

    while(s<=e){

            if(arr[mid]==key){
                ans=mid;
                e=mid-1;
            }


            else if(key>arr[mid])
                s=mid+1;

            else if(key<arr[mid])
                e=mid-1;

                mid=s+(e-s)/2;

    }

    return ans;


}




int lastindex(int arr[],int n,int key){

        int s=0,e=n-1;
        int mid=s+(e-s)/2;
        int ans=-1;

        while(s<=e){

            if(arr[mid]==key)
            {
                ans=mid;
                s=mid+1;
            }

            else if(arr[mid]<key)
                    s=mid+1;

            else if(arr[mid]>key)
                    e=mid-1;

                mid=s+(e-s)/2;
        }

        return ans;


}


int main(){

    int n,key,last_index,first_index,totaloccurance;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }


    cin >> key;

    last_index=lastindex(arr,n,key);


    if(last_index==-1)
        cout << "key value not present "<< endl;
    else 

        cout << last_index << endl;


        first_index=firstindex(arr,n,key);


        if(first_index==-1)
            cout << "key value is not present "<< endl;

        else

            cout  << first_index << endl;

        totaloccurance=last_index-first_index;

        cout << totaloccurance + 1 << endl;



        return 0;


    
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n; i++){
        cin >> arr[i];
    }

    set<int>s;

    for(int i=0;i<n; i++){

        int x;
        x=arr[i];
        s.insert(x);

    }
    cout << s.size() << endl;



    return 0;
    }*/

/*#include<iostream>
using namespace std;

int main(){

    int p[4][4];
    
    for(int i=1; i <4; i++){

    for(int j=1;j<4; j++){

        cin >> p[i][j];
    }

}
int i=2, j=3;
p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+p[i][j];
cout << p[i][j] << endl;

    return 0;
}
*/


#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int d){

        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

node* buildtree(node* root){
    //cout << "Enter the data" << endl;

    int data;
    cin >> data;
     root= new node(data);
     if(data==-1){

        return NULL;
        
     }
    // cout << "enter the data for inserting in left" << endl;

     root->left=buildtree(root->left);

    // cout << "Enter the data for inserting right of tree " << endl;

     root->right=buildtree(root->right);
        return root;

}



void diagonal(node* root ,map<int,vector<int>>&mp,int level){
    if(root==NULL)
    return;

    mp[level].push_back(root->data);
    
        diagonal(root->left,mp,level+1);
    
   
        diagonal(root->right,mp,level);
    
}


int main(){
    node* root;
    root = buildtree(root);
    map<int,vector<int>>mp;
    int level=0;
    diagonal(root,mp,level);
    for(auto it: mp){
        cout << "Level " <<it.first ;
        for(auto i:it.second){
            cout << i <<" ";
            
        }
        cout << endl;
    }
    return 0;
}