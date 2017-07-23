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