class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<long long,long long>> v;long long sum1 = 0,sum = 0;
        for(int j = 0;j < nums.size();j++){
            sum = sum + cost[j];
            v.push_back(make_pair(nums[j],cost[j]));
        }
        sort(v.begin(),v.end());
        vector<int> cost1;int i;
        for(i = 0;i < nums.size();i++){
            sum1 = sum1 + v[i].second;
            if(2*sum1 >= sum){
                break;
            }
        }
        int num = v[i].first;
        long long res = 0;
        for(int j = 0;j < nums.size();j++){
            res = res + v[j].second*(abs(v[j].first - num));
        }
        return res;
    }
};
