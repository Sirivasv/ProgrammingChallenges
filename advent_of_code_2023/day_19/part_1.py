import sys
import json

input_lines = [line.rstrip() for line in sys.stdin]

rules_list = []
parts_list = []
blank_line_id = 0
for line_id in range(len(input_lines)):
  if (len(input_lines[line_id]) == 0):
    blank_line_id = line_id
rules_list = input_lines[:blank_line_id]
parts_list = input_lines[blank_line_id + 1:]

parts_clean = []
for part_id in range(len(parts_list)):
  curr_part_raw = parts_list[part_id][1:-1].split(",")
  curr_part_parsed = {}
  for attribute_id in range(len(curr_part_raw)):
    attribute_raw = curr_part_raw[attribute_id].split("=")
    attribute_name = attribute_raw[0]
    attribute_value = int(attribute_raw[1])
    curr_part_parsed[attribute_name] = attribute_value
  parts_clean.append(curr_part_parsed)

rules_clean = {}
for rule_id in range(len(rules_list)):
  curr_rule_raw = rules_list[rule_id].split("{")
  rule_name = curr_rule_raw[0]

  curr_rule_raw_steps = curr_rule_raw[1][:-1].split(",")
  curr_clean_steps = []
  for raw_step_i in range(len(curr_rule_raw_steps)):
    has_value_condition = False
    value_condition_symbol = ""
    if ("<" in curr_rule_raw_steps[raw_step_i]):
      has_value_condition = True
      value_condition_symbol = "<"
    if (">" in curr_rule_raw_steps[raw_step_i]):
      has_value_condition = True
      value_condition_symbol = ">"

    if has_value_condition:
      curr_condition_raw = curr_rule_raw_steps[raw_step_i].split(":")
      curr_send_workflow = curr_condition_raw[1]
      curr_condition_check_raw = curr_condition_raw[0].split(value_condition_symbol)
      curr_attribute_name_check = curr_condition_check_raw[0]
      curr_attribute_value_check = int(curr_condition_check_raw[1])
      curr_clean_steps.append([value_condition_symbol, curr_attribute_name_check, curr_attribute_value_check, curr_send_workflow])
    else:
      curr_clean_steps.append([curr_rule_raw_steps[raw_step_i]])
  rules_clean[rule_name] = curr_clean_steps

curr_parts_processing = []
for parts_clean_id in range(len(parts_clean)):
  curr_parts_processing.append(["in", parts_clean_id])

final_sum = 0
while len(curr_parts_processing) > 0:
  curr_part_processing = curr_parts_processing[0]
  curr_parts_processing = curr_parts_processing[1:]

  curr_rule_name = curr_part_processing[0]
  curr_part_id = curr_part_processing[1]
  
  for rule_step_id in range(len(rules_clean[curr_rule_name])):
    curr_rule_step = rules_clean[curr_rule_name][rule_step_id]

    if (curr_rule_step[0] == ">") or (curr_rule_step[0] == "<"):
      curr_attribute_name_check = curr_rule_step[1]
      curr_attribute_value_check = curr_rule_step[2]
      curr_send_workflow = curr_rule_step[3]

      passed_check = False
      if ((curr_rule_step[0] == ">") and (parts_clean[curr_part_id][curr_attribute_name_check] > curr_attribute_value_check)) or ((curr_rule_step[0] == "<") and (parts_clean[curr_part_id][curr_attribute_name_check] < curr_attribute_value_check)):
        if curr_send_workflow == "R":
          break
        if curr_send_workflow == "A":
          for attribute_name in parts_clean[curr_part_id]:
            final_sum += parts_clean[curr_part_id][attribute_name]
          break
        curr_parts_processing.append([curr_send_workflow, curr_part_id])
        break
    elif (curr_rule_step[0] == "R"):
      break
    elif (curr_rule_step[0] == "A"):
      for attribute_name in parts_clean[curr_part_id]:
        final_sum += parts_clean[curr_part_id][attribute_name]
      break
    else:
      curr_parts_processing.append([curr_rule_step[0], curr_part_id])
      break

# print(rules_clean)
# print("----")
# print(parts_clean)
# print("**********")
print(final_sum)
