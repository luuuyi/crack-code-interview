class Stack {
private:
    // 根据每个演员的身高先排序
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
public:
    int getHeight(vector<vector<int> > actors, int n) {
        // write code here
        // 跟动态规划求最长递增子序列一个思路
        // 两个条件，固定其中一个即可
        sort(actors.begin(), actors.end(), cmp);
        vector<int> dp(n+1, 1);
        int ret = INT_MIN;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(actors[i-1][0]<actors[j-1][0]&&actors[i-1][1]<actors[j-1][1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};