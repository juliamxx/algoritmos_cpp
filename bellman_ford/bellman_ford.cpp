#include <iostream>
#include <cmath>

#define INF 999

using namespace std;

struct Salto
{
    int esforco, origem, destino;
};

struct Ponto
{
    int x = 0, y = 0, qSaltos = 0;
    Salto* saltos = nullptr;
    bool moeda = 0;
};

class Fase //G
{
private:
    int qPontos, qMoedas;
    int iMoeda;
    Ponto* pontos = nullptr;

public:
    Fase(int quant)
    {
        qPontos = quant;
        pontos = new Ponto[qPontos];
        int i, j;
        
        for (i = 0; i < qPontos; i++)
            cin >> pontos[i].x >> pontos[i].y;

        cin >> qMoedas;
        for (i = 0; i < qMoedas; i++)
        {
            cin >> iMoeda;
            pontos[iMoeda].moeda = true;
        }

        for (i = 0; i < qPontos; i++)
        {
            cin >> pontos[i].qSaltos;
            pontos[i].saltos = new Salto[pontos[i].qSaltos];
            for (j = 0; j < pontos[i].qSaltos; j++)
            {
                pontos[i].saltos[j].origem = i;
                cin >> pontos[i].saltos[j].destino;
                pontos[i].saltos[j].esforco = pow((pontos[pontos[i].saltos[j].destino].x - pontos[i].x), 2) + pow((pontos[pontos[i].saltos[j].destino].y - pontos[i].y), 2);
                if (pontos[pontos[i].saltos[j].destino].moeda == true)
                    pontos[i].saltos[j].esforco *= -1;
            }
        }
    }

    void findAWay()
    {
        int distancias[qPontos], precursores[qPontos], caminho[qPontos], tamCaminho = 0, i, j, k, origem, destino, esforco;

        for (i = 0; i < qPontos; i++)
        {
            distancias[i] = INF;
            precursores[i] = -1;
        }
        distancias[0] = 0;

        for (k = 0; k < qPontos; k++)
        {
            for (i = 0; i < qPontos - 1; i++)
            {
                for (j = 0; j < pontos[i].qSaltos; j++)
                {
                    origem = pontos[i].saltos[j].origem;
                    destino = pontos[i].saltos[j].destino;
                    esforco = pontos[i].saltos[j].esforco;

                    if (distancias[origem] + esforco < distancias[destino])
                    {
                        distancias[destino] = distancias[origem] + esforco;
                        precursores[destino] = origem;
                    }
                }
            }
        }        
        
        for (i = 0; i < qPontos - 1; i++)
        {
            for (j = 0; j < pontos[i].qSaltos; j++)
            {
                origem = pontos[i].saltos[j].origem;
                destino = pontos[i].saltos[j].destino;
                esforco = pontos[i].saltos[j].esforco;

                if (distancias[origem] + esforco < distancias[destino])
                {
                    cout << "LOOP" << endl;
                    return;
                }
            }
        }
        i = qPontos -1;
        j = 0;
        cout << distancias[i] << " " << 0 << " ";
        while (precursores[i] > 0)
        {
            caminho[j] = precursores[i];
            i = caminho[j];
            tamCaminho++;
            j++;
        }
        for (i = tamCaminho - 1; i >= 0; i--)
        {
            cout << caminho[i] << " ";
        }
        cout << qPontos - 1 << endl;
    }

    ~Fase()
    {
        for (int i = 0; i < qPontos; i++)
            delete[] pontos[i].saltos;    
        delete[] pontos;
    }
};

int main()
{
    int fases, quant;
    
    cin >> fases;

    for (int i = 0; i < fases; i++)
    {
        cin >> quant;
        Fase* fase = new Fase(quant);
        fase->findAWay();
    }

    return 0;
}