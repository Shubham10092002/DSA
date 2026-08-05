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
	cout << "Enter the data" << endl;

	int data;
	cin >> data;
	 root= new node(data);
	 if(data==-1){
	 	return NULL;
	 }

	 cout << "enter the data for inserting in left" << endl;
	 root->left=buildtree(root->left);
	 cout << "Enter the data for inserrting right of tree " << endl;
	 root->right=buildtree(root->right);
		return root;
}	

void levelordertraversal(node *root){
		queue<node*>q;
		q.push(root);

		while(!q.empty()){
			node *temp=q.front();
			cout << temp->data << " ";
			q.pop();

			if(temp->left){
				q.push(temp->left);

			}

			if(temp->right){
				q.push(temp->right);
			}
			
		}

}

void inorder(node* root){

	// base case
	if(root==NULL)
		return;

	 //LNR
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(node* root){

	//base

	if(root==NULL)
		return;

	//NLR

	cout << root ->data << " ";
	preorder(root->left);
	preorder(root>right);

}

void postorder(node* root){

	//base
	if(root==NULL)
		return;

	//LRN
postorder(root>left);
postorder(root->right);
cout << root ->data << " ";

}

int height(node* root){
	if(root==NULL)
		return 0;

	int leftheight=height(root->left);
	int rightheight=height(root->right);
	int ans=max(rightheight,leftheight)+1;
	return ans;
}

int main(){
	node *root=NULL;
	root=buildtree(root);

	levelordertraversal(root);
	inorder(root);

	cout << "height: " << height(root) << endl; 

}	