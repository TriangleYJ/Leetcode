/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
    int w, h;
    vector<vector<char>> _board;
    string _word;
    const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    bool exist(vector<vector<char>>& board, string word) {
        h = board.size(), w = board.at(0).size();
        _board = board, _word = word;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (board.at(y).at(x) == word.at(0))
                    if (step(x, y, 0)) return true;
            }
        }
        return false;
    }

    bool step(int x, int y, int s) {
        if (s == _word.length()) return true;
        if(!(x >= 0 && y >= 0 && x < w && y < h)) return false;
        if (_board.at(y).at(x) != _word.at(s)) return false;
        _board.at(y).at(x) = '-';
        bool least_one = false;
        for (int i = 0; i < 4; i++) {
            int dx = x + d[i][0], dy = y + d[i][1];
            if(step(dx, dy, s + 1)) least_one = true;
        }
        _board.at(y).at(x) = _word.at(s);
        return least_one;
    }
};
// @lc code=end
