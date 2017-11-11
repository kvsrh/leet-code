import argparse

exchange = 50
coins = [1,2,5]

def coin_exchange(exchange, coins):
    if  (exchange <= 0):
        return 
    for coin in coins:
        coin_exchange(exchange - coin, coins)

if "__name__" == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("-e",
                    "--exchange",
                    required=True,
                    help="coin exchange amount")
    ap.add_argument("-c",
                    "--coins",
                    required=True,
                    help="coin denomination")
    args = vars(ap.parse_args())
#    exchange = args["exchange"]
#    coins = args["coins"]
    print "exchange - {}".format(exchange)
    print "coins - {}".format(coins)
    print "num coins - {}".format(coin_exchange(exchange, coins))
