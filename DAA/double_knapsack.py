import sys

INFINITE = 0xFFFFFFFF   # Constant for our algorithm

# Top down approach
def double_knapsack_backtracking(capacity_A, capacity_B, items, index, score):
    # Base cases
    if (capacity_A < 0 or capacity_B < 0):
        return -INFINITE
    elif ((capacity_A == 0 and capacity_B == 0) or index == len(items)):
        return score
    else:   # Transition
        return max(
                    # Put item in A
                    double_knapsack_backtracking(   
                        capacity_A - items[index], capacity_B, items, index + 1, score + items[index]
                    ),
                    # Put item in B
                    double_knapsack_backtracking(
                        capacity_A, capacity_B - items[index], items, index + 1, score + items[index]
                    ),
                    # Skip over item  
                    double_knapsack_backtracking(capacity_A, capacity_B, items, index + 1, score)
                )


def read_list(list_size):
    list = []
    _input = input().split(" ")
    for i in range(list_size):
        list += [int(_input[i])]
    return list


def main():
    sys.setrecursionlimit(10200)
    number_of_elements = int(input())
    list_of_items = read_list(number_of_elements)
    capacities = read_list(2)
    capacity_A = capacities[0]
    capacity_B = capacities[1]
    print(double_knapsack_backtracking(capacity_A, capacity_B, list_of_items, index = 0, score = 0))
    return


if __name__ == "__main__":
    main()