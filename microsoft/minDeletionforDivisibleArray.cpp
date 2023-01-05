class Solution {
public:
   int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int hcf=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++) hcf=__gcd(hcf,numsDivide[i]);
        sort(begin(nums),end(nums));
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>hcf) return -1;
            else if(hcf%nums[i]==0) return i;
        }
        return -1;
    }
};
