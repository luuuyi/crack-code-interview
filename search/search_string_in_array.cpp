// 最朴素的二分查找法的应用，只不过换成了字符串
class Finder {
private:
    int binarySearch(vector<string>& str, int s, int e, const string& t){
        while(s <= e){
            int mid = s+(e-s)/2;
            if(t.compare(str[mid]) == 0)    return mid;
            // 根据其中可能会插入空格字符串的约束条件，增加几个条件即可
            else if(str[mid].compare(" ")!=0 && t.compare(str[mid])>0)  s = mid + 1;
            else if(str[mid].compare(" ")!=0 && t.compare(str[mid])<0)  e = mid - 1;
            // 灵活使用字符串的匹配函数，明白返回值的意义
            else if(str[mid].compare(" ")==0){
                int right = mid, left = mid;
                while(str[right].compare(" ")==0) right++;
                while(str[left].compare(" ")==0) left--;
                if(t.compare(str[left]) <= 0)   e = left;
                if(t.compare(str[right]) >= 0)   s = right;
            }
        }
        return -1;
    }
public:
    int findString(vector<string> str, int n, string x) {
        // write code here
        return binarySearch(str, 0, n-1, x);
    }
};