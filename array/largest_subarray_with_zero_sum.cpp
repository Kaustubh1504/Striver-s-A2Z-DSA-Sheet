//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // 15 -2 2 -8 1 7 10 23
        // 15 13 15 7 8 15 25 48
       map<int,int> mpp;
       int sum=0;
       int maxi=0;
       
       for(int i=0;i<n;i++){
           sum+=A[i];
           if(sum==0){
               maxi=i+1; // length from starting index
           }
           else{
               if(mpp.find(sum)!=mpp.end()){
                   int lastindexatwhichsumocuured=mpp[sum];
                   maxi=max(maxi,i-lastindexatwhichsumocuured);
                   //lenght from a index where the sum was same as cur sum
               }else{
                   mpp[sum]=i;
               }
           }
       }
       
       return maxi;
       
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
