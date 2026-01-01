
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]!=9){
        digits[n-1]++;
            return digits;
        }
        else{
            digits[n-1]++;
            for(int i=n-1;i>=0;i--){
                if(digits[i]==10){
                    if(i!=0){
                    digits[i]=0;digits[i-1]++;}
                    else{
                    digits[0]=1;
                    digits.push_back(0);
                    }

                    
                }
                }
            return digits;
            }
            }
};