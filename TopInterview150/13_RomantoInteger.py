class Solution(object):
    def romanToInt(self, s):
        d={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        l=len(s)
        s1=d[s[-1]]
        for i in range(l-1):
            s1+=(-1 if d[s[i]]<d[s[i+1]] else 1)*d[s[i]]
        return s1
