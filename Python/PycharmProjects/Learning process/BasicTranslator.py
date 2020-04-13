# dog translator wherever there is a volws we replace it with wuff
'''
# multiple comment line
sdfsdfsdf
sdfsdfsdf
sfsdfff
'''
def translate(phrase):
    tranlation  = ""
    for letter in phrase:
        if letter.lower() in "aeiou": # lower case all the letters and search
            if letter.isupper():
                tranlation = tranlation + "Wuff"
            else:
                tranlation = tranlation + "wuff"
        else:
            tranlation = tranlation + letter
    return tranlation
print(translate(input("Enter a phrase : ")))