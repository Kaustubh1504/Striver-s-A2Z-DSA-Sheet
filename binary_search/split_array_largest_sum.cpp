class Solution {
public:
    bool isPossible(int mid,vector<int> A, int N, int M){
        
        for(int i=0;i<N;i++){
            if(A[i]>mid) return false;
        }
        
        int pages=0;
        int students=1;
        for(int i=0;i<N;i++){
            if(pages+A[i]>mid){
                students++;
                pages=0;
            }
            pages+=A[i];
            // cout<<pages<<" "<<students<<endl;
        }
        
        if(students<=M) return true;
        return false;
    }
    int splitArray(vector<int>& A, int k) {

        int M = k;
        int N= A.size();
        if(N==1) return A[0];
        if(N<M) return -1;
        int low=1;
        int high=0;
        for(int i=0;i<N;i++) {high+=A[i];}
        
        int ans=INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(mid,A,N,M)){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        // isPossible(81,A,N,M);
        
        return ans;
    }
};
