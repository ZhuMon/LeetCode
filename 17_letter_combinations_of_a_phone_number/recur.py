class Solution:
    d = {"2": "abc", "3":"def", "4":"ghi", "5": "jkl", 
         "6":"mno", "7": "pqrs", "8":"tuv", "9":"wxyz"}
    def recursive(self, now_num, now_str):
        # now_num: digits
        # now_char: index of character of the digit
        # now_str: letters
        if len(now_str) == self.digits_len:
            self.output.append(now_str)
            return
        
        for i in range(len(self.d[self.digits[now_num]])):
            self.recursive(now_num+1, now_str+self.d[self.digits[now_num]][i])
            
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        self.digits = digits
        self.digits_len = len(digits)
        self.output = []
        self.recursive(0, '')
        return self.output
