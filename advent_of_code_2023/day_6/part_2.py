import sys

race_details = []
race_times = []
race_record_distances = []

for line in sys.stdin:
  curr_line = line.rstrip()
  curr_line_split = curr_line.split(":")
  race_details.append(curr_line_split[1].strip().split())

race_times = [int("".join(race_details[0]))]
race_record_distances = [int("".join(race_details[1]))]

final_mult = 1
for race_id in range(len(race_record_distances)):
  race_time = race_times[race_id]
  race_record_distance = race_record_distances[race_id]
  
  many_ways = 0
  for holding_milis in range(1, race_time):
    if ((race_time - holding_milis) * holding_milis) > race_record_distance:
      many_ways += 1
  final_mult = final_mult * many_ways

print(final_mult)