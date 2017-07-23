class Change {
private:
    int _ret;
    // 借助全局变量深度优先遍历
    void findMinGap(map<string, vector<string>>& table, string& s, string &t, int depth){
        if(t.compare(s) == 0)   _ret = min(_ret, depth);
        if(table[t].size() == 0)    return;
        for(int i=0;i<(int)table[t].size();i++){
            findMinGap(table, s, table[t][i], depth+1);
        }
    }
public:
    // LeetCode的word-ladder问题，其实就是个广度优先遍历+深度优先遍历
    int countChanges(vector<string> dic, int n, string s, string t) {
        // write code here
        if(n <= 0)  return 0; //if(s.compare(t) == 0) return 0;
        set<string> strs; _ret = INT_MAX;
        for(int i=0;i<n;i++)    strs.insert(dic[i]);
        queue<string> que; que.push(s); strs.erase(s);
        map<string, vector<string>> table;
        while(!que.empty()){
            queue<string> tmp_que;
            // 将每一个位置的26个可能的字符枚举出来
            while(!que.empty()){
                string tmp = que.front(); que.pop();
                for(int i=0;i<(int)tmp.size();i++){
                    // 都暂时假设是小写字母组成
                    for(char c='a';c<='z';c++){
                        if(tmp[i] != c){
                            string change = tmp; change[i] = c;
                            if(strs.find(change) != strs.end()){
                                table[change].push_back(tmp);
                                tmp_que.push(change);
                            }
                        }
                    }
                }
            }
            que = tmp_que;
            while(!tmp_que.empty()){
                strs.erase(tmp_que.front());
                tmp_que.pop();
            }
        }
        findMinGap(table, s, t, 1);
        return _ret==INT_MAX?-1:_ret-1;
    }
};