#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left != nullptr) {
            q.push(current->left);
        } else {
            current->left = new Node(value);
            return root;
        }

        if (current->right != nullptr) {
            q.push(current->right);
        } else {
            current->right = new Node(value);
            return root;
        }
    }

    return root;
}

int findLevel(Node* root, int value, int level) {
    if (root == nullptr) {
        return -1;
    }

    if (root->data == value) {
        return level;
    }

    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != -1) {
        return leftLevel;
    }

    return findLevel(root->right, value, level + 1);
}

int findDistance(Node* root, int x, int y) {
    if (root == nullptr) {
        return 0;
    }

    Node* commonAncestor = nullptr;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if ((current->data == x || current->data == y) && commonAncestor == nullptr) {
            commonAncestor = current;
        }

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }

        if (commonAncestor != nullptr) {
            if (current->data == x || current->data == y) {
                return abs(findLevel(root, x, 0) - findLevel(root, y, 0));
            } else if (findLevel(current, x, 0) != -1 || findLevel(current, y, 0) != -1) {
                int distanceX = findLevel(current, x, 0);
                int distanceY = findLevel(current, y, 0);
                return distanceX + distanceY;
            }
        }
    }

    return 0;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    Node* root = nullptr;

    cout << "Enter " << n << " integer numbers: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }

    int x, y;
    cout << "Enter two numbers (x and y): ";
    cin >> x >> y;

    int distance = findDistance(root, x, y);

    cout << "Minimum distance between " << x << " and " << y << " is: " << distance << endl;

    return 0;
}

