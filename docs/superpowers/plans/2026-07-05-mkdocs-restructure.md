# MkDocs Restructure Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Convert the repository into an OI Wiki-inspired MkDocs documentation site while preserving the existing algorithm notes and C++ templates.

**Architecture:** The project will use standard MkDocs layout with `mkdocs.yml` at the repository root and all site content under `docs/`. Existing numbered chapter folders will be migrated into semantic knowledge-domain folders such as `docs/basic/`, `docs/ds/`, `docs/search/`, `docs/dp/`, `docs/math/`, and `docs/misc/`. C++ templates will live near related pages in category-local `code/` directories, and validation will ensure MkDocs nav and file links stay consistent.

**Tech Stack:** MkDocs, Material for MkDocs, Markdown, pymdown-extensions, C++ template files, PowerShell for local file operations and verification commands.

---

## File Structure

Create or modify these files:

- Create: `mkdocs.yml` — MkDocs site configuration, theme options, Markdown extensions, and explicit navigation.
- Create: `requirements.txt` — pinned or minimally constrained Python documentation dependencies.
- Create: `docs/index.md` — documentation home page adapted from the current root `README.md`.
- Create: `docs/basic/index.md` — algorithm basics category landing page.
- Create: `docs/basic/sort.md` — migrated sorting note.
- Create: `docs/basic/enumerate.md` — migrated brute-force and enumeration note.
- Create: `docs/basic/binary.md` — migrated binary search note.
- Create: `docs/basic/divide-and-conquer.md` — migrated divide and conquer note.
- Create: `docs/basic/binary-lifting.md` — migrated binary lifting note.
- Create: `docs/basic/greedy.md` — migrated greedy note.
- Create: `docs/basic/prefix-sum.md` — migrated prefix sum and difference note.
- Create: `docs/basic/code/*.cpp` and `docs/basic/code/sort/*.cpp` — migrated C++ templates for basic algorithms.
- Create: `docs/ds/index.md` — data structures category landing page.
- Create: `docs/ds/sequence-container.md` — migrated linear container note.
- Create: `docs/ds/associative-container.md` — migrated associative container note.
- Create: `docs/ds/monotonic-stack.md` — split from `2-Basic-Data-Structures/3-Util/Util.md`.
- Create: `docs/ds/monotonic-queue.md` — split from `2-Basic-Data-Structures/3-Util/Util.md`.
- Create: `docs/ds/dsu.md` — migrated DSU note.
- Create: `docs/ds/fenwick.md` — migrated Fenwick tree note.
- Create: `docs/ds/code/*.cpp` — migrated C++ templates for data structures.
- Create: `docs/search/index.md` — search category landing page.
- Create: `docs/search/dfs.md` — migrated DFS note.
- Create: `docs/search/bfs.md` — migrated BFS note.
- Create: `docs/search/memo.md` — migrated memoized search note from the clean visible directory.
- Create: `docs/search/pruning.md` — migrated pruning note.
- Create: `docs/dp/index.md` — dynamic programming category landing page.
- Create: `docs/dp/knapsack.md` — migrated knapsack DP note.
- Create: `docs/dp/linear.md` — migrated linear DP note.
- Create: `docs/dp/interval.md` — migrated interval DP note.
- Create: `docs/dp/tree.md` — migrated tree DP note from the current untracked file.
- Create: `docs/dp/code/knapsack/*.cpp` — migrated knapsack template files.
- Create: `docs/string/index.md` — string category starter page.
- Create: `docs/graph/index.md` — graph category starter page.
- Create: `docs/math/index.md` — math category landing page.
- Create: `docs/math/bignum.md` — migrated high precision note.
- Create: `docs/math/sieve.md` — migrated prime sieve note.
- Create: `docs/math/binary-exponentiation.md` — migrated fast power note.
- Create: `docs/math/code/*.cpp` — migrated math template files.
- Create: `docs/misc/index.md` — miscellaneous category landing page.
- Create: `docs/misc/discrete.md` — migrated discretization note.
- Create: `docs/misc/code/*.cpp` — migrated miscellaneous template files.
- Modify: `README.md` — replace the hand-maintained outline with repository usage instructions for the MkDocs site.
- Delete after verification: old numbered content directories once all mapped Markdown and C++ files exist under `docs/`.

