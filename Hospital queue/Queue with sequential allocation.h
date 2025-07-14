#ifndef QUEUE_SEQUENTIAL_ALLOCATION_H_INCLUDED
#define QUEUE_SEQUENTIAL_ALLOCATION_H_INCLUDED

template <typename Type>
class Queue {
private:
    int rear, front;
    unsigned count;
    unsigned capacity;
    Type* array;

public:
    Queue(unsigned size) {
        rear = -1;
        front = 0;
        count = 0;
        capacity = size;
        array = new Type[capacity];
    }

    ~Queue() {
        delete[] array;
    }

    void enqueue(Type x) {
        rear++;
        if (rear == capacity) {
            rear = 0; // circular queue wrap-around
        }
        array[rear] = x;
        count++;
    }

    Type dequeue() {
        Type temp = array[front];
        front++;
        if (front == capacity) {
            front = 0; // circular queue wrap-around
        }
        count--;
        return temp;
    }

    Type first() {
        return array[front];
    }

    Type last() {
        return array[rear];
    }

    bool isFull() {
        return count == capacity;
    }

    bool isEmpty() {
        return count == 0;
    }

    int getRear() {
        return rear;
    }

    int getFront() {
        return front;
    }

    Type getValue(unsigned position) {
        return array[position];
    }

    unsigned getCapacity() {
        return capacity;
    }
};

#endif // QUEUE_SEQUENTIAL_ALLOCATION_H_INCLUDED

