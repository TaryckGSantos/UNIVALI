#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#define MAX 4
#define MAX_HORAIOS 5

struct filmes{
    string nome;
    float horarios[MAX_HORAIOS];
};

int ver_filmes(filmes vet_filmes[]){
    int menu_cliente = 0, horarios = 0, consulta_horario = 0, escolha;

    int quant_filmes = 4, total_horarios = 4;

    float horario_escolhido;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t|          CINECON         |";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t\t . Filmes em cartaz: \n\n";
    for(int i=0; i<MAX; i++){
        cout << "\n\n\t\t\t- " << vet_filmes[i].nome;
    }
    cout << "\n\n\n\n\t\t\t1. Consultar horários";
    cout << "\n\n\t\t\t* Ou pressione qualquer tecla para voltar ao menu anterior *";
    cin >> horarios;
    if (horarios == '1'){
        system("cls");
        cout << "\n\t\t\t\t\t----------------------------";
        cout << "\n\t\t\t\t\t|    CINECON - HORÁRIOS    |";
        cout << "\n\t\t\t\t\t----------------------------";
        cout << "\n\n\n\n\t\t\t\t . Escolha o filme: \n\n";
        for(int i = 0; i < total_horarios; i++){
            cout << "\n\n\t\t\t" << i+1 << ". " << vet_filmes[i].nome;
        }
        cout << "\n\n\n\n\t\t\t";
        cin >> consulta_horario;
        system("cls");
        for(int i = 0; i < total_horarios; i++){
            if(i == consulta_horario-1){
                cout << "\n\t\t\t\t\t----------------------------";
                cout << "\n\t\t\t\t\t|    CINECON - HORÁRIOS    |";
                cout << "\n\t\t\t\t\t----------------------------";
                cout << "\n\n\n\n\t\t\t\t . Horários disponíveis para '" << vet_filmes[i].nome << "' : \n\n\n\n\n\t\t\t";
                for(int j = 0; j < total_horarios; j++){
                    cout << "   -   " << vet_filmes[i].horarios[j];
                }
                system("pause>nul");
            }
        }
    }
}

int compra_ingressos(filmes vet_filmes[]){
    int menu_cliente = 0, horarios = 0, consulta_horario = 0, escolha;

    int quant_filmes = 4, total_horarios = 4;

    float horario_escolhido;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t|          CINECON         |";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t\t . Filmes em cartaz: \n\n";
    for(int i = 0; i < total_horarios; i++){
            cout << "\n\n\t\t\t" << i+1 << ". " << vet_filmes[i].nome;
        }
    cout << "\n\n\n\n\t\t\tEscolha o filme desejado: ";
    cin >> escolha;
    for(int i=0; i<quant_filmes; i++){
        if(i == escolha-1){
            system("cls");
            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\t\t\t\t\t|    CINECON - HORÁRIOS    |";
            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\n\n\n\t\t\t\t . Horários disponíveis para '" << vet_filmes[i].nome << "' : \n\n\n\n\n\t\t\t";
            for(int j = 0; j < total_horarios; j++){
                cout << "   -   " << vet_filmes[i].horarios[j];
            }
            cout << "\n\n\n\t\t\tEscolha um horário: ";
            cin >> escolha;
            for(int j = 0; j < total_horarios; j++){
                if(escolha == vet_filmes[i].horarios[j]){
                    horario_escolhido = escolha;
                } else {
                    cout << "\n\n\n\t\t\tNão há nenhum filme neste horário!!!";
                }
            }
        }
    }
}

int menu_filmes(){

}