Do not modify:

- `docs/superpowers/specs/2026-07-04-mkdocs-restructure-design.md`
- `docs/superpowers/plans/2026-07-05-mkdocs-restructure.md` except for checklist progress while executing this plan.

## Commit Strategy

The user requested meaningful commits rather than tiny commits. Use one final restructure commit after the site builds and the migration is verified:

```bash
git add mkdocs.yml requirements.txt README.md docs 1-Basic-Algorithms 2-Basic-Data-Structures 3-Searching 4-DP 5-String 6-Tree 7-Graph 8-Maths
git commit -m "docs: migrate project to mkdocs site"
```

If implementation reveals an unrelated blocking cleanup, stop and ask before making a separate commit.

---

### Task 1: Capture Baseline and Prepare Verification Commands

**Files:**
- Read: `docs/superpowers/specs/2026-07-04-mkdocs-restructure-design.md`
- Read: `README.md`
- Read: all current Markdown and C++ source paths listed by `rg --files`

- [ ] **Step 1: Capture current git state**

Run:

```powershell
git status --porcelain=v1 -uall
```

Expected: output includes the existing working-tree changes:

```text
 D "3-Searching/3-\342\200\213\342\200\213Memoization/\342\200\213\342\200\213Memoization.md"
 M README.md
?? 3-Searching/3-Memoization/Memoization.md
?? 4-DP/4-Tree/Tree.md
?? docs/superpowers/plans/2026-07-05-mkdocs-restructure.md
```

- [ ] **Step 2: Capture source file inventory**

Run:

```powershell
rg --files
```

Expected: output includes all existing Markdown and C++ files, including:

```text
README.md
3-Searching\3-Memoization\Memoization.md
4-DP\4-Tree\Tree.md
docs\superpowers\specs\2026-07-04-mkdocs-restructure-design.md
docs\superpowers\plans\2026-07-05-mkdocs-restructure.md
```

- [ ] **Step 3: Confirm no existing MkDocs config will be overwritten**

Run:

```powershell
Get-ChildItem -Force -Filter 'mkdocs.yml'
Get-ChildItem -Force -Filter 'requirements.txt'
```

Expected: no `mkdocs.yml` exists. If `requirements.txt` exists, read it and merge documentation dependencies instead of overwriting it.

---

### Task 2: Create MkDocs Skeleton

**Files:**
- Create: `mkdocs.yml`
- Create: `requirements.txt`
- Create: category directories under `docs/`

- [ ] **Step 1: Create category directories**

Run:

```powershell
New-Item -ItemType Directory -Force -Path `
  'docs\basic\code\sort', `
  'docs\ds\code', `
  'docs\search', `
  'docs\dp\code\knapsack', `
  'docs\string', `
  'docs\graph', `
  'docs\math\code', `
  'docs\misc\code'
```

Expected: PowerShell creates the directories or reports that they already exist.

- [ ] **Step 2: Create `requirements.txt`**

Add this exact content:

```text
mkdocs-material>=9.5,<10
pymdown-extensions>=10.0,<11
```

- [ ] **Step 3: Create `mkdocs.yml`**

Add this exact content:

