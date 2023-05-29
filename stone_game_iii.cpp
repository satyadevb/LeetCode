class Solution {
public:
    string stoneGameIII(vector<int>& s) {
        int n = s.size();
        vector<pair<int,int>> d(n+1,make_pair(INT_MIN,INT_MIN));
        d[n].first = 0;d[n].second = 0;
        for(int i = n - 1;i >=0;i--){
            if(i == n - 1){
                d[i].first = s[n-1];
                d[i].second = 0;
            }else if(i == n - 2){
                d[i].first = d[i+1].second + s[i];
                d[i].second = d[i+1].first;
                if(d[i].first < d[i+2].second + s[i] + s[i+1]){
                    d[i].first = d[i+2].second + s[i] + s[i+1];
                    d[i].second = d[i+2].first;
                }
            }else{
                d[i].first = d[i+1].second + s[i];
                d[i].second = d[i+1].first;
                if(d[i].first < d[i+2].second + s[i] + s[i+1]){
                    d[i].first = d[i+2].second + s[i] + s[i+1];
                    d[i].second = d[i+2].first;
                }
                if(d[i].first < d[i+3].second + s[i] + s[i+1] + s[i+2]){
                    d[i].first = d[i+3].second + s[i] + s[i+1] + s[i+2];
                    d[i].second = d[i+3].first;
                }
            }
        }
        if(d[0].first > d[0].second){
            return "Alice";
        }else if(d[0].first < d[0].second){
            return "Bob";
        }else{
            return "Tie";
        }
    }
};