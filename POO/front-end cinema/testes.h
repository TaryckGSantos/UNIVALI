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
            cout << "\n\n\n\t\t\tSenha incorreta! ";
            return 4;
        }
    } else {
        cout << "\n\n\n\t\t\tEste usuário não consta no nosso sistema! ";
        return 3;
    }
}



int criar_filme(){
    string nome, isDublado, is3d, data;
    int id, duracao;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t| MENU ADMIN - CRIAR FILME |";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o nome do novo filme: ";
    cin >> nome;
    cout << "\n\n\t\t\t. Insira o ID do filme: ";
    cin >> id;
    cout << "\n\n\t\t\t. O filme é dublado? ";
    cin >> isDublado;
    cout << "\n\n\t\t\t. O filme é 3D? ";
    cin >> is3d;
    cout << "\n\n\t\t\t. Data: ";
    cin >> data;
    cout << "\n\n\t\t\t. Duração do filme (em minutos): ";
    cin >> duracao;
}

int excluir_filme(){
    int aux_id;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t|MENU ADMIN - EXCLUIR FILME|";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o ID do filme que será excluído: ";
    cin >> aux_id;
    /*for(int i=0, i<MAX; i++){
        if(aux_id == vet_filmes[i].id){
            cout << "\n\n\n\n\t\t\t '" << vet_filmes[i].nome << "' excluído!";
            delete vet_filmes[i]; /// USAR O .ERASE
            return 1;
        }
        return 0;
    }*/
}

int buscar_filme(){
    int aux_busca;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t| MENU ADMIN - BUSCA FILME |";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o ID a ser buscado: ";
    cin >> aux_busca;
    /*for(int i=0, i<MAX; i++){
        if(aux_busca == vet_filmes[i].id){
            cout << "\n\n\n\n\t\t\tFilme: '" << vet_filmes[i].nome << "' ";
            return 1;
        }
        return 0;
    }*/
}

int criar_sala(){

    int id, qtd_assentos;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t|  MENU ADMIN - CRIAR SALA |";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o ID da nova sala: ";
    cin >> id;
    cout << "\n\n\t\t\t. Insira a quantidade de assentos da sala: ";
    cin >> qtd_assentos;
}

int buscar_sala(){
    int aux_busca;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t|  MENU ADMIN - BUSCA SALA |";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o ID a ser buscado: ";
    cin >> aux_busca;
    /*for(int i=0, i<MAX; i++){
        if(aux_busca == vet_salas[i].id){
            cout << "\n\n\n\n\t\t\tSala: '" << vet_salas[i].id << "' existe!";
            return 1;
        }
        return 0;
    }*/
}

int excluir_sala(){
    int aux_id;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t| MENU ADMIN - EXCLUIR SALA|";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o ID da sala que será excluída: ";
    cin >> aux_id;
    /*for(int i=0, i<MAX; i++){
        if(aux_id == vet_salas[i].id){
            cout << "\n\n\n\n\t\t\tSala '" << vet_salas[i].nome << "' excluída!";
            delete vet_salas[i]; /// USAR O .ERASE
            return 1;
        }
        return 0;
    }*/
}

int criar_sessao(){

    int id, qtd_assentos_disp;
    string filme, sala;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t| MENU ADMIN - CRIAR SESSÃO|";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o ID da nova sessão: ";
    cin >> id;
    cout << "\n\n\t\t\t. Qual é o filme que será exibido nessa sessão? ";
    cin >> filme;
    cout << "\n\n\t\t\t. Qual é a sala que será utilizada nessa sessão? ";
    cin >> sala;
    cout << "\n\n\t\t\t. Insira a quantidade de assentos disponíveis nessa sala: ";
    cin >> qtd_assentos_disp;
}

int excluir_sessao(){
    int aux_id;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t|MENU ADMIN  EXCLUIR SESSÃO|";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o ID da sessão que será excluída: ";
    cin >> aux_id;
    /*for(int i=0, i<MAX; i++){
        if(aux_id == vet_sessoes[i].id){
            cout << "\n\n\n\n\t\t\tSessão '" << vet_sessoes[i].nome << "' excluída!";
            delete vet_sessao[i]; /// USAR O .ERASE
            return 1;
        }
        return 0;
    }*/
}

