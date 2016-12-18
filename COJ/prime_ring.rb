$is_p = [false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, false, false, false, false, true, false, true, false]
$free = Array.new(20, true)
$a = Array.new(20)
$n
def Barrack(u, x)
    if x == $n
        if ($is_p[$a[$n] + $a[1]] == false) then return; end
        print $a[1]
        for i in 2..$n
            print " #{$a[i]}"
		end
        puts ""
        return
    end
    for i in 2..$n
        if $free[i] && $is_p[i + u]
            $free[i] = false
            $a[x + 1] = i
            Barrack(i, x + 1)
            $free[i] = true
        end
	end
end
T = gets.chomp.to_i
for i in 1..T
  $n = gets.chomp.to_i
  puts "Case #{i}:"
  for j in 0..$n
    $free[j] = true
  end
  $free[1] = false
  $a[1] = 1;
  Barrack(1, 1)
end