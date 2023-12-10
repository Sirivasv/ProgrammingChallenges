import sys

pipe_map = [[*line.rstrip()] for line in sys.stdin]

starting_pos = []
types_of_pipe = ["|", "-", "L", "J", "7", "F"]
max_further_step = 0

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

  while len(curr_positions) > 0:
    
    next_positions = []
    for curr_position in curr_positions:
      position_encoded = ",".join([str(curr_position[0]), str(curr_position[1]), str(curr_position[2])])
      # print(position_encoded)
      if not position_encoded in visited_tiles:
        visited_tiles[position_encoded] = curr_step
      else:
        there_is_cycle = True
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

for i in range(0, len(pipe_map)):
  for j in range(0, len(pipe_map[i])):
    if pipe_map[i][j] == "S":
      starting_pos = [i, j]
      break

for type_of_pipe in types_of_pipe:
  pipe_map[starting_pos[0]][starting_pos[1]] = type_of_pipe
  # print("**************")
  # for line in pipe_map:
    # print(line)
  
  curr_furthest_step = get_further_step_in_cycle()
  if curr_furthest_step > max_further_step:
    max_further_step = curr_furthest_step

print(max_further_step)
