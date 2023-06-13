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
    void postorder(TreeNode* node,vector<int> &traversal){
        if(node==NULL) return;

        postorder(node->left,traversal);
        postorder(node->right,traversal);
        traversal.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(root==NULL) return ans;
        // postorder(root,ans);
        // return ans;
        
        stack<TreeNode* > st1,st2;
        st1.push(root);

        while(!st1.empty()){
            auto node = st1.top();
            st1.pop();
            ans.push_back(node->val);

            if(node->left!=NULL) st1.push(node->left);
            if(node->right!=NULL) st1.push(node->right);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
