class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL)
            return NULL;

        //check for p and q;
        if(root->val == p->val)
            return p;
        if(root->val == q->val)
            return q;
        
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns == NULL && rightAns == NULL)
            return NULL;
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else{
            return root;
        }
    }

};
// //burning tree
// Given a binary tree and a node data called target. 
// Find the minimum time required to burn the complete binary tree 
// if the target is set on fire. 
// It is known that in 1 second all nodes connected to a given node get burned. 
// That is its left child, right child, and parent.
// Note: The tree contains unique values.
class Solution {
  public:
  Node* solve(Node* root,  unordered_map<Node*,Node*>&parentmap,int target){
      queue<Node*>q;
      Node* targetnode = 0;
      q.push(root);
      parentmap[root] = 0;
      while(!q.empty()){
          Node* front = q.front();
          q.pop();
          if(front->data == target){
              targetnode = front;
          }
          if(front ->left){
              q.push(front->left);
              parentmap[front->left] = front;
          }
           if(front ->right){
              q.push(front->right);
              parentmap[front->right] = front;
          }
      }
      
      return targetnode;
  }
    
    
   int burnthetree(Node* targetnode,unordered_map<Node*,Node*>&parentmap) {
       unordered_map<Node* , bool>isburnt;
       queue<Node*>q;
       q.push(targetnode);//currently set on fire
       int t = 0;
       isburnt[targetnode] =1;

       while(!q.empty()){
           int size = q.size();
           bool isfirespreaded =0;
           
           for(int i=0; i<size; ++i){
            
               Node* front = q.front();
               q.pop();
               if(front->left && !isburnt[front->left]){
                   q.push(front->left);
                   isburnt[front->left] =1;
                   isfirespreaded =1 ;
                   
               }
               
               if(front->right && !isburnt[front->right]){
                   q.push(front->right);
                   isburnt[front->right] =1;
                   isfirespreaded =1 ;
                   
               }
               
               if(parentmap[front] && !isburnt[parentmap[front]]){
                    q.push(parentmap[front]);
                   isburnt[parentmap[front]] =1;
                   isfirespreaded =1 ;
               }
               
              
           }
            if( isfirespreaded ) ++t;
       }
       
       return t;
   }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>parentmap;
        
        //make node to parrent mapping and find target node
        Node* targetnode = solve(root,parentmap,target);
        
        return burnthetree(targetnode,parentmap);
    }