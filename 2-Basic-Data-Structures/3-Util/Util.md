
# 单调栈与单调队列

## 单调栈

单调栈是一种栈结构，栈内元素保持单调递增或递减。常用于解决“下一个更大/小元素”、“区间最值”等问题。

### 基本思想

- 入栈时弹出不满足单调性的元素，保证栈内元素单调。
- 适合处理一维数组的区间性质问题。

### 常见应用

- 下一个更大/小元素
- 柱状图最大矩形
- 单调区间最值

### 代码示例（下一个更小元素）

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

---

## 单调队列

单调队列是一种队列结构，队列内元素保持单调递增或递减。常用于滑动窗口最值、DP优化等场景。

### 基本思想

- 入队时弹出不满足单调性的队尾元素，保证队列单调。
- 队首元素始终是当前窗口的最值。

### 常见应用

- 滑动窗口最大/最小值
- 队列优化DP（如最短路、斜率优化）

### 代码示例（滑动窗口最大值）

```cpp
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k) dq.pop_front();
        if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}
```

---

## 注意事项

- 单调栈/队列适用于需要快速获取区间最值或下一个更大/小元素的问题。
- 注意边界处理和下标的使用。

