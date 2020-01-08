---
title: Leetcode Hard难度 题解
date: 2019-04-26 21:04:46
tags:
categories:
- Leetcode
mathjax: true
---
只写简单和中等题就是在摸鱼罢。
<!-- more -->

# 4
真是一个不错的题。
考虑二分。可以发现，如果两个序列归并，那么第一个中位数之前会有 $tot=\frac{n+m-1}{2}$ 个数。考虑把这些数的来源，设第一个序列的前 $p$ 个数，和第二个序列的前 $tot-p$ 个数构成了这些数。对 $p$ 二分，设当前值为 $mid$ ，判定方法是如果第一个序列下标为 $mid$ 的数（即，假定的“中位数”）小于第二个序列下标为 $tot-mid-1$ 的数（即，假定的前 $tot$ 个数的最大者），则说明 $p$ 太小。
边界情况很多，包括二分的上下限和答案的位置，需要多次特判。

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(!n && !m) return 0.0;
        int pos = (n + m - 1) >> 1;
        int l = max(0, pos - m), r = min(pos, n); // 取好答案的上下界
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums1[mid] < nums2[pos - mid - 1])
                l = mid + 1;
            else r = mid;
        }
        if((n + m) & 1) {
            if(l >= n) return nums2[pos - l];
            if(pos - l >= m) return nums1[l];
            if(nums1[l] < nums2[pos - l]) return nums1[l];
            return nums2[pos - l];
        }else{
            if(l >= n) return 0.5 * (nums2[pos - l] + nums2[pos - l + 1]);
            if(pos - l >= m) return 0.5 * (nums1[l] + nums1[l + 1]);
            if(pos - l + 1 < m && nums1[l] > nums2[pos - l + 1])
                return 0.5 * (nums2[pos - l] + nums2[pos - l + 1]);
            else if(l + 1 < n && nums2[pos - l] > nums1[l + 1])
                return 0.5 * (nums1[l] + nums1[l + 1]);
            else return 0.5 * (nums1[l] + nums2[pos - l]);
        }
    }
};
```

# 10
有点神奇的 DP。
首先这个题在某种意义上有点复杂，如果能够把诸如 `x*` 的字符匹配形式换成单个字符的话，代码会简便一些。下面为了方便起见，认为形式 `x*` 是一个字符。
考虑 s 串的前 $i$ 个字符去和 $p$ 的前 $j$ 个字符匹配，成功与否由 $f[i][j]$ 指示。现在匹配到了 $s[i]$ 和 $p[j]$：

1. 如果 $p[j]$ 是字母，那么答案仅仅是 $f[i-1][j-1]$ 和 $s[i]=p[j]$ 的逻辑与。
2. 如果 $p[j]$ 是 `.`，那么答案仅仅是 $f[i-1][j-1]$。
3. 如果 $p[j]$ 具有 `x*` 形式，那么答案可能来自 $f[i][j-1]$（表明该星号没有匹配到任何一个字符）：
   1. 如果 $p[j]$ 是 `.*`，那么答案还可以来自 $f[i-1][j-1]$ 和 $f[i-1][j]$。前者表明开始匹配，后者表明沿着之前利用星号匹配的部分继续匹配。
   2. 否则，根据 $x=s[i]$ 与否判断：
      1. 是，那么答案还可以来自 $f[i-1][j-1]$，表明开始匹配；如果 $s[i-1]$ 和 $s[i]$ 相同，那么答案还可以来自 $f[i-1][j]$，表明沿着之前利用星号匹配的部分继续匹配。
      2. 否，那么不能匹配任何字符。

一开始有一个初始化：$f[0][0]=\text{true}$。但是注意，星号可以匹配空串，所以一开始还要检查如果 $p$ 以星号开头，那么匹配空串是成功的。
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
		int n = s.length(), rm = p.length(), m = rm;
		for (char c: p) if (c == '*') --m;
        vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
		f[0][0] = true;
		for (int j = 2; j <= rm; j += 2){
			if (p[j - 1] != '*') break;
			f[0][j >> 1] = true;
		}
		for (int i = 1; i <= n; ++i){
			for (int j = 1, j_ = 1; j <= rm; ++j){
				if (j < rm && p[j] == '*') continue;
				if (isalpha(p[j - 1])){
					f[i][j_] = (f[i - 1][j_ - 1] && s[i - 1] == p[j - 1]);
				}else if (p[j - 1] == '.'){
					f[i][j_] = f[i - 1][j_ - 1];
				}else{
					if (p[j - 2] != '.' && p[j - 2] == s[i - 1]){
						f[i][j_] = f[i][j_ - 1] || f[i - 1][j_ - 1];
						if (i >= 2 && s[i - 1] == s[i - 2])
							f[i][j_] = f[i][j_] || f[i - 1][j_];
					}else if (p[j - 2] == '.') {
						f[i][j_] = f[i][j_ - 1] || f[i - 1][j_ - 1] || f[i - 1][j_];
					}else{
						f[i][j_] = f[i][j_ - 1];
					}
				}
				++j_;
			}
		}
		return f[n][m];
    }
};
```

# 23
经典问题。用一个堆可以解决。具体操作是：先把所有链表的第一个节点放进小根堆里（按照值比较），然后每一次从堆中弹出具有当前最小值的节点，向堆中放入它链向的下一个节点，再从它所属的链表中将其删去。
设总共有 $N$ 个节点，那么堆的大小不超过 $K$ ，总时间复杂度是 $O(N\log K)$ 。
```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct P{
            int val, id;
            P(int v, int i): val(v), id(i) {}
        };
        struct cmp{
            bool operator ()(const P &p1, const P &p2){
                return p1.val > p2.val;
            }
        };
        priority_queue<P, vector<P>, cmp> pq;
        ListNode *head = new ListNode(0), *res = head;
        int n = lists.size();
        for (int i = 0; i < n; ++i)
            if(lists[i] != NULL)
                pq.push(P(lists[i]->val, i));
        while(!pq.empty()){
            P t = pq.top();
            pq.pop();
            head->next = lists[t.id], head = head->next;
            lists[t.id] = lists[t.id]->next;
            if(lists[t.id] != NULL)
                pq.push(P(lists[t.id]->val, t.id)); 
        }
        return res->next;
    }
};
```
还有一个做法就是将这些链表先两两合并，然后再两两合并，循环往复，经过 $\log_2 k$ 轮后只剩下一个链表，这就是答案。因为整个合并的过程可以看作是一棵由链表作为节点的满二叉树从底向上的构建过程，而向上一层的时间复杂度是 $O(N)$ ，总共有 $\log_2 k$ 层，所以总时间复杂度和上面是一样的。

# 25
画个图就行了。注意链表不要链来链去链出环来，那就很麻烦了。
```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *hhd = new ListNode(-1), *res = hhd;
        hhd->next = head;
        while(hhd->next != NULL){
            int cnt = 0;
            ListNode *tt;
            for (tt = hhd; tt->next != NULL && cnt < k; tt = tt->next)
                ++cnt;
            if(cnt < k) break;
            ListNode *bef = hhd, *cur = hhd->next, *tmp, *tmp2 = tt->next;
            for (int i = 0; i < k; ++i){
                tmp = cur->next;
                cur->next = bef;
                bef = cur, cur = tmp;
            }
            hhd->next->next = tmp2;
            tmp2 = hhd->next;
            hhd->next = tt;
            hhd = tmp2; 
        }
        return res->next;
    }
};
```

# 30

## 方法一
经典的暴力 DFS。不需要剪枝也可以过。
```cpp
class Solution {
public:
    vector<int> wpos, vis;
    vector<int> ans;
    void dfs(int pos, int cur, int left, string& s, vector<string>& words){
        int nn = words[cur].length(), id = wpos[cur];
        for (int i = 0; i < nn; ++i)
            if (s[pos + i] != words[id][i])
                return ;
        if (left == 1){
            ans.push_back(pos + nn);
            return ;
        }
        --vis[cur];
        for (int i = 0; i < wpos.size(); ++i)  {
            if (vis[i] == 0) continue;
            dfs(pos + nn, i, left - 1, s, words);
        }
        ++vis[cur];
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size();
        if (!m) return vector<int>();
        sort(words.begin(), words.end());
        for (int i = 0; i < m; ){
            int j = i;
            while (j < m && words[i] == words[j])
                ++j;
            wpos.push_back(i), vis.push_back(j - i);
            i = j;
        }

        int cnt = 0, real_size = wpos.size();
        for (string& ss: words)
            cnt += ss.length();
        if (cnt > s.length()) return vector<int>();
        for (int i = 0; i <= s.length() - cnt; ++i) 
            for (int j = 0; j < real_size; ++j)
                dfs(i, j, m, s, words);
        for (int &aans: ans) aans -= cnt;
        return ans;
    }
};
```
在这里如果加上记忆化什么的反而会导致效率的下降。

## 方法二
利用每一个单词的长度都相同的特性构建滑动窗口，这样可以避免大量的重复判定。
```cpp
class Solution {
public:
    vector<int> vis, ans;
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size();
        if (!m) return vector<int>();

        unordered_map<string, int> mp;
        sort(words.begin(), words.end());
        for (int i = 0, rz = 0; i < m; ){
            int j = i;
            while (j < m && words[i] == words[j])
                ++j;
            vis.push_back(j - i);
            mp[words[i]] = rz, rz++;
            i = j;
        }

        int unit_len = words[0].length(), s_len = s.length();
        int cnt = unit_len * m;
        if (cnt > s_len) return vector<int>();
        
        queue<int> que;
        for (int i = 0; i < unit_len && i + cnt <= s_len; ++i){
            int left = m;
            for (int j = 0; j < m; ++j){
                if (mp.count(s.substr(j * unit_len + i, unit_len))){
                    int id = mp[s.substr(j * unit_len + i, unit_len)];
                    --vis[id];
                    if (vis[id] >= 0) --left;
                    que.push(id);
                }else que.push(-1);
            }
            int rt = i + cnt;
            if (!left) ans.push_back(i);
            while (rt + unit_len <= s_len){
                int tp = que.front();
                que.pop();
                if (tp >= 0){
                    ++vis[tp];
                    if (vis[tp] >= 1) ++left; 
                }
                if (mp.count(s.substr(rt, unit_len))){
                    int id = mp[s.substr(rt, unit_len)];
                    --vis[id];
                    if (vis[id] >= 0) --left;
                    que.push(id);
                }else que.push(-1);
                rt += unit_len;
                if (!left) ans.push_back(rt - cnt);
            }
            while (!que.empty()) {
                if (que.front() >= 0) ++vis[que.front()];
                que.pop();
            }
        }
        return ans;
    }
};
```

不得不说，c++ 的切片真的很鸡肋。。。

## 方法三
构建 AC 自动机
（等待更新）

# 32


# 37

## 方法一
采用一些简单的剪枝手法。
用一个三元组 $(\text{type}, \text{id}, \text{digit})$ 来表示当前的填写状态，其中 type=0 表示行，type=1 表示列，type=2 表示 3 * 3 的方格。同时用一个列表 `lis` 记录当前尚未填写的位置。
每次 DFS 时，填写一个空之后就在列表中剩下没有填写的位置里找出自由度最低的空格，将其作为下一个搜索对象，直到所有空格都被填写为止。
经实践，这种方法的效率在面对一般的数独题目还是非常好的。
```cpp
class Solution {
public:
    bool vis[3][11][11]; // 0 行 1 列 2 宫 
    int lis[81][2], len_lis;
    void get(int at){
        int mini = 99, targ = -1;
        for(int i = at + 1; i < len_lis; ++i){
            int x = lis[i][0], y = lis[i][1], o = 0;
            for(int j = 1; j <= 9; ++j){
                if(vis[0][x][j] || vis[1][y][j] || vis[2][(x / 3) * 3 + y / 3][j])
                    continue;
                ++o;
            }
            if(o < mini) mini = o, targ = i;
        }
        swap(lis[targ][0], lis[at + 1][0]);
        swap(lis[targ][1], lis[at + 1][1]);
    }
    bool dfs(int at, vector<vector<char>>& board){
        int x = lis[at][0], y = lis[at][1];
        int block_id = (x / 3) * 3 + y / 3;
        for(int i = 1; i <= 9; ++i){
            if (vis[0][x][i] || vis[1][y][i] || vis[2][block_id][i])
                continue;
            vis[0][x][i] = vis[1][y][i] = vis[2][block_id][i] = true, 
            board[x][y] = i + '0';
            if(at < len_lis - 1){
                if (at != len_lis - 2) get(at);
                if (dfs(at + 1, board))
                    return true;
            }else return true;
            vis[0][x][i] = vis[1][y][i] = vis[2][block_id][i] = 0;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(vis, 0, sizeof(vis));
        memset(lis, 0, sizeof(lis));
        len_lis = 0;
        for (int i = 0; i < 9; ++i) 
            for (int j = 0; j < 9; ++j){
                if (board[i][j] == '.'){
                    lis[len_lis][0] = i, lis[len_lis++][1] = j;
                }else {
                    int id = board[i][j] - '0';
                    vis[0][i][id] = vis[1][j][id] = vis[2][(i / 3) * 3 + j / 3][id] = true;
                }
            }
        dfs(0, board);
    }
};
```

## 方法二
DLX 算法。
（等待更新）
```cpp

```


# 41
基本同448，物归原主方法。
```python
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == []:
            return 1
        len1 = len(nums)
        for i in range(0, len1):
            while True:
                if nums[i] > len1 or nums[i] <= 0 or nums[nums[i] - 1] == nums[i] or i == nums[i] - 1:
                    break
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        i = 0
        while i < len1:
            if nums[i] != i + 1:
                break
            i += 1
        return i + 1
```

# 42
一开始写了半天单调栈，发现单调栈好像根本搞不出来。。。
于是放弃，写了一个前缀和后缀最大值，两个间的较小值减掉该位置的高度就是该位置水应当有的高度。这个值可能为负，所以要和0取max。
说白了写不出就是基础不扎实。。。
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n, 0), r(n, 0);
        int ans = 0;
        for (int i = 1; i < n; ++i)
            l[i] = max(l[i - 1], height[i - 1]);
        for (int i = n - 2; i >= 0; --i)
            r[i] = max(r[i + 1], height[i + 1]), 
            ans += max(0, min(l[i], r[i]) - height[i]);
        return ans;
    }
};
```

# 44
第 10 题的弱化版。

## 方法一
直接把第 10 题大部分的代码照搬就行。
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
		int n = s.length(), m = p.length();
        vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
		f[0][0] = true;
		for (int j = 1; j <= m; ++j){
			if (p[j - 1] != '*') break;
			f[0][j] = true;
		}
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				if (isalpha(p[j - 1])){
					f[i][j] = (f[i - 1][j - 1] && s[i - 1] == p[j - 1]);
				}else if (p[j - 1] == '?'){
					f[i][j] = f[i - 1][j - 1];
				}else{
					f[i][j] = f[i][j - 1] || f[i - 1][j - 1] || f[i - 1][j];
				}
			}
		}
		return f[n][m];
    }
};
```

## 方法二


# 45
写了一个谜一样的树状数组。。。
```cpp
class Solution {
public:
    vector<int> bb;
    int lowbit(int x){
        return x & (-x);
    }
    void update(int k, int r, int n){
        while(k <= n)
            bb[k] = min(bb[k], r), k += lowbit(k);
    }
    int query(int k){
        int res = 0x3f3f3f3f;
        while(k)
            res = min(res, bb[k]), k -= lowbit(k);
        return res;
    }
    int jump(vector<int>& nums) {
        vector<pair<int, int> > nnums;
        vector<int> f;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            nnums.push_back(make_pair(-i - nums[i], i));
        sort(nnums.begin(), nnums.end());
        f = vector<int>(n, 0x3f3f3f3f);
        bb = vector<int>(n + 1, 0x3f3f3f3f);
        {
            f[0] = 0;
            int iid = lower_bound(nnums.begin(), nnums.end(), make_pair(-nums[0], 0)) - nnums.begin();
            update(iid + 1, 0, n);
        }
        for (int i = 1; i < n; ++i){
            int id = upper_bound(nnums.begin(), nnums.end(), make_pair(-i, n)) - nnums.begin();
            f[i] = query(id) + 1;
            int iid = lower_bound(nnums.begin(), nnums.end(), make_pair(-i - nums[i], i)) - nnums.begin();
            update(iid + 1, f[i], n);
        }
        return f[n - 1];
    }
};
```
但实际上这个题没有这么麻烦，


# 51
比下面这个难
```python
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        """
        :type n: int
        :rtype: int
        """
        ans = [0] * n
        aans = []
        def solve(n, cur_id, left, straight, right):
            nonlocal ans
            if cur_id == n + 1:
                lst = [("." * ans[i]) + "Q" + ("." * (n - ans[i] - 1)) for i in range(0, n)]
                aans.append(lst)
                return 
            cur = ((left & ((1 << n) - 1)) | straight | right)
            for i in range(0, n):
                j = 1 << i
                if cur & j:
                    continue
                else:
                    ans[cur_id - 1] = i
                    solve(n, cur_id + 1, (left | j) << 1, straight | j, (right | j) >> 1)
        solve(n, 1, 0, 0, 0)
        return ans
```

# 52
这算困难吗。。。算了还是写在这
```python
class Solution:
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        def solve(n, cur_id, left, straight, right):
            nonlocal ans
            if cur_id == n + 1:
                ans += 1
                return 
            cur = ((left & ((1 << n) - 1)) | straight | right)
            for i in range(0, n):
                j = 1 << i
                if cur & j:
                    continue
                else:
                    solve(n, cur_id + 1, (left | j) << 1, straight | j, (right | j) >> 1)
        solve(n, 1, 0, 0, 0)
        return ans
```

# 57
两次二分，第一次找所有区间中，第一个**右端点大于等于给定区间左端点**的区间；第二次找所有区间中，第一个**左端点大于给定区间右端点**的区间。后者的前一个区间就是最后一个**左端点小于等于给定区间右端点**的区间。
然后就可以合并了。合并过程比较容易，但不知道为什么空间花费很多。
需要注意的是，二分的结果中有些极端情况需要特判。
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int l1 = 0, r1 = n;
        while (r1 > l1){
            int mid = (l1 + r1) >> 1;
            if (intervals[mid][1] < newInterval[0]) l1 = mid + 1;
            else r1 = mid;
        }
        if (l1 == n){
            intervals.push_back(newInterval);
            return intervals;
        }
        int l2 = 0, r2 = n;
        while (r2 > l2){
            int mid = (l2 + r2) >> 1;
            if (intervals[mid][0] <= newInterval[1]) l2 = mid + 1;
            else r2 = mid;
        }
        --l2;
        if (l2 == -1){
            intervals.insert(intervals.begin(), newInterval);
        }else if (l2 == n - 1){
            int rr = max(newInterval[1], intervals[n - 1][1]);
            while (l1 < intervals.size() - 1) intervals.pop_back();
            intervals[l1][0] = min(newInterval[0], intervals[l1][0]);
            intervals[l1][1] = rr;
        }else { 
            int ll = min(newInterval[0], intervals[l1][0]);
            int rr = max(newInterval[1], intervals[l2][1]);
            if (l1 <= l2){
                intervals[l1][0] = ll, intervals[l1][1] = rr;
                intervals.erase(intervals.begin() + l1 + 1, intervals.begin() + l2 + 1);
            }else {
                intervals.insert(intervals.begin() + l1, vector<int>{ll, rr});
            }
        }
        return intervals;
    }
};
```

# 65
偷懒
```python
class Solution(object):
    def isNumber(self, s):
        try:
            a = complex(s)
        except ValueError:
            return False
        return True
