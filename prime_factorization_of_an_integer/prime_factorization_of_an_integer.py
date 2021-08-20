def get_prime_factors(num: int) -> list:
    prime_factors = []
    prime_factor = 2
    while num > 1:
        if num % prime_factor == 0:
            prime_factors.append(prime_factor)
            num /= prime_factor
        else:
            prime_factor += 1
    return prime_factors


def test():
    print(get_prime_factors(20)) # => [2, 2, 5]
    print(get_prime_factors(100)) # => [2, 2, 5, 5]
    print(get_prime_factors(8912234)) # => [2, 47, 94811]
    print(get_prime_factors(169)) # => [13, 13]
    print(get_prime_factors(12)) # => [2, 2, 3]
    print(get_prime_factors(35)) # => [5, 7]


def main():
    test()


if __name__ == "__main__":
    main()
