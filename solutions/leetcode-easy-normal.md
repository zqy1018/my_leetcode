# Leetcode 困难以下 简要题解
个人认为以下题目中比较好的：11，19，84，96，137，138，189，229，240，258，260，264，290，324，326，368，400，438，448，453，456，458，459，478，479，633，754，877，932，939

# 1
Hash Table 边存边找

# 2
简单大数加法

# 3
用类似于尺取法的方法统计字符，维护滑动窗口中字符的出现次数。
另一个相对更好的方法是维护每一个字符的出现位置，这样就不需要在更新滑动窗口的时候（这时最后一个被纳入的字符出现重复）让前端的指针向后一步一步移动，而是可以直接让前端指针指向重复字符在窗口内出现位置的后一个位置。
比如：当前窗口是 abcb，b 重复，就可以让头指针（指向 a）改为指向前一个 b 的后面一个位置，也就是 c。这样略去了前端指针不断后移的过程，从而减小了时间复杂度的常数因子。

# 5
最差的是枚举子串暴力判断，$O(n^3)$；比较好的是枚举中间点暴力判断，$O(n^2)$；最好的是 Manacher，$O(n)$。

# 6
模拟或者推公式。

# 7
基本上和翻转字符串相同。特判负数和溢出。

# 8
小模拟
用 python 的正则表达式做法是真的厉害。。。

# 9
用字符串。
不用字符串可以考虑先特判负数，然后转化为翻转数字来做。官方给了一个更好的方法：只需要判断反转后一半是否相等即可。

# 11

## 方法一
排序，找周围比自己高的，进而找最远的。
```python
class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        len1 = len(height)
        h = list(zip(height, range(0, len1)))
        h.sort(key = lambda x: x[0])
        ans = 0
        hd, tl = 0, len1 - 1
        for i in h:
            hh, idx = i[0], i[1]
            ans = max(ans, max(idx - hd, tl - idx) * hh)
            height[idx] = -1
            while hd < tl and height[hd] == -1: hd += 1
            while hd < tl and height[tl] == -1: tl -= 1
        return ans
```
## 方法二
使用两个分别指向头和尾的指针，每次比较两个指针所指的木板的长度，将指向较小者的指针向中间地区移动，这样就可以保证能找到最大的解。这样做是线性的时间复杂度。
```python
class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        len1 = len(height)
        i, j, ans = 0, len1 - 1, 0
        while i < j:
            ans = max(ans, min(height[i], height[j]) * (j - i))
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return ans
```

# 12
模拟

# 13
小模拟

# 14
二分最长前缀长度。可以用`startswith()`。

# 15
基本同18，不过简单很多

# 16
暴力可以做，但是时间效率不行。
应该是先排序然后用双指针。

# 17
水

# 18
折半搜索

# 19
这题有点厉害。。。
先用一个快指针跳$n$个点，然后慢指针从头开始，两个指针始终维护$n$的间距。快指针到末尾时慢指针到答案处。
```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode *hhd = new ListNode(-1), *res = hhd;
        hhd->next = head;
        ListNode *fst = hhd;
        for (int i = 0; i < n; ++i)
            fst = fst->next;
        while(fst->next != NULL)
            fst = fst->next, hhd = hhd->next;
        hhd->next = hhd->next->next;
        return res->next;
    }
};
```

# 20
水栈。

# 21
水归并

# 22
水 DFS。模拟一个栈中匹配括号的过程，在 DFS 的时候记录栈中有多少个左括号就可以完成 DFS。

# 24
加一个头节点即可

# 26
可以用双指针法。

# 27
遍历。

# 28
```python
str.find()
```

# 29
倍增。-2147483648的情况非常不好做。

# 31
```cpp
next_permutation(nums.begin(), nums.end());
```

# 33
先二分找到旋转的地方，再普通二分。

# 34
二分。等同于实现`lower_bound()`和`upper_bound()`。

# 35
二分。基本等同于34题。

# 36
模拟

# 38
容易

# 39
完全背包记录方案

# 40
DFS

# 46
简单全排列构造

# 47
排序后递归全排列，或者直接next_permutation?

# 48
水

# 49
把元组或者正规化的字符串作为键其实可以，不过有一个神奇操作是用质数作为状态压缩的工具，把一个字符串映射成为一个数。实在是非常创新了。（虽然两个做法效率差不多）

# 50
```python
return x ** n
```

# 53
我觉得$O(n)$更精妙来着...

# 54
模拟

# 56
按左端点从左到右排序，模拟即可。

# 58
水

# 59
和54题配套

# 60
康拓展开

# 61
先遍历一遍求出总长，再找到要切断的地方。

# 62
水递推

# 63
简单递推。

# 64
DP

# 66
水

# 67
```python
return bin(int(a, 2) + int(b, 2))[2: ]
```

# 69
二分or函数。

# 70
递推。斐波那契数列。

# 71
超过 3 个点算文件夹名，惊了

# 73
可以把每一个0提到每一行/列的第一个位置，这样就不用保存每一行/列是否有0出现了。

# 74
类似于二分

# 75
三指针问题，只要分别记录 0 区域的右边界，2 区域的左边界即可，剩下一个指针用来遍历数组。
我一开始想的是只记录 2 区域的左边界，然后把 1 换成 2，在遍历结束后再加上去。。。这样不够好。

# 77
基本的递归组合。

# 78
基本的二进制数构造子集。

# 79
大力 DFS 就行了。。。

# 80
理论上任意指定的保留数目都可以实现。

# 81
因为存在重复元素，所以无法在二分的时候判定重复元素是属于哪一部分。故不能直接套用原来的方法。
如果打算在二分的时候去重就需要花费至多 $O(n)$ 的时间。既然如此，还不如直接扫一遍获知答案。。。

# 82
水

# 83
水

# 86
用两个头节点，把原来的链表拆开之后按顺序连接到头节点上即可。
不要想的太复杂。

# 88
从尾部开始合并有序队列。

# 90
先排序算出每一种数的个数，然后把答案的vector建出来，按照特定的顺序向里面添加一定数目的元素即可。
有直接生成然后去重的偷懒做法，不提倡。

# 91
水 DP

# 92
这题做法比较多，我用的是维护链表$m-1, m, n+1$三个位置，然后根据各自位置判断链接方式的方法。

# 93
简单枚举和剪枝

# 94, 144
水
迭代应该是指用栈记录上一次访问了什么，然后遇到这个节点更新，如果全部弄完了就出栈。

# 95
递归的时候以包含所有可能的树结构的 vector 作为返回值即可。
（有没有什么可以降低空间复杂度的方法？）

# 96
经典问题。答案是Catalan数。

# 98
中序遍历

# 100
水

# 101
递归遍历用两个参数

# 102
BFS

# 103
每一层按照奇偶性转一下

# 104
水

# 105, 106
模板

# 107
把102的结果reverse即可。

# 108
相当于构建一棵AVL树。只需要每次对半切分子序列即可。

# 109
基本同108

# 110
按照题意模拟即可。

# 112
水

# 113
水

# 114
水

# 116
对于一个根节点，令左儿子连接右儿子，右儿子连接根的next的左儿子。

# 117
基本同116，不过找next要沿着next链跳，且要先向右走。
或者，一个更好的方法是按层构建next，因为构建了一层next就可以在这层基础上把所有子节点的next构造出来。

# 118
水

# 119
利用组合数公式

# 120
普通DP

# 121
维护当前所遇到的最小数$mini$，然后从左向右扫，每遇到一个数就尝试更新答案和$mini$。

# 122
简单DP

# 125
正规化字符串之后直接判定。

# 129
简单递推

# 130
BFS

# 131
把每一个前缀的答案记录一下。这个过程和记忆化有些类似。
猜测这个题目用 python 会方便很多。

# 134
跑一遍就行，如果从$i$跑不到$j$，那么从$i+1, i+2, ..., j-1$也跑不到$j$。证明很简单。

# 136
异或

# 137

## 方法一
基本做法是统计每一位的1数目，看看哪一位的次数模$3$余$1$，然后把这些位或起来。
```python
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, j, cnt1, cnt2 = 0, 1, 0, 0
        for i in range(0, 32):
            for t in nums:
                if t >= 0:
                    if t & j:
                        cnt1 += 1
                else:
                    if (-t) & j:
                        cnt2 += 1
            if cnt1 % 3 == 1:
                ans += j
            elif cnt2 % 3 == 1:
                ans += -j
            j <<= 1
            cnt1, cnt2 = 0, 0
        return ans
```
## 方法二
对于这道题而言，我们寄希望于能找到一种方法，利用位运算，来实现三进制的无进位加法。换言之，有没有什么方法可以实现某些位上出现`00`->`01`->`10`->`00`的循环呢？
答案是有的。因为是二进制，所以我们可以考虑用两个二进制数表示一个三进制的数。
这里直接给出这种运算方法。手算可以发现它实现了b，a上同一位`00`->`01`->`10`->`00`的变化（因为我也不知道这是怎么想到的，代码来自中文leetcode本题评论区）
事实上，利用逻辑运算规则可以构造出这样一个真值函数，来实现三进制的运算。
```python
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a, b = 0, 0
        for num in nums:
            b = ~a & (b ^ num)
            a = ~b & (a ^ num)
        return b
```

