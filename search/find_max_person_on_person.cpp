class Stack {
public:
    int getHeight(vector<int> men, int n) {
        // write code here
        // 寻找最长递增子序列的题目
        vector<int> dp(n+1, 1);
        int ret = INT_MIN;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(men[i-1] > men[j-1]) dp[i] = max(dp[i], dp[j]+1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};