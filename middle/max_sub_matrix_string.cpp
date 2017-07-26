// 题目据说表述不清楚,看了讨论区的答案,发现题意完全不符
/*class AlphaMatrix {
public:
    int findAlphaMatrix(vector<string> dic, int n) {
        // write code here
        vector<vector<int>> above(n, vector<int>(12, 0));
        vector<vector<int>> left(n, vector<int>(12, 0));
        for(int i=0;i<12;i++)   above[0][i] = i<(int)dic[0].size()?1:0;
        for(int i=0;i<n;i++)   left[i][0] = 1;
        for(int i=1;i<n;i++){
            for(int j=1;j<12;j++){
                if(j < (int)dic[i].size()){

                }
            }
        }
    }
};*/

// 其实题意是,给定一个字符串数组,用其中重复的字符串堆叠成一个矩阵,求其中面积最大的结果
class AlphaMatrix {
public:
    int findAlphaMatrix(vector<string> dic, int n) {
        // write code here
        map<string, int> table;
        for(int i=0;i<n;i++){
            table[dic[i]]++;
        }
        int ret = INT_MIN;
        for(int i=0;i<n;i++)    ret = max(ret, int(table[dic[i]]*dic[i].size()));
        return ret;
    }
};