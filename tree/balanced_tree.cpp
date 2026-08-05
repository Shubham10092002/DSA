
//timecomplexity o(n)
class solution{
public:

		bool isbalanced=true;

	int height(treenode* root){
		if(root==NULL)

			return 0;

		int lh=height(root->left);
		int rh=height(root->right);

		//check for current node
		if(isbalanced && abs( lh - rh > 1))
			isbalanced=false;

		return max(lh,rh)+1;
		
	}

	bool isBalanced(treenode* root){
		height(root);
		return isbalanced;
	}
};


//diagonal traversal


vector<int> diagonal(node* root){

	vector<int> ans;
	if(!root) return ans;
	queue<node*>q;
	q.push(root);
	while(!q.empty()){

		node* temp=q.front(); q.pop();

		while(temp){
			ans.push_back(temp->data);
			if(temp->left)
				q.push(temp->left);

				temp=temp->right;
		}

	}

	return ans;

}

//diagonal traversal using map

vector<int> diagonal(node* root){

	map<int , vector<int> >mp;
	int curr=0;

	if(root->left){
		curr++;
		mp[curr]
	}
}




//maximum sum of non adjacent node
class Solution{
  public:
  pair<int,int> maxsum(Node* root){
      if(!root)
        return {0,0};
        
        auto leftsum =  maxsum(root->left);
        auto rightsum = maxsum(root->right);
        int a = root->data + leftsum.second + rightsum.second;
        int b = max(leftsum.first,leftsum.second) + max(rightsum.first,rightsum.second);
        return {a,b};
  }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        auto ans = maxsum(root);
        
        return max(ans.first,ans.second);
    }
};




// Sum of nodes on the longest path from root to leaf node

// Difficulty: MediumAccuracy: 52.39%Submissions: 106K+Points: 4
// Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. 
// If two or more paths compete for the longest path, 
// then the path having maximum sum of nodes will be considered.



pair<int,int> height(Node* root){
    if(root  == NULL)
        return {0,0};
    
    int sum = root->data;
    
    auto  leftheight = height(root->left);
    auto rightheight = height(root->right);
    
    
    if(leftheight.first == rightheight.first){
        sum +=leftheight.second > rightheight.second?leftheight.second : rightheight.second;
    }
    
    else if(leftheight.first > rightheight.first){
        sum += leftheight.second;
    }
    
    else{
        sum += rightheight.second;
    }
    
    return {max(leftheight.first , rightheight.first) + 1, sum};
    
}
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        auto h = height(root);
        return h.second;
    }