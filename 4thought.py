operators = [" + "," - "," * "," // "]

values = {}

for x in operators:
    for y in operators:
        for z in operators:
	    expression = "4{:s}4{:s}4{:s}4".format(x,y,z)
	    value = eval(expression)
	    values[value] = expression.replace("//","/") + " = {:d}".format(value)

for m in range(int(input())):
	n = int(input())
	if n not in values:
		print("no solution")
	else:
		print(values[n])
