class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        if(n <= 0)  return vector<int>();
        // 找到后面数值中比当前数值小的那个数，可以用一个set来做
        // 也可以用两个栈来做
        set<int> table; vector<int> ret;
        for(int i=n-1;i>=0;i--){
            if(table.empty() || table.upper_bound(A[i])==table.end()) ret.push_back(-1);
            else    ret.push_back(*table.upper_bound(A[i]));
            table.insert(A[i]);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};