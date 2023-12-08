import sys

adj_list = {}

instruction_sequence = "" 

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
    curr_node_list.append("{}".format(node_id))

next_node_list = []

while True:
  step_id = step_id_counter % len(instruction_sequence)
  
  all_end_in_z = True
  for curr_node in curr_node_list:
    if curr_node[2] != "Z":
      all_end_in_z = False
  
  if all_end_in_z:
    many_steps = step_id_counter
    break
  
  next_node_list = []
  for curr_node in curr_node_list:
    next_move = 1 
    if instruction_sequence[step_id] == "L":
      next_move = 0
    print(adj_list[curr_node][next_move])
    next_node_list.append("{}".format(adj_list[curr_node][next_move]))
  print(step_id)
  print(step_id_counter)
  print("-+---")
  curr_node_list = next_node_list
  step_id_counter += 1

print(many_steps)