```

# 68
大模拟，大力分类讨论
```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int cur = 0, n = words.size();
        vector<string> ans;
        while(cur < n){
            string curstr(maxWidth, ' ');
            int j = cur + 1, cnt = words[cur].size(); 
            while(j < n && cnt + words[j].size() + j - cur <= maxWidth)
                cnt += words[j].size(), ++j;
            int num_of_space = maxWidth - cnt;
            if(j - cur == 1){
                for (int i = 0; i < cnt; ++i)
                    curstr[i] = words[cur][i];
            }else if(j == n){
                for (int i = 0, len = 0; i < n - cur; ++i){
                    int siz = words[cur + i].size();
                    for (int j = 0; j < siz; ++j)
                        curstr[len++] = words[cur + i][j];
                    len++;
                }
            }else{
                int pos = (j - cur - 1), bas = num_of_space / pos;
                int left = num_of_space % pos;
                for (int i = 0, len = 0; i <= pos; ++i){
                    int siz = words[cur + i].size();
                    for (int j = 0; j < siz; ++j)
                        curstr[len++] = words[cur + i][j];
                    len += bas;
                    if(left) len++, left--;
                }
            }
            ans.push_back(curstr);
            cur = j;
        }
        return ans;
    }
};
```

# 72
简单DP
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if(!len1 || !len2) return len1 + len2;
        vector<vector<int> > f(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i <= len1; ++i)
            f[i][0] = i;
        for (int i = 0; i <= len2; ++i)
            f[0][i] = i;
        for (int i = 1; i <= len1; ++i)
            for (int j = 1; j <= len2; ++j){
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                if(word1[i - 1] == word2[j - 1])
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                else
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            }
        return f[len1][len2];
    }
};
```

# 76
尺取法
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(129, 0), cnt2(129, 0);
        int i = 0, j = -1, n = s.size(), m = t.size();
        int tot = 0, curtot = 0;
        int ans = n + 1, posi = -1, posj = -1;
        for (int k = 0; k < m; ++k){
            cnt2[t[k]]++;
            if(cnt2[t[k]] == 1) tot++;
        }
        for(; i < n && j < n - 1; ){
            while(j < n - 1 && curtot < tot){
                ++j, cnt[s[j]]++;
                if(cnt[s[j]] == cnt2[s[j]]) curtot++;
            }
            if(j == n - 1 && curtot < tot) break;
            while(i < j){
                if(cnt[s[i]] == cnt2[s[i]]) break;
                cnt[s[i]]--, ++i;
            }
            if(ans > j - i + 1)
                ans = j - i + 1, posi = i, posj = j;
            cnt[s[i]]--, --curtot, ++i;
        }
        if(ans == n + 1) return string("");
        return s.substr(posi, ans);
    }
};
```

# 84
单调栈经典题
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        heights.push_back(0);
        int n = heights.size();
        vector<int> id, w;
        for (int i = 0; i < n; ++i){
            int curw = 0;
            while(!id.empty() && heights[id.back()] >= heights[i]){
                curw += w.back();
                ans = max(ans, curw * heights[id.back()]);
                id.pop_back(), w.pop_back();
            }
            id.push_back(i), w.push_back(curw + 1);
        }
        return ans;
    }
};
```

# 85
扩展单调栈
```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size(), ans = 0;
        stack<int> st, w;
        vector<int> h(m + 1, 0);
        for (int i = 0, cur = 0; i < m; ++i){
            if(matrix[0][i] == '1') h[i] = 1, cur++, ans = max(ans, cur);
            else cur = 0, h[i] = 0;
        }
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if(matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            while(!st.empty())
                st.pop(), w.pop();
            for (int j = 0; j <= m; ++j){
                int curw = 0;
                while(!st.empty() && st.top() >= h[j])
                    curw += w.top(), ans = max(ans, curw * st.top()), st.pop(), w.pop();
                w.push(curw + 1), st.push(h[j]);
            }
        }
        return ans;
    }
};
```

# 87
考虑将两个字符串切分，只有两种可能：

1. 第一个的前半部分配第二个的前半部分，第一个的后半部分配第二个的后半部分。
2. 第一个的前半部分配第二个的后半部分，第一个的后半部分配第二个的前半部分。

然后判定配对成功与否用一个桶即可，这样递归下去也跑的比较快。
```cpp
class Solution {
public:
    bool dfs(string& s1, string& s2, int l1, int r1, int l2, int r2, bool flag){
        if (r1 - l1 == 1)
            return s1[l1] == s2[l2];
        int vec[128] = {0}, cnt = 0;
        for (int i = 1; i < r1 - l1; ++i){
            if (vec[s1[l1 + i - 1]] == 0) ++cnt;
            else if (vec[s1[l1 + i - 1]] == -1) --cnt;
            ++vec[s1[l1 + i - 1]];
            if (flag) {
                if (vec[s2[l2 + i - 1]] == 1) --cnt;
                else if (vec[s2[l2 + i - 1]] == 0) ++cnt;
                --vec[s2[l2 + i - 1]];
                if (cnt == 0 && (dfs(s1, s2, l1, l1 + i, l2, l2 + i, true) || dfs(s1, s2, l1, l1 + i, l2, l2 + i, false)) &&
                    (dfs(s1, s2, l1 + i, r1, l2 + i, r2, true) || dfs(s1, s2, l1 + i, r1, l2 + i, r2, false)))
                    return true;
            }else {
                if (vec[s2[r2 - i]] == 1) --cnt;
                else if (vec[s2[r2 - i]] == 0) ++cnt;
                --vec[s2[r2 - i]];
                if (cnt == 0 && (dfs(s1, s2, l1, l1 + i, r2 - i, r2, true) || dfs(s1, s2, l1, l1 + i, r2 - i, r2, false)) &&
                    (dfs(s1, s2, l1 + i, r1, l2, r2 - i, true) || dfs(s1, s2, l1 + i, r1, l2, r2 - i, false)))
                    return true;
            }
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        return dfs(s1, s2, 0, s1.length(), 0, s2.length(), true) || 
            dfs(s1, s2, 0, s1.length(), 0, s2.length(), false);
    }
};
```

# 97
简单的 DP。可以压成一维。
```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ( s1.empty() ) return s2 == s3;
        if ( s2.empty() ) return s1 == s3;
        int n = s1.length(), m = s2.length();
        if ( n + m != s3.length() ) return false;
        vector<vector<bool> > f( n + 1, vector<bool>( m + 1, false ));
        f[0][0] = true;
        for (int i = 0; i < n; ++i){
            if ( s1[i] == s3[i] && f[i][0] ) f[i + 1][0] = true;
            else break;
        }
        for (int i = 0; i < m; ++i){
            if ( s2[i] == s3[i] && f[0][i] ) f[0][i + 1] = true;
            else break;
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if ( s1[i] == s3[i + j + 1] && f[i][j + 1] )
                    f[i + 1][j + 1] = true;
                else if ( s2[j] == s3[i + j + 1] && f[i + 1][j] ) 
                    f[i + 1][j + 1] = true;
            }
        }
        return f[n][m];
    }
};
```

# 99
观察可以发现：整个中序遍历序列中，只会出现一或两次前一元素大于后一元素的情况。而且一次的情况可以视作是两次该结构出现在同一位置的特殊情况。
这样规约后得到：对于序列中靠前的该结构，其前一元素是被交换的；对于序列中靠后的该结构，其后一元素是被交换的。这样就找到了两个交换了的元素。
```cpp
class Solution {
public:
    TreeNode *lst1, *targ1, *targ2;
    void dfs(TreeNode* root){
        if (root == NULL) return ;
        dfs(root->left);
        if (lst1 != NULL && lst1->val > root->val){
            if (targ1 == NULL) targ1 = lst1, targ2 = root;
            else targ2 = root;
        }
        lst1 = root;
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        lst1 = NULL, targ1 = targ2 = NULL;
        dfs(root);
        swap(targ1->val, targ2->val);
    }
};
```

注：这里的代码并不是一开始交上去的代码，而是做了精简的版本。原版考虑了一个更加复杂的结构，但也是对的。

# 115
一个挺水的计数DP，但是可以优化到不错的效果。
可以层层优化。
```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned> > f(n + 1, vector<unsigned>(m + 1, 0));
        for (int i = 0; i <= n; ++i)
            f[i][0] = 1;
        for (int j = 0; j < m; ++j){
            for (int i = 0; i < n; ++i){
                if(s[i] == t[j]){
                    f[i + 1][j + 1] = f[i][j] + f[i][j + 1];
                }else{
                    f[i + 1][j + 1] = f[i][j + 1];
                }
            }
        }
        return f[n][m];
    }
};
```

# 123
对122的DP方程稍微做些修改即可。
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> f(n, 0);
        int mini = prices[0];
        for (int i = 1; i < n; ++i){
            f[i] = max(prices[i] - mini, f[i - 1]);
            mini = min(mini, prices[i]);
        }
        int pst1 = -prices[0], ans = 0;
        for (int i = 1; i < n; ++i){
            int tmp = prices[i] + pst1;
            ans = max(ans, tmp);
            pst1 = max(pst1, f[i - 1] - prices[i]);
        }
        return ans;
    }
};
```

# 124
简单的树形DP，考虑以当前节点为LCA的最大路径和，那么只需要求出左、右两个节点为根时对应的最大路径和相加即可。
可以设计成下面的递归函数求解。
```cpp
class Solution {
public:
    int ans;
    int dfs(TreeNode *root){
        if(root == NULL) return -2147483648;
        int ll = max(0, dfs(root->left));
        int rr = max(0, dfs(root->right));
        ans = max(ans, root->val + ll + rr);
        return root->val + max(ll, rr);
    } 
    int maxPathSum(TreeNode* root) {
        ans = -2147483648;
        dfs(root);
        return ans;
    }
};
```

# 128
一开始想到的是万能的排序，后来想到这种依附关系用并查集很好维护，进而推想出可以不用并查集而是用 Hash Table 直接扫区间。
所以就是 $O(n)$ 了。这里偷了懒，用的是自带的 unordered_map。
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
            mp[nums[i]] = i;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i){
            if ( !mp.count( nums[i] ) ) continue;
            mp.erase( nums[i] );
            int res = 1, tmp = nums[i];
            while ( mp.count( tmp + 1 ) )
                ++res, mp.erase( tmp + 1 ), ++tmp;
            tmp = nums[i];
            while ( mp.count( tmp - 1 ) )
                ++res, mp.erase( tmp - 1 ), --tmp;
            ans = max( ans, res );
        }
        return ans;
    }
};
```

# 132
比较标准的一维 $O(n^2)$ DP，不知道有没有更好的方法。。。
```cpp
class Solution {
public:
    vector<vector<int>> pos;
    vector<int> ans;
    int minCut(string s) {
        int n = s.length();
        pos = vector<vector<int> >(n, vector<int>());
        ans = vector<int>(n, n);
        for (int i = 0; i < n; ++i)
            for (int j = i, k = i; j >= 0 && k < n && s[j] == s[k]; --j, ++k)
                pos[k].push_back(j);
        for (int i = 0; i < n - 1; ++i)
            for (int j = i, k = i + 1; j >= 0 && k < n && s[j] == s[k]; --j, ++k)
                pos[k].push_back(j);
        ans[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j: pos[i]){
                if (j == 0){
                    ans[i] = 0;
                    break;
                }else ans[i] = min(ans[i], ans[j - 1] + 1);
            }
        }
        return ans[n - 1];
    }
};
```

# 135
一个比较水的递推。

可以发现这个题只有在分数不断下降的时候比较难搞，我们就记录一下总共下降的长度和这个下降坡对应第一个人的糖果数目。在下降的时候，我们先认为每一个人都只分到 0 个糖，在整个下降序列结束的时候再结算。

然后就是简单的数学问题：对于第一个人，考虑要不要增加他的糖果数，使得其糖果数至少等于下降序列的长度；对于其他人，他们的糖果数依次递减，最后递减到 1，所以很容易算出这一部分的糖果总数。

最后统计答案即可。为了节省空间，我们只记录前一个人的糖果数，而不是把糖果数记录成为一个数组。

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 1, n = ratings.size(), lst = 1;
        int len = 1, st = 1;
        for (int i = 1; i < n; ++i){
            if (ratings[i] > ratings[i - 1]){
                ans += lst + 1, ++lst;
                ans += (len * (len - 1) >> 1) + max(len - st, 0);
                len = 1, st = lst;
            }else if (ratings[i] == ratings[i - 1]){
                ++ans, lst = 1;
                ans += (len * (len - 1) >> 1) + max(len - st, 0);
                len = 1, st = lst;
            }else {
                lst = 1, ++len;
            }
        }
        ans += (len * (len - 1) >> 1) + max(len - st, 0);
        return ans;
    }
};
```

# 140
在 139 的基础上修改一下，记录路径即可。
```cpp
class Solution {
public:
    vector<string> ans;
    void dfs(int cur, string str, vector<vector<int>>& e, vector<string>& wordDict){
        if (!cur) {
            str.pop_back();
            ans.push_back(str);
            return ;
        }
        for (int v: e[cur])
            dfs(cur - wordDict[v].length(), wordDict[v] + " " + str, e, wordDict);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int l = s.length(), n = wordDict.size();
        vector<vector<int>> edges(l + 1, vector<int>());
        edges[0].push_back(-1);
        for (int i = 1; i <= l; ++i){
            for (int j = 0; j < n; ++j){
                int l1 = wordDict[j].length();
                if (i >= l1 && s.substr(i - l1, l1) == wordDict[j] && !edges[i - l1].empty()){
                    edges[i].push_back(j);
                }
            }
        }
        dfs(l, "", edges, wordDict);
        return ans;
    }
};
```

# 145
这很难？
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        ans = []
        def travell(curn):
            if curn.left != None:
                travell(curn.left)
            if curn.right != None:
                travell(curn.right)
            ans.append(curn.val)
            
        travell(root)
        return ans
```
不过要想到这个比较精巧的非递归方法，是挺难的。

# 149
本来以为这个题目要用什么非常高深的方法，结果发现就是暴力 $O(N^2)$。。。

用一个 map 记录一下就行了，要开 long double，因为有数据专门卡这个。

不过看评论区发现更暴力的 $O(N^3)$ 好像更快，应该是因为用的是整数的叉积，同时没有用到什么数据结构。

```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<long double, int> mp;
        int ans = 0;
        for (int i = 0; i < points.size(); ++i){
            mp.clear();
            int vect = 0, self = 1, maxi = 0;
            for (int j = i + 1; j < points.size(); ++j){
                if (points[j][0] == points[i][0])
                    if (points[j][1] == points[i][1]) self++;
                    else vect++;
                else{
                    long double k = (long double) (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    if (!mp.count(k)) mp[k] = 1, maxi = max(maxi, 1);
                    else ++mp[k], maxi = max(maxi, mp[k]);
                }
            }
            maxi = max(maxi, vect) + self;
            ans = max(ans, maxi);
        } 
        return ans;
    }
};
```

# 154
因为有重复的数据，所以我们难以找出具体的旋转点，从而难以进行二分。
但我们仍然可以缩小搜索范围，并且达到一个比较理想的时间复杂度。


# 164
邓公的计算几何里面讲到过这个题。
大体思路就是按照元素个数分配相应个数的桶，然后把数据放进桶里，比较左边桶的最大值和右边桶的最小值之间的差值。
实现的时候有的细节比较烦人，不过按照分块的写法来就比较容易。
```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
		int mini = INT_MAX, maxi = -1;
		for (int i = 0; i < n; ++i)	
			mini = min(mini, nums[i]), 
			maxi = max(maxi, nums[i]);
		vector<bool> vis(n, false);
        vector<int> mine(n, INT_MAX), maxe(n, -1);
		int bsize = max(1, (maxi - mini) / (n - 1));
		if (bsize * (n - 1) < (maxi - mini))
			++bsize;
		
        for (int i = 0; i < n; ++i)	{
			int bid = (nums[i] - mini) / bsize;
			vis[bid] = true;
			mine[bid] = min(mine[bid], nums[i]);
			maxe[bid] = max(maxe[bid], nums[i]);
		}
		int ans = 0, cur = 0;
		while (!vis[cur]) ++cur;
		for (; cur < n; )	{
			ans = max(ans, maxe[cur] - mine[cur]);
			int j = cur + 1;
			while (j < n && !vis[j])
				++j;
			if (j == n) break;
			ans = max(ans, mine[j] - maxe[cur]);
			cur = j;
		}
		return ans;
    }
};
```

# 174
非常傻的一个解法（我写的）是二分答案。实际上根本没必要，只要从终点开始 DP 就行了。状态表示为从当前位置到终点需要的最小 HP。
这可能也说明了一些问题：一些用二分可以做的题目，实际上可能倒推更好做。
```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if ( dungeon.empty() ) return 1;
        int n = dungeon.size(), m = dungeon[0].size();
        for (int i = n - 1; i >= 0; --i)
            for (int j = m - 1; j >= 0; --j){
                if ( i == n - 1 && j == m - 1 )
                    dungeon[i][j] = max( 0, -dungeon[i][j] ) + 1;
                else {
                    int mini = 2147483647;
                    if ( i + 1 < n ) mini = min( mini, dungeon[i + 1][j] );
                    if ( j + 1 < m ) mini = min( mini, dungeon[i][j + 1] );
                    dungeon[i][j] = max( 1, mini - dungeon[i][j] );
                }
            }
        return dungeon[0][0];
    }
};
```

# 188
对123再次修改，不断迭代求解，直到解的大小不再变化为止（因为 $k$ 可以很大）。
```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<vector<int> > f(2, vector<int>(n, 0));
        int mini = prices[0];
        for (int i = 1; i < n; ++i){
            f[1][i] = max(prices[i] - mini, f[1][i - 1]);
            mini = min(mini, prices[i]);
        }
        int lstans = 0;
        for (int i = 2; i <= k; ++i){
            int B = i & 1, B_ = 1 - B;
            fill(f[B].begin(), f[B].end(), 0);
            int pst1 = -prices[0], curans = 0;
            for (int j = 1; j < n; ++j){
                int tmp = prices[j] + pst1;
                f[B][j] = max(tmp, f[B][j - 1]);
                curans = max(tmp, f[B][j]);
                pst1 = max(pst1, f[B_][j - 1] - prices[j]);
            }
            if(curans == lstans) return curans;
            lstans = curans;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, f[k & 1][i]);
        return ans;
    }
};
```

