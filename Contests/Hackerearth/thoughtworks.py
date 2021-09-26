def solve ( N, M, A, queries):
    # compute prefix sum of A
    prefix = list(bytearray(len(A)))

    row, col = (len(A), len(A))
    precompute = [[0] * col] * row

    for i in range(0,len(prefix)):
        prefix[i] = A[i] & 1

    for query in queries:
        print(query)
    print(prefix)
    print(precompute)
    pass

N = int(input())
M = int(input())
A = list(map(int, input().split()))

queries = [list(map(int, input().split())) for i in range(M)]

out_ = solve(N,M,A,queries)
# print(' '.join(map(str, out_)))