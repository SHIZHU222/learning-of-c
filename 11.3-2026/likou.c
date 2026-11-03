#define _CRT_SECURE_NO_WARNINGS 
#include <stdbool.h>
#include <string.h>

static int M, N;
static const int dx[4] = { 1, -1, 0, 0 };
static const int dy[4] = { 0, 0, 1, -1 };

/* 从 (r,c) 开始匹配 word[k..] */
static bool dfs(char** board, int r, int c, const char* word, int k) {
    if (word[k] == '\0') return true;              // 全部匹配完
    if (r < 0 || r >= M || c < 0 || c >= N) return false;
    if (board[r][c] != word[k]) return false;

    char saved = board[r][c];
    board[r][c] = '#';                             // 标记已用（回溯法核心）

    bool ok = false;
    for (int d = 0; d < 4 && !ok; d++)             // 找到一条路就停
        ok = dfs(board, r + dx[d], c + dy[d], word, k + 1);

    board[r][c] = saved;                           // 恢复现场
    return ok;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    if (word == NULL || word[0] == '\0') return true;
    if (boardSize == 0 || boardColSize == NULL || boardColSize[0] == 0) return false;

    M = boardSize;
    N = boardColSize[0];

    int len = (int)strlen(word);
    if (len > M * N) return false;                 // 格子数不够，剪枝

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (dfs(board, i, j, word, 0)) return true;

    return false;
}