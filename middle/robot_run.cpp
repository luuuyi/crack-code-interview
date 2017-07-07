class Robot {
public:
    int countWays(int x, int y) {
        // write code here
        // 最简单的走方格动态规划题目
        vector<vector<int>> dp(y, vector<int>(x, 0));
        for(int i=x-1;i>=0;i--) dp[y-1][i] = 1;
        for(int i=y-1;i>=0;i--) dp[i][x-1] = 1;
        // 每一个方格的值都等于右边和下边方格值相加
        for(int i=y-2;i>=0;i--){
            for(int j=x-2;j>=0;j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};