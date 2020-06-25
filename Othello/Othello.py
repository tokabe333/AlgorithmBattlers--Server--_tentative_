import sys, os, json
sys.path.append(os.getcwd())
from Util import GameRule as ugr
from Util import Json as uj

class Othello(ugr.GameRule):
	def __init__(self):
		super().__init__()

ot = Othello()
ot.init_game()

print(uj.DumpJson(ot))