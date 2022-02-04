/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // o ([ - ])x
        // [ - ] x x [ - - - - - ] x x x
        // x [ - - - ] x x [ - - - - ] x
        int f_bs = firstList.size();
        int s_bs = secondList.size();
        int f_bi = 0;
        int s_bi = 0;
        vector<vector<int>> result;

        while(f_bi < f_bs && s_bi < s_bs){
            int f_l = firstList.at(f_bi).at(0);
            int f_r = firstList.at(f_bi).at(1);
            int s_l = secondList.at(s_bi).at(0);
            int s_r = secondList.at(s_bi).at(1);


            //case 1. A, B not overlapped 
            if(f_r < s_l) {
                f_bi++;
                continue;
            }
            //case 2. B, A not overlapped
            if(s_r < f_l){
                s_bi++;
                continue;
            }

            //case 3. A, B overlapped
            result.push_back({max(f_l, s_l), min(f_r, s_r)});
            if(f_r > s_r) s_bi++;
            else if(f_r == s_r){
                s_bi++;
                f_bi++;
            } 
            else f_bi++;// f_r < s_r
        }
        return result;
    }
};
// @lc code=end

