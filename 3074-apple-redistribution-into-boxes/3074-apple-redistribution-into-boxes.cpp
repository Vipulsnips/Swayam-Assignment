class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int curr=0,ans=0;
        for(auto i:capacity){
            if(curr>=sum) break;
            curr+=i;
            ans++;
        }
        return ans;
    }
};