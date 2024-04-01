
https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/













________________________________________________________________________________________________________________________________________________________________________________________________


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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        bool prev=false;
        q.push(root);
        while(!q.empty())
        {
          TreeNode* node=q.front();
          q.pop();
          if(node==NULL)
          {
            prev=true;
          }
          else{
            if(prev==true)
            {
                return false;

            }
              q.push(node->left);
                q.push(node->right);
          }
        }
        return true;
    }
};
