import sys

current_seed_ranges = []
map_step_seed_ranges = []

curr_step = 1
for line in sys.stdin:
  curr_line = line.rstrip()
  curr_line_split = curr_line.split(":")
  if (curr_line_split[0] == "seeds"):
    seed_values = curr_line_split[1].strip().split()

    for seed_value_id in range(0, len(seed_values)):
      if seed_value_id % 2 == 0:
        current_seed_ranges.append([int(seed_values[seed_value_id]), int(seed_values[seed_value_id]) + int(seed_values[seed_value_id + 1]) - 1, 0])
  else:
    if len(curr_line_split) == 1 and curr_line_split[0] == '':
      continue
    
    if len(curr_line_split) == 1:

      range_value_split = curr_line_split[0].split()
      destination_start = int(range_value_split[0])
      source_start = int(range_value_split[1])
      length_value = int(range_value_split[2])

      value_offset = destination_start - source_start

      source_end = source_start + length_value - 1
      map_step_seed_ranges = []

      for current_seed_value_id in range(0, len(current_seed_ranges)):
        current_seed_value = current_seed_ranges[current_seed_value_id]
        
        flag_check = True
        if current_seed_value[2] == curr_step:
          flag_check = False
        
        if source_end < current_seed_value[0]:
          flag_check = False
        
        if source_start > current_seed_value[1]:
          flag_check = False
        
        if flag_check:
          max_start = max(current_seed_value[0], source_start)        
          min_end = min(current_seed_value[1], source_end)
          map_step_seed_ranges.append([max_start + value_offset, min_end + value_offset, curr_step])
          
          if not ((max_start == current_seed_value[0]) and (min_end == current_seed_value[1])):
            if (source_start <= current_seed_value[0]) and (source_end < current_seed_value[1]):
              map_step_seed_ranges.append([source_end + 1, current_seed_value[1], current_seed_value[2]])
            elif (source_start > current_seed_value[0]) and (source_end >= current_seed_value[1]):
              map_step_seed_ranges.append([current_seed_value[0], source_start - 1, current_seed_value[2]])
            elif (source_start > current_seed_value[0]) and (source_end < current_seed_value[1]):
              map_step_seed_ranges.append([current_seed_value[0], source_start - 1, current_seed_value[2]])
              map_step_seed_ranges.append([source_end + 1, current_seed_value[1], current_seed_value[2]])
        else:
          map_step_seed_ranges.append([current_seed_value[0], current_seed_value[1], current_seed_value[2]])
      current_seed_ranges = map_step_seed_ranges
    else:

      curr_step = curr_step + 1

set_first = False
minimum_last_value = 0
for current_seed_value_id in range(len(current_seed_ranges)):
  current_seed_value = current_seed_ranges[current_seed_value_id]
  if not set_first:
    minimum_last_value = current_seed_value[0]
    set_first = True
  elif minimum_last_value > current_seed_value[0]:
    minimum_last_value = current_seed_value[0]
print(minimum_last_value)