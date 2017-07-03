class CrossLine {
public:
    bool checkCrossLine(double s1, double s2, double y1, double y2) {
        // write code here
        // ret为两条线是否不相交，不相交返回true，相交返回false
        bool ret = (abs(s1-s2) <= 0.0000001) && (abs(y1-y2) > 0.0000001);
        // 根据题意需要反一下
        return !ret;
    }
};