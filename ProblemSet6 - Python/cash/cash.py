import cs50

counter = 0

while True:
    print("How much change is owed?")
    money = cs50.get_float()
    if money > 0.0:
        break

money*=100
cents = round(money)

while cents>=25:
    cents -= 25
    counter += 1

while cents >= 10:
    cents -= 10
    counter += 1

while cents >= 5:
    cents -=5
    counter += 1

while cents>= 1:
    cents -= 1
    counter += 1

print("{}".format(counter))

