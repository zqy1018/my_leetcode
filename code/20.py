class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        toop = 0
        st = []
        for i in s:
            if i == '(' or i == '{' or i == '[':
                st.append(i)
                toop += 1
            else:
                if i == ')':
                    if toop > 0 and st[-1] == '(':
                        st.pop()
                        toop -= 1
                    else:
                        return False
                elif i == ']':
                    if toop > 0 and st[-1] == '[':
                        st.pop()
                        toop -= 1
                    else:
                        return False
                elif i == '}':
                    if toop > 0 and st[-1] == '{':
                        st.pop()
                        toop -= 1
                    else:
                        return False
        return len(st) == 0