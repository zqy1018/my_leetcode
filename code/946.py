class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        dict1, len1 = {}, len(pushed)
        for i in range(0, len1):
            dict1[pushed[i]] = i
        for i in range(0, len1):
            popped[i] = dict1[popped[i]]
        st, top, cur = [], 0, 0
        for i in range(0, len1):
            while cur < len1 and (top == 0 or st[-1] != popped[i]):
                st.append(cur)
                top += 1
                cur += 1
            if cur == len1 and (top == 0 or st[-1] != popped[i]):
                return False
            st.pop()
            top -= 1
        return True