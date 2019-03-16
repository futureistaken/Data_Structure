friends = ["kevin","Karen","Karen","Karen","Babak","haha","Jim","lura"]
lucy_numbers = [4,8,15,6,23,42]
friends[5] = "mary"
print(friends)
print(lucy_numbers)
friends.append("Sirus") # add an element to the end of the list
friends.remove("Sirus")
friends.insert(1,"Sirus")
friends.pop() # remove the last elemet
# friends.clear() remove all the elements
friends.extend(lucy_numbers)
print(friends)
# Find the index element of the element - ** if elemment is not the if generates a ValueError
print(friends.index("Babak"))
# count the number of time that it sees the element on the list
print(friends.count("Karen"))
# sorting in alphabetical order
lucy_numbers.reverse() # reverse the order
lucy_numbers.sort(reverse=True) # sort the element from low to hight (defualt)
print(lucy_numbers)
friends_Copy = friends.copy()
print(friends_Copy)