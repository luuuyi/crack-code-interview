class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        // write code here
        if(n == 0)  return mat;
        vector<vector<bool>> marks(2, vector<bool>(n, false));
        // 先判断元素是否为0，如果是将对应的行列标注好
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    marks[0][i] = true;
                    marks[1][j] = true;
                }
            }
        }
        // 根据对应的行列，将元素初始化为0
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(marks[0][i] && marks[1][i])    mat[i][j] = mat[j][i] = 0;
                else if(marks[0][i] && !marks[1][i])   mat[i][j] = 0;
                else if(!marks[0][i] && marks[1][i])   mat[j][i] = 0;
                else    continue;
            }
        }
        return mat;
    }
};