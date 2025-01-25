class MyCircularQueue {
public:
    int front;
    int rear;
    int size;
    int *arr;

    MyCircularQueue(int k) {
        front = -1;
        rear = -1;
        size = k;
        arr = new int[size];
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % size; // Move rear in a circular manner
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) { // Single element left
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size; // Move front in a circular manner
        }

        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */