class Frequency {
public:
    int getFrequency(vector<string> article, int n, string word) {
        // write code here
        // 第一遍还想复杂了，以为只要是出现就要统计出来
        // 结果没想到要用word去匹配article中的完成字符串
        if(n <= 0)  return 0;
        int ret = 0;
        for(int i=0;i<n;i++){
            if(word.compare(article[i]) == 0)   ret++;
        }
        return ret;
    }
};