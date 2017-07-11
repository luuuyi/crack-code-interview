class Flood {
public:
    int floodFill(vector<vector<int> > map, int n, int m) {
        // write code here
        if(n == 0 || m == 0)    return 0;
        // 这是一道广度优先算法的考题，一般可以用递归+回溯法来做
        // 这里使用队列来辅助完成递归算法，并且利用队列的特性，保证最终结果一定是最小的
        // 可以将二维数组映射为一维的，保存坐标；下面为四个方向的移动方式
        vector<vector<int>> move({{1,0},{0,1},{-1,0},{0,-1}});
        // 使用一个队列来维护哪些点最先进入了队列，物理意义为哪些点最先被洪水淹没
        queue<int> idx; idx.push(0);
        while(!idx.empty()){
            int tmp_idx = idx.front(); idx.pop();
            // 通过压缩的位置信息还原当前点的坐标
            int x = tmp_idx % m, y = tmp_idx / m;
            if(x == m-1 && y == n-1)    return map[y][x];
            // 计算出之后四个方向可能被洪水淹没点的坐标，记得满足边界条件和洪水淹没的条件
            // 然后将数值加一即为下一个点最快被洪水淹没的时间，之后入队
            for(int k=0;k<4;k++){
                int next_x = x + move[k][1];
                int next_y = y + move[k][0];
                if((next_x >=0 && next_x < m)&&(next_y >=0 && next_y < n)&&map[next_y][next_x] == 0){
                    idx.push(next_y*m+next_x);
                    map[next_y][next_x] = map[y][x] + 1;
                }
            }
        }
        return -1;
    }
};