from abc import *

class GameRule:
	def __init__(self):
		self.ngo = "334"
		return

	@abstractmethod
	def init_game(self):
		return 0

	def turn(self):
		return 0

	def calc_scores(self):
		return 0

