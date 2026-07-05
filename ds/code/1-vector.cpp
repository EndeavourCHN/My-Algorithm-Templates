#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main(){
	// 添加元素
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // 访问元素
    cout << "v[1] = " << v[1] << endl;

    // 大小
    cout << "Size = " << v.size() << endl;

    // 改变大小
    v.resize(5, -1); // 新增部分初始化为-1
    cout << "Resized to 5: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // 创建迭代器
    vector<int>::iterator it = v.begin();
    cout << "The first element: " << *it << endl;

    // 通过迭代器访问元素
    cout << "The third element: " << *(v.begin() + 2) << endl;

    // 排序
    sort(v.begin(), v.end());
    cout << "Sorted vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;

	return 0;
}
