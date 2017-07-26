/*
struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};*/

class Path {
private:
    // 分别从a和b计算广度优先遍历,如果发现了就返回true
    // 广度优先遍历用队列来辅助完成
    bool check(UndirectedGraphNode* a, UndirectedGraphNode* b){
        if(a == b)  return true;
        queue<UndirectedGraphNode*> que; que.push(a);
        set<UndirectedGraphNode*> table; table.insert(a);
        while(!que.empty()){
            UndirectedGraphNode *tmp = que.front(); que.pop();
            for(int i=0;i<(int)tmp->neighbors.size();i++){
                if(tmp->neighbors[i] == b)  return true;
                if(table.find(tmp->neighbors[i])==table.end()){
                    table.insert(tmp->neighbors[i]);
                    que.push(tmp->neighbors[i]);
                }
            }
        }
        return false;
    }
public:
    // 广度优先遍历的题目
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        // write code here
        return check(a, b)||check(b, a);
    }
};