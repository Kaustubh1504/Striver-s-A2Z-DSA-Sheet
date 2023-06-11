class Disjointset{
	
   public:
	 vector<int> rank,par,size;
   	Disjointset(int n){
   		rank.resize(n+1,0);
   		par.resize(n+1,0);
   		size.resize(n+1,0);

   		for(int i=0;i<=n;i++) {
   			par[i]=i;
   			size[i]=1;
   		}
   	}

    int findParent(int v){
    	if(par[v]==v) return v;
    	return par[v]=findParent(par[v]);
    }

    void unionByRank(int u,int v){
    	int ulp_u = findParent(u);
    	int ulp_v= findParent(v);

    	if(ulp_u==ulp_v) return;

    	if(rank[ulp_u]<rank[ulp_v]){
    		par[ulp_u]=ulp_v;
    	}else if(rank[ulp_v]<rank[ulp_u]){
    		par[ulp_v]=ulp_u;
    	}else{
    		par[ulp_v]=ulp_u;
    		rank[ulp_u]++;
    	}
    }

    void unionBySize(int u,int v){
    	int ulp_u = findParent(u);
    	int ulp_v= findParent(v);

    	if(ulp_u==ulp_v) return;

    	if(size[ulp_u]<size[ulp_v]){
    		par[ulp_u]=ulp_v;
    		size[ulp_v]+=size[ulp_u];
    	}else{
    		par[ulp_v]=ulp_u;
    		size[ulp_u]+=size[ulp_v];
    	}
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow=0;
				int maxCol=0;
				for(auto it:stones){
					maxRow=max(maxRow,it[0]);
					maxCol=max(maxCol,it[1]);
				}
				/*
					  5 6 7 8  --> colno
					0 1
					1
					2
					3
					4--> rowno 

					node between (0,0)==(0,5)


				*/

			  Disjointset d(maxRow+maxCol+1);
				map<int,int> uniquenodes;
				
				for(auto edge:stones){
					 int u = edge[0];
					 int v=  maxRow + edge[1] + 1;
					 d.unionBySize(u,v);
					 uniquenodes[u]++;
					 uniquenodes[v]++;
				}

				int nofconnect=0;
				for(auto it:uniquenodes){
					  int node=it.first;
						if(d.findParent(node)==node) nofconnect++;
				}

				cout<<nofconnect<<" ";
				return n-nofconnect;

    }
};
