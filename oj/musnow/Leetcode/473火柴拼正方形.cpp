class Solution {
    bool _makesquare(vector<int>& matchsticks,vector<int>& bucket,int target,int index) {
        if(index>=matchsticks.size()){
            return true;
        }
        for(int i = 0;i<bucket.size();i++)
        {
            if(bucket[i] + matchsticks[index] > target){
                continue;
            }
            if(i > 0 && bucket[i]== bucket[i-1]){
                continue;
            }
            bucket[i] += matchsticks[index];
            if(_makesquare(matchsticks,bucket,target,index+1)){
                return true;
            }
            bucket[i] -= matchsticks[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto&i:matchsticks){
            sum+=i;
        }
        // 不能整除4，不可能围城正方形
        if(sum % 4 !=0){
            return false;
        }
        int target = sum / 4;
        vector<int> bucket(4,0);
        sort(matchsticks.begin(),matchsticks.end());
        return _makesquare(matchsticks,bucket,target,0);
    }
};