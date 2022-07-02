//https://leetcode.cn/problems/first-unique-character-in-a-string/submissions/
//387. 字符串中的第一个唯一字符
class Solution {
public:
    int firstUniqChar(string s) {
        int* arr=(int*)calloc(26,sizeof(int));
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
        }

        for(int i=0;i<s.size();i++)
        {
            if(arr[s[i]-'a']==1){
                free(arr);//避免内存泄漏
                return i;//再次通过映射查找，找到以后返回
            }
        }
        free(arr);
        return -1;
    }
};