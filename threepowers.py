while True:
    n = int(input())

    if n == 0:
        break

    n = n - 1
    i = 0

    ans = []
    while n != 0:
        if n % 2 != 0:
            ans.append(3**i)
        i += 1
        n = n // 2

    if ans == []:
        print("{ }")
        continue

    print("{ ", end='')
    for num in ans[:-1]:
        print(num, ", ", sep='', end='')
    print(ans[-1], "}")
