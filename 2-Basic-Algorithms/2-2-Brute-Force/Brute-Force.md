
## next_permutation

`next_permutation` 是 C++ STL 中用于生成序列的下一个字典序排列的函数，常用于全排列枚举。

- 头文件：`#include <algorithm>`
- 用法：`next_permutation(begin, end);`
- 返回值：如果存在下一个排列，返回 `true`，否则返回 `false` 并将序列变为最小排列。

**示例：**
```cpp
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    do {
        for (int x : v) cout << x << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}
```
```
输出：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```
