from copy import copy


def get_longest_substring(string: str) -> str:
    longest_substring = ""
    substring = ""
    odd = False
    for i in range(len(string)):
        if i != 0 and bool(ord(string[i]) % 2) == odd:
            if len(substring) > len(longest_substring):
                longest_substring = copy(substring)
            substring = ""
        substring += string[i]
        odd = bool(ord(string[i]) % 2)
    if len(longest_substring) >= 2:
        return longest_substring


def test():
    print(get_longest_substring("225424272163254474441338664823"))
    # => "272163254"
    print(get_longest_substring("594127169973391692147228678476"))
    # => "16921472"
    print(get_longest_substring("721449827599186159274227324466"))
    # => "7214"
    print(get_longest_substring("122"))
    # => "12"
    print(get_longest_substring("11"))
    # => None
    print(get_longest_substring("1"))
    # => None
    print(get_longest_substring(""))
    # => None


def main():
    test()


if __name__ == "__main__":
    main()
