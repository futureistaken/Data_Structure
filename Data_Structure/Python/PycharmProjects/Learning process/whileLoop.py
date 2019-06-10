secret_word = "leo"
guess = ""
guess_counter = 0
while guess_counter < 3 :
    guess = input("guess the word : ")
    guess_counter +=1
    if secret_word == guess:
        guess_counter = -1
        break

if  guess_counter == -1:
    print("congrats the word was leo ")
else:
    print("Sry, you lost")