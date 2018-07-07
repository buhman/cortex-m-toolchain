from itertools import product

stty = [
    4800,
    9600,
    19200,
    38400,
    57600,
    115200,
    230400,
    460800,
    921600,
]

div = range(0, 14 + 1)
mul = range(1, 15 + 1)

restrict = lambda dm: dm[0] < dm[1]

fraction = list(filter(restrict, product(div, mul)))

print("<clock> <baud> [error, actual, [divisor, (fraction)]]")

for clock in [12000000, 180000000, 204000000]:
    for target in stty:

        rank = []

        for div, mul in fraction:
            dl = (clock) / ((target * 16) * (1 + (div/mul)))

            for dli in [int(dl), int(dl) + 1]:
                if dli <= 0:
                    # too fast
                    continue

                actual = (clock) / ((dli * 16) * (1 + (div/mul)))

                error = abs((actual - target) / (target))
                if error < 0.02:
                    rank.append([error, actual, [dli, (div, mul)]])

        rank = sorted(rank, key=lambda i: i[0])

        print(clock, target, rank[0] if rank else "<impossible>")
