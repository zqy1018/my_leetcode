# D

C++ 暴力

当 $l \le r$ 时，题目中的 `func(a, l, r)` 计算的就是 $a_l \operatorname{and} a_{l+1} \operatorname{and} \cdots \operatorname{and} a_{r}$，其中 $\operatorname{and}$ 为按位与。显然，任何一个 $l\le r$ 的情况得到的解都比 $l > r$ 的要好，因此我们只考虑 $l \le r$ 的情况。

按照暴力算法，一开始我们维护一个 $ans$，对于每一个位置 $i$，我们都检查下面每一个数和 $target$ 的差的绝对值，并用其更新 $ans$。
$$
\begin{aligned}
    & a_0 \operatorname{and} a_{1} \operatorname{and} \cdots \operatorname{and} a_{i} \\
    & a_{1} \operatorname{and} \cdots \operatorname{and} a_{i} \\
    & \vdots \\
    & a_{i - 1} \operatorname{and} a_{i} \\
    & a_{i}
\end{aligned}
$$
对于上面这个数集，可以用一个数组维护。

使用这个算法即可通过。

# C

我们对每一种字母预处理出其第一次和最后一次出现的位置，然后对于每种字母 $i$，试图处理出这样的段 $[l_i, r_i]$：

1. $l_i$ 为 $i$ 第一次出现的位置。
2. 段中所有字母只出现在段中。
3. 满足以上两点的情况下，$r_i$ 最小。

由于对于某个字母，这样的段可以不存在（考虑 `abab` 中对 `b` 处理），因此这样的段最多有 $|\Sigma| = 26$ 个。

那么答案对应的所有子串就是**不包含任何其他段的段**对应到原字符串上的子串。

时间复杂度为 $O(n|\Sigma| + |\Sigma|^2)$。

```cpp
class Solution {
    int st[27], ed[27];
    pair<int, int> seg[100];
public:
    vector<string> maxNumOfSubstrings(string s) {
        int l = s.length();
        memset(st, -1, sizeof(st));
        for (int i = 0; i < l; ++i){
            if (st[s[i] - 'a'] < 0)
                st[s[i] - 'a'] = i;
            ed[s[i] - 'a'] = i;
        }
        vector<string> ans;
        int tot = 0;
        for (int i = 0; i < 26; ++i){
            if (st[i] < 0) continue;
            int targ = ed[i];
            bool flag = true;
            for (int j = st[i] + 1; j <= targ; ++j){
                if (st[s[j] - 'a'] < st[i]){
                    flag = false;
                    break;
                }
                targ = max(targ, ed[s[j] - 'a']);
            }
            if (flag)
                seg[tot].first = st[i], seg[tot++].second = targ;
        }
        for (int i = 0; i < tot; ++i){
            bool flag = true;
            for (int j = 0; j < tot; ++j)
                if (i != j && seg[j].first >= seg[i].first && seg[j].second <= seg[i].second){
                    flag = false;
                    break;
                }
            if (flag) 
                ans.push_back(s.substr(seg[i].first, seg[i].second - seg[i].first + 1));
        }
        return ans;
    }
};
```