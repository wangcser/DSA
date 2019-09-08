#include <iostream>
#include <vector>

using namespace std;

class Queue {
public:
    void push(int num);

    void pop();

    int front();

    int back();

    int size();

    bool empty();

    void traverse();

private:
    vector<int> que;
};

void Queue::push(int num) {
    que.push_back(num);
}

void Queue::pop() {
    que.erase(que.begin());
}

int Queue::front() {
    return que.front();
}

int Queue::back() {
    return que.back();
}

void Queue::traverse() {
    for (auto num : que) {
        cout << num << " ";
    }
    cout << endl;
}


int main() {

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout << q.front() << endl;

    q.traverse();

    return 0;
}