t = int(input())

while t != 0:
    n, k = map(int, input().split())
    lst = list(map(int, input().strip().split()))[:n]
    sum1 = 0
    lst.sort()

    for i in range(n-k-1, n):
        sum1 += lst[i]
    print(sum1)
    t -= 1
