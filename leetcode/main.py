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

    # 743. Network Delay Time
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        ret = -1
        # [[2,1,1],[2,3,1],[3,4,1]]
        INFTY = float('inf')
        # graph = {}
        # for i in range(1, n+1):
        #     graph[i] = []
        #     for t in times:
        #         if t[0] == i:
        #             graph[i].append([t[1], t[2]])
        graph = {i:[] for i in range(1, n+1)}

        for u, v, w in times:
            graph[u].append([v, w])

        print(graph)

        dist = {node: INFTY for node in graph}
        dist[k] = 0
        prev = {node: None for node in graph}
        S = set()

        while len(S) < n:
            # 2. Tim dinh u nam ngoai tap S co dist[u] nho nhat
            min_dist = INFTY
            u = None
            for node in graph:
                if node not in S and dist[node] < min_dist:
                    min_dist = dist[node]
                    u = node

            if u is None or dist[u] == INFTY:
                break

            S.add(u)

            # 3. Thu gian cac dinh ke v chua nam trong S
            for v, w in graph[u]:
                if v not in S:
                    new_dist = dist[u] + w
                    if new_dist < dist[v]:
                        dist[v] = new_dist
                        prev[v] = u

        ret = dist[k]
        for i in range(1, n+1):
            if dist[i] == INFTY:
                ret = -1
                break
            else:
                if dist[i] > ret:
                    ret = dist[i]
        return ret


if __name__ == '__main__':
    sol = Solution()
    #times = [[2,1,1],[2,3,1],[3,4,1]]
    times = [[1,2,1]]
    n = 2
    k = 2
    print(sol.networkDelayTime(times, n, k))