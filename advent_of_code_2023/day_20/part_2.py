import sys
import copy

input_lines = [line.rstrip() for line in sys.stdin]

def are_same_state(module_current_states, module_starting_states):
  
  for module_id in module_current_states:
    module_type = module_current_states[module_id][0]
    
    curr_module_onoff = module_current_states[module_id][1]
    curr_module_inputs = module_current_states[module_id][2]

    start_module_onoff = module_starting_states[module_id][1]
    start_module_inputs = module_starting_states[module_id][2]

    if module_type == "broadcaster":
      continue
    if module_type == "%" and curr_module_onoff != start_module_onoff:
      return False
    if module_type == "&":
      for module_input_id in curr_module_inputs:
        if curr_module_inputs[module_input_id] != start_module_inputs[module_input_id]:
          return False
  
  return True

# type, on/off, inputs remember, adjacency list
module_starting_states = {}
for input_line in input_lines:
  input_line_split = input_line.split("->")

  current_raw_module = input_line_split[0].strip()
  current_module_type = current_raw_module[0]
  current_module_id = current_raw_module[1:]
  
  current_adj_list = [x.strip() for x in input_line_split[1].strip().split(",")]

  if current_raw_module == "broadcaster":
    current_module_id = current_raw_module
    current_module_type = current_raw_module

  if not current_module_id in module_starting_states:
    module_starting_states[current_module_id] = ["", 0, {}, []]
  
  module_starting_states[current_module_id][0] = current_module_type
  module_starting_states[current_module_id][3] = current_adj_list 
  for receiver_id in current_adj_list:
    if not receiver_id in module_starting_states:
      module_starting_states[receiver_id] = ["", 0, {}, []]
    module_starting_states[receiver_id][2][current_module_id] = 0

module_current_states = {}
for module_id in module_starting_states:
  module_current_states[module_id] = []
  for element_id in range(len(module_starting_states[module_id])):
    module_current_states[module_id].append(copy.deepcopy(module_starting_states[module_id][element_id]))

final_sum_low = 0
final_sum_high = 0
saw_module_on = {
  "qs":{},
  "jv":{},
  "pr":{},
  "jm":{},
  "kj":{},
}
for step_id in range(200000000):
  
  curr_modules_processing = [["broadcaster", "button", 0]]
  final_sum_low += 1
  
  while len(curr_modules_processing) > 0:

    curr_module_processing = curr_modules_processing[0]
    curr_modules_processing = curr_modules_processing[1:]

    curr_module_id = curr_module_processing[0]
    curr_module_input_id = curr_module_processing[1]
    curr_received_signal = curr_module_processing[2]
        
 
    if curr_module_id == "rx" and curr_received_signal == 0:
      print("WIN")
      print(step_id + 1)
      break

    curr_module_type = module_current_states[curr_module_id][0]
    
    curr_signal_to_send = 0
    will_send_signals = False

    if curr_module_type == "broadcaster":
      will_send_signals = True

    if curr_module_type == "%" and curr_received_signal == 0:
      if module_current_states[curr_module_id][1] == 0:
        module_current_states[curr_module_id][1] = 1
        curr_signal_to_send = 1
      else:
        module_current_states[curr_module_id][1] = 0
        curr_signal_to_send = 0
      will_send_signals = True

    if curr_module_type == "&":
      will_send_signals = True
      module_current_states[curr_module_id][2][curr_module_input_id] = curr_received_signal
      
      if curr_module_id == "qs" or curr_module_id == "jv" or curr_module_id == "pr" or curr_module_id == "jm" or curr_module_id == "kj":
      # if curr_module_id == "jv":
        # print("********")
        # print(step_id)
        # print("*{}-".format(curr_module_id))
        # print(module_current_states[curr_module_id][2])
        encoded_number = ""
        for module_input_id in module_current_states[curr_module_id][2]:
          encoded_number += str(module_current_states[curr_module_id][2][module_input_id] )
        if not encoded_number in saw_module_on[curr_module_id]:
          saw_module_on[curr_module_id][encoded_number] = 1
          print("********")
          print(step_id + 1)
          print(encoded_number)
          print("*{}-".format(curr_module_id))
          print(module_current_states[curr_module_id][2])

      curr_signal_to_send = 0
      for module_input_id in module_current_states[curr_module_id][2]:
        if module_current_states[curr_module_id][2][module_input_id] == 0:
          curr_signal_to_send = 1
    
    if will_send_signals:
      
      if curr_signal_to_send == 0:
        final_sum_low += len(module_current_states[curr_module_id][3])
      else:
        final_sum_high += len(module_current_states[curr_module_id][3])
      
      # print(curr_module_id)
      # print(curr_signal_to_send)
      # print(len(module_current_states[curr_module_id][3]))

      for module_adj_id in module_current_states[curr_module_id][3]:
        curr_modules_processing.append([module_adj_id, curr_module_id, curr_signal_to_send])

  # if are_same_state(module_current_states, module_starting_states):
  #   print("CYCLE")
  #   print(step_id + 1)
  #   break
    # for module_id in module_current_states:
    #   print(module_id)
    #   print(module_current_states[module_id])
    # print("************")
    # for module_id in module_starting_states:
    #   print(module_starting_states[module_id])

print(final_sum_high * final_sum_low)