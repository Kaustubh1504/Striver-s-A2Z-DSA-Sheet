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
    int mxdepth(TreeNode* node){
        if(node==NULL) return 0;

        int left = mxdepth(node->left)+1;
        int right= mxdepth(node->right)+1;

        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return mxdepth(root);
    }
};
