typedef long long int ll;

class Solution {
    ll ValidPairs (int l, int r, vector<ll>& nums, const ll diff) {
        if (l == r) return 0;
        
        int m = (l+r) >> 1;
        ll result = ValidPairs (l, m, nums, diff) + ValidPairs (m+1, r, nums, diff);
        
        int l1 = l, r1 = m, l2 = m+1, r2 = r;
        vector<ll> merged;
        
        for (int j = l2; j <= r2; j ++) {
            // x <= y+d
            ll mx_allowed = nums[j] + diff;
            
            int ind = upper_bound (nums.begin()+l1, nums.begin()+r1+1, mx_allowed) - nums.begin() - 1;
            if (ind <= r1) result += (ind - l1 + 1);
        }
        
        while (l1 <= r1 && l2 <= r2) {            
            if (nums[l1] <= nums[l2]) 
                merged.push_back(nums[l1 ++]);
            else 
                merged.push_back(nums[l2 ++]);
        }
        while (l2 <= r2) merged.push_back(nums[l2 ++]);
        while (l1 <= r1) merged.push_back(nums[l1 ++]);
        
        for (int j = l; j <= r; j ++) nums[j] = merged[j - l];
        return result;
    }
    
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<ll> nums(n);
        for (int j = 0; j < n; j ++) nums[j] = nums1[j] - nums2[j];
        
        return ValidPairs (0, n-1, nums, diff);
    }
};