//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    void generate(int ind,string sub,int n){
        
        
        if(ind>=n) {
            cout<<sub<<" ";
            return;
        }
        
        //do not make the current index one
        generate(ind+1,sub,n);
        
        //make current index one
        sub[ind]='1';
        generate(ind+2,sub,n);
        sub[ind]='0';
        
    }
    
    void generateBinaryStrings(int num){
        //Write your code
        string sub="";
        for(int i=0;i<num;i++) sub+='0';
        
        generate(0,sub,num);
    
    }
  
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
