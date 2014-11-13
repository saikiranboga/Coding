hash_map[0] = [-1]
prefix_sum = 0
for index in range(0..N-1):
  prefix_sum += array[index]
  start_list = hash_map[prefix_sum - K]
  for start_index in start_list:
    print start_index+1, index
  start_list2 = hash_map[prefix_sum]
  start_list2.append(index)
  
print start_list2
