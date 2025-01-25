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
        // Check if the queue is full
        if (isFull()) {
            return false;
        }

        // First element insertion
        if (front == -1 && rear == -1) {
            front++;
            rear++;
        }
        // Wrap rear to the beginning if needed
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        // Regular case: move rear forward
        else {
            rear++;
        }

        arr[rear] = value; // Insert the value
        return true;
    }

    bool deQueue() {
        // Check if the queue is empty
        if (isEmpty()) {
            return false;
        }

        // Single element in the queue
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        // Wrap front to the beginning if needed
        else if (front == size - 1) {
            front = 0;
        }
        // Regular case: move front forward
        else {
            front++;
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
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        // Check if the queue is full in a circular way
        return ((rear + 1) % size == front);
    }
};