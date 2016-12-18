maxn = 10009
parent = [0 for i in range(maxn)]
N = 0
M = 0

def Find(u):
	if parent[u] == u:
		return u
	parent[u] = Find(parent[u])
	return parent[u]

def Unir(u, v):
	parent[Find(u)] = Find(v)
	
def MismoConjunto(u, v):
	return Find(u) == Find(v)

def Limpia():
	for i in range(N):
		parent[i] = i

T = int(input())
for nc in range(T):
	dt = input().split()
	N = int(dt[0])
	M = int(dt[1])
	Limpia()
	sz = N
	for i in range(M):
		dt = input().split();
		a = int(dt[0]) - 1
		b = int(dt[1]) - 1
		if not MismoConjunto(a, b):
			sz = sz - 1
			Unir(a, b)
	print(((sz * (sz -1)) >> 1))