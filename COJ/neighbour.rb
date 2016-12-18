n = gets.chomp.to_i
aux = n
a = []
while n != 0 do
  a.push(n %10)
  n /= 10
end
a = a.permutation.to_a.map(&:join).map(&:to_i).sort
found = false
for i in 0...a.length 
  if a[i] > aux
    puts a[i]
	found = true
	break;
  end
end
puts 0 unless found