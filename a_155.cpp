#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>

using namespace std;

struct Node {
    int val;
    int min;
    Node* next;
    Node(int a, int b, Node* c): val(a), min(b), next(c) {}
};

class MinStack {
private:
    Node* head;
public:
    MinStack() {
        head = nullptr;
    }

    void push(int val) {
        if (head == nullptr) {
            head = new Node(val, val, nullptr);
        } else {
            Node* node = new Node(val, min(val, head->min), head);
            head = node;
        }
    }

    void pop() {
        head = head->next;
    }

    int top() {
        return head->val;
    }

    int getMin() {
        return head->min;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
