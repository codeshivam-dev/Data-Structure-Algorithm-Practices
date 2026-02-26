
class Solution {
public:
    int mxPath;   

    /*
        solve(root, l, r)

        l = length of ZigZag path if previous move was LEFT
        r = length of ZigZag path if previous move was RIGHT

        Idea:
        - If we go LEFT now → previous move must have been RIGHT
        - If we go RIGHT now → previous move must have been LEFT
    */
    void solve(TreeNode* root, int l, int r){
        if(!root) return; 

        
        mxPath = max(mxPath, max(l, r));

        /*
            If we move to left child:
            - This continues a zigzag only if previous move was RIGHT
            - So new left length = r + 1
            - Right length becomes 0 (since direction changed)
        */
        solve(root->left, r + 1, 0);

        /*
            If we move to right child:
            - This continues a zigzag only if previous move was LEFT
            - So new right length = l + 1
            - Left length becomes 0
        */
        solve(root->right, 0, l + 1);
    }

    int longestZigZag(TreeNode* root) {
        mxPath = 0;        
        solve(root, 0, 0); 
        return mxPath;
    }
};