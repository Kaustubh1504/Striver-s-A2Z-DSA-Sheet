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
     void levelorder(TreeNode* node,vector<int>&rightview){
        if(node==NULL) return;
        map<int,TreeNode*> linenode;
        queue<pair<int,TreeNode*>> q;
        q.push({0,node});

        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){
                auto cur=q.front();
                q.pop();
                int cur_line=cur.first;
                auto cur_node=cur.second;

                linenode[cur_line]=cur_node;

                if(cur_node->left!=NULL) q.push({cur_line+1,cur_node->left});
                if(cur_node->right!=NULL) q.push({cur_line+1,cur_node->right});
            }
        }

        for(auto c:linenode){
            // cout<<c.second->val<<" ";
            rightview.push_back(c.second->val);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        levelorder(root,ans);
        return ans;

    }
};
