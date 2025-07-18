#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;

    // 插入/赋值
    m["apple"] = 5;
    m["banana"] = 3;

    // 查找
    if (m.find("apple") != m.end()) {
        cout << "apple number: " << m["apple"] << endl;
    }

    // 删除
    m.erase("banana");

    // 大小
    cout << "Map size: " << m.size() << endl;

    // 判空
    cout << "If the map is empty: " << (m.empty() ? "Yes" : "No") << endl;

    // 遍历
    for (auto &p : m) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
