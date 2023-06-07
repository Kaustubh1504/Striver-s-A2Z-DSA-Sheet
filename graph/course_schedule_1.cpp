class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            use kahns algorithm bfs topo sort to detect cycle
            if cycle is present return false
        */
        vector<int> g[numCourses];
        for(auto pr:prerequisites){
            int x=pr[0];
            int y=pr[1];
            g[x].push_back(y);
        }

        vector<int> indegree(numCourses,0);
        for(auto pre:prerequisites){
            int first=pre[0];
            int second=pre[1];
            indegree[second]++;
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

        for(auto c: topo) cout<<c<<" ";

        if(topo.size()==numCourses) return true;
        return false;


    }
};
