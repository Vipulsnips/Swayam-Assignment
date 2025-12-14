class Solution {
public:
    static const int MOD = 1000000007;

    int numberOfWays(string corridor) {
        long long ans = 1;
        int cnt = 0, check = 1;
        int n = corridor.size();
        int s = count(corridor.begin(), corridor.end(), 'S');

        if (s == 0 || (s & 1)) return 0;

        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S' && cnt < 2) {
                cnt++;
            }
            else if (corridor[i] == 'S' && cnt == 2) {
                ans = (ans * check) % MOD;
                cnt = 1;        // current S starts next group
                check = 1;
            }
            else if (corridor[i] == 'P' && cnt == 2) {
                check++;
            }
        }
        return ans;
    }
};
