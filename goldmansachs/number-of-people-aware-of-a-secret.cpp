class Solution {
public:
    int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int count = 1;
        vector <int> dp(n+1,0);
        
        // The first person knows the secret.
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            // If the delay period is over, the secret will be told to someone. 
            if(i-delay>=1) dp[i]++;
            
            // This loop determines the total number of people who knows the secret. 
            for(int j = max(1,i-forget+1); j<=max(1,i-delay); j++)
                dp[i] = (dp[i]%mod + dp[j]%mod)%mod;
            
            // If there is someone who will forget today, make him forget :)
            if(i-forget>=1) dp[i]--;
        }
        return dp[n]%mod;
    }
};
