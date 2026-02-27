

class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* node,
             int remainingSum,
             vector<int>& currentPath) {

        if (!node) return;

        // Choose current node
        currentPath.push_back(node->val);
        remainingSum -= node->val;

        // Check if leaf & sum satisfied
        if (!node->left && !node->right && remainingSum == 0) {
            result.push_back(currentPath);
        }

        // Explore children
        dfs(node->left, remainingSum, currentPath);
        dfs(node->right, remainingSum, currentPath);

        // Backtrack
        currentPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        vector<int> currentPath;

        dfs(root, targetSum, currentPath);

        return result;
    }
};