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
  boxes = [[] for x in range(256)]
  for step_code in input_line_split:
    label_code = ""
    box_number = 0
    lens_focal_length = 0
    remove_step = False
    if ("-" in step_code):
      label_code = step_code.split("-")[0]
      remove_step = True
      # print(label_code)
    else:
      label_code = step_code.split("=")[0]
      lens_focal_length = int(step_code.split("=")[1])
      # print(label_code)
      # print(lens_focal_length)
    box_number = get_hash(label_code)
    # print(box_number)
    if remove_step:
      found_lens_label = False
      found_lens_i = 0
      for lens_i in range(len(boxes[box_number])):
        curr_lens = boxes[box_number][lens_i]
        if curr_lens[0] == label_code:
          found_lens_label = True
          found_lens_i = lens_i
          break
      if found_lens_label:
        boxes[box_number] = boxes[box_number][:found_lens_i] + boxes[box_number][found_lens_i + 1:]
    else:
      found_lens_label = False
      for lens_i in range(len(boxes[box_number])):
        if boxes[box_number][lens_i][0] == label_code:
          found_lens_label = True
          boxes[box_number][lens_i][1] = lens_focal_length
          break
      if not found_lens_label:
        boxes[box_number].append([label_code, lens_focal_length])

  for box_i in range(len(boxes)):
    for slot_i in range(len(boxes[box_i])):
      final_sum += (box_i + 1) * (slot_i + 1) * (boxes[box_i][slot_i][1])
  print(final_sum)