# 212
普通 DFS 加上一个 Trie 树。题目里给了这个提示。
```cpp
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
class WordDictionary {
public:
    struct Node{
        int al[26], isend;
        Node() {
            memset(al, 0, sizeof(al));
            isend = 0;
        }
    };
    vector<Node> trie;
    int cnt;
    WordDictionary() {
        trie.push_back(Node()), trie.push_back(Node());
        cnt = 1;
    }
    void addWord(string& word, int iid) {
        int rt = 1;
        for (char c: word){
            if(!trie[rt].al[c - 'a'])
                trie.push_back(Node()), 
                trie[rt].al[c - 'a'] = ++cnt;
            rt = trie[rt].al[c - 'a'];
        }
        trie[rt].isend = iid;
    }
};
class Solution {
public:
    WordDictionary wc;
    int n, m;
    vector<vector<bool> > vis;
    vector<bool> stat;
    void dfs(vector<vector<char>>& board, int x, int y, int rt){
        if (wc.trie[rt].isend > 0) 
            stat[wc.trie[rt].isend - 1] = true;
        for (int i = 0; i < 4; ++i){
            int cx = x + dx[i], cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m || vis[cx][cy]) continue;
            if (!wc.trie[rt].al[board[cx][cy] - 'a']) continue;
            int new_rt = wc.trie[rt].al[board[cx][cy] - 'a'];
            vis[cx][cy] = true;
            dfs(board, cx, cy, new_rt);
            vis[cx][cy] = false;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (board.empty()) return ans;
        if (words.empty()) return ans;
        n = board.size(), m = board[0].size();
        vis = vector<vector<bool> >(n, vector<bool>(m, false));
        int wz = words.size();
        stat = vector<bool>(wz, false);
        for (int i = 0; i < wz; ++i)
            wc.addWord(words[i], i + 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if (!wc.trie[1].al[board[i][j] - 'a']) continue;
                int new_rt = wc.trie[1].al[board[i][j] - 'a'];
                vis[i][j] = true, dfs(board, i, j, new_rt), vis[i][j] = false;
            }
        for (int i = 0; i < wz; ++i)
            if (stat[i]) ans.push_back(words[i]);
        return ans;
    }
};
```

# 214
一开始手搓了一个暴力，结果在最后一个点炸上天去了。
于是果断上 manacher。其实要求的东西很简单，就是最长的回文前缀。
```cpp
class Solution {
public:
    void manacher(string& s, vector<int>& res){
        int n = s.length();
        res[0] = 0;
        for (int i = 1; i < (n << 1) - 1; ++i) res[i] = -1;
        for (int i = 1, rmost = 0; i < (n << 1) - 1; ++i){
            int l = (i >> 1), r = i - l, rpos = ((rmost + 1) >> 1) + res[rmost] - 1;
            if ((rmost << 1) >= i)
                res[i] = min(rpos - r + 1, res[(rmost << 1) - i]);
            while (l - res[i] - 1 >= 0 && r + res[i] + 1 < n 
                && s[l - res[i] - 1] == s[r + res[i] + 1])
                ++res[i];
            if (r + res[i] - 1 > rpos)
                rmost = i;
        } 
    }
    string shortestPalindrome(string s) {
        int n = s.length(), ans = 0;
        if (!n) return s;
        vector<int> res((n << 1) - 1, 0);
        manacher(s, res);
        for (int i = 0; i < (n << 1) - 1; ++i){
            if (res[i] + (i & 1) == ((i + 1) >> 1))
                ans = max(ans, (res[i] << 1) + (i & 1) + 1);
        }
        string sans = s;
        reverse(sans.begin(), sans.end());
        for (int i = ans; i < n; ++i)   
            sans.push_back(s[i]);
        return sans;
    }
};
```

# 224
简单表达式计算
注意坑爹的2147483647
```cpp
class Solution {
public:
    int calculate(string s) {
        s = "(" + s + ")";
        stack<int> operand;
        stack<char> oprt;

        auto calc = [&operand, &oprt]() -> void{
            int r2 = operand.top();
            operand.pop();
            int r1 = operand.top();
            operand.pop();
            if(oprt.top() == '+') operand.push(r1 + r2);
            else operand.push(r1 - r2);
            oprt.pop();
        };

        int n = s.size();
        for (int i = 0, t = -1; i < n; ++i){
            if(s[i] == ' ') continue;
            if(isdigit(s[i])){
                if(t < 0) t = s[i] - '0';
                else t = t * 10 + (s[i] - '0');
            }else{
                if(s[i] == '('){
                    oprt.push(s[i]);
                }else{
                    if(t >= 0) operand.push(t), t = -1;
                    while(oprt.top() != '(')
                        calc();
                    if(s[i] == ')') oprt.pop();
                    else oprt.push(s[i]);
                }
            }
        }
        return operand.top();
    }
};
```

# 233

## 方法一
直接套用任意数字计数的方法求解。
```cpp
class Solution {
public:
    int countDigitOne(int n) {
        int j = 1, p = 0, ans = 0;
        while (j * 10ll <= n)
            j *= 10, ++p;
        while (n > 0){
            ans += (n / j) * (j / 10) * p;
            if (n / j == 1)
                ans += (n % j) + 1;
            else if (n / j > 1)
                ans += j;
            n %= j, j /= 10, --p;
        }
        return ans;
    }
};
```

## 方法二
使用公式。

# 239
没啥好说的，单调队列模板题。。。
```cpp
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if nums == []:
            return []
        que, len1, len2 = [], 0, len(nums)
        ans = []
        for i in range(k):
            while len1 > 0 and nums[i] >= que[-1][0]:
                que.pop()
                len1 -= 1
            que.append((nums[i], i))
            len1 += 1
        for i in range(k, len2):
            ans.append(que[0][0])
            if i - que[0][1] >= k:
                del que[0]
                len1 -= 1
            while len1 > 0 and nums[i] >= que[-1][0]:
                que.pop()
                len1 -= 1
            que.append((nums[i], i))
            len1 += 1
        ans.append(que[0][0])
        return ans
```

# 273
按照十亿，百万，千和百分解即可。
```cpp
string sl1[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string sl2[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string sl3[] = {"Billion", "Million", "Thousand", "Hundred"};
int t[] = {1000000000, 1000000, 1000, 100};
class Solution {
public:
    string dfs(int num){
        for (int i = 0; i < 4; ++i)
            if (num / t[i]){
                if (num % t[i] == 0) return dfs(num / t[i]) + " " + sl3[i];
                return dfs(num / t[i]) + " " + sl3[i] + " " + dfs(num % t[i]);
            }
        if (num < 20) return sl1[num];
        if (num % 10 == 0) return sl2[num / 10 - 2];
        return sl2[num / 10 - 2] + " " + sl1[num % 10];
    }
    string numberToWords(int num) {
        if (!num) return string("Zero");
        string ans = dfs(num);
        if (ans.back() == ' ') ans.pop_back();
        return ans;
    }
};
```

# 295
对顶堆
```cpp
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int> > pq2;
    int n;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if(n & 1){
            pq1.push(num);
            pq2.push(pq1.top());
            pq1.pop();
        }else{
            if(pq1.empty() || pq1.top() >= num) pq1.push(num);
            else{
                pq2.push(num);
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
        ++n;
    }
    
    double findMedian() {
        if(!n) return 0;
        if(n & 1){
            return pq1.top();
        }else{
            return (pq1.top() + pq2.top()) * 0.5;
        }
    }
};
```

# 297
比较简单的想法是把所有叶子节点表示出来，然后用前序遍历去记录。
注意数据可能带符号。
```cpp
class Codec {
public:

    void dfs( TreeNode* root, string& ans ){
        if (root == NULL) {
            ans.push_back(' ');
            ans.push_back('#');
            return ;
        }
        ans.push_back(' ');
        ans += to_string( root->val );
        dfs( root->left, ans );
        dfs( root->right, ans );
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans("");
        dfs( root, ans );
        return ans;
    }

    pair<TreeNode*, int> dfs2( string& data, int l ){
        ++l;
        if ( data[l] == '#' ) return make_pair( ( TreeNode* ) NULL, l + 1 );
        int x = 0, flag = 1;
        if ( data[l] == '-' ) flag = -1, ++l;
        while ( data[l] != ' ' )
            x = x * 10 + data[l] - '0', ++l;
        x = x * flag;
        TreeNode* root = new TreeNode(x);
        pair<TreeNode*, int> res = dfs2 ( data, l );
        root->left = res.first, l = res.second;
        res = dfs2 ( data, l );
        root->right = res.first, l = res.second;
        return make_pair( root, l );
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return dfs2( data, 0 ).first;
    }
};
```

# 312
简单的区间DP，状态设成戳破两个区间端点之间的气球可以得到的最大的分数。
```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
		nums.push_back(1);
		nums.insert(nums.begin(), 1);
		int n = nums.size();
        vector<vector<int> > f(n, vector<int>(n, 0));
        for (int i = 2; i < n; ++i)
			for (int j = 0; j + i < n; ++j)
				for (int k = j + 1; k < j + i; ++k)	
					f[j][j + i]	= max(f[j][i + j], f[j][k] + f[k][j + i] + nums[k] * nums[i + j] * nums[j]); 
		return f[0][n - 1];
    }
};
```

# 315
本质是对每一个数计算其作为逆序对中较大的数的贡献。

可以用归并排序做，也可以用树状数组去做。
```cpp
class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        list1, len1 = list(enumerate(nums)), len(nums)
        list1.sort(key = lambda x: x[1])
        cnt, ans = [0 for i in range(len1 + 1)], [0 for i in range(len1)]
        
        def lowbit(x):
            return x & (-x)
        def ask(r):
            res = 0
            while r > 0:
                res += cnt[r]
                r -= lowbit(r)
            return res
        def modify(k, r):
            while r <= len1:
                cnt[r] += k
                r += lowbit(r)

        for tp in list1:
            ans[tp[0]] = ask(len1) - ask(tp[0] + 1)
            modify(1, tp[0] + 1)
        return ans
```

# 316
同 1081
```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26] = {0}, n = s.length();
        bool vis[26] = {0};
        for (int i = 0; i < n; ++i)
            ++cnt[s[i] - 'a'];
        string ans;
        for (int i = 0; i < n; --cnt[s[i] - 'a'], ++i){
            if (vis[s[i] - 'a']) 
                continue;
            while (!ans.empty() && s[i] <= ans.back()){
                if (!cnt[ans.back() - 'a'])
                    break;
                vis[ans.back() - 'a'] = false, ans.pop_back();
            }
            vis[s[i] - 'a'] = true, ans.push_back(s[i]);
        }
        return ans;
    }
};
```

# 327
multiset维护前缀和
```cpp
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        set<long long> st;
        st.insert(0);
        int n = nums.size(), ans = 0;
        long long ss = 0;
        for (int i = 0; i < n; ++i){
            ss += 1ll * nums[i];
            ans += distance(st.lower_bound(ss - upper), st.upper_bound(ss - lower));
            st.insert(ss);
        }
        //Si - Sj >= lower -> Sj <= Si - lower
        //Si - Sj <= upper -> Sj >= Si - upper
        return ans;
    }
};
```

# 329
先对矩阵中的数排序，然后从小到大转移。或者记忆化搜索也可以。
```cpp
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        typedef pair<int, pair<int, int> > T;
        vector<T> vec;
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size(), ans = 0;
        vector<vector<int> > f(n, vector<int>(m, 1));
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                vec.push_back(make_pair(matrix[i][j], make_pair(i, j)));
        sort(vec.begin(), vec.end());
        for (T &t: vec){
            int h = t.first, x = t.second.first, y = t.second.second;
            for (int i = 0; i < 4; ++i){
                int cx = x + dx[i], cy = y + dy[i];
                if(cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
                if(matrix[cx][cy] < h) f[x][y] = max(f[x][y], f[cx][cy] + 1);
            }
            ans = max(ans, f[x][y]);
        }
        return ans;
    }
};
```

# 336

## 方法一
暴力能过，惊了（对，卡过去的）
```cpp
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i){
            int len1 = words[i].length();
            for (int j = 0; j < n; ++j){
                if (i == j) continue;
                int len2 = words[j].length();
                int len = len1 + len2;
                bool flag = true;
                for (int u = 0, v = len - 1; u < v; ++u, --v){
                    if ((u < len1 ? words[i][u]: words[j][u - len1]) != 
                        (v >= len1 ? words[j][v - len1]: words[i][v])){
                            flag = false;
                            break;
                        }
                }
                if (flag) ans.push_back(vector<int>{i, j});
            }
        }
        return ans;
    }
};
```

## 方法二
这个的思想和添加最短前缀变成回文串相似，考虑把字符串截成某两部分，检查前/后一部分是不是回文串，是的话把另一部分对称过去即可。
注意考虑空字符串。
不得不说，c++ 里面操纵字符串确实比 python 麻烦挺多。。。
```cpp
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i)
            mp[words[i]] = i;
        auto check = [](string& x, int i, int j){
            for (; i < j; ++i, --j)
                if (x[i] != x[j]) return false;
            return true;
        };
        vector<vector<int>> ans;
        string emptystr("");
        for (int i = 0; i < n; ++i){
            int l = words[i].length();
            if (!l) continue;
            if (check(words[i], 0, l - 1)){
                if (mp.count(emptystr)) {
                    int id = mp[emptystr];
                    ans.push_back(vector<int>{i, id}), 
                    ans.push_back(vector<int>{id, i});
                }
            }else {
                string tmp = words[i];
                reverse(tmp.begin(), tmp.end());
                if (mp.count(tmp)){
                    int id = mp[tmp];
                    ans.push_back(vector<int>{id, i});
                }
            }
            string tmpa = words[i];
            reverse(tmpa.begin(), tmpa.end());
            for (int j = 0; j < l - 1; ++j){
                if (check(words[i], 0, j)){
                    string tmp = tmpa.substr(0, l - j - 1);
                    if (mp.count(tmp))
                        ans.push_back(vector<int>{mp[tmp], i});
                }
                if (check(words[i], j + 1, l - 1)){
                    string tmp = tmpa.substr(l - j - 1);
                    if (mp.count(tmp))
                        ans.push_back(vector<int>{i, mp[tmp]});
                }
            }
        }
        return ans;
    }
};
```

# 352
用一个 multiset 维护区间，合并即可。
```cpp
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    multiset<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (st.count(val))
            return ;
        st.insert(val);
        auto iter = st.find(val);
        if (distance(st.begin(), iter) & 1) {
            st.erase(iter);
            return ;
        }
        auto iter2 = iter;
        ++iter2;
        if (iter != st.begin() && iter2 != st.end()){
            auto iter3 = iter;
            --iter3;
            int l = *iter3, r = *iter2;
            if (l == val - 1 && r == val + 1)
                st.erase(iter3), st.erase(iter2), st.erase(iter);
            else if (l == val - 1)
                st.erase(iter3);
            else if (r == val + 1)
                st.erase(iter2);
            else st.insert(val);
        }else if (iter != st.begin()){
            auto iter3 = iter;
            --iter3;
            if (*iter3 == val - 1){
                st.erase(iter3);
            }else st.insert(val);
        }else if (iter2 != st.end()){
            if (*iter2 == val + 1){
                st.erase(iter2);
            }else st.insert(val);
        }else st.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto iter = st.begin(); iter != st.end(); ++iter){
            vector<int> vec{*iter};
            ++iter;
            vec.push_back(*iter);
            ans.push_back(vec);
        }
        return ans;
    }
};
```

# 354
经典的二位偏序问题。

## 方法一
最水的方法就是先按点对的方式排一个序，然后做 $O(n^2)$ 的朴素 DP。
```cpp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), ans = 0;
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& v1, vector<int>& v2){
            if (v1[0] == v2[0]) return v1[1] < v2[1];
            return v1[0] < v2[0];
        });
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    f[i] = max(f[i], f[j] + 1);
            }
        }
        for (int i = 0; i < n; ++i)
            ans = max(ans, f[i]);
        return ans;
    }
};
```

## 方法二


# 363
还是这种二维化一维的题目，先枚举要选择的两列，然后对行扫描，用一个 set 保存前面遇到的前缀和，每一次查询当前和减掉 $K$ 的 lower_bound 就行了。
```cpp
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size(), ans = INT_MIN;
        if (!m) return 0;
        vector<vector<int> > sum(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] = sum[i + 1][j] + matrix[i][j];
        set<int> st;
        for (int i = 1; i <= m; ++i){
            for (int j = i; j <= m; ++j){
                st.clear();
                st.insert(0);
                int ssm = 0;
                for (int t = 1; t <= n; ++t){
                    ssm += sum[t][j] - sum[t][i - 1];
                    auto iter = st.lower_bound(ssm - k);
                    if (iter != st.end())
                        ans = max(ans, ssm - *iter);
                    st.insert(ssm);
                }
            }
        }
        return ans;
    }
};
```

# 391

## 方法一
暴力求面积并，然后判断是否符合矩形边框的面积，同时判断是否符合所有给定矩形的面积和。

本题针对假算法的反例特别多。
```cpp
int seg[400005], mini[400005], yy[100005], id[100005], sum[100005];
int siz, _a, _b, val;
pair<int, int> pp[100005];
void maintain(int id, int l, int r){
    if (mini[id] > 0) seg[id] = sum[r] - sum[l - 1];
    else seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
void update(int id, int l, int r){
    if (l > _b || r < _a) return ;
    if (l >= _a && r <= _b){
        mini[id] += val;
        maintain(id, l, r);
        return ;
    }
    update(id << 1, l, (l + r) >> 1);
    update(id << 1 | 1, (l + r + 1) >> 1, r);
    maintain(id, l, r);
}
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        int rr = INT_MIN, uu = INT_MIN, ll = INT_MAX, dd = INT_MAX; 
        long long rarea = 0;
        for (int i = 0; i < n; ++i){
            pp[i << 1].first = rectangles[i][0], 
            pp[i << 1].second = i + 1,
            pp[i << 1 | 1].first = rectangles[i][2], 
            pp[i << 1 | 1].second = -i - 1;
            yy[i << 1] = rectangles[i][1], yy[i << 1 | 1] = rectangles[i][3];

            ll = min(ll, rectangles[i][0]), rr = max(rr, rectangles[i][2]);
            uu = max(uu, rectangles[i][3]), dd = min(dd, rectangles[i][1]);
            rarea += 1ll * (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
        }
        sort(pp, pp + n + n);
        sort(yy, yy + n + n);
        for (int i = 0; i < n; ++i){
            id[i << 1] = lower_bound(yy, yy + n + n, rectangles[i][1]) - yy, 
            id[i << 1 | 1] = lower_bound(yy, yy + n + n, rectangles[i][3]) - yy;
        }
        sum[0] = 0;
        for (int i = 1; i < n + n; ++i)
            sum[i] = sum[i - 1] + yy[i] - yy[i - 1];
        for (siz = 1; siz < n + n - 1; siz <<= 1)
            ;

        memset(seg, 0, sizeof(seg));
        memset(mini, 0, sizeof(mini));
        long long ans = 0;
        int lst = pp[0].first;
        for (int i = 0; i < n + n; ++i){
            int xx = pp[i].first, pos = pp[i].second;
            int rid = (pos < 0 ? -pos: pos) - 1;
            _a = id[rid << 1] + 1, _b = id[rid << 1 | 1];
            ans += 1ll * seg[1] * (xx - lst);
            if (pos > 0){
                val = 1, update(1, 1, siz);
            }else {
                val = -1, update(1, 1, siz);
            }
            lst = xx;
        } 
        return ans == 1ll * (rr - ll) * (uu - dd);
    }
};
```

## 方法二

# 410
经典二分。注意数据范围大。
```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        unsigned int l = *max_element(nums.begin(), nums.end()), 
            r = accumulate(nums.begin(), nums.end(), 0u);
        int n = nums.size();
        while (r > l){
            unsigned int mid = (l + r) >> 1;
            int left = m;
            for (int i = 0; i < n; ){
                unsigned int cnt = 0;
                int j = i;
                while (j < n && cnt <= mid)
                    cnt += nums[j++];
                --left;
                i = (cnt > mid ? j - 1: j);
            }
            if (left < 0) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
```

