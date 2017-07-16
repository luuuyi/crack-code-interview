class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
        // write code here
        // 基于不使用额外空间，还有不使用加减乘除操作符的方法
        // 当前是使用加减乘除方法
        /*AB[0] = AB[0] + AB[1];
        AB[1] = AB[0] - AB[1];
        AB[0] = AB[0] - AB[1];*/
        // 当前是不使用加减乘除方法
        AB[0] = AB[0] ^ AB[1];
        AB[1] = AB[0] ^ AB[1];
        AB[0] = AB[0] ^ AB[1];
        return AB;
    }
};