class AllOne:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.key_to_val = dict()
        self.val_to_key = dict()
        self.mini = -1
        self.maxi = -1

    def inc(self, key: str) -> None:
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        """
        if key in self.key_to_val:
            # 更新键值对
            v = self.key_to_val[key]
            self.key_to_val[key] += 1
            self.val_to_key[v].remove(key)
            if v + 1 not in self.val_to_key:
                self.val_to_key[v + 1] = set()  
            self.val_to_key[v + 1].add(key)
            
            # 更新最小值，此时最小值必存在
            if self.mini == v and not self.val_to_key[v]:
                self.mini += 1
            # 更新最大值，此时最大值必存在
            self.maxi = max(self.maxi, v + 1)
        else:
            # 插入键值对
            self.key_to_val[key] = 1
            if 1 not in self.val_to_key:
                # 此时初始化
                self.val_to_key[1] = set()
                self.val_to_key[1].add(key)
                self.mini = 1
                self.maxi = 1
                return 
            self.val_to_key[1].add(key)

            # 更新最小值，此时最小值必为 1
            self.mini = 1
            # 更新最大值
            self.maxi = max(1, self.maxi)

    def dec(self, key: str) -> None:
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        """
        v = self.key_to_val.get(key, -1)
        if v < 0:
            return 
        # 删除这个键
        self.key_to_val.pop(key)
        self.val_to_key[v].remove(key)
        
        if v == 1:
            # 需要更新最大值和最小值
            



        else:

        

    def getMaxKey(self) -> str:
        """
        Returns one of the keys with maximal value.
        """
        if self.maxi < 0: return ""
        for s in self.val_to_key[self.maxi]:
            # 遇到就直接返回
            return s
        return ""

    def getMinKey(self) -> str:
        """
        Returns one of the keys with Minimal value.
        """
        if self.mini < 0: return ""
        for s in self.val_to_key[self.mini]:
            # 遇到就直接返回
            return s
        return ""
        


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()