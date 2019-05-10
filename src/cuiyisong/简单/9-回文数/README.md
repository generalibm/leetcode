判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。  

示例 1:  
    输入: 121  
    输出: true  

示例 2:  
    输入: -121  
    输出: false  
    解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。  

示例 3:
    输入: 10  
    输出: false  
    解释: 从右向左读, 为 01 。因此它不是一个回文数。  

进阶:  
    你能不将整数转为字符串来解决这个问题吗？  


解析：  

1、判断回文数最简单的方法就是转为字符串，反转，然后与原字符串做对比。无需考虑溢出问题。  

2、如果不转为字符串则需要考虑溢出问题，直接使用try-catch，如果溢出报错返回false  



class Solution:  
    def isPalindrome(self, x: int) -> bool:  
        if x < 0:  
            return False  
        elif x >= 0:  
            tmp_int = 0  
            tmp_in = x  
            while(tmp_in):  
                tmp_int = tmp_int * 10 + tmp_in % 10  
                tmp_in = int(tmp_in / 10)  
            return (x == tmp_int)  



python3中的除法保留小数，所以在每次除后需要将小数转为整数以便进行下次循环。  
如：  
    10 / 2 = 5.0