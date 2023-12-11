import sys

original_universe_map = [[*line.rstrip()] for line in sys.stdin]

O_MAX_I = len(original_universe_map)
O_MAX_J = len(original_universe_map[0])

expanded_universe = []
for i in range(0, O_MAX_I):
  expanded_universe.append([])
  for j in range(0, O_MAX_J):
    expanded_universe[i].append(original_universe_map[i][j])

# Expand vertically
rows_to_exand_vertically = []
for i in range(0, O_MAX_I):
  many_galaxys_in_row = 0
  for j in range(0, O_MAX_J):
    if original_universe_map[i][j] == "#":
      many_galaxys_in_row += 1
  
  if many_galaxys_in_row == 0:
    rows_to_exand_vertically.append(i)

for row_i in range(0, len(rows_to_exand_vertically)):
  new_expanding_row = [ "." for s_i in range(0, O_MAX_J)]
  new_expanding_row_id = row_i + rows_to_exand_vertically[row_i]
  expanding_part_1 = expanded_universe[:new_expanding_row_id + 1]
  expanding_part_2 = []
  if rows_to_exand_vertically[row_i] < (O_MAX_I - 1):
    expanding_part_2 = expanded_universe[new_expanding_row_id + 1:]
  expanded_universe =  expanding_part_1 + [new_expanding_row] + expanding_part_2
  
E_MAX_I = len(expanded_universe)

# Expand horizontally
columns_to_exand_horizontally = []
for j in range(0, O_MAX_J):
  many_galaxys_in_column = 0
  for i in range(0, O_MAX_I):
    if original_universe_map[i][j] == "#":
      many_galaxys_in_column += 1
  
  if many_galaxys_in_column == 0:
    columns_to_exand_horizontally.append(j)

for col_i in range(0, len(columns_to_exand_horizontally)):
  new_expanding_col_id = col_i + columns_to_exand_horizontally[col_i]
  
  for i in range(0, E_MAX_I):  
    expanding_part_1 = expanded_universe[i][:new_expanding_col_id + 1]
    expanding_part_2 = []
    if columns_to_exand_horizontally[col_i] < (O_MAX_J - 1):
      expanding_part_2 = expanded_universe[i][new_expanding_col_id + 1:]
    expanded_universe[i] =  expanding_part_1 + ["."] + expanding_part_2


E_MAX_J = len(expanded_universe[0])

galaxy_positions = []
sum_distances = 0
for i in range(0, E_MAX_I):
  for j in range(0, E_MAX_J):
    if expanded_universe[i][j] == "#":
      for galaxy_position in galaxy_positions:
        sum_distances += abs(i - galaxy_position[0]) + abs(j - galaxy_position[1])
      galaxy_positions.append([i, j])
print(sum_distances)
