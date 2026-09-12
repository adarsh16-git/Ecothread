import numpy as np

def gram_schmidt(A):
    U = []
    Q = []

    for v in A:
        u = v.copy()

        for q in Q:
            u = u - np.dot(v, q) * q

        U.append(u)

        q = u / np.linalg.norm(u)
        Q.append(q)

    return np.array(U), np.array(Q)


A = np.array([
    [1, 1, 1, 1],
    [1, 2, 4, 5],
    [1, -3, -4, -2]
], dtype=float)

U, Q = gram_schmidt(A)

print("Orthogonal vectors:\n")
for i, vec in enumerate(U, start=1):
    print(f"u_{i} = {vec}\n")

print("Orthonormal vectors:\n")
for i, vec in enumerate(Q, start=1):
    print(f"û_{i} = {vec}\n")