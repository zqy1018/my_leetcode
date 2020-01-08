# 链表总结

事先说明，本文仅仅是一个纲要（考前快速复习的材料）。

先给出全文使用的结构体定义，不特殊说明都使用该定义：

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

# 概要

经典题目：

- 怎么找出链表的倒数第 $N$ 个节点并删除？（[Leetcode 19](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)）
  - 怎么找出链表最中间位置的节点（即：链表长度为 $L$，从 0 开始编号时，编号为 $\lceil\frac{L}{2}\rceil$ 的节点）？（[Leetcode 876](https://leetcode-cn.com/problems/middle-of-the-linked-list/)）
- 怎么两两交换链表中相邻的节点？（[Leetcode 24](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)）
- 怎么翻转链表？（[Leetcode 206](https://leetcode-cn.com/problems/reverse-linked-list/)）
  - 怎么 $K$ 个 $K$ 个一组的翻转链表？（Leetcode 25）
  - 怎么只反转节点编号在 $m$ 到 $n$（$m<n$）之间的链表？（Leetcode 92）
- 怎么将链表重新链接，使连接顺序从 $node_0\rightarrow node_1 \rightarrow node_2 \rightarrow \cdots \rightarrow node_{N-1}$ 变成 $node_0\rightarrow node_{N-1} \rightarrow node_1 \rightarrow node_{N-2} \rightarrow \cdots$？
- 怎么将链表以 $K$ 为单位做循环移位？（Leetcode 61）
- 怎么删除有序链表中的重复元素，重复的只保留一个？（[Leetcode 83](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)）
  - 怎么删除有序链表中的重复元素，只保留不重复的元素？（[Leetcode 82](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)）
- 给定一个值 $x$，怎么将链表中所有等于 $x$ 的值删除？（[Leetcode 203](https://leetcode-cn.com/problems/remove-linked-list-elements/)）
- 给定一个值 $x$，怎么操作链表使其从前到后分为 $<x$，$=x$，$>x$ 三个部分？（Leetcode 86）
- 给定一个链表，每一个节点有一个随机指针指向 `NULL` 或者任意一个节点，怎么对这个链表做深拷贝（即，生成一个内容完全一样，但内存意义上完全不相关的拷贝）？（Leetcode 138）
- 怎么在一个链表上跑插入排序？（Leetcode 147）
  - 怎么在一个链表上跑 $O(n\log n)$ 级别的排序？（Leetcode 148）
- 怎么判断一个链表是否是回文链表（即链表反转后和原来链表值的排列顺序不变）？（Leetcode 234）
- 给定两个单链表，保证两个单链表从某一个节点开始相汇合成一个单链表，怎么找到这个交点？（Leetcode 160）
- 怎么判断一个单链表中是否有环？（Leetcode 141）
  - 怎么找到一个包含环的单链表中，从头节点开始进入环的第一个节点？（Leetcode 142）
- 怎么把链表重新排列，使得奇数编号的节点和偶数编号的节点排在一起，且不改变相对顺序？以 5 个节点的链表为例，重排后链表变成 1->3->0->2->4（数字代表原始节点编号）。（Leetcode 328）
  - 怎么把链表重新排列，使得节点编号按 $\mod k$ 的余数排在一起，且不改变相对顺序？
- 给定两个单链表，分别表示两个大整数（链表头表示最低位），怎么将这两个整数相加并且返回作为结果的链表？（Leetcode 2）
  - 给定两个单链表，分别表示两个大整数（链表头表示最高位），怎么将这两个整数相加并且返回作为结果的链表？（Leetcode 445）
- 怎么将对链表做删改，使得最终链表中任意一段子链和（即某一段链表中，所有节点 `val` 的和）不为 0？（Leetcode 1171）
- 怎么将一个有序链表转换成一个平衡树？（Leetcode 109）
- 怎么合并两个有序链表？（[Leetcode 21](https://leetcode-cn.com/problems/merge-two-sorted-lists/)）
  - 怎么合并 $K$ 个有序链表？（[Leetcode 23](https://leetcode-cn.com/problems/merge-k-sorted-lists/)）

经典技巧：

- 哑头节点，用来统合非空链表和空链表，同时方便前插/后插/删除。特点是会将对节点的访问转化成对 next 指针所指节点的访问。
  - 简单例子：遍历链表并且输出每一个节点的值。
    - 不用哑节点时输出 `cur_node->val`，判定到末尾使用 `while (cur_node != NULL)`
    - 使用哑节点时从哑节点开始遍历，输出 `cur_node->next->val`，判定到末尾使用 `while (cur_node->next != NULL)`
  - 简单例子：删除某个节点。
    - 不用哑节点需要知道被删除节点的前一个节点 `pre_node`，然后 `pre_node->next = cur_node->next; delete cur_node`，还需要讨论是否是第一个节点
    - 用哑节点时如果 `cur_node->next` 就是要被删除的就 `tmp = cur_node->next; cur_node->next = cur_node->next->next; delete tmp`（如果不释放空间更简单）
- 双指针，一般都是快慢指针，还有别的辅助指针之类的
  - 简单例子：判环，找某位置节点

# Leetcode 19

先用一个快指针跳 $N$ 个点，然后慢指针从头开始，两个指针同步移动，始终维护 $N$ 的间距。快指针到末尾时慢指针到答案处。

如果只要求寻找的话这么做就够了。但这里还要求删除，所以用一个哑头结点。

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) return NULL;
    ListNode *dummy_head = new ListNode(-1);    // 创建一个哑节点
    dummy_head->next = head;
    ListNode *slow = dummy_head;
    ListNode *fast = dummy_head;
    for (int i = 0; i < n; ++i)
        fast = fast->next;                      // 快指针先跑 N 步
    while (fast->next != NULL)
        fast = fast->next, slow = slow->next;   // 快、慢指针同时移动
    slow->next = slow->next->next;              // 删除倒数第 N 个节点
    return dummy_head->next;
}
```

时间复杂度：$O(n)$，空间复杂度：$O(1)$。

# Leetcode 876

思想基本同上，只是快指针跑的速度是慢指针的两倍。

```cpp
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    for (; fast != NULL; ){
        fast = fast->next;
        if (fast == NULL) break;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
```

时间复杂度：$O(n)$，空间复杂度：$O(1)$。

# Leetcode 24

使用哑节点后如图所示。



```cpp
ListNode* swapPairs(ListNode* head) {
    ListNode *dummy_head = new ListNode(-1);
    dummy_head->next = head;
    ListNode *cur_node = dummy_head, *tmp;
    while (cur_node->next != NULL){
        if (cur_node->next->next == NULL) break;        // 最后只剩一个节点就退出

        tmp = cur_node->next->next;
        cur_node->next->next = tmp->next;
        tmp->next = cur_node->next;
        cur_node->next = tmp;
        cur_node = tmp->next;
    }
    return dummy_head->next;
}
```

时间复杂度：$O(n)$，空间复杂度：$O(1)$。

# Leetcode 206

如图所示。



```cpp
ListNode* reverseList(ListNode* head) {
    ListNode *before_node = NULL, *tmp;
    while (head != NULL){
        tmp = head->next;
        head->next = before_node;
        before_node = head;
        head = tmp;
    }
    return before_node;
}
```

时间复杂度：$O(n)$，空间复杂度：$O(1)$。

# 




# Leetcode 83

从头到尾访问节点，每访问到一个节点（设其 `val` 为 $x$）就用另一个指针（设为 `q`）从当前节点开始向后，一直移动到为 `NULL` 或者 `q` 所在节点的值不为 $x$ 为止。然后令当前正在访问的节点的 `next` 指针直接指向 `q`，如此往复。

用图描述如下：



可以使用哑节点，也可以不使用。

（注意修改！！！！！）

```cpp
ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode *tmp = head;
    while (tmp->next != NULL){
        ListNode *q = tmp->next;
        while (q != NULL && q->val == head->val)
            head->next = q->next, q = q->next;
        if(tmp == NULL) break;
        head = tmp;
    }
    return tmp;
}
```

时间复杂度：$O(n)$，空间复杂度：$O(1)$。

# Leetcode 82

和上一题差不多，只是每次都要判断当前节点是否应当保留。

最好使用哑结点来避免一些复杂情况的讨论。

```cpp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *dummy_head = new ListNode(-1);
    dummy_head->next = head;
    ListNode *tmp = dummy_head;
    while (tmp->next != NULL){
        ListNode *q = tmp->next;
        while (q != NULL && q->val == tmp->next->val)
            q = q->next;
        if(hhd->next->next != tmp)
            hhd->next = tmp;
        else hhd = hhd->next;
    }
    return res->next;
}
```

时间复杂度：$O(n)$，空间复杂度：$O(1)$。




# Leetcode 203

使用哑节点辅助删除即可。

```cpp
ListNode* removeElements(ListNode* head, int val) {
    ListNode *dummy_head = new ListNode(-1);
    dummy_head->next = head;
    ListNode *tmp = dummy_head;
    while (tmp->next != NULL){
        if (tmp->next->val == val)
            tmp->next = tmp->next->next;    // 删除，由于 Leetcode 上不要求释放空间故没有释放
        else tmp = tmp->next;
    }
    return dummy_head->next;
}
```

时间复杂度：$O(n)$，空间复杂度：$O(1)$。











# Leetcode 21

使用一个哑节点作为合并后的结果链表的头，后面基本同归并排序中两个有序数组的归并。

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy_head = new ListNode(-1);
    ListNode *tail = dummy_head;                // 归并的时候是不断向尾部连接节点的
    while (l1 != NULL && l2 != NULL){
        // 从两个链表中不断拆出节点连到结果链表末尾
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;  
    }
    tail->next = (l1 == NULL ? l2: l1);         // 直接令尾部连接剩余的链表
    return dummy_head->next;
}
```

时间复杂度：$O(n+m)$，$n$，$m$ 分别为两个链表的长度。空间复杂度：$O(1)$。

# Leetcode 23

经典问题，用一个堆可以解决。

具体操作是：类似两个链表归并时，先创建一个哑节点作为合并后的结果链表的头。把所有链表的第一个节点放进小根堆里（按照 `val` 比较），然后每一次从堆中弹出具有当前最小值的节点，向堆中放入它的 `next`，再将它链到结果链表的末尾。

```cpp
template<class elemType> class Heap;        // 小根堆
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        Heap<ListNode*> pq(k);              // 假定你通过某种方式实现了 ListNode 之间的比较
        ListNode *dummy_head = new ListNode(-1);
        ListNode *tail = dummy_head;
        for (int i = 0; i < k; ++i)
            if (lists[i] != NULL)
                pq.push(lists[i]);
        while (!pq.empty()){
            ListNode *cur_node = pq.pop();
            tail->next = cur_node, tail = tail->next;
            cur_node = cur_node->next;
            if (cur_node != NULL)
                pq.push(cur_node); 
        }
        return dummy_head->next;
    }
};
```

时间复杂度：$O(n\log K)$，$n$ 为所有链表节点数目的和。空间复杂度：$O(K)$。