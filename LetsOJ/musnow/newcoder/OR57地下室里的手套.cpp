class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int sum=0,suml=0,sumr=0;
        int minl=INT16_MAX,minr=INT16_MAX;
        for(int i=0;i<n;i++)
        {
            if(left[i]*right[i]==0)
            {
                sum+=left[i]+right[i];
            }
            else
            {
                suml+=left[i];
                sumr+=right[i];
                if(left[i]<minl){
                    minl=left[i];
                }
                if(right[i]<minr){
                    minr=right[i];
                }
            }
        }
        //int min = minl>minr?minr:minl;
        if(suml<sumr){
            //cout << sum+(suml-minl+1)+1 << endl;
            return sum+(suml-minl+1)+1;
        }
        else{
            //cout << sum+(sumr-minr+1)+1 << endl;
            return sum+(sumr-minr+1)+1;
        }
        return 0;
    }
};
//https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=182&tqId=34783&rp=1&ru=/ta/exam-all&qru=/ta/exam-all/question-ranking&tab=answerKey
