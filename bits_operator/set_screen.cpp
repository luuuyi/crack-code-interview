class Render {
public:
    vector<int> renderPixel(vector<int> screen, int x, int y) {
        // write code here
        // 技巧性做法
        // 找到定位位置的数值，然后更改相应位置的二进制值即可
        for(int i=x;i<=y;i++){
            int index = i / 8;
            int bits = i % 8;
            screen[index] |= (1<<bits); 
        }
        return screen;
    }
};