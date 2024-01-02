# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():
    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # Todo: Read teams into memory from file
    # input = sys.argv[1] 冗余程式碼
    with open(sys.argv[1]) as data:
        reader = csv.DictReader(data)
        for row in reader:
            row["rating"] = int(row["rating"])
            teams.append(
                row
            )  # 一直跳針寫成 teams = teams.append(x) ... 因為是 immutable 這樣做會出現 nonetype 錯誤：object has no attribute 'append'
        # print(teams)

    counts = {}  # dictionary
    # todo: Simulate N tournaments and keep track of win counts
    # 建立字典，傳入 team 則 1) 查找有無 team 2) 無就 建立 team 3) count +1
    for i in range(N):
        team = simulate_tournament(teams)
        if team in counts:
            counts[team] += 1  # my_dictionary[new_key] = new_value
        else:
            counts[team] = 1
        # i += 1  # 跑一千次的 loop 冗余程式碼

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # todo
    # repeatedly simulate rounds until you’re left with one team
    while True:
        winner = simulate_round(teams)
        teams = winner
        if len(winner) == 1:
            return winner[0]["team"]  # winner = [{'team': 'Belgium', 'rating': 1346}]


if __name__ == "__main__":
    main()
