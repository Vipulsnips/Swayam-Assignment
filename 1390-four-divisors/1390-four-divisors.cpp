class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i],cnt=0,sum=0;
            for(int j=1;j*j<=(temp);j++){
                if(temp%j==0 && j!=(temp)/j){
                    cnt+=2;
                    sum+=j;
                    sum+=(temp)/j;
                }
                else if(temp%j==0){
                    cnt++;
                    sum+=j;
                }
            }
            if(cnt==4){
                ans+=sum;
            }
        }
        return ans;
    }
};