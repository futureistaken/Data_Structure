from Question import Question

question_promots = [
    "what color are apples?\n(a) red/green\n(b) purple\n(c) orange\n\n",
    "what color are bananas?\n(a) red\n(b) blue\n(c)Yellow\n\n",
    "what color are Strawbarries?\n(a) black\n(b) red\n(c)green\n\n",
]

questions = [
    Question(question_promots[0],"a"),
    Question(question_promots[1],"c"),
    Question(question_promots[2],"b")
]


def run_test(questions):
    score = 0
    for question in questions:
        answer = input(question.prompt)
        if answer == question.anwer:
            score +=1
    print("You got " + str(score) + "/" + str(len(questions)) + "correct")

run_test(questions)