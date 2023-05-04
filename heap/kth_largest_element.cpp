class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minheap;

        for(auto c:nums){
            minheap.push(c);
            if(minheap.size()>k) minheap.pop();
        }

        int ans = minheap.top();

        return ans;
    }
};
