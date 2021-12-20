class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if lists == [] or lists == [[]]:
            return 
        
        #index = [0 for i in range(len(lists))]
        max_index = [None for l in lists]
        ptrs = lists
        begin = ListNode()
        now = begin
        while ptrs != max_index:
            v = [l.val if l != None else 10001 for l in ptrs]
            index = v.index(min(v))
            now.next = ptrs[index]
            
            ptrs[index] = ptrs[index].next
            now = now.next
       
        return begin.next
