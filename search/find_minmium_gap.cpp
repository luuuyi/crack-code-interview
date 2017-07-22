class Distance {
private:
    // 寻找两个数组的最小差值函数，使用类似于夹逼的方法来做的
    // 其实还有更好的方法，两个数组的最小差值，是LeetCode上n个数组的最小差值的一种特殊情况；
    // 那道题使用一个容量为n的优先队列来维护每个数组抽出来的值，因为每一个数组都是递增的，每一次推出
    // 优先队列中最小的一个值，并且从他所属的数组中放入下一个值，用一个外部变量来描述队列中最大值到最小值的差距
    int findMinGap(vector<int>& x, vector<int>& y){
        int ret = INT_MAX;
        for(int i=0;i<(int)x.size();i++){
            int right = (int)y.size()-1, tmp = INT_MAX;
            while(right >= 0 && abs(x[i]-y[right]) < tmp){
                tmp = abs(x[i]-y[right]);
                --right;
            }
            ret = min(ret, tmp);
        }
        return ret;
    }
public:
    int getDistance(vector<string> article, int n, string x, string y) {
        // write code here
        // 解题方法，退化为寻找两个数组的最小差值，LeetCode上有很多多个数组之间的最大差值和最小差值的题目
        // 首先先将每个单词出现的下标存为一个数组
        if(n <= 0)  return 0;
        vector<int> loc_x, loc_y;
        for(int i=0;i<n;i++){
            if(x.compare(article[i]) == 0)  loc_x.push_back(i);
            if(y.compare(article[i]) == 0)  loc_y.push_back(i);
        }
        return findMinGap(loc_x, loc_y);
    }
};