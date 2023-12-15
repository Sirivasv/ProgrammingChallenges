import sys

input_lines = [line.rstrip() for line in sys.stdin]

final_sum = 0

def get_hash(step_code):
  
  curr_hash = 0
  for step_code_i in range(len(step_code)):
    curr_ascii = ord(step_code[step_code_i])
    curr_hash += curr_ascii
    curr_hash = curr_hash * 17
    curr_hash = curr_hash - (int(curr_hash / 256) * 256)
  return curr_hash

for input_line in input_lines:
  input_line_split = input_line.split(",")
  for step_code in input_line_split:
    # print(step_code)
    curr_hash = get_hash(step_code)
    # print(curr_hash)
    final_sum += curr_hash
  print(final_sum)
