#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

typedef struct {
    int* data;   /* 主栈 */
    int* mins;   /* 辅助栈：mins[i] = data[0..i] 的最小值 */
    int top;     /* 元素个数（也等于栈顶下标 + 1） */
    int cap;     /* 当前容量 */
} MinStack;

MinStack* minStackCreate(void) {
    MinStack* s = (MinStack*)malloc(sizeof(MinStack));
    s->cap = 16;
    s->top = 0;
    s->data = (int*)malloc(s->cap * sizeof(int));
    s->mins = (int*)malloc(s->cap * sizeof(int));
    return s;
}

/* 容量不足时扩容 */
static void ensureCapacity(MinStack* s) {
    if (s->top < s->cap) return;
    s->cap *= 2;
    s->data = (int*)realloc(s->data, s->cap * sizeof(int));
    s->mins = (int*)realloc(s->mins, s->cap * sizeof(int));
}

void minStackPush(MinStack* obj, int val) {
    ensureCapacity(obj);

    obj->data[obj->top] = val;
    if (obj->top == 0)
        obj->mins[obj->top] = val;
    else
        obj->mins[obj->top] = (val < obj->mins[obj->top - 1])
        ? val : obj->mins[obj->top - 1];
    obj->top++;
}

void minStackPop(MinStack* obj) {
    if (obj->top > 0) obj->top--;   /* 两个栈同步弹出 */
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->mins[obj->top - 1];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->mins);
    free(obj);
}