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
    void inorder(TreeNode* node,vector<int> &traversal){
        if(node==NULL) return;

        inorder(node->left,traversal);
        traversal.push_back(node->val);
        inorder(node->right,traversal);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // inorder(root,ans);
        // return ans;

        stack<TreeNode*> st;
        vector<int> ans;
        if(root==NULL) return ans;
        TreeNode* node= root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
                
            }else{
                if(st.empty()==true) break;
                node= st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};
