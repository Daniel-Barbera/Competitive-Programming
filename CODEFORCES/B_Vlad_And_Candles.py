

if __name__ == "__main__":
    numCasos = int(input())
    for k in range(numCasos):
        numVelas = int(input())
        velas = input().split()
        velas = [int(x) for x in velas]
        minimo = min(velas)
        maximo = max(velas)
        if (maximo - minimo) > 1:
            print("NO")
        else:
            print("YES")


print(*velas)
