Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100






________________________________________________________________________________________________________


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
                vector<vector<int>>result;

   if(root==NULL)
        {
            return result;
        }


     
        queue<TreeNode*>q;
q.push(root);
bool ltor=true;
while(!q.empty())
{
    int s=q.size();
vector<int>ans(s);
for(int i=0;i<s;i++)
{
int index=ltor?i:s-i-1;
TreeNode* frontnode=q.front();
q.pop();
ans[index]=frontnode->val;

    if(frontnode->left!=NULL)
    {
        q.push(frontnode->left);
    }
        if(frontnode->right!=NULL)
    {
        q.push(frontnode->right);
    }
}
ltor=!ltor;
result.push_back(ans);
}
return result;
    }
};
