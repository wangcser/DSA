#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {};
};

class List {
public:
    List() {
        head = nullptr;
        tail = nullptr;
    };

    ~List() {};

    bool isEmpty();

    int length();

    bool find(int n);

    void push_front(int n);

    void push_back(int n);

    void pop_front();

    void pop_back();

    void insert(int i, int n);

    void traverse();

    void reverse();

    void unique();

    void sort();


private:
    ListNode *head;
    ListNode *tail;
};

bool List::isEmpty() {
    if (head == nullptr) return true;
    else return false;
}

int List::length() {
    if (isEmpty()) return 0;

    int count = 0;
    ListNode *cur = head;
    while (cur != nullptr) {
        count++;
        cur = cur->next;
    }

    return count;
}

bool List::find(int n) {
    if (isEmpty()) return false;

    ListNode *cur = head;
    while (cur != nullptr && cur->val != n)
        cur = cur->next;

    if (cur != nullptr) return true;
    else return false;
}

void List::push_front(int n) {
    if (isEmpty()) {
        head = new ListNode(n);
        tail = head;
        return;
    }

    ListNode *node = new ListNode(n);
    node->next = head;
    head = node;
}

void List::push_back(int n) {
    if (isEmpty()) {
        tail = new ListNode(n);
        head = tail;
        return;
    }

    tail->next = new ListNode(n);
    tail = tail->next;
}

void List::pop_front() {
    if (isEmpty()) return;

    ListNode *tmp = head;
    head = head->next;

    tmp->next = nullptr;
    delete tmp;
}

void List::pop_back() {
    if (isEmpty()) return;

    ListNode *pre = head;
    while (pre->next != tail)
        pre = pre->next;

    ListNode *tmp = tail;
    tail = pre;

    tail->next = nullptr;
    delete tmp;
}

void List::insert(int i, int n) {

    if (i == 0) {
        push_front(n);
        return;
    } else if (i == length()) {
        push_back(n);
        return;
    } else if (i < 0 || i > length())
        return;

    ListNode *pre = head;
    while (i > 1) {
        pre = pre->next;
        i--;
    }
    ListNode *node = new ListNode(n);
    node->next = pre->next;
    pre->next = node;
}

void List::traverse() {
    if (isEmpty()) {
        cout << "list is empty." << endl;
        return;
    }

    ListNode *cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }

    cout << endl;
}

void List::reverse() {
    if (isEmpty()) return;

    tail = head;

    ListNode *pre = nullptr;
    ListNode *cur = head;

    while (cur != nullptr) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    head = pre;
}

void List::unique() {
    if (isEmpty() || length() < 2) return;

    set<int> myset;
    ListNode *pre = new ListNode(-1);
    ListNode *cur = head;

    while (cur != nullptr) {
        if (myset.find(cur->val) == myset.end()) {
            myset.insert(cur->val);
            pre->next = cur;
            pre = cur;
        }

        cur = cur->next;
    }

    pre->next = nullptr;
    tail = pre;
}

void List::sort() {
    ListNode *cur = head;
    ListNode *nHead = new ListNode(-1);
//    nHead->next = cur;

//    cur = cur->next;
    while (cur != nullptr) {
        ListNode *ncur = nHead;
        while (ncur->next != nullptr && ncur->next->val <= cur->val) {
            ncur = ncur->next;
        }

        ListNode *next = cur->next;
        cur->next = ncur->next;
        ncur->next = cur;

        cur = next;
    }

    head = nHead->next;
}


int main() {
    // test code
    List l;
    l.push_front(1);
    l.push_back(2);
    l.push_front(0);
    l.push_back(3);
    l.insert(0, 10);
    l.insert(4, 3);
    l.push_back(2);
    l.push_back(2);
    l.push_back(2);
    l.push_back(4);
    l.push_back(5);
    l.push_back(10);
    l.push_back(10);

    l.traverse();

//    l.unique();

//    l.traverse();

//    l.reverse();

    l.sort();

    l.traverse();

}