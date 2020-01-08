class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        len1 = len(chars)
        lst, cnt, i = chars[0], 1, 1
        while i < len1:
            if chars[i] == lst:
                cnt += 1
                chars.pop(i)
                i -= 1
                len1 -= 1
            else:
                if cnt > 1:
                    str1 = str(cnt)
                    llen = len(str1)
                    chars[i: i] = list(str1)
                    i += llen
                    len1 += llen
                lst, cnt = chars[i], 1
            i += 1
            
        if cnt > 1:
            str1 = str(cnt)
            chars[len1: len1] = list(str1)
        return len(chars)

"""
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
"""