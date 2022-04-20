import sys


def is_odd(a):
    return a % 2 != 0


def is_even(a):
    return not is_odd(a)


def is_preceded_by(a, b):
    if (is_even(a) and is_even(b)) or (is_odd(a) and is_odd(b)):
        return a <= b
    elif is_even(a):
        return False
    else:
        return True


def merge(left_half, right_half):
    if left_half == []:
        return right_half
    elif right_half == []:
        return left_half
    elif is_preceded_by(left_half[0], right_half[0]):
        return [left_half[0]] + merge(left_half[1:], right_half)
    else:
        return [right_half[0]] + merge(right_half[1:], left_half)


def merge_sort(list):
    list_length = len(list)
    if list_length <= 1:
        return list
    else:
        left_half = merge_sort(list[ : list_length // 2])
        right_half = merge_sort(list[list_length // 2: ])
        return merge(left_half, right_half)


def read_list(list_size):
    list = []
    _input = input().split(" ")
    for i in range(list_size):
        list += [int(_input[i])]
    return list
 

def write_list(list):
    print(*list, sep = " ")
    return


def main():
    sys.setrecursionlimit(10200)
    list_size = int(input())
    list = read_list(list_size)
    list = merge_sort(list)
    write_list(list)
    

if __name__ == "__main__":
    main()