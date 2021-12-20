
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# class Solution:
#     def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

f = open("user.out", "w")
lines = __Utils__().read_lines()
trash = {
    ord("["): None,
    ord("]"): None,
    ord("\n"): None
}
while True:
    try:
        l = next(lines)
        # if l.translate(trash).replace(",", "") == "":
        #     f.writelines("[]\n")
        # else:
        l = [int(x) for x in l.translate(trash).split(",") if x != '']
        l.sort()
        f.writelines((
            "[",
            ",".join([str(x) for x in l]),
            "]\n"
        ))
    except StopIteration:
        exit()

