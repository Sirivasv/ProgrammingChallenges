import sys

input_map = [[*line.rstrip()] for line in sys.stdin]

map_len_i = len(input_map)
map_len_j = len(input_map[0])

sys.setrecursionlimit(100000)

orig_position = [0, 0]
end_position = [0, 0]
answer_cache = {}
for j in range(map_len_j):
  if (input_map[0][j] == '.'):
      orig_position = [0, j]
  if (input_map[map_len_i - 1][j] == "."):
      end_position = [map_len_i - 1, j]
      

directions_i = [0, 1, 0, -1]
directions_j = [1, 0, -1, 0]

def max_path(curr_i, curr_j, prev_i, prev_j):
  global answer_cache
  if curr_i == end_position[0] and curr_j == end_position[1]:
    return 0
  
  encoded_string = ",".join([str(curr_i), str(curr_j), str(prev_i), str(prev_j)])
  
  if encoded_string in answer_cache:
    return answer_cache[encoded_string]
  
  curr_max_answer = -1
  for next_dir in range(4):
    next_i = curr_i + directions_i[next_dir]
    next_j = curr_j + directions_j[next_dir]
    if (next_i >= 0) and (next_i < map_len_i) and (next_j >= 0) and (next_j < map_len_j) and (input_map[next_i][next_j] != "#"):
      if (input_map[next_i][next_j] == ".") or ((input_map[next_i][next_j] == ">") and (next_dir == 0)) or ((input_map[next_i][next_j] == "v") and (next_dir == 1)) or ((input_map[next_i][next_j] == "<") and (next_dir == 2)) or ((input_map[next_i][next_j] == "^") and (next_dir == 3)):
        if (next_i != prev_i) or (next_j != prev_j):
          curr_max_answer = max(curr_max_answer, max_path(next_i, next_j, curr_i, curr_j))
  
  answer_cache[encoded_string] = curr_max_answer + 1
  return answer_cache[encoded_string]

print(max_path(orig_position[0], orig_position[1], orig_position[0], orig_position[1]))
