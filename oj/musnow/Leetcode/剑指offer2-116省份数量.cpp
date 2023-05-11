//采用的是并查集的思想
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

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        vector<int> v(isConnected.size(),-1);
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    int root1 = FindRoot(v,i);
                    int root2 = FindRoot(v,j);
                    if(root1!=root2)
                    {
                        v[root1] += v[root2];
                        v[root2] = root1;
                    }
                }
            }
        }

        int count = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<0)
            {
                count++;
            }
        }

        return count;
    }
};

//https://leetcode.cn/problems/bLyHh0/submissions/386166975/
