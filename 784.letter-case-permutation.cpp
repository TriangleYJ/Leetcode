/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        string status (s.size(), '.');
        vector<string> result;
        letterCasePermutationStep(s, result, status, 0);
        return result;
    }

    void letterCasePermutationStep(string s, vector<string>& result, string& status, int step){
        if(step == s.size()){
            result.push_back(string(status));
            return;
        }
        char c = s.at(step);
        status.at(step) = c;
        letterCasePermutationStep(s, result, status, step+1);
        if(c >= 'a' && c <= 'z') {
            status.at(step) = c - ('a'-'A');
            letterCasePermutationStep(s, result, status, step+1);
        } else if(c >= 'A' && c <= 'Z') {
            status.at(step) = c + ('a'-'A');
            letterCasePermutationStep(s, result, status, step+1);
        }
    }
};
// @lc code=end

