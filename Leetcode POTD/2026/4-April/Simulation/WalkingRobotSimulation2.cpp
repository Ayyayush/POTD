class Robot {
public:
    int w, h;
    int x, y;
    int dir; // 0 = East, 1 = North, 2 = West, 3 = South
    int perimeter;
    
    vector<pair<int,int>> directions = {
        {1, 0},   // East
        {0, 1},   // North
        {-1, 0},  // West
        {0, -1}   // South
    };
    
    vector<string> dirNames = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        perimeter = 2 * (w + h - 2);
    }
    
    void step(int num) {
        if (perimeter == 0) return;

        num %= perimeter;
        if (num == 0) num = perimeter;

        while (num--) {
            int nx = x + directions[dir].first;
            int ny = y + directions[dir].second;
            // check boundary
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4; // turn CCW
                nx = x + directions[dir].first;
                ny = y + directions[dir].second;
            }

            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirNames[dir];
    }
};