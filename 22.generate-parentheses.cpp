/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
private:
    string tmp = "";
    vector<string> results;
    int N;

public:
    vector<string> generateParenthesis(int n) {
        N = n;
        step(0, 0);
        return results;
    }

    void step(int s, int lvl){
        if(lvl < 0) return;
        if(s == 2 * N){
            if(lvl == 0) results.push_back(tmp);
            return;
        }
        tmp += "(";
        step(s+1, lvl+1);
        tmp.pop_back();
        tmp += ")";
        step(s+1, lvl-1);
        tmp.pop_back();
    }
};
// @lc code=end