```yaml
site_name: My Algorithm Templates
site_description: 信竞算法笔记与代码模板文档站
site_author: EndeavourCHN

exclude_docs: |
  superpowers/**

theme:
  name: material
  language: zh
  features:
    - navigation.tabs
    - navigation.sections
    - navigation.top
    - search.highlight
    - search.suggest
    - content.code.copy

markdown_extensions:
  - admonition
  - def_list
  - footnotes
  - toc:
      permalink: true
  - pymdownx.arithmatex:
      generic: true
  - pymdownx.highlight:
      anchor_linenums: true
  - pymdownx.inlinehilite
  - pymdownx.superfences
  - pymdownx.tabbed:
      alternate_style: true
  - pymdownx.tasklist:
      custom_checkbox: true

extra_javascript:
  - https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js

nav:
  - 首页: index.md
  - 算法基础:
      - 简介: basic/index.md
      - 排序: basic/sort.md
      - 枚举: basic/enumerate.md
      - 二分: basic/binary.md
      - 递归与分治: basic/divide-and-conquer.md
      - 倍增: basic/binary-lifting.md
      - 贪心: basic/greedy.md
      - 前缀和与差分: basic/prefix-sum.md
  - 数据结构:
      - 简介: ds/index.md
      - 序列式容器: ds/sequence-container.md
      - 关联式容器: ds/associative-container.md
      - 单调栈: ds/monotonic-stack.md
      - 单调队列: ds/monotonic-queue.md
      - 并查集: ds/dsu.md
      - 树状数组: ds/fenwick.md
  - 搜索:
      - 简介: search/index.md
      - DFS: search/dfs.md
      - BFS: search/bfs.md
      - 记忆化搜索: search/memo.md
      - 剪枝: search/pruning.md
  - 动态规划:
      - 简介: dp/index.md
      - 背包 DP: dp/knapsack.md
      - 线性 DP: dp/linear.md
      - 区间 DP: dp/interval.md
      - 树形 DP: dp/tree.md
  - 字符串:
      - 简介: string/index.md
  - 图论:
      - 简介: graph/index.md
  - 数学:
      - 简介: math/index.md
      - 高精度: math/bignum.md
      - 筛法: math/sieve.md
      - 快速幂: math/binary-exponentiation.md
  - 杂项:
      - 简介: misc/index.md
      - 离散化: misc/discrete.md
```

---

### Task 3: Create Category Landing Pages and Home Page

**Files:**
- Create: `docs/index.md`
- Create: `docs/basic/index.md`
- Create: `docs/ds/index.md`
- Create: `docs/search/index.md`
- Create: `docs/dp/index.md`
- Create: `docs/string/index.md`
- Create: `docs/graph/index.md`
- Create: `docs/math/index.md`
- Create: `docs/misc/index.md`

- [ ] **Step 1: Create `docs/index.md`**

Use this exact content:

```markdown
# My Algorithm Templates

我的信竞算法笔记与代码模板文档站。

这里记录常见算法、数据结构、动态规划、搜索、数学等内容。笔记会随着学习与练习逐步补充和修正；如果发现错漏，欢迎通过 Issue 指正。

## 内容导航

- [算法基础](basic/index.md)
- [数据结构](ds/index.md)
- [搜索](search/index.md)
- [动态规划](dp/index.md)
- [字符串](string/index.md)
- [图论](graph/index.md)
- [数学](math/index.md)
- [杂项](misc/index.md)

## OJ 账号

- Codeforces: <https://codeforces.com/profile/EndeavourCHN>
- LeetCode: <https://leetcode.cn/u/endeavourchn/>
- 洛谷: <https://www.luogu.com.cn/user/606580>
```

- [ ] **Step 2: Create category index pages**

Use these exact contents:

```markdown
# 算法基础

本节整理排序、枚举、二分、分治、倍增、贪心、前缀和与差分等基础算法内容。
```

```markdown
# 数据结构

本节整理常用 STL 容器、单调栈、单调队列、并查集、树状数组等数据结构内容。
```

```markdown
# 搜索

本节整理 DFS、BFS、记忆化搜索、剪枝等搜索相关内容。
```

```markdown
# 动态规划

本节整理背包 DP、线性 DP、区间 DP、树形 DP 等动态规划内容。
```

```markdown
# 字符串

本节预留字符串算法内容，后续可补充 KMP、哈希、Trie、AC 自动机等主题。
```

```markdown
# 图论

本节预留图论内容，后续可补充最短路、最小生成树、拓扑排序、连通性等主题。
```

```markdown
# 数学

本节整理筛法、快速幂、高精度等数学相关内容。
```

```markdown
# 杂项

本节整理不容易归入其他章节的内容，例如离散化等技巧。
```

Place them respectively in:

```text
docs/basic/index.md
docs/ds/index.md
docs/search/index.md
docs/dp/index.md
docs/string/index.md
docs/graph/index.md
docs/math/index.md
docs/misc/index.md
```

---

### Task 4: Migrate Markdown Notes

