import math

totalToCut, manyRobots = map(int, raw_input().split())
totalToCut = float(totalToCut)

cheapestValidRobots = []
cheapestRobot = 1000000000

for i in xrange(manyRobots):
	currentName, currentPrice, currentCutPerMinute, currentCutMinutes, currentChargeMinute = raw_input().split(",")
	currentPrice = float(currentPrice)
	currentCutPerMinute = float(currentCutPerMinute)
	currentCutMinutes = float(currentCutMinutes)
	currentChargeMinute = float(currentChargeMinute)
	flag = 1
	for j in xrange(0, 100):
		iteration = j + 1
		blcks = (totalToCut * iteration) / (currentCutMinutes * currentCutPerMinute)
		tTime = (blcks * currentCutMinutes) + (math.floor(blcks) * currentChargeMinute)
		if (tTime > ((10080.0) * float(iteration))):
			flag = 0
	for j in xrange(1000, 1100):
		iteration = j + 1
		blcks = (totalToCut * iteration) / (currentCutMinutes * currentCutPerMinute)
		tTime = (blcks * currentCutMinutes) + (math.floor(blcks) * currentChargeMinute)
		if (tTime > ((10080.0) * float(iteration))):
			flag = 0
	for j in xrange(10000, 10100):
		iteration = j + 1
		blcks = (totalToCut * iteration) / (currentCutMinutes * currentCutPerMinute)
		tTime = (blcks * currentCutMinutes) + (math.floor(blcks) * currentChargeMinute)
		if (tTime > ((10080.0) * float(iteration))):
			flag = 0
	for j in xrange(100000, 100100):
		iteration = j + 1
		blcks = (totalToCut * iteration) / (currentCutMinutes * currentCutPerMinute)
		tTime = (blcks * currentCutMinutes) + (math.floor(blcks) * currentChargeMinute)
		if (tTime > ((10080.0) * float(iteration))):
			flag = 0
	for j in xrange(1000000, 1000100):
		iteration = j + 1
		blcks = (totalToCut * iteration) / (currentCutMinutes * currentCutPerMinute)
		tTime = (blcks * currentCutMinutes) + (math.floor(blcks) * currentChargeMinute)
		if (tTime > ((10080.0) * float(iteration))):
			flag = 0
	if (flag):
		cheapestValidRobots.append({"name": currentName, "price": currentPrice})
		if (cheapestRobot > currentPrice):
			cheapestRobot = currentPrice

if (len(cheapestValidRobots) == 0):
	print "no such mower"

for robot in cheapestValidRobots:
	if (robot["price"] == cheapestRobot):
		print robot["name"]