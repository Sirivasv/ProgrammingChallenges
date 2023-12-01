import sys
final_sum = 0

def search_len3_number(element, curr_line):
  if curr_line[element:element+3] == "one":
    return 1
  if curr_line[element:element+3] == "two":
    return 2
  if curr_line[element:element+3] == "six":
    return 6
  return -1

def search_len4_number(element, curr_line):
  if curr_line[element:element+4] == "four":
    return 4
  if curr_line[element:element+4] == "five":
    return 5
  if curr_line[element:element+4] == "nine":
    return 9
  return -1

def search_len5_number(element, curr_line):
  if curr_line[element:element+5] == "three":
    return 3
  if curr_line[element:element+5] == "seven":
    return 7
  if curr_line[element:element+5] == "eight":
    return 8
  return -1


def has_spelled_digit(element, curr_line):

  found_len3_number = search_len3_number(element, curr_line)
  if found_len3_number != -1:
    return found_len3_number

  found_len4_number = search_len4_number(element, curr_line)
  if found_len4_number != -1:
    return found_len4_number

  found_len5_number = search_len5_number(element, curr_line)
  if found_len5_number != -1:
    return found_len5_number
  
  return -1


for line in sys.stdin:
  curr_line = str(line.rstrip())
  left_number = 0
  right_number = 0
  for element in range(0, len(curr_line)):
    if str(curr_line[element]).isdigit():
      left_number = int(curr_line[element])*10
      break
    found_spelled_number = has_spelled_digit(element, curr_line)
    if (found_spelled_number != -1):
      left_number = found_spelled_number * 10
      break
  for element in reversed(range(0, len(curr_line))):
    if str(curr_line[element]).isdigit():
      right_number = int(curr_line[element])
      break
    found_spelled_number = has_spelled_digit(element, curr_line)
    if (found_spelled_number != -1):
      right_number = found_spelled_number
      break
  final_sum = final_sum + left_number + right_number
print(final_sum)
