class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> res,list;
        int j,low,high,mid;
        for(int i = 0;i < n;i++){
            
            low = 0;
            high = list.size();
            while(low < high){
                mid = (low + high)/2;
                if(obstacles[i] >= list[mid]){
                    low = mid + 1;
                }else{
                    high = mid;
                }
            }
            mid = (low + high)/2;
            j = mid;
            cout << mid << " ";
            if(j == list.size()){
                list.push_back(obstacles[i]);
            }else{
                list[j] = obstacles[i];
            }
            res.push_back(j + 1);
        }
        return res;
    }
};