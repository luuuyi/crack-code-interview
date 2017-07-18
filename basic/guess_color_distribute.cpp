class Result {
public:
    vector<int> calcResult(string A, string guess) {
        // write code here
        // 首先判断输入数据是否合法
        if(A.size()!=4 || guess.size()!=4)  return vector<int>({-1, -1});
        map<char, int> table;
        // 第一次先保存标准字符的信息
        for(int i=0;i<4;i++)    table[A[i]]++;
        int right = 0, total = 0;
        for(int i=0;i<4;i++){
            // 比对相同位置是否相等，更新猜中
            // 比对所有的猜中和伪猜中的情况，统计所有的信息
            if(guess[i] == A[i])    right++;
            if(table[guess[i]] > 0){
                total++; table[guess[i]]--;
            }
        }
        return vector<int>({right, total-right});
    }
};