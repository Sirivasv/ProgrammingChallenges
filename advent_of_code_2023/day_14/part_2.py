import sys

input_map = [[*line.rstrip()] for line in sys.stdin]

final_sum = 0

curr_map = []
for i in range(len(input_map)):
  # print(input_map[i])
  curr_map.append([])
  for j in range(len(input_map[i])):
    curr_map[i].append(input_map[i][j])

curr_map_len_i = len(curr_map)
curr_map_len_j = len(curr_map[0])

# for spin_i in range(many_spins):
# Find the maps period
many_spins = 1
saved_maps = []
saved_maps.append([])
for i in range(curr_map_len_i):
  saved_maps[0].append([])
  for j in range(curr_map_len_j):
    saved_maps[0][i].append(input_map[i][j])

cycle_length = 0
tail_length = 0
while True:

  # Tilt north
  for i in range(curr_map_len_i):
    for j in range(curr_map_len_j):
      if curr_map[i][j] == ".":
        for n_i in range(i + 1, curr_map_len_i):
          if curr_map[n_i][j] == "O":
            curr_map[n_i][j] = "."
            curr_map[i][j] = "O"
            break
          if curr_map[n_i][j] == "#":
            break
  
  # Tilt west
  for j in range(curr_map_len_j):
    for i in range(curr_map_len_i):
      if curr_map[i][j] == ".":
        for n_j in range(j + 1, curr_map_len_j):
          if curr_map[i][n_j] == "O":
            curr_map[i][n_j] = "."
            curr_map[i][j] = "O"
            break
          if curr_map[i][n_j] == "#":
            break

  # Tilt south
  for i in range(curr_map_len_i):
    i = curr_map_len_i - 1 - i
    for j in range(curr_map_len_j):
      if curr_map[i][j] == ".":
        for n_i in range(0, i):
          n_i = i - 1 - n_i
          if curr_map[n_i][j] == "O":
            curr_map[n_i][j] = "."
            curr_map[i][j] = "O"
            break
          if curr_map[n_i][j] == "#":
            break

  # Tilt east
  for j in range(curr_map_len_j):
    j = curr_map_len_j - 1 - j
    for i in range(curr_map_len_i):
      if curr_map[i][j] == ".":
        for n_j in range(0, j):
          n_j = j - 1 - n_j
          if curr_map[i][n_j] == "O":
            curr_map[i][n_j] = "."
            curr_map[i][j] = "O"
            break
          if curr_map[i][n_j] == "#":
            break

  seen_configuration = False
  seen_from_spin_i = 0
  for spin_i in range(many_spins):

    same_conf = True
    for i in range(curr_map_len_i):
      for j in range(curr_map_len_j):
        if curr_map[i][j] != saved_maps[spin_i][i][j]:
          same_conf = False
    
    if same_conf:
      seen_from_spin_i = spin_i
      seen_configuration = True
  
  if seen_configuration:
    # print("Found!")
    # print(seen_from_spin_i)
    # print(many_spins)
    cycle_length = many_spins - seen_from_spin_i
    tail_length = seen_from_spin_i - 1
    # print(cycle_length)
    # print(tail_length)
    break

  saved_maps.append([])
  for i in range(curr_map_len_i):
    saved_maps[many_spins].append([])
    for j in range(curr_map_len_j):
      saved_maps[many_spins][i].append(curr_map[i][j])

  many_spins += 1

# for i in range(curr_map_len_i):
#  print(curr_map[i])
many_spins_needed = tail_length + ((1000000000 - tail_length) % cycle_length)

curr_map = []
for i in range(len(input_map)):
  curr_map.append([])
  for j in range(len(input_map[i])):
    curr_map[i].append(input_map[i][j])

for f_spin_i in range(many_spins_needed):

  # Tilt north
  for i in range(curr_map_len_i):
    for j in range(curr_map_len_j):
      if curr_map[i][j] == ".":
        for n_i in range(i + 1, curr_map_len_i):
          if curr_map[n_i][j] == "O":
            curr_map[n_i][j] = "."
            curr_map[i][j] = "O"
            break
          if curr_map[n_i][j] == "#":
            break
  
  # Tilt west
  for j in range(curr_map_len_j):
    for i in range(curr_map_len_i):
      if curr_map[i][j] == ".":
        for n_j in range(j + 1, curr_map_len_j):
          if curr_map[i][n_j] == "O":
            curr_map[i][n_j] = "."
            curr_map[i][j] = "O"
            break
          if curr_map[i][n_j] == "#":
            break

  # Tilt south
  for i in range(curr_map_len_i):
    i = curr_map_len_i - 1 - i
    for j in range(curr_map_len_j):
      if curr_map[i][j] == ".":
        for n_i in range(0, i):
          n_i = i - 1 - n_i
          if curr_map[n_i][j] == "O":
            curr_map[n_i][j] = "."
            curr_map[i][j] = "O"
            break
          if curr_map[n_i][j] == "#":
            break

  # Tilt east
  for j in range(curr_map_len_j):
    j = curr_map_len_j - 1 - j
    for i in range(curr_map_len_i):
      if curr_map[i][j] == ".":
        for n_j in range(0, j):
          n_j = j - 1 - n_j
          if curr_map[i][n_j] == "O":
            curr_map[i][n_j] = "."
            curr_map[i][j] = "O"
            break
          if curr_map[i][n_j] == "#":
            break

for i in range(curr_map_len_i):
  for j in range(curr_map_len_j):
    if curr_map[i][j] == "O":
      final_sum += curr_map_len_i - i

print(final_sum)
