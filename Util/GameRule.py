from abc import *

class GameRule:
	__metaclass__ = ABCMeta

	def __init__(self):
		self.board = None
		self.player_names = []
		self.player_scores = []

		print("GameRule is inherited!")
		return

	@abstractmethod
	def init_game(self):
		print("GameRule is initialized!")
		return 0

	@abstractmethod
	def turn(self):
		return 0

	@abstractmethod
	def calc_scores(self):
		return 0
