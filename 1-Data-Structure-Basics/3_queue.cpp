#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // 入队
    q.push(10);
    q.push(20);
    q.push(30);

    // 访问队首
    cout << "Front element: " << q.front() << endl;

    // 出队
    q.pop();
    cout << "Front element: " << q.front() << endl;

    // 大小
    cout << "Queue size: " << q.size() << endl;

    // 判空
    cout << "If the queue is empty: " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
