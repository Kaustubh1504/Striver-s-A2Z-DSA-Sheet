class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF=1e9;
        vector<vector<int>> dis(n,vector<int>(n,0));

        /*
          0 3 4 5   2
          3 0 1 2   3
          4 1 0 1   3
          5 3 1 0   2
        */

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) dis[i][j]=0;
                else dis[i][j]=INF;
            }
        }

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            dis[u][v]=wt;
            dis[v][u]=wt;
        }

        for(int via=0;via<n;via++){  
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  dis[i][j]=min(dis[i][via]+dis[via][j],dis[i][j]);
              }
          }
        }
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) {
                
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ansnode=-1,mincnt=INF+10;
        for(int i=0;i<n;i++){

            int cur_cnt=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dis[i][j]<=distanceThreshold) cur_cnt++;
            }
            cout<<cur_cnt<<endl;
            if(cur_cnt<=mincnt) {
                ansnode=max(ansnode,i);
                mincnt=cur_cnt;
            }
        }

       
        return ansnode;




    }
};
