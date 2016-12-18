#python v3.x
n = int(input())
A = input().split()
B = input().split()
for i in range(n):
	A[i] = int(A[i])
	B[i] = int(B[i])
A.sort()
B.sort()
sum = 0
for i in range(n):
	sum += A[i] * B[n - i - 1]
print(sum)