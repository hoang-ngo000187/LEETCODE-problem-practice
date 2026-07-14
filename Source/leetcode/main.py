class Solution:
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

if __name__ == '__main__':
    sol = Solution()
    low = 100
    high = 300
    print(sol.sequentialDigits(low, high))