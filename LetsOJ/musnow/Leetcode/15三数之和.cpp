class Solution {
public:
    //错误解法，没有解决去重问题
    vector<vector<int>> test1(vector<int>& nums)
    {
        int i=0,j=0,k=0,sum,md5;
        vector<vector<int>> ret;
        unordered_set<int> st;
        int sz = nums.size();
        // 暴力解法，三个遍历
        // 还需要考虑元组的顺序问题
        for(i=0;i<sz-2;i++)
        {
            for(j=i+1;j<sz-1;j++)
            {
                for(k=j+1;k<sz;k++)
                {
                    sum=nums[i]+nums[j]+nums[k];
                    if(sum==0)
                    {
                        cout << nums[i]<<" " <<nums[j]<<" " <<nums[k]<<endl;
                        //插入
                        md5 = nums[i]&nums[j]&nums[k];
                        cout << "md " << md5<<endl;
                        if(st.find(md5)==st.end())
                        {
                            st.insert(md5);
                            ret.push_back(vector<int>({nums[i],nums[j],nums[k]}));
                        }
                    }
                }
            }
        }
        return ret;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i =0,left=1,right=nums.size()-1;
        sort(nums.begin(),nums.end());// 先排序，正序
        vector<vector<int>> ret;
        // for(auto&e:nums){
        //     cout << e <<" ";
        // }
        // cout << " sorted" << endl;
        int sum=100;
        for(i=0;i<nums.size()-2;i++)
        {
            //正序，第一个元素都大于0了，整个数组都大于0，不可能出现三数和为0的情况
            if(nums[i]>0){
                return ret;
            }
            // 这里必须要判断i和i-1，而不是判断i和i+1
            // -1 -1 2 3
            //  i  L R
            // 如果判断i和i+1，则会跳过上面[-1 -1 2]这个正确的结果
            // -1 -1 2 3 
            //     i L R
            // 如上，判断i和i-1相等，则代表当前i所处位置的-1往后如果存在结果集，其实已经被前面那个-1给收纳进去了
            // 这里因为我们数据是有序的，所以不可能会出现漏掉的情况
            // -1 -1 0 1 3
            //  i    L R
            // 比如这种情况的数组，我们能找到一个结果集为-1 0 1
            // -1 -1 0 1 3
            //     i L R
            // i往后移动，此时收集到的结果集依旧是-1 0 1，这个是已经存在了的！
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            left=i+1;
            right=nums.size()-1;//最后一个元素
            while(left<right)
            {   
                sum=nums[i]+nums[left]+nums[right];
                if(sum>0)//大于零缩小右边界
                    right--;
                else if(sum<0)//小于0缩小左边界
                    left++;
                else{
                    //cout << i << " " << left<<" " << right << endl;
                    ret.push_back({nums[i],nums[left],nums[right]});
                    // 这里和i的情况不同，有一个数字已经固定了，所以可以继续缩小找其他的
                    while(left<right && nums[right]==nums[right-1])
                        right--;
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    // 走完这两个while，left和right依旧是处在和最开始的数字相同的数字上，所以还需要缩小一次
                    // -1 -1 -1 -1 -1 0 1 1 1 1
                    //  i             L       R
                    // 开始走循环，R不断--
                    // -1 -1 -1 -1 -1 0 1 1 1 1
                    //  i             L R
                    // 此时循环会停止，因为nums[right]!=nums[right-1]
                    left++;
                    right--;
                }
            }
        }    
        return ret;
    } 
    //https://www.bilibili.com/video/BV1GW4y127qo/
    //https://leetcode.cn/problems/3sum/
};