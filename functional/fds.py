






def reduce(reducer, initial, list):
    acc = initial
    for item in list:
        acc = reducer(acc, item)
    return acc

add = lambda a, b: a + b
res = reduce(add, 0, [1, 2, 3])
print(res) # 6
res = reduce(add, 'T', "ommy")
print(res) # Tommy


def filter(pred, inputList):
    update = lambda list, curr: [*list, curr] if pred(curr) else list
    return reduce(update, [], inputList)

def build_filterer(pred):
    return lambda list: filter(pred, list)

non_empty_words = build_filterer(lambda word: len(word) != 0)
res = non_empty_words(["abc", "", "abcde"])
print(res) # ['abc', 'abcde']

capital_letters = build_filterer(lambda char: char.isupper())
res = capital_letters("Tommy")
print(res) # ['T']
