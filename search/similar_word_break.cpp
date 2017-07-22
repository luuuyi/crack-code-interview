class LongestString {
private:
    static bool cmp(string s1, string s2){
        return s1.size() < s2.size();
    }
    // leetcode题目word-break的思路，判断一个单词是否能被一个字符串数组中的成员组合而成
    bool wordBreak(string& s, set<string>& table){
        int lens = s.size(); if(lens == 1)  return false;
        vector<int> dp(lens+1, 0); dp[0] = 1;
        for(int i=1;i<=lens;i++){
            if(dp[i-1] == 1){
                for(int j=i;j<=lens;j++){
                    if(table.find(s.substr(i-1, j-i+1)) != table.end())   dp[j] = 1;
                }
            }
        }
        return dp[lens]==1?true:false;
    }
public:
    int getLongest(vector<string> str, int n) {
        // write code here
        // 首先按长度排序，然后之后从最后开始判断
        sort(str.begin(), str.end(), cmp);
        set<string> table;
        for(int i=0;i<n;i++)    table.insert(str[i]);
        for(int i=n-1;i>=0;i--){
            // 每一次将该词的从hash表中删除
            table.erase(str[i]);
            if(wordBreak(str[i], table))    return str[i].size();
            table.insert(str[i]);
        }
        return 0;
    }
};