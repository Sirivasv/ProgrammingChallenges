import sys

directions_i = [0, 1, 0, -1]
directions_j = [1, 0, -1, 0]

input_map = [[*line.rstrip()] for line in sys.stdin]

map_len_i = len(input_map)
map_len_j = len(input_map[0])

max_steps = 64 + 1

starting_pos = []

visited_map = []
for i in range(map_len_i):
  visited_map.append([])
  for j in range(map_len_j):
    if input_map[i][j] == "S":
      starting_pos = [i, j]
    visited_map[i].append([])
    for k in range(max_steps):
      visited_map[i][j].append(0)

curr_positions = [[starting_pos[0], starting_pos[1], 0]]
visited_map[starting_pos[0]][starting_pos[1]][0] = 1

while len(curr_positions) > 0:

  curr_position = curr_positions[0]
  curr_positions = curr_positions[1:]

  curr_i = curr_position[0]
  curr_j = curr_position[1]
  curr_step = curr_position[2]
  
  next_step = curr_step + 1
  for next_dir in range(4):
    next_i = curr_i + directions_i[next_dir]
    next_j = curr_j + directions_j[next_dir]

    if (next_step < max_steps) and (next_i >= 0) and (next_i < map_len_i) and (next_j >= 0) and (next_j < map_len_j) and ((input_map[next_i][next_j] == ".") or (input_map[next_i][next_j] == "S")) and (not visited_map[next_i][next_j][next_step]):
      visited_map[next_i][next_j][next_step] = 1
      curr_positions.append([next_i, next_j, next_step])

final_count = 0
for i in range(map_len_i):
  for j in range(map_len_j):
    if visited_map[i][j][max_steps - 1] == 1:
      final_count += 1
print(final_count)