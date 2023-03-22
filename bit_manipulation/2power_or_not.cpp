class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n<=0) return false;
        int c = n&(n-1);
        

        return c==0? true: false;
        
    }
};
