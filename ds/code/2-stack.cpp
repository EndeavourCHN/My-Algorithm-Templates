#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // 入栈
    s.push(10);
    s.push(20);
    s.push(30);

    // 访问栈顶
    cout << "Top element: " << s.top() << endl;

    // 出栈
    s.pop();
    cout << "Top element: " << s.top() << endl;

    // 大小
    cout << "Stack size: " << s.size() << endl;

    // 判空
    cout << "Is the stack empty: " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
