class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),nn=strs[0].size();
        //------------------L I S dp------------------------
        vector <int> dp(nn,1);
        int lis=0;
        for(int i=0;i<nn;i++){
            for(int j=0;j<i;j++){
                int flg=1;
                for(int k=0;k<n;k++){
                    if(strs[k][j] > strs[k][i]){
                        flg=0;
                        break;
                    }
                }
                if(flg){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            lis=max(lis,dp[i]);
        }
        return nn-lis;
    }
};