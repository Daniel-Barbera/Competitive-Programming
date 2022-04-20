

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
    element = int(input())
    insert_element(list, element)
    write_list(list)

