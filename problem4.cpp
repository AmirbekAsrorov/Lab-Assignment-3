#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertBack(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        Node* curr = head;
        Node* prevNode = nullptr;

        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prevNode;
            curr->prev = nextNode;
            prevNode = curr;
            curr = nextNode;
        }

        tail = head;
        head = prevNode;
    }

    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    int n, num;
    cout << "Enter the number of elements for the list: ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        list.insertBack(num);
    }

    cout << "Original list: ";
    list.printList();

    cout << "Reversed list: ";
    list.reverse();
    list.printList();

    return 0;
}