# 466
这好像是一个经典的题目。

首先，如果我们能找到最大的 $k$ 使得 $[s_2, k]$ 是 $[s_1, n_1]$ 的子序列，那么显然答案就是 $\lfloor \frac {k} {n_2}\rfloor$。于是我们把问题转化为寻找这样的 $k$。

其次，这样含有“重复”的问题似乎可以使用倍增处理。我们下面使用这种想法。

先预处理出 `nxt` 数组：（方便起见，下面的字符都用 `0` 到 `25` 之间的数表示）`nxt[j][i]` 表示字符串 `s1` 在 `j` 位置，最近的下一个 `i` 字符的位置。这里的下一个是循环移位的，即下一个字符可以存在于 `j` 之前的位置。如果 `j` 位置之后不存在 `i` 字符则为 `-1`。

然后处理转移数组。`endp[i][j]` 表示从某个 `s1` 的 `i` 位置开始和 $2^j$ 个前后拼接的 `s2` 匹配，匹配完成的位置。这里的匹配可以看作是在由无限个 `s1` 首尾拼接成的串上进行的。可以在 $O(|s_1||s_2|)$ 的时间内利用 `nxt` 数组计算出 `endp[i][0]`，那么有 `endp[i][j]=endp[endp[i][j-1]][j-1]`。

再处理总共需要多少个 `s1` 完成这样的转移。`cnt[i][j]` 表示从 `s1` 的 `i` 位置开始和 $2^j$ 个前后拼接的 `s2` 匹配，中间经过的 `s1` 的首尾相接处的个数。在计算 `endp[i][0]` 时可以顺便计算 `cnt[i][0]`，然后有 `cnt[i][j]=cnt[i][j-1]+cnt[endp[i][j-1]][j-1]`。

最后，我们使用 `endp[i][j]` 和 `cnt[i][j]` 来计算结果。整个过程和倍增求 LCA 类似，此处不赘述。

整个算法的时间复杂度为 $O(|s_1||s_2|+L|s_1|)$，这里的 $L$ 是倍增时选取的最大的 $2^j$ 的指数。这里选 $L=26$。
```cpp
int endp[105][32], nxt[105][26];
unsigned cnt[105][32];
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        memset(endp, 0, sizeof(endp));
        memset(cnt, 0, sizeof(cnt));
        memset(nxt, -1, sizeof(nxt));
        int l1 = s1.length(), l2 = s2.length();
        for (int i = 0; i < 26; ++i){
            int pos = -1;
            for (int j = 0; j < l1; ++j)
                if (s1[j] == i + 'a'){
                    pos = j;
                    break ;
                }
            if (pos < 0){
                for (int j = 0; j < l1; ++j)
                    nxt[j][i] = -1;
            }else {
                nxt[pos][i] = pos;
                for (int j = (pos == 0 ? l1 - 1: pos - 1), lst = pos; j != pos; lst = j, j = (j == 0 ? l1 - 1: j - 1)){
                    if (s1[j] == i + 'a') nxt[j][i] = j;
                    else nxt[j][i] = nxt[lst][i];
                }
            }
        }
        for (int i = 0; i < l2; ++i)
            if (nxt[0][s2[i] - 'a'] < 0) 
                return 0;
        for (int i = 0; i < l1; ++i) {
            int cur = i;
            for (int j = 0; j < l2; ++j){
                int nx = nxt[cur][s2[j] - 'a'];
                if (nx < cur) ++cnt[i][0];
                if (nx == l1 - 1) cur = 0, ++cnt[i][0];
                else cur = nx + 1;
            }
            endp[i][0] = cur;
        }
        for (int i = 1; i <= 26; ++i)
            for (int j = 0; j < l1; ++j)
                endp[j][i] = endp[endp[j][i - 1]][i - 1], 
                cnt[j][i] = cnt[j][i - 1] + cnt[endp[j][i - 1]][i - 1];
        int ans = 0, used = 0, cur = 0;
        for (int i = 26; i >= 0; --i)
            if (cnt[cur][i] + used < n1 || (cnt[cur][i] + used == n1 && endp[cur][i] == 0))
                used += cnt[cur][i], cur = endp[cur][i], 
                ans += (1 << i);
        return ans / n2;
    }
};
```

# 483
外部枚举该进制可能的位数，内部二分出该进制。
```py
class Solution:
    def smallestGoodBase(self, n: str) -> str:
        from math import floor
        def db(x, t):
            fz = x ** (t + 1) - 1
            return fz // (x - 1)
        n = int(n)

        for t in range(64, 1, -1):
            ll, rr = 2, floor(n ** (1 / t))
            while ll < rr:
                mid = (ll + rr) >> 1
                if db(mid, t) < n:
                    ll = mid + 1
                else:
                    rr = mid
            if db(ll, t) == n:
                return str(ll)
        
        return str(n - 1)
```

# 493
改造归并排序求逆序对的过程即可。每次合并的时候维护一个指针，最开始指向右半部分的开头，然后对于每一个左半部分的元素，向右移动指针直到该元素第一次大于右半部分中指针所指向的元素。那么该元素的贡献就是指针和右半部分头指针的差。

显然这个指针的移动具有单调性，所以总的时间复杂度是 $O(n\log n)$。
```cpp
class Solution {
public:
    vector<int> tmp;
    int ans;
    void Merge(vector<int>& nums, int f, int md, int l){
	    int lp = f, rp = md, pos = f;
        int cur = md;
    	while(lp < md && rp < l){
    		if(nums[lp] < nums[rp]) {
                while (cur < l && 1ll * nums[lp] > 2ll * nums[cur])
                    ++cur;
                ans += cur - md, tmp[pos++] = nums[lp++];
            }else tmp[pos++] = nums[rp++];
    	}
    	while(lp < md) {
            while (cur < l && 1ll * nums[lp] > 2ll * nums[cur])
                ++cur;
            ans += cur - md, tmp[pos++] = nums[lp++];
        }
    	while(rp < l) tmp[pos++] = nums[rp++];
        for (int i = f; i < l; ++i) 
            nums[i] = tmp[i];
    }
    void MSort(vector<int>& nums, int l, int r){
    	if(r - l <= 1) return ;
    	else{
            int mid = (l + r) >> 1;
    		MSort(nums, l, mid);
    		MSort(nums, mid, r);
    		Merge(nums, l, mid, r);
    	}
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        tmp = vector<int>(n, 0);
        ans = 0;
        MSort(nums, 0, n);
        return ans;
    }
};
```

# 502
堆优化贪心
```cpp
class Solution {
public:
    priority_queue<int> pq;
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        k = min(k, n);
        vector<int> id(n, 0);
        for (int i = 0; i < n; ++i) id[i] = i;
        sort(id.begin(), id.end(), [&Capital](int i, int j){ return Capital[i] < Capital[j]; });
        int cur = 0;
        while (cur < n && Capital[id[cur]] <= W)
            pq.push(Profits[id[cur]]), ++cur;
        for (int i = 0; i < k && !pq.empty(); ++i){
            W += pq.top(), pq.pop();
            while (cur < n && Capital[id[cur]] <= W)
                pq.push(Profits[id[cur]]), ++cur;
        }
        return W;
    }
};
```

# 514
平凡的 DP，平凡的时间复杂度是 $O(n^2m)$，$n$ 是 `ring` 的长度，$m$ 是 `key` 的长度。

不知道有没有更加优秀的做法。
```cpp
int f[105][105], pos[26][105];
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        memset(f, 0x3f, sizeof(f));
        for (int i = 0; i < 26; ++i)
            pos[i][0] = 0;
        int n = ring.length(), m = key.length();
        for (int i = 0; i < n; ++i){
            int c = ring[i] - 'a';
            pos[c][++pos[c][0]] = i;
        }
        for (int i = 1; i <= pos[key[0] - 'a'][0]; ++i)
            f[0][i] = min(pos[key[0] - 'a'][i], n - pos[key[0] - 'a'][i]);
        for (int i = 1; i < m; ++i){
            int t1 = key[i - 1] - 'a', t2 = key[i] - 'a';
            for (int j = 1; j <= pos[t1][0]; ++j)
                for (int k = 1; k <= pos[t2][0]; ++k){
                    int opt1 = (pos[t1][j] - pos[t2][k] + n) % n, 
                        opt2 = (pos[t2][k] - pos[t1][j] + n) % n;
                    f[i][k] = min(f[i][k], f[i - 1][j] + min(opt1, opt2));                    
                }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= pos[key[m - 1] - 'a'][0]; ++i)
            ans = min(ans, f[m - 1][i]);
        return ans + m;
    }
};
```

# 546
同 UVa 10559。

## 方法一
设 $f(i, j, k)$ 为当前区间为 $[i, j]$，且区间中消除到有 $k$ 个和 $i$ 处颜色相同的方块时，可以得到的最大分数。显然，答案为 $f(1, n, 0)$。
当 $k\neq 0$ 时，要考虑从 $k-1$ 转移过来。此时考虑从 $[i, j]$ 中遍历 $l$，当第 $l$ 个方块颜色和第 $i$ 个相同时，将从 $l$ 左或者从 $l$ 右开始的一部分作为从 $k-1$ 转移过来的部分，另一部分消去。因为消去的顺序不影响结果，此处将右边一半消去。从而有：
$$
f(i, j, k) = \max_{i\le l\le j}\lbrace f(i, l - 1, k - 1) + f(l + 1, j, 0) \rbrace
$$
当 $k=0$ 时，考虑将积累下来的方块消去，就有：
$$
f(i, j, 0) = \max\lbrace f(i, j, k) + k^2\rbrace
$$
时间复杂度 $O(n^4)$。实测该实现在最后一个点极容易被卡 TLE。
```cpp
class Solution {
public:
    vector<vector<vector<int>>> f;
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        f = vector<vector<vector<int>>>(n + 2, vector<vector<int>>(n + 2, vector<int>(n + 2, -1)));
        for (int i = 1; i <= n; ++i)
            f[i][i][1] = 0, f[i][i][0] = 1;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                f[i][j][0] = 0;
        f[n + 1][n][0] = 0;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j + i <= n; ++j)
                for (int k = 1; k <= i + 1; ++k){
                    for (int l = j; l <= j + i; ++l){
                        if (boxes[j - 1] != boxes[l - 1]) continue;
                        if (f[j][l - 1][k - 1] >= 0)
                            f[j][j + i][k] = max(f[j][j + i][k], f[j][l - 1][k - 1] + f[l + 1][j + i][0]);
                    }
                    for(int k = 1; k <= i + 1; ++k)
                        if(f[j][j + i][k] >= 0)
                            f[j][j + i][0] = max(f[j][j + i][0], f[j][j + i][k] + k * k);
                }
        return f[1][n][0];
    }
};
```

## 方法二
使用记忆化搜索和快速转移优化，效果有明显的提升。
```cpp
int f[102][102][102], tot[102][102] = {0};
class Solution {
public:
    int dfs(int x, int y, int z, vector<int>& boxes){
        if (y < x) return 0;
        if (f[x][y][z] >= 0) return f[x][y][z];
        int d = y - x + 1;
        if (!z){
            int cnt = 1;
            while (cnt <= tot[x][0] && tot[x][cnt] <= y)
                ++cnt;
            for (int i = 1; i < cnt; ++i)
                f[x][y][z] = max(f[x][y][z], dfs(x, y, i, boxes) + i * i);
        }else {
            for (int i = tot[x][z], j = z; i <= y && j <= tot[x][0]; ++j, i = tot[x][j])
                f[x][y][z] = max(f[x][y][z], dfs(x, i - 1, z - 1, boxes) + dfs(i + 1, y, 0, boxes));
        }
        //cout << x << " " << y << " " << z << " " << f[x][y][z] << endl;
        return f[x][y][z];
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(f, -1, sizeof(f));
        memset(tot, 0, sizeof(tot));
        for (int i = 1; i <= n; ++i)
            f[i][i][1] = 0, f[i][i][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                if (boxes[i - 1] == boxes[j - 1])
                    tot[i][++tot[i][0]] = j;
        return dfs(1, n, 0, boxes);
    }
};
```

# 552
划分情况，总共可划分出 7 种情况：

1. 当前位不是 L，是第一个 L，是第二个 L，且之前没有出现过 A。
2. 当前位不是 L，是第一个 L，是第二个 L，且之前出现过 A。
3. 当前位是 A。（这种情况可以合并掉，所以总共可以只有 6 种，不过貌似用矩阵快速幂这种情况不能舍去？）

然后就是一个比较显而易见的线性递推。可以用矩阵快速幂优化。当然这里数据比较小，可以不用。
```cpp
class Solution {
public:
    int checkRecord(int n) {
        int f0 = 1, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;
        for (int i = 0; i < n; ++i){
            int ff0 = ((f0 + f1) % 1000000007 + f2) % 1000000007;
            int ff1 = f0;
            int ff2 = f1;
            int ff3 = ((f3 + f4) % 1000000007 + f5) % 1000000007;
            ff3 += f6;
            if (ff3 >= 1000000007) ff3 -= 1000000007;
            int ff4 = (f3 + f6) % 1000000007;
            int ff5 = f4;
            int ff6 = ((f0 + f1) % 1000000007 + f2) % 1000000007;
            f0 = ff0, f1 = ff1, f2 = ff2, f3 = ff3, 
            f4 = ff4, f5 = ff5, f6 = ff6;
        }
        int ans = f0 + f1;
        if (ans >= 1000000007) ans -= 1000000007;
        ans += f2;
        if (ans >= 1000000007) ans -= 1000000007;
        ans += f3;
        if (ans >= 1000000007) ans -= 1000000007;
        ans += f4;
        if (ans >= 1000000007) ans -= 1000000007;
        ans += f5;
        if (ans >= 1000000007) ans -= 1000000007;
        ans += f6;
        if (ans >= 1000000007) ans -= 1000000007;
        return ans;
    }
};
```

# 629
设 $f(i, j)$ 表示前 $i$ 个数构成 $j$ 个逆序对的方案数目。如果算出来了前 $i-1$ 的答案，考虑把元素 $i$ 插入到原来的序列里，插得位置不同会产生不同的逆序对数目。增加的逆序对数在 $[0, i-1]$ 内，据此可以写出状态转移方程：
$$
f(i, j) = \sum_{k = 0}^{i - 1} f(i - 1, j - k)
$$
修改一下有
$$
\begin{aligned}
f(i, j) &= \sum_{k = 0}^{i - 1} f(i - 1, j - k) \\
&= \sum_{k = 1}^{i} f(i - 1, j - k) + f(i - 1, j) - f(i - 1, j - i) \\
&= \sum_{k = 0}^{i - 1} f(i - 1, (j - 1) - k) + f(i - 1, j) - f(i - 1, j - i) \\
&= f(i, j - 1) + f(i - 1, j) - f(i - 1, j - i) 
\end{aligned}
$$
边界条件是 $f(0, 0) = 1$。时间复杂度 $O(nk)$。
```cpp
class Solution {
public:
    vector<vector<int>> vec;
    int kInversePairs(int n, int k) {
        vec = vector<vector<int>>(n + 1, vector<int>(k + 1, 0));
        vec[0][0] = 1;
        for (int i = 1; i <= n; ++i){
            vec[i][0] = 1;
            for (int j = 1; j <= k; ++j){
                vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
                if (vec[i][j] >= 1000000007)    
                    vec[i][j] -= 1000000007;
                if (j >= i){
                    vec[i][j] += 1000000007 - vec[i - 1][j - i];
                    if (vec[i][j] >= 1000000007)    
                        vec[i][j] -= 1000000007;
                }
            }
        }
        return vec[n][k];
    }
};
```

# 632
看起来就像是那种经常出现的堆的题目。
用堆维护一个滑动窗口即可，时间复杂度 $O(N\log K)$。
```cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        struct N{
            int id;
            vector<int>::iterator iter;  
            N ( int _id, vector<int>::iterator _v ): id( _id ), iter( _v ) {}
        };
        struct cmp{
            bool operator() ( const N& n1, const N& n2 ){
                return *(n1.iter) > *(n2.iter);
            }
        };
        priority_queue<N, vector<N>, cmp> pq;
        int n = nums.size();
        int ansl = 2147483647, ansr = -2147483648;
        for (int i = 0; i < n; ++i){
            if ( nums[i].empty() ) continue;
            pq.push( N( i, nums[i].begin() ) );
            ansl = min( ansl, nums[i].front() );
            ansr = max( ansr, nums[i].front() );
        }
        int curl = ansl, curr = ansr;
        for (; ansr > ansl && !pq.empty(); ){
            N nn = pq.top();
            pq.pop();
            if ( nn.iter + 1 != nums[nn.id].end() ){
                curl = ( pq.size() == n - 1 ) ? *pq.top().iter: curl;
                ++nn.iter;
                curl = min( curl, *nn.iter ), curr = max( curr, *nn.iter );
                pq.push( nn );
            }
            if ( ansr - ansl > curr - curl )
                ansl = curl, ansr = curr;
        }
        return vector<int> { ansl, ansr };
    }
};
```

# 639
比较简单的 DP，注意 * 不能代表 0，以及各种有 0 没 0 的情况即可。
```cpp
class Solution {
public:
    int numDecodings(string s) {
        int f2 = 1, f1 = 0, l = s.length();
        int M = 1000000007;
        if (s[0] == '*') f1 = 9;
        else if (s[0] != '0') f1 = 1;
        else return 0;
        for (int i = 1; i < l; ++i){
            int f0 = 0;
            if (s[i] == '*'){
                if (s[i - 1] == '*'){
                    f0 += 15ll * f2 % M;
                    f0 += 9ll * f1 % M;
                }else {
                    f0 += 9ll * f1 % M;
                    if (s[i - 1] == '1'){
                        f0 += 9ll * f2 % M;
                    }else if (s[i - 1] == '2'){
                        f0 += 6ll * f2 % M;
                    }
                }
            }else {
                if (s[i - 1] == '*'){
                    if (s[i] == '0'){
                        f0 += 2ll * f2 % M;
                    }else if (s[i] <= '6'){
                        f0 += f1;
                        f0 += 2ll * f2 % M;
                    }else {
                        f0 += f1;
                        f0 += f2;
                    }
                }else {
                    int t = 10 * (s[i - 1] - '0') + s[i] - '0';
                    if (s[i - 1] == '0'){
                        if (s[i] == '0') return 0;
                        f0 += f1;
                    }else {
                        if (t <= 26) f0 += f2;
                        if (s[i] != '0') f0 += f1;
                    }
                }
            }
            f0 %= M;
            f2 = f1, f1 = f0;
        }
        return f1;
    }
};
```

# 664
基本同 546，只需要将个数改成 0/1（即没有/有）即可。
```cpp
int f[102][102][2], tot[102][102] = {0};
class Solution {
public:
    int dfs(int x, int y, int z){
        if (y < x) return 0;
        if (f[x][y][z] < 0x3f3f3f3f) return f[x][y][z];
        cout << x << " " << y << " " << z << endl;
        if (!z){
            f[x][y][z] = dfs(x, y, 1) + 1;
        }else {
            for (int i = tot[x][z], j = z; i <= y && j <= tot[x][0]; ++j, i = tot[x][j])
                f[x][y][z] = min(f[x][y][z], dfs(x, i - 1, 1) + dfs(i + 1, y, 0));
        }
        cout << x << " " << y << " " << z << " " << f[x][y][z] << endl;
        return f[x][y][z];
    }
    int strangePrinter(string s) {
        int n = s.length();
        memset(f, 0x3f, sizeof(f));
        memset(tot, 0, sizeof(tot));
        for (int i = 1; i <= n; ++i)
            f[i][i][1] = 0, f[i][i][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                if (s[i - 1] == s[j - 1])
                    tot[i][++tot[i][0]] = j;
        return dfs(1, n, 0);
    }
};
```

