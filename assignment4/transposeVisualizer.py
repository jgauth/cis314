import numpy as np

array2d = [[1, 2, 3, 4],
		   [5, 6, 7, 8],
		   [9, 10,11,12],
		   [13,14,15,16]]

def transpose(a):
	for i in range(0,4):
		for j in range(0,i):
			t = a[i][j]
			a[i][j] = a[j][i]
			a[j][i] = t	
			print(np.matrix(a))
			print("swapped {} and {}".format(a[i][j], a[j][i]))
			print("\n")


print(np.matrix(array2d))
print("\n")

# print(" ")
transpose(array2d)
# print(np.matrix(array2d))