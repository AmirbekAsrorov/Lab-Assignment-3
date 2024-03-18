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

    void deleteAtPosition(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position." << endl;
            return;
        }
        Node* curr = head;
        if (position == 0) {
            head = head->next;
        } else {
            for (int i = 0; i < position - 1; i++) {
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        size--;
    }

    int getSize() {
        return size;
    }
};

int main() {
    LinkedList list;

    int n, num;
    cout << "Enter the number of elements for the list:";
    cin >> n;

    cout << "Enter " << n << " elements:";
    for (int i = 0; i < n; i++) {
        cin >> num;
        list.insert(num);
    }

    int position;
    cout << "Enter the position of the element to delete (0-indexed):";
    cin >> position;

    list.deleteAtPosition(position);

    cout << "Size of the list:" << list.getSize() << endl;

    return 0;
}