# 668
经典二分。
```cpp
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (r > l){
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 1; i <= m; ++i)
                cnt += min(n, mid / i);
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
```

# 675

## 方法一
每次都暴力 BFS 算出两点间距离。事件复杂度：$O(n^2m^2)$。
```cpp
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
class Solution {
public:
    map<int, pair<int, int>> mp;
    vector<pair<int, int>> vec;
    vector<vector<int>> dis;
    vector<vector<bool>> vis;
    queue<int> qx, qy;
    void bfs(int n, int m, int tx, int ty, vector<vector<int>>& forest){
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            if (cx == tx && cy == ty) 
                break ;
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue ;
                if (vis[ex][ey] || forest[ex][ey] == 0)
                    continue ;
                dis[ex][ey] = dis[cx][cy] + 1;
                vis[ex][ey] = true;
                qx.push(ex), qy.push(ey);
            }
        }
        while (!qx.empty()) 
            qx.pop(), qy.pop();
    }
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest[0][0] == 0)
            return -1;
        int n = forest.size(), m = forest[0].size();
        dis = vector<vector<int>>(n, vector<int>(m, 0));
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (forest[i][j] > 1){
                    mp[forest[i][j]] = make_pair(i, j);
                }
            }
        }
        for (auto k: mp)
            vec.push_back(k.second);
        int t = vec.size(), lstx = 0, lsty = 0, ans = 0;
        for (int i = 0; i < vec.size(); ++i){
            auto p = vec[i];
            qx.push(lstx), qy.push(lsty);
            dis[lstx][lsty] = 0, vis[lstx][lsty] = true;
            bfs(n, m, p.first, p.second, forest);
            if (!vis[p.first][p.second])
                return -1;
            ans += dis[p.first][p.second];
            lstx = p.first, lsty = p.second;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    vis[i][j] = false;
        }
        return ans;
    }
};
```

## 方法二
这种网格图上寻找最短路径的题目有一些专门的算法。在这里介绍 Hadlock 算法。虽然其的最坏时间复杂度仍然是 $O(nm)$，但实际上效率比较高。





# 689
其实就是把两个的情况再叠加一个上去。
```cpp
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1), f1(n + 1, 0), f2(n + 1, 0);
        int ss = 0, maxi = -1, ans = 0;
        for (int i = 0; i < n; ++i)
            ss += nums[i], sum[i + 1] = ss;
        for (int i = 2 * k, lst = k; i <= n; ++i){
            f1[i] = lst;
            if(sum[i - k + 1] - sum[i + 1 - k - k] > sum[lst] - sum[lst - k])
                lst = i - k + 1;
        }
        for (int i = 3 * k, lst = k + k; i <= n; ++i){
            f2[i] = lst;
            if(sum[f1[i + 1 - k]] - sum[f1[i + 1 - k] - k] + sum[i + 1 - k] - sum[i + 1 - k - k] > 
                sum[f1[lst]] - sum[f1[lst] - k] + sum[lst] - sum[lst - k])
                lst = i - k + 1;
            if(sum[i] - sum[i - k] + sum[f2[i]] - sum[f2[i] - k] + sum[f1[f2[i]]] - sum[f1[f2[i]] - k] > maxi)
                maxi = sum[i] - sum[i - k] + sum[f2[i]] - sum[f2[i] - k] + sum[f1[f2[i]]] - sum[f1[f2[i]] - k], ans = i;
        }
        vector<int> rans;
        rans.push_back(f1[f2[ans]] - k);
        rans.push_back(f2[ans] - k);
        rans.push_back(ans - k);
        return rans;
    }
};
```

# 710

## 方法一
显然可以预处理出所有的合法区间，然后在这些区间上用二分找到具体数的位置。时间复杂度是 $O((Q+|B|)\log |B|)$。空间复杂度理论上可以做到常数（我写的比较丑）。。。
```cpp
class Solution {
public:
    int cap, len;
    vector<int> vec, sm;
    Solution(int N, vector<int>& blacklist) {
        cap = N - blacklist.size();
        int cur = 0, n = blacklist.size();
        while (cur < n && blacklist[cur] == cur)
            ++cur;
        if (cur == n) vec.push_back(n), sm.push_back(N - n);
        else{
            int lst = cur;
            for (; cur < n; ){
                vec.push_back(lst), sm.push_back(blacklist[cur] - lst);
                int tmp = blacklist[cur], t = cur;
                while (cur < n && cur - t == blacklist[cur] - tmp)
                    ++cur;
                lst = blacklist[cur - 1] + 1;
            }
            if (lst != N)
                vec.push_back(lst), sm.push_back(N - lst);
        }
        len = sm.size();
        for (int i = 1; i < len; ++i)   
            sm[i] += sm[i - 1];
    }
    
    int pick() {
        int t = rand() % cap + 1;
        int id = lower_bound(sm.begin(), sm.end(), t) - sm.begin();
        return vec[id] + (sm[id] - t);
    }
};
```

## 方法二
更经典的方法是将黑名单中的数映射到 $[N-B, N)$ 这个区间上。这样只需要求 $[0, N - B)$ 中的随机数即可。

# 719
排序后二分
```cpp
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front();
        int n = nums.size();
        while (r > l){
            int mid = (l + r) >> 1;
            int cur = 0, cnt = 0;
            for (int i = 1; i < n; ++i){
                while (cur < i && nums[i] - nums[cur] > mid)
                    ++cur;
                cnt += i - cur;
            }
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
```

# 726
简单的 Parser
```python
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        formula = "(" + formula + ")"
        l = len(formula)

        def mmerge(dst, src, xs):
            for k, v in src.items():
                t = dst.get(k, 0)
                dst[k] = v * xs + t

        def aux(st):
            nonlocal formula, l
            res = {}
            st += 1
            while st < l and formula[st] != ')':
                if formula[st].isupper():
                    j = st + 1
                    while j < l and formula[j].islower():
                        j += 1
                    rp = j
                    while j < l and formula[j].isdigit():
                        j += 1
                    x = 1 if j == rp else int(formula[rp: j])
                    x += res.get(formula[st: rp], 0)
                    res[formula[st: rp]] = x
                    st = j
                elif formula[st] == '(':
                    endp, rres = aux(st)
                    j = endp + 1
                    while j < l and formula[j].isdigit():
                        j += 1
                    xs = 1 if j == endp + 1 else int(formula[endp + 1: j])
                    mmerge(res, rres, xs)
                    st = j
            return st, res

        _, ans = aux(0)
        lis = sorted(ans.keys())
        aans = []
        for s in lis:
            aans.append(s)
            t = ans[s]
            if t > 1:
                aans.append(str(t))

        return "".join(aans)
```

# 765
将一对情侣看作是一个节点，将交错的两对情侣相连边，容易发现一对情侣至多位于一个环上，交换次数等于情侣对数减去环个数。

当然发现了这一点直接交换就行，本质上这是一个沿着环跑的过程，经过的边数和上面的答案是相等的。

下面的代码用的是繁琐的写法。
```cpp
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int to[31][2], ans = 0, n = row.size();
        int f = 0;
        memset(to, -1, sizeof(to));
        for (int i = 0; i < n; i += 2){
            int t1 = row[i] >> 1, t2 = row[i + 1] >> 1;
            if (to[t1][0] < 0) to[t1][0] = t2;
            else to[t1][1] = t2;
            if (to[t2][0] < 0) to[t2][0] = t1;
            else to[t2][1] = t1;
        }
        for (int i = (n >> 1) - 1; i >= 0; --i){
            if (f & (1 << i)) continue;
            int cnt = 0, t = i, fa = -1;
            do{
                f |= (1 << t);
                int tt = (to[t][0] == fa ? to[t][1]: to[t][0]);
                fa = t, t = tt, ++cnt;
            }while (t != i);
            ans += cnt - 1;
        }
        return ans;
    }
};
```

# 768

## 方法一
如果一个前缀排序后和排序后前缀相同，那么就可以分为一段。

从而，如果一个子段排序后和排序后这部分子段相同，那么也可以分为一段。

从而只需要判断，前 $i$ 个数中，如果最大的数排序后恰好在 $i$ 的位置，那么就可以分出一段。时间复杂度 $O(n\log n)$。
```cpp
int f[2005];
class Solution {
public:
    unordered_map<int, int> mp;
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; ++i) f[i] = arr[i];
        sort(f, f + n);
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && f[i] == f[j])
                ++j;
            mp[f[i]] = i, i = j;
        }
        int rtm = -1;
        for (int i = 0; i < n; ++i){
            rtm = max(rtm, mp[arr[i]]), ++mp[arr[i]];
            if (rtm == i) ++ans;
        }
        return ans;
    }
};
```

## 方法二

# 779
水水水 BFS
```cpp
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int cnt1 = 0, a[6], b[6], tot = 0;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j])
                    a[tot++] = board[i][j];
        for (int i = 0; i < 5; ++i)
            for (int j = i + 1; j < 5; ++j)
                if (a[i] > a[j]) ++cnt1;
        if (cnt1 & 1) return -1;

        tot = 0;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                a[tot++] = board[i][j];

        auto pack = [](int *a){ return a[0] * 100000 + a[1] * 10000 + a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[5]; };
        auto unpack = [](int x, int *a){ 
            int tot = 5;
            while (tot >= 0)
                a[tot--] = x % 10, x /= 10;
        };

        unordered_map<int, int> mp;
        queue<int> q;
        int cd = pack(a);
        q.push(cd), mp[cd] = 0;
        for (; ; ){
            int t = q.front(), step = mp[t];
            if (t == 123450) return step;
            q.pop();
            unpack(t, a);
            int pos = 0;
            while (a[pos] != 0) ++pos;

            if (pos != 0 && pos != 3) {
                swap(a[pos], a[pos - 1]);
                t = pack(a);
                if (!mp.count(t))
                    mp[t] = step + 1, q.push(t);
                swap(a[pos], a[pos - 1]);
            }
            if (pos != 2 && pos != 5) {
                swap(a[pos], a[pos + 1]);
                t = pack(a);
                if (!mp.count(t))
                    mp[t] = step + 1, q.push(t);
                swap(a[pos], a[pos + 1]);
            }
            if (pos <= 2) {
                swap(a[pos], a[pos + 3]);
                t = pack(a);
                if (!mp.count(t))
                    mp[t] = step + 1, q.push(t);
                swap(a[pos], a[pos + 3]);
            }else {
                swap(a[pos], a[pos - 3]);
                t = pack(a);
                if (!mp.count(t))
                    mp[t] = step + 1, q.push(t);
                swap(a[pos], a[pos - 3]);
            }
        }
        return 0;
    }
};
```

# 780
辗转相除法。
首先容易知道：如果开始或者结束，数对的两个数相同，那么只有一种可能：整个数对没有经过转换，否则会出现 $0$，而题目中否定了这种情况的出现。
其次，通过观察发现一个重要的结论：如果一个对是 $(a, b)$，那么它之前必然是 $(a, b - a)$ 或者 $(a- b, b)$。且由于整个过程没有出现负数，所以必然是 $a, b$ 中较大者减去较小者，这表明之前两种情况只有一种是正确的。我们可以一直沿着这两种情况中的一种走，直到新的 $a, b$ 的不等关系交换。
而只有当新的 $a'$ 变成 $a\bmod b$（或者新的 $b'$ 变成 $b\bmod a$）这种不等关系才会交换，我们可以利用这一点加速程序。剩下的就是简单的边界条件的判断。
时间复杂度：$O(\log \max\lbrace tx, ty \rbrace)$。
```cpp
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx < sx || ty < sy) return false;
        if (tx > ty) {
            if (sy == ty)    
                return sx >= (tx % ty) && (tx - sx) % sy == 0;
            return reachingPoints(sx, sy, tx % ty, ty);
        }else if (tx < ty){
            if (sx == tx)    
                return sy >= (ty % tx) && (ty - sy) % sx == 0;
            return reachingPoints(sx, sy, tx, ty % tx);
        }else return tx == sx && ty == sy;
    }
};
```

# 786
如果常数足够小可能可以用堆卡过去。
这里考虑二分，判定当前总共有多少个分数小于或等于 $mid$。如果刚好是 $K$ 个就作为答案返回最大的那个分数。
在二分的时候可以发现对于每一个分母，第一个大于 $mid$ 的分子是递增的。可以利用这一点在 $O(n)$ 时间内完成一次二分的判定。所以总的时间复杂度是 $O(nk)$，$k$ 是二分的次数。
```cpp
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double l = 0.0, r = 1.0;
        int n = A.size();
        for (; ; ){
            double mid = (l + r) * 0.5;
            int cnt = 0, p = 0, q = 1;
            for (int i = 1, j = 0; i < n; ++i){
                while (j < n && A[j] <= A[i] * mid)
                    ++j;
                cnt += j;
                if (j > 0 && p * A[i] < q * A[j - 1])
                    p = A[j - 1], q = A[i];
            }
            if (cnt == K) return vector<int>{p, q};
            if (cnt < K) l = mid;
            else r = mid;
        }
        return vector<int>();
    }
};
```

# 793
二分
```cpp
class Solution {
public:
    int preimageSizeFZF(int K) {
        if(K == 0) return 5;
        typedef long long ll;
        auto calc = [](ll x) -> int{
            int res = 0;
            ll cur = 5;
            while(x >= cur)
                res += x / cur, cur *= 5ll;
            return res;
        };
        ll l1 = 0, r1 = K * 5ll;
        while(l1 < r1){
            ll mid = (l1 + r1) >> 1;
            if(calc(mid) < K)
                l1 = mid + 1;
            else r1 = mid;
        }
        ll l2 = 0, r2 = (K + 1) * 5ll;
        while(l2 < r2){
            ll mid = (l2 + r2) >> 1;
            if(calc(mid) <= K)
                l2 = mid + 1;
            else r2 = mid;
        }
        return r2 - r1;
    }
};
```

# 798
用一个数组

```cpp
class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size(), tot = 0;
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; ++i) 
            if (i >= A[i])
                ++cnt[i - A[i]], ++tot;
        int p = 0, maxi = -1;
        for (int i = 0; i < n; ++i){
            if (tot > maxi) maxi = tot, p = i;
            tot -= cnt[i];
            if (i - A[i] >= 0) 
                --cnt[i - A[i]];
            else ++cnt[n + i - A[i]];
            if (A[i] < n) ++tot;
        }
        return p;
    }
};
```

# 805

## 方法一
DP
```cpp
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), sum = 0;
        if(n <= 1) return false;
        for (int i: A)
            sum += i;
        vector<vector<bool> > f((n >> 1) + 1, vector<bool>(1 + (n >> 1) * sum / n, 0));
        f[0][0] = true;
        for (int i = 0; i < n; ++i){
            for (int j = (n >> 1); j >= 1; --j)
                for (int k = (n >> 1) * sum / n; k >= A[i]; --k){
                    if(f[j - 1][k - A[i]])
                        f[j][k] = true;
                }
        }
        for (int i = (n >> 1); i >= 1; --i){
            if(i * sum % n) continue;
            int targ = i * sum / n;
            if(f[i][targ]) return true;
        }
        return false;
    }
};
```

## 方法二
暴搜（好像非常快？）
```cpp

```

# 810
这种博弈论的神奇题目一般都不能大力递推。。。
可以发现，一个平凡的结论是：只要开局异或和是 0，那么先手必胜。然后有一个并不是很平凡的结论：除了这种情况之外，黑板在游戏结束的时候都会被擦干净。
（等待更新）
```cpp
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int a = 0;
        for (int i: nums) a ^= i;
        return (!a) || (nums.size() % 2 == 0);
    }
};
```

# 815
比较简单的 BFS，但是要稍微绕一个弯。

首先对每一个点，记录通过该点的线路。

然后对每一个点记录距离，但是点之间转移是以路线为单位的。从一个点转移到另一个点相当于做了该点到另一个点所在线路上所有点的转移。因此，只要一条线路中的一个点被访问过，这条线路就不需要再访问了。这样应该可以保证线性的时间复杂度。
```cpp
int at[1000005], to[250005], nxt[250005], cnt;
int dis[1000005];
int que[250005], hd, tl;
bool vis[505];
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        cnt = 0;
        for (auto& rt: routes)  
            for (int x: rt)
                at[x + 1] = 0, dis[x + 1] = 0x3f3f3f3f;
        int n = routes.size();
        for (int i = 0; i < n; ++i)  
            for (int x: routes[i])
                to[++cnt] = i, nxt[cnt] = at[x + 1], at[x + 1] = cnt;
        ++S, ++T;
        dis[S] = 0;
        hd = tl = 0;
        que[tl++] = S;
        memset(vis, 0, sizeof(vis));
        while (tl > hd){
            int u = que[hd++];
            if (u == T) return dis[u];
            for (int i = at[u]; i; i = nxt[i]){
                int rt_id = to[i];
                if (vis[rt_id]) continue;
                vis[rt_id] = true;
                for (int v: routes[rt_id])
                    if (dis[v + 1] > dis[u] + 1){
                        dis[v + 1] = dis[u] + 1;
                        que[tl++] = v + 1;
                    }
            }
        }
        if (dis[T] >= 0x3f3f3f3f)
            return -1;
        return dis[T];
    }
};
```

# 827
这题为什么是 Hard？
枚举所有为 0 的点，然后看上下左右是否连接着岛和岛的大小。不断更新答案即可。
注意同一个岛不要重复统计。
```cpp
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size(), tot_island = 0;
        vector<pair<int, int> > q;
        vector<int> siz;
        auto v = [&grid, &q, dx, dy, n, m](int x, int y){
            int hd = q.size(), tl = hd;
            q.push_back(make_pair(x, y)), ++tl;
            grid[x][y] = -1;
            while(tl > hd){
                x = q[hd].first, y = q[hd].second, ++hd;
                for (int i = 0; i < 4; ++i){
                    int cx = x + dx[i], cy = y + dy[i];
                    if(cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
                    if(grid[cx][cy] < 0 || grid[cx][cy] == 0) continue;
                    grid[cx][cy] = -1;
                    q.push_back(make_pair(cx, cy)), ++tl;
                }
            }
        };
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if(grid[i][j] == 1){
                    int lst = q.size();
                    v(i, j), ++tot_island;
                    for (int k = lst; k < q.size(); ++k)
                        grid[q[k].first][q[k].second] = -tot_island;
                    siz.push_back(q.size() - lst), ans = max(ans, siz.back());
                }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if(grid[i][j] == 0){
                    int tot = 1;
                    for (int k = 0; k < 4; ++k){
                        int cx = i + dx[k], cy = j + dy[k];
                        if(cx < 0 || cy < 0 || cx >= n || cy >= m || grid[cx][cy] == 0) continue;
                        if (siz[-grid[cx][cy] - 1] < 0) continue;
                        tot += siz[-grid[cx][cy] - 1], siz[-grid[cx][cy] - 1] = -siz[-grid[cx][cy] - 1];
                    }
                    ans = max(tot, ans);
                    for (int k = 0; k < 4; ++k){
                        int cx = i + dx[k], cy = j + dy[k];
                        if(cx < 0 || cy < 0 || cx >= n || cy >= m || grid[cx][cy] == 0) continue;
                        if (siz[-grid[cx][cy] - 1] > 0) continue;
                        siz[-grid[cx][cy] - 1] = -siz[-grid[cx][cy] - 1];
                    }
                }
        return ans;
    }
};
```

