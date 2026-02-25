class Solution {
public:
    
    // Collect leaf nodes in left -> right order
    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if(!root) return;
        
        // If leaf node, store value
        if(!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        }
        
        // Traverse left first 
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leaves1, leaves2;
        
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        
        return leaves1 == leaves2;   
    }
};