# 138
一个非常不错的题目。
一种优秀的做法是：先将每一个点都复制一份，连在其后方，新节点和旧节点交替链接。然后遍历新节点，新节点的随机指针指向的就是旧节点随即指针指向的next。然后将新节点连成新链表即可。
这种方法最优秀的一点在于，通过构造这样一种结构，它避免了遍历节点的时候成环等情况，让更新随机指针更加方便。
```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node *tmp = head;
        while (tmp != NULL){
            Node *n = new Node(tmp->val, tmp->next, NULL);
            tmp->next = n, tmp = n->next;
        }
        tmp = head;
        while (tmp != NULL){
            if (tmp->random != NULL) 
                tmp->next->random = tmp->random->next;
            tmp = tmp->next->next;
        }
        tmp = head;
        Node *ans = head->next;
        while (tmp->next->next != NULL){
            Node *p = tmp->next->next;
            tmp->next->next = p->next;
            tmp->next = p;
            tmp = p;
        }
        tmp->next->next = NULL;
        tmp->next = NULL;
        return ans;
    }
};
```

# 139
简单 DP

# 141
Floyd判圈法

# 142
不让用额外空间就还行，那就乱搞。。。
不乱搞实际就是Floyd判圈法的一个推论。

# 147
从头向后插入即可。

# 148
对链表做归并排序。要满足题目中说的只使用常数级别的空间复杂度就不能使用自顶向下的递归式排序方法，而是要使用类似倍增的自底向上的排序方法。
链表这个结构比较特殊，我们可以不开辟新的空间而实现归并排序。同时，从前向后的顺序访问也是本题使用归并排序的原因之一。

# 150
水，但是用python小心python的神奇负数除法

# 151
```python
return " ".join(reversed(s.split()))
```

# 152
（不太）容易证明，最大值一定是 0 或者某个不包含 0 的段的前缀积或者后缀积。所以遍历两次即可。
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -2147483648;
        int n = nums.size();
        for (int i = 0, pp = 1; i < n; ++i, pp = (pp == 0 ? 1: pp))
            pp *= nums[i], ans = max(ans, pp);
        for (int i = n - 1, pp = 1; i >= 0; --i, pp = (pp == 0 ? 1: pp))
            pp *= nums[i], ans = max(ans, pp);
        return ans;
    }
};
```

# 153
是 33 的第一步（找出旋转点）

# 155
单调栈

# 157
注意边界条件

# 160
先求出两个表头的深度，然后把两个表头放到同一深度，再一起向前走。

# 161
最暴力的做法当然是直接套编辑距离的模板，但没必要。可以在两个字符串第一次不匹配的地方按照三种情况（添，删，改）讨论，再对剩余的部分做线性匹配即可。时间复杂度是线性的。

```cpp
class Solution {
public:
    int n, m;
    bool cmp(int st1, int st2, string& s, string& t){
        if (n - st1 != m - st2)
            return false;
        for (int i = 0; i < n - st1; ++i)
            if (s[st1 + i] != t[st2 + i])
                return false;
        return true;
    } 
    bool isOneEditDistance(string s, string t) {
        n = s.length(), m = t.length();
        if (abs(n - m) > 1) return false;
        int cur = 0;
        while (cur < n && cur < m && s[cur] == t[cur])
            ++cur;
        if (cur == n || cur == m)
            return n != m;
        return cmp(cur + 1, cur, s, t) || cmp(cur, cur + 1, s, t) || cmp(cur + 1, cur + 1, s, t);
    }
};
```

# 162
因为数组的两端都视为最低点，所以可以用二分来做。思想很简单：我们希望最后停在峰的位置。对于 $mid$，如果从 $mid$ 到 $mid+1$ 高度增加，那么说明至少峰不是 $mid$，令 $l:=mid+1$；否则说明至少 $r$ 右边不是峰，令 $r:=mid$。
注意，这里我们似乎只考虑了只有一个峰的情况。但事实上，二分的每一步都是正确的，而最后得到的确实是峰的位置。
（证明有时间可能会证一下）

# 165
按照`.`切分列表之后按照项比较即可

# 166
这题细节太多。。。（要素过多）
基本思想还是判环，由抽屉原理不可能出现比分母还多种类的余数，所以用一个 Hash Table 记录余数（因为分母可以特大），用另外一个列表记录商。
然后就是各种奇奇怪怪的边界情况。请考虑：

1. 没有小数部分
2. 分母为 `INT_MIN`
3. 结果是负数

考虑完这三种情况差不多就能过了。
```cpp
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
		if (!numerator) return string("0");
		string ans;
		
		int flag1 = 0, flag2 = 0;
		long long n = numerator, d = denominator;
		if (numerator < 0) ++flag1, n = -n;
		if (denominator < 0) ++flag2, d = -d;
		if (flag1 + flag2 == 1) ans.push_back('-');

        if (n >= d)
			ans += to_string(n / d), 
			n %= d;
		else ans.push_back('0');
		if (!n) return ans;

		long long g = __gcd(n, d);
		n /= g, d /= g;

		vector<int> val(1, 0);
		unordered_map<int, int> mp;

		int cnt = 0, cycle, shang, yushu;
		for(; n; n *= 10ll){
			shang = n / d, 
			yushu = n % d;
			cout << n << "  " << d << endl;
			val.push_back(shang), ++cnt;
			if(mp.count(yushu)) 
				break;
			mp[yushu] = cnt;
			n %= d;
		}
		ans.push_back('.');
		if(!n){
			for (int i = 2; i <= cnt; ++i)
				ans.push_back(val[i] + '0');
		}else{
			cycle = mp[yushu] + 1;
			for(int i = 2; i < cycle; ++i)
				ans.push_back(val[i] + '0');
			ans.push_back('(');
			for(int i = cycle; i <= cnt; ++i)
				ans.push_back(val[i] + '0');
			ans.push_back(')');
		}
		return ans;
    }
};
```

# 167
双指针

# 168
特殊的进制问题，对于进位要特殊处理，或者每每次循环先让$n$自减1。

# 169
摩尔投票法，经典问题。

# 170
set

# 171
```cpp
for (int i = 0; i < n; ++i)
    ans = ans * 26 + s[i] - 'A' + 1;
```

# 172
统计这个阶乘中因子$2$和$5$的次数，取其较小者。但显然后者更少，所以只要统计后者。

# 173
模拟中序遍历。可以使用 0，1，2，三个状态码来表示当前节点的状态（将要访问左子树，将要访问自己，将要访问右子树并且退出）

# 175
Left Join

# 176
使用 LIMIT 选项获取指定的行。注意两点：

1. 去重。
2. 最后查询结果是空的时候输出 NULL。

# 178
比较两个数字相连之后的字典序。

# 187
压成20位的二进制数，然后bitset记录

# 189

## 方法一
根据$k$把原序列切分成两段，然后递归交换这两段。
```python
class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        len1 = len(nums)
        k %= len1
        if k == 0 or len1 == 1: 
            return
        a1, b1, a2, b2 = 0, len1 - 1 - k, len1 - k, len1 - 1
        # 均以下标为准
        while b2 - a2 != b1 - a1:
            if b2 - a2 > b1 - a1:
                len2 = (b1 - a1 + 1)
            else:
                len2 = (b2 - a2 + 1)
            for i in range(0, len2):
                nums[a1 + i], nums[b2 - len2 + 1 + i] = nums[b2 - len2 + 1 + i], nums[a1 + i]
            if b2 - a2 > b1 - a1:
                b2 -= len2
            else:
                a1 += len2
        len2 = b1 - a1 + 1
        for i in range(0, len2):
            nums[a1 + i], nums[a2 + i] = nums[a2 + i], nums[a1 + i]
```
## 方法二
采取类似于非旋转treap的方法，按照$k$把序列切分成为两段，然后分别逆序两段，再将一整段逆序就可以得到答案。
```python
class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def rev(a, b):
            mid = (a + b) >> 1
            for i in range(a, mid + 1):
                nums[i], nums[b + a - i] = nums[b + a - i], nums[i]

        len1 = len(nums)
        k %= len1
        if k != 0:
            rev(0, len1 - k - 1)
            rev(len1 - k, len1 - 1)
            rev(0, len1 - 1)
