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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        
        if(root == NULL) 
            return ans; 
            
        queue<TreeNode*> q; 
        q.push(root); 
        bool lefttoright=true;
        while(!q.empty()) {
           
            vector<int> level;
            int noofnodeinalevel=q.size();
            for(int i=0;i<noofnodeinalevel;i++){
                TreeNode *temp = q.front(); 
                q.pop(); 
                
                level.push_back(temp->val);
                if(temp->left != NULL) 
                    q.push(temp->left); 
                if(temp->right != NULL) 
                    q.push(temp->right); 
            }
            if(lefttoright==false) reverse(level.begin(),level.end());
            ans.push_back(level);
            lefttoright=!lefttoright;
        }
        return ans; 
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        ans=levelOrder(root);
        return ans;
        // for(auto c: level) cout<<c<<" ";

        
        // int n=level.size();
        
        // if(level.size()==0) return ans;
        // ans.push_back({level[0]});
        // int i=1;
        // int cnt=2;

        // while(i<level.size()){
        //     vector<int> temp;
        //     for(int j=i;j<=cnt;j++){
        //        if(j>=n) break;
        //        temp.push_back(level[j]);
        //     }
        //     ans.push_back(temp);
        //     i=i+cnt;
        //     cnt=cnt*2;  
        // }

        // for(int i=1;i<ans.size();i+=2){
        //     reverse(ans[i].begin(),ans[i].end());
        // }

        

        return ans;
    }
};
