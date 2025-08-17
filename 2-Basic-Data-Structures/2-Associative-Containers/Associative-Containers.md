# 关联式容器

### 1 集合 set

- 头文件：`#include <set>`
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

### 2 映射表 map

- 头文件：`#include <map>`
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