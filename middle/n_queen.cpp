class Queens {
private:
    int ret;
    // 使用一个数组来保存当前index行的皇后列位置
    // 判断的时候只需要判断之前放下的皇后是否和当前点在同一列或者同一对角线即可
    // 不需要判断是否在同一行，因为一行只取一个值
    void dfs(vector<int>& cols, int n, int cur){
        if(cur == n){
            ret++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(cols, cur, i)){
                cols[cur] = i;
                dfs(cols, n, cur+1);
                //cols[n] = i;
            }
        }
    }
    // 判断当前点放下皇后的可能性
    bool isValid(vector<int>& cols, int cur, int i){
        for(int row=0;row<cur;row++){
            // 判断是否在同一对角线可以判断两点的横纵坐标相差绝对值是否相同
            if(cols[row] == i || abs(cols[row]-i) == abs(row - cur))  return false;
        }
        return true;
    }
public:
    int nQueens(int n) {
        // write code here
        // 跟数独问题一样，使用递归+回溯法来做
        if(n <= 0)  return 0;
        ret = 0;
        vector<int> cols(n, 0);
        dfs(cols, n, 0);
        return ret;
    }
};