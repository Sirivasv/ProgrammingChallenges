import sys
import copy

input_map = [[*line.rstrip()] for line in sys.stdin]

map_len_i = len(input_map)
map_len_j = len(input_map[0])

orig_position = [0, 0]
end_position = [0, 0]
visited_map = []
for j in range(map_len_j):
  if (input_map[0][j] == '.'):
      orig_position = [0, j]
  if (input_map[map_len_i - 1][j] == "."):
      end_position = [map_len_i - 1, j]

directions_i = [0, 1, 0, -1]
directions_j = [1, 0, -1, 0]

def can_get_to_nodes(orig_position_func):
  global visited_map
  can_get_to = {}
  visited_map = []
  for i in range(map_len_i):
    visited_map.append([])
    for j in range(map_len_j):
      visited_map[i].append(False)

  curr_positions = [[orig_position_func, 0]]
  visited_map[orig_position_func[0]][orig_position_func[1]] = True

  while len(curr_positions) > 0:

    curr_position = curr_positions[0]
    curr_positions = curr_positions[1:]

    curr_i = curr_position[0][0]
    curr_j = curr_position[0][1]
    curr_dist = curr_position[1]

    many_possible_splits = 0
    is_end_position = False
    if curr_i == end_position[0] and curr_j == end_position[1]:
      is_end_position = True
    for next_dir in range(4):
      next_i = curr_i + directions_i[next_dir]
      next_j = curr_j + directions_j[next_dir]
      
      if (next_i >= 0) and (next_i < map_len_i) and (next_j >= 0) and (next_j < map_len_j) and (input_map[next_i][next_j] != "#"):
        if not visited_map[next_i][next_j]:
          many_possible_splits += 1

    if many_possible_splits > 1 or is_end_position:
      encoded_string = ",".join([str(curr_i), str(curr_j)])
      can_get_to[encoded_string] = curr_dist
    
    for next_dir in range(4):
      next_i = curr_i + directions_i[next_dir]
      next_j = curr_j + directions_j[next_dir]
      
      if (next_i >= 0) and (next_i < map_len_i) and (next_j >= 0) and (next_j < map_len_j) and (input_map[next_i][next_j] != "#"):
        if not visited_map[next_i][next_j]:
          visited_map[next_i][next_j] = True
          if many_possible_splits == 1 or ((many_possible_splits > 1) and (curr_i == orig_position_func[0] and curr_j == orig_position_func[1])):
            curr_positions.append([[next_i, next_j], curr_dist + 1])
  
  return can_get_to

adj_sets = {}
encoded_end_string = ",".join([str(end_position[0]), str(end_position[1])])
encoded_orig_string = ",".join([str(orig_position[0]), str(orig_position[1])])
adj_sets[encoded_orig_string] = can_get_to_nodes(orig_position)
visit_encoded = [encoded_orig_string]

while len(visit_encoded) > 0:
  curr_visit = visit_encoded[0]
  visit_encoded = visit_encoded[1:]

  for encoded_next_node in adj_sets[curr_visit]:
    curr_visit_split = encoded_next_node.split(",")
    curr_visit_i = int(curr_visit_split[0])
    curr_visit_j = int(curr_visit_split[1])
    if not encoded_next_node in adj_sets:
      adj_sets[encoded_next_node] = can_get_to_nodes([curr_visit_i, curr_visit_j])
      visit_encoded.append(encoded_next_node)

full_clean_adj = {}
for adj_set_key in adj_sets:
  if not adj_set_key in full_clean_adj:
    full_clean_adj[adj_set_key] = {}
  for adj_linked_key in adj_sets[adj_set_key]:
    full_clean_adj[adj_set_key][adj_linked_key] = adj_sets[adj_set_key][adj_linked_key]
    if not adj_linked_key in full_clean_adj:
      full_clean_adj[adj_linked_key] = {}
    full_clean_adj[adj_linked_key][adj_set_key] = adj_sets[adj_set_key][adj_linked_key]

# for adj_clean_set_key in full_clean_adj:
#   for adj_clean_linked_key in full_clean_adj[adj_clean_set_key]:
#     print("{};{};{}".format(adj_clean_set_key, adj_clean_linked_key, full_clean_adj[adj_clean_set_key][adj_clean_linked_key]))

answer_cache = {}
def max_path(curr_encoded, visited_dir):
  global answer_cache
  global full_clean_adj

  if curr_encoded == encoded_end_string:
    return 0
  
  keys_sorted_list = list(visited_dir.keys())
  keys_sorted_list.sort()
  encoded_string = ";".join([curr_encoded] + keys_sorted_list)
  
  if encoded_string in answer_cache:
    return answer_cache[encoded_string]

  curr_max_answer = -1000000000
  for adj_clean_linked_key in full_clean_adj[curr_encoded]:
    if not adj_clean_linked_key in visited_dir:
      visited_dir_copy = copy.deepcopy(visited_dir)
      visited_dir_copy[adj_clean_linked_key] = 1
      curr_max_answer = max(curr_max_answer, max_path(adj_clean_linked_key, visited_dir_copy) + full_clean_adj[curr_encoded][adj_clean_linked_key])
  
  answer_cache[encoded_string] = curr_max_answer
  return answer_cache[encoded_string]

orig_visited_dir = {}
orig_visited_dir[encoded_orig_string] = 1
print(max_path(encoded_orig_string, orig_visited_dir))