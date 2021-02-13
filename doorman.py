X = int(input())
s = input()

diff = 0
ans = 0
while abs(diff) <= X and len(s) > 0:
    # first male and admit
    if s[0] == 'M' and diff+1 <= X:
        ans += 1
        diff += 1
        s = s[1:]

    elif s[0] == 'W' and diff-1 >= -X:
        ans += 1
        diff -= 1
        s = s[1:]

    elif s[0] == 'M' and diff == X \
            and s[1] == 'W':
        ans += 1
        diff -= 1
        s = s[0] + s[2:]

    elif s[0] == 'W' and diff == -X \
            and s[1] == 'M':
        ans += 1
        diff += 1
        s = s[0] + s[2:]

    else:
        break

    # print(s, ans, diff)

print(ans)
# WMMMMWWMMMWWMW
