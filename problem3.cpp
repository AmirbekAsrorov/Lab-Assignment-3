#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp != nullptr) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                cout << "Invalid position." << endl;
                delete newNode;
            }
        }
    }

    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        list.insertAtPosition(value, i + 1);
    }

    int newValue, position;
    cout << "Enter the value of the new element: ";
    cin >> newValue;
    cout << "Enter the position to insert the new element: ";
    cin >> position;
    list.insertAtPosition(newValue, position);

    cout << "Updated list: ";
    list.displayList();

    return 0;
}


