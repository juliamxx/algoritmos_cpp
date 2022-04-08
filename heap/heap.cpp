#include <iostream>

using namespace std;

struct Hospital
{
    int casos, id;
    Hospital()
    {
        id = 0;
        casos = 0;
    }
};

/*
MaxHeap de hospitais em relação ao número de casos
+ Vetor auxiliar que guarda a posição do hospital com determinado id no índice correspondente ao id (atualizado a cada operação)
*/
class Sistema
{
private:
    int size, heapSize, posSize;
    Hospital* hospitais = nullptr;
    int* pos = nullptr;

    void bubbleDown(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int m = i;

        if (l < heapSize && hospitais[l].casos > hospitais[m].casos) m = l;
        if (l < heapSize && hospitais[l].casos == hospitais[m].casos && hospitais[l].id > hospitais[m].id) m = l;
        if (r < heapSize && hospitais[r].casos > hospitais[m].casos) m = r;
        if (l < heapSize && hospitais[r].casos == hospitais[m].casos && hospitais[r].id > hospitais[m].id) m = r;
        
        if (m != i)
        {
            Hospital temp;
            temp = hospitais[m];
            hospitais[m] = hospitais[i];
            hospitais[i] = temp;
            bubbleDown(m);
        }
        pos[hospitais[i].id] = i;
    }

    void bubbleUp(int i)
    {
        Hospital temp;
        int tempPos, p;
        p = (i - 1) / 2;
        while (i > 0 && hospitais[i].casos >= hospitais[p].casos)
        {
            tempPos = pos[hospitais[p].id];
            temp = hospitais[p];
            pos[hospitais[p].id] = pos[hospitais[i].id];
            hospitais[p] = hospitais[i];
            pos[hospitais[i].id] = tempPos;
            hospitais[i] = temp;

            i = p;
            p = (i - 1) / 2;
        }
    }

    void buildHeap()
    {
        for (int i = heapSize / 2 - 1; i >= 0; i--)
            bubbleDown(i);
    }

    void printHospital()
    {
        if (heapSize > 0)
            cout << hospitais[0].id << " " << hospitais[0].casos << endl;
        else
            cout << -1 << " " << -1 << endl;
        
    }

public:
    Sistema(int quant, int casos0[]) //inicializa o sistema com a quantidade de hospitais, o número de casos e o vetor auxiliar
    {
        heapSize = quant;
        posSize = size = heapSize * 2;

        pos = new int[posSize];
        hospitais = new Hospital[size];
        for (int i = 0; i < heapSize; i++)
        {
            pos[i] = i;
            hospitais[i].casos = casos0[i];
            hospitais[i].id = i;
        }
        buildHeap();
    }

    ~Sistema()
    {
        delete[] hospitais;
        delete[] pos;
    }

    void insertHospital(int id, int casos) //cadastra um novo hospital
    {
        if (size == heapSize)
        {
            size *= 2;
            Hospital* temp = new Hospital[size];
            for (int i = 0; i < heapSize; i++)
                temp[i] = hospitais[i];

            hospitais = temp;
        }
        if (posSize == id)
        {
            posSize *= 2;
            int* tempPos = new int[posSize];
            for (int i = 0; i < posSize; i++)
                tempPos[i] = pos[i];

            pos = tempPos;
        }

        hospitais[heapSize].id = id;
        hospitais[heapSize].casos = casos;
        pos[id] = heapSize;
        bubbleUp(heapSize);
        heapSize++;
        printHospital();
    }

    void deleteHospital(int id) //remove um hospital
    {
        heapSize--;
        hospitais[pos[id]] = hospitais[heapSize];
        pos[hospitais[pos[id]].id] = pos[id];
        bubbleDown(pos[id]);
        printHospital();
    }

    void inCasos(int id, int casos) //incrementa o número de casos do hospital
    {
        hospitais[pos[id]].casos += casos;
        cout << hospitais[pos[id]].casos << endl;
        bubbleUp(pos[id]);
    }

    void outCasos(int id, int casos) //decrementa o número de casos do hospital
    {
        hospitais[pos[id]].casos -= casos;
        cout << hospitais[pos[id]].casos << endl;
        bubbleDown(pos[id]);
    }

    void pay(int recursos) //dispara uma rodada de distribuição de uma quantidade total R em recursos para os hospitais.
    {
        int pago = 0;
        while (recursos > 0 && hospitais[0].casos > 0)
        {
            hospitais[0].casos--;
            bubbleDown(0);
            recursos--;
            pago++;
        }
        cout << pago << endl;
    }

    void totalCasos()
    {
        int total = 0;
        for (int i = 0; i < heapSize; i++)
            total += hospitais[i].casos;

        cout << total << endl;
    }
};


int main()
{
    int quant, id, casos, recursos;
    string command;
    
    cin >> quant;
    int casos0[quant];

    for (int i = 0; i < quant; i++)
        cin >> casos0[i];

    Sistema sistema(quant, casos0);

    cin >> command;
    while (command != "END")
    {
        if (command == "NEW")
        {
            cin >> id >> casos;
            sistema.insertHospital(id, casos);
        }
        else if (command == "DEL")
        {
            cin >> id;
            sistema.deleteHospital(id);
        }            
        else if (command == "IN")
        {
            cin >> id >> casos;
            sistema.inCasos(id, casos);
        }
        else if (command == "OUT")
        {
            cin >> id >> casos;
            sistema.outCasos(id, casos);
        }
        else if (command == "PAY")
        {
            cin >> recursos;
            sistema.pay(recursos);
        }
        cin >> command;
    }
    sistema.totalCasos();

    return 0;
}