

try:
    value = 10 / 0
    number = int(input("Enter a number : "))
    input(number)
except ZeroDivisionError as err:
    print(err)
except ValueError:
    print("invalid input")