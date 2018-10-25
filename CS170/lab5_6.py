TupleInt = eval(input("Enter a list of numbers, seperated by a comma and no space:"))
ListInt = []
for t in range(len(TupleInt)):
	ListInt.append(TupleInt[t]**2)
print(ListInt)