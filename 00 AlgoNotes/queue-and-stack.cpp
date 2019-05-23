class Queue {
    private:
        vector<int> data;
        int p_start;
    public:
        Queue() {
            p_start = 0;
        }

        bool enQueue(int x) {
            data.push_back(x);
            return true;
        }

        bool deQueue() {
            if(isEmpty()) return false;
            p_start++;

            return true;
        }

        int front() {
            return fata[p_start];
        }

        bool isEmpty() {
            return p_start >= data.size();
        }
}

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

int main() {
    // 1. init
    queue<int> q;
    // 2. push new element to the tail
    q.push(1);
    // 3. get the front element
    int head = q.front();
    // 4. get the last element
    int tail = q.back();
    // 5. get the size of queue
    int len = q.size();
    // 6. check if the queue is empty
    if(q.empty()) ;
    // 7. pop first element
    q.pop();
}

void bfs(Node* root) {
    // state
    queue<Node*> q;
    int step = 0;

    // 1. init
    q.push(root);

    // 2. BFS
    while(!q.empty()) {
        // 执行的轮次
        step++;
        // 当前层的访问数量，我们是不知道下一层和上一层的数量的
        // 因为都不会出现在队列中
        int size = q.size();
        for(int i = 0; i < size; i++) {
            // 2.1 获取队头元素
            Node* cur = q.front();
            // 2.2 访问队头元素
            // doSomething(cur);
            // 2.3 将其邻接点加入队列
            for(auto next : cur->nexts) {
                q.push(next);
            }
            // 2.4 删除队头元素
            q.pop();
        }
    }
}


class Stack {
    private:
        vector<int> data;
    public:
        void push(int x) {
            data.push_back(x);
        }

        bool isEmpty() {
            return data.empty();
        }

        int top() {
            return data.back();
        }

        bool pop() {
            if(isEmpty()) return false;

            data.pop_back();
            return true;
        }
}

int main() {
    stack<int> s;
    s.push(1);
    if(s.empty()) ;
    int element = s.top();
    s.size();
    s.pop();
}