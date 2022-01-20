/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid.at(0).size();

        queue<int> rotten_xs;
        queue<int> rotten_ys;
        int fresh_num = 0;
        int time = 0;

        // init
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (grid.at(y).at(x) == 2) {
                    rotten_xs.push(x);
                    rotten_ys.push(y);
                } else if (grid.at(y).at(x) == 1)
                    fresh_num++;
            }
        }

        //bfs - rottening
        const int dy[4] = {0, -1, 0, 1};
        const int dx[4] = {-1, 0, 1, 0};
        while (!rotten_xs.empty()) {
            int cur_size = rotten_xs.size();
            for (int i = 0; i < cur_size; i++) {
                int x = rotten_xs.front();
                rotten_xs.pop();
                int y = rotten_ys.front();
                rotten_ys.pop();
                
                const bool c[4] = {x > 0, y > 0, x < w - 1, y < h - 1};
                for (int j = 0; j < 4; j++) {
                    if (c[j] && grid.at(y + dy[j]).at(x + dx[j]) == 1) {
                        grid.at(y + dy[j]).at(x + dx[j]) = 2;  // lock
                        fresh_num--;
                        rotten_xs.push(x + dx[j]);
                        rotten_ys.push(y + dy[j]);
                    }
                }
            }
            time++;  // time++ should be ignored at last iteration
        }

        //check there is fresh orange
        if (fresh_num == 0)
            return time >= 1 ? time - 1 : 0;
        else
            return -1;
    };
};
// @lc code=end
