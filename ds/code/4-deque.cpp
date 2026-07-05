#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;

    // 头部插入
    d.push_front(10);
    // 尾部插入
    d.push_back(20);

    // 头部删除
    d.pop_front();
    // 尾部删除
    d.push_front(30);
    d.pop_back();

    // 访问队首和队尾
    d.push_back(40);
    cout << "Front: " << d.front() << ", Back: " << d.back() << endl;

    // 访问元素
    d.push_back(50);
    cout << "d[1]: " << d[1] << endl;

    // 大小
    cout << "Deque size: " << d.size() << endl;

    // 判空
    cout << "If the deque is empty: " << (d.empty() ? "Yes" : "No") << endl;

    return 0;
}
