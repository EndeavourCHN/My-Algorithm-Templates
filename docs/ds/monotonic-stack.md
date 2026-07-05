# 单调栈

单调栈是一种栈结构，栈内元素保持单调递增或递减。常用于解决“下一个更大/小元素”、“区间最值”等问题。

## 基本思想

- 入栈时弹出不满足单调性的元素，保证栈内元素单调。
- 适合处理一维数组的区间性质问题。

## 常见应用

- 下一个更大/小元素
- 柱状图最大矩形
- 单调区间最值

## 代码示例（下一个更小元素）

```cpp
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmaller(const vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && nums[stk.top()] > nums[i]) {
            res[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    return res;
}
```

## 注意事项

- 单调栈适用于需要快速获取下一个更大/小元素或维护单调性质的问题。
- 注意边界处理和下标的使用。
