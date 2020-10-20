import numpy as np


if __name__ == '__main__':
    '''
    sub-task a
    '''

    print("a)")

    z12 = np.zeros((11, 11))

    for x in range(11):
        for y in range(11):
            z12[x][y] = ((x+1) * (y+1)) % 12

    print(z12)

    print("b)")

    for x in range(11):
        for y in range(11):
            if z12[x][y] == 1:
                print(f'{x+1} has a multiplicative inverse with mod 12')
