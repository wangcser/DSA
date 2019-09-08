#include <iostream>
#include <vector>

using namespace std;

class CirQueue {
public:
    explicit CirQueue(int size) : head(0), tail(0), count(0), qSize(size) {
        que.resize(qSize);
    };

    void push(int num);

    void pop();

    int front();

    int back();

    int size();

    bool empty();

    bool full();

    void traverse();

private:
    vector<int> que;
    int head;
    int tail;
    int count;
    int qSize;
};

bool CirQueue::empty() {
    return head == tail;
}

bool CirQueue::full() {
    return (tail + 1) % qSize == head;
}

void CirQueue::push(int num) {
    if (full()) {
        cout << "que is full." << endl;
        return;
    }

    que[tail] = num;
    count++;
    tail = (tail + 1) % qSize;
}

void CirQueue::pop() {
    if (empty()) {
        cout << "que is empty." << endl;
        return;
    }

    count--;
    head = (head + 1) % qSize;
}

int CirQueue::front() {
    return empty() ? -1 : que[head];
}

int CirQueue::back() {
    return empty() ? -1 : que[tail - 1];
}

int CirQueue::size() {
    return count;
}

void CirQueue::traverse() {
    if (empty()) {
        cout << "que is empty" << endl;
        return;
    }

    int i = head;
    while (i != tail) {
        cout << que[i] << " ";
        i = (i + 1) % qSize;
    }
    cout << endl;
}


int main() {

    CirQueue q(11);

    for (int i = 1; i <= 20; ++i)
        q.push(i);

    cout << q.size() << endl;
    q.traverse();

    return 0;
}