#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

using namespace std;

template <typename TIPO, int MAX> // template usada em todo o código
struct Agenda { // Struct criacao agenda.
    TIPO itens[MAX]; // Variavel itens genericos.
    int quantidade; // Quantidade contatos manipulavel.
};

struct comercial{ // Struct com dados comerciais.
    int id;
    long long int cnpj;
    string nome;
    long long int telefone;
};

struct pessoal{ // Struct com dados pessoais.
    int id;
    long long int cpf;
    string nome;
    long long int celular;
};

template <typename TIPO, int MAX> // Inicializacao da agenda.
void inicializa_agenda(Agenda <TIPO,MAX> &ag) {
    ag.quantidade = 0;  // quantidade comeca com zero.
}

template <int MAX>
void insere_pessoal(Agenda <pessoal,MAX> &ag){ // Funcao que cadastra contatos pessoais.
    pessoal Contatop; // Declarando variavel auxuliar para receber valores.

    system("cls");
    cout << endl << "\t\t- Agenda -";
    cout << endl << endl << endl << "\tInsira o CPF: ";
    cin >> Contatop.cpf;
    cout << endl << "\tInsira o nome: ";
    /*while(getline(cin,Contatop.nome))
        if(Contatop.nome != ""){
            break;
        }*/
    cin >> Contatop.nome;
    cout << endl << "\tInsira o Telefone: ";
    cin >> Contatop.celular;
    cout << endl << "\tInsira o ID desejado: ";
    cin >> Contatop.id; // O ID é atribuído por quem está digitando

    for(int i=0;i<ag.quantidade;i++){
        if(Contatop.cpf==ag.itens[i].cpf){ // Caso ja possua esse valor cadastrado mensagem de aviso.
            system("cls");
            cout << endl << "\t\t- Agenda -";
            cout << endl << endl << endl << "\tO CPF digitado já está sendo utilizado em outra conta. " << endl;
            system("pause");
            return;
        }

        if(Contatop.id==ag.itens[i].id){ // Caso ja possua esse valor cadastrado mensagem de aviso.
            system("cls");
            cout << endl << "\t\t- Agenda -";
            cout << endl << endl << endl << "\tO ID digitado já está sendo utilizado em outra conta. ";
            cout << endl;
            system("pause");
            return;
        }

        if(Contatop.nome==ag.itens[i].nome){ // Caso ja possua esse nome cadastrado mensagem de aviso.
            system("cls");
            cout << endl << "\t\t- Agenda -";
            cout << endl << endl << endl << "\tO Nome digitado já está sendo utilizado em outra conta. ";
            cout<<endl;
            system("pause");
            return;
        }
    }
    ag.itens[ag.quantidade]=Contatop; // Atribuição das entradas no vetor agenda
    ag.quantidade++; // quantidade aumentada
}


template <int MAX>
void insere_comercial(Agenda <comercial,MAX> &ag){ // Funcao que cadastras contatos comerciais.
    comercial Contatoc;

    system("cls");
    cout << endl << "\t\t- Agenda -";
    cout << endl << endl << endl << "\tInsira o CNPJ: ";
    cin >> Contatoc.cnpj;
    cout << endl << "\tInsira o nome: ";
    /*while(getline(cin,Contatoc.nome))
        if(Contatoc.nome != ""){
                break;
        }*/
    cin >> Contatoc.nome;
    cout << endl << "\tInsira o Telefone: ";
    cin >> Contatoc.telefone;
    cout << endl << "\tInsira o ID desejado: ";
    cin >> Contatoc.id;

    for(int i=0;i<ag.quantidade;i++){
        if(Contatoc.cnpj==ag.itens[i].cnpj){ // Caso já haja um cnpj igual no código
            system("cls");
            cout << endl << "\t\t- Agenda -";
            cout << endl << endl << endl << "\tO CPF digitado já está sendo utilizado em outra conta. " << endl;
            system("pause");
            return;
        }

        if(Contatoc.id==ag.itens[i].id){ // Caso já haja um id igual no código
            system("cls");
            cout << endl << "\t\t- Agenda -";
            cout << endl << endl << endl << "\tO ID digitado já está sendo utilizado em outra conta. " << endl;
            system("pause");
            return;
        }

        if(Contatoc.nome==ag.itens[i].nome){ // Caso já haja um nome igual no código
            system("cls");
            cout << endl << "\t\t- Agenda -";
            cout << endl << endl << endl << "\tO Nome digitado já está sendo utilizado em outra conta. " << endl;
            system("pause");
            return;
        }
    }
    ag.itens[ag.quantidade]=Contatoc; //Novamente no final o vetor agenda recebe os valores de entrada
    ag.quantidade++;
}

