//https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?tpId=167&tqId=34050&ru=/exam/oj
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        if(gifts[0] == 339){
            cout << "test  " << n <<endl;
        }
        sort(gifts.begin(),gifts.end());
        int max = gifts[n/2];//排序了之后，超过一半的数肯定在中间
        int count =0;
        for(auto&e:gifts)
        {
            if(e==max){
                count++;
            }
        }
        //遍历确认其超过了一半
        if(count>=n/2){
            return max;
        }
        return 0;

        // 下面这种办法有些情况无法正常判断
        // if(gifts[n/2-1]!=gifts[n/2] && gifts[n/2+1]!=gifts[n/2])
        // {
        //     return 0;
        // }
        // return gifts[n/2];
    }
};
