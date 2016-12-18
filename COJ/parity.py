while (True):
	N = input()
	if N == "0":
		break
	N = bin(int(N))
	B = ""
	cnt = 0
	for i in range(2, len(N)):
		B += N[i]
		if (N[i] == "1"):
			cnt += 1
	print("The parity of " + B + " is " + str(cnt) + " (mod 2).")