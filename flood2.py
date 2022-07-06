class Node:
	def __init__(self, x):
		self.data = x
		self.link = None


head = None


def Loop(head):
	sPoint = head
	fPoint = head

	while (sPoint != None
		and fPoint != None
		and fPoint.link != None):
		sPoint = sPoint.link
		fPoint = fPoint.link.link
		if (sPoint == fPoint):
			return 1

	return 0


head = Node(10)
head.link = Node(1)
head.link.link = Node(2)
head.link.link.link = Node(3)
head.link.link.link.link = Node(4)
head.link.link.link.link.link = Node(5)


temp = head
while (temp.link != None):
	temp = temp.link

temp.link = head


if (Loop(head)):
	print("Loop exists")
else:
	print("Loop does not exist")

