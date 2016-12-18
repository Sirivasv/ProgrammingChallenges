 n = gets.chomp.to_i
 n.times {
   par = gets.chomp.split.map(&:to_i)
   problems = gets.chomp.split.map(&:to_i).sort
   i = 0
   acum = 5
   penalty = 0
   par[0] -= 5
   while par[0] > 0 do
     if (i >= par[1]) then break; end
	 if (par[0] - problems[i]) < 0 then break; end
	 par[0] -= problems[i]
	 acum += problems[i]
	 penalty += acum
	 i += 1
   end
   puts "#{i} #{penalty}"
 }