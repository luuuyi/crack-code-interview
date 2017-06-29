class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        // write code here
        // 首先判断边界条件
        if(s1.size() <= 0 || s1.size() != s2.size())  return false;
        char first = s1[0];
        int pos = 0, begin = 0;
        // 在s2中查找s1的首字母，然后拼接子串来对比
        while((pos = s2.find(first, begin)) != string::npos){
            string tmp = s2.substr(pos) + s2.substr(0, pos);
            if(s1.compare(tmp) == 0)    return true;
            begin = pos + 1;
        }
        return false;
    }
};