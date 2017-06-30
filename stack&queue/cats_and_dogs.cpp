class CatDogAsylum {
public:
    vector<int> asylum(vector<vector<int> > ope) {
        // write code here
        deque<int> room;
        stack<int> helper;
        vector<int> ret;
        for(int i=0;i<(int)ope.size();i++){
            // 根据收容所规则，收容小动物，用deque来维护收容所
            if(ope[i][0] == 1)  room.push_back(ope[i][1]);
            // 根据领养规则，进入规则
            else if(ope[i][0] == 2){
                // 第一种领养规则，领养最早进入收容所的动物
                if(ope[i][1] == 0){
                    ret.push_back(room.front());
                    room.pop_front();
                }
                // 第二种规则，领养最早进入的狗子，使用stack辅助从头开始找
                else if(ope[i][1] == 1){
                    while(!room.empty()){
                        if(room.front() > 0){
                            ret.push_back(room.front());
                            room.pop_front();
                            break;
                        }
                        else{
                            helper.push(room.front());
                            room.pop_front();
                        }
                    }
                }
                // 第二种规则，领养最早进入的猫，使用stack辅助从头开始找
                else if(ope[i][1] == -1){
                    while(!room.empty()){
                        if(room.front() < 0){
                            ret.push_back(room.front());
                            room.pop_front();
                            break;
                        }
                        else{
                            helper.push(room.front());
                            room.pop_front();
                        }
                    }
                }
                while(!helper.empty()){
                    room.push_front(helper.top()); helper.pop();
                }
            }
        }
        return ret;
    }
};