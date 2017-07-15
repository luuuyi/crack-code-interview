class Finder {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        // 经典题目，在二维矩阵中找数字，然后返回坐标
        // 二维数组行列方向递增
        if(n == 0)  return vector<int>({-1, -1});
        int cur_x = m-1, cur_y = 0;
        while(cur_x>=0&&cur_x<m&&cur_y>=0&&cur_y<n){
            if(mat[cur_y][cur_x] > x){
                cur_x--;
            }
            else if(mat[cur_y][cur_x] < x){
                cur_y++;
            }
            else{
                return vector<int>({cur_y, cur_x});
            }
        }
        return vector<int>({-1, -1});
    }
};