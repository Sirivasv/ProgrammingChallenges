n = gets.chomp.to_i
a = gets.chomp.split().map(&:to_i)
mint = a[0]
mats = a[0]
ans = 0
for i in 1...a.length 
  if a[i] < mint 
    mint = a[i]
	ans += 1
  end
  if a[i] > mats 
    mats = a[i]
	ans += 1
  end
end
puts ans
