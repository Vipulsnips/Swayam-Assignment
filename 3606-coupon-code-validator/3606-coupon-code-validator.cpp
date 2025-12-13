class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector <string> check = {"electronics", "grocery", "pharmacy", "restaurant"};
        vector<pair <int,string>>  ans;
        int n=code.size();
        for(int i=0;i<n;i++){
            int flg=1;
            if(isActive[i]==0) {
                continue;
            }
            if(count(check.begin(),check.end(),businessLine[i]) == 0) {
                continue;
            }
            if(code[i].size()==0) continue;
            for(int j=0;j< code[i].size();j++){
                if((isalnum(code[i][j])) || code[i][j]=='_'){
                    continue;
                } 
                else {
                    flg=0;break;
                }
            }
            if(flg) {
                int in = find(check.begin(),check.end(),businessLine[i])- check.begin();
                ans.push_back({in,code[i]}); 
            }
        }
        sort(ans.begin(),ans.end());
        vector <string> cool;
        for(auto i : ans ) cool.push_back(i.second);
        return cool;
    }
};