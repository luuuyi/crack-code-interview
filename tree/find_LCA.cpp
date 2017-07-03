// 经典题，找最近公共祖先
class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        if(a <= 1 || b <= 1) return 0;
        // 根据完全二叉树的节点规律，a和b的二进制表达肯定有一部分是相等的
        // 相等的值即为公共祖先的值
        for(int i=a;i>0;i>>=1){
            for(int j=b;j>0;j>>=1)
                if(i == j)  return i;
        }
        return 0;
    }
};