import sys

input_map = [[*line.rstrip()] for line in sys.stdin]

final_sum = 0

curr_map = []
for i in range(len(input_map)):
  # print(input_map[i])
  curr_map.append([])
  for j in range(len(input_map[i])):
    curr_map[i].append(input_map[i][j])

curr_map_len_i = len(curr_map)
curr_map_len_j = len(curr_map[0])
for i in range(curr_map_len_i):

  for j in range(curr_map_len_j):
    if curr_map[i][j] == ".":
      for n_i in range(i + 1, curr_map_len_i):
        if curr_map[n_i][j] == "O":
          curr_map[n_i][j] = "."
          curr_map[i][j] = "O"
          final_sum += curr_map_len_i - i
          break
        if curr_map[n_i][j] == "#":
          break
    elif curr_map[i][j] == "O":
      final_sum += curr_map_len_i - i

# for i in range(curr_map_len_i):
  # print(curr_map[i])

print(final_sum)
