import cs50

while True:
    print("Height: ", end="")
    h = cs50.get_int()
    if(h <= 23 and h >= 0):
        break

for k in range(1, h + 1):
    for j in range(h, -1, -1):
        if j <= k:
            print("#", end="")
        else:
            print(" ", end="")
    print()
