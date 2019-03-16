print(2**3)

def raise_to_power(baseNum,powNum):
    result = 1
    for index in range(powNum):
        result = result*baseNum
    return result
print(raise_to_power(2,3))