class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

            // if(m<n) merge(nums2,n,nums1,m);
            // int l=0;
            // int r=n-1;

            // while(l<m && r>=0){
            //     if(nums1[l]>nums2[r]){
            //         swap(nums1[l],nums2[r]);
            //         l++;
            //         r--;
            //     }else{
            //         l++;
            //     }
            // }

            // // sort(nums2.begin(),nums2.end());

            // // cout<<l<<" "<<r;
            // int j=0;
            // for(int i=m;i<m+n;i++){
            //     nums1[i]=nums2[j];
            //     j++;
            // }

            // for(auto c: nums1) cout<<c<<" ";
            // cout<<endl;
            // for(auto c: nums2) cout<<c<<" ";


            int i=m-1;
            int j=n-1;
            int k=m+n-1;

            while(i>=0 && j>=0){
                if(nums1[i]>nums2[j]){
                    nums1[k]=nums1[i];
                    k--;
                    i--;
                }
                else{
                    nums1[k]=nums2[j];
                    k--;
                    j--;
                }
            }

            while(i>=0){
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            while(j>=0){
                nums1[k]=nums2[j];
                k--;
                j--;
            }

    }
};
