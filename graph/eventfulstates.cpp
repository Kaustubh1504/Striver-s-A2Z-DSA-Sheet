class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int v = graph.size();
        vector<int> g[v];
        for(int i=0;i<v;i++){
            for(auto c:graph[i]){
                // g[i].push_back(c);
                g[c].push_back(i);
            }
        }

        vector<int> indegree(v);
        for(int i=0;i<v;i++){
            for(auto child:g[i]){
                indegree[child]++;
            }
        }

        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            topo.push_back(cur);
            for(auto child:g[cur]){
                indegree[child]--;
                if(indegree[child]==0) q.push(child);
            }
        }

        // for(auto c: indegree) cout<<c<<" ";
        sort(topo.begin(),topo.end());
        return topo;
    }
};
