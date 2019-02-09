
def main():
    num = {'z' : [2, 3, 5], 'b' : [3, 1, 2], 'c' : [3, 2, 4]}

    sorted_dict = {x : sorted(y) for x, y in num.items()}

    print(sorted_dict)



if __name__ == "__main__":
    main()
