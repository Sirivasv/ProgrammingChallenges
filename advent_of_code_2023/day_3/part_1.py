import sys

final_sum = 0
max_i = 0
max_j = 0
schematic = []

def is_symbol(check_char):
  if check_char.isdigit():
    return False
  if check_char == '.':
    return False
  return True

def is_symbol_adjacent(index_i, start_j, end_j):
  # Check left
  if (start_j - 1) >= 0:
    if (is_symbol(schematic[index_i][start_j - 1])):
      return True
  # Check right
  if (end_j + 1) < max_j:
    if is_symbol(schematic[index_i][end_j + 1]):
      return True
  # Check line above
  if (index_i - 1) >= 0:
    actual_start_j = start_j
    if (start_j - 1) >= 0:
      actual_start_j = start_j - 1
    
    actual_end_j = end_j
    if (end_j + 1) < max_j:
      actual_end_j = end_j + 1
    
    for id_j in range(actual_start_j, actual_end_j + 1):
      if is_symbol(schematic[index_i - 1][id_j]):
        return True
  # Check line below
  if (index_i + 1) < max_i:
    actual_start_j = start_j
    if (start_j - 1) >= 0:
      actual_start_j = start_j - 1
    
    actual_end_j = end_j
    if (end_j + 1) < max_j:
      actual_end_j = end_j + 1
    
    for id_j in range(actual_start_j, actual_end_j + 1):
      if is_symbol(schematic[index_i + 1][id_j]):
        return True

  return False

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
        if is_symbol_adjacent(i, current_number_start_j, j - 1):
          final_sum = final_sum + current_number
        processing_number = False
        current_number = 0

  if processing_number:
      processing_number = False
      if is_symbol_adjacent(i, current_number_start_j, max_j - 1):
        final_sum = final_sum + current_number

print(final_sum)
