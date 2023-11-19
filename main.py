from colorama import Fore, Style
from random import choice
from time import sleep

score = 10


class Bets:
    red = False
    black = False
    numbers = False
    firsttwelve = False
    secondtwelve = False
    thirdtwelve = False
    onetoeightteen = False
    nineteentothirtysix = False
    even = False
    odd = False


class Variablen:
    red = [1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36]
    black = [2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 33, 31, 35]
    numbers = list(range(37))
    firsttwelve = list(range(1, 13))
    secondtwelve = list(range(13, 25))
    thirdtwelve = list(range(1, 19))
    onetoeightteen = list(range(25, 37))
    nineteentothirtysix = list(range(19, 37))
    even = list(range(2, 37, 2))
    odd = list(range(1, 37, 2))


def bets():
    global score
    global bet
    global variable
    print(f"current score: {score}")
    variable = input(
        "set your bets\ntype a number for each number, min. 0 and max. 36. 1.12, 2.12 or 3.12 for the 12er groups, 1.18 for the first 18 or 19.36 for the last 18 or even and odd and black or red for the color\n>")
    try:
        bet = int(input("how much do you want to bet?\n>"))
        if bet > score:
            print("error, to much bet")
            return bets()
    except ValueError:
        print("false input")
        return bets()
    score = score - bet
    try:
        if int(variable) in Variablen.numbers:
            Bets.numbers = True
            return
    except:
        pass
    if variable == "red":
        Bets.red = True
    elif variable == "black":
        Bets.black = True
    elif variable == "1.12":
        Bets.firsttwelve = True
    elif variable == "2.12":
        Bets.secondtwelve = True
    elif variable == "3.12":
        Bets.thirdtwelve = True
    elif variable == "1.18":
        Bets.onetoeightteen = True
    elif variable == "19.36":
        Bets.nineteentothirtysix = True
    elif variable == "even":
        Bets.even = True
    elif variable == "odd":
        Bets.odd = True
    else:
        print("false input")
        score = score + bet
        bet = 0
        return bets()


def win_check():
    global number
    global score
    global bet
    global variable
    if Bets.red:
        Bets.red = False
        if number in Variablen.red:
            win()
        else:
            print("lose")
            bet = 0
    elif Bets.black:
        Bets.black = False
        if number in Variablen.black:
            win()
        else:
            print("lose")
            bet = 0
    elif Bets.firsttwelve:
        Bets.firsttwelve = False
        if number in Variablen.firsttwelve:
            win()
        else:
            print("lose")
            bet = 0
    elif Bets.secondtwelve:
        Bets.secondtwelve = False
        if number in Variablen.secondtwelve:
            win()
        else:
            print("lose")
            bet = 0
    elif Bets.thirdtwelve:
        Bets.thirdtwelve = False
        if number in Variablen.thirdtwelve:
            win()
        else:
            print("lose")
            bet = 0
    elif Bets.onetoeightteen:
        Bets.onetoeightteen = False
        if number in Variablen.onetoeightteen:
            win()
        else:
            print("lose")
            bet = 0
    elif Bets.nineteentothirtysix:
        Bets.nineteentothirtysix = False
        if number in Variablen.nineteentothirtysix:
            win()
        else:
            print("lose")
            bet = 0
    elif Bets.even:
        Bets.even = False
        if number in Variablen.even:
            win()
        else:
            print("lose")
            bet = 0
    elif Bets.odd:
        Bets.odd = False
        if number in Variablen.odd:
            win()
        else:
            print("lose")
            bet = 0
    elif Bets.numbers:
        Bets.numbers = False
        if number == int(variable):
            win()
        else:
            print("lose")
            bet = 0
    else:
        exit("critical error")


def animation():
    print("roulette is starting")
    sleep(1.5)
    print("almost done")
    sleep(1.5)


def spin():
    global number
    animation()
    number = choice(Variablen.numbers)
    if number in Variablen.red:
        print(Fore.RED + str(number))
    elif number in Variablen.black:
        print(Fore.BLACK + str(number))
    print(Style.RESET_ALL)


def win():
    global score
    global bet
    print(Fore.GREEN + "win")
    print(Style.RESET_ALL)
    score = score + bet + bet
    bet = 0
    print(f"current score: {score}")


def again():
    input_again = input("do you want to play again? [y/n]\n>")
    if input_again == "y":
        pass
    elif input_again == "n":
        print("good bye")
        exit()
    else:
        print("error, false input")
        return again()


if __name__ == "__main__":
    while score > 0:
        bets()
        spin()
        win_check()
        if score > 0:
            again()
    print("you don't have any money left")