**Files:**
- Create: all mapped `docs/**/*.md` topic pages
- Source: existing Markdown notes listed in the approved design spec

- [ ] **Step 1: Copy simple one-to-one Markdown pages**

Run copy operations equivalent to:

```powershell
Copy-Item '1-Basic-Algorithms\1-Sorting\Sorting.md' 'docs\basic\sort.md'
Copy-Item '1-Basic-Algorithms\2-Brute-Force\Brute-Force.md' 'docs\basic\enumerate.md'
Copy-Item '1-Basic-Algorithms\3-Binary-Search\Binary-Search.md' 'docs\basic\binary.md'
Copy-Item '1-Basic-Algorithms\4-Divide-and-Conquer\Divide-and-Conquer.md' 'docs\basic\divide-and-conquer.md'
Copy-Item '1-Basic-Algorithms\5-Binary-Lifting\Binary-Lifting.md' 'docs\basic\binary-lifting.md'
Copy-Item '1-Basic-Algorithms\6-Greedy\Greedy.md' 'docs\basic\greedy.md'
Copy-Item '1-Basic-Algorithms\7-High-Precision\High-Precision.md' 'docs\math\bignum.md'
Copy-Item '1-Basic-Algorithms\8-Preprocessing\Preprocessing.md' 'docs\basic\prefix-sum.md'
Copy-Item '1-Basic-Algorithms\9-Discretization\Discretization.md' 'docs\misc\discrete.md'
Copy-Item '2-Basic-Data-Structures\1-Linear-Structures\Linear-Structures.md' 'docs\ds\sequence-container.md'
Copy-Item '2-Basic-Data-Structures\2-Associative-Containers\Associative-Containers.md' 'docs\ds\associative-container.md'
Copy-Item '3-Searching\1-DFS\DFS.md' 'docs\search\dfs.md'
Copy-Item '3-Searching\2-BFS\BFS.md' 'docs\search\bfs.md'
Copy-Item '3-Searching\3-Memoization\Memoization.md' 'docs\search\memo.md'
Copy-Item '3-Searching\4-Pruning\Pruning.md' 'docs\search\pruning.md'
Copy-Item '4-DP\1-Knapsack\Knapsack.md' 'docs\dp\knapsack.md'
Copy-Item '4-DP\2-Linear\Linear.md' 'docs\dp\linear.md'
Copy-Item '4-DP\3-Interval\Interval.md' 'docs\dp\interval.md'
Copy-Item '4-DP\4-Tree\Tree.md' 'docs\dp\tree.md'
Copy-Item '6-Tree\1-DSU\DSU.md' 'docs\ds\dsu.md'
Copy-Item '6-Tree\2-Fenwick-Tree\Fenwick-Tree.md' 'docs\ds\fenwick.md'
Copy-Item '8-Maths\1-Prime-Sieve\Prime-Sieve.md' 'docs\math\sieve.md'
Copy-Item '8-Maths\2-Fast-Pow\Fast-Pow.md' 'docs\math\binary-exponentiation.md'
```

Expected: all target Markdown files exist under `docs/`.

- [ ] **Step 2: Split `Util.md` into monotonic stack and monotonic queue pages**

Read:

```powershell
Get-Content '2-Basic-Data-Structures\3-Util\Util.md' -Encoding UTF8
```

Create `docs/ds/monotonic-stack.md` with the section for 单调栈 and `docs/ds/monotonic-queue.md` with the section for 单调队列. If the source file has only brief content, preserve the original wording and title each page:

```markdown
# 单调栈
```

and

```markdown
# 单调队列
```

Expected: each page contains only the relevant section and builds as a standalone MkDocs page.

---

### Task 5: Migrate C++ Templates

**Files:**
- Create: `docs/basic/code/**/*.cpp`
- Create: `docs/ds/code/*.cpp`
- Create: `docs/dp/code/knapsack/*.cpp`
- Create: `docs/math/code/*.cpp`
- Create: `docs/misc/code/*.cpp`

- [ ] **Step 1: Copy basic algorithm templates**

Run:

