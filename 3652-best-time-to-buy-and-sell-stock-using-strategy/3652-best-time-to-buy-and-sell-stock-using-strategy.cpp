#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector <ll> pre(n);
        int ind = ( k/2 );
        for(int i=0;i<n;i++){
            if(i==0) pre[i]=strategy[i] * prices[i];
            else{
                pre[i] = pre[i-1]+ (strategy[i] * prices[i]);
            }
        }
        ll st =0 ,en = 0, curr =0, maxm = pre[n-1];
        while(en <k){
            if(en >= (k/2)) curr+=prices[en];
            en++;
        }
        cout<<curr<<endl;
        en--;
        while(en < n){
            ll now;
            if(st==0){
                now = curr+pre[n-1] - pre[en];
                st++;
                en++;
            }
            else{
                curr-=prices[ind];
                ind++;
                curr+=prices[en];
                now =pre[st-1]+ curr + pre[n-1] - pre[en]; 
                en++;st++;
            }
        cout<<now<<endl;
            maxm=max(maxm,now);
        }
        return maxm;
    }
};