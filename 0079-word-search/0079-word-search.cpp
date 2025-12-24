#define ll long long
class Solution {
public:
    bool recursion(vector<vector<char>> &a,
                   vector<vector<ll>> &marked,
                   string &word,
                   int i, int size, int n, int m,
                   pair<int,int> last) {

        if (i >= size) return true;

        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < m; jj++) {

                if (word[i] == a[ii][jj] && marked[ii][jj] == 0) {

                    // adjacency check with PREVIOUS cell
                    if (abs(ii - last.first) + abs(jj - last.second) != 1)
                        continue;

                    marked[ii][jj] = 1;
                    pair<int,int> newLast = {ii, jj};

                    if (recursion(a, marked, word, i + 1, size, n, m, newLast))
                        return true;

                    marked[ii][jj] = 0;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<ll>> marked(n, vector<ll>(m, 0));

        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < m; jj++) {
                if (word[0] == board[ii][jj]) {
                    marked[ii][jj] = 1;
                    if (recursion(board, marked, word, 1, word.size(), n, m, {ii, jj}))
                        return true;
                    marked[ii][jj] = 0;
                }
            }
        }
        return false;
    }
};
