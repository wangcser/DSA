#include <iostream>
#include <map>

using namespace std;

class DeListNode {
public:
    int key;
    int val;
    DeListNode *prev;
    DeListNode *next;

    DeListNode() {
        prev = nullptr;
        next = nullptr;
    }
};

class LRU {
private:
    int capacity;
    DeListNode *head;
    DeListNode *tail;
    map<int, DeListNode *> nodeMap; // Node->key to Node

public:
    LRU(int c) : capacity(c) {
        head = new DeListNode();
        tail = new DeListNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key);

    void put(int key, int val);

    void insertAtHead(DeListNode *node);

    void removeAtTail();

    void moveToHead(DeListNode *node);

    void traverse();
};

int LRU::get(int key) {
    if (nodeMap.find(key) != nodeMap.end()) { // 直接从 map 中访问即可
        DeListNode *node = nodeMap[key];
        moveToHead(node);

        return node->val;
    }

    cout << "key " << key << " is not in LRU cache." << endl;

    return -1;
}

void LRU::put(int key, int val) {
    if (nodeMap.find(key) == nodeMap.end()) { // 如果是新的记录，则在头部插入新节点即可
        DeListNode *node = new DeListNode();
        node->key = key;
        node->val = val;

        if (nodeMap.size() == capacity) // 如果缓存满了，则删除最后一个有效节点
            removeAtTail();

        insertAtHead(node);
        // 将新记录加入 map
        nodeMap[node->key] = node;
    } else { // 旧的记录，将节点移动到头部即可
        moveToHead(nodeMap[key]);
    }
}

void LRU::insertAtHead(DeListNode *node) {
    // 插入到头节点之后
    head->next->prev = node;
    node->next = head->next;
    node->prev = head;
    head->next = node;
}


void LRU::moveToHead(DeListNode *node) {
    // 摘掉 cur 节点
    node->prev->next = node->next;
    node->next->prev = node->prev;

    // 插入到头结点之后
    insertAtHead(node);
}

void LRU::removeAtTail() {
    // 摘掉尾节点的上一个节点
    DeListNode *tmp = tail->prev;
    tmp->prev->next = tail;
    tail->prev = tmp->prev;

    // 删除其在 map 中的记录
    nodeMap.erase(tmp->key);

    // 释放被删除节点的空间
    delete tmp;
    tmp = nullptr;
}

void LRU::traverse() {
    DeListNode *cur = head->next;
    while (cur->next != nullptr) {
        cout << cur->key << ", " << cur->val << endl;
        cur = cur->next;
    }
}

int main() {
    LRU lru(5);
    lru.put(1, 1);
    lru.put(2, 1);
    lru.put(3, 1);
    lru.put(4, 1);

    lru.get(3);
    lru.put(5, 1);
    lru.get(2);

    lru.put(6, 1);

    lru.get(7);

    lru.put(4, 1);

    lru.traverse();

    return 0;
}