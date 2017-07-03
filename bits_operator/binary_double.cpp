class BinDecimal {
public:
    string printBin(double num) {
        // write code here
        double tmp = num;
        // 首先明白十进制小数转二进制的规则
        // 用0.125来测试下就知道了
        string ret = "0.";
        for(int i=0;i>=0;i++){
            if(i < 32){
                tmp *= 2;
                // 小数就算求得1，也不能很单纯的就对double用==操作符
                if(abs(tmp-1.0) <= 0.00000001){
                    ret.push_back('1');
                    return ret;
                }
                else if(tmp < 1.0)  ret.push_back('0');
                else if(tmp > 1.0){
                    ret.push_back('1');
                    tmp -= 1.0;
                }
            }
            else    break;
        }
        return "Error";
    }
};