class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if lists == [None] or lists == []:
            return 
        expand = []
        for l in lists:
            now = l
            
            while now != None:
                prev = now
                expand.append(now)
                now = now.next
                prev.next = None
        if expand == []:
            return
     
        expand = sorted(expand, key=lambda x: x.val)
        
        first = expand[0]
        for i in expand[1:]:
            first.next = i
            first = first.next
            
        return expand[0]
            
