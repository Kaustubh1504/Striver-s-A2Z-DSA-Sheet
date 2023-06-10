#include<bits/stdc++.h>
using namespace std;
class Disjointset{
	vector<int> rank,par;
   public:
   	Disjointset(int n){
   		rank.resize(n+1,0);
   		par.resize(n+1,0);
   		for(int i=0;i<=n;i++) par[i]=i;
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
};
int main(int argc, char const *argv[])
{
	Disjointset d(7);
	d.unionByRank(1,2);
	d.unionByRank(2,3);
	d.unionByRank(4,5);
	d.unionByRank(6,7);
	d.unionByRank(5,6);

	if(d.findParent(3)==d.findParent(6)) cout<<"same"<<endl;
	else cout<<"not same"<<endl;

	d.unionByRank(3,7);

	if(d.findParent(3)==d.findParent(6)) cout<<"same"<<endl;
	else cout<<"not same"<<endl;


	return 0;
}
