
### Reference: Figure 4.8 @ Introduction to Recursive Programming
def insertion_sort(unsorted_sublist, sorted_sublist): 
    if unsorted_sublist == []:
        return sorted_sublist
    else:
        element = unsorted_sublist.pop()
        sorted_sublist = insert_element(sorted_sublist, element)
        return insertion_sort(unsorted_sublist, sorted_sublist)


def insert_element(list, element):
    if list == [] or list[-1] < element:
        list.append(element)
        return list
    else:
        tail = list.pop()
        list = insert_element(list, element)
        list.append(tail)
        return list


def read_list(list_size):
    list = []
    _input = input().split(" ")
    for i in range(list_size):
        list += [int(_input[i])]
    return list


def write_list(list):
    print(*list, sep = " ")
    return


if __name__ == "__main__":
    list_size = int(input())
    list = read_list(list_size)
    list = insertion_sort(unsorted_sublist = list, sorted_sublist = [])
    write_list(list)