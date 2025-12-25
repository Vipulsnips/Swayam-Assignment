#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        sort(a.rbegin(),a.rend());
        ll minus=0,cnt=0;
        for(int i=0;i<a.size(),k--;i++){
            cnt+=max(0LL,a[i]-minus);
            minus++;
        }
        return cnt;
    }
};