class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1 = version1.split('.')
        while int(version1[-1]) == 0:
            version1.pop(-1)
            if len(version1) == 0:
                break
        version2 = version2.split('.')
        while int(version2[-1]) == 0:
            version2.pop(-1)
            if len(version2) == 0:
                break
        if len(version1) > len(version2):
            tmp_len = len(version2)
        elif len(version1) <= len(version2):
            tmp_len = len(version1)
        i = 0
        while i < tmp_len:
            if int(version1[i]) == int(version2[i]):
                i += 1
            elif int(version1[i]) > int(version2[i]):
                return 1
            else:
                return -1
        if len(version1) > len(version2):
            return 1
        elif len(version1) < len(version2):
            return -1
        return 0