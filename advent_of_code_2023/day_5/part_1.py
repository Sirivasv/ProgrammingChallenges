import sys

current_seed_values = {}

curr_step = 1
for line in sys.stdin:
  curr_line = line.rstrip()
  curr_line_split = curr_line.split(":")
  if (curr_line_split[0] == "seeds"):
    seed_values = curr_line_split[1].strip().split()
    for seed_value in seed_values:
      current_seed_values[seed_value] = [int(seed_value), 0]
  else:
    if len(curr_line_split) == 1 and curr_line_split[0] == '':
      continue
    
    if len(curr_line_split) == 1:

      range_value_split = curr_line_split[0].split()
      destination_start = int(range_value_split[0])
      source_start = int(range_value_split[1])
      length_value = int(range_value_split[2])
      for current_seed_value_id in current_seed_values:
        current_seed_value = current_seed_values[current_seed_value_id]
        if (current_seed_value[0] >= source_start) and (current_seed_value[0] < (source_start + length_value)) and (current_seed_value[1] != curr_step):
          value_offset = current_seed_value[0] - source_start
          current_seed_value[0] = destination_start + value_offset
          current_seed_value[1] = curr_step
    else:
      curr_step = curr_step + 1

set_first = False
minimum_last_value = 0
for current_seed_value_id in current_seed_values:
  current_seed_value = current_seed_values[current_seed_value_id]
  if not set_first:
    minimum_last_value = current_seed_value[0]
    set_first = True
  elif minimum_last_value > current_seed_value[0]:
    minimum_last_value = current_seed_value[0]
print(minimum_last_value)