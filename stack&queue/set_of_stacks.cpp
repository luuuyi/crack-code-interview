class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
        // write code here
        // 先用一个vector来存储所有的值
        vector<int> tmp;
        for(int i=0;i<(int)ope.size();i++){
            if(ope[i][0] == 1){
                tmp.push_back(ope[i][1]);
            }
            else{
                tmp.pop_back();
            }
        }
        // 根据size将tmp中的值放入一个二维数组中
        vector<vector<int>> ret;
        if(size == 0)   return ret;
        vector<int> row; int count = 0;
        for(int i=0;i<(int)tmp.size();i++){
            row.push_back(tmp[i]);
            if((++count) == size){
                ret.push_back(row);
                row.clear(); count = 0;
            }
        }
        if(count != 0)  ret.push_back(row);
        return ret;
    }
};