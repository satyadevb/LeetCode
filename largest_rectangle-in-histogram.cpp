#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack<int> s;
        s.push(-1);
        int n = v.size();
        int area = v[0],i = 0;
        vector<int> pre(n, -1),succ(n, n);
        while(i < n){
            while((!s.empty()) && (s.top()!=-1) && (v[s.top()] > v[i])){
                succ[s.top()] = i;
                s.pop();
            }
            s.push(i);
            i++;
        }
        i = n - 1;
        stack<int> s2;
        s2.push(n);
        while(i >= 0){
            while((!s2.empty()) && (s2.top() != n) && (v[s2.top()] > v[i])){
                pre[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
            i--;
        }
    for(int i = 0;i < n; i++){
        area = max(area, v[i]*(succ[i] - pre[i] - 1));
    }
    return area;
    }
};
