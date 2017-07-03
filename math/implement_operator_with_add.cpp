class AddSubstitution {
public:
    int calc(int a, int b, int type) {
        // write code here
        // 乘法和除法均可用加法来解决
        if(type == 1){
            int ret = a;
            for(int i=0;i<b-1;i++)  ret += a;
            return ret;
        }
        else if(type == 0){
            int i = 0, ret = 0;
            for(;i>=0;i++){
                ret += b;
                if(ret > a) return i;
                else if(ret == a)   return i+1;
            }
            return a;
        }
        // 整数的减法表示为将负数变成补码+1以后的加法
        else if(type == -1){
            int ret = a + (~b) + 1;
            return ret;
        }
        else    return 0;
    }
};