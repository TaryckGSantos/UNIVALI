#include <iostream>
using namespace std;

#include <vector>

class Jogo {
private:
    string nome;
    int id;

public:
    Jogo(string nome) {
        this->nome = nome;
    }

    string getNome() {
        return this->nome;
    }
};

class Jogador {
private:
    string nome;
    int idade;
    vector<Jogo> jogos;
    string posicao;
    int id;

public:
    Jogador(string nome, int idade, string posicao, int id) {
        this->nome = nome;
        this->idade = idade;
        this->posicao = posicao;
        this->id = id;
    }

    void adicionarJogo(Jogo jogo) {
        jogos.push_back(jogo);
    }

    void mostrar(Jogo jogo) {
        cout << "Player: " << this->nome << "\n\n";
        cout << "Idade: " << this->idade << "\n\n";
        cout << "Jogos:\n";
        for(int i = 0; i < jogos.size(); i++){
            cout << jogo.getNome() << "\n";
        }
        cout << "Posição in Game: " << this->posicao << "\n\n";
        cout << "ID do player: " << this->id << "\n\n";
    }

    int getID() {
        return this->id;
    }

    string getNome() {
        return this->nome;
    }

    void inserir_player(vector<Jogador> &player, string nome, int idade, string jogo, string posicao, int id){
        player.push_back(Jogador(nome,idade,posicao,id));
    }

    void mostrar_players(vector<Jogador> &player, Jogo jogo){
        for(int i = 0; i < player.size(); i++){
            player[i].mostrar(jogo);
        }
    }
};

class Time{
private:
    string nome;
    vector<Jogo> jogo;
    vector<Jogador> jogadores;

public:
    Time(string nome) {
        this->nome = nome;
    }

    string getNome(){
        return this->nome;
    }
    void inserir_jogador(vector<Jogador> &jogadores, string nome, int idade, string jogo, string posicao, int id){
        jogadores.push_back(Jogador(nome,idade,posicao,id));;
    }

    void mostrar_players(vector<Jogador> &jogadores) {
        cout << "Time: " << this->nome << "\n\n";
        cout << "Players : \n";
        for(int i = 0; i < jogadores.size(); i++){
            cout << jogadores[i].getNome() << "\n";
        }
    }

    void remover_players(int id) {
        for (auto it = jogadores.begin(); it != jogadores.end(); ++it) {
            if (it->getID() == id) {
                jogadores.erase(it);
                break;
            }
        }
    }
};

class Campeonato{
private:
    string nome;
    vector<Jogo> jogos;
    vector<Time> times;
public:
    Campeonato(const string& nome) {
        this->nome = nome;
    }
    string getNome(){
        return this->nome;
    }
    void adicionarJogo(const Jogo& jogo) {
        jogos.push_back(jogo);
    }

    void adicionarTime(const Time& time) {
        times.push_back(time);
    }

    void removerTime(const string& nomeTime) {
        for (auto it = times.begin(); it != times.end(); ++it) {
            if (it->getNome() == nomeTime) {
                times.erase(it);
                break;
            }
        }
    }

    Time* buscarTime(const string& nomeTime) {
        for (auto& time : times) {
            if (time.getNome() == nomeTime) {
                return &time;
            }
        }
        return NULL;
    }
};

struct Plataforma {
    vector<Campeonato> campeonatos;
public:
    void criarCampeonato(const string& nome) {
        campeonatos.push_back(nome);
        cout << "Campeonato '" << nome << "' criado com sucesso.\n";
    }

    void eliminarCampeonato(const string& nome) {
        for (auto it = campeonatos.begin(); it != campeonatos.end(); ++it) {
            if (it->getNome() == nome) {
                campeonatos.erase(it);
                cout << "Campeonato '" << nome << "' eliminado com sucesso.\n";
                return;
            }
        }
        cout << "Campeonato '" << nome << "' não encontrado.\n";
    }

    void verCampeonatos() {
        cout << "Campeonatos existentes:\n";
        for (int i = 0; i < campeonatos.size(); i++) {
            cout << " - " << campeonatos[i].getNome() << "\n";
        }
    }
};

int main()
{

    vector<Jogo> jogos;
    vector<Jogador> jogadores;
    vector<Time> times;
    vector<Campeonato> campeonatos;
    vector<Plataforma> plataformas;

    return 0;
}
