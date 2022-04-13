class Solution:
    def recur(self, s, p):
        if s == p:
            return True
        if p == "":
            return False
        if s == "" and len(p) == 2 and p[1] == "*":
            return True

        if len(p) == 1:
            if len(s) > 1:
                return False
            if p == '.' and len(s) == 1:
                return True

        if p[0] == '.' and p[1:2] != '*' and s != "":
            return self.recur(s[1:], p[1:])
        if p[:2] == ".*":
            if len(p) == 2:
                return True
            if len(p) > 2:
                res = False
                for i in range(len(s)+1):
                    res = res or self.recur(s[i:], p[2:])
                return res

        if p[1:2] == "*":
            res = False
            i = 0
            for i in range(len(s)+1):
                res = res or self.recur(s[i:], p[2:])
                if s[i:i+1] == p[0]:
                    continue
                else:
                    break

            return res

        if s[0:1] != p[0:1]:
            return False
        if s[0:1] == p[0:1]:
            return self.recur(s[1:], p[1:])

    def isMatch(self, s: str, p: str) -> bool:
        return self.recur(s, p)
