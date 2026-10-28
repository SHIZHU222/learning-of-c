#define _CRT_SECURE_NO_WARNINGS 
#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int m = prerequisitesSize;

    int* indeg = (int*)calloc(numCourses, sizeof(int));
    int* head = (int*)malloc(numCourses * sizeof(int));
    int* to = (int*)malloc((m > 0 ? m : 1) * sizeof(int));
    int* nxt = (int*)malloc((m > 0 ? m : 1) * sizeof(int));
    for (int i = 0; i < numCourses; i++) head[i] = -1;

    /* 建图：b -> a */
    for (int i = 0; i < m; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        to[i] = a;
        nxt[i] = head[b];
        head[b] = i;
        indeg[a]++;
    }

    int* q = (int*)malloc(numCourses * sizeof(int));
    int qh = 0, qt = 0;
    for (int i = 0; i < numCourses; i++)
        if (indeg[i] == 0) q[qt++] = i;

    int cnt = 0;
    while (qh < qt) {
        int u = q[qh++];
        cnt++;
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (--indeg[v] == 0) q[qt++] = v;
        }
    }

    free(indeg);
    free(head);
    free(to);
    free(nxt);
    free(q);

    return cnt == numCourses;
}