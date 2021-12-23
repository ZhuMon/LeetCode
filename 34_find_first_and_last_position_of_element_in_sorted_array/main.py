class Solution:
    def searchRange(self, nums, target):
        if nums == None or nums == []:
            return [-1,-1]
        
        b = 0
        e = len(nums)-1
        # binary search
        while e > b:
            mid = (b+e) // 2 
            if nums[mid] == target:
                break
            elif nums[mid] > target:
                e = mid-1
            else:
                b = mid+1
        
        if e <= b and nums[mid] != target:
            return [-1, -1]
        
        b = mid-1
        e = mid+1
        
        while b > -1 and nums[b] == target:
            b -= 1
            
        b += 1
        if nums[b] != target:
            b = mid
        
        
        while e < len(nums) and nums[e] == target:
            e += 1
        
        e -= 1
        if nums[e] != target:
            e = mid
        
        return [b,e]
                
if __name__ == "__main__":
    s = Solution()
    # print(s.searchRange([5,7,7,8,8,10], 8))
    print(s.searchRange([5,7,7,8,8,10], 6))

