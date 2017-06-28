//剑指offer上的原题，可以考虑从后面往前面插值
class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
        if(length == 0) return iniString;
        int count = 0;
        for(int i=0;i<length;i++)   if(iniString[i] == ' ')  count++;
        int i = length-1;
        //这里原来的字符串是定长的，所以需要在后面增加空间
        length += count*2;
        iniString.append(string(count*2, 0));
        int j = length-1;
        while(i>=0 && j>=0){
            if(iniString[i] != ' ') iniString[j--] = iniString[i--];
            else{
                iniString[j--] = '0';
                iniString[j--] = '2';
                iniString[j--] = '%';
                i--;
            }
        }
        return iniString;
    }
};