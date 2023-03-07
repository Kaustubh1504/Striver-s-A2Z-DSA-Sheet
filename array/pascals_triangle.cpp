class Solution {
public:
    int ncr(int n,int r){
        // int num=1;
        // int den=1;
        // if (n - r < r) r = n - r;
        // for(int i=1;i<=r;i++){
        //     num=num*n;
        //     n--;
        // }

        // while(r>0){
        //     den*=r;
        //     r--;
        // }
        // // for(int j=1;j<=r;j++){
        // //     den=den*r;
        // //     r--;
        // // }

        // int ans = num/den;
        long long p = 1, k = 1;
        if (n - r < r)
        r = n - r;

        if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            // gcd of p, k
            long long m = __gcd(p, k);
 
            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }
 
    else
        p = 1;
        return p;
    }
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> triangle;

        for(int i=1;i<=numRows;i++){
            vector<int> row;
            for(int j=1;j<=i;j++){
                int cur=ncr(i-1,j-1);
                row.push_back(cur);
            }

            triangle.push_back(row);
        }
        
        return triangle;
    }
};