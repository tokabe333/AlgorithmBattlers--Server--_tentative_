import sys, os, json
import OthelloBoard as ob
sys.path.append(os.getcwd())
from Util import GameRule as ugr
from Util import Json as uj


class Othello(ugr.GameRule):
    def __init__(self, n, name1, name2):
        super().__init__()
        self.board = ob.OthelloBoard()
        self.player_names = [name1, name2]
        self.player_scores = [0] * 2


def main_othello():
    ot = Othello(6, "hotti", "naochin")
    ot.init_game()
    print(uj.DumpJson(ot))


if __name__ == "__main__":
    main_othello()
