import sys
from math import lcm

adj_list = {}

path_lengths = []

instruction_sequence = "" 

def get_path_length(start_node_id):

  step_id_counter = 0
  step_id = 0

  next_move = 1 
  if instruction_sequence[step_id] == "L":
    next_move = 0

  curr_node = adj_list[start_node_id][next_move]

  step_id_counter = 1
  visited = {}
  visited[start_node_id] = 1
  while True:
    step_id = step_id_counter % len(instruction_sequence)

    if curr_node[2] == "Z":
      return step_id_counter

    next_move = 1 
    if instruction_sequence[step_id] == "L":
      next_move = 0
    curr_node = adj_list[curr_node][next_move]

    step_id_counter += 1


for line in sys.stdin:
  curr_line = line.rstrip()
  curr_line_split = curr_line.split("=")

  if len(curr_line_split) == 1 and curr_line_split[0] != "":
    instruction_sequence = [*curr_line_split[0]]
  elif len(curr_line_split) > 1:
    curr_node = curr_line_split[0].strip()
    curr_LR_list = curr_line_split[1].strip().split(",")
    curr_LR_list[0] = curr_LR_list[0].strip()[1:]
    curr_LR_list[1] = curr_LR_list[1].strip()[:-1]
    adj_list[curr_node] = [curr_LR_list[0], curr_LR_list[1]]

many_steps = 0
step_id_counter = 0
curr_node_list = []
next_node_list = []

for node_id in adj_list:
  if node_id[2] == "A":
    path_lengths.append(get_path_length(node_id))
# print(path_lengths)
curr_lcm = path_lengths[0]

for path_length in path_lengths:
  curr_lcm = lcm(curr_lcm, path_length)

print(curr_lcm)
