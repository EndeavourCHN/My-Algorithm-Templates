# 基础数据结构

## 一）线性表

### 1 动态数组 vector
- 定义：`vector<int> v;`
- 添加元素：`v.push_back(x);`
- 访问元素：`v[i]`
- 大小：`v.size();`
- 改变大小：`v.resize(n);` 或 `v.resize(n, val);`
- 创建迭代器：`vector<int>::iterator it`
- 通过迭代器访问元素：`*it` 或 `*(v.begin() + i)`
- 排序：`sort(v.begin(), v.end());`

### 2 栈 stack
- 定义：`stack<int> s;`
- 入栈：`s.push(x);`
- 出栈：`s.pop();`
- 访问栈顶：`s.top();`
- 大小：`s.size();`
- 判空：`s.empty();`

### 3 队列 queue
- 定义：`queue<int> q;`
- 入队：`q.push(x);`
- 出队：`q.pop();`
- 访问队首：`q.front();`
- 大小：`q.size();`
- 判空：`q.empty();`

### 4 双端队列 deque
- 定义：`deque<int> d;`
- 头部插入：`d.push_front(x);`
- 尾部插入：`d.push_back(x);`
- 头部删除：`d.pop_front();`
- 尾部删除：`d.pop_back();`
- 访问队首：`d.front();`
- 访问队尾：`d.back();`
- 访问元素：`d[i]`
- 大小：`d.size();`
- 判空：`d.empty();`

## 二）链式结构

### 5 链表 list
- 定义：`list<int> l;`
- 头部插入：`l.push_front(x);`
- 尾部插入：`l.push_back(x);`
- 头部删除：`l.pop_front();`
- 尾部删除：`l.pop_back();`
- 访问头部：`l.front();`
- 访问尾部：`l.back();`
- 创建迭代器：`list<int>::iterator it;`
- 插入（指定位置）：`l.insert(it, x);`
- 删除（指定位置）：`l.erase(it);`
- 删除指定值：`l.remove(x);`
- 大小：`l.size();`
- 判空：`l.empty();`
- 遍历：
  ```cpp
  for (int x : l) { /* ... */ }

  for (it = l.begin(); it != l.end(); it++) { /* ... */ }
  ```

## 三）关联式容器

### 6 集合 set
- 定义：`set<int> s;`
- 插入：`s.insert(x);`
- 删除（按元素）：`s.erase(x);`
- 删除（按地址）：`s.erase(it);`
- 查找：`s.find(x);`，查询x在集合中的地址，如果这个数不存在，返回 `s.end()`。
- 查询不小于 $x$ 的最小数的地址：`s.lower_bound(x);`
- 查询不大于 $x$ 的最大数的地址：`s.upper_bound(x);`
- 大小：`s.size();`
- 判空：`s.empty();`
- 遍历：
  ```cpp
  for (int x : s) { /* ... */ }
  ```

### 7 映射表 map
- 定义：`map<A, B> m;`，创建下标类型为 `A`，元素类型为 `B` 的映射表。
- 插入/赋值：`m[key] = value;`
- 查找：`m.find(key) != m.end();`
- 删除：`m.erase(key);`
- 大小：`m.size();`
- 判空：`m.empty();`
- 遍历：
  ```cpp
  for (auto &p : m) {
      int key = p.first, value = p.second;
      // ...
  }
  ```
