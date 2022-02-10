/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
    const vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string tmp = "";
    string d;
    vector<string> results;

public:
    vector<string> letterCombinations(string digits) {
        d = digits;
        if(digits.length() == 0) return {};
        step(0);
        return results;
    }

    void step(int idx){
        if(idx == d.size()){
            results.push_back(tmp);
            return;
        }
        for(char c: letters.at(d.at(idx) - '2')){
            tmp += c;
            step(idx+1);
            tmp.pop_back();
        }
    }
};
// @lc code=end

