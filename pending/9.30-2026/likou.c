#define _CRT_SECURE_NO_WARNINGS 
//P146
#include <stdlib.h>

typedef struct Node {
    int key, val;
    struct Node* prev, * next;
} Node;

typedef struct {
    Node* head, * tail;   // 哑头、哑尾
    int cap;
    int size;
    Node** hash;         // 简单哈希表
    int hashSize;
} LRUCache;

static int hashIndex(LRUCache* c, int key) {
    return (key & 0x7fffffff) % c->hashSize;
}

static void unlinkNode(Node* n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
}

static void insertFront(LRUCache* c, Node* n) {
    n->next = c->head->next;
    n->prev = c->head;
    c->head->next->prev = n;
    c->head->next = n;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* c = (LRUCache*)malloc(sizeof(LRUCache));
    c->head = (Node*)calloc(1, sizeof(Node));
    c->tail = (Node*)calloc(1, sizeof(Node));
    c->head->next = c->tail;
    c->tail->prev = c->head;
    c->cap = capacity;
    c->size = 0;
    c->hashSize = capacity * 2 + 1;
    c->hash = (Node**)calloc(c->hashSize, sizeof(Node*));
    return c;
}

int lRUCacheGet(LRUCache* c, int key) {
    Node* n = c->hash[hashIndex(c, key)];
    while (n && n->key != key) n = n->next;   // 处理哈希冲突（链地址）
    if (!n) return -1;
    unlinkNode(n);
    insertFront(c, n);
    return n->val;
}

void lRUCachePut(LRUCache* c, int key, int value) {
    Node* n = c->hash[hashIndex(c, key)];
    while (n && n->key != key) n = n->next;

    if (n) {
        n->val = value;
        unlinkNode(n);
        insertFront(c, n);
        return;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->val = value;
    node->prev = node->next = NULL;
    insertFront(c, node);

    // 头插到哈希桶
    int idx = hashIndex(c, key);
    node->next = c->hash[idx];   // 复用 next 字段做哈希链
    if (c->hash[idx]) c->hash[idx]->prev = node;
    c->hash[idx] = node;

    if (c->size < c->cap) {
        c->size++;
    }
    else {
        // 删除尾部节点
        Node* last = c->tail->prev;
        unlinkNode(last);
        // 从哈希桶移除
        int li = hashIndex(c, last->key);
        Node** pp = &c->hash[li];
        while (*pp && (*pp)->key != last->key) pp = &(*pp)->next;
        *pp = (*pp)->next;
        free(last);
    }
}

void lRUCacheFree(LRUCache* c) {
    free(c->hash);
    free(c->head);
    free(c->tail);
    free(c);
}