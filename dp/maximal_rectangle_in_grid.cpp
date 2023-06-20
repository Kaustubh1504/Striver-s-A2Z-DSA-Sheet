class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
         1. find next smaller element fill with n
         2. find prev smaller element fill with -1
         3. maximize area = nextsmaller[i]-prevsmaller[i]-1
        */
        int n = heights.size();
        vector<int> nextsmaller(n+1,n),prevsmaller(n+1,-1);

        stack<int> st;

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
            }else{
                while(!st.empty() && heights[st.top()]>heights[i]){
                    nextsmaller[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }

        // for(int i=0;i<n;i++) cout<<nextsmaller[i]<<" ";
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
            }else{
                while(!st.empty() && heights[st.top()]>heights[i]){
                    prevsmaller[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }

        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<prevsmaller[i]<<" ";
        // cout<<endl;

        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            int h = heights[i];
            int l = nextsmaller[i]-prevsmaller[i] - 1;
            int area = h*l;
            // cout<<"height: "<<h<<" length: "<<l<<endl;
            ans = max(ans,area);
        }

        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int> heights(m+1,0);

        int ans=0;
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }

            ans=max(ans,largestRectangleArea(heights));
        }

        return ans;
    }
};
