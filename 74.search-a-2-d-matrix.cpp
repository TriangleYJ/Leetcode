/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
private:
    int w;
    int h;
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        h = matrix.size();
        w = matrix.at(0).size();

        int left = 0;
        int right = w * h - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(get(mid, matrix) < target) left = mid+1;
            else if(get(mid, matrix) >= target) right = mid;
        }
        if(get(left, matrix) == target) return true;
        else return false;
    }

    int get(int idx, vector<vector<int>>& matrix){
        return matrix.at(idx / w).at(idx % w);
    } 
    
};
// @lc code=end

