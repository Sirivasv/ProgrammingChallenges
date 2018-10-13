memo = {}
bids = []
names = []
winners = []
idLimit = 0
sumLimit = 0

def DP(id, currentSum):

	currentState = (id, currentSum)

	if (memo.get(currentState)):
		return memo[currentState]
	
	if (currentSum > sumLimit):
		memo[currentSum] = 0
		return memo[currentSum]

	if (id == idLimit):
		memo[(id, currentSum)] = 1 if (currentSum == sumLimit) else 0
		return memo[(id, currentSum)]

	newSum = currentSum + bids[id]
	
	takeThisElement = DP(id + 1, newSum);
	takeNotThisElement = DP(id + 1, currentSum);

	memo[currentState] = 1 if (takeThisElement + takeNotThisElement > 0) else 0;
		
	if (takeThisElement == 1):
		winners.append(names[id])
	
	return memo[currentState]

idLimit, sumLimit = map(int, raw_input().split())

for i in xrange(idLimit):
	currentData = raw_input().split()
	currentName = currentData[0]
	currentBid = int(currentData[1])
	bids.append(currentBid)
	names.append(currentName)

DP(0, 0)

winnerLimit = len(winners)

print winnerLimit

for winner in winners:
	print winner