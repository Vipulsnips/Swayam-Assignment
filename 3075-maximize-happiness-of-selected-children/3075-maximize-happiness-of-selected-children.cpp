#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        sort(a.rbegin(),a.rend());
        ll minus=0,cnt=0;
        for(int i=0;i<a.size(),k--;i++){
            ll curr=max(0LL,a[i]-minus);
            if(curr==0) break;
            cnt+=curr;
            minus++;
        }
        return cnt;
    }
};