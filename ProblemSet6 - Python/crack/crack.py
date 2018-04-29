import crypt
import sys

def main():
    if len(sys.argv) <= 1 or len(sys.argv) > 2:
        print("Usage: ./crack hash")
        exit(1)

    hash = sys.argv[1]
    alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

    for i in range(len(alpha)):
        pass_one = alpha[i]
        hash_test = hash_gen(pass_one, "50")
        if hash == hash_test:
            print("{}".format(pass_one))
            exit(0)

    for i in range(len(alpha)):
        pass_two = alpha[i]
        for j in range(len(alpha)):
            pass_two2 = pass_two + alpha[j]
            hash_test = hash_gen(pass_two2, "50")
            if hash == hash_test:
                print("{}".format(pass_two2))
                exit(0)

    for i in range(len(alpha)):
        pass_three = alpha[i]
        for j in range(len(alpha)):
            pass_three2 = pass_three + alpha[j]
            for k in range(len(alpha)):
                pass_three3 = pass_three2 + alpha[k]
                hash_test = hash_gen(pass_three3, "50")
                if hash == hash_test:
                    print("{}".format(pass_three3))
                    exit(0)

    for i in range(len(alpha)):
        pass_four = alpha[i]
        for j in range(len(alpha)):
            pass_four2 = pass_four + alpha[j]
            for k in range(len(alpha)):
                pass_four3 = pass_four2 + alpha[k]
                for m in range(len(alpha)):
                    pass_four4 = pass_four3 + alpha[m]
                    hash_test = hash_gen(pass_four4, "50")
                    if hash == hash_test:
                        print("{}".format(pass_four4))
                        exit(0)

    for i in range(len(alpha)):
        pass_five = alpha[i]
        for j in range(len(alpha)):
            pass_five2 = pass_five + alpha[j]
            for k in range(len(alpha)):
                pass_five3 = pass_five2 + alpha[k]
                for m in range(len(alpha)):
                    pass_five4 = pass_five3 + alpha[m]
                    for l in range(len(alpha)):
                        pass_five5 = pass_five4 + alpha[l]
                        hash_test = hash_gen(pass_four4, "50")
                        if hash == hash_test:
                            print("{}".format(pass_four4))
                            exit(0)

def hash_gen(password, salt):
    return crypt.crypt(password, salt)

if __name__ == "__main__":
    main()