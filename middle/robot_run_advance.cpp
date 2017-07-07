class Robot {
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        // write code here
        const int MOD = 1000000007;
        // x为纵坐标上的值，根据习惯交换了一下
        swap(x, y);
        // 首先初始化，要注意遇到障碍就退出
        // 遇到要取模的题，考虑把变量改为long long
        vector<vector<long long>> dp(y, vector<long long>(x, 0));
        for(int i=x-1;i>=0;i--){
            if(map[y-1][i] == 1)    dp[y-1][i] = 1;
            else    break;
        }
        for(int i=y-1;i>=0;i--){
            if(map[i][x-1] == 1)    dp[i][x-1] = 1;
            else    break;
        }
        // 根据机器人走方格的的规则来
        for(int i=y-2;i>=0;i--){
            for(int j=x-2;j>=0;j--){
                if(map[i][j] == 1)  dp[i][j] = (dp[i+1][j] + dp[i][j+1])%MOD;
            }
        }
        return int((dp[0][0]+MOD)%MOD);
    }
};