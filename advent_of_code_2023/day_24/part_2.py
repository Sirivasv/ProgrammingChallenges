import sys
import math

input_lines = [line.rstrip() for line in sys.stdin]

hailstones = []

for input_line in input_lines:
  hailstone_raw_split = input_line.split("@")

  hailstone_position = [ int(x.strip()) for x in hailstone_raw_split[0].split(",")]
  hailstone_velocities = [ int(x.strip()) for x in hailstone_raw_split[1].split(",")]
  
  hailstones.append([hailstone_position, hailstone_velocities])

def get_three_point_angle(p_1, p_2, p_3):
  a_2_1 = [p_2[0] - p_1[0], p_2[1] - p_1[1]]
  b_2_3 = [p_2[0] - p_3[0], p_2[1] - p_3[1]]
  
  mag_a = math.sqrt((math.pow(a_2_1[0], 2)) + (math.pow(a_2_1[1], 2)))
  mag_b = math.sqrt((math.pow(b_2_3[0], 2)) + (math.pow(b_2_3[1], 2)))

  middle_value = ((a_2_1[0] * b_2_3[0]) + (a_2_1[1] * b_2_3[1])) / (mag_a * mag_b)
  
  inner_angle_radians = math.acos(middle_value)
  inner_angle_degrees = math.degrees(inner_angle_radians)

  return inner_angle_degrees

def paths_intersect_in_test_area(hailstone_a, hailstone_b, ta_min=200000000000000.0, ta_max=400000000000000.0):
  # print(hailstone_a)
  # print(hailstone_b)
  ha_x = hailstone_a[0][0]
  ha_y = hailstone_a[0][1]

  na_x = ha_x + hailstone_a[1][0]
  na_y = ha_y + hailstone_a[1][1]
  
  hb_x = hailstone_b[0][0]
  hb_y = hailstone_b[0][1]

  nb_x = hb_x + hailstone_b[1][0]
  nb_y = hb_y + hailstone_b[1][1]

  inner_angle_na_ha_hb = get_three_point_angle([na_x, na_y], [ha_x, ha_y], [hb_x, hb_y])
  inner_angle_ha_hb_nb = get_three_point_angle([ha_x, ha_y], [hb_x, hb_y], [nb_x, nb_y])

  inner_angle_partial_sum = inner_angle_ha_hb_nb + inner_angle_na_ha_hb
  
  if inner_angle_partial_sum >= 180.0:
    return False
  
  sl_a = (na_y - ha_y) / (na_x - ha_x)
  sl_b = (nb_y - hb_y) / (nb_x - hb_x)

  if sl_a == sl_b:
    return False
  
  inter_x = -(((ha_y - (sl_a * ha_x)) - (hb_y - (sl_b * hb_x))) / (sl_a - sl_b))
  inter_y = ((sl_b * (ha_y - (sl_a * ha_x))) - (sl_a * (hb_y - (sl_b * hb_x)))) / (sl_b - sl_a)
  
  # print("x={}, y={}".format(inter_x, inter_y))

  time_a_inter_x = (inter_x - ha_x) / hailstone_a[1][0]
  if time_a_inter_x < 0:
    return False
  
  time_a_inter_y = (inter_y - ha_y) / hailstone_a[1][1]
  if time_a_inter_y < 0:
    return False

  time_b_inter_x = (inter_x - hb_x) / hailstone_b[1][0]
  if time_b_inter_x < 0:
    return False
  
  time_b_inter_y = (inter_y - hb_y) / hailstone_b[1][1]
  if time_b_inter_y < 0:
    return False

  if (inter_x >= ta_min) and (inter_x <= ta_max) and (inter_y >= ta_min) and (inter_y <= ta_max):
    return True
  return False

final_sum = 0
for hailstone_a_id in range(len(hailstones)):
  for hailstone_b_id in range(hailstone_a_id + 1, len(hailstones)):
    if paths_intersect_in_test_area(hailstones[hailstone_a_id], hailstones[hailstone_b_id]):
      final_sum += 1

print(final_sum)