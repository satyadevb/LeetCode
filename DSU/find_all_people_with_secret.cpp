
class UnionFind{
public:
    vector<int> root;
    int num;
    UnionFind(int n) {
        num = n;
        for (int i = 0; i <= n; i++) {
            root.push_back(i);
        }
    }
    
    int find(int x) {
        if (root[x] == x) {
            return x;
        }
        
        return root[x] = find(root[x]);
    }
    
    int join(int x, int y) {       
        x = find(x); y = find(y);
        
        if (x == y) {
            return 0;
        }
        if(x == 0){
            root[y] = x;
        }else{
            root[x] = y;
        }
        num--;
        return 1;
    }    
    int num_components() {
        return num;
    }
};

class Solution {
    static bool compare( vector<int> &v1, vector<int> &v2)
    {
        if(v1[2] < v2[2]){
            return true;
        }
        return false;
    }
    
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        UnionFind u(n);
        u.join(0,firstPerson);
        sort(meetings.begin(),meetings.end(),compare);
        vector<int> ans;
        int time;
        for(int i = 0;i < meetings.size();i++){
            time = meetings[i][2];
            int j = i;
            while((i < meetings.size()) && (meetings[i][2] == time)){
                u.join(meetings[i][0],meetings[i][1]);
                i++;
            }
            while(j < i){
                if((u.find(meetings[j][0]) != 0)&&(u.find(meetings[j][1]) != 0)){
                    u.root[meetings[j][0]] = meetings[j][0];
                    u.root[meetings[j][1]] = meetings[j][1];
                }
                j++;
            }
            i--;
        }
        for(int i = 0;i < n;i++){
            if(u.find(i) == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
