
## 基础数据结构

### vector
- 定义：`vector<int> v;`
- 添加元素：`v.push_back(x);`
- 访问元素：`v[i]` or `*(v.begin() + i)`
- 大小：`v.size();`
- 创建迭代器：`vector<int>::iterator it`
- 通过迭代器访问元素：`*it`

### stack
- 定义：`stack<int> s;`
- 入栈：`s.push(x);`
- 出栈：`s.pop();`
- 访问栈顶：`s.top();`
- 判空：`s.empty();`
- 大小：`s.size();`

### queue
- 定义：`queue<int> q;`
- 入队：`q.push(x);`
- 出队：`q.pop();`
- 访问队首：`q.front();`
- 判空：`q.empty();`
- 大小：`q.size();`

### deque
- 定义：`deque<int> d;`
- 头部插入：`d.push_front(x);`
- 尾部插入：`d.push_back(x);`
- 头部删除：`d.pop_front();`
- 尾部删除：`d.pop_back();`
- 访问元素：`d[i]`
- 大小：`d.size();`
- 判空：`d.empty();`

### set
- 定义：`set<int> s;`
- 插入：`s.insert(x);`
- 删除：`s.erase(x);`
- 查找：`s.find(x) != s.end();`
- 大小：`s.size();`
- 判空：`s.empty();`
- 遍历：
  ```cpp
  for (int x : s) { /* ... */ }
  ```

### map
- 定义：`map<int, int> m;`
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
