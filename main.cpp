#include <iostream>
#include <stack>

using namespace std;

#define LINHA 20
#define COLUNA 21

void geraLab(char lab[][COLUNA]) {

    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            if(lab [i][j] == 'E')
                lab[i][j] = ' ';
            if(lab [i][j] == 'S')
                lab[i][j] = ' ';
        }
        cout << endl;
    }
};
void imprimeLab(char lab[][COLUNA]) {

    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            if(lab [i][j] == 'E')
                lab[i][j] = ' ';
            if(lab [i][j] == 'S')
                lab[i][j] = ' ';
            cout << lab[i][j];
        }
        cout << endl;
    }
};
int main(){
    char labirinto[LINHA][COLUNA]{
            "XEXXXXXXXXXXXXXXXXXX",//1
            "X   X              X",//2
            "XX     X XXX   X   X",//3
            "XXXXXXXXX     XXX  X",//4
            "X   XXX   XXXXX    X",//5
            "X            XXX  XX",//6
            "XX XXXX XXXXX     XX",//7
            "X    X           XXX",//8
            "X   XXXX     XXX  XX",//9
            "XXXXX      XX     XX",//10
            "X      XXXXX   XXXXX",//11
            "XXXX    XXX        X",//12
            "X XXX   X     XXXX X",//13
            "X       XXX        X",//14
            "X     XX   X       X",//15
            "XXX XX XX     XXXXXX",//16
            "X         XX   X   X",//17
            "XX XXXX   XXX  X   X",//18
            "X    X  XXX    X   X",//19
            "XXXXXXXSXXXXXXXXXXXX"//20
    };

    geraLab(labirinto);

    stack<int>stackL;
    stack<int>stackC;

    int linha = 0;
    int coluna = 1;

    bool saida = false;

    while(!saida) {

        if (linha == 'S' && coluna == 'S'){
            saida = true;
            break;
        }
        if (labirinto[linha][coluna + 1] == ' '){
            stackL.push(linha);
            stackC.push(coluna);
            labirinto[linha][coluna] = '*';
            coluna++;
        }
        else if (labirinto[linha + 1][coluna] == ' '){
            stackL.push(linha);
            stackC.push(coluna);
            labirinto[linha][coluna] = '*';
            linha++;
        }
        else if (labirinto[linha][coluna - 1] == ' '){
            stackL.push(linha);
            stackC.push(coluna);
            labirinto[linha][coluna] = '*';
            coluna--;
        }
        else if (labirinto[linha - 1][coluna] == ' '){
            stackL.push(linha);
            stackC.push(coluna);
            labirinto[linha][coluna] = '*';
            linha--;
        }
        else {
            if (!stackL.empty()) {
                labirinto[linha][coluna] = 'D';
                stackL.pop();
                stackC.pop();
            }
            else{
                saida = true;
                imprimeLab(labirinto);
            }
        }
    }
    return 0;
}
