import random


def select_random_distinct_numbers(k, start_range, end_range):
    numbers = list(range(start_range, end_range))
    random.shuffle(numbers)
    res = numbers[:k]
    return res
