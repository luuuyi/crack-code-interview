class SortString {
public:
    vector<string> sortStrings(vector<string> str, int n) {
        // write code here
        // 比较简单的一个题，大致思路可以先合并变位词字符串，然后将其排序即可
        map<string, set<string>> table;
        string tmp;
        // 合并变位词使用一个map来做，每个map的value为一个set，方便快速筛选出字典序最小的那个串
        for(int i=0;i<n;i++){
            tmp = str[i];
            sort(tmp.begin(), tmp.end());
            table[tmp].insert(str[i]);
        }
        // 将每一个变位词字符串序列中最小的那位字符串取出来
        vector<string> ret;
        for(auto k=table.begin();k!=table.end();k++){
            ret.push_back(*(k->second.begin()));
        }
        // 排序所有的字符串
        sort(ret.begin(), ret.end());
        return ret;
    }
};