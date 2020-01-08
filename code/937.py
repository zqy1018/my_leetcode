class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        if logs == []: return []
        digitlg, alphalg = [], []
        for i in logs:
            b = i.split()[1]
            if b.isdigit(): digitlg.append(i)
            else: alphalg.append(i)
        alphalg.sort(key = lambda x: x.split()[1: ])
        return alphalg + digitlg