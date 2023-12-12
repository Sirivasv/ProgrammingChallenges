import sys

input_lines = [line.rstrip() for line in sys.stdin]

many_valid = 0
sum_valids = 0

hot_springs_map = []
max_unknown = 0
for input_line in input_lines:
  input_line_split = input_line.split()
  hot_springs_map = input_line_split[0]
  for i in range(1, 5):
    hot_springs_map = hot_springs_map + "?" + input_line_split[0]
  hot_springs_map = [*hot_springs_map]
  # print(hot_springs_map)

  contiguous_damaged_groups = input_line_split[1]
  for i in range(1, 5):
    contiguous_damaged_groups = contiguous_damaged_groups + "," + input_line_split[1]

  contiguous_damaged_groups = contiguous_damaged_groups.split(",")
  contiguous_damaged_groups = [int(x) for x in contiguous_damaged_groups]
  # print(contiguous_damaged_groups)

  many_unknown = hot_springs_map.count("?")
  max_unknown = max(max_unknown, many_unknown)
  max_contiguous_damaged_group = 0
  for x in contiguous_damaged_groups:
    max_contiguous_damaged_group = max(max_contiguous_damaged_group, x)

  many_valid = 0
  
  hot_springs_map_len = len(hot_springs_map)
  contiguous_damaged_groups_len = len(contiguous_damaged_groups)

  state_map = []
  for i in range(0, hot_springs_map_len + 1):
    state_map.append([])
    for j in range(0, contiguous_damaged_groups_len + 1):
      state_map[i].append([])
      for k in range(0, max_contiguous_damaged_group + 1):
        state_map[i][j].append(0)
  
  for i in range(0, hot_springs_map_len + 1):
    i = hot_springs_map_len - i
    for j in range(0, contiguous_damaged_groups_len + 1):
      j = contiguous_damaged_groups_len - j
      for k in range(0, max_contiguous_damaged_group + 1):
        k = max_contiguous_damaged_group - k
        
        state_map[i][j][k] = 0

        if (i == hot_springs_map_len) and (j == contiguous_damaged_groups_len) and (k == 0):
            state_map[i][j][k] = 1
        elif (i == hot_springs_map_len) and (j == (contiguous_damaged_groups_len - 1)) and (k == contiguous_damaged_groups[j]) :
            state_map[i][j][k] = 1
        elif (i < hot_springs_map_len):
          if (hot_springs_map[i] == '.') and (k == 0):
            state_map[i][j][k] += state_map[i + 1][j][k]
          if (hot_springs_map[i] == '.') and (j < contiguous_damaged_groups_len) and (k == contiguous_damaged_groups[j]):
            state_map[i][j][k] += state_map[i + 1][j + 1][0]
        
          if (hot_springs_map[i] == '#') and (j < contiguous_damaged_groups_len) and (k < contiguous_damaged_groups[j]):
            state_map[i][j][k] += state_map[i + 1][j][k + 1]

          if (hot_springs_map[i] == '?') and (k == 0):
            state_map[i][j][k] += state_map[i + 1][j][k]
          if (hot_springs_map[i] == '?') and (j < contiguous_damaged_groups_len) and (k == contiguous_damaged_groups[j]):
            state_map[i][j][k] += state_map[i + 1][j + 1][0]
          if (hot_springs_map[i] == '?') and (j < contiguous_damaged_groups_len) and (k < contiguous_damaged_groups[j]):
            state_map[i][j][k] += state_map[i + 1][j][k + 1]
        
        # print("({}, {}, {}) = {}".format(i, j, k, state_map[i][j][k]))

  # print(state_map[0][0][0])
  sum_valids += state_map[0][0][0]

print(sum_valids)
