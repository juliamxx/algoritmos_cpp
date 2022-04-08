#include <iostream>

using namespace std;

class Premio
{
private:
    int quantItens, minItens, maxVal;
    int* precos;
public:
    int possiveis = 0;
    Premio(int itens)
    {
        quantItens = itens;
        precos = new int[quantItens];
        for (int i = 0; i < quantItens; i++)
            cin >> precos[i];
        
        cin >> minItens >> maxVal;
        backtrack(0, 0, 0, false);
    }
    ~Premio()
    {
        delete[] precos;
    }

    void backtrack(int itensComprados, int precoAtual, int i, bool rep)
    {
        if (precoAtual <= maxVal && itensComprados >= minItens && !rep) possiveis++;
        if (i == quantItens || precoAtual > maxVal) return;
        backtrack((itensComprados + 1), (precoAtual + precos[i]), i + 1, false);
        if (i + 1 < quantItens) backtrack(itensComprados, precoAtual, i + 1, true);
    }
};

int main()
{
    int casos, itens;
    cin >> casos;
    for (int i = 0; i < casos; i++)
    {
        cin >> itens;
        Premio* premio = new Premio(itens);
        cout << "caso " << i << ": " << premio->possiveis << endl;
    }

    return 0;
}