```
## 方法三
我猜是暴力移动...?

# 190
用`bin()`，但也可以用位运算。

# 191
位运算

# 198
水DP

# 199
利用二叉树前序遍历时，某一深度最后被访问的节点一定在本层最右这一性质。

# 200
傻逼BFS

# 201
```cpp
int rangeBitwiseAnd(int m, int n) {
    int ans = 0, j = 1;
    while(m && n){
        if((m & 1) && (n & 1) && m == n) ans |= j;
        m >>= 1, n >>= 1, j <<= 1;
    }
    return ans;
}
```
不断考虑最低位。

# 202
循环。

# 203
水

# 204
用埃氏筛，欧拉筛会被卡。

# 205
用一个dict记录映射，一个set判断重复映射。

# 206
把每一个节点往前面链

# 207
其实就是判断整张图里面是否存在环。可以用 DFS 做，也可以做一次拓扑排序，然后判定是否所有顶点都进入了队列中。

# 208
模板

# 209
双指针，或者二分答案

# 210
207 的升级版，做一次拓扑排序即可。

# 211
Trie 树上套一个递归查询。好像也挺快的？

# 213
环形DP，考虑偷或者不偷第一家。

# 215
`nth_element()`

# 216
水 DFS

# 217
```python
return len(set(nums)) < len(nums)
```

# 219
开一个dict记录一个数最后出现的位置，边遍历边更新。

# 220
multiset水过，注意可恶的INT_MIN和INT_MAX。

# 221
简单DP

# 222
水

# 223
简单容斥

# 225
理论上每一次pop的时间复杂度都是$O(n)$（用来把栈顶放到队列的头），但可以通过多加几个缓冲队列来分摊一下时间复杂度。

# 226
同非旋转treap。

# 227
不是很懂为什么之前那个是困难，这个就是中等了
原理都差不多

# 228
水，但是注意溢出。。。

# 229
神奇的摩尔投票法的扩展
简单来说就是每次删除3个不同的数，这个使用计数器实现。然后检验剩下的两个候选数是不是真的满足条件（在原来的摩尔投票法中不需要，因为题目有这个条件）即可。
```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cx = 0, cy = 0, ax, ay;
        for (int i: nums){
            if(cx && ax == i) cx++;
            else if(cy && ay == i) cy++;
            else if(!cx) ax = i, cx = 1;
            else if(!cy) ay = i, cy = 1;
            else --cx, --cy;
        }
        int n = nums.size(), cnt = 0;
        vector<int> ans;
        for (int i: nums)
            if(i == ax) cnt++;
        if(cnt > n / 3) ans.push_back(ax);
        if(cy){
            cnt = 0;
            for (int i: nums)
                if(i == ay) cnt++;
            if(cnt > n / 3) ans.push_back(ay);
        }
        return ans;
    }
};
```

# 230
在一般的平衡树中是通过记录子树的大小来实现的，但这里可以通过记录当前节点是中序遍历的第几个节点来实现。

# 231
判断`n == lowbit(n)`。

# 232
两个栈，一个用于反转，一个用于保存。先放进保存的栈里，如果要pop/peek，先检查反转栈里有没有，没有的话把保存栈里的全部pop进反转栈，然后输出即可。

# 234
先用某种方法获取链表的中点，然后可以顺便反转了链表的前半部分，然后比对前后半部分即可。

# 235
和下面的差不多，只是利用BST的特性可以判断具体该向哪一个方向走

# 236
可以记录father然后向上爬，不过这样很麻烦。
更快捷的做法是查找p和q在哪一个最深的子树当中，也就是对于每一个子树递归的去做。
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == q || root == p) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if(l != NULL && r != NULL) return root; //都有，那么自己就是LCA
        return l != NULL ? l: r;
    }
};
```

# 237
由于题目中已经定位到了要删除的节点，所以按照传统方式删除是做不到的。要等价于“接管”后一个节点来做。
```cpp
node->val = node->next->val;
node->next = node->next->next;
```

# 238
用对数。。。（并不）
做两遍，从左乘和从右乘。

# 239
经典单调队列

# 240
最差劲的方法是对对角线二分，然后每次分成 3 个可能区域继续二分，这样做是 $O(n^{\log_2{3}})$ 的。（之前算错了复杂度）
对其可以改进一下，先二分出某一行使得目标在数的大小上恰好处于**这一行上面中间的数**和**这一行中间的数**之间（形式化的说，若当前矩阵列的中间位置是 $mid$，那么要找到一个值 $row $ 满足 $\operatorname{matrix}[row- 1 ][mid]<\text { target }<\text {matrix}[\text {row}][m i d] $，前一个不等号始终不满足就取 $row$ 为第一行，后一个不等号始终不满足就取 $row$ 为最后一行的下一行 ），然后根据单调性可以发现答案一定不处于矩阵按这一行划分的左上部分和右下部分，分两个部分递归即可。
还有一个更加优秀的办法：从矩阵的左下角开始，将当前格元素不断和目标比对，比目标小说明当前所在列可以舍去，比目标大说明当前所在行可以舍去。无论如何都要舍去一行或者一列，表明了该算法的时间复杂度是线性的。

# 241
把表达式按照符号拆成两个部分，然后每一个部分分别计算可能的结果，在上一层合并起来。

# 242
对字符串内字符排序后比较。也可以统计字符，比较各种字符数目。

# 246
水

# 257
水

