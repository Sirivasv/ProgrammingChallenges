import sys

input_lines = [line.rstrip() for line in sys.stdin]

many_valid = 0
sum_valids = 0

hot_springs_map = []
max_unknown = 0
for input_line in input_lines:
  input_line_split = input_line.split()
  hot_springs_map = [*input_line_split[0]]
  contiguous_damaged_groups = input_line_split[1]
  many_unknown = hot_springs_map.count("?")
  max_unknown = max(max_unknown, many_unknown)
  many_valid = 0

  current_configuration = []
  encoded_conf_max = 1 << many_unknown
  for encoded_conf in range(0, encoded_conf_max):
    
    current_configuration = []
    for i in range(0, len(hot_springs_map)):
      current_configuration.append(hot_springs_map[i])
    
    current_unknown = 0
    for i in range(0, len(hot_springs_map)):
      if current_configuration[i] == "?":
        if encoded_conf & (1 << current_unknown):
          current_configuration[i] = "."
        else:
          current_configuration[i] = "#"
        current_unknown += 1
    
    current_damaged_contiguous_groups = []
    current_group_count = 0
    current_group_open = False
    for i in range(0, len(hot_springs_map)):
      if current_configuration[i] == "#":
        if current_group_open:
          current_group_count += 1
        else:
          current_group_open = True
          current_group_count = 1
      else:
        if current_group_open:
          current_group_open = False
          current_damaged_contiguous_groups.append(str(current_group_count))
          current_group_count = 0
    if current_group_open:
      current_group_open = False
      current_damaged_contiguous_groups.append(str(current_group_count))
      current_group_count = 0
    
    joined_current_damaged_contiguous_groups = ",".join(current_damaged_contiguous_groups)
    # print(hot_springs_map)
    # print(current_configuration)
    # print(joined_current_damaged_contiguous_groups)
    # print(contiguous_damaged_groups)
    if (joined_current_damaged_contiguous_groups == contiguous_damaged_groups):
      many_valid += 1
  # print(contiguous_damaged_groups)
  # print(hot_springs_map.count("?"))
  # print("----------")
  sum_valids += many_valid

print(sum_valids)
