class Solution {
public:
    // this function will calculate the sum for the current element subtree
    void average(TreeNode* node, int& ans)
    {
        int sum=0;                       // it will calculate the subtree sum for current node#
        int cnt=0;                       // it will store the number of values that are present in subtree
        
        // pushing current node to the queue
        queue<TreeNode*> q;
        q.push(node);
        
        // BFS
        while(!q.empty())
        {
            int s = q.size();
            
            // iterating over q size
            for(int i=0;i<s;i++)
            {
                // extracting the queue's front element
                TreeNode* nod = q.front();
                q.pop();
                
                // after taking the elemets , add that val into the sum and incraese the value's cnt by 1
                sum += nod->val;
                cnt++;
                
                // check for current node left and right
                if(nod->left)
                    q.push(nod->left);
                if(nod->right)
                    q.push(nod->right);
            }
        }
        if(sum/cnt==node->val)
            ans++;
    }
    
    // this function will make sure to iterate all the nodes
    int averageOfSubtree(TreeNode* root) 
    {
        // we have to traversal all the given tree and for each node we have to traverse it's own subtree
        // so we can use both BFS & DFS here 
        // so we will solve this problem by using BFS 
        
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        // BFS
        while(!q.empty())
        {
            // extracting the size of the queue
            int s = q.size();
            
            // now check for the elements that avaliable in queue
            for(int i=0;i<s;i++)
            {
                // taking out the front element
                TreeNode* node = q.front();
                q.pop();
                
                // call the function for current node and calculate its avg
                average(node,ans);
                
                // after counting the avg's chech there is left or right available 
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
