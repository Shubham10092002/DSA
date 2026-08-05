/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


    int maxDepth(TreeNode* root) {
        if(root == NULL) 
		return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }

    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) 
        return 0;

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + 1 + maxDepth(root->right);
        int ans = max(op1, max(op2, op3));
        return ans ;
    }

//optimal approach

int d=0;
int diameter(TreeNode* root){
    if(root==NULL)
        return 0;

   int lefth= diameter(root->left);
   int righth= diameter(root->right);

  int currD=lefth+righth;
        d=max(currD,d);
        return max(lefth ,righth)+1;

    
};

//optimise solution
class Solution {
  public:
    
     int fun(Node* root,int &ans){
        if(root==NULL)
            return(0);
        int l=fun(root->left,ans);
        int r=fun(root->right,ans);
        
        ans=max(ans,1+l+r);
        return(1+max(l,r));
        
    }
    
    
    int diameter(Node* root) {
        int ans=0;
        int h=fun(root,ans);
        return(ans);
        
    }
};


#include <algorithm>  // For max function

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int diameterUtil(Node* root, int &diameter) {
    if (root == NULL) {
        return 0;  // If the node is NULL, return height as 0
    }

    // Recursively get the height of the left and right subtrees
    int leftHeight = diameterUtil(root->left, diameter);
    int rightHeight = diameterUtil(root->right, diameter);

    // Update the diameter if the current path (leftHeight + rightHeight) is larger than the current diameter
    diameter = std::max(diameter, leftHeight + rightHeight);

    // Return the height of the current node
    return 1 + std::max(leftHeight, rightHeight);
}

int diameter(Node* root) {
    int diameter = 0;
    diameterUtil(root, diameter);
    return diameter;
}



