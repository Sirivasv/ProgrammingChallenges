import sys

pipe_map = [[*line.rstrip()] for line in sys.stdin]

starting_pos = []
types_of_pipe = ["|", "-", "L", "J", "7", "F"]
max_further_step = 0
inside_tiles = 0

def get_next_position(curr_position):

  next_i = -1
  next_j = -1

  ### | Pipe Type
  if pipe_map[curr_position[0]][curr_position[1]] == "|":
    if curr_position[2] == 0: # comes from north - goes to south
      next_i = curr_position[0] + 1
      next_j = curr_position[1]
      if next_i < len(pipe_map):
        if (pipe_map[next_i][next_j] == "|") or (pipe_map[next_i][next_j] == "L") or (pipe_map[next_i][next_j] == "J"):
          return [next_i, next_j, 0]
    elif curr_position[2] == 1: # comes from south - goes to north
      next_i = curr_position[0] - 1
      next_j = curr_position[1]
      if next_i >= 0:
        if (pipe_map[next_i][next_j] == "|"):
          return [next_i, next_j, 1]
        elif (pipe_map[next_i][next_j] == "7") or (pipe_map[next_i][next_j] == "F"):
          return [next_i, next_j, 0]

  ### - Pipe Type
  elif pipe_map[curr_position[0]][curr_position[1]] == "-":
    if curr_position[2] == 0: # comes from west - goes to east
      next_i = curr_position[0]
      next_j = curr_position[1] + 1
      if next_j < len(pipe_map[next_i]):
        if (pipe_map[next_i][next_j] == "-"):
          return [next_i, next_j, 0]
        elif (pipe_map[next_i][next_j] == "J") or (pipe_map[next_i][next_j] == "7"):
          return [next_i, next_j, 1]
          
    elif curr_position[2] == 1: # comes from east - goes to west
      next_i = curr_position[0]
      next_j = curr_position[1] - 1
      if next_j >= 0:
        if (pipe_map[next_i][next_j] == "-") or (pipe_map[next_i][next_j] == "L") or (pipe_map[next_i][next_j] == "F"):
          return [next_i, next_j, 1]

  ### L Pipe Type
  elif pipe_map[curr_position[0]][curr_position[1]] == "L":
    if curr_position[2] == 0: # comes from north - goes to east
      next_i = curr_position[0]
      next_j = curr_position[1] + 1
      if next_j < len(pipe_map[next_i]):
        if (pipe_map[next_i][next_j] == "-"):
          return [next_i, next_j, 0]
        elif (pipe_map[next_i][next_j] == "J") or (pipe_map[next_i][next_j] == "7"):
          return [next_i, next_j, 1]
          
    elif curr_position[2] == 1: # comes from east - goes to north
      next_i = curr_position[0] - 1
      next_j = curr_position[1]
      if next_i >= 0:
        if (pipe_map[next_i][next_j] == "|"):
          return [next_i, next_j, 1]
        elif (pipe_map[next_i][next_j] == "7") or (pipe_map[next_i][next_j] == "F"):
          return [next_i, next_j, 0]

  ### J Pipe Type
  elif pipe_map[curr_position[0]][curr_position[1]] == "J":
    if curr_position[2] == 0: # comes from north - goes to west
      next_i = curr_position[0]
      next_j = curr_position[1] - 1
      if next_j >= 0:
        if (pipe_map[next_i][next_j] == "-") or (pipe_map[next_i][next_j] == "L") or (pipe_map[next_i][next_j] == "F"):
          return [next_i, next_j, 1]
          
    elif curr_position[2] == 1: # comes from west - goes to north
      next_i = curr_position[0] - 1
      next_j = curr_position[1]
      if next_i >= 0:
        if (pipe_map[next_i][next_j] == "|"):
          return [next_i, next_j, 1]
        elif (pipe_map[next_i][next_j] == "7") or (pipe_map[next_i][next_j] == "F"):
          return [next_i, next_j, 0]
  
  ### 7 Pipe Type
  elif pipe_map[curr_position[0]][curr_position[1]] == "7":
    if curr_position[2] == 0: # comes from south - goes to west
      next_i = curr_position[0]
      next_j = curr_position[1] - 1
      if next_j >= 0:
        if (pipe_map[next_i][next_j] == "-") or (pipe_map[next_i][next_j] == "L") or (pipe_map[next_i][next_j] == "F"):
          return [next_i, next_j, 1]
          
    elif curr_position[2] == 1: # comes from west - goes to south
      next_i = curr_position[0] + 1
      next_j = curr_position[1]
      if next_i < len(pipe_map):
        if (pipe_map[next_i][next_j] == "|") or (pipe_map[next_i][next_j] == "L") or (pipe_map[next_i][next_j] == "J"):
          return [next_i, next_j, 0]
  
  ### F Pipe Type
  elif pipe_map[curr_position[0]][curr_position[1]] == "F":
    if curr_position[2] == 0: # comes from south - goes to east
      next_i = curr_position[0]
      next_j = curr_position[1] + 1
      if next_j < len(pipe_map[next_i]):
        if (pipe_map[next_i][next_j] == "-"):
          return [next_i, next_j, 0]
        elif (pipe_map[next_i][next_j] == "J") or (pipe_map[next_i][next_j] == "7"):
          return [next_i, next_j, 1]
          
    elif curr_position[2] == 1: # comes from east - goes to south
      next_i = curr_position[0] + 1
      next_j = curr_position[1]
      if next_i < len(pipe_map):
        if (pipe_map[next_i][next_j] == "|") or (pipe_map[next_i][next_j] == "L") or (pipe_map[next_i][next_j] == "J"):
          return [next_i, next_j, 0]
  
  return [-1, -1, -1]

