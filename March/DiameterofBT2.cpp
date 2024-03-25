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
pair<int,int>diam(TreeNode* root)
{
  if(root==NULL)
        {
            return {0,0};

        }
        pair<int,int>l=diam(root->left);
        pair<int,int>r=diam(root->right);
        int op1=l.first;
        int op2=r.first;
        int op3=l.second+r.second+1;

        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(l.second,r.second)+1;
return ans;
}
    int diameterOfBinaryTree(TreeNode* root) 
    {
      return diam(root).first-1;
    }
};
