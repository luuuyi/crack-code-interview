class Board {
public:
    // 更简单的方法可以直接判断同一行同一列或者对角线上的值相加是否等于3
    bool checkWon(vector<vector<int> > board) {
        // write code here
        // 获胜条件是同一行或者同一列，或者同一主对角线，副对角线
        int h = board.size();
        if(h != 3)  return false;
        int w = board[0].size();
        if(w != 3)    return false;
        // 使用一个set来存储所有1的坐标位置
        set<int> x, y;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(board[i][j] == 1){
                    x.insert(j);
                    y.insert(i);
                }
            }
        }
        int i = x.size(), j = y.size();
        if((i==1&&j==3)||(i==3&&j==3)||(i==3&&j==3))    return true;
        else    return false;
    }
};