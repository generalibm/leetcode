给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。  

有效字符串需满足：  

左括号必须用相同类型的右括号闭合。  
左括号必须以正确的顺序闭合。  
注意空字符串可被认为是有效字符串。  

示例 1:  
    输入: "()"  
    输出: true  

示例 2:  
    输入: "()[]{}"  
    输出: true  

示例 3:  
    输入: "(]"  
    输出: false  

示例 4:  
    输入: "([)]"  
    输出: false  

示例 5:  
    输入: "{[]}"  
    输出: true  



解析：  

1、根据题目要求，每一个右括号相邻的左括号为匹配的才可以。  

2、采用栈先入后出最为方便。  



class Solution:  
    def isValid(self, s: str) -> bool:  
        if 0 == len(s):  
            return True  
        else:  
            tmpList = []  
            tmpDict = {'(' : ')', '{' : '}', '[' : ']'}  
            for i in s:  
                if i in tmpDict:  
                    tmpList.append(i)  
                elif i not in tmpDict:  
                    if 0 == len(tmpList):  
                        return False  
                    elif i == tmpDict[tmpList[-1]]:  
                        tmpList.pop(-1)  
                    else:  
                        return False  
            if 0 == len(tmpList):  
                return True  
            elif 0 != len(tmpList):  
                return False