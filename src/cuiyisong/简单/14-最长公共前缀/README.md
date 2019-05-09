编写一个函数来查找字符串数组中的最长公共前缀。  

如果不存在公共前缀，返回空字符串 ""。  

示例 1:  
    输入: ["flower","flow","flight"]  
    输出: "fl"  

示例 2:  
    输入: ["dog","racecar","car"]  
    输出: ""  
    解释: 输入不存在公共前缀。  

说明:  
    所有输入只包含小写字母 a-z 。  



解析：  

1、公共前缀的长度小于等于最短的字符串。  

2、一旦前面的字符串相同的前缀长度为 0 ，后面的字符串无需再判断。  



class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:  
        if 0 == len(strs):  
            return ''  
        elif 1 == len(strs):  
            return strs[0]  
        lenStr = len(strs[0])
        for i in range(1, len(strs)):  
            if len(strs[i]) < lenStr:  
                lenStr = len(strs[i])  
            tmpLen = lenStr  
            for j in range(0, tmpLen):  
                if strs[0][:lenStr] == strs[i][:lenStr]:  
                    break  
                else:  
                    lenStr -= 1  
                    if lenStr == 0:  
                        return ''  
        return strs[0][:lenStr]