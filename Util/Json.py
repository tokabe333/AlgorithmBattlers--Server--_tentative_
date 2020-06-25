import json

def default_method(item):
	if isinstance(item, object) and hasattr(item, '__dict__'):
		return item.__dict__
	else:
		print(item)
		raise TypeError

def DumpJson(obj):
	return json.dumps(obj, default=default_method, indent=2)	


# # --------------いらないこ-------------

# class unchi:
# 	def __init__(self):
# 		self.unpi = "buryuryuryu"
# 		self.unpip = 114514
# 		self.unpipi = [1,1,4,5,1,4]
# 		self.unpipip = [[i * j for i in range(3)] for j in range(2)]
# 		#self.pipi = unpiii()
# 		print("333")

# class unpiii(unchi):
# 	def __init__(self):
# 		super().__init__()
# 		self.unnn = "unnn"

# 	def uncicici(self):
# 		self.unnn = "jfkdal"


# def main():
# 	u = unchi()
# 	uu = unpiii()
# 	uu.uncicici()
# 	print(DumpJson(uu))

# if __name__=="__main__":
# 	main()