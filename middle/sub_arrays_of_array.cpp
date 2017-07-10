class Subset {
private:
    static bool cmp(int a, int b){
        return a > b;
    }
public:
    vector<vector<int> > getSubsets(vector<int> A, int n) {
        // write code here
        // 首先先将数组排序，取值递减排序
        sort(A.begin(), A.end(), cmp);
        int tmp = 0, index = 0;
        vector<int> tmp_vec;
        vector<vector<int>> ret;
        // 根据最后要输出的规则，要按类字典序来排序输出
        // 可以看到需要输出的格式满足二进制递减的格式，所以模拟二进制递减来整理数值即可
        for(int i=pow(2, n)-1;i>0;i--){
            tmp = n; index = i;
            while(tmp--){
                if(index&0x01)  tmp_vec.push_back(A[tmp]);
                index >>= 1;
            }
            reverse(tmp_vec.begin(), tmp_vec.end());
            ret.push_back(tmp_vec);
            tmp_vec.clear();
        }
        return ret;
    }
};