import sys

def rotate(l, n): #Args: l = list, n=number
    return l[n:] + l[:n]

def toyTetragraphHash(msg):
	msg = msg.replace(" ","") #Remove spaces and punctuation
	msg = msg.replace(".", "")
	msg = msg.replace("?", "")
	msg = msg.replace("!","")
	msg = msg.replace("\n","")
	msg = msg.lower() #convert to lowercase
	while len(msg)%16!=0:
		msg+="a" #pad message with null char (a)
		 
	blocks = [[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]] for x in range(len(msg)//16)] #Initialize each block to 4x4 matrix of zeros
	charMap = {chr(x+97):x for x in range(26)} #Dictionary lookup builder
	for charIdx in range(len(msg)):
		blockIdx = charIdx//16 #Block number is floor of charIdx / 16
		rowIdx = charIdx%16//4 #Character in block is idx%16, 4 rows and row idx is floor of charIdx / 4
		colIdx = charIdx%4     #4 columns, colIdx is charIdx mod 4
		blocks[blockIdx][rowIdx][colIdx] = charMap[msg[charIdx]]
	
	RunningTotal = [0,0,0,0]
	for block in blocks:
		#Phase 1
		for i in range(4):
			for j in range(4): 
				RunningTotal[i]+=block[j][i] #Add each row in column j
			RunningTotal[i]%=26 #Mod 26
		#Phase 2
		ShiftedBlock = [rotate(block[0],1),rotate(block[1],2),rotate(block[2],3),list(reversed(block[3]))]
		for i in range(4):
			for j in range(4):
				RunningTotal[i]+=ShiftedBlock[j][i]
			RunningTotal[i]%=26
	charMapReverse = {x:chr(x+97) for x in range(26)} #Dictionary lookup builder
	return ((''.join([charMapReverse[RunningTotal[i]] for i in range(4)])).upper())
			
			
for i in sys.stdin.readlines():
	print(toyTetragraphHash(i))