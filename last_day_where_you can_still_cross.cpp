class UnionFind{
public:
    vector<int> root;
    vector<int> csize;
    int num;
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
    
    int join(int x, int y) {       
        x = find(x); y = find(y);
        
        if (x == y) {
            return 0;
        }
        if(x == 0){
            csize[x] += csize[y];
            root[y] = x;
        }else{
            csize[y] += csize[x];
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
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        UnionFind u(row*col+2);
        vector<int> grid(row*col+2,1);
        vector<int> elem;
        int top,bottom,left,right,curr;
        for(int i = cells.size()-1;i > 0;i--){
            elem = cells[i];
            (elem[0])--;(elem[1])--;
            curr = col*elem[0] + elem[1] + 1;
            grid[curr] = 0;
            if(elem[0] == 0){
                top = 0;
                u.join(curr,top);
            }else{
                top = col*(elem[0]-1) + elem[1] + 1;
                if(grid[top] == 0){
                    u.join(curr,top);
                }
            }
            if(elem[0] == row-1){
                bottom = row*col + 1;
                u.join(curr,bottom);
            }else{
                bottom = col*(elem[0]+1) + elem[1] + 1;
                if(grid[bottom] == 0){
                    u.join(curr,bottom);
                }
            }
            if(elem[1] == 0){
                left = curr;
            }else{
                left = col*(elem[0]) + elem[1];
                if(grid[left] == 0){
                    u.join(curr,left);
                }
            }
            if(elem[1] == col-1){
                right = curr;
            }else{
                right = col*(elem[0]) + elem[1] + 2;
                if(grid[right] == 0){
                    u.join(curr,right);
                }
            }
            if(u.find(0) == u.find(row*col+1)){
                return i;
            }
        }
        return 0;
    }
};