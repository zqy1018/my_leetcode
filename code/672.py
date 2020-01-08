class Solution:
    def flipLights(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n == 1:
            return 1 if m == 0 else 2
        if m == 0: 
            return 1
        elif m & 1:
            if m == 1:
                return 3 if n <= 2 else 4
            else:  
                return 4 if n <= 2 else 8
        else:
            if m == 2:
                return 4 if n <= 2 else 7
            else:
                return 4 if n <= 2 else 8