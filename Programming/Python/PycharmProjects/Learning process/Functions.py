# void function
def say_hi(name,age):
    print("hello " + name + " your age is " + age)

name = input("Please enter your name : ")
age = input("Please enter your age : ")
say_hi(name,age)

# retuned item function
def cube (num):
    return pow(num,3)

print(cube(2))