class Solution {
    long long int mod = pow(10,9) + 7;
    vector<vector<long long int>> comb;
    long long int count(vector<int> nums){
        if(nums.size() <= 2){
            return 1;
        }
        vector<int> l,r;
        int root = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(nums[i] > nums[0]){
                r.push_back(nums[i]);
            }else{
                l.push_back(nums[i]);
            }
        }
        long long int c = comb[nums.size() - 1][l.size()];
        long long lv = count(l) % mod;
        long long rv = count(r) % mod; 
        c = (((c * lv) % mod) * rv) % mod;
        return c;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> v(n+1,0);
        for(int i = 0;i <= n;i++){
            comb.push_back(v);
        }    
        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= i;j++){
                if(i == j){
                    comb[i][j] = 1;
                }else if(j == 0){
                    comb[i][j] = 1;
                }else{
                    comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%mod;  
                }   
            }
        }
        return count(nums) - 1;
    }
};