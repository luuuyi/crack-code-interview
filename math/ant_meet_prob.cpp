class Ants {
public:
    double antsCollision(int n) {
        // write code here
        // 简单的概率题，蚂蚁顺时针和逆时针走的时候不会出现碰撞的情况
        return 1.0 - 2.0/pow(2, n);
    }
};