class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        // 用栈辅助一次性做出来
        if(n <= 0)  return vector<int>();
        stack<int> stk;
        vector<int> ret;
        for(int i=n-1;i>=0;){
            // 考虑的情况和直方图合成最大矩形一样
            // 主要下面要用小于等于符号
            if(stk.empty() || stk.top() <= A[i]){
                if(stk.empty()){    stk.push(A[i]); ret.push_back(-1); --i;}
                else    stk.pop();
            }
            else{
                ret.push_back(stk.top());
                stk.push(A[i]); --i;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};