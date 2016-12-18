n = gets.chomp.to_i
ans = 0
while n > 0
  n /= 2
  ans += 1
end
puts ans