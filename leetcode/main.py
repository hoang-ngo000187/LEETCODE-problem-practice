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
        INFTY = float('inf')
        graph = {i:[] for i in range(1, n+1)}

        for u, v, w in times:
            graph[u].append([v, w])

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

    # 787. Cheapest Flights Within K Stops
    def findCheapestPrice(self, n: int, flights: list[list[int]], src: int, dst: int, k: int) -> int:
        INFTY = float('inf')
        graph = {i: [] for i in range (0, n)}
        for u, v, w in flights:
            graph[u].append([v, w])

        dist = {city: INFTY for city in graph}
        dist[src] = 0
        prev = {city: None for city in graph}

        # Chạy đúng k + 1 vòng lặp (tương ứng tối đa k + 1 chặng bay = k điểm dừng)
        for i in range(k+1):
            update = False
            # Tạo bản sao để không bị cập nhật dây chuyền trong cùng 1 lượt lặp
            temp_dist = dist.copy()

            # Duyet qua tat ca cac canh (u->v) tu graph
            for u in graph:
                if dist[u] == INFTY:
                    continue
                for v, w in graph[u]:
                    # Đọc chi phí từ dist (bước trước), cập nhật vào temp_dist (bước hiện tại)
                    if dist[u] + w < temp_dist[v]:
                        temp_dist[v] = dist[u] + w
                        prev[v] = u
                        update = True

            dist = temp_dist
            if not update:
                break
            
        return dist[dst] if dist[dst] != INFTY else -1

    # 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
    def findTheCity(self, n: int, edges: list[list[int]], distanceThreshold: int) -> int:
        INFTY = float('inf')
        graph = {i: [] for i in range(n)} # 0 --> n - 1 cities
        for u, v, w in edges:
            graph[u].append([v, w])
            graph[v].append([u, w]) # ma tran 2 chieu
        
        dist = [[INFTY]*n for _ in range(n)]

        # Khoi tao duong cheo chinh
        for i in range(n):
            dist[i][i] = 0

        # Khoi tao cac canh
        for u in graph:
            for v, w in graph[u]:
                dist[u][v] = w

        # Floyd-Warshall
        for k in range(n):
            for i in range(n):
                if dist[i][k] == INFTY:
                    continue
                for j in range(n):
                    if dist[k][j] == INFTY:
                        continue

                    new_dist_ij = dist[i][k] + dist[k][j]
                    if new_dist_ij < dist[i][j]:
                        dist[i][j] = new_dist_ij
        print(dist)

        min_cnt = INFTY
        for i, row in enumerate(dist):
            cnt = 0
            for r in row:
                if r <= distanceThreshold:
                    cnt += 1
            cnt -= 1
            if cnt <= min_cnt:
                min_cnt = cnt
                ret = i

        return ret

if __name__ == '__main__':
    sol = Solution()
    n = 4
    edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]]
    distanceThreshold = 4
    print(sol.findTheCity(n, edges, distanceThreshold))