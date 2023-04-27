int maxDepth(char * s){
    int sz = strlen(s);
    int i =0;
    int max=0,count=0;
    //直接遍历整个数组
    for(i=0;i<sz;i++)
    {
        //遇到左括号，计数
        if(s[i]=='('){
            count++;
            if(count>max){
                //如果比max大就替换max
                max=count;
            }
        }//遇到右括号--
        else if(s[i]==')'){
            count--;
        }
    }
    return max;
}
//1614. 括号的最大嵌套深度
//https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/submissions/
// 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
// 内存消耗：5.5 MB, 在所有 C 提交中击败了39.07%的用户
