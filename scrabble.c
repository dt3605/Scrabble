#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Pontuação das letras, índices 0 = A, 1 = B, ..., 25 = Z
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Entrada das palavras
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Computa a pontuação
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Decide o vencedor
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int sum = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Se for letra, calcula pontuação
        if (isalpha(word[i]))
        {
            // Converte para maiúscula para ter índice consistente
            int idx = toupper(word[i]) - 'A';
            sum += POINTS[idx];
        }
    }
    return sum;
}

