class Solution {
public:
    int countCoveredBuildings(int b, vector<vector<int>>& a) {
        map<int, vector<int>> rows, cols;
        
        for (auto& p : a) {
            rows[p[1]].push_back(p[0]); // y -> x list
            cols[p[0]].push_back(p[1]); // x -> y list
        }

        for (auto& [_, v] : rows) sort(v.begin(), v.end());
        for (auto& [_, v] : cols) sort(v.begin(), v.end());

        int ans = 0;

        for (auto& p : a) {
            int x = p[0], y = p[1];

            // Check row (left & right)
            auto& row = rows[y];
            auto it = lower_bound(row.begin(), row.end(), x);
            bool left = it != row.begin();
            bool right = (it + 1) != row.end();

            // Check column (up & down)
            auto& col = cols[x];
            auto it2 = lower_bound(col.begin(), col.end(), y);
            bool down = it2 != col.begin();
            bool up = (it2 + 1) != col.end();

            if (left && right && up && down)
                ans++;
        }

        return ans;
    }
};