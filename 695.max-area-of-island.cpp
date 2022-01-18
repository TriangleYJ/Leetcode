/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid.at(0).size();
        int mmax = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int pix = grid.at(y).at(x);
                int area;
                if (pix == 1){
                    area = step(grid, y, x, w, h);
                    mmax = mmax < area ? area : mmax;
                }
            }
        }
        return mmax;
    }
    int step(vector<vector<int>>& grid, int y, int x, int w, int h) {
        int area = 1;
        grid.at(y).at(x) = 0;
        if ((x > 0) && grid.at(y).at(x - 1) == 1)
            area += step(grid, y, x - 1, w, h);
        if ((y > 0) && grid.at(y - 1).at(x) == 1)
            area += step(grid, y - 1, x, w, h);
        if ((x < w - 1) && grid.at(y).at(x + 1) == 1)
            area += step(grid, y, x + 1, w, h);
        if ((y < h - 1) && grid.at(y + 1).at(x) == 1)
            area += step(grid, y + 1, x, w, h);
        return area;
    }
};
// @lc code=end
