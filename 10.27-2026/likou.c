#define _CRT_SECURE_NO_WARNINGS 
#define MAXN 10005

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int qr[MAXN], qc[MAXN];
    int head = 0, tail = 0;
    int fresh = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                qr[tail] = i;
                qc[tail] = j;
                tail++;
            }
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int minutes = 0;
    int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

    while (head < tail && fresh > 0) {
        int levelSize = tail - head;   /* 当前这一分钟的橘子数 */
        for (int k = 0; k < levelSize; k++) {
            int r = qr[head], c = qc[head];
            head++;
            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d][0];
                int nc = c + dirs[d][1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    qr[tail] = nr;
                    qc[tail] = nc;
                    tail++;
                }
            }
        }
        minutes++;
    }

    return fresh == 0 ? minutes : -1;
}