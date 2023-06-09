class Solution {
public:
    int dijisktra(vector<pair<int,int>>g[],int n,int src){

        const int INF=1e7;
        vector<int> dist(n+10,INF);

        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        q.push({0,src});
        dist[src]=0;

        while(!q.empty()){
            int cur_n = q.top().second;
            int dis = q.top().first;
            q.pop();

            for(auto child : g[cur_n]){
                int child_wt=child.second;
                int child_n=child.first;

                if(dis + child_wt<dist[child_n]){
                    dist[child_n]= dis + child_wt;
                    q.push({dist[child_n],child_n});
                }
                
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<=n;i++) {
            // cout<<dist[i]<<" ";
            ans=max(ans,dist[i]);
        }

        if(ans==INF) return -1;
        return ans;

    }
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {

        vector<pair<int,int>> g[n+1];
        for(auto vec:times){
            int x=vec[0];
            int y=vec[1];
            int wt=vec[2];
            g[x].push_back({y,wt});
        }
        

        return dijisktra(g,n,src);
      
    }
};