# 828
对于每一个位置的字母计算其的贡献即可。容易发现这个贡献只需要知道其左边和右边第一个相同字母的位置就可以计算出来，所以只需要两个数组记录前一个和前前一个和该字母相同的字母的位置即可。
```cpp
int lst[30], lst2[30];
class Solution {
public:
    int uniqueLetterString(string S) {
        int n = S.length();
        if (!n) return 0;
        memset(lst, -1, sizeof(lst));
        memset(lst2, -1, sizeof(lst2));
        int ans = 0;
        for (int i = 0; i < n; ++i){
            int iid = S[i] - 'A';
            if (lst[iid] >= 0){
                int ll = lst[iid] - lst2[iid];
                int rr = i - lst[iid];
                ans += 1ll * ll * rr % 1000000007;
                if (ans >= 1000000007) ans -= 1000000007;
                lst2[iid] = lst[iid];
            }
            lst[iid] = i; 
        }
        for (int i = 0; i < 26; ++i){
            if (lst[i] >= 0){
                int ll = lst[i] - lst2[i];
                int rr = n - lst[i];
                ans += 1ll * ll * rr % 1000000007;
                if (ans >= 1000000007) ans -= 1000000007;
            }
        }
        return ans;
    }
};
```

# 834
二次扫描和换根法。
```cpp
int to[20005], at[10005], nxt[20005], cnt;
int siz[10005], res[10005], n;
class Solution {
public:
    void dfs(int cur, int fa){
        ++siz[cur];
        for (int i = at[cur]; i != -1; i = nxt[i]){
            int v = to[i];
            if (v == fa) continue;
            dfs(v, cur);
            siz[cur] += siz[v], res[cur] += res[v] + siz[v];
        }
    }
    void dfs2(int cur, int fa){
        for (int i = at[cur]; i != -1; i = nxt[i]){
            int v = to[i];
            if (v == fa) continue;
            res[v] = res[cur] - siz[v] + n - siz[v];
            dfs2(v, cur);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N, cnt = 0;
        for (int i = 0; i < N; ++i) at[i] = -1, siz[i] = res[i] = 0;
        for (vector<int>& e: edges){
            int u = e[0], v = e[1];
            to[cnt] = v, nxt[cnt] = at[u], at[u] = cnt++;
            to[cnt] = u, nxt[cnt] = at[v], at[v] = cnt++;
        }
        vector<int> ans(N, 0);
        dfs(1, 0);
        dfs2(1, 0);
        for (int i = 0; i < N; ++i) ans[i] = res[i];
        return ans;
    }
};
```

# 839
这个题有两种路线。第一种是暴力构图，即二重枚举字符串，然后看两个字符串之间有没有边连接。第二种是暴力连边，对每一个字符串枚举交换的两个字符，然后看交换后能不能和另外的某个字符串匹配。
最后找联通块用并查集即可。第一种做法的时间复杂度是 $O(n^2l)$，第二种是 $O(l^2n)$（使用 Hash Table 和字符串 Hash）。
下面给的代码是第二种做法的，亲测常数比较大。所以还是比较建议第一种。
```cpp
class Solution {
public:
    vector<int> fa, siz;
    vector<unsigned long long> h, hh;
    int Find(int x){
        return (fa[x] == x ? x: (fa[x] = Find(fa[x])));
    }
    void Union(int x, int y){
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return ;
        if (siz[fx] > siz[fy]) siz[fx] += siz[fy], fa[fy] = fx;
        else siz[fy] += siz[fx], fa[fx] = fy;
    }
    int numSimilarGroups(vector<string>& A) {
        unordered_map<unsigned long long, int> mp;
        int n = A.size(), l = A[0].length(), ans = 0;
        fa = vector<int>(n, 0);
        siz = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) 
            fa[i] = i, siz[i] = 1;
        h.push_back(1);
        for (int i = 1; i <= l; ++i)
            h.push_back(h.back() * 9982443ull);
        for (int i = 0; i < n; ++i) {
            unsigned long long h1 = 0;
            for (int j = 0; j < l; ++j)
                h1 = h1 * 9982443ull + A[i][j];
            if (mp.count(h1)) Union(i, mp[h1]);
            else mp[h1] = i; 
            hh.push_back(h1);
        }    
        for (int i = 0; i < n; ++i) {
            bool flag = true;
            for (int j = 0; j < l; ++j)
                for (int k = 0; k < j; ++k) 
                    if (A[i][j] != A[i][k]){
                        unsigned long long h1 = hh[i];
                        h1 -= A[i][j] * h[l - j - 1], h1 -= A[i][k] * h[l - k - 1];
                        h1 += A[i][k] * h[l - j - 1], h1 += A[i][j] * h[l - k - 1];
                        if (mp.count(h1))
                            Union(i, mp[h1]), flag = false;
                    }
        }
        for (int i = 0; i < n; ++i) {
            Find(i);
            if (fa[i] == i) ++ans;            
        }
        return ans;
    }
};
```

# 847

## 方法一
朴素的状态压缩 DP。
```cpp
int f[4100][12], dis[12][12];
class Solution {
public:
    inline int lowbit(int x){ return x & (-x); }
    unordered_map<int, int> mp;
    void init(int n){
        memset(f, 0x3f, sizeof(f));
        memset(dis, 0x3f, sizeof(dis));
        for (int i = 0; i < n; ++i)
            mp[1 << i] = i, f[1 << i][i] = 0;
    }
    void dfs(int di, int dj, vector<vector<int>>& graph){
        if (f[di][dj] < 0x3f3f3f3f) return ;
        int dii = di - (1 << dj);
        for (int i = dii, j = lowbit(i); i > 0; i -= j, j = lowbit(i)){
            int id = mp[j];
            dfs(dii, id, graph);
            f[di][dj] = min(f[dii][id] + dis[id][dj], f[di][dj]);
        }
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(); 
        init(n);
        for (int i = 0; i < n; ++i) {
            dis[i][i] = 0;
            for (int v: graph[i])
                dis[i][v] = dis[v][i] = 1;
        }
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i) 
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i)
            dfs((1 << n) - 1, i, graph), ans = min(ans, f[(1 << n) - 1][i]);
        return ans;
    }
};
```

## 方法二



# 850
矩形面积并模板题。注意这并不是一般意义上的区间型线段树，而是正宗的**线段树**，所以有的地方写法稍微有一些不同。
```cpp
int seg[1005], mini[1005], yy[205], id[205], sum[205];
int siz, _a, _b, val;
pair<int, int> pp[205];
void maintain(int id, int l, int r){
    if (mini[id] > 0) seg[id] = sum[r] - sum[l - 1];
    else seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
void update(int id, int l, int r){
    if (l > _b || r < _a) return ;
    if (l >= _a && r <= _b){
        mini[id] += val;
        maintain(id, l, r);
        return ;
    }
    update(id << 1, l, (l + r) >> 1);
    update(id << 1 | 1, (l + r + 1) >> 1, r);
    maintain(id, l, r);
}
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        for (int i = 0; i < n; ++i){
            pp[i << 1].first = rectangles[i][0], 
            pp[i << 1].second = i + 1,
            pp[i << 1 | 1].first = rectangles[i][2], 
            pp[i << 1 | 1].second = -i - 1;
            yy[i << 1] = rectangles[i][1], yy[i << 1 | 1] = rectangles[i][3];
        }
        sort(pp, pp + n + n);
        sort(yy, yy + n + n);
        for (int i = 0; i < n; ++i){
            id[i << 1] = lower_bound(yy, yy + n + n, rectangles[i][1]) - yy, 
            id[i << 1 | 1] = lower_bound(yy, yy + n + n, rectangles[i][3]) - yy;
        }
        sum[0] = 0;
        for (int i = 1; i < n + n; ++i)
            sum[i] = sum[i - 1] + yy[i] - yy[i - 1];
        for (siz = 1; siz < n + n - 1; siz <<= 1)
            ;

        memset(seg, 0, sizeof(seg));
        memset(mini, 0, sizeof(mini));
        long long ans = 0;
        int lst = pp[0].first;
        for (int i = 0; i < n + n; ++i){
            int xx = pp[i].first, pos = pp[i].second;
            int rid = (pos < 0 ? -pos: pos) - 1;
            _a = id[rid << 1] + 1, _b = id[rid << 1 | 1];
            ans += 1ll * seg[1] * (xx - lst);
            if (pos > 0){
                val = 1, update(1, 1, siz);
            }else {
                val = -1, update(1, 1, siz);
            }
            lst = xx;
        } 
        return ans % 1000000007;
    }
};
```

# 854
暴搜？
```cpp
class Solution {
public:
    int n, ans;
    void dfs(string& A, string& B, int st, int cur){
        if(cur == n){
            ans = min(ans, st);
            return ;
        }
        while(cur < n && A[cur] == B[cur])
            ++cur;
        if(cur == n){
            ans = min(ans, st);
            return ;
        }

        for (int i = cur + 1; i < n && st < ans - 1; ++i){
            if(A[i] == B[cur]){
                swap(A[i], A[cur]), dfs(A, B, st + 1, cur + 1), 
                swap(A[i], A[cur]);
            }
        }
    }
    int kSimilarity(string A, string B) {
        n = A.length();
        ans = n;
        dfs(A, B, 0, 0);
        return ans;
    }
};
```

# 862

## 方法一
保存前缀和，然后按前缀和从小到大将下标插入平衡树，查询当前最接近当前下标

# 864

## 方法一
对于每一种（持有钥匙情况，当前出发位置的钥匙）跑一次 BFS，然后大力转移。时间复杂度 $O(RCA2^A)$。
```cpp
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int dis[65][6][32][32], pos[10][2], logg[65];
int f[65][6];
bool vis[65][6];
class Solution {
public:
    queue<int> qx, qy;
    void bfs(vector<string>& grid, int sx, int sy, int di, int dj){
        int n = grid.size(), m = grid[0].size();
        qx.push(sx), qy.push(sy);
        dis[di][dj][sx][sy] = 0;
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            int step = dis[di][dj][cx][cy];
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue;
                if (grid[ex][ey] == '#' || dis[di][dj][ex][ey] < 0x3f3f3f3f) continue;
                if (isupper(grid[ex][ey]) && ((1 << (grid[ex][ey] - 'A')) & di) == 0)
                    continue;
                dis[di][dj][ex][ey] = step + 1;
                qx.push(ex), qy.push(ey);
            }
        }
    }
    int dfs(int di, int dj){
        if (vis[di][dj]) return f[di][dj];
        if ((di & (-di)) == di) f[di][dj] = dis[0][0][pos[dj][0]][pos[dj][1]];
        else {
            int p = (1 << dj);
            for (int i = di - p, j = (i & (-i)); i > 0; i -= j, j = (i & (-i)))
                f[di][dj] = min(f[di][dj], dfs(di - p, logg[j]) + dis[di - p][logg[j]][pos[dj][0]][pos[dj][1]]);
        }
        vis[di][dj] = true;
        return f[di][dj];
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        int sx, sy;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if (islower(grid[i][j]))
                    pos[grid[i][j] - 'a'][0] = i, 
                    pos[grid[i][j] - 'a'][1] = j, ++cnt;
                else if (grid[i][j] == '@')
                    sx = i, sy = j;
            }
        int lim = (1 << cnt);
        logg[1] = 0, logg[2] = 1, logg[4] = 2, 
        logg[8] = 3, logg[16] = 4, logg[32] = 5;

        memset(dis[0][0], 0x3f, sizeof(dis[0][0]));
        bfs(grid, sx, sy, 0, 0);
        memset(f, 0x3f, sizeof(f));
        memset(vis, 0, sizeof(vis));

        for (int i = 1; i < lim - 1; ++i){
            for (int j = i, k = (j & (-j)); j > 0; j -= k, k = (j & (-j))){
                int id = logg[k];
                memset(dis[i][id], 0x3f, sizeof(dis[i][id]));
                bfs(grid, pos[id][0], pos[id][1], i, id);
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < cnt; ++i)   
            ans = min(ans, dfs(lim - 1, i)); 
        return (ans == 0x3f3f3f3f ? -1: ans);
    }
};
```

## 方法二



# 871

比较简单的堆题目。我们可以枚举关键点（即所有加油站+目的地），然后看从前一个点到这里汽油够不够，不够的话看看之前有哪些加油站没有加过油，从中选取量最多的加油站加一次油（用堆维护），一直加到够或者没有可用加油站为止。
```cpp
class Solution {
public:
    priority_queue<int> pq;
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        vector<pair<int, int> > vec;
        for (auto& p: stations)
            vec.push_back(make_pair(p[0], p[1]));
        sort(vec.begin(), vec.end());
        int lst = 0, ans = 0;
        for (auto& p: vec)  {
            int pos = p.first, f = p.second;
            while (startFuel < pos - lst && !pq.empty()){
                int tt = pq.top();
                startFuel += tt;
                pq.pop();
                ++ans;
            }
            if (startFuel < pos - lst) return -1;
            startFuel -= (pos - lst);
            lst = pos;
            pq.push(f);
        }
        while (startFuel < target - lst && !pq.empty()){
            int tt = pq.top();
            startFuel += tt;
            pq.pop();
            ++ans;
        }
        if (startFuel < target - lst) return -1;
        return ans;
    }
};
```

# 878
简单数论题
```cpp
class Solution {
public:
    int gcd(int a, int b){
        return (!b) ? a: gcd(b, a % b);
    }
    int nthMagicalNumber(int N, int A, int B) {
        int lcm = A * B / gcd(A, B);
        int r = lcm / A + lcm / B - 1;
        int ans = 1ll * (N / r) * lcm % 1000000007;
        N %= r;
        if(N){
            int j = A, k = B, res;
            for (int i = 0; i < N; ++i){
                if(j <= k) res = j, j += A;
                else res = k, k += B;
            }
            ans = (ans + res) % 1000000007;
        }
        return ans;
    }
};
```

# 879
简单的二维背包。对于大于 $P$ 的部分单独设一个 $g(i)$，记为所选择人数为 $i$ 时，利润大于 $P$ 的情况数目。其他同二维背包。
```cpp
int f[105][105], g[105];
class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		f[0][0] = 1;
		int M = 1000000007, n = group.size();
		for (int i = 0; i < n; ++i){
			for (int j = G; j >= group[i]; --j){
				for (int p = max(0, P - profit[i] + 1); p <= P; ++p)
					g[j] = (g[j] + f[j - group[i]][p] >= M ? g[j] + f[j - group[i]][p] - M: g[j] + f[j - group[i]][p]);
				g[j] = (g[j] + g[j - group[i]] >= M ? g[j] + g[j - group[i]] - M: g[j] + g[j - group[i]]);
				for (int p = P; p >= profit[j]; --p)	
					f[j][p] = (f[j][p] + f[j - group[i]][p - profit[i]] >= M ?
						f[j][p] + f[j - group[i]][p - profit[i]] - M: f[j][p] + f[j - group[i]][p - profit[i]]);
			}
		}
		int ans = 0;
		for (int i = 0; i <= G; ++i)
			ans = (ans + f[i][P] >= M ? ans + f[i][P] - M: ans + f[i][P]), 
			ans = (ans + g[i] >= M ? ans + g[i] - M: ans + g[i]);
		return ans;
    }
};
```

# 882
不知道这个题是我的 Dijkstra 太脑瘫还是怎么

# 895
按照频率维护栈即可，按栈里保存的元素顺序pop相应的结果
```python
class FreqStack:

    def __init__(self):
        self.freq = {}
        self.maxi = 0
        self.stacks = {}

    def push(self, x: int) -> None:
        if not x in self.freq:
            self.freq[x] = 1
        else:
            self.freq[x] += 1
        f = self.freq[x]
        if f > self.maxi:
            self.maxi = f
            if not self.maxi in self.stacks:
                self.stacks[self.maxi] = []
        self.stacks[f].append(x)

    def pop(self) -> int:
        x = self.stacks[self.maxi].pop()
        self.freq[x] -= 1
        if not self.stacks[self.maxi]:
            self.maxi -= 1
        return x
```

# 906

## 方法一
打表，拿 Python 打也就 5 分钟不到
```cpp
class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        long long a[] = {1ll, 4ll, 9ll, 121ll, 484ll, 10201ll, 12321ll, 14641ll, 40804ll, 44944ll, 1002001ll, 1234321ll, 4008004ll, 100020001ll, 102030201ll, 104060401ll, 121242121ll, 123454321ll, 125686521ll, 400080004ll, 404090404ll, 10000200001ll, 10221412201ll, 12102420121ll, 12345654321ll, 40000800004ll, 1000002000001ll, 1002003002001ll, 1004006004001ll, 1020304030201ll, 1022325232201ll, 1024348434201ll, 1210024200121ll, 1212225222121ll, 1214428244121ll, 1232346432321ll, 1234567654321ll, 4000008000004ll, 4004009004004ll, 100000020000001ll, 100220141022001ll, 102012040210201ll, 102234363432201ll, 121000242000121ll, 121242363242121ll, 123212464212321ll, 123456787654321ll, 400000080000004ll, 10000000200000001ll, 10002000300020001ll, 10004000600040001ll, 10020210401202001ll, 10022212521222001ll, 10024214841242001ll, 10201020402010201ll, 10203040504030201ll, 10205060806050201ll, 10221432623412201ll, 10223454745432201ll, 12100002420000121ll, 12102202520220121ll, 12104402820440121ll, 12122232623222121ll, 12124434743442121ll, 12321024642012321ll, 12323244744232321ll, 12343456865434321ll, 12345678987654321ll, 40000000800000004ll, 40004000900040004ll};
        long long l = stoll(L), r = stoll(R);
        int ans = 0;
        for (int i = 0; i < 70; ++i)
            if (a[i] <= r && a[i] >= l)
                ++ans;
        return ans;
    }
};
```

## 方法二
使用数学方法。

# 940
设 $f(i)$ 为以 $i$ 为结尾的所有子序列的数目，则有：
$$
f(i) = \sum_{j=0}^{i-1} f(j)
$$
考虑去重。设在 $i$ 左边，离 $i$ 最近的，和 $i$ 是相同字符的位置为 $k$。显然 $f(i)$ 包含了所有 $f(k)$ 的情况，此时令 $f(k)=0$ 即可。因为我们在 $k$ 处也这么做了，所以就不用更进一步考虑 $k$ 左边的情况。

用一个值维护右式即可。时间复杂度为 $O(n)$。
```cpp
int f[2005], ssm, nxt[2005], lst[26];
class Solution {
public:
    int distinctSubseqII(string S) {
        memset(f, 0, sizeof(f));
        memset(lst, 0, sizeof(lst));
        const int M = 1000000007;
        int l = S.length();
        f[0] = 1, ssm = 1;
        for (int i = 1; i <= l; ++i){
            if (!lst[S[i - 1] - 'a'])
                lst[S[i - 1] - 'a'] = i, nxt[i] = 0;
            else 
                nxt[i] = lst[S[i - 1] - 'a'], lst[S[i - 1] - 'a'] = i;
        }
        for (int i = 1; i <= l; ++i){
            f[i] = ssm, ssm <<= 1;
            if (ssm >= M) ssm -= M;
            if (nxt[i] > 0){
                ssm += (M - f[nxt[i]]);
                if (ssm >= M) ssm -= M;                
            } 
        }
        return ssm;
    }
};
```

