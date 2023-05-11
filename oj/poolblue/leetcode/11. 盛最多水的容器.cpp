//https://leetcode.cn/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
    //双指针
    int left =0;
    int right=height.size()-1;
    int res=0;
    //双边向中遍历
     while(left<right)
     {   //容纳水的高度由短板决定
         //找短板往中间递减，因为长板向中递减，面积一定变小，短板往中递减，面积可能会增加
        res= height[left] > height[right] ?
        max(res,(right-left)*height[right--]):
        max(res,(right-left)*height[left++]);
     }
     return res;
    }
};
