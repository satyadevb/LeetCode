class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> v;
        sort(cuts.begin(),cuts.end());
        for(int i = 0;i < cuts.size();i++){
            v.push_back(cuts[i]);
        }
        v.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m + 1,vector<int> (m + 1,INT_MAX));
        for(int i = 0;i <= m;i++){
            dp[i][i] = 0;
        }
        for(int l = 1;l <= m;l++){
            for(int j = 0;j <= m - l;j++){
                if(l == 1){
                    if(j == 0){
                        dp[j][j+l] = v[j + l];
                    }else{
                        dp[j][j+l] = v[j + l] - v[j - 1];
                    }
                }else{
                    for(int k = 0;k < l;k++){
                        if(j == 0){
                            dp[j][j+l] = min(dp[j][j+l], v[j + l] + dp[j][j + k] + dp[j + k + 1][j + l]);
                        }else{
                            dp[j][j+l] = min(dp[j][j+l], v[j + l] - v[j - 1] + dp[j][j + k] + dp[j + k + 1][j + l]);
                        }
                    }
                }

            }
        }
        return dp[0][m];
    }
};

