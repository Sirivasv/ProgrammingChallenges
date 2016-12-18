
def pot(b, pow):
	res = 1
	p = b
	n = pow
	while (n):
		if (n % 2):
			res = (res * p)
		p = (p * p)
		n >>= 1
	return res

dat = input().split()

for i in range(0, 4):
	dat[i] = int(dat[i])
	
aux = pot(dat[0], dat[2])
if (dat[0] == 1):
	print (int((aux + (dat[1] * ((dat[2] * (dat[2] + 1)) >> 1))) % 1000000007))
else:
	print (int((aux + (dat[1] * ((aux - 1) / (dat[0] - 1)))) % 1000000007))