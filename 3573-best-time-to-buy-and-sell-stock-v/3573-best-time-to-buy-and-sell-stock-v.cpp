#define ll long long
class Solution {
public:
    ll dp[1001][501][3];
    ll solve(int i,int k,int cases,vector<int>& prices){
        if(i>=prices.size()){
            if(cases==0) return 0LL;
            return INT_MIN;
        }
        if(dp[i][k][cases]!=INT_MIN) return dp[i][k][cases];
        ll ans1=solve(i+1,k,cases,prices);
        ll ans2=INT_MIN;
        if(k>0){
            if(cases==1){
                ans2= prices[i]+ solve(i+1,k-1,0,prices);
            }
            else if(cases == 2){
                ans2= -prices[i]+solve(i+1,k-1,0,prices);
            }
            else{
                ans2= max(-prices[i]+ solve(i+1,k,1,prices),prices[i]+ solve(i+1,k,2,prices));
            }
        }
        return dp[i][k][cases]=max(ans1,ans2);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        for(ll i=0;i<1001;i++){
            for(ll j=0;j<501;j++){
                for(ll k=0;k<3;k++) dp[i][j][k]=INT_MIN;
            }
        }
        return solve(0,k,0,prices);
    }
};