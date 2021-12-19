class Solution:
    d = {"2": "abc", "3":"def", "4":"ghi", "5": "jkl", 
         "6":"mno", "7": "pqrs", "8":"tuv", "9":"wxyz"}
            
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        
        output = [""]
        for i in digits:
            new_output = []
            for o in output:
                for l in self.d[i]:
                    new_output.append(o+l)
            output = new_output

        return output
