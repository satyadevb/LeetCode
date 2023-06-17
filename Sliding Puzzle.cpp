class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& b) {
        string s = "";
        string f = "123450";
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 3;j++){
                s.append(to_string(b[i][j]));
            }
        }
        string x,y;
        int t;
        unordered_map<string,int> m;
        queue<pair<string,int>> q;
        q.push(make_pair(s,0));
        while(q.size()){
            x = q.front().first;
            t = q.front().second;
            if(x == f){
                return t;
            }
            q.pop();
            int p = -1;
            for(int i = 0;i < 6;i++){
                if(x[i] == '0'){
                    p = i;
                }
            }
            if((p != 0)&&(p != 3)){
                y = x;
                swap(y[p],y[p - 1]);
                if(!m[y]){
                    q.push(make_pair(y,t+1));
                    m[y] = 1;
                }
            }//else if()
            if((p != 2)&&(p != 5)){
                y = x;
                swap(y[p],y[p + 1]);
                if(!m[y]){
                    q.push(make_pair(y,t+1));
                    m[y] = 1;
                }
            }
            if(p >= 3){
                y = x;
                swap(y[p],y[p - 3]);
                if(!m[y]){
                    q.push(make_pair(y,t+1));
                    m[y] = 1;
                }
            }
            if(p < 3){
                y = x;
                swap(y[p],y[p + 3]);
                if(!m[y]){
                    q.push(make_pair(y,t+1));
                    m[y] = 1;
                }
            }
        }
        return -1;
    }
};