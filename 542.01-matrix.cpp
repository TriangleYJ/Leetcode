/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int h = mat.size();
        int w = mat.at(0).size();
        //vector<vector<int>> result(h, vector<int> (w, 0));
        queue<int> zero_xs;
        queue<int> zero_ys;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (mat.at(y).at(x) == 0) {
                    zero_xs.push(x);
                    zero_ys.push(y);
                } else
                    mat.at(y).at(x) = -1;
            }
        }

        int distance = 0;

        const int dy[4] = {0, -1, 0, 1};
        const int dx[4] = {-1, 0, 1, 0};
        while (!zero_xs.empty()) {
            int cur_size = zero_xs.size();
            for (int i = 0; i < cur_size; i++) {
                int x = zero_xs.front();
                zero_xs.pop();
                int y = zero_ys.front();
                zero_ys.pop();
                mat.at(y).at(x) = distance;
                
                // 4-side check
                const bool c[4] = {x > 0, y > 0, x < w - 1, y < h - 1};
                for (int j = 0; j < 4; j++) {
                    if (c[j] && mat.at(y + dy[j]).at(x + dx[j]) == -1) {
                        mat.at(y + dy[j]).at(x + dx[j]) = 0;  // lock
                        zero_xs.push(x + dx[j]);
                        zero_ys.push(y + dy[j]);
                    }
                }
            }
            distance++;
        }
        return mat;
    }
};
// @lc code=end
