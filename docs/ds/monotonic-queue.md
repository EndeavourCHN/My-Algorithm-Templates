# 单调队列

单调队列是一种队列结构，队列内元素保持单调递增或递减。常用于滑动窗口最值、DP 优化等场景。

## 基本思想

- 入队时弹出不满足单调性的队尾元素，保证队列单调。
- 队首元素始终是当前窗口的最值。

## 常见应用

- 滑动窗口最大/最小值
- 队列优化 DP

## 代码示例（滑动窗口最大值）

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

## 注意事项

- 单调队列适用于需要快速获取滑动窗口最值或维护区间最值的问题。
- 注意边界处理和下标的使用。
