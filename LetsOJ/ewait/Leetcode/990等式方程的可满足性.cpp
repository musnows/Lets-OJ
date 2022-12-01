class Solution {
public:
    int FindRoot(const vector<int>& v,int n)
    {
        int prev = n;//初始下标
        while(v[prev]>=0)//它的父亲下标
        {
            prev=v[prev];//如果不为负数，那就还是需要往前找
        }
        return prev;
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> v(26,-1);//因为题目给的都是小写字母，直接建立26个小写字母的映射表
        for(int i=0;i<equations.size();i++)
        {
            int root1 = FindRoot(v,equations[i][0]-'a');//第一个字母
            int root2 = FindRoot(v,equations[i][3]-'a');//第二个字母
            if(equations[i][1]=='=')//代表等于
            {
                if(root1!=root2)
                {//设置为一个集合中的元素
                    v[root1] += v[root2];
                    v[root2] = root1;
                }
            }
            else//不等于
            {
                if(root1==root2)
                {
                    //如果不等于的同时，根还相同
                    //说明是同一个集合，不符合题意
                    return false;
                }
            }
        }

        //还需要遍历第二遍，避免漏网之鱼
        for(int i=0;i<equations.size();i++)
        {
            int root1 = FindRoot(v,equations[i][0]-'a');//第一个字母
            int root2 = FindRoot(v,equations[i][3]-'a');//第二个字母
            if(equations[i][1]=='!')//不等于
            {
                if(root1==root2)
                {
                    //如果不等于的同时，根还相同
                    //说明是同一个集合，不符合题意
                    return false;
                }
            }
        }

        return true;
    }
};
//https://leetcode.cn/problems/satisfiability-of-equality-equations/description/
