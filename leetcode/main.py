class Solution:
    # 1291. Sequential Digits
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        str_digits = "123456789"
        res = []
        for i in range(9):
            str_num = str_digits[i]
            for j in range(i+1, 9):
                str_num += str_digits[j]
                num = int(str_num)
                if  num >= low and num <= high:
                    res.append(num)
        return sorted(res)
    
    # 26. Remove Duplicates from Sorted Array
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        j = i
        L = len(nums)
        res = 0
        if L == 1:
            return 1
        else:
            res = 1
            while (i < L and j < L):
                if nums[i] == nums[j]:
                    j += 1
                else:
                    # Swap nums[i+1] and nums[j]
                    nums[i+1] = nums[j]
                    i += 1
                    res += 1
        return res

    # 27. Remove Element
    def removeElement(self, nums: List[int], val: int) -> int:
        L = len(nums)
        res = 0
        i = 0
        j = 0
        while (i < L and j < L):
            if nums[i] != val:
                nums[j] = nums[i]
                res += 1
                j+=1
            i += 1
        return res

if __name__ == '__main__':
    sol = Solution()
    nums = [3,2,2,3]
    val = 3
    print(sol.removeElement(nums, val))