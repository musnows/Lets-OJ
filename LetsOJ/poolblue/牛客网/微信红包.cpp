class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        //众数法
        sort(gifts.begin(),gifts.end());//进行排序，中间的金额为众数
        int mid_val=gifts[n/2];
        int count=0;
        for(const auto& g:gifts)
        {
            if(g==mid_val)//计数
                count++;
        }
          if(count>n/2)//如果大于n/2,返回金额
          return mid_val;
        
        return 0;
    }
};
// class Gift {
// public:
//     int getValue(vector<int> gifts, int n) {
//         //哈希映射
//        map<int,int> redgift;
//         for(const auto& e : gifts)
//         {   
//             //计数
//             redgift[e]++;
//         }

//         for(auto& r :redgift)
//         {   //判断
//             if(r.second>(n/2))
//             return r.first;
//         }
//         return 0;
//     }
// };
