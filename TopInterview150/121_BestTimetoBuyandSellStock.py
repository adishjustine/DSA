class Solution(object):
    def maxProfit(self, prices):
        maxp=0
        minp=float('inf')
        for i in prices:
            maxp=max(maxp, i-minp)
            minp=min(minp, i)
        return maxp
        
