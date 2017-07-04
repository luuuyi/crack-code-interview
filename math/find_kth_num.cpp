class KthNumber {
public:
    int findKth(int k) {
        // write code here
        // 借鉴找丑数那个题，那个题找的是以2,3,5为素因数的值
        // 用动态规划的思路来做
        vector<int> dp(k+1, 0);
        dp[0] = 1;
        int idx3 = 0, idx5 = 0, idx7 = 0;
        // dp中的数全是丑数，3,5,7的标签一开始都对应同一个
        // 选中某一个为最小值以后，与该值相关的index都要加一
        // 要注意的是，某一些时刻会求出多个最小值，每一个最小值对应的index都要加一
        for(int i=1;i<=k;i++){
            dp[i] = min(dp[idx3]*3, min(dp[idx5]*5, dp[idx7]*7));
            if(dp[i] == dp[idx3]*3)   idx3++;
            if(dp[i] == dp[idx5]*5)  idx5++;
            if(dp[i] == dp[idx7]*7)    idx7++;
        }
        return dp[k];
    }
};