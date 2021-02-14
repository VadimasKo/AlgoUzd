def bubbleSort (array):
    length = len(array)

    for i in range(length-1):
        for j in range(0, length-i-1):
            if array[j] > array[j+1] :
                array[j], array[j+1] = array[j+1], array[j]


array = [16,78,64,41,3,4,5,6,7]
bubbleSort(array)
string = "Sorted array is: "
for i in range(len(array)):
    string = string + str(array[i])  + " "

print (string)