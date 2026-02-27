class Solution {
public:
    int totalPaths = 0;

    void dfs(TreeNode* node,
             long long currentSum,
             int target,
             unordered_map<long long, int>& prefixCount) {
        
        if (!node) return;

        // Include current node in running sum
        currentSum += node->val;

        // If currentSum itself equals target → valid path from root
        if (currentSum == target) {
            totalPaths++;
        }

        // Check if there exists a prefix such that:
        //    currentSum - prefix = target
        long long neededPrefix = currentSum - target;

        if (prefixCount.find(neededPrefix) != prefixCount.end()) {
            totalPaths += prefixCount[neededPrefix];
        }

        // Store current prefix sum before going deeper
        prefixCount[currentSum]++;

        // Explore left & right subtree
        dfs(node->left, currentSum, target, prefixCount);
        dfs(node->right, currentSum, target, prefixCount);

        // Backtrack → remove current prefix sum
        prefixCount[currentSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixCount;
        totalPaths = 0;

        dfs(root, 0LL, targetSum, prefixCount);

        return totalPaths;
    }
};