import cs50

def main():
    cc_number = enterNumber()
    cc_figures = ccFigures(cc_number)
    sum = ccSum(cc_number, cc_figures)
    firstdigits = firstDigits(cc_number, cc_figures)
    result(sum, firstdigits)

def enterNumber():
    while True:
        print("Number: ")
        a = cs50.get_int()
        if a > 1:
            break
    return a

def ccFigures(cc_number):
    a = 0

    while cc_number != 0:
        cc_number = (int)(cc_number/10)
        a += 1

    return a

def ccSum(cc_number, cc_figures):
    temp = cc_number
    sum = 0
    k = 0
    j = 0

    for i in range(cc_figures):
        j = temp % 10
        temp = (int)(temp / 10)
        sum += j

        k = (temp % 10) * 2
        temp = (int)(temp / 10)
        if k >= 10:
            sum = sum + (k % 10)
            k = (int)(k / 10)
        sum += k

    return sum

def firstDigits(cc_number, cc_figures):
    a = 0

    if cc_figures == 13:
        a = (int)(cc_number/100000000000)
    elif cc_figures == 15:
        a = (int)(cc_number/10000000000000)
    elif cc_figures == 16:
        a = (int)(cc_number/100000000000000)

    return a

def result(sum, firstdigits):
    if (sum%10)==0 and (firstdigits==34 or firstdigits == 37):
        print("AMEX\n")
    elif (sum%10)==0 and (firstdigits==51 or firstdigits == 52 or firstdigits == 53 or firstdigits == 54 or firstdigits == 55):
        print("MASTERCARD\n")
    elif (sum%10)==0 and (((int)(firstdigits/10)) == 4):
        print("VISA\n")
    else:
        print("INVALID\n")

if __name__ == "__main__":
    main()


