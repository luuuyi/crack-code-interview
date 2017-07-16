class Rank {
public:
    vector<int> getRankOfNumber(vector<int> A, int n) {
        // write code here
        // 比较经典的一个题，要返回小于当前值的数值个数数组
        // 解题思路是利用二叉搜索树，思路一致，只不过用了现成的C++ STL库
        if(n <= 0)  return vector<int>({0});
        vector<int> ret(n, 0); map<int, int> table;
        map<int, int>::iterator iter;
        for(int i=0;i<n;i++){
            // lower_bound返回的是大于等于的位置
            // upper_bound返回的是大于的位置
            table[A[i]]++;  iter = table.lower_bound(A[i]);
            for(auto k=table.begin();k!=iter;k++)
                ret[i] += k->second;
        }
        return ret;
    }
};