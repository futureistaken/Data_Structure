input_file = open("input.txt","r")
# if the file is readable  true else false!
# print(input_file.readable())

# read the whole file  - if .read() is being called the readline won't print anyting but an empty line
print(input_file.read())

# read all the lines and convert all of them in to an array
# print(input_file.readlines()[1]) access to the second element of the file ' index starts from 0

# print all the lines in input array file
# for input in input_file.readlines():
    #print(input)

# read an individual line
#print(input_file.readline())

'''
different modes: r = read
                 w = write
                 a = add to the end of the file
                 r+ = read and write
'''
input_file.close()

# add a new friend to the input
input_file = open("input.txt","a")
input_file.write("\nHarry")
input_file.close()

# creating a new file name input1.txt with one input - kelly
input_file = open("input1.txt","w")
input_file.write("Kelly")
input_file.close()