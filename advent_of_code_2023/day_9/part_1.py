import sys

input_lines = [line.rstrip().split() for line in sys.stdin]

final_sum = 0

def get_nex_value(number_list):

  delta_lists = [number_list]

  all_deltas_zero = True
  while True:
    
    curr_number_list = delta_lists[-1]

    all_deltas_zero = True
    for curr_number in curr_number_list:
      if curr_number != 0:
        all_deltas_zero = False
        break
    
    if all_deltas_zero:
      deltas_sum = 0
      for delta_list in delta_lists:
        deltas_sum += delta_list[-1]
      return deltas_sum
    
    new_deltas_list = []
    
    for curr_number_id in range(len(curr_number_list) - 1):
      new_deltas_list.append(curr_number_list[curr_number_id + 1] - curr_number_list[curr_number_id])
    
    delta_lists.append(new_deltas_list)

for input_line in input_lines:
  curr_number_list = [int(x) for x in input_line]
  final_sum += get_nex_value(curr_number_list)

print(final_sum)