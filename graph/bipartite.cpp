class Solution {
public:
    bool bfs(int source,vector<vector<int>>& graph,int color[]){
        queue<int> q;
        q.push(source);
        
        color[source]=0;

        while(!q.empty()){
            int cur=q.front();
            q.pop();

            for(auto child:graph[cur]){
                if(color[child]==-1){
                    //not colored previously
                    color[child]=!color[cur];
                    q.push(child);
                }else if(color[child]==color[cur]){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[graph.size()];
        bool ans=true;
        memset(color,-1,sizeof(color));

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,graph,color)==false) {
                    ans=false;
                    break;
                }
            }
        }

        return ans;
    }
};
