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
        if((front == 0 && rear == size-1) || (rear +1 == front)){
            return false;
        }

        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = value;
            return true;
        }

        else if(front!= 0 && rear == size-1){
            rear = 0;
            arr[rear] = value;
            return true;
        }
        else{
            rear++;
            arr[rear] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if(front == -1 && rear == -1){
            return false;
        }

        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
            return true;
        }

        else if(front == size - 1 && rear!=size-1){
            arr[front] = -1;
            front = 0;
            return true;
        }
        else{
            arr[front] = -1;
            front++;
            return true;

        }
    }
    
    int Front() {
        if(front == -1 && rear == -1){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int Rear() {
        if(front == -1 && rear == -1){
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        return (front == -1 && rear ==-1 ) ? true : false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size-1) || (rear +1 == front)){
            return true;
        }
        else{
            return false;
        }
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