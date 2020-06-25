import numpy as np
n = 8
a = np.array([[0] * n for i in range(n)])
a[3][2] = 334
print(a)