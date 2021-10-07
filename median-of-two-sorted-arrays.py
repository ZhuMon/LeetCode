
nums1 = [1,3]
nums2 = [2,4]
s = nums1 + nums2
s.sort()
index = int(len(s)/2)
if index*2 == len(s):
    print float((s[index-1]+s[index])/2.0)
    print s[index-1]
    print s[index]
else:
    print s[index-1]
