import sys

input_map = [[*line.rstrip()] for line in sys.stdin]

map_len_i = len(input_map)
map_len_j = len(input_map[0])

for i in range(map_len_i):
  for j in range(map_len_j):
    input_map[i][j] = int(input_map[i][j])

inf_val = 1000000000

visited_map = []
for i in range(map_len_i):
  visited_map.append([])
  for j in range(map_len_j):
    visited_map[i].append([])
    for dir_lim in range(11):
      visited_map[i][j].append([])
      for dir_id in range(4):
        visited_map[i][j][dir_lim].append(inf_val)

# heat, many direction, direction, pos_i, pos_j
orig_position_1 = [0, 0, 0, 0, 0]
orig_position_2 = [0, 0, 1, 0, 0]
curr_positions = [orig_position_1, orig_position_2]

directions_i = [0, 1, 0, -1]
directions_j = [1, 0, -1, 0]

while len(curr_positions) > 0:

  curr_position = curr_positions[0]
  curr_positions = curr_positions[1:]
  # print(curr_position)

  curr_heat = curr_position[0]
  curr_many_dir = curr_position[1]
  curr_dir = curr_position[2]
  curr_i = curr_position[3]
  curr_j = curr_position[4]
  
  for next_dir in range(4):
    next_i = curr_i + directions_i[next_dir]
    next_j = curr_j + directions_j[next_dir]
    
    if (next_i >= 0) and (next_i < map_len_i) and (next_j >= 0) and (next_j < map_len_j):
      
      is_same_dir = next_dir == curr_dir
      next_many_dir = 1
      if is_same_dir:
        next_many_dir = curr_many_dir + 1
      
      min_dirs = min(next_dir, curr_dir)
      max_dirs = max(next_dir, curr_dir)
      if (min_dirs + 2) != max_dirs:
        
        can_move = False
        if (is_same_dir) and (next_many_dir <= 10):
          can_move = True
        elif (not is_same_dir) and (curr_many_dir >= 4):
          can_move = True
        
        if can_move:
          next_heat = curr_heat + input_map[next_i][next_j]
          if next_heat < visited_map[next_i][next_j][next_many_dir][next_dir]:
            visited_map[next_i][next_j][next_many_dir][next_dir] = next_heat
            curr_positions.append([next_heat, next_many_dir, next_dir, next_i, next_j])
  curr_positions.sort()

min_final_heat = inf_val
for dir_lim in range(11):
  for dir_id in range(4):
    min_final_heat = min(visited_map[map_len_i - 1][map_len_j - 1][dir_lim][dir_id], min_final_heat)
print(min_final_heat)

