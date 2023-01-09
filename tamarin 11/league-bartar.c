#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

typedef struct player {
	char name[30];
	int price, speed, finishing, defence;
	bool has_team;
} player;

typedef struct team {
	char name[30];
	int playerctr, money, lose, win, draw;
	int p_id[30];//saves player index
} team;
int pick_best(team* tim, int ctr, int first) {
	int winner_ind = first;
	for (int i = first; i < ctr; i++) {
		if (tim[i].win > tim[winner_ind].win) {
			winner_ind = i;

		}
		else if (tim[i].lose < tim[winner_ind].lose) {
			winner_ind = i;
		}

	}
	return winner_ind;
}
void rank(team* tim_orginal, int ctr) {//t_ctr
	char** list;
	team* tim, temp;
	int winner;
	tim = (team*)malloc(ctr * sizeof(team));

	list = (char**)malloc(ctr * sizeof(char*));
	for (int i = 0; i < ctr; i++) {
		list[i] = (char*)malloc(30 * sizeof(char));
		tim[i] = tim_orginal[i];
	}

	for (int i = 0; i < ctr-1; i++) {
		winner = pick_best(tim, ctr, i);
		temp = tim[winner];
		for (int k = winner - 1; k >= i; k--) {
			tim[k + 1] = tim[k];
		}
		tim[i] = temp;
	}
	int c = 1;
	for (int i = 0; i < ctr; i++) {
		printf("%d. %s\n", c, tim[i].name);
		c++;
	}


	free(list);
	return;
}




int main() {
	char buff[40];
	player* plyr = NULL;
	team* tim = NULL;
	int p_ctr = 0, t_ctr = 0, tmp;
	while (1) {
		scanf("%s", buff);

		if (strcmp(buff, "new") == 0) {
			scanf("%s", buff);
			if (strcmp(buff, "player") == 0) {
				plyr = (player*)realloc(plyr, ++p_ctr * sizeof(player));

				scanf("%s", buff);
				strcpy(plyr[p_ctr - 1].name, buff);

				scanf("%d", &tmp);
				plyr[p_ctr - 1].price = tmp;

				scanf("%d", &tmp);
				plyr[p_ctr - 1].speed = tmp;

				scanf("%d", &tmp);
				plyr[p_ctr - 1].finishing = tmp;

				scanf("%d", &tmp);
				plyr[p_ctr - 1].defence = tmp;
				plyr[p_ctr - 1].has_team = false;
			}
			else if (strcmp(buff, "team") == 0) {
				tim = (team*)realloc(tim, ++t_ctr * sizeof(team));

				scanf("%s", buff);
				bool con = false;
				for (int i = 0; i < t_ctr - 1; i++) {//check if team name already exists
					if (strcmp(buff, tim[i].name) == 0)
					{
						scanf("%d", &tmp);
						tim = (team*)realloc(tim, --t_ctr * sizeof(team));
						con = true;
						break;
					}
				}
				if (con)
					continue;

				strcpy(tim[t_ctr - 1].name, buff);
				tim[t_ctr - 1].playerctr = tim[t_ctr - 1].lose = tim[t_ctr - 1].win = tim[t_ctr - 1].draw = 0;
				scanf("%d", &tmp);
				tim[t_ctr - 1].money = tmp;
			}

		}
		else if (strcmp(buff, "buy") == 0) {
			int team_id, player_id;

			scanf("%d %d", &player_id, &team_id);
			player_id--; team_id--;
			if (p_ctr < player_id + 1) {
				printf("player with the id playerID doesnt exist\n");

			}
			else if (t_ctr < team_id + 1) {
				printf("player with the id playerID doesnt exist\n");

			}
			else if (tim[team_id].money < plyr[player_id].price) {
				printf("the team cant afford to buy this player\n");

			}
			else if (plyr[player_id].has_team) {
				printf("player already has a team\n");

			}
			else {
				plyr[player_id].has_team = true;
				tim[team_id].money -= plyr[player_id].price;
				tim[team_id].p_id[tim[team_id].playerctr++] = player_id;
				printf("player added to the team succesfully\n");
			}
		}
		else if (strcmp(buff, "sell") == 0) {
			int team_id, player_id, p_place;
			bool plr_exists = false;
			scanf("%d %d", &player_id, &team_id);
			player_id--; team_id--;

			if (team_id > t_ctr - 1) {//check if team exists
				printf("team doesnt exist\n");
				continue;
			}
			else {
				for (int i = 0; i < tim[team_id].playerctr; i++) {//check if player is in team
					if (player_id == tim[team_id].p_id[i]) {
						plr_exists = true;
						p_place = i;
						break;
					}
				}
				if (!plr_exists) {
					printf("team doesnt have this player\n");

				}
				else {
					printf("player sold succesfully\n");
					tim[team_id].money += plyr[player_id].price;
					for (int i = p_place; i < tim[team_id].playerctr; i++) {
						tim[team_id].p_id[i] = tim[team_id].p_id[i + 1];
					}
					tim[team_id].playerctr--;
					plyr[player_id].has_team = false;
				}

			}
		}
		else if (strcmp(buff, "match") == 0) {
			int team1_id, team2_id;
			scanf("%d %d", &team1_id, &team2_id);
			team1_id--; team2_id--;
			if (team1_id > t_ctr - 1 || team2_id > t_ctr - 1) {
				printf("team doesnt exist\n");

			}
			else if (tim[team1_id].playerctr < 11 || tim[team2_id].playerctr < 11) {

				printf("the game can not be held due to loss of the players\n");


			}
			else {
				int team1_power = 0, team2_power = 0;
				for (int i = 0; i < 11; i++) {
					team1_power += plyr[tim[team1_id].p_id[i]].speed + plyr[tim[team1_id].p_id[i]].finishing;
					team2_power += plyr[tim[team2_id].p_id[i]].speed + plyr[tim[team2_id].p_id[i]].defence;
				}
				if (team1_power > team2_power) {
					tim[team1_id].win++;
					tim[team1_id].money += 1000;
					tim[team2_id].lose++;


				}
				else if (team1_power < team2_power) {
					tim[team2_id].win++;
					tim[team2_id].money += 1000;
					tim[team1_id].lose++;
				}
				else {
					tim[team2_id].draw++;
					tim[team1_id].draw++;
				}
			}

		}
		else if (strcmp(buff, "rank") == 0) {
			rank(tim, t_ctr);
		}
		else if (strcmp(buff, "end") == 0) {
			break;
		}
		else {
			printf("wrong input\n");
		}
	}



	//free();
	return 0;
}
