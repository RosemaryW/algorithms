from time import sleep
from random import seed, randrange
import pyautogui as g
import sys

if (len(sys.argv) != 2):
    print("please specify the number of games you want as a cli arg")
    quit()

#accept a counter
num_games = int(sys.argv[1])
print(f"auto play {num_games} games in 5 seconds")

seed()
sleep(5)

for _ in range(0, num_games):
    # blue "start game" button
    g.click(x=randrange(1200, 1366), y=randrange(820, 844))
    sleep(randrange(3, 8))

    # red "start game" button
    g.click(x=randrange(1205, 1269), y=randrange(513, 709))
    sleep(randrange(120, 140)) # each game takes approximately 1 min 30 sec

    # game done screen
    g.click(x=randrange(192, 1254), y=randrange(128, 466))
    sleep(randrange(3, 10))