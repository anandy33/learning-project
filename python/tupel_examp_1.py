from copy import deepcopy

def main():
    tuples = ("hello", 5, [], True)
    tup_clone = deepcopy(tuples)

    clon = tuples
    clon[2].append(12)

    tup_clone[2].append(23)
    print(tup_clone)
    print(tuples)
    print(clon)

if __name__ == "__main__":
    main()
