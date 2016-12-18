def Probar(vals):
	for i in range(3):
		for j in range(3):
			if j == i:
				continue
			for k in range(3):
				if (k == j) or (k == i):
					continue
				if (vals[i] ** 2) + (vals[j] ** 2) == vals[k] ** 2:
					return True
	return False			

while (True):
	values = input()
	if len(values) == 1:
		break
	values = values.split();
	for i in range(3):
		values[i] = int(values[i])
	if Probar(values):
		print("right")
	else:
		print("wrong")