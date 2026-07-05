#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    // 头部插入
    l.push_front(10);
    // 尾部插入
    l.push_back(20);

    // 头部删除
    l.pop_front();
    // 尾部删除
    l.push_front(30);
    l.pop_back();

    // 访问头部和尾部
    l.push_back(40);
    cout << "Front: " << l.front() << ", Back: " << l.back() << endl;

    // 插入和删除（指定位置）
    auto it = l.begin();
    l.insert(it, 50);
    l.erase(l.begin());

    // 删除指定值
    l.push_back(60);
    l.remove(60);

    // 大小
    cout << "List size: " << l.size() << endl;

    // 判空
    cout << "If the list is empty: " << (l.empty() ? "Yes" : "No") << endl;

    // 遍历
    l.push_back(70);
    l.push_back(80);
    cout << "Traversal: ";
    for (int x : l) cout << x << " ";
    cout << endl;

    return 0;
}
