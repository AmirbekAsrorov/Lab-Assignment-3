#include<iostream>
#include<vector>

using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void insertAtPosition(int val, int position) {
        if (position < 0 || position > size) {
            cout << "Invalid position." << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            for (int i = 0; i < position - 1; i++) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        size++;
    }

    int getSize() {
        return size;
    }
};

int main() {
    LinkedList list;

    int n, num;
    cout << "Enter the number of elements for the list: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        list.insert(num);
    }

    int value, position;
    cout << "Enter the value to insert: ";
    cin >> value;
    cout << "Enter the position to insert (0-indexed): ";
    cin >> position;

    list.insertAtPosition(value, position);

    cout << "Size of the list: " << list.getSize() << endl;

    return 0;
}
