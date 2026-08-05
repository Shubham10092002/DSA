
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