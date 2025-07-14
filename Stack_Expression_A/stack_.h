#ifndef STACK__H_INCLUDED
#define STACK__H_INCLUDED

// Node structure for the stack
template <typename Type>
struct Node {
    Type data;
    Node<Type>* next;
};

// Stack class using linked list
template <typename Type>
class Stack {
private:
    Node<Type>* top;

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Push an element onto the stack
    bool push(Type x) {
        bool success = true;
        Node<Type>* temp = new Node<Type>;
        if (temp == NULL) {
            success = false;
        } else {
            temp->data = x;
            temp->next = top;
            top = temp;
        }
        return success;
    }

    // Pop the top element from the stack
    Type pop() {
        Type value = top->data;
        Node<Type>* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Get the top element without removing it
    Type topElement() {
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Get pointer to the top node
    Node<Type>* getTop() {
        return top;
    }
};

#endif // STACK__H_INCLUDED

