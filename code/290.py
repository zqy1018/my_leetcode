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