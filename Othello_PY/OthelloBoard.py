import numpy as np
import sys


# オセロボードくん
# 白→1 黒→-1
class OthelloBoard:
    def __init__(self, n=8):
        self.n = n
        self.map = np.array([[0] * self.n for i in range(self.n)])
        # 最初の4個を配置
        ngo = int(self.n / 2)
        self.map[ngo - 1][ngo - 1] = 1
        self.map[ngo - 1][ngo] = -1
        self.map[ngo][ngo - 1] = -1
        self.map[ngo][ngo] = 1
    # End_Constructor
