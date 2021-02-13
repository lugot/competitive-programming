from sys import stdin

var = {}
for line in stdin.readlines():
    line = line.split()

    if line[0] == 'define':
        var[line[2]] = int(line[1])

    else:
        a = line[1]
        op = line[2]
        b = line[3]

        if a not in var.keys() or b not in var.keys():
            print('undefined')
            continue

        if op == '=':
            if var[a] == var[b]:
                print('true')
            else:
                print('false')
        elif op == '>':
            if var[a] > var[b]:
                print('true')
            else:
                print('false')
        else:
            if var[a] < var[b]:
                print('true')
            else:
                print('false')

