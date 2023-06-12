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
    void preorder(TreeNode* node,vector<int>&order){
        if(node==NULL){ 
            order.push_back(0);
            return;
        }

        order.push_back(node->val);
        
        preorder(node->left,order);
        
        preorder(node->right,order);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> porder,qorder;
        preorder(p,porder);
        preorder(q,qorder);

        return porder==qorder;
    }
};
