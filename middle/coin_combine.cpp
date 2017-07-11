class Coins {
public:
    int countWays(int n) {
        // write code here
        const int MOD = 1000000007;
        vector<int> coins({0, 25, 10, 5, 1});
        vector<long long> dp(n+1, 0);
        // 经典的硬币组成问题；类似的题目都可以用动态规划来做
        // 记得初始化第一位，表示要组成面值为0的时候有且仅有一种方法，那就是面值全为空
        // 组成规则为dp[i][n]表示使用i中面值的硬币，组成n的方法数，可以用压缩的方法节省空间
        dp[0] = 1;
        for(int i=1;i<=4;i++){
            for(int j=coins[i];j<=n;j++){
                // 每一次方法数为上一次组成j的方法数加上算上当前面值硬币以后组成j-coins[i]的方法数
                // 记得取模
                dp[j] = (dp[j] + dp[j-coins[i]])%MOD;
            }
        }
        return int((dp[n]+MOD)%MOD);
    }
};