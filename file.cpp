#include <iostream>
#include <ctime>

double gen_char();

char user_char();

char generated_char();

void update_scores(int &val1, int &val2, char choice1, char choice2);

int main()
{
    std::cout << "Welcome! to the ROCK PAPER SCISSORS game \n";
    char user_pick;

    int score1 = 0;
    int score2 = 0;

    do
    {
        // user selected character
        user_pick = user_char();

        // computer displays it's generated character
        char generated = generated_char();

        if (user_pick == 'p' || user_pick == 'p' || user_pick == 'r' || user_pick == 'R' || user_pick == 'S' || user_pick == 's')
        {
            std::cout << "I picked " << generated << '\n';
            // track scores
            update_scores(score1, score2, user_pick, generated);
            std::cout << "you " << score1 << " : " << "me " << score2 << '\n';
        }
        else if (user_pick == 'Q')
        {
            if (score1 == score2)
            {
                std::cout << "we are tied! \n";
            }
            else if (score1 > score2)
            {
                std::cout << "Congratulations! You won \n";
            }
            else
            {
                std::cout << "I won YAY! \n";
            }
            std::cout << "Goobye";
        }
    } while (user_pick != 'Q');

    return 0;
}

char user_char()
{
    char item;
    std::cout << "Pick a character (r)ock or (p)aper or (s)cissors (Q to quit): ";
    std::cin >> item;

    while (item != 'r' && item != 'R' && item != 'p' && item != 'P' && item != 'S' && item != 's' && item != 'Q')
    {
        std::cout << "Incorrect value! Choose either (r)ock or (p)aper or (s)cissors (Q to quit): ";
        std::cin >> item;
    }

    return item;
}

char generated_char()
{
    char item;
    srand(time(NULL));

    int rand_num = (rand() % 3) + 1;

    if (rand_num == 1)
    {
        item = 'r';
    }
    else if (rand_num == 2)
    {
        item = 'p';
    }
    else
    {
        item = 's';
    }

    return item;
}

void update_scores(int &score1, int &score2, char char1, char char2)
{
    if (char1 == char2)
    {
        return;
    }

    // Player 1 wins conditions
    if ((char1 == 'r' && char2 == 's') ||
        (char1 == 'p' && char2 == 'r') ||
        (char1 == 's' && char2 == 'p'))
    {
        score1++;
    }
    else
    {
        // Player 2 wins otherwise
        score2++;
    }
}
