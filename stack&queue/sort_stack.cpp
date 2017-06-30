class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
        // 使用两个stack来做
        stack<int> ori, sorted;
        for(int i=(int)numbers.size()-1;i>=0;i--)   ori.push(numbers[i]);
        // 原始stack顶端数字大于或者等于排序stack顶端数字，则将其压入排序stack
        // 否则，用临时变量存储原始stack顶端数字，将排序stack顶端大于其的数一一压入原始stack
        // 直到遇到小于等于其的排序stack顶端数字，将临时变量压入排序stack
        while(!ori.empty()){
            if(sorted.empty() || sorted.top() <= ori.top()){
                sorted.push(ori.top()); ori.pop();
            }
            else{
                int tmp = ori.top(); ori.pop();
                while(!sorted.empty() && sorted.top() > tmp){
                    ori.push(sorted.top()); sorted.pop();
                }
                sorted.push(tmp);
            }
        }
        vector<int> ret;
        while(!sorted.empty()){
            ret.push_back(sorted.top()); sorted.pop();
        }
        return ret;
    }
};