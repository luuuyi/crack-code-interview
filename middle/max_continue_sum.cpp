class MaxSum {
public:
    int getMaxSum(vector<int> A, int n) {
        // write code here
        if(n <= 0)  return 0;
        // 比较经典的一个题，判断连续序列和的最大值
        int max_val = INT_MIN, begin = 0, end = 0;
        int sum = 0;
        // 遍历一遍完成，先加上每一次的值，要用一个外部变量来维护这段过程中的最大值
        for(int i=0;i<n;i++){
            sum += A[i];
            // 如果加上当前值以后总和大于0，那可以继续以当前的状态继续加下去
            if(sum >= 0){
                max_val = max(max_val, sum);
            }
            // 如果是负数了，那就要及时脱手，不要再考虑之前的和了
            else{
                max_val = max(max_val, sum);
                sum = 0;
            }
        }
        return max_val;
    }
};