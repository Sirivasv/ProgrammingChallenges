import sys

final_sum = 0

for line in sys.stdin:
  curr_line = line.rstrip()
  curr_line_split = curr_line.split(":")
  number_parts_split = curr_line_split[1].split("|")
  winning_numbers = number_parts_split[0].strip().split()
  numbers_you_have = number_parts_split[1].strip().split()

  curr_points = 1
  curr_sum = 0
  for number_you_have in numbers_you_have:
    if number_you_have in winning_numbers:
      curr_sum = curr_points
      curr_points = curr_points * 2
  final_sum = final_sum + curr_sum
print(final_sum)
