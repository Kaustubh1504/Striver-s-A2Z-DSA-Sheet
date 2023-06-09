class Solution {
public:
     vector<int> dijikstra(int n,vector<pair<int,int>> g[],int k,int src){
        vector<int> distance(n+5,1e9);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        // queue< pair<int,pair<int,int>> > q;
        q.push({0,{src,0}});
        distance[src]=0;

        while(!q.empty()){
            auto cur=q.top();
            int disstep=cur.first;
            int cur_n=cur.second.first;
            int cur_wt=cur.second.second;
            q.pop();

            if(disstep>k) continue;

            for(auto child:g[cur_n]){
                int child_n=child.first;
                int child_wt=child.second;

                if(cur_wt+child_wt<distance[child_n] && disstep <= k){
                        distance[child_n]=cur_wt+child_wt;
                        q.push({disstep+1,{child_n,distance[child_n]}});
                }
                
            }
        }

        for(auto c: distance) cout<<c<<" ";

        return distance;

    }
   
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> g[n];
        for(auto vec: flights){
            int x=vec[0];
            int y=vec[1];
            int wt=vec[2];
            g[x].push_back({y,wt});
        }
        vector<int> dis=dijikstra(n,g,k,src);
        // int ans=dijikstra(n,k,g);
        int ans=dis[dst];
        if(ans==1e9) return -1;
        return dis[dst];
        
    }
    //  vector<int> dijikstra(int n,vector<pair<int,int>> g[],int k,int src){
        
    //     vector<int> distance(n,1e9);
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    //     q.push({0,src});//  {wt,node}
    //     distance[src]=0;

    //     while(!q.empty()){
    //         int curn=q.top().second;
    //         int dis=q.top().first;
    //         q.pop();
    //         k--;
            
    //         for(auto child:g[curn]){
    //             int child_n=child.first;
    //             int child_wt=child.second;
    //             if(dis+child_wt>distance[child_n]) continue;
    //             distance[child_n]=dis+child_wt;
    //             q.push({distance[child_n],child_n});
    //         }

    //     }

    //     return distance;

    // }
};
