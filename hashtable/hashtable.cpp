#include <iostream>
#include <cstdlib>

using namespace std;

int GenerateKey(const string &name)
    {
        int key = 0;
        for (int i = 0; i < name.size(); i++)
            key += name[i] * i;
        
        return key;
    }

struct Song
{
    int duration, key, rep;
    string name;

    Song(const string &name, int duration)
    {
        rep = 0;
        this->name = name;
        this->duration = duration;
        key = GenerateKey(name);
    }
};


class Playlist
{
    Song** songs = NULL; //vetor de ponteiros para as músicas
    int max, count; //capacidade máxima e quantidade de elementos inseridos

public:
    //Constructor; cria a playlist (hashtable)
    Playlist(int max)
    {
        count = 0;
        this->max = max;
        songs = (Song**) calloc(max, sizeof(Song*));
        if (songs == nullptr) exit(1);
    }

    //rehash: dobra (++) o max da playlist e reposiciona todos os elementos já inseridos
    void Rehash()
    {
        int position, position0;
        Song** temp = nullptr;
        temp = (Song**) calloc(max, sizeof(Song*));

        for (int i = 0; i < max; i++)
        {
            temp[i] = songs[i];
            songs[i] = nullptr;
        }

        max = max * 2 + 1;

        songs = (Song**) realloc(songs, max * sizeof(Song*));
        for (int i = 0; i < max; i++)
            songs[i] = nullptr;
        
        if (songs == nullptr) exit(1);

        for (int i = 0; i < (max - 1) / 2; i++)
        {
            if (temp[i] != nullptr)
            {
                position0 = temp[i]->key % max;
                position = position0;
                for (int j = 0; 1; j++)
                {
                    if (songs[position] == nullptr)
                    {
                        songs[position] = temp[i];
                        break;
                    }
                    else
                        position = (position0 + j + 1) % max;
                }
            }
        }
        
        // for (int i = 0; i < (max - 1) / 2; i++)
        //     free(temp[i]);
        // free(temp);
    }

    //Adiciona a música de name s com duração t à tabela (playlist); imprime uma linha com o name da música adicionada à playlist e a posição da tabela onde a música ela foi inserida
    //H0(C) = (C mod M); H(C, i) = (H0(C) + i) mod M;
    void Add(Song *song)
    {
        if (count / (max * 1.00) >= 0.5)
            Rehash();
        
        int position0 = song->key % max;
        int position = position0;
        for (int i = 0; 1; i++)
        {
            if (songs[position] == nullptr)
            {
                songs[position] = song;
                count++;
                break;
            }
            else
                position = (position0 + i + 1) % max;
        }
        cout << song->name << ' ' << position << endl;
    }

    //Busca a música de name s na tabela e incrementa o tempo total de reprodução de acordo com sua duração; imprime uma linha com o name da música e o tempo total de reprodução dela até o momento
    void Play(string name)
    {
        int key = GenerateKey(name);
        int position0 = key % max;
        int position = position0;

        for (int i = 0; 1; i++)
        {
            if (songs[position]->name == name)
            {
                songs[position]->rep += songs[position]->duration;
                break;
            }
            else
                position = (position0 + i + 1) % max;
        }
        cout << songs[position]->name << ' ' << songs[position]->rep << endl;
    }

    //Busca a música de name s na tabela e informa o tempo total de reprodução de s até o momento atual; imprime uma linha com o name da música e o tempo total de reprodução dela até o momento
    void Time(string name)
    {
        int key = GenerateKey(name);
        int position0 = key % max;
        int position = position0;

        for (int i = 0; 1; i++)
        {
            if (songs[position]->name == name)
            {
                cout << songs[position]->name << ' ' << songs[position]->rep << endl;
                break;
            }
            else
                position = (position0 + i + 1) % max;
        }
    }

    ~Playlist()
    {
        for (int i = 0; i < max; i++)
            free(songs[i]);
        free(songs);
    }
};

int main()
{
    int max, duration;
    string command, name;

    cin >> max >> command;

    //criar o array com tamanho max
    Playlist playlist(max);

    while (command != "END")
    {
        if (command == "ADD")
        {
            cin >> name >> duration;
            Song* song = new Song(name, duration);
            playlist.Add(song);
        }
        else if (command == "PLAY")
        {
            cin >> name;
            playlist.Play(name);
        }            
        else if (command == "TIME")
        {
            cin >> name;
            playlist.Time(name);
        }
        cin >> command;
    }

    return 0;
}