# My-Algorithm-Templates

我的信竞笔记和代码模板库。For XCPC / 蓝桥杯

相关内容按照个人理解与习惯记录，随着学习与练习情况更新补充。鉴于鄙人水平有限，难免有错谬疏漏之处，还请谅解。若能提交Issues指正/补充，不胜感激！

**目前很多内容尚不完善，计划先构建大致框架，后续会逐步润色。**

考虑到控制台终端编码兼容性，文件命名和程序中输出部分文本使用英语，注释及 Markdown 文件使用中文。

This is my code templates library for competitive programming. For better compatibility of console terminal encoding, the file names and the output parts of the programs are in English, and the comments and Markdown files are in Chinese. 

### My OJ Accounts

Codeforces: https://codeforces.com/profile/EndeavourCHN

LeetCode: https://leetcode.cn/u/endeavourchn/

洛谷 (Luogu): https://www.luogu.com.cn/user/606580

## 目录

### 大纲

[My-Algorithm-Templates/](#my-algorithm-templates)
- [1-Basic-Algorithms/](#第一章-基础算法) # 基础算法
- [2-Basic-Data-Structures/](#第二章-基础数据结构) # 基础数据结构
- [3-Searching/](#第三章-搜索) # 搜索
- [4-DP/](#第四章-动态规划) # 动态规划
- [5-String/](#第五章-字符串) # 字符串
- [6-Tree/](#第六章-树论) # 树论
- [7-Graph/](#第七章-图论) # 图论
- [8-Maths/](#第八章-数学) # 数学
- [9-Other/](#第九章-其他) # 其他

### 第一章 基础算法
[1-Basic-Algorithms/](1-Basic-Algorithms/) # 基础算法
- [1-Sorting/](1-Basic-Algorithms/1-Sorting/Sorting.md) # 排序
- [2-Brute-Force/](1-Basic-Algorithms/2-Brute-Force/Brute-Force.md) # 枚举
  - [1-Subset-Enumeration](1-Basic-Algorithms/2-Brute-Force/Brute-Force.md/#1-子集枚举) # 子集枚举
  - [2-Permutation-Enumeration](1-Basic-Algorithms/2-Brute-Force/Brute-Force.md/#2-排列枚举) # 排列枚举
- [3-Binary-Search/](1-Basic-Algorithms/3-Binary-Search/Binary-Search.md) # 二分查找
- [4-Divide-and-Conquer/](1-Basic-Algorithms/4-Divide-and-Conquer/Divide-and-Conquer.md) # 分治
- [5-Binary-Lifting/](1-Basic-Algorithms/5-Binary-Lifting/Binary-Lifting.md) # 倍增
- [6-Greedy/](1-Basic-Algorithms/6-Greedy/Greedy.md) # 贪心
- [7-High-Precision/](1-Basic-Algorithms/7-High-Precision/High-Precision.md) # 高精度
- [8-Preprocessing/](1-Basic-Algorithms/8-Preprocessing/Preprocessing.md) # 预处理
  - [1-Prefix-Sum](1-Basic-Algorithms/8-Preprocessing/Preprocessing.md/#1-前缀和) # 前缀和
  - [2-Difference-Array](1-Basic-Algorithms/8-Preprocessing/Preprocessing.md/#2-差分) # 差分
- [9-Discretization/](1-Basic-Algorithms/9-Discretization/Discretization.md) # 离散化

### 第二章 基础数据结构

[2-Basic-Data-Structures/](2-Basic-Data-Structures/) # 基础数据结构
- [1-Linear-Structures/](2-Basic-Data-Structures/1-Linear-Structures/Linear-Structures.md) # 线性结构
  - [1-vector](2-Basic-Data-Structures/1-Linear-Structures/Linear-Structures.md/#1-动态数组-vector) # 动态数组
  - [2-stack](2-Basic-Data-Structures/1-Linear-Structures/Linear-Structures.md/#2-栈-stack) # 栈
  - [3-queue](2-Basic-Data-Structures/1-Linear-Structures/Linear-Structures.md/#3-队列-queue) # 队列
  - [4-deque](2-Basic-Data-Structures/1-Linear-Structures/Linear-Structures.md/#4-双端队列-deque) # 双端队列
  - [5-list](2-Basic-Data-Structures/1-Linear-Structures/Linear-Structures.md/#5-链表-list) # 链表
- [2-Associative-Containers/](2-Basic-Data-Structures/2-Associative-Containers/Associative-Containers.md) # 关联式容器
  - [1-set](2-Basic-Data-Structures/2-Associative-Containers/Associative-Containers.md/#1-集合-set) # 集合
  - [2-map](2-Basic-Data-Structures/2-Associative-Containers/Associative-Containers.md/#2-映射表-map) # 映射表
- [3-Util/](2-Basic-Data-Structures/3-Util/Util.md) # 应用
  - [1-Mono-Stack](2-Basic-Data-Structures/3-Util/Util.md/#单调栈) # 单调栈
  - [2-Mono-Queue](2-Basic-Data-Structures/3-Util/Util.md/#单调队列) # 单调队列

### 第三章 搜索

[3-Searching/](3-Searching/) # 搜索
- [1-DFS/](3-Searching/1-DFS/DFS.md) # 深度优先搜索
- [2-BFS/](3-Searching/2-BFS/BFS.md) # 广度优先搜索
- [3-Memoization/](3-Searching/3-Memoization/Memoization.md) # 记忆化搜索

```
3-Searching/            # 搜索
├── 1-DFS/              # 深度优先搜索
├── 2-BFS/              # 广度优先搜索
├── 3-​​Memoization​​/      # 记忆化搜索
├── 4-Pruning​​/          # 剪枝
├── 5-IDDFS/            # 迭代加深搜索
├── 6-Bidirectional/    # 双向搜索
│   ├── 1-DFS/          # 双向DFS
│   └── 2-BFS/          # 双向BFS
├── 7-A*/               # 启发式搜索
└── 8-IDA*/             # 启发式迭代加深搜索
```

### 第四章 动态规划

```
4-DP/                       # 动态规划
├── 1-Knapsack/             # 背包动态规划
├── 2-Linear/               # 线性动态规划
├── 3-Interval/             # 区间动态规划
└── 4-State-Compression/    # 状态压缩动态规划
```

### 第五章 字符串

```
5-String/       # 字符串
├── 1-KMP/      # KMP
```

### 第六章 树论

```
6-Tree/                 # 树论
├── 1-DSU/              # 并查集
├── 2-Fenwick-Tree​​/     # 树状数组
```

### 第七章 图论

```
7-Graph/                # 图论
```

### 第八章 数学

```
8-Maths/	            # 数学
```

### 第九章 其他

```
9-Other/                # 其他
```