def get_further_step_in_cycle():

  curr_positions = [[starting_pos[0], starting_pos[1], 0]]
  # print(curr_positions)
  visited_tiles = {}
  curr_step = 0
  there_is_cycle = False
  next_positions = []
  current_cycle_map = []
  for i in range(0, len(pipe_map)):
    current_cycle_map.append([])
    for j in range(0, len(pipe_map[i])):
      current_cycle_map[i].append(0)
  
  current_cycle_map[starting_pos[0]][starting_pos[1]] = 1

  while len(curr_positions) > 0:
    
    next_positions = []
    for curr_position in curr_positions:
      position_encoded = ",".join([str(curr_position[0]), str(curr_position[1]), str(curr_position[2])])
      # print(position_encoded)
      if not position_encoded in visited_tiles:
        visited_tiles[position_encoded] = curr_step
        current_cycle_map[curr_position[0]][curr_position[1]] = 1
      else:
        there_is_cycle = True
        current_cycle_map
        # print(pipe_map[starting_pos[0]][starting_pos[1]])
        check_many_inside(current_cycle_map)
        return int(curr_step/2)
      
      next_position = get_next_position(curr_position)
      # print("-------------")
      # print(curr_position)
      # print(next_position)
      if (next_position[0] != -1):
        next_positions.append(next_position)
    
    curr_positions = next_positions
    curr_step += 1
  
  if not there_is_cycle:
    return -1

