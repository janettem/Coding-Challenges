def stutter(str):
    return str[0] + str[1] + "... " + str[0] + str[1] + "... " + str + "?"


def test():
    print(stutter("incredible"))
    print(stutter("enthusiastic"))
    print(stutter("outstanding"))


test()
