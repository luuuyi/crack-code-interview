class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        stack<char> stk;
        // 经典的用栈辅助的括号匹配问题
        for(int i=0;i<n;i++){
            // 遇到左括号，直接入栈
            if(A[i] == '(') stk.push(A[i]);
            // 遇到右括号，要假设出几种情况分别处理，遇到同样的右括号即错误
            // 遇到左括号，即退出循环去匹配；遇到其他单词直接出栈
            else if(A[i] == ')'){
                while(!stk.empty()){
                    if(stk.top() == '(')    break;
                    else if(stk.top() != ')')   stk.pop();
                    else    return false;
                }
                if(stk.empty()) return false;
                stk.pop();
            }
            // 其他单词的情况，只有遇到栈顶是右括号的情况才会出错，其他情况都是可以入栈的
            else{
                if(stk.top() != ')')    stk.push(A[i]);
                else    return false;
            }
        }
        if(stk.empty()) return true;
        else    return false;
    }
};