# MkDocs Documentation Site Restructure Design

## Goal

Restructure this repository from a chapter-numbered algorithm template collection into a MkDocs documentation site inspired by OI Wiki.

The new structure should feel like a knowledge base first and a code template library second: pages explain concepts, implementation ideas, complexity, templates, and common notes in a consistent order. The initial migration should preserve existing content as much as possible and avoid rewriting every note during the structural change.

## Current Context

The repository currently stores Markdown notes and C++ templates under numbered top-level directories:

- `1-Basic-Algorithms/`
- `2-Basic-Data-Structures/`
- `3-Searching/`
- `4-DP/`
- `5-String/`
- `6-Tree/`
- `7-Graph/`
- `8-Maths/`

There is also a root `README.md` with a hand-written outline. The working tree already contains unrelated user changes, including edits to `README.md`, a renamed memoization directory, and a new tree DP note. The migration must preserve these changes and must not revert or overwrite them.

## Target Structure

Use the standard MkDocs shape:

```text
mkdocs.yml
docs/
  index.md
  basic/
  ds/
  search/
  dp/
  string/
  graph/
  math/
  misc/
```

Top-level document categories should follow OI Wiki-style knowledge domains rather than the current numbered chapter folders:

- `basic/`: algorithm basics such as sorting, enumeration, binary search, divide and conquer, greedy, prefix sum, and binary lifting.
- `ds/`: data structures such as sequence containers, associative containers, monotonic stack/queue, DSU, and Fenwick tree.
- `search/`: DFS, BFS, memoized search, pruning, and later advanced search techniques.
- `dp/`: knapsack, linear DP, interval DP, tree DP, and later state compression or DP optimization topics.
- `string/`: string algorithms. Initially this may only contain `index.md`.
- `graph/`: graph algorithms. Initially this may only contain `index.md`.
- `math/`: math topics such as prime sieve and binary exponentiation.
- `misc/`: topics that do not fit cleanly elsewhere. This can later hold discretization if the site grows closer to OI Wiki's taxonomy.

Every category should have an `index.md` page. Empty or not-yet-written categories can start with short starter pages that state the intended scope without pretending content exists.

## Initial Content Mapping

Map existing pages into the new knowledge-domain structure:

```text
README.md                                      -> docs/index.md
1-Basic-Algorithms/1-Sorting/Sorting.md        -> docs/basic/sort.md
1-Basic-Algorithms/2-Brute-Force/Brute-Force.md -> docs/basic/enumerate.md
1-Basic-Algorithms/3-Binary-Search/Binary-Search.md -> docs/basic/binary.md
1-Basic-Algorithms/4-Divide-and-Conquer/Divide-and-Conquer.md -> docs/basic/divide-and-conquer.md
1-Basic-Algorithms/5-Binary-Lifting/Binary-Lifting.md -> docs/basic/binary-lifting.md
1-Basic-Algorithms/6-Greedy/Greedy.md          -> docs/basic/greedy.md
1-Basic-Algorithms/7-High-Precision/High-Precision.md -> docs/math/bignum.md
1-Basic-Algorithms/8-Preprocessing/Preprocessing.md -> docs/basic/prefix-sum.md
1-Basic-Algorithms/9-Discretization/Discretization.md -> docs/misc/discrete.md

2-Basic-Data-Structures/1-Linear-Structures/Linear-Structures.md -> docs/ds/sequence-container.md
2-Basic-Data-Structures/2-Associative-Containers/Associative-Containers.md -> docs/ds/associative-container.md
2-Basic-Data-Structures/3-Util/Util.md         -> split or migrate to docs/ds/monotonic-stack.md and docs/ds/monotonic-queue.md

3-Searching/1-DFS/DFS.md                       -> docs/search/dfs.md
3-Searching/2-BFS/BFS.md                       -> docs/search/bfs.md
3-Searching/3-Memoization/Memoization.md       -> docs/search/memo.md
3-Searching/4-Pruning/Pruning.md               -> docs/search/pruning.md

4-DP/1-Knapsack/Knapsack.md                    -> docs/dp/knapsack.md
4-DP/2-Linear/Linear.md                        -> docs/dp/linear.md
4-DP/3-Interval/Interval.md                    -> docs/dp/interval.md
4-DP/4-Tree/Tree.md                            -> docs/dp/tree.md

6-Tree/1-DSU/DSU.md                            -> docs/ds/dsu.md
6-Tree/2-Fenwick-Tree/Fenwick-Tree.md          -> docs/ds/fenwick.md

8-Maths/1-Prime-Sieve/Prime-Sieve.md           -> docs/math/sieve.md
8-Maths/2-Fast-Pow/Fast-Pow.md                 -> docs/math/binary-exponentiation.md
```

