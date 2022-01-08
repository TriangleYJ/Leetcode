class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = nums.size();
        int zi = 0;
        
        //first zero index <-> first nonzero index && nzi > zi
        while(1){
            while(zi < l && nums.at(zi) != 0) zi++;
            if(zi == l) break;
            int nzi = zi+1;
            while(nzi < l && nums.at(nzi) == 0) nzi++;
            if(nzi == l) break;
            
            //nzi <-> zi
            nums.at(zi) = nums.at(nzi);
            nums.at(nzi) = 0;
            
        }
    }
};