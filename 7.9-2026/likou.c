bool isRobotBounded(char* instructions) {
    int x = 0, y = 0, dir = 0;
    // dir: 0=北, 1=东, 2=南, 3=西
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };

    for (int i = 0; instructions[i]; i++) {
        if (instructions[i] == 'G') {
            x += dx[dir];
            y += dy[dir];
        }
        else if (instructions[i] == 'L') {
            dir = (dir + 3) % 4;  // 左转 = 逆时针
        }
        else if (instructions[i] == 'R') {
            dir = (dir + 1) % 4;  // 右转 = 顺时针
        }
    }

    return (x == 0 && y == 0) || dir != 0;
}