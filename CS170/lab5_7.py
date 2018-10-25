TupleInt = eval(input("Enter a list of numbers, seperated by a comma and no space:"))
ListInt = []
sum = 0
for t in range(len(TupleInt)):
	sum+=TupleInt[t]
print(sum)