# 943
状压 DP。考虑字符串相拼接，去掉重合的部分即可。

注意在求两个字符串相重部分的时候可以用 KMP 的方法优化到线性。这里没加。
```cpp
int f[4100][12], bef[4100][12], dis[12][12];
unordered_map<int, int> mp;
class Solution {
public:
    inline int lowbit(int x){ return x & (-x); }
    void dfs(int di, int dj){
        if (f[di][dj] < 0x3f3f3f3f) return ;
        int dii = di - (1 << dj);
        for (int i = dii, j = lowbit(i); i > 0; i -= j, j = lowbit(i)){
            int id = mp[j];
            dfs(dii, id);
            if (f[dii][id] + dis[id][dj] < f[di][dj])
                f[di][dj] = f[dii][id] + dis[id][dj], bef[di][dj] = id;
        }
    }
    string shortestSuperstring(vector<string>& A) {
        memset(f, 0x3f, sizeof(f));
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            int li = A[i].length();
            for (int j = 0; j < n; ++j){
                if (i == j) continue;
                int maxlen = min(A[i].length(), A[j].length()), k = maxlen;
                for (; k >= 1; --k){
                    bool flag = true;
                    for (int u = 0; u < k; ++u){
                        if (A[i][li - k + u] != A[j][u]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) break;
                }
                dis[i][j] = A[j].length() - k;
            }
        }
        for (int i = 0; i < n; ++i)
            mp[1 << i] = i;
        for (int i = 0; i < n; ++i) 
            f[1 << i][i] = A[i].length(), bef[1 << i][i] = 0;
        for (int i = 0; i < n; ++i)
            dfs((1 << n) - 1, i);
        int ans[12], minp = 0;
        for (int i = 1; i < n; ++i) 
            if (f[(1 << n) - 1][i] < f[(1 << n) - 1][minp])
                minp = i;
        for (int i = minp, j = (1 << n) - 1, k = n - 1; j > 0; --k)
            ans[k] = i, i = bef[j][i], j -= (1 << ans[k]);
        string anss = A[ans[0]];
        for (int i = 1; i < n; ++i)
            anss += A[ans[i]].substr(A[ans[i]].length() - dis[ans[i - 1]][ans[i]]);
        return anss;
    }
};
```

# 952
预处理数组 $v$，其中 $v[i]$ 保存的为 $A$ 中大小为 $i$ 的数的下标，未出现记为 $-1$。然后使用埃氏筛法，利用 $v$ 将被筛掉的数用并查集相连。

时间复杂度 $O(n\log \log n)$，即与埃氏筛同阶。
```cpp
class Solution {
public:
    vector<int> fa, siz;
    int v[100005], ans;
    bool vis[100005];
    int Find(int x){
        return (x == fa[x] ? x: (fa[x] = Find(fa[x])));
    }
    void Union(int x, int y){
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return ;
        if (siz[fx] > siz[fy]){
            fa[fy] = fx, siz[fx] += siz[fy], ans = max(ans, siz[fx]);
        }else {
            fa[fx] = fy, siz[fy] += siz[fx], ans = max(ans, siz[fy]);
        }
    }
    int largestComponentSize(vector<int>& A) {
        int n = A.size(), maxi = -1;
        memset(v, -1, sizeof(v));
        memset(vis, 0, sizeof(vis));
        fa = vector<int>(n, 0);
        siz = vector<int>(n, 1);
        ans = 0;
        for (int i = 0; i < n; ++i)
            fa[i] = i, v[A[i]] = i, maxi = max(maxi, A[i]);
        for (int i = 2; i <= maxi; ++i){
            if (!vis[i]){
                int t = -1;
                if (v[i] >= 0) t = v[i];
                for (int j = i + i; j <= maxi; j += i){
                    if (v[j] >= 0) {
                        if (t < 0) t = v[j];
                        else Union(t, v[j]);
                    }
                    vis[j] = true;
                }
            }
        }
        return ans;
    }
};
```

# 960
扩展版本的 LIS，**把删除转换为选取最多的列**即可。
```cpp
int f[105];
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        memset(f, 0, sizeof(f));
        int l = A[0].length(), ans = 1;
        f[0] = 1;
        for (int i = 1; i < l; ++i){
            f[i] = 1;
            for (int j = 0; j < i; ++j){
                bool flag = true;
                for (auto& s: A)
                    if (s[i] < s[j]){
                        flag = false;
                        break;
                    }
                if (flag) f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
        }
        return l - ans;
    }
};
```

# 975
首先我们可以反向考虑：从一个点跳若干次到末尾，等价于从末尾跳若干次到该点。之所以可以这么等效是因为对前者而言，如果从 $i$ 到 $j$ 是奇数次，那么 $j$ 到 $i$ 也是奇数次；从 $i$ 到 $j$ 是偶数次，那么 $j$ 到 $i$ 也是偶数次。

然后构图，对每一个下标建立两个点 $(i, 0)$ 或者 $(i, 1)$，$(i, 0)$ 表示从数组末尾跳到 $i$ 时，总步数为偶数这个状态；$(i,1)$ 表示从数组末尾跳到 $i$ 时，总步数为奇数这个状态。有了点，我们可以考虑边，对于 $(i, 1)$，我们如果能求出在 $i$ 位置奇数次跳的目标位置 $t$ 的话，我们就可以连一条 $(t, 0)$ 到 $(i, 1)$ 的有向边（因为这时跳到 $t$ 时

再考虑边，我们可以使用一个经典的技巧


容易发现，对每一个点而言，如果 $(i, 0)$ 通过某种方式


容易发现只要处理出从每一个点出发，奇数次跳或者偶数次跳

（草无法组织语言）

```cpp
int bef[100005], aft[100005];
int at[100005], to[100005], nxt[100005], cnt;
int at2[20005], to2[40005], nxt2[40005], cnt2;
bool w[40005];
bool vis[20005][2];
class Solution {
public:
    void dfs(int cur, int b){
        for (int i = at2[cur]; i; i = nxt2[i]){
            if (w[i] != b) continue;
            int v = to2[i];
            if (vis[v][b]) continue;
            vis[v][b] = true;
            dfs(v, b ^ 1);
        }
    }
    int oddEvenJumps(vector<int>& A) {
        cnt = cnt2 = 0;
        memset(at, 0, sizeof(at));
        memset(at2, 0, sizeof(at2));
        memset(vis, 0, sizeof(vis));
        int n = A.size(), maxi = 0;
        for (int i = n - 1; i >= 0; --i){
            maxi = max(maxi, A[i] + 1);
            to[++cnt] = i + 1, nxt[cnt] = at[A[i] + 1], at[A[i] + 1] = cnt;
        }
        int lst = 0;
        for (int i = 1; i <= maxi; ++i){
            if (!at[i]) continue;
            if (lst) 
                bef[i] = lst, aft[lst] = i;
            else bef[i] = 0;
            lst = i;
        }
        aft[lst] = 0;
        for (int i = 0; i < n; ++i){
            int v = A[i] + 1;
            at[v] = nxt[at[v]];         // 删除自己
            if (at[v]){
                int vv = to[at[v]];
                to2[++cnt2] = i + 1, w[cnt2] = 1, nxt2[cnt2] = at2[vv], at2[vv] = cnt2;
                to2[++cnt2] = i + 1, w[cnt2] = 0, nxt2[cnt2] = at2[vv], at2[vv] = cnt2;
            }else {
                if (aft[v] && at[aft[v]]){
                    int vv = to[at[aft[v]]];
                    to2[++cnt2] = i + 1, w[cnt2] = 1, nxt2[cnt2] = at2[vv], at2[vv] = cnt2;
                    bef[aft[v]] = bef[v];
                }
                if (bef[v] && at[bef[v]]){
                    int vv = to[at[bef[v]]];
                    to2[++cnt2] = i + 1, w[cnt2] = 0, nxt2[cnt2] = at2[vv], at2[vv] = cnt2;
                    aft[bef[v]] = aft[v];
                }
            }
        }
        int ans = 0;
        dfs(n, 1), dfs(n, 0);
        for (int i = 1; i < n; ++i) 
            if (vis[i][1])
                ++ans;
        return ans + 1;
    }
};
```

# 982
小暴力
```cpp
class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size(), maxi = 1, ans = 0;
        vector<int> cnt(65536, 0);
        for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j) 
                cnt[A[i] & A[j]]++;
			while(maxi <= A[i]) maxi <<= 1;
		}
        for (int i = 0; i < n; ++i){
			for (int j = 0; j < maxi; ++j){
				if(A[i] & j) continue;
				ans += cnt[j];
			}
		}
		return ans;
    }
};
```

# 995
写了一个十分睿智的树状数组。。。
其实根本不需要，只要记录前缀和就行了。
```cpp
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size(), ans = 0;
        vector<int> ss(n + 1, 0);
        for (int i = 0; i <= n - K; ++i){
            int res = (ss[i] - ss[max(i - K + 1, 0)] + A[i]) % 2;
            if(!res){
                ans++;
                ss[i + 1]++;
            }
            ss[i + 1] += ss[i];
        }
        for (int i = n - K + 1; i < n; ++i){
            int res = (ss[i] - ss[max(i - K + 1, 0)] + A[i]) % 2;
            if(!res) return -1;
            ss[i + 1] = ss[i];
        }
        return ans;
    }
};
```

# 996
小暴搜，先记录所有可以结成的对，然后搜索
```cpp
class Solution {
public:
    vector<vector<bool> > f;
    int ans;
    void dfs(int used, int cur, int lst, vector<int>& A){
        int n = A.size();
        if(cur == n){
            ans++;
            return ;
        }
        for (int i = 0; i < n; ){
            int j = i;
            while(j < n && A[i] == A[j])
                ++j;
            while(i < j && ((1 << i) & used))
                ++i;
            if(i == j) continue;
            if(!f[lst][i]){
                i = j;
                continue;
            }
            dfs(used | (1 << i), cur + 1, i, A);
            i = j;
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        f = vector<vector<bool> >(n, vector<bool>(n, 0));
        auto judge = [](int x){
            int sqt = (int)floor(sqrt(x) + 0.5);
            if(sqt * sqt > x) sqt--;
            return sqt * sqt == x;
        };
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j){
                if(judge(A[i] + A[j]))
                    f[i][j] = f[j][i] = true;
            }
        ans = 0;
        for (int i = 0; i < n; ){
            int j = i;
            while(j < n && A[i] == A[j])
                ++j;
            dfs(1 << i, 1, i, A);
            i = j;
        }    
        return ans;
    }
};
```

# 1000
类似于原版的石子归并，其实就是原来的两部分合并成一部分成了 K 部分合并成一部分。只需要递归的做就行了。
时间复杂度好像是 $O(n^3k)$？
```cpp
class Solution {
public:
    vector<vector<int>> f;
    vector<int> sum;
    int KK;
    void dfs(int k, int l, int r, int acc, int& res){
        if (k == 1){
            acc += sum[r + 1] - sum[l] + f[l][r];
            res = min(res, acc);
            return ;
        }
        for (int t = 0; t + k - 1 <= r - l; t += (KK - 1))
            dfs(k - 1, l + t + 1, r, acc + sum[l + t + 1] - sum[l] + f[l][l + t], res);
    }
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n - 1) % (K - 1)) return -1;
        f = vector<vector<int>>(n, vector<int>(n, 0x3f3f3f3f));
        sum = vector<int>(n + 1, 0);
        KK = K;
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + stones[i], 
            f[i][i] = 0; 
        for (int i = K - 1; i < n; i += K - 1)
            for (int j = 0; j + i < n; ++j)
                dfs(K, j, j + i, 0, f[j][j + i]);
        return f[0][n - 1];
    }
};
```

# 1001
用 multiset 记录横纵斜坐标，用 set 维护当前亮的灯的集合即可。
```cpp
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
class Solution {
public:
    unordered_multiset<int> hor, ver, xie1, xie2;
    set<pair<int, int>> st;
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int q = queries.size(), left = lamps.size();
        vector<int> ans;
        ans.reserve(q);
        for (vector<int>& pos: lamps){
            hor.insert(pos[0]), ver.insert(pos[1]), 
            xie1.insert(pos[0] + pos[1]), xie2.insert(pos[0] - pos[1]);
            st.insert(make_pair(pos[0], pos[1]));
        }
        for (vector<int>& pos: queries){
            int x = pos[0], y = pos[1];
            if (hor.count(x) || ver.count(y) || xie1.count(x + y) || xie2.count(x - y))
                ans.push_back(1);
            else ans.push_back(0);

            pair<int, int> pp(x, y);
            if (st.count(pp)) 
                st.erase(pp), hor.erase(hor.find(x)), ver.erase(ver.find(y)), 
                xie1.erase(xie1.find(x + y)), xie2.erase(xie2.find(x - y)), --left;
            for (int i = 0; i < 8; ++i){
                pp.first += dx[i], pp.second += dy[i], x += dx[i], y += dy[i];
                if (st.count(pp))
                    st.erase(pp), hor.erase(hor.find(x)), ver.erase(ver.find(y)), 
                    xie1.erase(xie1.find(x + y)), xie2.erase(xie2.find(x - y)), --left;
                pp.first -= dx[i], pp.second -= dy[i], x -= dx[i], y -= dy[i];
            }
            if (!left) break;
        } 
        while (ans.size() < queries.size())
            ans.push_back(0);
        return ans;
    }
};
```

# 1032
对每一个字符串反转，然后建立 Trie。每次询问都查询一次即可。

这题用 AC 自动机好像也能做。

另外，这题实际的数据量是真的小。。。看起来非常吓人，实际上 Trie 最多开 200000 就够了。。。

```cpp
int trie[200005][27], cnt;
bool ok[200005];
class StreamChecker {
public:
    vector<char> vec;
    StreamChecker(vector<string>& words) {
        memset(trie, 0, sizeof(trie));
        memset(ok, 0, sizeof(ok));
        cnt = 1;
        for (string& s: words){
            int l = s.length(), p = 1;
            for (int i = l - 1; i >= 0; --i){
                if (!trie[p][s[i] - 'a'])   
                    trie[p][s[i] - 'a'] = ++cnt;
                p = trie[p][s[i] - 'a'];
            }
            ok[p] = true;
        }
    }
    
    bool query(char letter) {
        vec.push_back(letter);
        int p = 1, cur = vec.size() - 1;
        while (p && cur >= 0 && !ok[p])
            p = trie[p][vec[cur] - 'a'], --cur;
        return p && ok[p];
    }
};
```

# 1036

## 方法一
如果走不出，只有两种可能：源点被障碍与边界包围，或者目的地被障碍与边界包围。

所以只要以这两个点为中心做两次 BFS 即可。只要能够走出 201（及以上）的距离，那么就表示没有被包围。

当然还有一种可能就是两个点被包围在同一个区域里，这种要特殊判断。
```cpp
bool vis[420][420];
class Solution {
public:
    set<pair<int, int> > st;
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for (auto &vec: blocked)    {
            st.insert(make_pair(vec[0], vec[1]))  ;
        }
        queue<int> qx, qy, step;
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

        int maxi_step = 0;
        memset(vis, 0, sizeof(vis));
        qx.push(source[0]), qy.push(source[1]), step.push(0);
        vis[0 + 205][0 + 205] = true;
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front(), curs = step.front();
            qx.pop(), qy.pop(), step.pop();
            if (cx == target[0] && cy == target[1]) return true;
            if (curs == 205) continue;
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ey < 0 || ex >= 1000000 || ey >= 1000000)
                    continue;
                if (st.count(make_pair(ex, ey))) continue;
                if (vis[ex - source[0] + 205][ey - source[1] + 205])
                    continue;
                vis[ex - source[0] + 205][ey - source[1] + 205] = true;
                maxi_step = max(maxi_step, curs + 1);
                qx.push(ex), qy.push(ey), step.push(curs + 1);
            }
        }
        if (maxi_step < 205) return false;

        maxi_step = 0;
        memset(vis, 0, sizeof(vis));
        qx.push(target[0]), qy.push(target[1]), step.push(0);
        vis[0 + 205][0 + 205] = true;
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front(), curs = step.front();
            qx.pop(), qy.pop(), step.pop();
            if (curs == 205) continue;
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ey < 0 || ex >= 1000000 || ey >= 1000000)
                    continue;
                if (st.count(make_pair(ex, ey))) continue;
                if (vis[ex - target[0] + 205][ey - target[1] + 205])
                    continue;
                vis[ex - target[0] + 205][ey - target[1] + 205] = true;
                maxi_step = max(maxi_step, curs + 1);
                qx.push(ex), qy.push(ey), step.push(curs + 1);
            }
        }
        if (maxi_step < 205) return false;
        return true;
    }
};
```

## 方法二
上面那种方法比较憨。我们可以对所有行和列进行离散化，只保留源点、目标点或者障碍存在的行和列，把原本的大迷宫压缩成为一个几百大小的小迷宫。这样就很容易求解了。

# 1044

## 方法一
暴力 Hash
```cpp
class Solution {
public:
    string longestDupSubstring(string S) {
        int n = S.size();
        unsigned long long P = 1000007;
        vector<unsigned long long> h1(n + 1, 0), h2(n + 1, 0);
        h1[0] = 1;
        for (int i = 1; i <= n; ++i)    
            h1[i] = h1[i - 1] * P;
        for (int i = 1; i <= n; ++i)
            h2[i] = h2[i - 1] * P + S[i - 1];
        int l = 0, r = n - 1, ans = 0;
        unordered_set<unsigned long long> st;
        while (r > l){
            int mid = (l + r + 1) >> 1;
            st.clear();
            bool flag = false;
            for (int i = mid; i <= n; ++i){
                unsigned long long str = h2[i] - h2[i - mid] * h1[mid];
                if (st.count(str)) {
                    flag = true, ans = i - mid;
                    break;
                }
                st.insert(str);
            }
            if (flag) l = mid;
            else r = mid - 1;
        }
        if (!l) return string("");
        return S.substr(ans, l);
    }
};
```

## 方法二
后缀数组的经典应用。

# 1074
一般这样的问题都是考虑降维打击。也就是通过枚举某一维，将二维问题变换到一维上去解决。
这个题目也是，先尝试枚举矩形的上下两条边，然后可以用矩阵前缀和在常数时间内算出两条边之间的和。这样就变成了一维意义上的找和为目标值的问题。
时间复杂度 $O(n^3)$（设 $n$ 和 $m$ 同阶）。
```cpp
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] = sum[i][j + 1] + matrix[i][j];
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = i; j <= n; ++j){
                mp.clear();
                mp[0] = 1;
                int ssm = 0;
                for (int k = 1; k <= m; ++k){
                    ssm += sum[j][k] - sum[i - 1][k];
                    if (mp.count(ssm - target)) 
                        ans += mp[ssm - target];
                    if (mp.count(ssm))
                        ++mp[ssm];
                    else mp[ssm] = 1;
                }
            }
        }
        return ans;
    }
};
```

