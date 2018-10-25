import sys

def xor(c1,c2):
	return_string = ""
	for idx, c in enumerate(c1):
		if c == c2[idx]:
			return_string+= "0"
		else:
			return_string+= "1"
	return return_string

def rotate(s, n):
	return s[n:] + s[:n]
	
def permute(s, order):
	return_string = ""
	for idx in order:
		return_string+=s[idx]
	return return_string

class SDES:
	def __init__(self, key):
		self.key = key
		temp_key = permute(key, [2,4,1,6,3,9,0,8,7,5])
		temp_key = rotate(temp_key[:5], 1) + rotate(temp_key[5:], 1)
		self.k1 = permute(temp_key, [5,2,6,3,7,4,9,8])
		#print("Key 1:",  self.)
		temp_key = rotate(temp_key[:5], 2) + rotate(temp_key[5:], 2)
		self.k2 = permute(temp_key, [5,2,6,3,7,4,9,8])
		#print("Key 2:",  self.k2)

	def encrypt(self, msg):
		IP = [1,5,2,0,3,7,4,6]
		IP_INVERSE = [3,0,2,4,6,1,7,5]
		msg = permute(msg, IP)
		#print("IP: ", msg)
		msg = SDES.f_k(msg[:4], msg[4:], self.k1)
		#print("FK: ", msg)
		msg = msg[4:] + msg[:4]
		#print("SWAP: ", msg)
		msg = SDES.f_k(msg[:4], msg[4:],self.k2)
		#print("FK: ", msg)
		msg = permute(msg, IP_INVERSE)
		#print("IP-1: ", msg)
		return msg
		
	def f_k(L, R, key):
		def f(R, key):
			S0 = [[1,0,3,2],[3,2,1,0],[0,2,1,3],[3,1,3,2]]
			S1 = [[0,1,2,3],[2,0,1,3],[3,0,1,0],[2,1,0,3]]
			EP = permute(R, [3,0,1,2,1,2,3,0])
			EP = xor(EP, key)
			#print("SBOX1 Co-ords = {0},{1}".format(int(EP[0]+EP[3],2),int(EP[1]+EP[2],2)))
			SBOX1 = "{0:02b}".format(S0[int(EP[0]+EP[3],2)][int(EP[1]+EP[2],2)])
			#print("SBOX 1:", SBOX1)
			#print("SBOX2 Co-ords = {0},{1}".format(int(EP[4]+EP[7],2),int(EP[5]+EP[6],2)))
			SBOX2 = "{0:02b}".format(S1[int(EP[4]+EP[7],2)][int(EP[5]+EP[6],2)])
			#print("SBOX 2:", SBOX2)
			return permute(SBOX1+SBOX2,[1,3,2,0])
		return xor(L, f(R,key))+R
		
	def decrypt(self, ciphertext):
		IP = [1,5,2,0,3,7,4,6]
		IP_INVERSE = [3,0,2,4,6,1,7,5]
		msg = ciphertext
		msg = permute(msg, IP)
		#print("IP: ", msg)
		msg = SDES.f_k(msg[:4], msg[4:], self.k2)
		#print("FK: ", msg)
		msg = msg[4:] + msg[:4]
		#print("SWAP: ", msg)
		msg = SDES.f_k(msg[:4], msg[4:],self.k1)
		#print("FK: ", msg)
		msg = permute(msg, IP_INVERSE)
		#print("IP-1: ", msg)
		return msg

for test_case in range(int(sys.stdin.readline())):
	line = sys.stdin.readline().split()
	encryptor = SDES(line[1])
	ciphertext = encryptor.encrypt(line[0])
	print("ENCRYPTION: ")
	print("Key: {0}, Msg: {1}, Ciphertext: {2}".format(line[1], line[0],ciphertext))
	print("DECRYPTION: ")
	print("Key: {0}, Ciphertext: {1}, Msg: {2}".format(line[1], ciphertext,encryptor.decrypt(ciphertext)))

