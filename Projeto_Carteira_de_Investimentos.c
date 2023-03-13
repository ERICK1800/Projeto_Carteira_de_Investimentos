#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void TgameOver();
void Carteira(float saldoInicial, float saldoAtual, float AReceber);
float rand1Time();
float rand2Time();
float rand3Time();
float rand4Time();
float rand5Time();
float rand1(float m[]);
float rand2(float m[]);
float rand3(float m[]);
float rand4(float m[]);
float rand5(float m[]);

int main() {
    system("color 3");

    char R;
    float saldoInicial = 600.00, saldoAtual = 600.00, AReceber = 0, m[5];
    int op, aEscolhida, qtdAtivo, tInvestido, qtdMaximo, InvestirNovaM, gameOver, Aux=0, k=0, i=0, j=1;
    m[0]=rand1Time(), m[1]=rand2Time(), m[2]=rand3Time(), m[3]=rand4Time(), m[4]=rand5Time();

    printf(
        "\n\t*****************************************"
        "\n\t*                                \t*"
        "\n\t*\tCARTEIRA DE INVESTIMENTOS\t*"
        "\n\t*                                \t*"
        "\n\t*\t\t1 - Investir     \t*"
        "\n\t*\t\t2 - Sair         \t*"
        "\n\t*                                \t*"
        "\n\t*****************************************\n");
    scanf("%d", &op);
    
    switch (op) {
    case 1:
        for (i = 0; i < j; i++)
        {
            system("cls");
            printf(
                "\n\t      BEM VINDO A BOLSA DE VALORES BRASILEIRA"
                "\n\t    ===========================================\n\n");
            printf(
                "\n\t|  PETR4  |  VALE3  |  BBAS3  |  MGLU3  |  ITUB4  |"
                "\n\t|  %.2f  |  %.2f |  %.2f  |  %.2f | %.2f |", m[0], m[1], m[2], m[3], m[4]);
            Carteira(saldoInicial, saldoAtual, AReceber);

            if (gameOver == 1)
            {
                TgameOver();
                break;
            }
            

            if (Aux == 0)
            {
                printf(
                    "\n\t| 1 | PETR4 |"
                    "\n\t| 2 | VALE3 |"
                    "\n\t| 3 | BBAS3 |"
                    "\n\t| 4 | MGLU3 |"
                    "\n\t| 5 | ITUB4 |\n");
                
                do {
                    //Qual Comprar
                    printf("\n\tQual ativo voce deseja comprar?\n");
                    scanf("%d", &aEscolhida);
                } while (aEscolhida <= 0 && aEscolhida > 6);
                
                //Quantidade de Ações
                qtdMaximo = saldoAtual / m[aEscolhida-1];
                do {
                        
                    printf("\tQual a quantidade? (quantia maxima e de %d)\n", qtdMaximo);
                    scanf("%d", &qtdAtivo);
                } while (qtdAtivo > qtdMaximo || qtdAtivo <= 0);
            }else{
                aEscolhida = Aux;
            }
            
            //Tempo de Investimento
            printf("\n\tQuanto tempo manter o dinheiro investido?\n");
            scanf("%d", &tInvestido);

            if(Aux == 0){
                saldoAtual = saldoInicial - (qtdAtivo * m[aEscolhida-1]);
            }

            system("cls");
            printf(
                "\n\t|  PETR4  |  VALE3  |  BBAS3  |  MGLU3  |  ITUB4  |"
                "\n\t|  %.2f  |  %.2f |  %.2f  |  %.2f | %.2f | Dia 0", m[0], m[1], m[2], m[3], m[4]);

            for (k = 0; k < tInvestido; k++)
            {
                printf("\n\t|  %.2f  |  %.2f |  %.2f  |  %.2f | %.2f | Dia %i", m[0]=rand1(m), m[1]=rand2(m), m[2]=rand3(m), m[3]=rand4(m), m[4]=rand5(m), k+1);
                _sleep(1000);
            }
            AReceber = m[aEscolhida-1] * qtdAtivo;
            Carteira(saldoInicial, saldoAtual, AReceber);

            //Vender Ações
            printf("\n\tDeseja vender as suas acoes? (Y/N) ");
            fflush(stdin);
            R  = toupper(getche());
            while (R != 'Y' && R != 'N')
            {
                printf("\n\tOpcao invalida! Tente novamente: ");
                fflush(stdin);
                R  = toupper(getche());
            }
            if (R == 'Y')
            {
                saldoAtual = saldoAtual + AReceber;
                aEscolhida = 0;
                AReceber = 0;
                Carteira(saldoInicial, saldoAtual, AReceber);
                saldoInicial = saldoAtual;

                //Sentença - Game Over
                if (saldoAtual < m[0] && saldoAtual < m[1] && saldoAtual < m[2] && saldoAtual < m[3] && saldoAtual < m[4])
                {
                    gameOver = 1;
                }
            }

            do
            {
                //Investir Novamente
                printf("\n\n\tDeseja investir novamente? (Y/N) ");
                fflush(stdin);
                R  = toupper(getche());
                while (R != 'Y' && R != 'N')
                {
                    printf("\n\tOpcao invalida! Tente novamente: ");
                    fflush(stdin);
                    R  = toupper(getche());
                }
                if (R == 'Y'){
                    Aux = aEscolhida;
                    j++;
                } else {
                    //Deseja Sair
                    printf("\n\n\tDeseja sair da BOLSA DE VALORES BRASILEIRA? (Y/N) ");
                    fflush(stdin);
                    R  = toupper(getche());
                    while (R != 'Y' && R != 'N')
                    {
                        printf("\n\tOpcao invalida! Tente novamente: ");
                        fflush(stdin);
                        R  = toupper(getche());
                    }
                    if (R == 'Y')
                    {
                        printf("\n\nSaindo...\n");
                        _sleep(3000);
                        system("taskkill /f /im cmd.exe\n\n");
                    }
                }
            } while (R != 'Y');
        }
        break;
    case 2:
        printf("\n\nSaindo...\n");
        _sleep(3000);
        system("taskkill /f /im cmd.exe\n\n");
        break;
    }

    system("pause");

    return 0;
}