template <typename TIPO, int MAX>
void remover(Agenda <TIPO,MAX> &ag){ //Função para a remoção de alguma atribuição
    int select;
    string var_nome;
    int var_id;
    int j,i;

    system("cls");
    cout << endl << "\t\t- Agenda Pessoal-";
    cout << endl << endl << endl << "\tPor qual meio você deseja pesquisar: ";
    cout << endl << endl << "\t1 - Nome: ";
    cout << endl << "\t2 - ID: " << endl << endl << "\t";
    cin >> select; // Seleção de qual tipo de busca e remoção fazer

    if(select==1){
        system("cls");
        cout << endl << "\t\t- Agenda -";
        cout << endl << endl << endl << "\tInserir o Nome: ";
        /*while(getline(cin,var_nome))
            if(var_nome != ""){
                break;
            }*/
        cin >> var_nome; //Escolhido a busca por nome

        for(i=0;i<ag.quantidade;i++){
            if(var_id==ag.itens[i].id){ // caso a busca for igual a algum dado, o conjunto é apagado
                for(j=i; j<ag.quantidade-1;j++)
                    ag.itens[i] = ag.itens[i+1];
                    ag.quantidade--;
                cout << endl << endl << "\tRemovido com sucesso";
                cout << endl << endl;
                system("pause");
            } else{
                cout << endl << endl << endl <<"\tNão existe ninguém com esse nome"; // busca por nome não encontrado
                system("pause");
            }
        }
    }

    else if(select==2){
        system("cls");
        cout << endl << "\t\t- Agenda -";
        cout << endl << endl << endl << "\tInserir o ID: ";
        cin >> var_id; //Escolhido a busca por ID


        for(i=0;i<ag.quantidade;i++){
            if(var_id==ag.itens[i].id){ // caso alguem tenha o id igual ao da busca
                for(j=i; j<ag.quantidade-1;j++)
                    ag.itens[i] = ag.itens[i+1];
                    ag.quantidade--;
                cout << endl << endl << "\tRemovido com sucesso";
                cout << endl << endl;
                system("pause");
            } else {
                cout << endl << endl << endl <<"\tNão existe ninguém com esse ID"; // caso o id digitado não seja parelho
                system("pause");
            }
        }
    }
}

template <int MAX>
void pesquisar_pessoal(Agenda <pessoal,MAX> &ag){ //função para pesquisa pessoal
    int select;
    string var_nome;
    int var_id;

    system("cls");
    cout << endl << "\t\t- Agenda Pessoal-";
    cout << endl << endl << endl << "\tPor qual meio você deseja pesquisar: ";
    cout << endl << endl << "\t1 - Nome: ";
    cout << endl << "\t2 - ID: " << endl << endl << "\t";
    cin >> select; // seleção de qual meio é realizada a pesquisa

    if(select==1){
        system("cls");
        cout << endl << "\t\t- Agenda -";
        cout << endl << endl << endl << "\tInserir o Nome: ";
        cin >> var_nome; // nome a ser buscado

        for(int i=0;i<ag.quantidade;i++){
            if(var_nome==ag.itens[i].nome){ //caso o nome seja igual a algum outro
                system("cls");
                cout << endl << "\t\t- Agenda -"; // mostra todos os dados de tal pessoa
                cout << endl << endl << endl << "\tNome: " << ag.itens[i].nome;
                cout << endl << "\tCPF: "<< ag.itens[i].cpf;
                cout << endl << "\tTelefone: "<< ag.itens[i].celular;
                cout << endl << "\tID: " << ag.itens[i].id << endl << endl;
                system("pause");
            }
        }
    }

    else if(select==2){
        system("cls");
        cout << endl << "\t\t- Agenda -";
        cout << endl << endl << endl << "\tInserir o ID: ";
        cin >> var_id; // ID a ser buscado

        for(int i=0;i<ag.quantidade;i++){
            if(var_id==ag.itens[i].id){ //caso o ID seja igual a algum outro
                system("cls");
                cout << endl << "\t\t- Agenda -"; // mostra todos os dados de tal pessoa
                cout << endl << endl << endl << "\tNome: " << ag.itens[i].nome;
                cout << endl << "\tCPF: "<< ag.itens[i].cpf;
                cout << endl << "\tTelefone: "<< ag.itens[i].celular;
                cout << endl << "\tID: " << ag.itens[i].id << endl << endl;
                system("pause");
            }
        }
    }
}