int buscar_sessao(){
    int aux_busca;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t| MENU ADMIN - BUSCA SESSÃO|";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o ID a ser buscado: ";
    cin >> aux_busca;
    /*for(int i=0, i<MAX; i++){
        if(aux_busca == vet_ssessoes[i].id){
            cout << "\n\n\n\n\t\t\tA sessão: '" << vet_sessoes[i].id << "' existe!";
            return 1;
        }
        return 0;
    }*/
}

int criar_cliente(){

    int id, idade;
    string nome, pcd;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t|MENU ADMIN - CRIAR CLIENTE|";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o nome do novo cliente: ";
    cin >> nome;
    cout << "\n\n\t\t\t. Insira a idade do novo cliente: ";
    cin >> idade;
    cout << "\n\n\t\t\t. Insira o novo ID do cliente: ";
    cin >> id;
    cout << "\n\n\t\t\t. Esse cliente é pcd? ";
    cin >> pcd;
}

int excluir_cliente(){
    int aux_id;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t|MENU ADMIN.EXCLUIR CLIENTE|";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o ID do cliente que será excluído: ";
    cin >> aux_id;
    /*for(int i=0, i<MAX; i++){
        if(aux_id == vet_clientes[i].id){
            cout << "\n\n\n\n\t\t\tCliente '" << vet_clientes[i].nome << "' excluído!";
            delete vet_clientes[i]; /// USAR O .ERASE
            return 1;
        }
        return 0;
    }*/
}

int buscar_cliente(){
    int aux_busca;

    system("cls");
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\t\t\t\t\t|MENU ADMIN - BUSCA CLIENTE|";
    cout << "\n\t\t\t\t\t----------------------------";
    cout << "\n\n\n\n\t\t\t. Insira o ID a ser buscado: ";
    cin >> aux_busca;
    /*for(int i=0, i<MAX; i++){
        if(aux_busca == vet_clientes[i].id){
            cout << "\n\n\n\n\t\t\tO cliente: '" << vet_clientes[i].id << "' existe!";
            return 1;
        }
        return 0;
    }*/
}

