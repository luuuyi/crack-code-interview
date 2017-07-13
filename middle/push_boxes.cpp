class Box {
private:
    static bool cmp(vector<int> a, vector<int> b){
        // 不明白为啥单个条件排序就能通过，两个条件联合排序就不行
        return a[0] > b[0];// && a[1] > b[1];
    }
public:
    int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
        // write code here
        if(n <= 0)  return 0;
        vector<vector<int>> boxes;
        for(int i=0;i<n;i++){
            boxes.push_back(vector<int>({w[i], l[i], h[i]}));
        }
        sort(boxes.begin(), boxes.end(), cmp);
        vector<int> dp(n+1, 0);
        // 类似于求序列中严格单调最长子序列
        int ret = INT_MIN;
        for(int i=1;i<=n;i++){
            int cur = boxes[i-1][2], add = 0;
            for(int j=i-1;j>=1;j--){
                if(boxes[i-1][0]<boxes[j-1][0]&&boxes[i-1][1]<boxes[j-1][1])    add = max(add, dp[j]);
            }
            dp[i] = cur + add;
            ret = max(dp[i], ret);
        }
        return ret;
    }
};