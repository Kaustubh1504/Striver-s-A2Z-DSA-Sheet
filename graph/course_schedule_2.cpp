class Solution {
public:
    vector<int> bfs(int source,vector<int>g[]){ 

        bool vis[2005];
        vector<int> bfsorder;
        queue<int> q;
        vis[source]=true;
        q.push(source);

        while(!q.empty()){
            int cur=q.front();
            q.pop();

            bfsorder.push_back(cur);
            cout<<cur<<" ";
            for(auto child:g[cur]){
                if(vis[child]==true) continue;
                vis[child]=true;
                q.push(child);
            }
        }
        
        return bfsorder;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            use kahns algorithm bfs topo sort to detect cycle
            if cycle is present return false
        */
        vector<int> g[numCourses];
        for(auto pr:prerequisites){
            int x=pr[0];
            int y=pr[1];
            g[y].push_back(x);
        }

        vector<int> indegree(numCourses,0);
        for(auto pre:prerequisites){
            int first=pre[0];
            int second=pre[1];
            indegree[first]++;
        }

        // for(auto c: indegree) cout<<c<<" ";

        queue<int>q;
        for(int i=0;i<numCourses;i++){
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

        // for(auto c: topo) cout<<c<<" ";

        if(topo.size()==numCourses) return topo;
        return vector<int>(0);
    }
};
