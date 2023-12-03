import sys

final_sum = 0
max_i = 0
max_j = 0
schematic = []

gears_adjacency = {}

def is_symbol(symbol_i, symbol_j, id_i, id_si, id_ej, current_number):
  check_char = schematic[symbol_i][symbol_j]
  if check_char.isdigit():
    return False
  if check_char == '.':
    return False
  if check_char == '*':
    key_map = "{},{}".format(symbol_i, symbol_j)
    if not key_map in gears_adjacency:
      gears_adjacency[key_map] = {}
    key_i_j = "{},{},{}".format(id_i, id_si, id_ej)
    gears_adjacency[key_map][key_i_j] = current_number
    return True
  return True

def is_symbol_adjacent(index_i, start_j, end_j, current_number):

  is_symbol_adjacent_flag = False

  # Check left
  if (start_j - 1) >= 0:
    if (is_symbol(index_i, start_j - 1, index_i, start_j, end_j, current_number)):
      is_symbol_adjacent_flag = True

  # Check right
  if (end_j + 1) < max_j:
    if is_symbol(index_i, end_j + 1, index_i, start_j, end_j, current_number):
      is_symbol_adjacent_flag = True

  # Check line above
  if (index_i - 1) >= 0:
    actual_start_j = start_j
    if (start_j - 1) >= 0:
      actual_start_j = start_j - 1
    
    actual_end_j = end_j
    if (end_j + 1) < max_j:
      actual_end_j = end_j + 1
    
    for id_j in range(actual_start_j, actual_end_j + 1):
      if is_symbol(index_i - 1, id_j, index_i, start_j, end_j, current_number):
        is_symbol_adjacent_flag = True
        
  # Check line below
  if (index_i + 1) < max_i:
    actual_start_j = start_j
    if (start_j - 1) >= 0:
      actual_start_j = start_j - 1
    
    actual_end_j = end_j
    if (end_j + 1) < max_j:
      actual_end_j = end_j + 1
    
    for id_j in range(actual_start_j, actual_end_j + 1):
      if is_symbol(index_i + 1, id_j, index_i, start_j, end_j, current_number):
        is_symbol_adjacent_flag = True

  return is_symbol_adjacent_flag

for line in sys.stdin:
  curr_line = line.rstrip()
  schematic.append([*curr_line])

max_i = len(schematic)
max_j = len(schematic[0])

for i in range(0, max_i):
  processing_number = False
  current_number = 0
  current_number_start_j = 0

  for j in range(0, max_j):
    if schematic[i][j].isdigit():
      current_number = current_number * 10 + int(schematic[i][j])
      if not processing_number:
        processing_number = True
        current_number_start_j = j
    else:
      if processing_number:
        is_symbol_adjacent(i, current_number_start_j, j - 1, current_number)
        processing_number = False
        current_number = 0

  if processing_number:
      processing_number = False
      is_symbol_adjacent(i, current_number_start_j, j - 1, current_number)

for gear in gears_adjacency:
  if len(gears_adjacency[gear]) == 2:
    current_ratio = 1
    for number_i_j in gears_adjacency[gear]:
      current_ratio = current_ratio * gears_adjacency[gear][number_i_j]
    
    final_sum = final_sum + current_ratio

print(final_sum)
