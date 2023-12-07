import sys
from functools import cmp_to_key

hands = []

card_values = {
  "J": 0,
  "2": 1,
  "3": 2,
  "4": 3,
  "5": 4,
  "6": 5,
  "7": 6,
  "8": 7,
  "9": 8,
  "T": 9,
  "Q": 11,
  "K": 12,
  "A": 13,
}

def get_hand_type(hand_cards):

  sets_of_cards = {}

  for card_value in hand_cards:
    if not card_value in sets_of_cards:
      sets_of_cards[card_value] = 0
    sets_of_cards[card_value] = sets_of_cards[card_value] + 1
  
  top_1_number = 0
  top_1_card = ""
  for card_set_card in sets_of_cards:
    if sets_of_cards[card_set_card] > top_1_number and (card_set_card != "J"):
      top_1_number = sets_of_cards[card_set_card]
      top_1_card = card_set_card

  if top_1_number == 5:
    return 7
  
  if "J" in sets_of_cards:
    top_1_number += sets_of_cards["J"]
    sets_of_cards["J"] = 0
  
  if top_1_number == 5:
    return 7

  top_2_number = 0
  top_2_card = ""
  for card_set_card in sets_of_cards:
    if (sets_of_cards[card_set_card] > top_2_number) and (card_set_card != top_1_card):
      top_2_number = sets_of_cards[card_set_card]
      top_2_card = card_set_card
  
  if top_1_number == 4:
    return 6

  if (top_1_number == 3) and (top_2_number == 2):
    return 5
  
  if (top_1_number == 3) and (top_2_number == 1):
    return 4

  if (top_1_number == 2) and (top_2_number == 2):
    return 3

  if (top_1_number == 2) and (top_2_number == 1):
    return 2
  
  return 1

def camel_cards_sorting(hand_1, hand_2):
  type_hand_1 = get_hand_type(hand_1["cards"])
  type_hand_2 = get_hand_type(hand_2["cards"])

  if (type_hand_1 > type_hand_2):
    return 1
  if (type_hand_2 > type_hand_1):
    return -1
  
  for card_id in range(len(hand_1["cards"])):
    card_value_1 = card_values[hand_1["cards"][card_id]]
    card_value_2 = card_values[hand_2["cards"][card_id]]

    if (card_value_1 > card_value_2):
      return 1
    if (card_value_2 > card_value_1):
      return -1 

  return 0


for line in sys.stdin:
  curr_line = line.rstrip()
  curr_line_split = curr_line.split(" ")
  hands.append({
    "cards": curr_line_split[0],
    "bid": int(curr_line_split[1])
  })

hands.sort(key=cmp_to_key(camel_cards_sorting))

final_sum = 0
for hand_id in range(0, len(hands)):
  final_sum = final_sum + ((hand_id + 1) * hands[hand_id]["bid"])

print(final_sum)