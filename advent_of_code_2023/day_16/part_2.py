import sys

input_map = [[*line.rstrip()] for line in sys.stdin]

map_len_i = len(input_map)
map_len_j = len(input_map[0])

visited_map = []

def refresh_visited_map():
  global visited_map
  visited_map = []
  for i in range(map_len_i):
    visited_map.append([])
    for j in range(map_len_j):
      visited_map[i].append([0, 0, 0, 0])

def get_next_positions(curr_position):
  curr_i = curr_position[0]
  curr_j = curr_position[1]
  curr_or = curr_position[2]
  curr_symbol = input_map[curr_i][curr_j]

  next_i_1 = -1
  next_j_1 = -1
  next_or_1 = -1

  next_i_2 = -1
  next_j_2 = -1
  next_or_2 = -1

  if curr_symbol == "|":
    if curr_or == 0:

      next_i_1 = curr_i - 1
      next_j_1 = curr_j
      next_or_1 = 3

      next_i_2 = curr_i + 1
      next_j_2 = curr_j
      next_or_2 = 1

    elif curr_or == 1:

      next_i_1 = curr_i + 1
      next_j_1 = curr_j
      next_or_1 = 1

    elif curr_or == 2:

      next_i_1 = curr_i - 1
      next_j_1 = curr_j
      next_or_1 = 3

      next_i_2 = curr_i + 1
      next_j_2 = curr_j
      next_or_2 = 1

    elif curr_or == 3:

      next_i_1 = curr_i - 1
      next_j_1 = curr_j
      next_or_1 = 3

  elif curr_symbol == "-":
    if curr_or == 0:

      next_i_1 = curr_i
      next_j_1 = curr_j + 1
      next_or_1 = 0

    elif curr_or == 1:
     
      next_i_1 = curr_i
      next_j_1 = curr_j + 1
      next_or_1 = 0

      next_i_2 = curr_i
      next_j_2 = curr_j - 1
      next_or_2 = 2

    elif curr_or == 2:

      next_i_1 = curr_i
      next_j_1 = curr_j - 1
      next_or_1 = 2

    elif curr_or == 3:

      next_i_1 = curr_i
      next_j_1 = curr_j + 1
      next_or_1 = 0

      next_i_2 = curr_i
      next_j_2 = curr_j - 1
      next_or_2 = 2

  elif curr_symbol == "/":
    if curr_or == 0:

      next_i_1 = curr_i - 1
      next_j_1 = curr_j
      next_or_1 = 3

    elif curr_or == 1:
      
      next_i_1 = curr_i
      next_j_1 = curr_j - 1
      next_or_1 = 2

    elif curr_or == 2:

      next_i_1 = curr_i + 1
      next_j_1 = curr_j
      next_or_1 = 1

    elif curr_or == 3:

      next_i_1 = curr_i
      next_j_1 = curr_j + 1
      next_or_1 = 0

  elif curr_symbol == "\\":
    if curr_or == 0:

      next_i_1 = curr_i + 1
      next_j_1 = curr_j
      next_or_1 = 1

    elif curr_or == 1:

      next_i_1 = curr_i
      next_j_1 = curr_j + 1
      next_or_1 = 0

    elif curr_or == 2:

      next_i_1 = curr_i - 1
      next_j_1 = curr_j
      next_or_1 = 3

    elif curr_or == 3:

      next_i_1 = curr_i
      next_j_1 = curr_j - 1
      next_or_1 = 2

  elif curr_symbol == ".":
    if curr_or == 0:
      
      next_i_1 = curr_i
      next_j_1 = curr_j + 1
      next_or_1 = 0

    elif curr_or == 1:

      next_i_1 = curr_i + 1
      next_j_1 = curr_j
      next_or_1 = 1

    elif curr_or == 2:

      next_i_1 = curr_i
      next_j_1 = curr_j - 1
      next_or_1 = 2

    elif curr_or == 3:

      next_i_1 = curr_i - 1
      next_j_1 = curr_j
      next_or_1 = 3
  
  next_pos_1 = [next_i_1, next_j_1, next_or_1]
  if not ((next_i_1 >= 0) and (next_i_1 < map_len_i) and (next_j_1 >= 0) and (next_j_1 < map_len_j)):
    next_pos_1 = [-1, -1, -1]

  next_pos_2 = [next_i_2, next_j_2, next_or_2]
  if not ((next_i_2 >= 0) and (next_i_2 < map_len_i) and (next_j_2 >= 0) and (next_j_2 < map_len_j)):
    next_pos_2 = [-1, -1, -1]

  return [next_pos_1, next_pos_2]

def bfs_map(orig_position):
  
  curr_positions = [orig_position]
  visited_map[orig_position[0]][orig_position[1]][orig_position[2]] = 1
  while len(curr_positions) > 0:

    next_positions = []
    for pos_i in range(len(curr_positions)):
      curr_position = curr_positions[pos_i]
      
      next_pair_positions = get_next_positions(curr_position)

      if (next_pair_positions[0][0] != -1) and (visited_map[next_pair_positions[0][0]][ next_pair_positions[0][1]][next_pair_positions[0][2]] == 0):
        visited_map[next_pair_positions[0][0]][next_pair_positions[0][1]][next_pair_positions[0][2]] = 1
        next_positions.append(next_pair_positions[0])
      
      if (next_pair_positions[1][0] != -1) and (visited_map[next_pair_positions[1][0]][ next_pair_positions[1][1]][next_pair_positions[1][2]] == 0):
        visited_map[next_pair_positions[1][0]][next_pair_positions[1][1]][next_pair_positions[1][2]] = 1
        next_positions.append(next_pair_positions[1])
    
    curr_positions = next_positions

  final_sum = 0
  for i in range(len(visited_map)):
    for j in range(len(visited_map[i])):
      many_i_j = 0
      for k in range(len(visited_map[i][j])):
        many_i_j += visited_map[i][j][k]
      if many_i_j > 0:
        final_sum += 1
  return final_sum

curr_check = []
refresh_visited_map()
final_max_sum = 0

# Check top edge downwards
for j in range(len(input_map[0])):
  curr_check = [0, j, 1]
  curr_final_sum = bfs_map(curr_check)
  final_max_sum = max(final_max_sum, curr_final_sum)
  refresh_visited_map()

# Check right edge to the left
for i in range(len(input_map)):
  curr_check = [i, map_len_j - 1, 2]
  curr_final_sum = bfs_map(curr_check)
  final_max_sum = max(final_max_sum, curr_final_sum)
  refresh_visited_map()

# Check bottom edge upwards
for j in range(len(input_map[map_len_i - 1])):
  curr_check = [map_len_i - 1, j, 3]
  curr_final_sum = bfs_map(curr_check)
  final_max_sum = max(final_max_sum, curr_final_sum)
  refresh_visited_map()

# Check left edge to the right
for i in range(len(input_map)):
  curr_check = [0, i, 0]
  curr_final_sum = bfs_map(curr_check)
  final_max_sum = max(final_max_sum, curr_final_sum)
  refresh_visited_map()

print(final_max_sum)

