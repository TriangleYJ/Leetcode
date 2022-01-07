// in-place solution?
// 뒤에서 n번째까지의 list를 reverse, 그에 해당하지 않는 나머지 리스트 reverse, 전체 reverse 를 하면 됨

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n);
        for(int i = 0; i < n; i++){
            int shift_pos = i + k;
            shift_pos = shift_pos % n;
            ret.at(shift_pos) = nums.at(i);
        }
        
        nums = ret;
    }
};