//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(double mid,vector<int> &stations, int K){
        int placedStn=0;
       
        for(int i=1;i<stations.size();i++){
            placedStn += floor((stations[i]-stations[i-1])/mid) ;
        }
        if(placedStn>K) return false;
        return true;
    }
    double findSmallestMaxDist(vector<int> &stations, int K){

      double low=0;
      double high=1e9+100;
      double eps = 1e-6;
      
      double ans=1e9;
      
      while((high-low)>eps){
          
          double mid = low + (high-low)/2.0;
        //   cout<<mid<<endl;
          
          if(isPossible(mid,stations,K)){
              ans=min(ans,mid);
              high=mid;
          }else{
              low=mid;
          }
      }
    //   isPossible(0.5,stations,K);
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
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends
