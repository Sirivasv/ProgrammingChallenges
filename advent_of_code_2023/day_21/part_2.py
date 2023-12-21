import sys
import math

directions_i = [0, 1, 0, -1]
directions_j = [1, 0, -1, 0]

input_map = [[*line.rstrip()] for line in sys.stdin]

map_len_i = len(input_map)
map_len_j = len(input_map[0])

max_steps = 481843
for curr_count in range(2, max_steps + 1):
  curr_gcd = math.gcd(curr_count, max_steps)
  print(curr_count)
  print(curr_gcd)
  if curr_gcd == curr_count:
    print("Found")
    break
  print("-------------")