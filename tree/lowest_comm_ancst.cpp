/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //BASE CASE
        if(root==NULL)
        return NULL;


        //CASE 1
        if(root->val  > q->val  && root->val > p->val){
            return  lowestCommonAncestor( root->left,  p,  q);

        }
        //CASE 2
       if( root->val  < q->val  && root->val < p->val){
           return lowestCommonAncestor( root->right,  p,  q);
       }
        //CASE 3 AND 4 BOTH P AND Q IN OPPOSITE SIDE OF ROOT
        return root;
    }
};