def is_inside(start_i, start_j, cycle_map):
  
  many_odd = 0
  many_cycle_pipes_up = 0

  found_cycle_pipe = 0.0
  many_found_cycle_pipes = 0
  curr_opener = ""
  for i in range(0, start_i + 1):
    i = start_i - i
    if cycle_map[i][start_j] == 1:
      found_cycle_pipe = 1
    if cycle_map[i][start_j] == 1:
      if pipe_map[i][start_j] == "-":
        many_cycle_pipes_up += 1.0
      elif pipe_map[i][start_j] == "F":
        if curr_opener == "J":
          many_cycle_pipes_up += 1.0
      elif pipe_map[i][start_j] == "7":
        if curr_opener == "L":
          many_cycle_pipes_up += 1.0
      elif pipe_map[i][start_j] == "L" or pipe_map[i][start_j] == "J":
        curr_opener = pipe_map[i][start_j]

  if int(many_cycle_pipes_up) % 2 == 1:
    many_odd += 1
  
  if found_cycle_pipe == 0:
    return False

  many_found_cycle_pipes += found_cycle_pipe
  found_cycle_pipe = 0

  many_cycle_pipes_down = 0.0
  for i in range(start_i, len(cycle_map)):
    if cycle_map[i][start_j] == 1:
      found_cycle_pipe = 1
    if cycle_map[i][start_j] == 1:
      if pipe_map[i][start_j] == "-":
        many_cycle_pipes_down += 1.0
      elif pipe_map[i][start_j] == "L":
        if curr_opener == "7":
          many_cycle_pipes_down += 1.0
      elif pipe_map[i][start_j] == "J":
        if curr_opener == "F":
          many_cycle_pipes_down += 1.0
      elif pipe_map[i][start_j] == "7" or pipe_map[i][start_j] == "F":
        curr_opener = pipe_map[i][start_j]
  # print("--{}".format(many_cycle_pipes_up))  
  if int(many_cycle_pipes_down) % 2 == 1:
    many_odd += 1
  
  if found_cycle_pipe == 0:
    return False

  many_found_cycle_pipes += found_cycle_pipe
  found_cycle_pipe = 0
  
  many_odd_up_down = many_odd

  many_odd = 0

  many_cycle_pipes_left = 0.0
  for j in range(0, start_j + 1):
    j = start_j - j
    if cycle_map[start_i][j] == 1:
      found_cycle_pipe = 1
    if cycle_map[start_i][j] == 1:
      if pipe_map[start_i][j] == "|":
        many_cycle_pipes_left += 1.0
      elif pipe_map[start_i][j] == "F":
        if curr_opener == "J":
          many_cycle_pipes_left += 1.0
      elif pipe_map[start_i][j] == "L":
        if curr_opener == "7":
          many_cycle_pipes_left += 1.0
      elif pipe_map[start_i][j] == "7" or pipe_map[start_i][j] == "J":
        curr_opener = pipe_map[start_i][j]
  
  if int(many_cycle_pipes_left) % 2 == 1:
    many_odd += 1
  
  if found_cycle_pipe == 0:
    return False

  many_found_cycle_pipes += found_cycle_pipe
  found_cycle_pipe = 0
  
  many_cycle_pipes_right = 0.0
  for j in range(start_j, len(cycle_map[start_i])):
    if cycle_map[start_i][j] == 1:
      found_cycle_pipe = 1
    if cycle_map[start_i][j] == 1:
      if pipe_map[start_i][j] == "|":
        many_cycle_pipes_right += 1.0
      elif pipe_map[start_i][j] == "J":
        if curr_opener == "F":
          many_cycle_pipes_right += 1.0
      elif pipe_map[start_i][j] == "7":
        if curr_opener == "L":
          many_cycle_pipes_right += 1.0
      elif pipe_map[start_i][j] == "F" or pipe_map[start_i][j] == "L":
        curr_opener = pipe_map[start_i][j]
  
  if int(many_cycle_pipes_right) % 2 == 1:
    many_odd += 1
  
  if found_cycle_pipe == 0:
    return False

  many_found_cycle_pipes += found_cycle_pipe
  found_cycle_pipe = 0
  
  many_odd_left_right = many_odd
  # print(many_odd_up_down)
  # print(many_odd_left_right)
  # print("----")
  if (many_odd_up_down + many_odd_left_right) == 4:
    return True

  return False

def check_many_inside(cycle_map):
  inside_tiles = 0
  # for i in range(0, len(cycle_map)):
    # print(cycle_map[i])
  # print(pipe_map[starting_pos[0]][starting_pos[1]])
  for i in range(0, len(cycle_map)):
    for j in range(0, len(cycle_map[i])):
      if cycle_map[i][j] == 0:
        # print("({}, {}) = {}".format(i, j, pipe_map[i][j]))
        if is_inside(i,j, cycle_map):
          # print("({}, {}) = {}".format(i, j, pipe_map[i][j]))
          inside_tiles += 1
  print(inside_tiles)

for i in range(0, len(pipe_map)):
  for j in range(0, len(pipe_map[i])):
    if pipe_map[i][j] == "S":
      starting_pos = [i, j]
      break

for type_of_pipe in types_of_pipe:
  pipe_map[starting_pos[0]][starting_pos[1]] = type_of_pipe
  get_further_step_in_cycle()
