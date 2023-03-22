//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {

        // Write your code 
        //18
         // 2*3*3 -- prime factorisation
         // 2,3 prime factors
         
         int seive[N+5]={0};
        //  memset(seive,0,sizeof(sieve));
         vector<int> primefact;
         
         for(int i=2;i<=N;i++){
             if(seive[i]==0){
                 for(int j=i;j<=N;j+=i){
                     seive[j]=i;
                     if(j==N){
                         primefact.push_back(i);
                     }
                 }
             }
         }
         
        //  cout<<primefact[0]<<endl;
         vector<int> ans;
        
         for(int i=0;i<primefact.size();i++){
                int prime=primefact[i];
                while(N%prime==0){
                    ans.push_back(prime);
                    N=N/prime;
                }
         }
         
         
         
         return ans;
         
         
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
