text = "Hello world!"

n = 2
list_a = list()
for i in range(len(text)):
    list_a.append(text[i:n+i])

print("{}".format(list_a))