class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        int n=a.size();
        // int ans=n;
        vector <long long > suff(n,0);
        suff[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(a[i]-1==a[i+1]) suff[i]+=1+suff[i+1];
            else suff[i]=0;
        }
        return accumulate(suff.begin(),suff.end(),0LL)+n;
    }
};