# IP地址无效化

[1108. IP 地址无效化 - 力扣（LeetCode）](https://leetcode.cn/problems/defanging-an-ip-address/submissions/)

![image-20220621091834517](https://biji-ssw.oss-cn-beijing.aliyuncs.com/obsidian/202206210918705.png)

题目要求使用[.]来代替.

很简单我们使用string的replace接口即可.

![image-20220621093705272](https://biji-ssw.oss-cn-beijing.aliyuncs.com/obsidian/202206210937432.png)

我们使用红框圈住的接口来使用.

代码如下

```cpp
class Solution {
public:
    string defangIPaddr(string address) 
    {
        int i = 0;
        const char* c = "[.]";
        while(address[i] != '\0')
        {
            if(address[i] == '.')
            {
                address.replace(i,1,c);
                i+=2;//当我们替换了之后要记得将i的位置向后移动不然会死循环.
            }
            i++;
        }
        return address;
    }
};
```
