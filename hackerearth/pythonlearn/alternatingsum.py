
memo = [[[-1 for k in xrange((1 << 10))] for j in xrange(2) ]for i in xrange(1002)]
N = 0
numbers = 0

def canPut(xi, bm, bp):
	if (bp != (xi & 1)):
		return 0
	if (xi == 0):
		if (bm & 1):
			return 0
		else:
			return 1
	while (xi):
		if (bm & (1 << (xi % 10))):
			return 0
		xi /= 10
	return 1

def calcMask(bm, xi): 
	if (xi == 0):
		bm |= 1
	while (xi):
		bm |= (1 << (xi % 10))
		xi /= 10
	return bm

def DP(pos, bp, bmask):
	global N, memo, numbers
	if (pos >= N[0]):
		return 0
	if (memo[pos][bp][bmask] != -1):
		return memo[pos][bp][bmask]
	posans = 0
	#print pos
	if (canPut(numbers[pos], bmask, bp)):
		posans = numbers[pos] + DP(pos + 1, 1 - (numbers[pos] & 1), calcMask(bmask, numbers[pos]))
	posans = max(posans, DP(pos + 1, bp, bmask))		
	memo[pos][bp][bmask] = posans
	return memo[pos][bp][bmask]


N = map(int, raw_input())
numbers = map(int, raw_input().split())
res = max(DP(0, 1, 0), DP(0, 0, 0))
res = str(res)
if (res[-1] == 'L'):
    print res[:-1]
else:
    print res