#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // 插入
    s.insert(10);
    s.insert(20);
    s.insert(30);

    // 查找
    if (s.find(20) != s.end()) {
        cout << "20 is in the set. " << endl;
    }

    // 删除
    s.erase(10);

    // 大小
    cout << "Set size: " << s.size() << endl;

    // 判空
    cout << "If the set is empty: " << (s.empty() ? "Yes" : "No") << endl;

    // 遍历
    cout << "Traversal: ";
    for (int x : s) cout << x << " ";
    cout << endl;

    // lower_bound/upper_bound
    s.insert(25);
    auto it = s.lower_bound(21);
    if (it != s.end()) cout << "The minimun number greater than 21: " << *it << endl;

    return 0;
}
