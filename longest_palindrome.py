s = "abajfaafj"
l = len(s)
if l < 2 or s == s[::-1]:
    print s

start = 0
maxLen = 1
for i in range(l):
    if i - maxLen - 1 >= 0:
        odd = s[i - maxLen - 1:i+1]
        if odd == odd[::-1]:
            start = i - maxLen - 1
            print i,"2"
            maxLen += 2
            continue

    if i - maxLen >= 0:
        even = s[i - maxLen : i+1]
        if even == even[::-1]:
            start = i - maxLen
            print i,"1"
            maxLen += 1
            continue

print s[start:start+maxLen]
