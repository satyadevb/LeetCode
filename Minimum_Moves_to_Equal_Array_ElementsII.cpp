
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            if(i < nums.size()/2){
                sum = sum + nums[nums.size()/2] - nums[i];
            }else{
                sum = sum - nums[nums.size()/2] + nums[i];
            }
        }
        return sum;
    }
};
