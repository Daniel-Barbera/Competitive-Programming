

if __name__ == "__main__":
    numCasos = int(input())

    for i in range(numCasos):
        entrada = input().split()
        monedas_uno = int(entrada[0])
        monedas_dos = int(entrada[1])
        if (monedas_uno > 0 and monedas_dos == 0):
            print(monedas_uno + 1)
        elif (monedas_uno == 0 and monedas_dos > 0):
            print(1)
        else:
            print(monedas_dos*2 + monedas_uno + 1)
    