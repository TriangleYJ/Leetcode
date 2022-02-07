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
    int d[5][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {0, 0}};
    int dc[8][2] = {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {0, 1}, {0, 3}, {1, 2}, {2, 3}};
    vector<vector<int>> g;

   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        h = grid.size(), w = grid.at(0).size(), g = grid;
        if(g.at(0).at(0) == 1) return -1;
        g.at(h-1).at(w-1) |= 8;
        return distanceToBR(0, 0);
    }

    int distanceToBR(int y, int x) {
        // _ _ _ _ _ _ _ _
        // 0. original bit
        // 1. lock bit
        // 2. distance = -1
        // 3~. distance > 0
        int val = g.at(y).at(x);
        if(val & 4) return -1;
        if(val >> 3) return val >> 3;
        
        int dist = 300;
        int c[5] = {x + 1 < w, y + 1 < h, x - 1 > 0, y - 1 > 0, 1};
        if(!c[0] && !c[1]) return 1; // end
        g.at(y).at(x) |= 2; // lock

        for (int i = 0; i < 8; i++) {
            int dc1 = dc[i][0], dc2 = dc[i][1];
            if(c[dc1] && c[dc2]){
                int dx = x + d[dc1][0] + d[dc2][0], dy = y + d[dc1][1] + d[dc2][1];
                if(g.at(dy).at(dx) & 2) continue;
                int n_d = distanceToBR(dy, dx);
                printf("%d %d %d\n", dx, dy, n_d);
                if(n_d == -1) continue;
                if ((g.at(dy).at(dx) & 1) == 0) dist = min(dist, n_d + 1);
            }
        }
        g.at(y).at(x) ^= 2; // unlock

        if(dist == 300){
            g.at(y).at(x) |= 4;
            return -1;
        }

        g.at(y).at(x) |= (dist << 3);
        return dist;
    }
};
// @lc code=end
