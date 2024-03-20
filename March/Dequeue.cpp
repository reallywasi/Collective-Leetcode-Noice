#include <iostream>
using namespace std;

#define MAX_SIZE 100 // Maximum size of the deque

class Deque {
private:
    int arr[MAX_SIZE]; // Array to store elements of the deque
    int front, rear;   // Pointers to the front and rear of the deque
public:
    Deque() { // Constructor to initialize the deque
        front = -1; // Initialize front pointer to -1 (indicating an empty deque)
        rear = -1;  // Initialize rear pointer to -1 (indicating an empty deque)
    }

    void push_front(int value) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
            // Check if the deque is full
            cout << "Deque is full, cannot push front\n";
            return;
        }
        if (front == -1) {
            // If the deque is empty, set front and rear to 0
            front = 0;
            rear = 0;
        } else if (front == 0) {
            // If front is at the beginning of the array, wrap around
            front = MAX_SIZE - 1;
        } else {
            // Move front pointer towards the beginning of the array
            front--;
        }
        // Insert the value at the new front position
        arr[front] = value;
    }

    void push_back(int value) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
            // Check if the deque is full
            cout << "Deque is full, cannot push back\n";
            return;
        }
        if (rear == -1) {
            // If the deque is empty, set front and rear to 0
            front = 0;
            rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            // If rear is at the end of the array, wrap around
            rear = 0;
        } else {
            // Move rear pointer towards the end of the array
            rear++;
        }
        // Insert the value at the new rear position
        arr[rear] = value;
    }

    void pop_front() {
        if (front == -1) {
            // Check if the deque is empty
            cout << "Deque is empty, cannot pop front\n";
            return;
        }
        // Display and remove the front element
        cout << "Popping front: " << arr[front] << endl;
        if (front == rear) {
            // If only one element is present, reset front and rear
            front = -1;
            rear = -1;
        } else if (front == MAX_SIZE - 1) {
            // If front is at the end of the array, wrap around
            front = 0;
        } else {
            // Move front pointer towards the end of the array
            front++;
        }
    }

    void pop_back() {
        if (rear == -1) {
            // Check if the deque is empty
            cout << "Deque is empty, cannot pop back\n";
            return;
        }
        // Display and remove the back element
        cout << "Popping back: " << arr[rear] << endl;
        if (front == rear) {
            // If only one element is present, reset front and rear
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            // If rear is at the beginning of the array, wrap around
            rear = MAX_SIZE - 1;
        } else {
            // Move rear pointer towards the beginning of the array
            rear--;
        }
    }

    int get_front() {
        if (front == -1) {
            // Check if the deque is empty
            cout << "Deque is empty\n";
            return -1;
        }
        // Return the value at the front of the deque
        return arr[front];
    }

    int get_back() {
        if (rear == -1) {
            // Check if the deque is empty
            cout << "Deque is empty\n";
            return -1;
        }
        // Return the value at the back of the deque
        return arr[rear];
    }

    bool is_empty() {
        // Check if the deque is empty
        return front == -1;
    }

    bool is_full() {
        // Check if the deque is full
        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
    }
};

int main() {
    Deque dq; // Create an instance of the Deque

    // Push elements to the front and back of the deque
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(5);
    dq.push_front(2);

    // Display the front and back elements of the deque
    cout << "Front element: " << dq.get_front() << endl;
    cout << "Back element: " << dq.get_back() << endl;

    // Pop elements from the front and back of the deque
    dq.pop_front();
    dq.pop_back();

    // Display the front and back elements of the deque after popping
    cout << "Front element after popping: " << dq.get_front() << endl;
    cout << "Back element after popping: " << dq.get_back() << endl;

    return 0;
}
