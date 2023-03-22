//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // int cnt=0;
        // // Your logic, here
        // for(int j=1;j<=n;j++){
        //     for(int i=0;i<31;i++){
        //         if(((j>>i)&1)==1) cnt++;
        //     }
            
        //
        
        
        // return cnt;
        n++;
        int cnt=0;
        
        //for A
        cnt+=n/2;
        
        int powof2 = 2;
        
        while(powof2<n){
            
           int totalgroups = n/powof2;
           cnt+=(totalgroups/2)*powof2;
          totalgroups&1==1?cnt+=(n%powof2):cnt+=0;
            
            
            powof2*=2;
            
        }
        
        
        return cnt;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends
