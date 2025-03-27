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

class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main(int argc, char *argv[]) {
    MyStack stack;

    return 0;
}
