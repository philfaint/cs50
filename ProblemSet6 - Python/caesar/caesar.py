import sys
import cs50

def main():
    if len(sys.argv) != 2:
        print("Error")
        exit(1)

    print("plaintext: ", end="")
    plaintext = cs50.get_string()

    k = (int)(sys.argv[1])

    print("ciphertext: ", end="")

    for i in range(len(plaintext)):
        if str.isalpha(plaintext[i]):
            if str.isupper(plaintext[i]):
                print("{}".format(upper(plaintext[i], k)), end = "")
            elif str.islower(plaintext[i]):
                print("{}". format(lower(plaintext[i], k)), end = "")
        else:
            print("{}".format(plaintext[i]), end = "")

    print()

def upper(a, k):
    upper_ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    for i in range(26):
        if a == upper_ch[i]:
            ch_encrypt = upper_ch[(i+k) % 26]

    return ch_encrypt

def lower(a, k):
    lower_ch = "abcdefghijklmnopqrstuvwxyz"

    for i in range(26):
        if a == lower_ch[i]:
            ch_encrypt = lower_ch[(i+k) % 26]

    return ch_encrypt

if __name__ == "__main__":
    main()
