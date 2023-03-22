class Solution {
public:
    int countPrimes(int n) {
        const int N = 5*1e6+5;
        int seive[N];
        memset(seive,0,sizeof(seive));

        for(int i=2;i<=n;i++){
            if(seive[i]==0){
                for(int j=2*i;j<=n;j+=i){
                    seive[j]=i;
                }
            }
        }

        int cnt=0;
        for(int i=2;i<n;i++){
            if(seive[i]==0) cnt++;
        }

        return cnt;
    }
};
