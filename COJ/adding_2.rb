def ManyFives(n)
  many = 0
  cnt = 1
  while n != 0 do
	if n % 10 == 5 
		many += cnt
	end
	n /= 10
	cnt *= 10
  end
  many
end
def ManySix(n)
  many = 0
  cnt = 1
  while n != 0 do
	if n % 10 == 6
	  many += cnt
	end
	n /= 10
	cnt *= 10
  end
  many
end
a = gets.chomp.split.map(&:to_i)
puts ((a[0] - ManySix(a[0])) + (a[1] - ManySix(a[1]))).to_s + " " + ((a[0] + ManyFives(a[0])) + (a[1] + ManyFives(a[1]))).to_s 