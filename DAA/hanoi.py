

def solve_hanoi(disk, source, auxiliary, destination):
    if disk == 0:
        return
    else:
        solve_hanoi(disk - 1, source, auxiliary, destination)
        print_movement(disk, source, auxiliary)
        solve_hanoi(disk - 1, destination, auxiliary, source)
        print_movement(disk, auxiliary, destination)
        solve_hanoi(disk - 1, source, auxiliary, destination)
        return


def print_movement(disk, source, destination):
    print(f'Mueve disco {disk} desde torre {source} a torre {destination}')
    return


if __name__ == "__main__":
    num_disks = int(input())
    solve_hanoi(num_disks, source = 1, auxiliary = 2, destination = 3)

