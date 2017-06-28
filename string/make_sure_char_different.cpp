//由于不能使用额外的空间，可以考虑用快排来做，遇到等于的就返回
class Different {
private:
    bool qSortSolve(string& iniString, int begin, int end){
        //典型的快速排序写法
        if(begin < end){
            int i = begin, j = end;
            int index = begin;
            while(i < j){
                for(;j>=begin&&j>i;j--){
                    if(iniString[j] > iniString[index]) continue;
                    else if(iniString[j] < iniString[index])    break;
                    else    return false;
                }
                iniString[i++] = iniString[j];
                for(;i<=end&&i<j;i++){
                    if(iniString[i] < iniString[index]) continue;
                    else if(iniString[i] > iniString[index])    break;
                    else    return false;
                }
                iniString[j--] = iniString[i];
            }
            iniString[i] = iniString[index];
            return qSortSolve(iniString, begin, i-1) && qSortSolve(iniString, i+1, end);
        }
        else    return true;
    }
public:
    bool checkDifferent(string iniString) {
        // write code here
        int lens = iniString.size();
        if(lens <= 1)   return true;
        return qSortSolve(iniString, 0, lens-1);
    }
};