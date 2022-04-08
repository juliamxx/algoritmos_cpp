#include <iostream>

using namespace std;

/*
ELEMENTOS______________________________________
- item (x, t) id, tempo de processamento
- Loader (L)
- Input queue (I, First In First Out)
- Scheduler (S)
- Circular work queue (W)
- Processor (P)
- Output queue (O, Last In First Out)
- Unloader (U)
- duração de um ciclo (K unidades de tempo)
*/

struct Item
{
    int id, tProc;
    Item *next, *prev;

    Item(int id, int tProc) //constructor
    {
        this->id = id;
        this->tProc = tProc;
        next = nullptr;
        prev = nullptr;
    }
};

class Queue
{
    Item *head, *tail;

public:
    Queue() //constructor
    {
        head = nullptr;
        tail = nullptr;
    }

    //insere um item novo na última posição (tail) da Input Queue
    void Load(int id, int tProc)
    {
        Item* item = new Item(id, tProc);
        if (head == nullptr)
            head = item;
        else
            tail->next = item;
        tail = item;
    }

    //retira o item do head da Input Queue e o insere na posição de acesso do Scheduler da Work Queue (head)
    void InsertWork(Queue &input)
    {
        Item* temp = input.head;

        input.head = input.head->next;

        temp->next = this->head;
        temp->prev = this->tail;

        if (this->head == nullptr)
            this->tail = temp;

        this->head = temp;

        if (temp->next != nullptr)
        {
            temp->next->prev = temp;
            temp->prev->next = temp;
        }
    }

    //retira o item da posição de acesso do Scheduler da Work Queue (head) e o insere no top da Output Queue
    void RemoveWork(Queue &output)
    {
        Item* temp = this->head;

        if (this->head != this->tail)
        {
            temp->next->prev = tail; //ou temp->prev
            tail->next = temp->next;
            head = tail->next;
        }
        else
        {
            tail = nullptr;
            head = nullptr;
        }        

        temp->next = output.head;
        temp->prev = nullptr;
        output.head = temp;
    }

    /*efetua um ciclo:
    1 - Verifica se o item no head da Work Queue tá com o tempo restante de processamento 0. Se sim, chama a função removeWork().
    2 - Verifica se algum novo item está presente na Input Queue. Se sim, chama a função InsertWork(). Ou seja, esse novo item ocupará a posição imediatamente após a posição do processador (no sentido de W)
    3 - Subtrai tProc - tCiclo do item no tail e avança a fila circular em uma posição
    */
    void Process(Queue& output, Queue& input, int tCiclo)
    {
        if (this->head != nullptr && this->head->tProc == 0)
            RemoveWork(output);
        
        if (input.head != nullptr)
            InsertWork(input);

        if (this->tail != nullptr)
        {
            this->tail->tProc -= tCiclo;
            if (this->tail->tProc < 0)
                this->tail->tProc = 0;
        }

        //Caso a fila de trabalho esteja vazia, deve ser impresso PROC -1 -1.
        if (this->head == nullptr)
            cout << "PROC -1 -1" << endl;
        else
            cout << "PROC " << this->tail->id << " " << this->tail->tProc << endl;

        if (this->head != this->tail)
        {
            this->head = this->tail;
            this->tail = this->tail->prev;
        }
    }

    //retira o item do top da Output Queue e printa "UNLD X" onde X é o id do item
    void Unload()
    {
        cout << "UNLD " << head->id << endl;

        Item* temp = head->next;
        Item* temp2 = head;
        head->next = nullptr;
        head = temp;
        delete(temp2);
    }
};

int main()
{
    int tCiclo, id, tProc;
    string comando;

    Queue input;
    Queue work;
    Queue output;

    cin >> tCiclo >> comando;

    while (comando != "END")
    {
        if (comando == "LOAD")
        {
            cin >> id >> tProc;
            input.Load(id, tProc);
        }
        else if (comando == "PROC")
            work.Process(output, input, tCiclo);
        else if (comando == "UNLD")
            output.Unload();
        
        cin >> comando;
    }

    return 0;
}