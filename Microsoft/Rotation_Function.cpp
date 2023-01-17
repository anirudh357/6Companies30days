class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int prevsol=0;
        int arraysum=0;
        for(int i=0;i<n;i++){
            prevsol = prevsol + (i*nums[i]);
            arraysum = arraysum + nums[i];
        }
        
        int maxsum = prevsol;
        for(int i = n-1; i>=1; i--){
            prevsol = prevsol + arraysum - (n*nums[i]);
            if(maxsum<prevsol){
                maxsum=prevsol;
            }
        }
        return maxsum;
    }
};