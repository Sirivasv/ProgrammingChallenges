import sys

final_sum = 0
cards_setup = []
cards_per_copy = {}

card_id = 0
for line in sys.stdin:
  curr_line = line.rstrip()
  curr_line_split = curr_line.split(":")
  number_parts_split = curr_line_split[1].split("|")
  winning_numbers = number_parts_split[0].strip().split()
  numbers_you_have = number_parts_split[1].strip().split()
  cards_setup.append([winning_numbers, numbers_you_have])

card_id = len(cards_setup) - 1
cards_setup.reverse()
for reverse_line in cards_setup:
  winning_numbers = reverse_line[0]
  numbers_you_have = reverse_line[1]
  
  cards_per_copy[card_id] = 1
  
  current_streak = 1
  for number_you_have in numbers_you_have:
    if number_you_have in winning_numbers:
      cards_per_copy[card_id] = cards_per_copy[card_id] + cards_per_copy[card_id + current_streak]
      current_streak += 1
  final_sum += cards_per_copy[card_id]
  card_id -= 1
print(final_sum)
