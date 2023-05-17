class UnionFind {
    vector<int> root;
    vector<int> csize;
    int num;
    
public:
    UnionFind(int n) {
        num = n;
        for (int i = 0; i <= n; i++) {
            root.push_back(i);
            csize.push_back(1);
        }
    }
    
    int find(int x) {
        if (root[x] == x) {
            return x;
        }
        
        return root[x] = find(root[x]);
    }
    
    int join(int x, int y){       
        x = find(x);y = find(y);
        if (x == y) {
            return 0;
        }
        if (csize[x] > csize[y]) {
            csize[x] += csize[y];
            root[y] = x;
        } else {
            csize[y] += csize[x];
            root[x] = y;
        }
        
        num--;
        return 1;
    }

    int size(int i) {
        return csize[find(i)];
    }
    int comp() {
        return num;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        UnionFind u(n*n);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    if(i != 0){
                        if(grid[i-1][j] == 1){
                            u.join(i*n + j,(i-1)*n + j);
                        }
                    }
                    if(j != 0){
                        if(grid[i][j-1] == 1){
                            u.join(i*n + j,i*n + j - 1);
                        }
                    }
                }
            }
        }
        int s,sm = 0;
        vector<int> v;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                v.clear();
                sm = max(sm,u.size(i*n+j));
                if(grid[i][j] == 0){
                    if(i != 0){
                        if(grid[i-1][j] == 1){
                            v.push_back(u.find( (i-1)*n + j));
                        }    
                    }
                    if(j != 0){
                        if(grid[i][j-1] == 1){
                            v.push_back(u.find(i*n + j - 1));
                        }
                    }
                    if(i != n-1){
                        if(grid[i+1][j] == 1){
                            v.push_back(u.find((i+1)*n + j));
                        }
                    }
                    if(j != n-1){
                        if(grid[i][j+1] == 1){
                            v.push_back(u.find(i*n + j + 1));
                        }
                    }
                    sort(v.begin(),v.end());
                    int p = 0,q = 0;
                    while(p < v.size()){
                        q = p + 1;
                        while(q < v.size()){
                            if(v[p] == v[q]){
                                v.erase(v.begin() + q);
                            }else{
                                break;
                            }
                        }
                        p = q;
                    }
                    s = 0;
                    for(int x = 0;x < v.size();x++){
                        s = s + u.size(v[x]);
                    }
                    sm = max(s + 1,sm);
                }
            }
        }  
        return sm;
    }
};