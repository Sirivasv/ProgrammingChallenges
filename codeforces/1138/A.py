from sys import stdin

def solve(input_elements):
    input_len = len(input_elements)
    last_viewed_element = -1
    group_id = 0
    size_of_group = []
    for i in range(input_len):
        if i == 0:
            last_viewed_element = input_elements[i]
            size_of_group.append(1)
            continue
        if input_elements[i] == last_viewed_element:
            size_of_group[group_id] += 1
            continue
        last_viewed_element = input_elements[i]
        group_id += 1
        size_of_group.append(1)
    group_id = 0
    current_answer = 0
    for i in range(input_len):
        if i == 0:
            last_viewed_element = input_elements[i]
            continue
        if input_elements[i] == last_viewed_element:
            continue
        last_viewed_element = input_elements[i]
        group_id += 1
        current_answer = max(current_answer, min(size_of_group[group_id], size_of_group[group_id - 1]))
    return current_answer

items = list(map(lambda x: int(x), stdin.read().split()))
items.pop(0)
print(solve(items) * 2)
