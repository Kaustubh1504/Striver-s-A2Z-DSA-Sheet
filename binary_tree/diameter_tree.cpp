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
    int mxdepth(TreeNode* node,int& diameter){
        if(node==NULL) return 0;
        int left=mxdepth(node->left,diameter);
        int right=mxdepth(node->right,diameter);
        diameter=max(diameter,left+right);

        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        int depth=mxdepth(root,diameter);
        return diameter;
        
    }
};
