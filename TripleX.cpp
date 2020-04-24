#include <iostream>
#include <locale>
#include <ctime>

void Introduction() 
{
    // "setlocale" faz o compilador expressar a pontuação de forma correta
    setlocale(LC_ALL, "");
    // Enunciado da qustão
    std::cout << "\n\n  ----------------------------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << " | Voce e um pesquisador, procurando uma vacina para uma certa doenca, ha tres elementos quimicos disponiveis que compoe a formula da vacina.   |\n";
    std::cout << " | O seu objetivo e descobrir a quantidade exata de cada elemento, seguindo alguns parametros:                                                  |\n";
    std::cout << "  ----------------------------------------------------------------------------------------------------------------------------------------------\n";
}

bool PlayGame(int Difficulty, int Max)
{
    Introduction();

    // Váriável estática que armazena a resosta correta da questão
    const int CodeA = rand() % Difficulty+1;
    const int CodeB = rand() % Difficulty+1;
    const int CodeC = rand() % Difficulty+1;
    const int CodeSum = CodeA + CodeB + CodeC, CodeProduct = CodeA * CodeB * CodeC;

    // Expressão das variáveis
    std::cout << "- Cada elemento tem um número em mililitros certo, que compoe a formula da vacina numero: " << Difficulty;
    std::cout << "\n- A soma dos tres numeros que compoe a quantidade de cada elemento na fórmula é igual a: " << CodeSum << std::endl;
    std::cout << "- E a multiplicacao dos tres numeros é igual a: " << CodeProduct << std::endl;
    std::cout << "**Digite o numero correto de 3 digitos que atenda todas as especificacoes**\n\n";

    // Guarda os dados inseridos pelo usuário
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    // Guarda a soma e o produto segundo os dados do usuário
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Testa se o usuário inseriu os dados certos
    if (GuessSum == CodeSum && GuessProduct == CodeProduct && Difficulty != Max)
    {
        std::cout << "Voce acertou, Proxima vacina --->";
        return true;
    }
    else if (GuessSum == CodeSum && GuessProduct == CodeProduct && Difficulty == Max)
    {
        return true;
    }
    else
    {
        std::cout << "Voce errou, tente de novo!";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Cria novas sequencias aleatorias baseadas na hora do dia 

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) //Repete o nível atual do jogo até todo os níveis etarem completos
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, MaxLevel);
        std::cin.clear(); // Limpa os erros
        std::cin.ignore();// Descarta o buffer

        if (bLevelComplete && LevelDifficulty == MaxLevel)
        {
            std::cout << "Voce venceu!";
            //Retorno da classe "main"
            return 0;
        }
        else if (!bLevelComplete)
        {

        }
        else
        {
            ++LevelDifficulty;
        }
    }
}