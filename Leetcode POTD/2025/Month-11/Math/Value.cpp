class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        val = 0                                      # initial value 0 set karte hain
        for i in range(len(operations)):              # har operation check karenge
            if operations[i] == "--X":                
                val -= 1                              # X ko 1 se kam kar do
            elif operations[i] == "++X":              
                val += 1                              # X ko 1 se badha do
            elif operations[i] == "X++":              
                val += 1                              # post increment bhi same result deta hai
            else:                                     
                val -= 1                              # post decrement bhi same result deta hai
        return val                                    # final value return karte hain