# 1092
其实就是 LCS 换了个皮。记录一下转移的来源，然后在最后还原这个超序列即可。
注意最后的超序列是反的，要反转一下。
```cpp
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0x3f3f3f3f));
        vector<vector<char>> bef(n + 1, vector<char>(m + 1, 0));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i)
            f[i][0] = i, bef[i][0] = 1;
        for (int i = 1; i <= m; ++i)
            f[0][i] = i, bef[0][i] = 3;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                if (str1[i - 1] == str2[j - 1]){
                    f[i][j] = f[i - 1][j - 1] + 1, bef[i][j] = 2;
                }else{
                    if (f[i][j - 1] > f[i - 1][j])
                        f[i][j] = f[i - 1][j] + 1, bef[i][j] = 1;
                    else 
                        f[i][j] = f[i][j - 1] + 1, bef[i][j] = 3;
                }
            }
        }
        string ans;
        for (int i = n, j = m; i || j; ){
            if (bef[i][j] == 1)
                ans.push_back(str1[i - 1]), --i;
            else if (bef[i][j] == 2)
                ans.push_back(str1[i - 1]), --i, --j;
            else 
                ans.push_back(str2[j - 1]), --j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

# 1106
比较简单的一个递归求表达式的值的题目。难度感觉没有 Hard 那种程度，最多是 Normal 把。。。
```cpp
class Solution {
public:
    int n, cur;
    bool calc(string& expr){
        if (isalpha(expr[cur])) return (expr[cur] == 't' ? true: false);
        if (expr[cur] == '!') {
            cur += 2;
            bool res = !calc(expr);
            ++cur;
            return res;
        }
        bool flag = (expr[cur] == '&' ? true: false), res = flag;
        for (; ; ){
            cur += 2;
            if (flag)
                res &= calc(expr);
            else 
                res |= calc(expr);
            if (expr[cur + 1] == ')')
                break;
        }
        ++cur;
        return res;
    }
    bool parseBoolExpr(string expression) {
        n = expression.length(), cur = 0;
        return calc(expression);
    }
};
```

# 1125
背包型状压 DP。（状压式背包）

每次都用人的技能去更新整个背包数组即可，时间复杂度为 $O(m2^n)$。$m$ 是人数，$n$ 是技能数目。要加上转移位置的处理。
```cpp
int bv[65], f[2][65550], pos[65550], choice[65550];
class Solution {
public:
    int n, m, ans;
    unordered_map<string, int> mp;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size(), m = people.size();
        for (int i = 0; i < n; ++i) 
            mp[req_skills[i]] = i;
        for (int i = 0; i < m; ++i){
            bv[i] = 0;
            for (string& s: people[i])
                bv[i] |= (1 << mp[s]);
        }
        memset(f, 0x3f, sizeof(f));
        f[1][0] = 0;
        int lim = (1 << n) - 1;
        for (int i = 0; i < m; ++i){
            int B = (i & 1), B_ = 1 - B;
            for (int j = 0; j <= lim; ++j)
                f[B][j] = f[B_][j];
            for (int j = 0; j <= lim; ++j){
                if (f[B_][j] + 1 < f[B][j | bv[i]])
                    f[B][j | bv[i]] = f[B_][j] + 1, pos[j | bv[i]] = j, choice[j | bv[i]] = i;
            }
        }
        int ans = f[(m - 1) & 1][lim];
        vector<int> aans;
        for (int i = choice[lim], j = lim; j > 0; j = pos[j], i = choice[j])
            aans.push_back(i);
        return aans;
    }
};
```

# 1147
直觉上可以贪心，实际上就是贪心。只要能切割就切割。
（具体的证明等待补充）
```python
class Solution:
    def longestDecomposition(self, text: str) -> int:
        if text == "":
            return 0
        len1 = len(text) // 2
        for i in range(1, len1 + 1):
            if text[0: i] == text[-i: ]:
                return self.longestDecomposition(text[i: -i]) + 2
        return 1
```

# 1153
很难让人在有限的样例下把握关键的题目。（比赛时我 WA 了 5 次，全靠 WA 出来的样例找出规律）
首先基本的，把每一个字符的映射找出来。然后是关键，答案是 true 的充要条件是下面两个的逻辑或：

1. 存在某个字符，它没有出现在 str1 中。这表明了某些字符可以将其作为中转站，从而变化成为别的字符。
2. 不存在某个环（自环不算），使得只有通过环上面的点才能进入到该环内。也就是说，没有某个入度为 0 的点能到达该环。

第二个条件有些奇怪，可以这么想：如果第一个条件成立，那么即使存在这样的环也可以通过某个空余字符将环拆解。（考虑 str1="ab", str2="ba"）第一个条件不成立，而第二个条件也不成立的话，那么对于这样的环，其上面的字符必须沿着某一方向逐步映射，而这样必然会丢失起始的字符。
如果第二个条件成立，第一个条件不成立也好办。这一步可以试着画个图理解一下。
```cpp
class Solution {
public:
    bool canConvert(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();
        vector<int> mp(26, -1);
        for (int i = 0; i < l1; ){
            int j = i, j2 = i;
            while (j < l1 && str1[i] == str1[j]) ++j;
            while (j2 < l2 && str2[i] == str2[j2]) ++j2;
            if (j2 < j) return false;
            if (mp[str1[i] - 'a'] < 0) mp[str1[i] - 'a'] = str2[i] - 'a';
            else {
                if (mp[str1[i] - 'a'] != str2[i] - 'a')
                    return false;
            }
            i = j;
        }
        int occ = 0, cnt = 26;
        int deg[26] = {0};
        bool vis[26] = {0};
        for (int i = 0; i < 26; ++i){
            if (mp[i] < 0) ++occ;
            else if (mp[i] == i) mp[i] = -1;
            else ++deg[mp[i]];
        }
        for (int i = 0; i < 26; ++i){
            if (deg[i]) continue;
            int tp = i;
            --cnt, vis[tp] = true;
            while (mp[tp] >= 0){// 沿着环走
                if (vis[mp[tp]]) break;
                --cnt, vis[mp[tp]] = true, tp = mp[tp];
            }
        }
        return occ || cnt == 0;
    }
};
```


# 1157
python 暴力居然卡了过去。。。
这可能是一个失误，因为比赛的时候是小数据（最多 500 次询问），而在正式题目中变成了 10000。

其实这道题就是区间众数，这个问题有很多种解法，下面给出一些解法。


# 1163
首先要发现：答案就是字符串的字典序最大的后缀。
为什么一定是后缀呢？如果不是，假设这个字典序最大的子串是 s，并且 s 不是后缀，那么 s 连接上它后面的若干字符构成的新字符串的字典序一定比 s 大，这和 s 是字典序最大的子串相矛盾，证毕。
有了这个结论，解法就很明了：使用后缀数组，求出最大的后缀即可。可以用最小表示法做，也可以用后缀数组做。
```cpp
char r[100005];
int sa[100005], wa[100005], wb[100005], wv[100005], cnt[100005] = {0};
int cmp(int *r, int a, int b, int l){
	return r[a] == r[b] && r[a + l] == r[b + l];
}
void build_sa(char *r, int *sa, int n, int m){
	int i, j, p, *x = wa, *y = wb;
	for(i = 0; i < m; ++i) cnt[i]=0;
	for(i = 0; i < n; ++i) cnt[x[i] = r[i]]++;
	for(i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
	for(i = n - 1; i >= 0; --i) sa[--cnt[x[i]]] = i;
	for(j = 1, p = 1; p < n; j <<= 1, m = p){
		for(p = 0, i = n - j; i < n; ++i) y[p++] = i;
		for(i = 0; i < n; ++i) if(sa[i] - j >= 0) y[p++] = sa[i] - j;
		for(i = 0; i < n; ++i) wv[i] = x[y[i]];
		for(i = 0; i < m; ++i) cnt[i] = 0;
		for(i = 0; i < n; ++i) cnt[wv[i]]++;
		for(i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
		for(i = n - 1; i >= 0; --i) sa[--cnt[wv[i]]] = y[i];
		swap(x, y);
		for(p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1: p++;		
	}
}
class Solution {
public:
    string lastSubstring(string s) {
        int l = s.length();
        for (int i = 0; i < l; ++i) 
            r[i] = s[i] - 'a' + 1;
        r[l] = 0;
        build_sa(r, sa, l + 1, 26 + 1);
        return s.substr(sa[l]);
    }
};
```

# 1172
用一个小根堆维护可以用的栈，用一个指针维护当前非空的最大栈。应该可以证明，用指针维护的话第二个操作的均摊时间复杂度是 $O(1)$。
整个算法比较麻烦的地方在于栈的在线申请。经测试，使用 vector 来保存一系列的栈比使用 unordered_map 要慢一些。还有就是堆的使用。
```cpp
class DinnerPlates {
private:
    unordered_map<int, stack<int>> st;
    int cap, cnt, cur;
    priority_queue<int, vector<int>, greater<int>> able;
public:
    DinnerPlates(int capacity) {
        cap = capacity, cnt = 1;
        cur = -1;
        st[0] = stack<int>();
        able.push(0);
    }
    
    void push(int val) {
        if (able.empty())
            st[cnt] = stack<int>(), 
            able.push(cnt), cur = cnt, ++cnt;

        int tp = able.top();
        st[tp].push(val);
        if (st[tp].size() == cap) able.pop();
    }
    
    int pop() {
        if (cur == -1) return -1;

        int res = st[cur].top();
        if (st[cur].size() == cap) able.push(cur);
        st[cur].pop();
        while (cur >= 0 && st[cur].empty())
            --cur;
        return res;
    }
    
    int popAtStack(int index) {
        if (st[index].empty()) return -1;
        
        int res = st[index].top();
        if (st[index].size() == cap) able.push(index);
        st[index].pop();
        if (cur == index){
            while (cur >= 0 && st[cur].empty())
                --cur;
        }
        return res;
    }
};
```

# 1176
先对每一个单词算出来位向量然后再用字谜的位向量去匹配即可，时间复杂度 $O(N+2^6 M)$，$N$ 是单词的字符数目，$M$ 是字谜的数目。
~~考了两个位运算的题目，这个比赛不行啊~~
```cpp
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int n = words.size(), m = puzzles.size();
        for (int i = 0; i < n; ++i){
            int vec = 0, cnt = 0;
            for (char c: words[i]){
                int t = 1 << (c - 'a');
                if (!(vec & t)) vec |= t, ++cnt;
            }
            if (cnt > 7) continue;
            if (mp.count(vec)) mp[vec] = 1;
            else ++mp[vec];
        }
        for (int i = 0; i < m; ++i){
            int cnt = 0;
            int v0 = 1 << (puzzles[i][0] - 'a'),
                v1 = 1 << (puzzles[i][1] - 'a'), 
                v2 = 1 << (puzzles[i][2] - 'a'), 
                v3 = 1 << (puzzles[i][3] - 'a'), 
                v4 = 1 << (puzzles[i][4] - 'a'), 
                v5 = 1 << (puzzles[i][5] - 'a'), 
                v6 = 1 << (puzzles[i][6] - 'a');
            for (int A = 0; A <= v1; A += v1)
            for (int B = 0; B <= v2; B += v2)
            for (int C = 0; C <= v3; C += v3)
            for (int D = 0; D <= v4; D += v4)
            for (int E = 0; E <= v5; E += v5)
            for (int F = 0; F <= v6; F += v6){
                int vec = v0 + A + B + C + D + E + F;
                if (mp.count(vec)) 
                    cnt += mp[vec];
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
```

# 1187
DP。

设 $g(i)$ 为使得 `arr1` 前 $i$ 个数递增且不修改第 $i$ 个数时的最小修改次数，$f(i, j)$ 为使得 `arr1` 前 $i$ 个数递增且修改第 $i$ 个数为 `arr2` 的第 $j$ 个数时的最小修改次数。则有转移关系：

$$
\begin{aligned}
g(i)&= \begin{cases}
g(i - 1)& \text{if } arr1[i]>arr[i - 1] \\
f(i - 1, k)& \text{if } arr1[i]>arr2[k]
\end{cases} \\

f(i, j)&= \begin{cases}
g(i - 1) + 1& \text{if } arr2[j]>arr[i - 1] \\
f(i - 1, k) + 1& \text{if } arr2[j]>arr2[k]
\end{cases}

\end{aligned}
$$
大括号的右端均是候选项，上述转移在所有候选项中取 $\min$。

朴素实现上述转移的时间复杂度为 $O(nm^2)$，其中 $n$ 为 `arr1` 长度，$m$ 为 `arr2` 长度。我们考虑优化。

对于 $g(i)$ 的转移，我们可以先对 `arr2` **排序去重**，然后对 `arr1` 中每一个数预处理出一个最大的 $p$ 使得 $arr1[i]>arr2[p]$。显然在排序去重后的 `arr2` 中，所有小于等于 $p$ 的 $k$ 都是候选项，这就可以通过每一轮做前缀最小值以快速查询出 $\min\lbrace f(i-1, k)\rbrace$。

对于 $f(i, j)$ 的转移，由于排序后 $arr2$ 的单调性，我们知道 $k$ 的取值是所有小于 $j$ 的值，因此可以方便维护 $\min\lbrace f(i-1, k)\rbrace$。

最后的答案就是 $\min \lbrace g(n), \min\lbrace f(n, k) \rbrace \rbrace$。

注意去重，这是一个非常关键的步骤。时间复杂度为 $O(nm+(m + n)\log m)$。空间复杂度可以优化至 $O(n+m)$。

```cpp
int f[2005][2005], g[2005], lb[2005];
int mini[2005];
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int n = arr1.size(), m = arr2.size();
        m = unique(arr2.begin(), arr2.end()) - arr2.begin();
        while (arr2.size() > m)
            arr2.pop_back();
        memset(f, 0x3f, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        memset(mini, 0, sizeof(mini));
        mini[0] = 0x3f3f3f3f;
        g[0] = 0;
        for (int i = 0; i < n; ++i) 
            lb[i + 1] = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
        for (int j = 1; j <= m; ++j)
            f[0][j] = 0;
        for (int i = 1; i <= n; ++i){
            int mmini = 0x3f3f3f3f;
            for (int j = 1; j <= m; ++j){
                int t = 0x3f3f3f3f;
                if (i == 1 || arr1[i - 1] > arr1[i - 2])
                    t = min(t, g[i - 1]);
                if (lb[i] >= 1 && lb[i] <= m)
                    t = min(t, mini[lb[i]]);
                g[i] = min(g[i], t);
                
                t = 0x3f3f3f3f;
                if (i == 1 || arr2[j - 1] > arr1[i - 2])
                    t = min(t, g[i - 1]);
                t = min(t, mmini);
                f[i][j] = t + 1;
                mmini = min(mmini, f[i - 1][j]);
            }
            mini[0] = 0x3f3f3f3f;
            for (int j = 1; j <= m; ++j)
                mini[j] = min(mini[j - 1], f[i][j]);
        }
        int ans = g[n];
        for (int i = 1; i <= m; ++i)
            ans = min(ans, f[n][i]);
        return ans == 0x3f3f3f3f ? -1: ans;
    }
};
```

# 1200
拓扑排序。将组看作大节点，项目看作小节点，大节点里面包含小节点。按照项目顺序在大小节点之间连边，然后对大节点做拓扑排序，大节点内部对小节点拓扑排序即可。

方便起见，可以为没有归属的组重新赋予编号。

注意自环。注意不要把 STL 写在 class 外面，不然会出现很奇怪的问题，这把我坑惨了。。。
```cpp
int to1[200005], nxt1[200005], at1[30005], cnt1, du1[30005];
int to2[200005], nxt2[200005], at2[60005], cnt2, du2[60005];
class Solution {
public:
    vector<int> G[60005];
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> ans;
        int totno = m; 
        memset(at1, 0, sizeof(at1)), memset(du1, 0, sizeof(du1)), cnt1 = 0;
        memset(at2, 0, sizeof(at2)), memset(du2, 0, sizeof(du2)), cnt2 = 0;
        for (int i = 0; i < n; ++i){
            if (group[i] == -1) group[i] = totno++;
            G[group[i]].push_back(i);
        }
            
        m = totno;
        for (int i = 0; i < n; ++i){
            for (int v: beforeItems[i]){
                to1[++cnt1] = i, nxt1[cnt1] = at1[v], at1[v] = cnt1;
                ++du1[i];
                if (group[i] != group[v])
                    to2[++cnt2] = group[i], nxt2[cnt2] = at2[group[v]], at2[group[v]] = cnt2, ++du2[group[i]];
            }
        }
        
        queue<int> que, que2;
        for (int i = 0; i < m; ++i) 
            if (!du2[i]) que.push(i);
        while (!que.empty()){
            int t = que.front();
            que.pop();
            for (int cur: G[t]){
                if (!du1[cur]) que2.push(cur);
            }
            while (!que2.empty()){
                int tt = que2.front();
                que2.pop();
                ans.push_back(tt);
                for (int i = at1[tt]; i; i = nxt1[i]){
                    int vv = to1[i];
                    --du1[vv];
                    if (!du1[vv] && group[vv] == t) // 只有当前组内节点参与拓扑排序
                        que2.push(vv);
                }
            }
            for (int i = at2[t]; i; i = nxt2[i]){
                int v = to2[i];
                --du2[v];
                if (!du2[v]) que.push(v);
            }
        }

        if (ans.size() < n) return vector<int>{};
        return ans;
    }
};
```

# LCP 4
首先，我们可以对棋盘进行黑白染色，使得任意相邻的两个格子颜色不相同。这意味着将格子看作是节点的话，整个期盼就是一个二分图。

然后可以发现，一个多米诺骨牌，必然会覆盖到一对相邻的黑白格子。这可以看作是一个多米诺骨牌会占据二分图中的一条边。

发现了这个性质，就可以将整个问题转化为求这个二分图的最大匹配。具体的说，将格子视作点，在没有障碍的格子之间连一条边，然后求最大匹配即可。

这里使用匈牙利算法求解。由于边的数目正比于点的数目，时间复杂度为 $O(n^2m^2)$。

```cpp
int mat[105][105], from[105], nn, mm;
bool vis[105];
bool unvisible[10][10];
int match(int x){
    for (int i = 0; i < nn * mm; ++i){
        int dx = i / mm, dy = i % mm;
        if ((dx + dy) & 1) continue;
        if (unvisible[dx][dy]) continue;
        if (!mat[x][i]) continue;
        if (!vis[i]){
            vis[i] = true;
            if (from[i] < 0 || match(from[i])){
                from[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
int Hungary(){
    // 认为 (x 坐标 + y 坐标) 为奇数时格子是黑色，对黑色格子找匹配
    int match_size = 0;
    memset(from, -1, sizeof(from));
    for (int i = 0; i < nn * mm; ++i){
        int dx = i / mm, dy = i % mm;
        if (!((dx + dy) & 1)) continue;
        if (unvisible[dx][dy]) continue;
        memset(vis, 0, sizeof(vis));
        match_size += match(i);
    }
    return match_size;
}
class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        nn = n, mm = m;
        memset(unvisible, 0, sizeof(unvisible));
        for (vector<int>& p: broken)
            unvisible[p[0]][p[1]] = true;
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (unvisible[i][j]) continue;
                int id = i * m + j;     // 将节点按照 (x 坐标 * m) + (y 坐标) 编号
                if (j + 1 < m && unvisible[i][j + 1] == false){
                    int iid = i * m + j + 1;
                    mat[id][iid] = mat[iid][id] = 1;
                }
                if (i + 1 < n && unvisible[i + 1][j] == false){
                    int iid = (i + 1) * m + j;
                    mat[id][iid] = mat[iid][id] = 1;
                }
            }
        }
        return Hungary();
    }
};
```