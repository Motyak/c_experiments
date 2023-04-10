






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

def map(fn, list):
    reducer = lambda acc, item: [*acc, fn(item)]
    return reduce(reducer, [], list)

res = map(lambda x: 2*x, [1, 2, 3])
print(res) # [2, 4, 6]

def pipe(*functions):
    def inner(f, g):
        return lambda x: g(f(x)) # apply functions from left to right
    return reduce(inner, lambda x: x, functions)

incThenDouble = pipe(lambda x: x+1, lambda x: x*2)
res = incThenDouble(10)
print(res) # 22
