#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_KEY_LEN 100
#define MAX_TABLE_SIZE 1000

typedef struct HashNode{
    char *key;
    int value;
    struct HashNode *nextNode;
}HashNode;


typedef struct HashTable{
    HashNode * hashNode[MAX_TABLE_SIZE];
    int currentIndex;
}HashTable;


unsigned long HashFun(const char *key)
{
    unsigned long hash = 0;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        hash = hash * 33 + key[i];
    }
    return hash;
}
//初始化
void InitHashTable(HashTable *hashTable)
{
    memset(hashTable->hashNode, 0, sizeof(HashNode *) * MAX_TABLE_SIZE);
    hashTable->currentIndex = 0;
}

//插入key value
void Insert(HashTable *hashTable, char *key, int value)
{
    int pos = HashFun(key) % MAX_TABLE_SIZE;
    HashNode * newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->nextNode = NULL;
    newNode->key = (char *)malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(newNode->key, key);
    newNode->key[strlen(key)] = '\0';
    newNode->value = value;
    HashNode *p = hashTable->hashNode[pos];
    if (p == NULL) {  //如果头结点为空，说明没有冲突
        hashTable->hashNode[pos] = newNode;
        hashTable->currentIndex++;
        return;
    }
    //头结点不为空，同时头结点的key和输入的key相同，覆盖value
    if (strcmp(p->key, key) == 0) {
        p->value = value;
        return;
    }

    //头结点不为空，冲突，插入到链表的第二个节点
    HashNode *q = p->nextNode;
    newNode->nextNode = q;
    p->nextNode = newNode;
}

int * Get(HashTable *hashTable, char *key)
{
    int pos = HashFun(key) % MAX_TABLE_SIZE;
    HashNode *p = hashTable->hashNode[pos];
    if (p == NULL) {  //如果头结点为空，说明不存在这样的key
        return NULL;
    } else {
        HashNode *q = p;
        while (q != NULL) {
            if(strcmp(q->key, key) == 0) {
                return &(q->value);
            }
            q = q->nextNode;
        }
        return NULL;
    }
}

int Drop(HashTable *hashTable, char *key)
{
    int pos = HashFun(key) % MAX_TABLE_SIZE;
    HashNode *p = hashTable->hashNode[pos];
    if (p == NULL) {  //如果头结点为空，说明不存在这样的key
        return 0;
    }
    else {
        if(strcmp(p->key, key) == 0) {  //删除的如果是头结点
            hashTable->hashNode[pos] = p->nextNode;
            free(p->key);
            free(p);
            return 1;
        }
        //删除的不是头结点的情况
        HashNode *q = p->nextNode;
        HashNode * last = p;
        while (q != NULL) {
            if(strcmp(q->key, key) == 0) {
                last->nextNode = q->nextNode;
                free(q->key);
                free(q);
                return 1;
            }
            last = q;
            q = q->nextNode;
        }
        return 0;
    }
}


void ClearHashTable(HashTable* hashTable)
{
    for(int i = 0; i < MAX_TABLE_SIZE; i++) {
        HashNode *head = hashTable->hashNode[i];
        while(head) {
            HashNode *temp = head->nextNode;
            free(head->key);
            free(head);
            head = temp;
        }
    }
}

void PrintHashTable(HashTable *hashTable)
{
    for(int i = 0; i < MAX_TABLE_SIZE; i++) {
        HashNode *head = hashTable->hashNode[i];
        if (head == NULL)
            continue;
        printf("\nindex:%d======>", i);
        printf("(%s:%d)", head->key, head->value);
        head = head->nextNode;
        while(head) {
            printf("-->(%s:%d)", head->key, head->value);
            head = head->nextNode;
        }
    }
}

int main(void)
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    InitHashTable(hashTable);
    Insert(hashTable,"1234", 1);
    Insert(hashTable,"11234", 1);
    Insert(hashTable,"hello", 2);
    Insert(hashTable,"world", 3);
    Insert(hashTable,"hzp", 4);
    Insert(hashTable,"java", 5);
    Insert(hashTable,"b", 12);
    Insert(hashTable,"c", 12);
    Insert(hashTable,"c1", 12);
    Insert(hashTable,"c++", 18);
    Insert(hashTable,"html", 18);
    Insert(hashTable,"web", 18);
    Insert(hashTable,"python", 56);
    PrintHashTable(hashTable);
    int *data = Get(hashTable,"b");
    printf("\n====%d=====\n", *data);
    Drop(hashTable, "python");
    PrintHashTable(hashTable);
    ClearHashTable(hashTable);

}