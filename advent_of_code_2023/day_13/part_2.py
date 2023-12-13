import sys

input_lines = [line.rstrip() for line in sys.stdin]


final_sum = 0
pattern_map = []
reading_map = False
for input_line in input_lines:
  if(len(input_line) != 0):
    if not reading_map:
      pattern_map = []
      reading_map = True
    pattern_map.append(input_line)
    continue
  
  reading_map = False
  
  map_len_i = len(pattern_map)
  map_len_j = len(pattern_map[0])

  # Find horizontal reflection
  reflections_found = {}
  differences_found = {}
  for i in range(0, map_len_i):
    for j in range(0, map_len_j - 1):
      first_part = pattern_map[i][0:j + 1][::-1]
      second_part = pattern_map[i][j + 1:]
      min_len = min(len(first_part), len(second_part))
      first_part = first_part[:min_len]
      second_part = second_part[:min_len]
      # print(first_part)
      # print(second_part)
      encoded_pair = "{},{}".format(j, j + 1)
      if (first_part == second_part):
        # print(encoded_pair)
        if not encoded_pair in reflections_found:
          reflections_found[encoded_pair] = [0, j + 1]
        reflections_found[encoded_pair][0] += 1
      else:
        if not encoded_pair in differences_found:
          differences_found[encoded_pair] = [0, j + 1, 0, set({})]
        differences_found[encoded_pair][0] += 1
        curr_differences = 0

        for m in range(0, len(first_part)):
          if first_part[m] != second_part[m]:
            curr_differences += 1
            differences_found[encoded_pair][3].add(m)
        differences_found[encoded_pair][2] += curr_differences
      # print("---------")
    # print("+++++++++")
  differences_found_exactly = False
  curr_diff_v = 0
  for differences_found_id in differences_found:
    # print(differences_found[differences_found_id])
    if differences_found[differences_found_id][0] == 1 and differences_found[differences_found_id][2] == 1:
      if differences_found_id in reflections_found:
        # print(reflections_found[differences_found_id])
        # print("dd")
        if reflections_found[differences_found_id][0] == (map_len_i - 1):
          # print("diff")
          # print(differences_found[differences_found_id][3])
          differences_found_exactly = True
          curr_diff_v = differences_found[differences_found_id][1]
  curr_same_v = 0
  if not differences_found_exactly:
    for reflection_found_id in reflections_found:
      if reflections_found[reflection_found_id][0] == map_len_i:
        # print("same")
        curr_same_v = reflections_found[reflection_found_id][1]
  # print("+++")

  # Find vertical reflection
  reflections_found = {}
  differences_found = {}
  for j in range(0, map_len_j):
    for i in range(0, map_len_i - 1):
      current_string = ""
      for k in range(0, map_len_i):
        current_string += pattern_map[k][j]
      
      first_part = current_string[0:i + 1][::-1]
      second_part = current_string[i + 1:]
      min_len = min(len(first_part), len(second_part))
      first_part = first_part[:min_len]
      second_part = second_part[:min_len]
      # print(first_part)
      # print(second_part)
      encoded_pair = "{},{}".format(i, i + 1)
      if (first_part == second_part):
        # print(encoded_pair)
        if not encoded_pair in reflections_found:
          reflections_found[encoded_pair] = [0, i + 1]
        reflections_found[encoded_pair][0] += 1
      else:
        if not encoded_pair in differences_found:
          differences_found[encoded_pair] = [0, i + 1, 0, set({})]
        differences_found[encoded_pair][0] += 1
        curr_differences = 0
        for m in range(0, len(first_part)):
          if first_part[m] != second_part[m]:
            curr_differences += 1
            differences_found[encoded_pair][3].add(m)
        differences_found[encoded_pair][2] += curr_differences
      # print("---------")
    # print("+++++++++")
  differences_found_exactly = False
  curr_diff_h = 0
  for differences_found_id in differences_found:
    # print(differences_found[differences_found_id])
    if differences_found[differences_found_id][0] == 1 and differences_found[differences_found_id][2] == 1:
      if differences_found_id in reflections_found:
        # print(reflections_found[differences_found_id])
        # print("dd")
        if reflections_found[differences_found_id][0] == (map_len_j - 1):
          # print("diff")
          # print(differences_found[differences_found_id][3])
          differences_found_exactly = True
          curr_diff_h = 100*differences_found[differences_found_id][1]
  curr_same_h = 0
  if not differences_found_exactly:
    for reflection_found_id in reflections_found:
      if reflections_found[reflection_found_id][0] == map_len_j:
        # print("same")
        curr_same_h = 100*reflections_found[reflection_found_id][1]
  curr_diff_sum = curr_diff_h + curr_diff_v
  if curr_diff_sum > 0:
    final_sum += curr_diff_sum
  else:
    final_sum += curr_same_h + curr_same_v
  # print("***")
print(final_sum)