# 258
观察可以发现答案和$n \mod 9$相关，实际也是。详细参见[Digital Root](https://en.wikipedia.org/wiki/Digital_root)
```python
class Solution:
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        return (num - 1) % 9 + 1 if num != 0 else 0
```

# 260
先把所有的数异或一遍，然后考虑结果的lowbit。这个bit必然存在于两个单独数的其中一个上，根据这个bit把这些数分成两个部分，分别异或一遍即可求出答案。

# 263
看除掉所有$2, 3, 5$之后是不是$1$。注意条件是正整数。

# 264
堆或者三指针。

即用一个序列记录所有丑数，然后对因子为2，3，5分别记录一个指针，这三个指针隐式的表示了三个单调队列的头节点。每次对这三个头节点取最小值更新即可。

注意一个数可能会出现在多个队列中，所以每一个头节点都要更新。

# 268
根据列表长度判断$n$然后用$0+1+\cdots+n$减列表中数。

# 274
排序贪心

# 275
二分

# 278
模板一样的二分

# 279
DP。
或者四平方定理。。。当且仅当$n=4^a(8b+7), a, b\in \mathbb{N}$的时候需要4个数。吃了没文化的亏。
```cpp
class Solution {
public:
    int numSquares(int n) {
        int tmp = n;
        while((tmp & 3) == 0)
            tmp >>= 2;
        if(tmp % 8 == 7) return 4;
        int ssqrt = (int)floor(sqrt(n) + 0.5);
        if(ssqrt * ssqrt > n) ssqrt--;
        if(ssqrt * ssqrt == n) return 1;
        int l = 1, r = ssqrt;
        while(l < r){
            int res = l * l + r * r - n;
            if(res > 0)
                r--;
            else if(res < 0)
                l++;
            else return 2;
        }
        if(2 * l * l == n) return 2;
        return 3;
    }
};
```

# 283
看到$0$就删，末尾加回来。

# 284
peek 之前复制一份自己，然后调用副本的 next。这是一种方法。

# 287
不断使数归位，直到出现重复

# 289
一个取巧的方法是把下一次的死活状态保存在第二个 bit 位，把整个矩阵处理完之后复位。

# 290
用两个dict同时记录原像和像。或者用一个dict记录双向。
以下代码采用了前者。
```python
class Solution:
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        domain, rng = {}, {}
        list1 = str.split()
        if len(list1) != len(pattern): return False
        for i, ch in enumerate(pattern):
            img, inv_img = rng.get(ch), domain.get(list1[i])
            if img or inv_img:
                if img != list1[i] or inv_img != ch: 
                    return False
            domain[list1[i]] = ch
            rng[ch] = list1[i]
        return True
```

# 292
观察发现$4 \mid n$时先手必败，其余情况下必胜。

# 299
水

# 300
LIS模板题。

# 303
前缀和

# 304
二维前缀和

# 306
842 的退化版本

# 307
树状数组

# 309
对原来题目的DP方程稍作修改即可。

# 311
非常古典的稀疏矩阵乘法。时间复杂度大约是前后两个矩阵非 0 元素个数的积？
```cpp
class Solution {
public:
    vector<pair<int, int>> vecm[1005], vecp[1005];
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), p = B[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (A[i][j] != 0)
                    vecm[i].push_back(make_pair(j, A[i][j]));
        for (int j = 0; j < p; ++j)
            for (int i = 0; i < n; ++i)
                if (B[i][j] != 0)
                    vecp[j].push_back(make_pair(i, B[i][j]));
        vector<vector<int>> ans(m, vector<int>(p, 0));
        for (int i = 0; i < m; ++i) {
            if (vecm[i].empty()) continue;
            int sizm = vecm[i].size();
            auto& vm = vecm[i];
            for (int j = 0; j < p; ++j){
                if (vecp[j].empty()) continue;
                int sizp = vecp[j].size();
                auto& vp = vecp[j];
                int lp = 0, rp = 0;
                while (lp < sizm && rp < sizp){
                    if (vm[lp].first < vp[rp].first) ++lp;
                    else if (vm[lp].first > vp[rp].first) ++rp;
                    else 
                        ans[i][j] += vm[lp].second * vp[rp].second, 
                        ++lp, ++rp;
                }
            }
        }
        return ans;
    }
};
```

# 313
n指针

# 315
经典逆序对。

# 318
用一个 int 来表示字母是否出现，然后 $O(n^2)$ 检查所有对即可。

# 319
大力推公式
```python
return int(n ** 0.5)
```

# 322
大力DP吧，没什么好说的。。。

# 324
先说明一个神奇的映射：对于$n$为奇数，$2i\mod n$可以实现把数组按下标的振动形式排序。如$0, 1, 2, 3, 4, 5, 6\rightarrow 0, 4, 1, 5, 2, 6, 3$。对于偶数的$n$，这个映射是$2i \mod {n-1}$，对于最后一个元素无效。
这是以0为下标起始的形式，如果以1为开始那么就有统一的形式$2i+1 \mod {(n \text{ or } 1)}$。
这样就可以先用nth_element找出中位数，然后
```cpp

```

# 326

## 方法一
循环。

## 方法二
对数。
```python
class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 1: return True
        if n <= 0 or n % 3 != 0: return False
        from math import log
        k = log(n) / log(3)
        return abs(k - round(k)) < 1e-9
```
## 方法三
如果不知道数据大小要用对数或者循环，知道的话判断$3^p \mod n$是否为$0$即可（因为$3$是质数），其中$\forall n, 3^p > n$。
```python
class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n > 0 and 1162261467 % n == 0
```

# 328
模拟

# 331
可以直接把问题转换为对叶子节点的验证。
```python
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        lst = preorder.split(",")
        deg = 1

        for idx, s in enumerate(lst):
            if deg == 0:
                return False
            deg += -1 if s == '#' else 1

        return deg == 0
```

# 333
如果看过 Software Foundations 就知道怎么从数学上更好的递归定义一个 BST。只需要用一个区间限定 BST 的值域即可。
```cpp
class Solution {
public:
    int ans;
    pair<pair<int, int>, int> dfs(TreeNode* cur){
        if (cur == nullptr) return make_pair(make_pair(INT_MAX, INT_MIN), 0);
        auto pl = dfs(cur->left), pr = dfs(cur->right);
        int siz = pl.second + pr.second + 1;
        if (pl.first.second < cur->val && pr.first.first > cur->val){
            ans = max(ans, siz);
            return make_pair(make_pair(min(pl.first.first, cur->val), max(pr.first.second, cur->val)), siz);
        }
        return make_pair(make_pair(INT_MIN, INT_MAX), siz);
    }
    int largestBSTSubtree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
```

# 337
简单树形DP

# 338
递推

# 341
用类似于前序遍历的方法即可。

# 342
先判断是不是$2$的幂，再开方看看开不开得出。或者判断`n & 0x55555555 == n`。

# 343
只拆分成2或者3

# 344
切片or函数。

# 345
双指针法，类似快排。注意大小写。

# 347
堆的经典应用之一——找前 $K$ 个最大元素的变形。用 Hash Table 来记录频率。
时间复杂度是 $O(N\log K)$。

# 349
set.intersection

# 350
用Counter或者dict之类。

# 355
可以直接暴力，也可以用 Top K 的方法遍历所有关注了的人的文章，然后找出最新的那些。

# 357
排列组合

# 361
水

# 365
大概可以猜出来是 Bezout 定理。至于怎么证明就 emmm
```cpp
if (!x && !y) return false;
if (x + y < z) return false;
return z % __gcd(x, y) == 0;
```

# 366
这就是一个假题，根本不是完全二叉树，就是普通二叉树。。。。

# 367
循环or二分or看开方是不是整数。

# 368
DP，先排序，这样只要保证前面的可以整除后面即可。
这么做还是$O(n^2)$，如果拿双联通分量来做是不是也是这个事件复杂度？
```cpp
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> f(n, 1), bef(n, -1);
        int ans = 0, maxi = -1;
        for(int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if(nums[j] % nums[i]) continue;
                if(f[i] + 1 > f[j]) f[j] = f[i] + 1, bef[j] = i;
            }
            if(f[i] > ans) ans = f[i], maxi = i; 
        }
        vector<int> aans;
        for (int i = 0, j = maxi; i < ans; ++i, j = bef[j])
            aans.push_back(nums[j]);
        return aans;
    }
};
```

# 370
差分数组

# 371
我用了`+`好像也没WA...?

# 372
欧拉降幂公式

# 373
经典的问题，用堆可以解决。
思想就是将第一个数组的每一个元素和第二个数组的元素从小到大相匹配，一开始将第一个数组的所有元素和第二个数组的第一个元素构成的序对放进堆里，每次找出最小的，然后将该序对中，第二个数组中元素的位置向后移动一位，再放进堆里，循环往复。
时间复杂度是 $O(k\log n)$。

# 374
水二分

# 375
简单的区间 DP。有一个小优化：每次取区间分点的时候从中点开始，虽然不太清楚原理。

# 377
无限背包的变形，注意有可能溢出（因为有可能根本没法组合成答案，而答案之外的某个数方案溢出）

# 380
一个简易的做法是保存一个 Hash Table 和一个数组，数组里保存元素，Hash Table 里面保存元素的下标。删除的时候把被删除的数和数组末尾的数交换，然后在 Hash Table 中清除该元素。这样就能做到每一个操作都是 $O(1)$。

# 381
基本和 380 一样。

# 383
统计字符数，看看magazine中的字符够不够。

# 387
统计字符数，找最靠前的只出现一次的字符。

# 389
统计字符数，作差。

# 390
子结构非常明显

# 393
字符串的解释方法是唯一的，所以只需要判定每一个字符是否符合要求即可。

# 396
看这种循环移位形式就知道是要将数组复制一份。复制一份，然后就是简单的推公式。

# 397
贪心，模4余3选择+1，模4余1选择-1。注意神奇的2147483647。

# 398
写了一个 unordered_map 套 vector 的大暴力，还算是卡了过去。
真正的解法是被称为流水线取样的方法。

# 400

## 方法一
先找最高位然后一位一位向下找。推公式。
```python
class Solution:
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        i, t, ten = 9, 1, 1
        while n > i * t:
            n -= i * t
            i *= 10
            t += 1
            ten *= 10
        # 寻找所在数字的位数
        
        ans = (1 + (n - 1) // (ten * t)) * ten
        n -= t * ten * (ans // ten - 1)
        ten //= 10

        for j in range(t - 1, 0, -1):
            i = 0
            while n > (i + 1) * t * ten:
                i += 1
            n -= i * t * ten
            ans += i * ten
            ten //= 10

        for j in range(0, t - n):
            ans //= 10
        return ans % 10
```
## 方法二
可以在做完一层就补上前面一层缺少的位数，然后直接找到第$n$位属于哪一个数字。
```python
class Solution:
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 10:
            return n
        i, p = 1, 9
        while True:
            n += p
            p = p * 10 + 9
            i += 1
            if n < i * p:
                return int(str((n + i - 1) // i)[(n + i - 1) % i])

        """ 核心思想是补余。
            寻找的顺序如下：
            1 2 3 4 ... 9
            -> 01 02 03 ... 99
            -> 001 002 003 ... 999
            所以n加的是p而不是i*p。只补上了前面的位数，与后面相齐。 """
```

# 401
大力枚举

# 402
单调栈。注意删掉某些数字之后产生的前导零

# 405
可以通过直接对 unsigned int 类型赋值来获取要转换的数。

# 406
从高到低向队列里插入人

# 409
统计字符数，对于一种字符，如果有$2k+1$个就取$2k$个，否则全取。最后如果存在某种字符是奇数个就令其在中间，并且补上之前这种字符没取的那个。

# 412
大水题

# 413
可以看出所有的等差数列都是成段的。只要把这些段全部找到，然后算下即可。

# 414
维护第一，第二，第三大数。

# 415
简单的高精度加法

# 416
水DP

# 421
Trie模板题

# 423
按照 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 和字母 z, w, u, x, g, o, r, f, v, i 的顺序计算。
计算完一个数字就减掉这个数字包含的字符个数。
```cpp
class Solution {
public:
    string originalDigits(string s) {
        int cnt[26] = {0}, tot[10] = {0}, totu = 0;
        string ans;
        for (char c: s) ++cnt[c - 'a'];
        tot[0] = cnt['z' - 'a'];
        cnt['o' - 'a'] -= cnt['z' - 'a'], cnt['r' - 'a'] -= cnt['z' - 'a'];
        tot[2] = cnt['w' - 'a'];
        cnt['o' - 'a'] -= cnt['w' - 'a'];
        tot[4] = cnt['u' - 'a'];
        cnt['o' - 'a'] -= cnt['u' - 'a'], cnt['r' - 'a'] -= cnt['u' - 'a'], cnt['f' - 'a'] -= cnt['u' - 'a'];
        tot[6] = cnt['x' - 'a'];
        cnt['i' - 'a'] -= cnt['x' - 'a'];
        tot[8] = cnt['g' - 'a'];
        cnt['i' - 'a'] -= cnt['g' - 'a'];
        tot[1] = cnt['o' - 'a'];
        tot[3] = cnt['r' - 'a'];
        tot[5] = cnt['f' - 'a'];
        cnt['v' - 'a'] -= cnt['f' - 'a'], cnt['i' - 'a'] -= cnt['f' - 'a'];
        tot[7] = cnt['v' - 'a'];
        tot[9] = cnt['i' - 'a'];
        for (int v: tot) totu += v;
        ans.reserve(totu);
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < tot[i]; ++j)
                ans.push_back(i + '0');
        return ans;
    }
};
```

# 427
常数谜之巨大

# 429
简单BFS

# 430
这是一个比较明显的递归结构，递归展开即可。

# 434
```python
return len(s.split())
```

# 437
二重递归或者拿一个unordered_map统计。

# 438
维护一个值$a$表示当前一个区间内有多少种字符数目和模板内该字符数目不同，然后移动更新$a$。
类似滑动窗口。
```python
class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        
        def oord(x):
            return ord(x) - 97

        list1, num = [0] * 26, 0
        for i in p:
            idx = oord(i)
            list1[idx] += 1
            if list1[idx] == 1: num += 1
            
        list2, cnt = [0] * 26, 0

        def calc(o, x):
            nonlocal cnt, list2
            idx = oord(x)
            if list2[idx] == list1[idx]: 
                cnt = cnt - 1
            list2[idx] += o
            if list2[idx] == list1[idx]: 
                cnt = cnt + 1

        len1, len2, ans = len(p), len(s), []
        
        if len1 > len2: return ans

        for i in range(0, len1):
            calc(1, s[i])

        if cnt == num:
            ans.append(0)
        
        for i in range(len1, len2):
            calc(-1, s[i - len1])
            calc(1, s[i])
            if cnt == num:
                ans.append(i - len1 + 1)

        return ans
```

# 441
二分。

# 442
基于和 448 相同的想法（~~这题完全就是 448 换了个说法吧~~）

# 443
算出每一段相同字符的数目然后在原列表中加上去（用切片插入，否则报错）。
本地修改也是可以的，稍微麻烦，可以参考下面的代码（来自[这里](https://leetcode.com/problems/string-compression/solution/)）。
```python
class Solution(object):
    def compress(self, chars):
        anchor = write = 0
        for read, c in enumerate(chars):
            if read + 1 == len(chars) or chars[read + 1] != c:
                chars[write] = chars[anchor]
                write += 1
                if read > anchor:
                    for digit in str(read - anchor + 1):
                        chars[write] = digit
                        write += 1
                anchor = read + 1
        return write
```

# 445
可以先记录链表的长度，然后反序保存高精度加法的结果（先不进位），然后再处理进位。

# 447
暴力统计

# 448
由于一个数只可能出现一或两次，一个性质成立：当第$i$个位置上的数不是$i$的时候，这个位置上的数就缺失了。
所以构造一个“排序”：对每一个$i$，如果$i$位置上的数不是$i$，而是$k$，就将$i$与$k$位置的数交换，直到这两个要交换的数相同为止。
可以看出这个算法是线性的，因为一次交换就会导致一个数回到原来的位置，而只有$n$个位置，所以至多交换$n$次。
```python
class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        len1 = len(nums)
        for i in range(0, len1):
            while nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        
        lst = []
        for i in range(0, len(nums)):
            if nums[i] != i + 1:
                lst.append(i + 1)

        return lst
```

# 449
其实和序列化和反序列化二叉树基本没什么区别，可能有一点区别在于可以只传输没有放置外部节点的前序遍历，然后利用搜索树性质获取中序遍历并且重建。
后者在解码的时候理论上效率会差一点，因为要加上一个排序的过程。

# 450
BST 基本操作

# 451
基本同791

# 453
$n-1$个元素同时增相当于剩下一个元素自己相对其他减，当每一个数相对大小相等就停止。因此可以统计所有元素的和$sum$和找出最小元素$mini$，那么$sum-mini$就是答案。这是所有非最小元素“减到”和最小元素相同的次数。
```python
class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum, mini = 0, 3000000000
        for i in nums:
            sum += i
            if i < mini:
                mini = i
        return sum - mini * len(nums)
```

# 454
先把两个数列组合起来，然后对其中一个做索引，另一个遍历一遍即可。

# 455
排序之后贪心，尽量给完。

# 456
考虑从右向左，找出一对逆序对，然后保证逆序对中较小的元素尽量大。这个过程可以用单调栈来实现。
```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        stack<int> st;
        int maxi = INT_MIN, n = nums.size();
        for (int i = n - 1; i >= 0; --i){
            if (nums[i] < maxi) return true;
            while (!st.empty() && nums[i] > st.top())
                maxi = max(maxi, st.top()), st.pop();
            st.push(nums[i]);
        }
        return false;
    }
};
```

# 458
本质是进制问题，或者状态空间之类的。可以归纳。
```python
class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        """
        :type buckets: int
        :type minutesToDie: int
        :type minutesToTest: int
        :rtype: int
        """
        if buckets == 1: return 0
        tot, ans = minutesToTest // minutesToDie, 1
        while (tot + 1) ** ans < 1.0 * buckets:
            ans += 1
        return ans
```

# 459
可以枚举总长度的倍数然后看子串是不是能拼出总串。更快的方法是看原串是否可以通过循环移位得到。具体写法是：
```python
return s in (s + s)[1: -1]
```

# 461
异或然后统计1的个数。

# 462
中位数的应用

# 463
BFS都不要

# 468
细节比较多

# 469
to-left 测试

# 470
并不是很懂这个题是怎么判定的，大概只要足够随机就行？

# 474
二维01背包

# 475
排序后贪心or二分。

# 476
利用反码=补码-1。

# 477
每一位分别计算

# 478
这题有两个方法：一个是在外切正方形里面做，不在圆内的点舍弃；或者用极坐标来做。
但是极坐标在取半径的时候不能均匀取半径，否则靠近圆心的部分会更加密集一些。这个结论可以通过概率论来证明，不过可以直观地理解成：在等距离分布的情况下，由于外周的周长更大，所以外周上的点更加稀疏，进而靠近圆心的部分更加密集。
可以证明，要想真正的均匀分布，半径的取值应该是 $r=R\sqrt {\text{random number}}$。

## 方法一（拒绝取样）
```cpp
class Solution {
public:
    double r, x, y, pi;
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
        srand(19722232);
    }
    
    vector<double> randPoint() {
        double a, b;
        for (; ; ){
            a = (2.0 * rand() / RAND_MAX - 1.0) * r;
            b = (2.0 * rand() / RAND_MAX - 1.0) * r;
            if (a * a + b * b > r * r)
                continue;
            else break;
        }
        return vector<double>{x + a, y + b};
    }
};
```

## 方法二（极坐标）
```cpp
class Solution {
public:
    double r, x, y, pi;
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
        pi = 2.0 * acos(-1);
        srand(2131231);
    }
    
    vector<double> randPoint() {
        double a = r * sqrt(1.0 * rand() / RAND_MAX);
        double b = pi * rand() / RAND_MAX;
        double xx = a * cos(b), yy = a * sin(b);
        return vector<double>{x + xx, y + yy};
    }
};
```

# 479

## 伪·正解
直接输出答案。
```python
class Solution:
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = [9, 987, 123, 597, 677, 1218, 877, 475]
        return ans[n - 1]
```
## 正解
（这种方法来自[这里](https://leetcode.com/problems/largest-palindrome-product/discuss/96294/could-any-python-experts-share-their-codes-within-100ms)）

可以发现，当$n>1$的时候最大的回文乘积都是偶数长度的（因为最高位都可以是$9$）。设最大的回文乘积为$U\times 10 ^ n + D = M\times L$。那么可以看出$U$和$D$是顺序恰好相反的两个数。
设$M = 10^n - i$，$L = 10^n - j$，那么$M\times L = 10^{2n} - (i + j) \times 10^n + ij$。如果$i\times j < 10^n$（这表明$i$和$j$可以很小，而这个结论适用于$n>1$），那么可以得到$U = 10^n - (i + j)$，$D = i \times j$。
这样我们设$a = i + j$，然后求出$U$，再根据$D = i \times (a - i)$解出整数$i$，解出来就成功了！
实际上这还不是最优的。通过实验可以发现当$n$是偶数的时候有确定的解，其中$i = 1, j = 10^{\frac{n}{2}} +1$。所以只要对$n$为奇数的情况求解即可。
```python
class Solution:
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 9
        p = 1
        for i in range(0, n):
            p *= 10
        if n & 1 == 0:
            return (p - 1) * (p - int(p ** 0.5) + 1) % 1337
        for a in range(2, p):
            u = p - a
            l = int(str(u)[: : -1])
            if a ** 2 - 4 * l >= 0:
                i = a + (a ** 2 - 4 * l) ** 0.5
                if i // 2 == i / 2:
                    return (u * p + l) % 1337
```

# 482
字符串模拟。

# 485
水

# 486
博弈论形式的 DP。

# 494
水DP

# 496
排序后从小到大，寻找每一个数$x$在原数组中右边的第一个元素，然后把$x$从原数组删去，如此反复。
也可以维护一个递减的单调栈，从而得到答案。

# 498
找规律

# 500
水

# 501
用三个变量分别维护当前统计元素、出现次数和最大出现次数。
~~所以我真的不知道不用额外空间怎么做。。。这可能吗？~~

# 503
数组复制一遍，单调栈。节省空间的话可以不用复制

# 504
简单进制转换

# 506
水

# 507
简单质因数分解。

# 509
水

# 518
完全背包

# 520
简单模拟

# 521
过于水

# 523
对前缀和取模并且统计

# 525
把0变-1，寻找相同大小的前缀和。

# 528
在前缀和上面二分即可。

# 530
记录一下前驱就行了。

# 532
排序后用指针

# 536
注意值可以是负数

# 537
水

# 538
水

# 539
水

# 540
按照元素出现位置二分

# 541
水

# 542
水BFS

# 543
考察树的高度

# 547
并查集

# 551
模拟

# 553
第一个元素必然为分子，第二个元素必然为分母。其余的位置可以变。所以全部放在分子上。
```python
class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        if len(nums) == 1: return str(nums[0])
        if len(nums) == 2: return str(nums[0]) + "/" + str(nums[1])
        s = str(nums[0]) + "/("
        for i in nums[1: -1]:
            s += str(i) + "/"
        s += str(nums[-1]) + ")"
        return s
```

# 554
用堆的解法应该是最容易想到的，实际上只要用一个 Hash Table 存一下墙缝就行了。。。

# 556
本质是求下一个排列

# 557
```python
return " ".join([ss[: : -1] for ss in s.split()])
```

# 559
水

# 560
利用 Hash Table 保存前缀和，扫一遍即可。

# 561
排序

# 562
横竖斜坐标系

# 563
水

# 565
其实就是找置换的循环节

# 566
模拟

# 567
滑动窗口统计字符

# 572
这个题数据小，可以乱搞。
可以将树序列化（这里要区分左右空节点，同时在节点值前面加入标识符防止 [23, 4, 5] 和 [3, 4, 5] 这样匹配事故的发生，具体看官方题解；或者直接转化成括号序列），也可以对每一个子树做一次匹配。
但我觉得最好的方法还是树 Hash，树 Hash 应该可以做到线性的时间复杂度。

# 575
水

# 576
水 DP

# 589, 590
基本同二叉的情况

# 593
正方形是菱形也是矩形，说明对角线相等并且四条边相等。依照这个对边排序计算即可。或者直接暴力枚举。

# 594
直接使用 Hash Table 统计相邻元素。

# 598
水

# 599
枚举索引和，然后判定

# 605
水，注意开头和结尾两个段

# 606
类似于树的括号表示方法

# 617
简单的递归合并。
速度有点慢？

# 623
水

# 628
找最大的三个数和最小的两个数，取最大数和最小两数积与最大三数积更大者。

# 633

## 方法一
查表。
```python
class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        list1 = [i * i for i in range(0, 65536)]
        
        i, j = 0, 65535
        while 2 * i * i <= c:
            while list1[j] > c - i * i:
                j -= 1
            if i * i + list1[j] == c:
                return True
            i += 1
        return False
```
## 方法二
双指针$l, r$，分别从$0$和$\sqrt{c}$向中间逼近。
```python
class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        i, j = 0, int(c ** 0.5) + 1
        while i <= j:
            res = i * i + j * j
            if res == c:
                return True
            elif res < c:
                i += 1
            elif res > c:
                j -= 1
        return False
```

# 637
水

# 638
记忆化搜索

# 640
稍微要考虑一下的模拟。注意 `0x` 这种坑人的东西。

# 641
水

# 646
水 DP

# 647
偷懒就用 $O(n^2)$ 的方法，或者用 Manacher 也可以。

# 650
可以DP，但是效果很差劲。。。实际上根据DP方程可以发现产生的字符数目一定是某几个数的乘积。因此可以归纳得出：质数只能一个一个得到，然后两个质数的积的答案就是两个质数的和，质数的幂等同于多个质数相乘。所以做一次质因数分解即可。

# 652
树 Hash

# 654
分治法找最大值

# 657
水

# 661
水

# 662
用类似于完全二叉树的方式给节点编号来做。
但这个题有一个非常变态的地方在于会出一些神奇数据，比如树直接退化成一条链，然后所有非叶子节点只有右子树。这样用 int 或者 long long 都会炸的很惨。
这时要么用 unsigned long long 大力卡过去，要么用 Python 大力卡过去。但这些都是奇技淫巧。
（等待正确做法，所以）

# 665
小贪心

# 670
小贪心

# 671
其实就是求左右子树中最小的数（不和根相同）。。。写炸了。（不过性能好像还行）

# 672
找规律。本质是异或操作的叠加。

# 673
经典DP题，在原来DP数组的基础上加一个计数数组即可。时间复杂度$O(n^2)$。

# 674
水

# 676
使用 Trie，同时枚举要改变字符的位置。

# 677
简单的 Trie 树应用

# 686
将 A 重复到长度大于或者等于 B，然后暴力匹配。这里用到的是循环移位的性质。

# 690
这是一个显然的树结构。

# 693
```cpp
unsigned int res = (n ^ (n >> 1)) + 1u;
return (res & (res - 1)) == 0;
```

# 695
傻逼BFS

# 696
每次维护两个不同字符的相同段，这两个段的贡献是较短的段的长度。

# 697
水

# 700
尾递归

# 701
BST 基本操作

# 703
经典堆问题

# 704
二分查找模板题

# 705
拿 bitset 水过了，但总感觉不太好。。。

# 707
水

# 709
大水题

# 712
DP

# 713
维护两个指针或者直接暴力向前取，只要保证把1跳过就行。

# 717
因为是无前缀的编码所以可以直接扫一遍。更好的做法是发现最后两个相邻 0 之间必须有偶数个 1 才能满足条件。

# 718
这是一个非常经典的问题：最长公共子串。当然，在这里因为数据量比较小，所以可以直接用 DP 做。
当然还有万能的字符串 Hash。

# 720
以长度为第一键值，字典序为第二键值对字符串排序，然后按不同长度暴力即可。

# 721
并查集

# 724
水

# 725
水

# 728
一一判断。

# 729
大暴力，或者二分。（数据比较小，暴力写起来很顺手）

# 735
拿栈模拟一下

# 738
注意要改变的那一位是否是 1，有这个判断即可。

# 739
单调栈的经典应用。

# 740
排序后变成DP

# 746
DP

# 747
水题

# 754
按奇偶性找规律，本质解方程。
```python
class Solution:
    def reachNumber(self, target):
        """
        :type target: int
        :rtype: int
        """
        if target == 0:
            return 0
        if target < 0:
            target = -target
        
        l, r = 1, target
        while l < r:
            mid = (l + r) >> 1
            if target <= mid * (mid + 1) // 2:
                r = mid
            else:
                l = mid + 1
        
        return ((l + 1) >> 1) << 1 | 1 if (((l + 1) >> 1) - target) & 1 else l
```

# 758
暴力模拟

# 762
直接暴力就行了。

# 763
贪心

# 766
水

# 767
模拟一下。我的做法是按照出现次数排序，然后按照频率从大到小隔位放置字母。

# 769
没有重复的话只需要检查子区间排序后是否与排序后的这一部分相同。特别的，我们只需要判断子区间上的最大值和最小值是否与排序后这一部分的最值相同。

# 771
```python
return sum([1 for c in S if c in J])
```

# 775
可以直接用逆序对的模板。不过利用原数组是一个排列的性质更好，通过观察可以发现局部倒置一定不大于全局倒置。那么我们只需要判断是否存在额外的全局倒置即可。
另外还可以发现全局和局部倒置数量相同当且仅当原排列中元素移动的距离不超过 1。即 $|A[i] - i|\le 1$。按照这个判断即可。
（可能需要证明一下）

# 777
注意到操作前后非X字符的相对顺序不会变化，且R只能向右移动，L只能向左移动。模拟即可。

# 779
找规律，奇数行对折，偶数行取反后对折。

# 781
提取数组为可重集形式，对 $(k, v)$ 的键值对统计答案为 $(v+1)\lceil \frac{k}{v+1}\rceil$。求和即可。

# 783
min gap 问题，排序解决。

# 784
枚举子集，可以用格雷码加速。

# 785
水

# 787
$O(NK)$ 最短路，这个是一个经典问题来着？只要做 $K$ 轮的松弛操作就行了。

# 788
仔细读题

# 789
答案是 true 当且仅当对任何一个鬼，其和目标的曼哈顿距离大于原点到目标点的曼哈顿距离。

# 790
递推式
$$
f[i] = f[i - 1] + f[i - 2] + 2\sum_{j = 1}^{i - 3} f[j]
$$

# 791
自定义优先级即可

# 794
先数一数每一种字符的数目。如果 X 比 O 多一个就保证后手不胜利，如果 X 和 O 一样多就保证先手不胜利，其他情况都是非法的。

# 795
可以用单调栈做

# 796
水

# 797
大力 DFS

# 801
不是很水的 DP

# 804
set 去重

# 809
简单模拟

# 811
简单的统计

# 812
数据比较小，可以暴力。大的话凸包+旋转卡壳

# 813
大力DP

# 814
递归清除左右子树，如果发现自己成了 0 叶子就说明自己这棵子树全是 0，于是自我清除。

# 817
用一个 bitset 将所有列表中的数记录下来，然后在链表上遍历一遍即可。

# 820
把字符串都反转一下然后按长度从大到小贪心即可。结合 Trie。

# 821
这个，没什么好说的。。。每次处理两个相邻的 C 即可。

# 822
只要两面是不同的数就可能作为答案。

# 829
手推公式，发现可以做到 $O(\sqrt{N})$。

# 832
水

# 833
一边扫描一边替换即可。

# 840
简单模拟

# 841
水 BFS

# 842
暴力，注意前两个数可以比较小
```python
class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        l = len(S)
        lst = []
        for i in range(1, (2 * l) // 3):
            for j in range(0, (i + 1) // 2):
                if S[0] == "0" and j + 1 != 1:
                    break
                if S[j + 1] == "0" and i - j != 1:
                    continue
                
                lst.append(int(S[0: j + 1]))
                lst.append(int(S[j + 1: i + 1]))

                cur = i + 1
                flag = 1
                while cur < l:
                    nxt = lst[-1] + lst[-2]
                    ll = len(str(nxt))
                    if ll + cur > l or int(S[cur: cur + ll]) != nxt or nxt >= 2147483648:
                        flag = 0
                        break
                    lst.append(nxt)
                    cur += ll

                if not flag:
                    lst.clear()
                    continue
                else:
                    return lst
        return lst
```

# 848
水

# 849
水

# 851
简单的 DAG DP。

# 852
简单的三分

# 855
一种做法的大致思想是：保存区间的左端点，和其对应长度的一半，用一个 set 来存，然后每次选出区间长度最大的那个，将数插入后一分为二；删除的时候将原来被分割开的两个区间合二为一。
实际上好像有更优秀的做法。

# 856
可以用栈模拟，也可以直接通过数括号记录深度，然后对单独的括号 `()` 计算分数。分数就是 `1 << dep`。

# 858
讨论 $\frac{\operatorname{lcm}\left(p, q\right)}{p}$ 和 $\frac{\operatorname{lcm}\left(p, q\right)}{q}$ 的奇偶组合即可。

# 859
先判断长度是否完全相同，再判断是否存在这样两个字符。

# 860
贪心

# 861
贪心，先把第一列反转到最大，然后再依次看后面每一列能不能反转到 1 比 0 多。

# 863
如果这个树使用邻接表保存的话事情会方便很多，但是这里比较可惜，不是。
所以可以用一个 Hash Table，先找到目标点，然后求出目标点的所有祖先到其的距离，然后再一次 DFS 算出所有点到其的距离。
实际上修改一下应该是可以去掉 Hash Table 的。

# 865
和 1123 差不多（我先做的 1123）

# 866
打表方法不是很难。如果要做在线判断的话可以考虑先二分出起始位置然后枚举回文数。
实际上有一个性质非常强的剪枝：**偶数长度的回文数全都不是质数**。因为它们全部可以被分解为形如 $1000...0001n$ 之和的形式，其中 $0$ 的个数是偶数个。而 $1000...0001 - 11 = 999...9990$，$9$ 的个数也是偶数个。所以必然被 11 整除。加上这个剪枝就能跑的很快了。
没加上也无所谓，反正在判定质数的时候会很早被 11 毙掉。

# 867
模拟

# 868
水，可以看出python字符串很慢？

# 869
水

# 870
排序后贪心：从 B 中最小的数开始，找 A 中第一个大于它的数，然后继续对 B 中次小的找对应的，以此类推。

# 872
水

# 873

## 方法一
大力枚举，由于斐波那契数的增长速度是指数级别的，所以总序列长度大约是 $\log$ 级别的。所以总时间复杂度是 $O(n^2\log m)$。$m$ 可以看作是序列中的最大数。

# 874
用数据结构（比如 Hash Table 或者是 Set）来保存所有的障碍点，然后直接模拟即可。

# 875
二分

# 877
DP 或者数学。因为先手必然可以取走所有编号奇偶性相同的堆，而编号全为奇数的堆总和和编号全为偶数的堆总和中必然有一个相对更大的，因此先手必胜。
```python
return True  # 就是这么自信。
```

# 883
从侧面，每一行/列的面积就是本行/列的最大值。

# 884
用Counter

# 886
二分图判定

# 888
只要找一组解就很简单

# 890
保存字符之间的双射即可，对每一个单词做一遍。
好像前面有非常类似的题目。

# 893
按下标奇偶性拆分字符串，排序后重组，再用set去重。

# 896
水，可以遍历两遍或一遍，这取决于写法。

# 901
单调栈

# 905
双指针交换或者新开两个数组。

# 908
找最小值$+K$和最大值$-K$之间关系。

# 910
将序列排序，然后选取前 $i$ 个元素加上 $K$，后 $n-i$ 个元素减去 $K$。这样总共就存在 $A[i]-A[0], A[n-1]-A[i+1], |A[i + 1] - A[0] - 2K|, |A[n - 1] - A[0] - 2K|, |A[i + 1] - A[i] - 2K|, |A[n - 1] - A[i] - 2K|$ 六个作为最大值的选择（实际上有一些是冗余的）。对每一个 $i$ 判断一下即可。
事件复杂度 $O(n\log n)$。

# 912
？

# 914
最大公约数。

# 916
先对 B 中每一个单词做一次字符统计，取 max 后再在 A 中统计。

# 917
双指针

# 918
用单调队列是非常睿智的做法。。。
要么是中间的一段被选，要么是中间的一段**不被选**。二者择其一即可。

# 919
模仿堆插入思路

# 921
直接对右括号进行匹配，然后剩余的左括号和右括号数目和就是答案。

# 922
水

# 925
字符串分段，比较段长。

# 926
水

# 929
简单的字符串处理。

# 931
水 DP

# 932
构造层级结构。
可以发现一个数列$$A_n$$保持了这个性质，那么对$$A_n$$的每一项加（或者减）去一个定值或者乘上一个非零数也会保持这样一个性质。从而构造递归结构：
基础：$n=2$，答案是$1, 2$。
向上：$n=2^k\rightarrow n=2^{k+1}$，$n=2^k$时答案是$$A_k$$，$n=2^{k+1}$时答案是$$2A_k-1$$和$$2A_k$$相连接。
```python
class Solution:
    def beautifulArray(self, N):
        """
        :type N: int
        :rtype: List[int]
        """
        lst, len1 = [1], 1
        while len1 < N:
            lst = [(i << 1) - 1 for i in lst] + [i << 1 for i in lst]
            len1 <<= 1
        return [i for i in lst if i <= N]
```

# 933
模拟

# 934
先找一个岛，然后一层一层向外扩张。代码可能有点长。

# 935
简单的线性递推

# 937
注意字母排序指的是对每一个字形成的列表进行字典序排序。

# 938
水

# 939
暴力枚举矩阵的对角上两个点，然后查找能不能找到另外两个点。

# 941
注意边界

# 942
一种做法是求出相对高度数组。设第一个数的高度为$0$，维护当前最大上升量$up$和最大下降量$down$，遇到I则该位相对高度为$up$，并上升量$+1$，遇到D则该位相对高度为$down$，并下降量$-1$，如此可以保证每一位上的相对高度都不同，然后按照相对高度分配$0, 1, \cdots, n$即可。

# 944
简单比较，注意这个题目中的有序指的是字母的ASCII码不递减。

# 945
排序然后暴力自增就行。正确性不显然。
```cpp
int ans = 0, n = A.size();
sort(A.begin(), A.end());
for(int i = 1; i < n; ++i){
    if (A[i - 1] >= A[i])
        ans += (A[i - 1] + 1 - A[i]), 
        A[i] = A[i - 1] + 1;
}
return ans;
```

# 946
模拟出栈即可。

# 947
按照在同一行或者同一列的关系将点连起来建图，一个连通块内的元素总可以被消去的只剩一个。所以只要找出联通块数目即可。
这个可以用并查集维护。

# 949
小模拟

# 950
双端队列模拟一下即可。

也可以用类似于约瑟夫的方法做，或者使用一些奇怪的递归方法。

# 952
节点值唯一很简单。

不唯一呢？

# 954
首先，正数、0、负数的数目都必须是偶数；然后正数和负数的绝对值分别排一个序，从小到大确认即可。

# 957
循环节

# 958
貌似这个题目只能用 BFS 去做。。。
判断准则是两条：
1. 不存在只有右儿子，没有左儿子的节点。
2. 叶子出现顺序连续。如果只有左儿子，那么下一个节点一定是叶子。

# 961
用bitset大力弄过。或者考虑元素之间的关系，这$N$个数要么相邻，要么全部间隔为1。依照此原则判断。

# 965
水

# 969
经典问题，每一次先把最大值翻到底即可。
这个问题的最坏情况就是 $2n$，所以标准还是比较松的。

# 970
水

# 973
K小堆

# 974
记录余数方案数目

# 976
经典题目，对边长排序，然后可以组成最大三角形的三条边在排序之后的数组里面一定是连续的。依照这个枚举判定即可。

# 977
找到负数和非负数的分解，双指针即可。

# 978
小模拟

# 981
同 1146

# 983
简单 DP

# 984
模拟

# 985
水

# 989
普通高精度加法

# 990
简单并查集

# 991

## 方法一
每一次的操作都可以归结为：$X$ 减一点，然后乘 $2$；$X$ 减一点，然后乘 $2$；循环往复。那么最后就有式子 $2^nX-\sum_{i=0}^{n}2^i a_{i} = Y$，而这里的代价就是 $n+\sum_{i=0}^{n}a_{i}$。

猜想这里的代价是一个单谷函数，所以当代价上升的时候立即停止。

## 方法二
神奇贪心？（等待补充）

# 993
记录一下深度即可。

# 994
水BFS

# 997
判入度，出度即可。

# 998
不断向右子树移动即可。

# 999
水

# 1002
水

# 1004
类滑动窗口，注意$K=0$的神奇情况。

# 1005
水，但是情况比较多

# 1006
模拟

# 1007
暴力

# 1008
偷懒的做法是直接把 105 的方法搬过来，然而利用 BST 性质会更加简洁一些。

# 1009
简单位运算

# 1010
水

# 1011
水二分

# 1013
双指针

# 1014 
水

# 1015
等价于寻找 $t$ 使得 $10^t\equiv 1 \pmod{9K}$，用欧拉定理，结合指数循环节即可。

# 1016
最简单的方法是枚举子串，然后判断 1 到 N 之间的数是不是全占了。实际上没必要，因为 $[2^(k-1), 2^k-1]$ 这个区间中的数包含了所有 $[0, 2^(k-1))$ 的数（这里包含是指子串意义上的），所以我们可以只需要判断离 $N$ 最近的 $2^k$ 长度的区间，并上长度不满 $2^k$ 的以 $N$ 为右端点的区间即可。

# 1017
求负的二进制。具体流程和求二进制基本相同，求出对-2的余数的绝对值，减掉这个绝对值然后除以-2，直到0为止。
可以看出把-2替换为别的正整数就是求正进制表达的方法。

# 1018
水

# 1020
简单 BFS 或者 DFS

# 1021 
水

# 1022
DFS

# 1023
小模拟

# 1024
$O(n^2)$ 的 DP，以位置和公差为状态转移。虽然想法容易，但是空间有点太大了。所以折衷使用 unordered_map 代替转移数组。这样空间理论上也是 $O(n^2)$。

# 1033
先对三个石头的位置排序，然后最大的移动次数就是最远-最近-2，最少的移动次数特判间距为1和间距为2的两个情况。

# 1034
先找联通块，然后判定是否是边界，修改即可。

# 1035
本质 LCS

# 1037
先判断三个点是否不同，然后再判断是否共线。

# 1038
在中序遍历上跑一个前缀和，然后按照中序遍历把值赋回去。

# 1039
其实就是一个简单的区间DP，但当初想得谜之复杂，就没做出来。。。
实际上为了避免点之间的循环顺序，只需要考虑某一段点之间，第一个点和最后一个点相连的边对应的三角形。

# 1040
这个题目思想非常有意思。我们先对列表排序。

对于最大的情况，不难想到，只需要让最左的两个元素或者最右的两个元素合在一块，然后不断向另一个方向“滚”，就可以达到在另一个端点处所有元素合在一起。两种情况取较大的即可。

对于最小的情况，我们可以构造以某个元素为起点、长为 $n$ 的区间，让所有元素落在这个区间内。这样需要移动次数就是 $n$ 减掉不在区间内的元素个数。我们枚举一下这个起点即可。

注意，有一个特例：如果存在一个元素落单，而其他所有元素抱团，且这两个部分相隔大于 $1$ 时，最少移动次数就是 2 而不是 1。

```py
class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        stones.sort()
        n = len(stones)
        maxi = max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - n + 1
        if stones[0] < stones[1] - 2 and stones[n - 1] - stones[1] == n - 2:
            return [2, maxi]
        if stones[n - 1] > stones[n - 2] + 2 and stones[n - 2] - stones[0] == n - 2:
            return [2, maxi]

        i, j = 0, 0
        mini = 2000000000
        while i < n:
            while j < n and stones[j] - stones[i] <= n - 1:
                j += 1
            mini = min(mini, n - j + i)
            i += 1
        return [mini, maxi]
```

# 1041
能够走出圈的充要条件是末状态朝向不变和行动距离大于1。

# 1042
水四染色

# 1043
水DP

# 1071
水

# 1072
bitset 搞一下

# 1073
负进制数加法

# 1078
水

# 1079
水排列组合

# 1080
树上 DP

# 1081
这个题目有点厉害。。。
用栈来做贪心，如果当前字典序比栈顶小，又有栈顶在后面还会出现，就把栈顶弹出，最后把当前字符置顶。
这种贪心的题目果然还是不擅长
```cpp
class Solution {
public:
    string smallestSubsequence(string text) {
        int cnt[26] = {0}, n = text.length();
        bool vis[26] = {0};
        for (int i = 0; i < n; ++i)
            ++cnt[text[i] - 'a'];
        string ans;
        for (int i = 0; i < n; --cnt[text[i] - 'a'], ++i){
            if (vis[text[i] - 'a']) 
                continue;
            while (!ans.empty() && text[i] <= ans.back()){
                if (!cnt[ans.back() - 'a'])
                    break;
                vis[ans.back() - 'a'] = false, ans.pop_back();
            }
            vis[text[i] - 'a'] = true, ans.push_back(text[i]);
        }
        return ans;
    }
};
```

# 1089
双指针

# 1090
简单的堆题目

# 1091
简单 BFS

# 1093
简单统计

# 1094
借教室？注意左闭右开

# 1103
简单的找规律

# 1104
只要在奇数深度把标号倒置一下即可。其他基本同堆式查找。

# 1105
~~水 DP。~~
这个 DP **非常硬核**，只是数据出小了。如果数据出到 100000 级别就很麻烦。
具体可以参见 POJ3017 Cut the sequence 的题解。

# 1108
水

# 1109
借教室？

# 1111
相当于开两个栈，尽量平分括号。就可以用两个变量记录剩余左括号数量。用一个变量然后依靠奇偶性也行。

# 1122
把原本的对数排序改成对元组进行排序即可。

# 1123
实际上不需要管什么叶子，只要管两个子树间高度的比较，然后分情况处理就行了。。。不知道为什么写的乱七八糟。

# 1124
写了一个 $O(n\log n)$ 的水算法，发现这题居然可以用单调栈做。。。

# 1137
水

# 1138
小模拟

# 1139
矩阵前缀和优化判断

# 1143
LCS

# 1144
要么只削减偶数位置的元素，要么只削减奇数位置的元素。

# 1145
以 x 为根，判定三个子树中是否存在比另外两棵节点数都多的一棵，有的话 y 就能获胜，反之则不能。

# 1146
~~可持久化数组（主席树）~~
没有必要用那么高级的东西。每一个位置都用 Hash Table 来保存即可。
所以说思维还是要开阔啊。。。
```cpp
class SnapshotArray {
public:
    vector<map<int, int>> arr;
    int cnt;
    SnapshotArray(int length) {
        cnt = 0;
        for (int i = 0; i < length; ++i)    
            arr.push_back(map<int, int>()), arr[i][0] = 0;
    }
    
    void set(int index, int val) {
        arr[index][cnt] = val;
    }
    
    int snap() {
        int res = cnt++;
        return res;
    }
    
    int get(int index, int snap_id) {
        auto it = arr[index].upper_bound(snap_id);
        --it;
        return (*it).second;
    }
};
```

# 1150
能用一行解决的最好就用一行。。。
```python
return collections.Counter(nums).get(target, -1) > (len(nums) // 2)
```

# 1151
滑动窗口，找 0 最少那个。

# 1152
这题特别麻烦。。。如果使用的是朴素的算法的话很容易写一大串。
大概思路就是暴力，但怎么写是一个很有意思的问题。我最开始写的版本有接近 90 行，并且调试了很久，而后看了其他人的发现根本不需要这么复杂。。。
下面给一个我修改过的大概的实例作为简短代码的参考。
```cpp

```

# 1154
水

# 1155
递推

# 1156
有点麻烦，但基本思想还可以：考虑长度为 1 的单字符子串，如果两侧的单字符子串包含相同的字符，那就看看能不能从别的地方弄一个字符和它交换以将两侧连接起来。这里有一些边界情况的讨论。
注意对于长度不为 1 的单字符子串也要考虑能不能将其端点旁的字符换成其包含的字符，这也是情况之一。
上面这个做法是线性的。

# 1160
模拟

# 1161
统计

# 1162
BFS

# 1169
水

# 1170
水

# 1173
水

# 1174
水

# 1175
判定区间内字符数目奇偶性即可。设总共有 $t$ 种字符出现了奇数次，那么只要 $\lfloor\frac{t}{2} \rfloor\le k$ 即可通过检测。

# 1184
从起点到终点和从终点到起点跑两次，取 $\min$。

# 1185
Zeller 公式

# 1186
设以 $i$ 结尾的最大子段和为 $maxi[i]$，删掉一个数的最大字段和为 $f[i]$，则：
$$
f[i] = sum[i] + \max_{1\le j < i} \lbrace maxi[j - 1] - sum[j]\rbrace
$$
简单的维护即可。

# 1227
神奇的题目。手算一下前几项除了 1 是 1 之外都是 0.5，于是答案就是除了 1 为 1 其余均为 0.5。

为什么？和错排问题差不多，如果 1 占了 $k$ 的位置，那么 $k$ 只有占 1 的位置才不会引发后面的事件，否则就要去占领 $>k$ 的人的位置。因此这可以看作一个 DP。设答案为 $f_n$，则 
$$
f_n = \frac{1}{n} + \frac{1}{n}\sum_{k = 2}^{n - 1} f_{n - k + 1}
$$

$n - k + 1$ 表示 $>k$ 的人数。

归纳可得最终答案。