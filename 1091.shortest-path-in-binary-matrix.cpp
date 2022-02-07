/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
   private:
    int w;
    int h;
    int d[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        h = grid.size(), w = grid.at(0).size();
        queue<vector<int>> q;
        if(grid.at(0).at(0) == 1) return -1;
        grid.at(0).at(0) |= 2;
        q.push({0, 0});
        
        while(!q.empty()){
            int x = q.front().at(0), y = q.front().at(1);
            int dist = grid.at(y).at(x) >> 1;
            if(y == h - 1 && x == w - 1) return dist;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int dx = x + d[i][0], dy = y + d[i][1];
                if(0 <= dx && dx < w && 0 <= dy && dy < h){
                    int dval = grid.at(dy).at(dx);
                    int ddist = dval >> 1;
                    if((dval & 1) == 0 && ddist == 0){
                        grid.at(dy).at(dx) |= ((dist + 1) << 1);
                        q.push({dx, dy});
                    }
                }
            }
        }

        return -1;
    }
};
// @lc code=end
