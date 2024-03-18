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

    int getSize() {
        Node *temp= head;
        int size = 0 ;
        while(temp){
        temp = temp->next
            size++;
        }
        return size;
    }

    int getMaximum() {
        if (head == nullptr) {
            return 0;
        }
        int maxVal = head->data;
        Node* curr = head->next;
        while (curr != nullptr) {
            if (curr->data > maxVal) {
                maxVal = curr->data;
            }
            curr = curr->next;
        }
        return maxVal;
    }

    int getMinimum() {
        if (head == nullptr) {
            return 0;
        }
        int minVal = head->data;
        Node* curr = head->next;
        while (curr != nullptr) {
            if (curr->data < minVal) {
                minVal = curr->data;
            }
            curr = curr->next;
        }
        return minVal;
    }

    int getFirst() {
        if (head == nullptr) {
            return 0;
        }
        return head->data;
    }
};

int main() {
    LinkedList list;

    int num;
    char ch;

    cout << "Enter numbers to insert into the list (enter a character to stop): ";
    while (cin >> num) {
        list.insert(num);
    }

    cout << "Maximum number: " << list.getMaximum() <<' '<< "First element: " << list.getFirst() << ' ' << "Size of the list: " << list.getSize() << ' ' << "Minimum number: " << list.getMinimum() << endl;

    return 0;
}


