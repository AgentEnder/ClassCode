#Custom Input Module
#Written by Craigory Coppola
#Last updated on November 3,2016
import sys
DEFAULT_NUM = "Please enter a number: "
DEFAULT_LIST_INT = "Please enter a list of integers seperated by commas: "
def getInt(min_value = 0, max_value = False, prompt = DEFAULT_NUM): #min_value defaults to 0, max is not required
	while True: #continue asking until an integer is given
		try:
			x = int(input(prompt + ' '))
			if(max_value != False):
				if x>max_value: #Check against max_value
					raise ValueError('')
			if x < min_value:
				raise ValueError(''); #Check against min_value
			break
		except ValueError: #Catch any value errors
			if(max_value != False):
				print("Please give an integer betweeen %d and %d!" %(min_value,max_value))
			else:
				print("Please give an integer greater than %d!" %(min_value))
	return x
def getListNum(prompt = DEFAULT_LIST_INT):
	string_x = input(prompt)
	list_string = string_x.split(",")
	ListInt = []
	for t in range(len(list_string)):
		ListInt.append(int(list_string[t]))
	return ListInt
def getFloat(min_value = 0, max_value = False, prompt = DEFAULT_NUM):
	while True: #continue asking until a valid value is given
		try:
			x = float(input(prompt + ' '))
			if(max_value != False):
				if x>max_value: #Check against max_value
					raise ValueError('')
			if x < min_value:
				raise ValueError(''); #Check against min_value
			break
		except ValueError:
			if(max_value != False):
				print("Please give a number betweeen %d and %d!" %(min_value,max_value))
			else:
				print("Please give a number greater than %d!" %(min_value))
	return x
def getString(prompt="Input a string:"):
	x = input(prompt + " ")
	if x == "exit":
		sys.exit()
	else:
		return x
def getChar(prompt="Input a string:"):
	x = input(prompt + " ")
	if x == "exit":
		sys.exit()
	else:
		return x[0]