template <int MAX>
void pesquisar_comercial(Agenda <comercial,MAX> ag){ //função para pesquisa comercial
    int select;
    string var_nome;
    int var_id;

    system("cls");
    cout << endl << "\t\t- Agenda Comercial-";
    cout << endl << endl << endl << "\tPor qual meio você deseja pesquisar: ";
    cout << endl << endl << "\t1 - Nome: ";
    cout << endl << "\t2 - ID: " << endl << endl << "\t";
    cin >> select; // seleção de qual meio é realizada a pesquisa

    if(select==1){
        system("cls");
        cout << endl << "\t\t- Agenda -";
        cout << endl << endl << endl << "\tInserir o Nome: ";
        cin >> var_nome; // nome a ser buscado

        for(int i=0;i<ag.quantidade;i++){
            if(var_nome==ag.itens[i].nome){ //caso o nome seja igual a algum outro
                system("cls");
                cout << endl << "\t\t- Agenda -"; // mostra todos os dados de tal pessoa
                cout << endl << endl << endl << "\tNome: " << ag.itens[i].nome;
                cout << endl << "\tCNPJ: "<< ag.itens[i].cnpj;
                cout << endl << "\tTelefone: "<< ag.itens[i].telefone;
                cout << endl << "\tID: " << ag.itens[i].id;
                system("pause");
            }
        }
    }

    else if(select==2){
        system("cls");
        cout << endl << "\t\t- Agenda -";
        cout << endl << endl << endl << "\tInserir o ID: ";
        cin >> var_id; // ID a ser buscado

        for(int i=0;i<ag.quantidade;i++){
            if(var_id==ag.itens[i].id){ //caso o id seja igual a algum outro
                system("cls");
                cout << endl << "\t\t- Agenda -"; // mostra todos os dados da pessoa encontrada
                cout << endl << endl << endl << "\tNome: " << ag.itens[i].nome;
                cout << endl << "\tCNPJ: "<< ag.itens[i].cnpj;
                cout << endl << "\tTelefone: "<< ag.itens[i].telefone;
                cout << endl << "\tID: " << ag.itens[i].id;
                system("pause");
            }
        }
    }
}

template <typename TIPO, int MAX>
void exibir_pessoas(Agenda <TIPO,MAX> &ag){ // função para a exibição de todas as entradas de pessoas

    system("cls");
    cout << endl << "\t\t- Agenda -";
    cout << endl << endl << endl << "\tItens da agenda pessoal: ";
    cout << endl;

    for(int i=0;i<ag.quantidade;i++){ // laço para ir de 0 ate o final, independendo da quantidade
        cout << endl << endl << "\tNome: " << ag.itens[i].nome;
        cout << endl << "\tCPF: " << ag.itens[i].cpf;
        cout << endl << "\tTelefone celular: : " << ag.itens[i].celular;
        cout << endl << endl << "\t";
    }
    system("pause");
}

template <typename TIPO, int MAX>
void exibir_empresas(Agenda <TIPO,MAX> &ag){ // função para a exibição de todas as entradas de empresas

    system("cls");
    cout << endl << "\t\t- Agenda -";
    cout << endl << endl << endl << "\tItens da agenda pessoal: ";
    cout << endl;

    for(int i=0;i<ag.quantidade;i++){ // laço para ir de 0 ate o final, independendo da quantidade
        cout << endl << endl << "\tNome: " << ag.itens[i].nome;
        cout << endl << "\tCPF: " << ag.itens[i].cnpj;
        cout << endl << "\tTelefone celular: : " << ag.itens[i].telefone;
        cout << endl << endl << "\t";
    }
    system("pause");
}

