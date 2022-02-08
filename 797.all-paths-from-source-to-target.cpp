/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        return pathsFromSource(0, graph);
    }

    vector<vector<int>> pathsFromSource(int index, vector<vector<int>>& graph){
        vector<int> nexts = graph.at(index);
        vector<vector<int>> ans;
        if(index == graph.size() - 1){
            vector<int> tmp(1, graph.size() - 1);
            ans.push_back(tmp);
            return ans;
        };
        for(int i : nexts){
            vector<vector<int>> npaths = pathsFromSource(i, graph);
            for(vector<int> npath: npaths){
                vector<int> tmp;
                tmp.push_back(index);
                for(int n: npath){
                    tmp.push_back(n);
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
// @lc code=end

