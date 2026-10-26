#define _CRT_SECURE_NO_WARNINGS 
void dfs(char** grid, int r, int c, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') return;
    grid[r][c] = '0';                  // 标记已访问（直接改为水）
    dfs(grid, r + 1, c, rows, cols);
    dfs(grid, r - 1, c, rows, cols);
    dfs(grid, r, c + 1, rows, cols);
    dfs(grid, r, c - 1, rows, cols);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rows = gridSize, cols = gridColSize[0];
    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, rows, cols);
            }
    return count;
}