```powershell
Copy-Item '1-Basic-Algorithms\1-Sorting\code\*.cpp' 'docs\basic\code\sort\'
Copy-Item '1-Basic-Algorithms\2-Brute-Force\*.cpp' 'docs\basic\code\'
Copy-Item '1-Basic-Algorithms\3-Binary-Search\Binary-Search.cpp' 'docs\basic\code\binary-search.cpp'
Copy-Item '1-Basic-Algorithms\4-Divide-and-Conquer\Hanoi.cpp' 'docs\basic\code\hanoi.cpp'
Copy-Item '1-Basic-Algorithms\5-Binary-Lifting\Sparse-Table.cpp' 'docs\basic\code\sparse-table.cpp'
Copy-Item '1-Basic-Algorithms\6-Greedy\Jump-Game.cpp' 'docs\basic\code\jump-game.cpp'
Copy-Item '1-Basic-Algorithms\8-Preprocessing\*.cpp' 'docs\basic\code\'
```

- [ ] **Step 2: Copy data structure templates**

Run:

```powershell
Copy-Item '2-Basic-Data-Structures\1-Linear-Structures\*.cpp' 'docs\ds\code\'
Copy-Item '2-Basic-Data-Structures\2-Associative-Containers\*.cpp' 'docs\ds\code\'
Copy-Item '2-Basic-Data-Structures\3-Util\*.cpp' 'docs\ds\code\'
Copy-Item '6-Tree\1-DSU\DSU.cpp' 'docs\ds\code\dsu.cpp'
Copy-Item '6-Tree\2-Fenwick-Tree\Fenwick-Tree.cpp' 'docs\ds\code\fenwick-tree.cpp'
```

- [ ] **Step 3: Copy DP, math, and misc templates**

Run:

```powershell
Copy-Item '4-DP\1-Knapsack\code\*.cpp' 'docs\dp\code\knapsack\'
Copy-Item '1-Basic-Algorithms\7-High-Precision\*.cpp' 'docs\math\code\'
Copy-Item '8-Maths\1-Prime-Sieve\*.cpp' 'docs\math\code\'
Copy-Item '8-Maths\2-Fast-Pow\Fast-Pow.cpp' 'docs\math\code\fast-pow.cpp'
Copy-Item '1-Basic-Algorithms\9-Discretization\Discretization.cpp' 'docs\misc\code\discretization.cpp'
```

Expected: no source `.cpp` file is lost; each existing `.cpp` has a corresponding target under `docs/**/code/`.

---

### Task 6: Update README for Repository Usage

**Files:**
- Modify: `README.md`

- [ ] **Step 1: Replace README content with project entry instructions**

Use this exact content:

```markdown
# My Algorithm Templates

我的信竞算法笔记与代码模板文档站。

文档内容使用 [MkDocs](https://www.mkdocs.org/) 和 [Material for MkDocs](https://squidfunk.github.io/mkdocs-material/) 构建，正文位于 `docs/` 目录。

## 本地预览

安装依赖：

```bash
pip install -r requirements.txt
```

启动本地服务：

```bash
mkdocs serve
```

构建静态站点：

```bash
mkdocs build
```

## 内容说明

笔记内容按照算法知识域组织，整体参考 OI Wiki 的文档站结构，但保留个人学习笔记和代码模板的写法。

目前很多内容尚不完善，计划先构建大致框架，再逐步润色。

## OJ 账号

- Codeforces: <https://codeforces.com/profile/EndeavourCHN>
- LeetCode: <https://leetcode.cn/u/endeavourchn/>
- 洛谷: <https://www.luogu.com.cn/user/606580>
```

Expected: README no longer contains a large manually maintained table of contents.

---

### Task 7: Remove Old Numbered Content Folders After Copy Verification

**Files:**
- Delete: old numbered content directories after targets exist
- Preserve: `.git/`, `docs/`, `README.md`, `mkdocs.yml`, `requirements.txt`

- [ ] **Step 1: Verify target files exist before deletion**

Run:

