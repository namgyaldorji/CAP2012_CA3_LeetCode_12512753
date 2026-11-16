#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> in, out;

    MyQueue() {}

    void push(int x) {
        in.push(x);
    }

    int pop() {
        peek();
        int val = out.top();
        out.pop();
        return val;
    }

    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}
