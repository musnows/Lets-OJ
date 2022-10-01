#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int num)
{
    vector<vector<int>> vv;
    vv.resize(num);//有多少行
    int k = 1;//和下标对应的加行数，第0行0+1个数据，第1行1+2个数据
    for(int i = 0;i<vv.size();i++)
    {
        vv[i].resize(i+k,0);//给一行开空间，初始化为0
        vv[i][0]=1;//首位
        vv[i][vv[i].size()-1]=1;//末尾
        k++;
    }
    
    for(int i =0;i<vv.size();i++)
    {
        for(int j = 0;j<vv[i].size();j++)
        {
            if(vv[i][j]==0)
            {
                //进行处理，避免越界
                if(j-1<0){
                    vv[i][j]=0+0+vv[i-1][j];
                }
                else if(j-2<0){
                    vv[i][j]=0+vv[i-1][j-1]+vv[i-1][j];
                }
                else{
                    vv[i][j]=vv[i-1][j-2]+vv[i-1][j-1]+vv[i-1][j];
                }
                
            }
        }
    }
    return vv;
}

void TestGenerate(int n)
{
    //直接使用本代码，内存超限
    vector<vector<int>> vv = generate(n);
    for(auto& e:vv){
        for(auto& d:e){
            cout << d << " ";
        }
        cout << endl;
    }
    
    int i=0;
    for(i =0;i<vv[n-1].size();i++)
    {
        if(vv[n-1][i]%2==0){
            cout<<i+1<<endl;//输出位置，而不是下标
            break;
        }
    }
    
    if(i==vv[n-1].size()){
        cout << -1 << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    //TestGenerate(n);
    //利用数阵生成代码，总结出规律
    //第1行和第二行没有偶数，输出-1
    //从第3行开始，偶数为2 3 2 4的循环
    //所以只用判断规律即可
    int ret[]={4,2,3,2};//注意这里的顺序，4%4=0，如果用2 3 2 4就会输出2，有问题
    if(n<=2){
        cout << -1 << endl;
    }
    else{
        int index = (n-2)%4;
        cout<<ret[index]<<endl;
    }
    
    return 0;
}
//https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43?orderByHotValue=0&commentTags=Java
//这道题可以关联leetcode118杨辉三角
