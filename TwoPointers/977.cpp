// O(n) solution?
// 주어진 데이터가 정렬되있기 때문에 양 끝의 제곱 중 더 큰것을 새로운 output의 뒤쪽부터 채워 넣는다.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> snums;
        for(int i : nums){
            snums.push_back(i*i);
        }
        sort(snums.begin(), snums.end());
        return snums;
        
    }
};