# STL 的一些坑

每一条的背后都是一段血泪史。

## 没把握就用 multiset 而非 set

因为保不准会出现重复的还要求你计算的数字。

## 提前清空容器

如果采用的写法是
```cpp
// 这里定义了一些容器，如 unordered_map、vector 之类
class Solution{
    // ...
}
```
最好先清空容器再使用，不然会出奇怪的错误（奇怪在根本不会报错，但就是有问题）。

## 注意 key 不在 map 中的情况

这个和 map 的机制有关。

有可能这种情况下会报错。因此最好始终检查 `mp.count`。

## 慎用 unordered_map



## 对 map 的快捷遍历

一般对 map 进行遍历都是通过迭代器实现的，但是使用 `for(auto& p: mp)` 时 `p` 是一个 `pair`。且该 `pair` 的 `first` 域（也就是键）是 `const` 类型，禁止修改。

## 消失的迭代器指针




## priority_queue 判空

在使用 `priority_queue.pop()` 之前一定要确认其是否非空。因为其是否为空是通过