template <int MAXP>
///MENU PESSOAL
void Menu_pessoal(int select, Agenda<pessoal,MAXP>&agp){ // Menu unicamente da agenda pessoal

    int cont_pes;

    cout << endl << "\t\t- Agenda Pessoal-";
    cout << endl << endl << endl << "\t\tEscolha o que fazer: ";
    cout << endl << endl << "\t1 - Para inserir um novo contato na agenda";
    cout << endl << "\t2 - Para remover um item da agenda";
    cout << endl << "\t3 - Para pesquisar um item da agenda";
    cout << endl << "\t4 - Para exibir os conteúdos da agenda: ";
    cout << endl << "\t5 - Para encerrar a agenda" << endl << endl << "\t";
    cin >> select;

    switch(select)
    {
    case 1:
        insere_pessoal(agp); // caso 1 - inserção de pessoas
        break;
    case 2:
        remover(agp); // caso 2 - remoção de pessoas
        break;
    case 3:
        pesquisar_pessoal(agp); // caso 3 - pesquisa individual de pessoas
        break;
    case 4:
        exibir_pessoas(agp); // caso 4 - exibição total de pessoas
        break;
    case 5: // Encerramento da agenda
        system("cls");
        cout << endl << endl << endl <<"\t\t\tAgenda encerrada :) ";
        cout << endl << endl << endl;
        exit(0);
        break;
    }
    system("cls");
}

template <int MAXC>
///MENU COMERCIAL
void Menu_comercial(int select, Agenda<comercial,MAXC>&agc){ // Menu unicamente da agenda comercial
    cout << endl << "\t\t- Agenda Comercial-";
    cout << endl << endl << endl << "\t\tEscolha o que fazer: ";
    cout << endl << endl << "\t1 - Para inserir um novo contato na agenda";
    cout << endl << "\t2 - Para remover um item da agenda";
    cout << endl << "\t3 - Para pesquisar um item da agenda";
    cout << endl << "\t4 - Para exibir os conteúdos da agenda: ";
    cout << endl << "\t5 - Para encerrar a agenda" << endl << endl << "\t";
    cin >> select;

    switch(select)
    {
    case 1:
        insere_comercial(agc); // caso 1 - inserção de empresas
        break;
    case 2:
        remover(agc); // caso 2 - remoção de empresas
        break;
    case 3:
        pesquisar_comercial(agc); // caso 3 - pesquisa individual de empresas
        break;
    case 4:
        exibir_empresas(agc); // caso 4 - exibição de todas as empresas
        break;
    case 5: // caso 5 - Término do programa
        system("cls");
        cout << endl << endl << endl << "\t\t\tAgenda encerrada :) ";
        cout << endl << endl << endl;
        exit(0);
        break;
    }
    system("cls");
}

template <int MAXP, int MAXC>
void Menu_contato(int select,Agenda<pessoal,MAXP>&agp, Agenda<comercial,MAXC>&agc){ // Menu usado para distinguir quem vai usufruir dos comandos

    cout << endl << "\t\t- Agenda -";
    cout << endl << endl << endl << "\tMenu de Contato:";
    cout << endl << endl << "\t1 - Ir para o setor pessoal da agenda";
    cout << endl << "\t2 - Ir para o setor comercial na agenda";
    cout << endl << "\t3 - Para encerrar a agenda" << endl << endl << "\t";
    cin >> select;
    system("cls");
    switch(select)
    {
        case 1:
            Menu_pessoal(select,agp); // caso seja escolhido 1, vai para o menu pessoal
            break;
        case 2:
            Menu_comercial(select,agc); // caso seja escolhido 2, vai para o menu comercial
            break;
        case 3: // encerramento
            system("cls");
            cout << endl << endl << endl <<"\t\t\tAgenda encerrada :) ";
            cout << endl << endl << endl;
            exit(0);
            break;
    }
}

#endif // AGENDA_H_INCLUDED
