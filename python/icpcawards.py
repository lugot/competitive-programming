univ_winners=[]
for x in range(int(input())):
	team = input().split()
	if team[0] not in univ_winners and len(univ_winners)<12:
		print("{:s} {:s}".format(team[0],team[1]))
		univ_winners.append(team[0])
