import numpy as np
import argparse as arg
    
def generate_array(size1):
	array = np.random.randint(2,size = (size1,size1))
	#array = np.zeros((size, size), dtype="uint8")
	#print "generate array!"
	return array

def print_array(array):
	print "array.{}".format(array)

def find_largest_1_matrix(array):
	size = array.shape
	max_square = 0 
	dp = np.zeros(size, dtype="uint8")
	#print "dp - {}".format(dp)		
	row = size[0]
	column = size[1]
	for i in xrange(row):
		for j in xrange(column):
			#print "value - {} \n".format(array[i,j])
			if (array[i,j] == 1):
				dp[i,j] = min(dp[i,j-1], dp[i-1,j], dp[i-1,j-1]) + 1
				max_square = max(dp[i,j], max_square)         
	return max_square

if __name__ == "__main__":
	ap = arg.ArgumentParser()
	ap.add_argument("-s", "--size", required=True, help="array size")		
	args = vars(ap.parse_args())
	print "array - {}, type - {}".format(args["size"], type(args["size"]))	
	array = generate_array(int(args["size"]))
	print_array(array)
	print "max square - {}".format(find_largest_1_matrix(array))	
	#print "Hello World!"
