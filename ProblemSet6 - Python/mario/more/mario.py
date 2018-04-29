import cs50

while True:
    print("Height: ", end="")
    h = cs50.get_int()
    if(h <= 23 and h >= 0):
        break

h2 = ((h * 2) + 3)

for i in range(h):
    for j in range(h2 - 1, 0, -1):
        if j == (int)(h2 / 2) or j == (int)((h2 / 2) +1):
            print(" ", end="")
        elif j <= ((h + 3) + i) and j >= (h-  i):
            print("#", end="")
        elif j >= ((h + 3) + i):
            print(" ", end="")
    print()
