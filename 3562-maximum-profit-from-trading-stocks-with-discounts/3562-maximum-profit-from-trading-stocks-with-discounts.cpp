class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {

        unordered_map<int, vector<int>> mp;
        vector<int> indeg(n + 1, 0);
        vector<int> boss(n + 1, 0);
        vector<int> purchase(n + 1, 0);

        for (auto &i : hierarchy) {
            boss[i[1]] = i[0];
            mp[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }

        // Topological sort
        queue<int> q;
        vector<int> topo;
        for (int i = 1; i <= n; i++)
            if (indeg[i] == 0) q.push(i);

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            topo.push_back(curr);
            for (auto v : mp[curr]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }

        return solve(0, n, present, boss, future, budget, purchase, topo);
    }

    int solve(int i, int n,
              vector<int>& present,
              vector<int>& boss,
              vector<int>& future,
              int budget,
              vector<int>& purchase,
              vector<int>& topo) {

        if (i == n) return 0;          // ✅ correct base
        if (budget < 0) return -1e9;

        int node = topo[i];            // ✅ correct index
        int price = present[node - 1];

        // ✅ safe boss check
        if (boss[node] != 0 && purchase[boss[node]])
            price /= 2;

        // Skip option
        int skip = solve(i + 1, n, present, boss, future, budget, purchase, topo);

        // Take option
        int take = -1e9;
        if (price <= budget) {
            purchase[node] = 1;
            take = (future[node - 1] - price)
                   + solve(i + 1, n, present, boss, future,
                           budget - price, purchase, topo);
            purchase[node] = 0;
        }

        return max(take, skip);
    }
};
