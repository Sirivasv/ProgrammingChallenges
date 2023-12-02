import sys

final_sum = 0
conf_red = 12
conf_green = 13
conf_blue = 14
for line in sys.stdin:
  curr_line = line.rstrip()
  curr_line_split = curr_line.split(":")
  curr_game_id = int(curr_line_split[0].split('Game ')[1])
  cube_draw_list = curr_line_split[1].split(";")
  max_red_cubes = 0
  max_blue_cubes = 0
  max_green_cubes = 0
  is_game_possible = True
  for cube_draw in cube_draw_list:
    cubes_in_draw_split = cube_draw.strip().split(',')
    for cube in cubes_in_draw_split:
        cube_split = cube.strip().split(' ')
        number_cubes = int(cube_split[0])
        cube_color = cube_split[1]
        if cube_color == "green" and number_cubes > max_green_cubes:
            max_green_cubes = number_cubes
        if cube_color == "red" and number_cubes > max_red_cubes:
            max_red_cubes = number_cubes
        if cube_color == "blue" and number_cubes > max_blue_cubes:
            max_blue_cubes = number_cubes
        if max_blue_cubes > conf_blue or max_green_cubes > conf_green or max_red_cubes > conf_red:
            is_game_possible = False
        if is_game_possible == False:
            break
    if is_game_possible == False:
        break
  if is_game_possible:
    final_sum = final_sum + curr_game_id
  
print(final_sum)