```powershell
Test-Path 'docs\basic\sort.md'
Test-Path 'docs\ds\dsu.md'
Test-Path 'docs\search\memo.md'
Test-Path 'docs\dp\tree.md'
Test-Path 'docs\math\binary-exponentiation.md'
Test-Path 'docs\misc\discrete.md'
Test-Path 'docs\basic\code\sort\1-counting-sort.cpp'
Test-Path 'docs\dp\code\knapsack\1-01.cpp'
```

Expected: every command prints `True`.

- [ ] **Step 2: Delete old numbered directories**

Use native PowerShell deletion only after Step 1 succeeds:

```powershell
Remove-Item -LiteralPath `
  '1-Basic-Algorithms', `
  '2-Basic-Data-Structures', `
  '3-Searching', `
  '4-DP', `
  '5-String', `
  '6-Tree', `
  '7-Graph', `
  '8-Maths' `
  -Recurse
```

Expected: the old numbered directories no longer exist. This is safe only because the repository root is `D:\Code\My-Algorithm-Templates` and all target files have already been verified under `docs/`.

---

### Task 8: Verify MkDocs Navigation and Build

**Files:**
- Read: `mkdocs.yml`
- Read: `docs/**/*.md`
- Read: `docs/**/*.cpp`

- [ ] **Step 1: Confirm nav target files exist**

Run:

```powershell
@(
  'docs\index.md',
  'docs\basic\index.md',
  'docs\basic\sort.md',
  'docs\basic\enumerate.md',
  'docs\basic\binary.md',
  'docs\basic\divide-and-conquer.md',
  'docs\basic\binary-lifting.md',
  'docs\basic\greedy.md',
  'docs\basic\prefix-sum.md',
  'docs\ds\index.md',
  'docs\ds\sequence-container.md',
  'docs\ds\associative-container.md',
  'docs\ds\monotonic-stack.md',
  'docs\ds\monotonic-queue.md',
  'docs\ds\dsu.md',
  'docs\ds\fenwick.md',
  'docs\search\index.md',
  'docs\search\dfs.md',
  'docs\search\bfs.md',
  'docs\search\memo.md',
  'docs\search\pruning.md',
  'docs\dp\index.md',
  'docs\dp\knapsack.md',
  'docs\dp\linear.md',
  'docs\dp\interval.md',
  'docs\dp\tree.md',
  'docs\string\index.md',
  'docs\graph\index.md',
  'docs\math\index.md',
  'docs\math\bignum.md',
  'docs\math\sieve.md',
  'docs\math\binary-exponentiation.md',
  'docs\misc\index.md',
  'docs\misc\discrete.md'
) | ForEach-Object { if (-not (Test-Path $_)) { "MISSING $_" } }
```

Expected: no output.

- [ ] **Step 2: Check whether MkDocs is available**

Run:

```powershell
mkdocs --version
```

Expected: prints an MkDocs version. If PowerShell reports `mkdocs` is not recognized, run:

```powershell
pip install -r requirements.txt
```

If dependency installation fails because network access is blocked, request approval to rerun the install command with escalated network access.

- [ ] **Step 3: Build the site**

Run:

```powershell
mkdocs build --strict
```

Expected: command exits successfully. The `exclude_docs` setting keeps `docs/superpowers/**` out of the MkDocs site so planning artifacts do not need nav entries.

---

### Task 9: Inspect Final Diff and Commit

**Files:**
- Modify: all files touched during migration

- [ ] **Step 1: Inspect changed files**

Run:

```powershell
git status --short
git diff --stat
```

Expected: output shows the MkDocs migration plus the previously existing README/memoization/tree DP changes now incorporated into the restructure.

- [ ] **Step 2: Inspect config and README diff**

Run:

```powershell
git diff -- mkdocs.yml requirements.txt README.md
```

Expected: `mkdocs.yml` contains the nav from Task 2, `requirements.txt` contains documentation dependencies, and `README.md` contains MkDocs usage instructions.

- [ ] **Step 3: Commit the completed migration**

Run:

```powershell
git add mkdocs.yml requirements.txt README.md docs 1-Basic-Algorithms 2-Basic-Data-Structures 3-Searching 4-DP 5-String 6-Tree 7-Graph 8-Maths
git commit -m "docs: migrate project to mkdocs site"
```

Expected: one logical commit is created for the verified restructure.
