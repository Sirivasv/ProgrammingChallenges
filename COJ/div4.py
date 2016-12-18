print(10 ** 1001)
N = int(input())
for i in range(N):
	aux = int(input())
	if (aux % 4) == 0:
		print("YES")
	else:
		print("NO")
