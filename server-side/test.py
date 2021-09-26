import game

newGame = game.start()
print(newGame.p1Action("go to", "lower landing"))
print(newGame.p1Action("use", "lever"))
print(newGame.p1Action("go to", "entrance"))
print(newGame.p1Action("go to", "drawing room"))
print(newGame.p1Action("use", "lever"))
print(newGame.p1Action("use", "blah"))
print(newGame.p1Action("attack"))
print(newGame.p2Action("go to", "lower landing"))
print(newGame.p2Action("go to", "dining room"))
print(newGame.p2Action("attack"))
print(newGame.p2Action("go to", "drawing room"))
print(newGame.p2Action("attack"))


