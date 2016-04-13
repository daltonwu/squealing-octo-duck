import time

val = [1, 1]

def timer(f):
    def inner(*arg):
        t0 = time.time()
        foo = f(*arg)
        t1 = time.time()
        print f.__name__ + str(arg) + ': ' + str(t0 - t1)
        return foo
    return inner


def remember(f):
    ''' memo-ization '''
    values = {}
    def inner(arg):
        if arg not in values:
            values[arg] = f(arg)
        return values[arg]
    return inner

@timer
def fib(n):
    global val
    while len(val) < n: val.append(val[-1] + val[-2])
    return val[n-1]

@timer
@remember
def fib2(n):
    return 1 if n <= 2 else fib(n-1) + fib(n-2)

print fib2(30)
