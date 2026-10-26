#define _CRT_SECURE_NO_WARNINGS 
//P1090
#include <stdio.h>

int heap[10005];
int size = 0;

void push(int x) {
    int i = ++size;
    while (i > 1 && heap[i / 2] > x) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

int pop() {
    int top = heap[1];
    int last = heap[size--];
    int i = 1, child = 2;
    while (child <= size) {
        if (child + 1 <= size && heap[child + 1] < heap[child]) child++;
        if (last <= heap[child]) break;
        heap[i] = heap[child];
        i = child;
        child = i * 2;
    }
    heap[i] = last;
    return top;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        push(a);
    }

    long long ans = 0;
    while (size > 1) {
        int a = pop();
        int b = pop();
        int s = a + b;
        ans += s;
        push(s);
    }

    printf("%lld\n", ans);
    return 0;
}