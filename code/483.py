class Solution:
    def smallestGoodBase(self, n: str) -> str:
        from math import floor
        def db(x, t):
            fz = x ** (t + 1) - 1
            return fz // (x - 1)
        n = int(n)

        for t in range(64, 1, -1):
            ll, rr = 2, floor(n ** (1 / t))
            while ll < rr:
                mid = (ll + rr) >> 1
                if db(mid, t) < n:
                    ll = mid + 1
                else:
                    rr = mid
            if db(ll, t) == n:
                return str(ll)
        
        return str(n - 1)