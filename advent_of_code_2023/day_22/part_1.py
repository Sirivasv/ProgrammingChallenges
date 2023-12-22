import sys

input_lines = [line.rstrip().split("~") for line in sys.stdin]

bricks = []
for input_line in input_lines:
  brick_end_1 = [int(x) for x in input_line[0].split(",")]
  brick_end_2 = [int(x) for x in input_line[1].split(",")]
  brick_end_1.reverse()
  brick_end_2.reverse()
  brick_i = [brick_end_1, brick_end_2]
  bricks.append(brick_i)

bricks.sort()

global_min_i = bricks[0][0][2]
global_min_j = bricks[0][0][1]
global_min_z = bricks[0][0][0]

global_max_i = bricks[0][0][2]
global_max_j = bricks[0][0][1]
global_max_z = bricks[0][0][0]

for brick in bricks:
  global_min_i = min(global_min_i, brick[0][2])
  global_min_i = min(global_min_i, brick[1][2])

  global_min_j = min(global_min_j, brick[0][1])
  global_min_j = min(global_min_j, brick[1][1])

  global_min_z = min(global_min_z, brick[0][0])
  global_min_z = min(global_min_z, brick[1][0])

  global_max_i = max(global_max_i, brick[0][2])
  global_max_i = max(global_max_i, brick[1][2])

  global_max_j = max(global_max_j, brick[0][1])
  global_max_j = max(global_max_j, brick[1][1])

  global_max_z = max(global_max_z, brick[0][0])
  global_max_z = max(global_max_z, brick[1][0])

support_base = []
for pos_i in range(global_min_i, global_max_i + 1):
  support_base.append([])
  for pos_j in range(global_min_j, global_max_j + 1):
    support_base[pos_i].append([-1, 0])

will_support_alone = {}
for brick_id in range(len(bricks)):
  brick = bricks[brick_id]
  curr_min_i = min(brick[0][2], brick[1][2])
  curr_max_i = max(brick[0][2], brick[1][2])

  curr_min_j = min(brick[0][1], brick[1][1])
  curr_max_j = max(brick[0][1], brick[1][1])

  curr_min_z = min(brick[0][0], brick[1][0])
  curr_max_z = max(brick[0][0], brick[1][0])
  curr_height = curr_max_z - curr_min_z + 1
  
  max_height_support_bases = {}
  max_height = -1
  for pos_i in range(curr_min_i, curr_max_i + 1):
    for pos_j in range(curr_min_j, curr_max_j + 1):
      support_base_height = support_base[pos_i][pos_j][1]
      support_base_id = support_base[pos_i][pos_j][0]

      if support_base_height > max_height:
        max_height = support_base_height
        max_height_support_bases = {support_base_id: max_height}
      elif support_base_height == max_height:
        max_height_support_bases[support_base_id] = max_height

  # print(max_height_support_bases)
  if (max_height > 0) and (len(max_height_support_bases) == 1):
    for support_brick_id in max_height_support_bases:
      will_support_alone[support_brick_id] = 1
  
  for pos_i in range(curr_min_i, curr_max_i + 1):
    for pos_j in range(curr_min_j, curr_max_j + 1):
      curr_support_base_height = support_base[pos_i][pos_j][1]
      curr_support_base_id = support_base[pos_i][pos_j][0]
      support_base[pos_i][pos_j][0] = brick_id
      support_base[pos_i][pos_j][1] = max_height + curr_height

# print(will_support_alone)
final_sum = len(bricks)
for brick_id in range(len(bricks)):
  if brick_id in will_support_alone:
    final_sum -= 1
print(final_sum)
