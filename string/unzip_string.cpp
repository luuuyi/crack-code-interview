class Zipper {
public:
    string zipString(string iniString) {
        // write code here
        // 首先判断边界条件
        if(iniString.size() <= 1)   return iniString;
        string ret;
        int count = 1;
        // 从第一位开始遍历，开始找到每个字符的数量
        for(int i=0;i<(int)iniString.size()-1;i++){
            if(iniString[i] == iniString[i+1])  ++count;
            else{    ret.push_back(iniString[i]); ret += to_string(count); count = 1;}
        }
        // 压缩字符，并且不要忘了还有最后的一部分需要压缩
        ret.push_back(iniString.back()); ret += to_string(count);
        if(ret.size() >= iniString.size())  return iniString;
        else    return ret;
    }
};