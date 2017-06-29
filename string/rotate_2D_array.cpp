class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        // write code here
        if(n <= 0) return mat;
        //首先将矩阵先上下沿着中线翻转
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                swap(mat[i][j], mat[n-1-i][j]);
            }
        }
        //再将矩阵沿着主对角线翻转
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        return mat;
    }
};