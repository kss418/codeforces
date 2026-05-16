mod = 1000000007
t = int(input())
for i in range(t):
    n = int(input())
    first = n * (n + 1)
    second = 2 * n + 1
    if(first % 3 == 0):
        first //= 3

    else:
        second //= 3

    third = ((first % mod) * (second % mod)) % mod
    fourth = n
    fifth = n + 1
    if(fourth % 2 == 0):
        fourth //= 2
    else:
        fifth //= 2
    sixth = (fourth % mod * fifth % mod) % mod
    cur = third - sixth
    print((2022 * cur)  % mod)
