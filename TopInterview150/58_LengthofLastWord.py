class Solution(object):
    def lengthOfLastWord(self, s):
        l1=s.split()
        return len(l1[-1])