The first implementation can copy or move content without heavily normalizing page prose. Page style can be standardized gradually after the site builds successfully.

## Code Template Strategy

C++ templates should stay close to the pages that explain them. For the initial migration, move code into category-local `code/` directories:

```text
docs/basic/code/
docs/ds/code/
docs/search/code/
docs/dp/code/
docs/math/code/
```

Examples:

- Sorting implementation files move to `docs/basic/code/`.
- Knapsack implementation files move to `docs/dp/code/knapsack/`.
- DSU and Fenwick tree implementation files move to `docs/ds/code/`.

Markdown pages should link to nearby code files when useful. Inline code blocks already present in Markdown can remain in place.

## MkDocs Configuration

Create a root `mkdocs.yml` with a minimal Material for MkDocs configuration:

- `site_name: My Algorithm Templates`
- `site_description` in Chinese, describing the project as an algorithm note and template site.
- `theme.name: material`
- `theme.language: zh`
- navigation tabs enabled if supported.
- search enabled through MkDocs defaults or Material defaults.
- Markdown extensions for competitive-programming notes:
  - `admonition`
  - `def_list`
  - `footnotes`
  - `toc` with permalink
  - `pymdownx.arithmatex` for math
  - `pymdownx.highlight`
  - `pymdownx.inlinehilite`
  - `pymdownx.superfences`
  - `pymdownx.tabbed`
  - `pymdownx.tasklist`

The first version should not copy OI Wiki's custom hooks, theme submodule, feedback system, analytics, or server-side MathJax pipeline. Those are powerful but too heavy for this repository's current scale.

## Navigation Design

The first `nav` should be explicit and small:

```yaml
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

## Page Style Direction

Over time, pages should move toward a consistent structure:

1. 简介
2. 核心思想
3. 复杂度
4. 实现 / 模板
5. 注意事项
6. 例题 or 练习链接, when available

The migration itself should not block on rewriting every page into this structure. Structural correctness and buildability come first.

## README Role

After migration, root `README.md` should become a project entry page for GitHub readers:

- briefly introduce the site;
- show how to install dependencies;
- show how to run `mkdocs serve`;
- link users to the generated documentation site if one exists later.

Detailed content navigation should live in `mkdocs.yml` and `docs/index.md`, not in a large hand-maintained README outline.

## Verification

Implementation should verify:

- `mkdocs.yml` exists and references only existing files.
- all Markdown files in `docs/` are reachable from nav unless intentionally left unlisted.
- all moved code links resolve.
- `mkdocs build` succeeds if dependencies are installed.
- if dependencies are missing, document the exact install command instead of silently skipping verification.

## Out of Scope

The initial migration should not:

- rewrite all notes for content quality;
- import OI Wiki's custom theme submodule or hooks;
- add deployment automation unless requested later;
- add analytics, comments, feedback systems, or service-worker assets;
- delete user changes that already exist in the working tree.

## Open Implementation Notes

- The repository already has a working-tree rename from a hidden-character memoization directory to `3-Searching/3-Memoization/`. Use the clean visible path during migration.
- `4-DP/4-Tree/Tree.md` is untracked but should be treated as intended content and migrated to `docs/dp/tree.md`.
- Use one logical commit for the design document, then one later logical commit for the actual MkDocs restructure after the implementation is complete and verified.
