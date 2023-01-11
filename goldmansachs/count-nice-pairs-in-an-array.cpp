class Solution {
public:
   int ok(int n)
    {
        string x=to_string(n);
        reverse(x.begin(),x.end());
        int y=stoi(x);
        return y;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            int y=ok(nums[i]);
            mp[x-y]++;
        }
        int ans=0;
        for(auto x:mp)
        {
            
            ans=(ans%1000000007+((x.second)*1LL*(x.second-1)/2)%1000000007)%1000000007;
        }
        return ans;  
    }
};
