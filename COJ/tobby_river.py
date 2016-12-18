#Python V2.x
maxn = 609
A = [0 for i in range(10)]
memo = [[-1 for j in range(maxn)] for i in range(10)]

def Can(id, x):
	if memo[id][x] != -1:
		return memo[id][x]
	if id == 5:
		memo[id][x] = ((x == 0) or (x - A[id] == 0))
		return memo[id][x]
	memo[id][x] = Can(id + 1, x)
	if A[id] <= x:
		memo[id][x] |= Can(id + 1, x - A[id])
	return memo[id][x]

def Limpia():
	for i in range(6):
		for j in range(maxn):
			memo[i][j] = -1

T = int(raw_input(""))
for nc in range(T):
	sum = 0;
	A = raw_input("").split()
	for i  in range(6):
		A[i] = int(A[i])
		sum += A[i]
	if sum & 1:
		print("Tobby no puede cruzar")
		continue;
	Limpia()
	sum >>= 1
	if Can(0, sum):
		print("Tobby puede cruzar")
	else:
		print("Tobby no puede cruzar")