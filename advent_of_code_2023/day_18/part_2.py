import sys

input_steps = [line.rstrip() for line in sys.stdin]

shape_vertices = []

def get_shape_area():
  
  sum_deltas = 0
  for v_id in range(len(shape_vertices) - 1):
    sum_deltas += (shape_vertices[v_id][0]*shape_vertices[v_id + 1][1]) - (shape_vertices[v_id][1]*shape_vertices[v_id + 1][0])
  sum_deltas = abs(sum_deltas) / 2
  return int(sum_deltas)

prev_p_id = 0
prev_square = [[0, 0], [0, 1], [1, 1], [1, 0]]
curr_square = []
shape_vertices.append([0, 0])
for input_step_id in range(len(input_steps) - 1):
  curr_input_steps = input_steps[input_step_id]
  curr_input_step_split = curr_input_steps.split(" ")
  curr_direction = curr_input_step_split[0]
  curr_distance = int(curr_input_step_split[1])
  curr_color_code = curr_input_step_split[2][2:-2]
  curr_actual_dir_code = curr_input_step_split[2][-2]
  if curr_actual_dir_code == "0":
    curr_direction = "R"
  elif curr_actual_dir_code == "1":
    curr_direction = "D"
  elif curr_actual_dir_code == "2":
    curr_direction = "L"
  elif curr_actual_dir_code == "3":
    curr_direction = "U"
  curr_distance = int(curr_color_code, 16)

  next_id_input_steps = input_steps[input_step_id + 1]
  next_id_input_step_split = next_id_input_steps.split(" ")
  next_id_direction = next_id_input_step_split[0]
  next_id_distance = int(next_id_input_step_split[1])
  next_id_color_code = next_id_input_step_split[2][2:-2]
  next_id_actual_dir_code = next_id_input_step_split[2][-2]
  if next_id_actual_dir_code == "0":
    next_id_direction = "R"
  elif next_id_actual_dir_code == "1":
    next_id_direction = "D"
  elif next_id_actual_dir_code == "2":
    next_id_direction = "L"
  elif next_id_actual_dir_code == "3":
    next_id_direction = "U"
  next_id_distance = int(next_id_color_code, 16)

  # print("{} - {} - {}".format(curr_direction, curr_distance, next_id_direction))

  curr_square = []
  for p_id in range(4):
    curr_square.append([])
    for c_id in range(2):
      curr_square[p_id].append(prev_square[p_id][c_id])

  if curr_direction == "R":
    for p_id in range(4):
      curr_square[p_id][1] += curr_distance
    
    if (prev_p_id == 0) and (next_id_direction == "U"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 1) and (next_id_direction == "D"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 2) and (next_id_direction == "U"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 3) and (next_id_direction == "D"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif next_id_direction == "D":
      if prev_p_id == 0:
        shape_vertices.append(curr_square[1])
        curr_p_id = 1
      elif prev_p_id == 1:
        shape_vertices.append(curr_square[0])
        curr_p_id = 0
      elif prev_p_id == 2:
        shape_vertices.append(curr_square[3])
        curr_p_id = 3
      elif prev_p_id == 3:
        shape_vertices.append(curr_square[2])
        curr_p_id = 2
    elif next_id_direction == "U":
      if prev_p_id == 0:
        shape_vertices.append(curr_square[1])
        curr_p_id = 1
      elif prev_p_id == 1:
        shape_vertices.append(curr_square[0])
        curr_p_id = 0
      elif prev_p_id == 2:
        shape_vertices.append(curr_square[3])
        curr_p_id = 3
      elif prev_p_id == 3:
        shape_vertices.append(curr_square[2])
        curr_p_id = 2

  elif curr_direction == "L":
    for p_id in range(4):
      curr_square[p_id][1] += -curr_distance
    
    if (prev_p_id == 0) and (next_id_direction == "D"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 1) and (next_id_direction == "U"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 2) and (next_id_direction == "D"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 3) and (next_id_direction == "U"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif next_id_direction == "D":
      if prev_p_id == 0:
        shape_vertices.append(curr_square[1])
        curr_p_id = 1
      elif prev_p_id == 1:
        shape_vertices.append(curr_square[0])
        curr_p_id = 0
      elif prev_p_id == 2:
        shape_vertices.append(curr_square[3])
        curr_p_id = 3
      elif prev_p_id == 3:
        shape_vertices.append(curr_square[2])
        curr_p_id = 2
    elif next_id_direction == "U":
      if prev_p_id == 0:
        shape_vertices.append(curr_square[1])
        curr_p_id = 1
      elif prev_p_id == 1:
        shape_vertices.append(curr_square[0])
        curr_p_id = 0
      elif prev_p_id == 2:
        shape_vertices.append(curr_square[3])
        curr_p_id = 3
      elif prev_p_id == 3:
        shape_vertices.append(curr_square[2])
        curr_p_id = 2

  elif curr_direction == "D":
    for p_id in range(4):
      curr_square[p_id][0] += curr_distance
    
    if (prev_p_id == 0) and (next_id_direction == "L"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 1) and (next_id_direction == "R"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 2) and (next_id_direction == "L"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 3) and (next_id_direction == "R"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (next_id_direction == "L"):
      if prev_p_id == 0:
        shape_vertices.append(curr_square[3])
        curr_p_id = 3
      elif prev_p_id == 3:
        shape_vertices.append(curr_square[0])
        curr_p_id = 0
      elif prev_p_id == 1:
        shape_vertices.append(curr_square[2])
        curr_p_id = 2
      elif prev_p_id == 2:
        shape_vertices.append(curr_square[1])
        curr_p_id = 1
    elif (next_id_direction == "R"):
      if prev_p_id == 0:
        shape_vertices.append(curr_square[3])
        curr_p_id = 3
      elif prev_p_id == 3:
        shape_vertices.append(curr_square[0])
        curr_p_id = 0
      elif prev_p_id == 1:
        shape_vertices.append(curr_square[2])
        curr_p_id = 2
      elif prev_p_id == 2:
        shape_vertices.append(curr_square[1])
        curr_p_id = 1
    
  elif curr_direction == "U":
    for p_id in range(4):
      curr_square[p_id][0] += -curr_distance
    
    if (prev_p_id == 0) and (next_id_direction == "R"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 1) and (next_id_direction == "L"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 2) and (next_id_direction == "R"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif (prev_p_id == 3) and (next_id_direction == "L"):
      shape_vertices.append(curr_square[prev_p_id])
      curr_p_id = prev_p_id
    elif next_id_direction == "R":
      if prev_p_id == 0:
        shape_vertices.append(curr_square[3])
        curr_p_id = 3
      elif prev_p_id == 3:
        shape_vertices.append(curr_square[0])
        curr_p_id = 0
      elif prev_p_id == 1:
        shape_vertices.append(curr_square[2])
        curr_p_id = 2
      elif prev_p_id == 2:
        shape_vertices.append(curr_square[1])
        curr_p_id = 1
    elif next_id_direction == "L":
      if prev_p_id == 0:
        shape_vertices.append(curr_square[3])
        curr_p_id = 3
      elif prev_p_id == 3:
        shape_vertices.append(curr_square[0])
        curr_p_id = 0
      elif prev_p_id == 1:
        shape_vertices.append(curr_square[2])
        curr_p_id = 2
      elif prev_p_id == 2:
        shape_vertices.append(curr_square[1])
        curr_p_id = 1
  # print("*---------")
  # print(curr_direction)
  # print(prev_square)
  # print(curr_square)
  # print(prev_p_id)
  # print(curr_p_id)
  prev_square = curr_square
  prev_p_id = curr_p_id
# print("*****")
# print(shape_vertices)
shape_area = get_shape_area()
print(shape_area)