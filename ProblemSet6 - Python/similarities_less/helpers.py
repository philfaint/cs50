# import module to divide a string into sentences
from nltk.tokenize import sent_tokenize

def lines(a, b):

    # split argument strings into a list of separate lines
    list_a = a.splitlines()
    list_b = b.splitlines()

    # remove all \n symbols from the list of string a
    k = list_a.count("")
    for i in range((len(list_a)-k)):
        if list_a[i] == '':
            list_a.pop(i)

    # remove all \n symbols from the list of string b
    k = list_b.count("")
    for i in range((len(list_b)-k)):
        if list_b[i] == '':
            list_b.pop(i)

    # create a new list of all identical lines in lists a and b
    list_c = set(list_a).intersection(list_b)

    #print("{}".format(list_c))
    return list_c


def sentences(a, b):

    # split argument strings into a sentences in a new lists
    list_a = sent_tokenize(a)
    list_b = sent_tokenize(b)

    # create a new list of all identical sentences in lists a and b
    list_c = set(list_a).intersection(list_b)
    return list_c


def substrings(a, b, n):

    list_a = list()

    for i in range(len(a)):
        if len(a) == n:
            list_a.append(a[i:n+i])
            break
        elif len(a) <= n:
            break
        elif len(a[i:n+i]) < n:
            break
        else:
            list_a.append(a[i:n+i])


    list_b = list()

    for i in range(len(b)):
        if len(b) == n:
            list_b.append(b[i:n+i])
            break
        elif len(b) <= n:
            break
        elif len(b[i:n+i]) < n:
            break
        else:
            list_b.append(b[i:n+i])

    print("{}".format(list_a))
    print("{}".format(list_b))

    list_c = set(list_a).intersection(list_b)
    return list_c