int menu_cliente(filmes vet_filmes[]){
    int menu_cliente = 0, horarios = 0, consulta_horario = 0, escolha;

    int quant_filmes = 4, total_horarios = 4;

    float horario_escolhido;

    do{
        system("cls");
        cout << "\n\t\t\t\t\t----------------------------";
        cout << "\n\t\t\t\t\t|   BEM-VINDO AO CINECON!  |";
        cout << "\n\t\t\t\t\t----------------------------";
        cout << "\n\n\n\n\t\t\t - Selecione o que quer fazer -";
        cout << "\n\n\n\n\t\t\t1. Ver filmes em cartaz";
        cout << "\n\n\t\t\t2. Comprar ingresso";
        cout << "\n\n\t\t\t3. Remover ingresso";
        cout << "\n\n\t\t\t4. Buscar ingresso\n\n\t\t\t";
        cin >> menu_cliente;

        if(menu_cliente == 1){ /// APENAS VER QUE FILME ESTÁ EM CARTAZ
            ver_filmes(vet_filmes);
        } else if (menu_cliente == 2){ /// COMPRA DE INGRESSOS
            compra_ingressos(vet_filmes);
        }
    } while (menu_cliente != 7);
}

int confirma_identidade(){
    string padrao_usuario = "admin";
    string padrao_senha = "123456789";
    string usuario, senha;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t|   MENU ADMIN - CINECON   |";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t . Entre com seus dados: \n\n";
    cout << "\n\n\n\t\t\tUsuário: ";
    cin >> usuario;
    cout << "\n\n\n\t\t\tSenha: ";
    cin >> senha;

    if (usuario == padrao_usuario){
        if (senha == padrao_senha){
            return 5;
        } else {
            return 4;
        }
    } else {
        return 3;
    }
}

int menu_admin(filmes vet_filmes[]){
    int aux = 0;
    string aux_menu;
    aux = confirma_identidade();

    if (aux == 5){
        system("cls");
        cout << "\n\t\t\t\t\t----------------------------";
        cout << "\n\t\t\t\t\t|   MENU ADMIN - CINECON   |";
        cout << "\n\t\t\t\t\t----------------------------";
        cout << "\n\n\n\n\t\t\t . Escolha o que deseja fazer: \n\n";
        cout << "\n\n\n\t\t\t1. Entrar no menu de filmes";
        cout << "\n\n\t\t\t2. Entrar no menu de sessões";
        cout << "\n\n\t\t\t3. Entrar no menu de salas";
        cout << "\n\n\t\t\t4. Entrar no menu de clientes";
        cout << "\n\n\t\t\t5. Voltar no menu inicial\n\n\t\t\t";
        cin >> aux_menu;

        if(aux_menu == "1"){
            string aux_menu_filmes;
            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\t\t\t\t\t|    MENU ADMIN - FILMES   |";
            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\n\n\n\t\t\t . Escolha o que deseja fazer: \n\n";
            cout << "\n\n\n\t\t\t1. Criar um novo filme";
            cout << "\n\n\t\t\t2. Excluir um filme";
            cout << "\n\n\t\t\t3. Buscar um filme";
            cout << "\n\n\t\t\t4. Voltar no menu anterior\n\n\t\t\t";
            cin >> aux_menu_filmes;

            if(aux_menu_filmes == "1"){

            } else if(aux_menu_filmes == "2"){

            } else if(aux_menu_filmes == "3"){

            } else if(aux_menu_filmes == "4"){
                return 7;
            } else {
                return menu_filmes();
            }

        } else if (aux_menu == "2"){

        } else if (aux_menu == "3"){

        } else if (aux_menu == "4"){

        } else if (aux_menu == "5"){
            return 1;
        }
    } else if (aux == 4) {
        cout << "\n\n\n\n\n\t\t\tSenha incorreta! ";
        system("pause>nul");
        return menu_admin(vet_filmes);
    } else if (aux == 3){
        cout << "\n\n\n\n\n\t\t\tEste usuário não consta no nosso sistema! ";
        system("pause>nul");
        return menu_admin(vet_filmes);
    }
}

int menu_acesso(filmes vet_filmes[]){
    string select;

    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t| CINECON - MENU DE ACESSO |";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t- Selecione o seu tipo de acesso -";
    cout << "\n\n\n\n\t\t\t1. Acesso de Cliente";
    cout << "\n\n\t\t\t2. Acesso Admin\n\n\n\n\t\t\t";
    cin >> select; // Verifica a tecla pressionada no teclado

    if (select == "1") { // Caso a tecla pressionada seja 1
        menu_cliente(vet_filmes);
    } else if (select == "2") {
        menu_admin(vet_filmes);
    }
}

#endif // TESTES_H_INCLUDED
