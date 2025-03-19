#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_points(string player, int len);
int transform_points(char c);

int main(void)
{
    string player_1;
    string player_2;

    player_1 = get_string("Player 1: ");
    player_2 = get_string("Player 2: ");

    int points_pl_1 = check_points(player_1, strlen(player_1));
    int points_pl_2 = check_points(player_2, strlen(player_2));

    if (points_pl_1 > points_pl_2)
        printf("Player 1 wins!\n");
    else if (points_pl_1 < points_pl_2)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
    return (0);
}

int check_points(string player, int len)
{
    static int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                             1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int total_points = 0;
    int points_position = 0;

    int j = 0;
    while (j < len)
    {
        if (isalpha(player[j]))
        {
            if (islower(player[j]))
                player[j] = toupper(player[j]);
            points_position = transform_points(player[j]);
            total_points += points[points_position];
        }
        j++;
    }
    return (total_points);
}

int transform_points(char c)
{
    int i = 0;
    int points = 0;

    while (c != i + 65)
    {
        i++;
    }
    if (c == i + 65)
    {
        points += i;
    }
    return (points);
}
