class Solution {
public:
    TreeNode* solve(TreeNode* root,int key){
        if(!root) return root;
        if(root->val == key){
            if(!root->right && !root->left) {
                delete root;
                return NULL;
            }
            else if(!root->left && root->right){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right && root->left){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* temp = root->right;
                TreeNode* it = temp;

                while(it->left != NULL) it = it->left;
                it->left = root->left;
                delete root;
                return temp;

            }
        }     
        if(root->val < key){
            root->right = solve(root->right,key);
        }
        else{
            root->left = solve(root->left,key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* nroot = solve(root,key);
        return nroot;
    }
};