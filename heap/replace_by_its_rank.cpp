//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        // priority_queue< pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>> > pq;
        // vector<int> ans;
        
        // for(int i=0;i<N;i++){
        //     pq.push({arr[i],i+1});
        // }
        
        // while(!pq.empty()){
        //     auto p=pq.top();
        //     cout<<p.first<<p.second<<endl;
        //     ans.push_back(p.second);
        //     pq.pop();
        // }
        
        
        // return ans;
        map<int,int> valrank;
        vector<int> ans=arr;
        
        sort(arr.begin(),arr.end());
        int rank=1;
        valrank.insert({arr[0],1});
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]!=arr[i]){
                rank++;
                valrank.insert({arr[i],rank});
            }
        }
        
        // for(auto c: valrank) cout<<c.first<<c.second<<endl;
        for(int i=0;i<ans.size();i++){
            ans[i]=valrank[ans[i]];
        }
        
        return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
