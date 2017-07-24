// 理解错题意了，认为要以矩阵中心为中心去找方阵
class SubMatrix {
public:
    int maxSubMatrix(vector<vector<int> > mat, int n) {
        // write code here
        int move = n/2;
        for(int i=0;i<=move;i++){
            int a = 0, b = 0, c = 0, d = 0;
            for(int j=i;j<=n-i-1;j++){
                //
                a += mat[i][j]; b += mat[j][i];
                c += mat[n-i-1][j]; d += mat[j][n-i-1];
            }
            if(a==b&&b==c&&c==d&&d==a&&a==n-2*i)    return n-2*i;
        }
        return 0;
    }
};

class SubMatrix {
public:
    int maxSubMatrix(vector<vector<int> > mat, int n) {
        // write code here
        // 用两个二维数组来维护dp，分别表示在mat中当前位置之前有多少位连续且相等的值
        vector<vector<int>> left(n, vector<int>(n, 1));
        vector<vector<int>> above(n, vector<int>(n, 1));
        int max_val = 1;
        // 初始化第一行和第一列
        for(int i=1;i<n;i++){
            if(mat[0][i] == mat[0][i-1])    left[0][i] = left[0][i-1] + 1;
        }
        for(int i=1;i<n;i++){
            if(mat[i][0] == mat[i-1][0])    above[i][0] = above[i-1][0] + 1;
        }
        // 每一次判断然后更新left和above数组的值，并且在mat当前值和上，左方的值相同时判断最大的方形
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                // 考虑几种情况的数值更新策略
                if(mat[i][j] != mat[i][j-1] || mat[i][j] != mat[i-1][j]){
                    if(mat[i][j] != mat[i][j-1] && mat[i][j] == mat[i-1][j]){
                        above[i][j] = above[i-1][j] + 1;
                    }
                    else if(mat[i][j] == mat[i][j-1] && mat[i][j] != mat[i-1][j]){
                        left[i][j] = left[i][j-1] + 1;
                    }
                }
                // 当当前值和左面，上面的值都相同时，进入判断环节
                else{
                    above[i][j] = above[i-1][j] + 1; left[i][j] = left[i][j-1] + 1;
                    int lens = min(above[i-1][j], left[i][j-1]);
                    for(int k=lens;k>0&&k>=max_val;k--){
                        // 当前点的左边和上边都满足了，要考察另外两边是否也满足
                        if(left[i-k][j] >= k + 1 && above[i][j-k] >= k + 1){
                            max_val = max(max_val, k+1);
                        }
                    }
                }
            }
        }
        return max_val;
    }
};