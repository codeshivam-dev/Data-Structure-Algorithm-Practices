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
int ans;
    
    void solve(TreeNode* root, int maxi){
        if(!root) return;

        if(maxi <= root->val) {
            ans++;
        }

        maxi = max(maxi, root->val);

        solve(root->left, maxi);
        solve(root->right, maxi);

        return;
    }
    int goodNodes(TreeNode* root) {
        ans = 0;
        solve(root, root->val);

        return ans; 
    }
};