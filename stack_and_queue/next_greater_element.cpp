class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // int n = nums1.size();
        // vector<int> ans(n,-1);

        // for(int i=0;i<nums1.size();i++){
        //     int cur=nums1[i];

        //     int j=0;
        //     for(j=0;j<nums2.size();j++){
        //         if(nums2[j]==cur) break;
        //     }

        //     cout<<j<<endl;

        //     for(int k=j;k<nums2.size();k++){
        //         if(nums2[k]>cur){
        //             ans[i]=nums2[k];
        //             break;
        //         }
        //     }
        // }

        // return ans;

       map<int,int> mNums1;

        for(auto c: nums1){
            mNums1[c]=-1;
        }

        for(auto itr: mNums1){
            cout<<itr.first<<":"<<itr.second<<endl;
        }
        stack<int> st;
        int n = nums2.size();
        for(int i=0;i<n;i++){
            // if(st.empty()){
            //     if(mNums1.find(nums2[i])!=mNums1.end()) st.push(nums2[i]);
            // }else{
                int cur= nums2[i];
                while(!st.empty() && st.top()<cur){
                    int last=st.top();
                    // if(mNums1.find(last)!=mNums1.end()){
                    //     mNums1[last]=cur;
                    //     st.pop();
                    // }
                    mNums1[last]=cur;
                    cout<<"poped "<<last<<"="<<cur<<endl;

                    st.pop();
                    
                }
                if(mNums1.find(cur)!=mNums1.end()) {
                    cout<<"pushed: "<<cur<<endl;
                    st.push(cur);
                }
            
            // }
        }

        vector<int> ans;

        for(auto itr: mNums1 ){
            ans.push_back(itr.second);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=mNums1[nums1[i]];
        }

        return nums1;
        
    }
};
