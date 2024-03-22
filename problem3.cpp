#include<iostream>

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

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        Node* temp = head;

        if (position == 1) {
            head = head->next;
            delete temp;
        } else {
            Node* prev = nullptr;
            for (int i = 1; i < position && temp != nullptr; i++) {
                prev = temp;
                temp = temp->next;
            }

            if (temp != nullptr) {
                prev->next = temp->next;
                delete temp;
            } else {
                cout << "Invalid position." << endl;
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

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
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
        list.insertAtEnd(value);
    }

    int position;
    cout << "Enter the position of the element to delete: ";
    cin >> position;
    list.deleteAtPosition(position);

    cout << "Updated list: ";
    list.displayList();

    return 0;
}
