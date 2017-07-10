class Permutation {
private:
    vector<string> ret;
    // 该题不能单纯的先给char排序以后用全排列的思路来做
    // 始终都不会自动达到字典序递减的顺序输出，所以需要用排序程序操作最终的结果
    static bool cmp(string a, string b){
        return a > b;
    }
    void getPermutation(string& A, int cur, int lens, string tmp){
        if(cur >= lens){
            ret.push_back(tmp);
        }
        // 全排列经典做法
        for(int i=cur;i<lens;i++){
            swap(A[i], A[cur]);
            tmp.push_back(A[cur]);
            getPermutation(A, cur+1, lens, tmp);
            tmp.pop_back();
            swap(A[i], A[cur]);
        }
    }
public:
    vector<string> getPermutation(string A) {
        // write code here
        //sort(A.begin(), A.end(), cmp);
        string tmp;
        getPermutation(A, 0, (int)A.size(), tmp);
        // 使用STL API来做全排列有一个局限性，就是元素值重复的情况下并不能输出所有结果
        /*do{
            ret.push_back(A);
        }while(next_permutation(A.begin(), A.end()));*/
        // 通过sort函数来给最终的结果排序，使得字典序递减，还有一种写法如下
        // sort(ret.begin(), ret.end(), greater<string>());
        // greater为一个模板类，重载()操作符使得其中的数据成员按递减的规则来排序
        sort(ret.begin(), ret.end(), cmp);
        return ret;
    }
};