//Carteira
void Carteira(float saldoInicial, float saldoAtual, float AReceber){
    printf(
        "\n\n\t| Saldo Inicial | R$ %.2f"
        "\n\t| Saldo Atual   | R$ %.2f"
        "\n\t| A Receber     | R$ %.2f\n", saldoInicial, saldoAtual, AReceber);
}

//Tela de Game Over
void TgameOver(){
    printf(
        " ________      ________      _____ ______       _______           ________      ___      ___  _______       ________     \n"
        "|\\   ____\\    |\\   __  \\    |\\   _ \\  _   \\    |\\  ___ \\         |\\   __  \\    |\\  \\    /  /||\\  ___ \\     |\\   __  \\    \n"
        "\\ \\  \\___|    \\ \\  \\|\\  \\   \\ \\  \\\\__\\  \\  \\   \\ \\   __/|        \\ \\  \\|\\  \\   \\ \\  \\  /  / /\\ \\   __/|    \\ \\  \\|\\  \\   \n"
        " \\ \\  \\  ___   \\ \\   __  \\   \\ \\  \\|__|  \\  \\   \\ \\  \\_|/__       \\ \\  \\\\   \\   \\ \\  \\/  / /  \\ \\  \\_|/__   \\ \\   _  _\\  \n"
        "  \\ \\  \\|\\  \\   \\ \\  \\ \\  \\   \\ \\  \\    \\ \\  \\   \\ \\  \\_|\\ \\       \\ \\  \\\\   \\   \\ \\    / /    \\ \\  \\_|\\ \\   \\ \\  \\\\  \\| \n"
        "   \\ \\_______\\   \\ \\__\\ \\__\\   \\ \\__\\    \\ \\__\\   \\ \\_______\\       \\ \\_______\\   \\ \\__/ /      \\ \\_______\\   \\ \\__\\\\ _\\ \n"
        "    \\|_______|    \\|__|\\|__|    \\|__|     \\|__|    \\|_______|        \\|_______|    \\|__|/        \\|_______|    \\|__|\\|__|\n\n");
}

//RAND BASEADO NO TEMPO

float rand1Time() {
    float preco;
    srand(time(NULL));

    do {
        preco = rand() % 99;
    } while (preco < 10);

    return preco;
}

float rand2Time() {
    float preco;
    srand(time(NULL));

    do {
        preco = rand() % 999;
    } while (preco < 100);

    return preco;
}

float rand3Time() {
    float preco;
    srand(time(NULL));

    do {
        preco = rand() % 50;
    } while (preco < 10);

    return preco;
}

float rand4Time() {
    float preco;
    srand(time(NULL));

    do {
        preco = rand() % 500;
    } while (preco < 100);

    return preco;
}

float rand5Time() {
    float preco;
    srand(time(NULL));

    do {
        preco = rand() % 5000;
    } while (preco < 1000);

    return preco;
}

//RAND BASEADO NO ANTERIOR

float rand1(float m[]) {
    float preco;
    srand(m[0]+rand1Time());

    do {
        preco = rand() % 99;
    } while (preco < 10);

    return preco;
}

float rand2(float m[]) {
    float preco;
    srand(m[1]+rand2Time());

    do {
        preco = rand() % 999;
    } while (preco < 100);

    return preco;
}

float rand3(float m[]) {
    float preco;
    srand(m[2]+rand3Time());

    do {
        preco = rand() % 50;
    } while (preco < 10);

    return preco;
}

float rand4(float m[]) {
    float preco;
    srand(m[3]+rand4Time());

    do {
        preco = rand() % 500;
    } while (preco < 100);

    return preco;
}

float rand5(float m[]) {
    float preco;
    srand(m[0]+rand5Time());

    do {
        preco = rand() % 5000;
    } while (preco < 1000);

    return preco;
}
