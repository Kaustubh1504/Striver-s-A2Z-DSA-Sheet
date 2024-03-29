//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    void generate(int ind,int sum,vector<int> arr,int N){
        
        if(ind==N){
            ans.push_back(sum);
            return;
        }
        //do not pick
        generate(ind+1,sum,arr,N);
        
        //pick
        generate(ind+1,sum+arr[ind],arr,N);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        ans.clear();
        generate(0,0,arr,N);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
