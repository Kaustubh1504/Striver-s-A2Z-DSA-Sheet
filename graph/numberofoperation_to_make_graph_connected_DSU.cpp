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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        Disjointset d(n);
        int extraEdges=0;
	    for(auto edge:connections){
            int u = edge[0];
            int v= edge[1];
            if(d.findParent(u)==d.findParent(v)) extraEdges++;
            else{
                d.unionBySize(u,v);
            }
        }
        int noofconnected=0;
        for(int i=0;i<n;i++){
            if(d.findParent(i)==i) noofconnected++;
        }

        int ans=noofconnected-1;
        if(extraEdges>=ans) return ans;
        else return -1;
    }
};


