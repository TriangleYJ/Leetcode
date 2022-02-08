/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
   private:
    int w, h;
    const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    void solve(vector<vector<char>>& board) {
        h = board.size(), w = board.at(0).size();

        for (int i = 0; i < w; i++) {
            spreadQ(i, 0, board);
            spreadQ(i, h - 1, board);
        }
        for (int i = 1; i < h - 1; i++) {
            spreadQ(0, i, board);
            spreadQ(w - 1, i, board);
        }

        for (int j = 0; j < h; j++) {
            for (int i = 0; i < w; i++) {
                int val = board.at(j).at(i);
                if (val == 'Q')
                    board.at(j).at(i) = 'O';
                else if (val == 'O')
                    board.at(j).at(i) = 'X';
            }
        }
    }

    void spreadQ(int initx, int inity, vector<vector<char>>& board) {
        char c = board.at(inity).at(initx);
        if (c == 'O') {
            queue<pair<int, int>> q;
            q.push({initx, inity});
            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if (board.at(y).at(x) == 'O') {
                    board.at(y).at(x) = 'Q';
                    for (int i = 0; i < 4; i++) {
                        int dx = x + d[i][0], dy = y + d[i][1];
                        if (dx >= 0 && dx < w && dy >= 0 && dy < h) {
                            q.push({dx, dy});
                        }
                    }
                }
            }
        }
    }
};
// @lc code=end
