//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        
        //Algo:
        // step 1: find xor of entire array and store in variable xor
        // step 2: do (xor)&(-xor), resultant number to be stored in variable set_bit_number
        //            find -xor by two's complement
        // step 3: do 'and' of set_bit_number with entire array, divide array into 2 grps:
        //         grp 1- gives ans=0 when set_bit_number & (arr[i]) is done
        //         grp 2- gives ans!=0 when set_bit_number & (arr[i]) is done
        // step 4: do xor of both these arrays to get both numbers that appear odd number of times
        // code here
        long long int xor2 = 0;
        // for(auto c: Arr) xor2^=c;
        for(long long int i=0;i<N;i++) xor2^=Arr[i];
        
        long long int setbitnumber = xor2 & (~(xor2-1));
        
        long long int num1 = 0;
        long long int num2=0;
        
        for(long long int i=0;i<N;i++){
            if(Arr[i]&setbitnumber){
                num1^=Arr[i];
            }else{
                num2^=Arr[i];
            }
        }
        
        vector<long long int> ans;
        ans.push_back(num1);
        ans.push_back(num2);
        sort(ans.rbegin(),ans.rend());
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