int menu_admin(filmes vet_filmes[], int &aux){
    int aux_excluir, aux_buscar;
    string aux_menu;

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

        if(aux_menu == "1"){ /// Filmes
            system("cls");
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
                criar_filme();
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_filmes == "2"){
                aux_excluir = excluir_filme();
                if(aux_excluir == 0){
                    cout << "\n\n\n\n\t\t\tNenhum filme com esse ID!";
                    system("pause>nul");
                }
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_filmes == "3"){
                aux_buscar = buscar_filme();
                if(aux_buscar == 0){
                    cout << "\n\n\n\n\t\t\tNenhum filme com esse ID!";
                    system("pause>nul");
                }
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_filmes == "4"){
                menu_admin(vet_filmes, aux);
            }
        } else if (aux_menu == "2"){ /// Sessões
            system("cls");
            string aux_menu_sessoes;
            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\t\t\t\t\t|    MENU ADMIN - SESSÕES  |";
            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\n\n\n\t\t\t . Escolha o que deseja fazer: \n\n";
            cout << "\n\n\n\t\t\t1. Criar uma nova sessão";
            cout << "\n\n\t\t\t2. Excluir uma sessão";
            cout << "\n\n\t\t\t3. Buscar uma sessão";
            cout << "\n\n\t\t\t4. Voltar no menu anterior\n\n\t\t\t";
            cin >> aux_menu_sessoes;

            if(aux_menu_sessoes == "1"){
                criar_sessao();
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_sessoes == "2"){
                aux_excluir = excluir_sessao();
                if(aux_excluir == 0){
                    cout << "\n\n\n\n\t\t\tNenhuma sessão com esse ID!";
                    system("pause>nul");
                }
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_sessoes == "3"){
                aux_buscar = buscar_sessao();
                if(aux_buscar == 0){
                    cout << "\n\n\n\n\t\t\tNenhuma sessão com esse ID!";
                    system("pause>nul");
                }
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_sessoes == "4"){
                menu_admin(vet_filmes, aux);
            }
        } else if (aux_menu == "3"){ /// Salas
            system("cls");
            string aux_menu_salas;

            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\t\t\t\t\t|     MENU ADMIN - SALAS   |";
            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\n\n\n\t\t\t . Escolha o que deseja fazer: \n\n";
            cout << "\n\n\n\t\t\t1. Adicionar sala";
            cout << "\n\n\t\t\t2. Remover sala";
            cout << "\n\n\t\t\t3. Procurar sala";
            cout << "\n\n\t\t\t4. Voltar no menu anterior\n\n\t\t\t";
            cin >> aux_menu_salas;

            if(aux_menu_salas == "1"){
                criar_sala();
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_salas == "2"){
                aux_excluir = excluir_sala();
                if(aux_excluir == 0){
                    cout << "\n\n\n\n\t\t\tNenhuma sala com esse ID!";
                    system("pause>nul");
                }
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_salas == "3"){
                aux_buscar = buscar_sala();
                if(aux_buscar == 0){
                    cout << "\n\n\n\n\t\t\tNenhuma sala com esse ID!";
                    system("pause>nul");
                }
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_salas == "4"){
                return 7;
            }
        } else if (aux_menu == "4"){ /// Clientes
            system("cls");
            string aux_menu_clientes;

            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\t\t\t\t\t|   MENU ADMIN - CLIENTES  |";
            cout << "\n\t\t\t\t\t----------------------------";
            cout << "\n\n\n\n\t\t\t . Escolha o que deseja fazer: \n\n";
            cout << "\n\n\n\t\t\t1. Adicionar cliente";
            cout << "\n\n\t\t\t2. Remover cliente";
            cout << "\n\n\t\t\t3. Procurar cliente";
            cout << "\n\n\t\t\t4. Voltar no menu anterior\n\n\t\t\t";
            cin >> aux_menu_clientes;

            if(aux_menu_clientes == "1"){
                criar_cliente();
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_clientes == "2"){
                aux_excluir = excluir_cliente();
                if(aux_excluir == 0){
                    cout << "\n\n\n\n\t\t\tNenhum cliente com esse ID!";
                    system("pause>nul");
                }
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_clientes == "3"){
                aux_buscar = buscar_cliente();
                if(aux_buscar == 0){
                    cout << "\n\n\n\n\t\t\tNenhum cliente com esse ID!";
                    system("pause>nul");
                }
                menu_admin(vet_filmes, aux);
            } else if(aux_menu_clientes == "4"){
                return 7;
            }
        } else if (aux_menu == "5"){
            return 8;
        }
    } else if (aux == 4) {
        int confirma;

        cout << "\n\n\n\t\t\t1. Tentar novamente";
        cout << "\n\n\t\t\t2. Retornar ao menu anterior\n\n\t\t\t";
        cin >> confirma;

        if (confirma == 1){
            aux = confirma_identidade();
            menu_admin(vet_filmes, aux);
        } else if (confirma == 2){
            return 15;
        }
    } else if (aux == 3){
        int confirma;

        cout << "\n\n\n\t\t\t1. Tentar novamente";
        cout << "\n\n\t\t\t2. Retornar ao menu anterior\n\n\t\t\t";
        cin >> confirma;

        if (confirma == 1){
            aux = confirma_identidade();
            menu_admin(vet_filmes, aux);
        } else if (confirma == 2){
            return 15;
        }
    }
}

int menu_acesso(filmes vet_filmes[], int &aux){
    string select;
    int verifica;

    system("cls");
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
        aux = confirma_identidade();
        verifica = menu_admin(vet_filmes, aux);
        if (verifica == 8){
            menu_acesso(vet_filmes, aux);
        }
    }
}

#endif // TESTES_H_INCLUDED
