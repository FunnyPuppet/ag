#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 默认桶大小
#define DEFAULT_HASH_SIZE (1 << 4)
// 最大桶容量
#define MAX_CAPACITY (1 << 30)
// 扩容因子
#define LOAD_FACTOR 0.75

// 哈希函数取余参数
static int HASH_MODE  = DEFAULT_HASH_SIZE;

typedef struct Pair Pair;

typedef struct HashMap HashMap;

// 节点
struct Pair {
    char *key;
    int val;
    Pair *next;
};

struct HashMap {
    // 桶
    Pair **buckets;
    // 桶容量
    int size;
    // 节点数量
    int count;
};

// 扩容函数
void resize(HashMap* map);

// 哈希函数
unsigned int hash(const char *key) {
    unsigned int hash_val = 0;

    while (*key != '\0') {
        hash_val = (hash_val << 5) + *key;
        key++;
    }

    return hash_val % HASH_MODE;
}

// 创建HashMap
HashMap* createHashMap() {
    HashMap *map;

    if ((map = malloc(sizeof(HashMap))) == NULL) {
        perror("Allocate memory error!");
        exit(EXIT_FAILURE);
    }

    map->buckets = malloc(sizeof(Pair*) * DEFAULT_HASH_SIZE);
    map->size = DEFAULT_HASH_SIZE;
    map->count = 0;

    for (int i = 0; i < DEFAULT_HASH_SIZE; i++) {
        map->buckets[i] = NULL;
    }

    return map;
}

// 添加
void insert(HashMap* map, const char* key, const int val) {
    // 通过hash函数获取key所在桶下标
    const unsigned int index = hash(key);

    Pair *cur = map->buckets[index];

    while (cur != NULL) {
        // 查询key值是否已存在, 存在则更新key值为新值
        if (strcmp(cur->key, key) == 0) {
            cur->val = val;
            return;
        }
        cur = cur->next;
    }

    Pair *pair;

    if ((pair = malloc(sizeof(Pair))) == NULL) {
        perror("Allocate memory error!");
        exit(EXIT_FAILURE);
    }

    pair->key = strdup(key);

    if (pair->key == NULL) {
        perror("Allocate memory error!");
        free(pair);
        exit(EXIT_FAILURE);
    }

    pair->val = val;
    // 出现hash冲突时, 将当前下标所在节点放在新节点的下一节点, 进行链式存储
    pair->next = map->buckets[index];

    // 如果当前下标没有值, 则是第一次添加, 更新节点数量
    if (map->buckets[index] == NULL) {
        map->count++;
    }

    map->buckets[index] = pair;

    // (节点数量/桶容量) 大于扩容因子, 进行扩容操作
    if ((double)map->count / map->size >= LOAD_FACTOR) {
        resize(map);
    }
}

// 删除
void delete(HashMap* map, const char* key) {
    const unsigned int index = hash(key);

    Pair *cur = map->buckets[index];
    const Pair *root = cur;
    Pair *pre = cur;

    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            Pair *tmp = cur;

            // 如果删除的是当前下标所在链表的头节点, 将下一节点作为头节点
            if (cur == root) {
                map->buckets[index] = cur->next;
            } else {
                pre->next = cur->next;
            }

            // 如果当前下标链表为空, 更新节点数量
            if (map->buckets[index] == NULL) {
                map->count--;
            }

            free(tmp->key);
            free(tmp);
            break;
        }

        pre = cur;
        cur = cur->next;
    }
}

// 查询
int search(const HashMap* map, const char* key) {
    const unsigned int index = hash(key);

    const Pair *cur = map->buckets[index];

    if (cur == NULL) {
        return -1;
    }

    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            return cur->val;
        }

        cur = cur->next;
    }

    return -1;
}

// 释放内存
void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Pair *cur = map->buckets[i];

        while (cur != NULL) {
            Pair *tmp = cur;
            cur = cur->next;

            free(tmp->key);
            free(tmp);
        }
    }

    free(map->buckets);
    free(map);
}

// 扩容
void resize(HashMap* map) {
    // 新的桶容量更新为原来的两倍
    const int newSize = map->size * 2;
    // 如果新容量大于最大容量, 不再进行扩容
    if (newSize > MAX_CAPACITY) return;

    Pair **newBucket;

    if ((newBucket = malloc(sizeof(Pair*) * newSize)) == NULL) {
        perror("Allocate memory error!");
        freeHashMap(map);
        exit(EXIT_FAILURE);
    }

    // 将桶内所有Pair指针的地址初始化为NULL
    for (int i = 0; i < newSize; i++) {
        newBucket[i] = NULL;
    }

    HASH_MODE = newSize;

    // 将节点数量更新为0, 因为要对所有节点重新进行hash, 节点数量需要重新计数
    map->count = 0;
    for (int i = 0; i < map->size; i++) {
        Pair *cur = map->buckets[i];

        while (cur != NULL) {
            Pair *next = cur->next;
            const unsigned int index = hash(cur->key);
            cur->next = newBucket[index];
            if (newBucket[index] == NULL) {
                map->count++;
            }
            newBucket[index] = cur;

            cur = next;
        }
    }

    free(map->buckets);

    map->size = newSize;
    map->buckets = newBucket;
}

int main() {
    HashMap *map = createHashMap();

    insert(map, "ab", 1);
    insert(map, "cd", 2);
    delete(map, "ab");
    delete(map, "xy");
    insert(map, "ab", 2);
    insert(map, "ef", 3);
    delete(map, "ef");
    insert(map, "a", 3);
    insert(map, "b", 3);
    insert(map, "c", 3);
    insert(map, "d", 3);
    insert(map, "e", 3);
    insert(map, "f", 3);
    insert(map, "g", 3);
    insert(map, "h", 3);

    const int val = search(map, "ab");

    printf("val=%d\n", val);

    for (int i = 0; i < map->size; i++) {
        const Pair *cur = map->buckets[i];

        while (cur != NULL) {
            printf("key: %s, value: %d\n", cur->key, cur->val);

            cur = cur->next;
        }
    }

    freeHashMap(map);

    return EXIT_SUCCESS;
}
