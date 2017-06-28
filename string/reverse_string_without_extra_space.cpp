//不使用额外的变量来做
class Reverse {
public:
    string reverseString(string iniString) {
        // write code here
        for(int i=0;i<(int)iniString.size()/2;i++)  swap(iniString[i], iniString[(int)iniString.size()-i-1]);
        return iniString;
    }
};