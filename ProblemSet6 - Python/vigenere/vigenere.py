import cs50
import sys

def main():
    if len(sys.argv) <= 1 or len(sys.argv) > 2:
        exit(1)

    if key_check(sys.argv[1]) == 0:
        exit(1)

    print("plaintext: ", end="")
    plaintext = cs50.get_string()
    print("ciphertext: ", end="")

    m = 0

    for i in range(len(plaintext)):
        if plaintext[i] != ' ' and str.isalpha(plaintext[i]):
            k = key(sys.argv[1], m)
            m += 1

            if str.isupper(plaintext[i]):
                print("{}".format(crypt_upper(plaintext[i], k)), end="")
            elif str.islower(plaintext[i]):
                print("{}".format(crypt_lower(plaintext[i], k)), end="")
        else:
            print("{}".format(plaintext[i]), end="")

    print()

def key_check(key):
    for i in range(len(key)):
        if not str.isalpha(key[i]):
            return 0

    return 1

def key(key, number):

    key_num = number % len(key)
    alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    k = 0

    key2 = key.upper()
    #print("{}".format(key))

    for i in range(26):
        if alpha[i] == key2[key_num]:
            k = i

    return k

def crypt_upper(c, k):
    alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    for i in range(26):
        if c == alpha[i]:
            crypt_char = alpha[(i+k) % 26]

    return crypt_char

def crypt_lower(c, k):
    alpha = "abcdefghijklmnopqrstuvwxyz"

    for i in range(26):
        if c == alpha[i]:
            crypt_char = alpha[(i+k) % 26]

    return crypt_char

if __name__ == "__main__":
    main()