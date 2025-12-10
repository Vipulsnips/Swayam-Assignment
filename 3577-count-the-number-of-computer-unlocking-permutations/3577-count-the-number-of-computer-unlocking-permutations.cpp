class Solution {
public:
    long long MOD=1000000007;
    int countPermutations(vector<int>& complexity) {
        int minm=complexity[0],n=complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[i]<=minm){
                cout<<"h";
                return 0;
            }
        }
        long long x=1;n--;
        while(n>0){
            x*=n;
            x%=MOD;
            n--;
        }
        return x;
    }
};