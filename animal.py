import sys
def default():
    print('hello')

def dog():
    print('Woof!wangwang!')

def main():
    if sys.argv[1] == 'dog':
        dog()
    else:
        default()
if __name__ == '__main__':
    main()
