import numpy as np

if __name__ == '__main__':

    print("A")

    A = np.array([(2, -1), (5, 8)])

    print(A)

    print("Z_10")

    z10 = np.mod(A, 10)

    print(z10)

    print("Z_10^(-1)")

    z10_inverted = np.linalg.inv(z10)

    print(z10_inverted)

    print("Z_9")

    z9 = np.mod(A, 9)

    print(z9)

    print("Z_9^(-1)")

    z9_inverted = np.linalg.inv(z9)

    print(z9_inverted)
