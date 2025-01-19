class Solution {
    // BRUTE FORCE APPROACH -> O(n2)
    int subArrSum(vector<int> nums) {
        int start = 0, ans = 0 ;
        for(int i=0;i<nums.size();i++) {
            start = max(0, i-nums[i]);
            for(int j = start;j<=i;j++) {
                ans+=nums[j];
            }
        }
        return ans;
    }

    // PREFIX SUM APPROACH -> O(n)
    int subArrSumOptimised(vector<int> nums) {
        int n = nums.size();
        vector<int> p_sum(n,0);
        int start = 0, ans = 0;
        for(int i=0;i<n;i++) {
            if(i==0)p_sum[0]=nums[0];
            else p_sum[i]=nums[i]+p_sum[i-1];

            start = max(0,i-nums[i]);
            if(start==0)ans+=p_sum[i];
            else ans+=(p_sum[i]-p_sum[start-1]);
            //cout<<ans<<endl;
        }
        return ans;
    }
public:
    int subarraySum(vector<int>& nums) {
        //return subArrSum(nums);
        return subArrSumOptimised(nums);
    }
};