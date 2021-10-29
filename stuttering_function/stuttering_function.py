def stutter(str):
    return str[0] + str[1] + "... " + str[0] + str[1] + "... " + str + "?"


def test():
    print(stutter("incredible"))  # -> "in... in... incredible?"
    print(stutter("enthusiastic"))  # -> "en... en... enthusiastic?"
    print(stutter("outstanding"))  # -> "ou... ou... outstanding?"


test()
