class Solution {
public:
    int MOD = 1000000007;
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};
    vector <vector <int>> dp;
    int numOfWays(int n) {
        dp.resize(n,vector <int>(12,-1));
        long long ans=0;
        for(int i=0;i<12;i++){
            ans=(ans+solve(n-1 , i)) % MOD;
        }
        return ans;
    }
    int solve(int n , int prev){
        if(n==0){
            return 1;
        }
        if(dp[n][prev]!=-1){
            return dp[n][prev];
        }
        int ans=0;
        string last=states[prev];
        for(int i=0;i<12;i++){
            if(i==prev) continue;
            string curr= states[i];
            int flg=0;
            for(int col=0;col<3;col++){
                if(curr[col]==last[col]){
                    flg=1;
                    break;
                }
            }
            if(!flg){
                ans=(ans+solve(n-1 , i)) % MOD;
            }
        }
        return dp[n][prev]=ans;
    }
};