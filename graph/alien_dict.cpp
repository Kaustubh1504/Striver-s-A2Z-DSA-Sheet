//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        //make the graph 0-a 1-b and so on
        vector<int> g[K+1];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            // cout<<s1<<" "<<s2<<endl;
            int j=0;
            while(j<s1.size() && j<s2.size()){
                if(s1[j]!=s2[j]){
                    int par=s1[j]-'a';
                    int child=s2[j]-'a';
                    g[par].push_back(child);
                    // cout<<par<<":"<<child<<endl;
                    break;
                }
                j++;
            }
        }
        
        vector<int> indegree(K,0);
        
        for(int i=0;i<K;i++){
            for(auto child:g[i]){
                indegree[child]++;
                // cout<<child<<" ";
            }
            // cout<<endl;
        }
        
        queue<int> q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        string topo="";
        
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            
            //convert int to string
            char current= cur+'a';
            topo+=current;
            
            for(auto child:g[cur]){
                indegree[child]--;
                if(indegree[child]==0) q.push(child);
            }
        }
        
        // cout<<topo<<endl;
        
        return topo;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
