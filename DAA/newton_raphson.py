

def sqrt_newton_raphson(approximation, radicand):
    epsilon = 10 ** (-6)
    f_x = approximation**2 - radicand
    first_order_derivative = 2*approximation
    
    if (abs(f_x) < epsilon):
        return approximation
    else:
        next_iteration = approximation - f_x/first_order_derivative
        approximation = sqrt_newton_raphson(next_iteration, radicand)
        return approximation


def write_result(output):
    output = '{0:.4f}'.format(output)
    print(output)
    return


if __name__ == "__main__":
    radicand = float(input())
    root = sqrt_newton_raphson(approximation = radicand, radicand = radicand)
    write_result(root)

