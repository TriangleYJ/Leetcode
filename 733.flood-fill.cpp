/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start

class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.at(sr).at(sc) != newColor) step(image, sr, sc, newColor);
        return image;
    }

    void step(vector<vector<int>>& image2, int r, int c, int newColor) {
        int h = image2.size();
        int w = image2.at(0).size();
        int pix = image2.at(r).at(c);
        image2.at(r).at(c) = newColor;
        if ((c > 0) && image2.at(r).at(c - 1) == pix)
            step(image2, r, c - 1, newColor);
        if ((r > 0) && image2.at(r - 1).at(c) == pix)
            step(image2, r - 1, c, newColor);
        if ((c < w - 1) && image2.at(r).at(c + 1) == pix)
            step(image2, r, c + 1, newColor);
        if ((r < h - 1) && image2.at(r + 1).at(c) == pix)
            step(image2, r + 1, c, newColor);
        
    }
};
// @lc code=end
