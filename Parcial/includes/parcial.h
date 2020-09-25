#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED

///PUNTO UNO
//A partir del ingreso de un peso mínimo y un peso máximo,
//listar el apellido y nombres de todos los usuarios que se encuentren dentro de ese rango.

void PuntoA(){
    float Pminimo, Pmaximo;
    system("cls");
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(26,10,46,25);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(31,11); cout << "      MOSTRAR POR RANGO DE PESO";
    gotoxy(27,12); cout << "---------------------------------------------";
    ShowConsoleCursor(true);
    gotoxy(35,21); cout << "INGRESE EL PESO MINIMO";
    gotoxy(35,26); cout << "INGRESE EL PESO MAXIMO";
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(34,22,28,2);
    recuadro(34,27,28,2);
    SetConsoleTextAttribute(hConsole, 7);

    ShowConsoleCursor(true);
    gotoxy(35,23); cin >> Pminimo;
    gotoxy(35,28); cin >> Pmaximo;
    ShowConsoleCursor(false);

    system("pause>NULL");
    system("cls");

    Usuario user;
    FILE * f;
    f = fopen("Dat/usuarioC.dat","rb");
    if(f == NULL){
        return;
    }
    while(fread(&user, sizeof(Usuario),1,f)){
         if(user.Peso>=Pminimo && user.Peso<=Pmaximo){
            cout << endl;
            SetConsoleTextAttribute(hConsole, 6);
            cout << "\t \t \t \t ================================" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "\t \t \t \t ID: "              << user.Nombre << endl;
            cout << "\t \t \t \t NOMBRE: "          << user.Apellido << endl;
            cout << "\t \t \t \t PESO: "            << user.Peso << endl;
            SetConsoleTextAttribute(hConsole, 6);
            cout << "\t \t \t \t ================================" << endl;
         }
    }
    fclose(f);
    system("pause>NULL");
}





///PUNTO DOS
//A partir de una cantidad de calorías ingresadas por teclado, listar apellidos
//y nombres de todos los usuarios que hayan quemado más calorías en total que la cantidad ingresada.

void puntoB(){
    float cal;
    system("cls");
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(26,10,46,25);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(31,11); cout << "        MOSTRAR POR CALORIAS";
    gotoxy(27,12); cout << "---------------------------------------------";
    ShowConsoleCursor(true);
    gotoxy(33,21); cout << "INGRESE LA CANTIDAD DE CALORIAS";
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(34,22,28,2);
    SetConsoleTextAttribute(hConsole, 7);

    ShowConsoleCursor(true);
    gotoxy(35,23); cin >> cal;
    ShowConsoleCursor(false);

    system("pause>NULL");
    system("cls");

    Usuario user;
    FILE * f;
    f = fopen("Dat/usuarioC.dat","rb");
    if(f == NULL){
        return;
    }
    while(fread(&user, sizeof(Usuario),1,f)){
        int ID;
        ID = user.Id;
        int cont;
        cont = buscarPuntoB(ID);
        if(cont >= cal){
            cout << endl;
            SetConsoleTextAttribute(hConsole, 6);
            cout << "\t \t \t \t ================================" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "\t \t \t \t NOMBRE: "             << user.Nombre << endl;
            cout << "\t \t \t \t APELLIDO: "           << user.Apellido << endl;
            cout << "\t \t \t \t CALORIAS ACUMULADAS: "<< cont << endl;
            SetConsoleTextAttribute(hConsole, 6);
            cout << "\t \t \t \t ================================" << endl;
        }
    }
    fclose(f);
    system("pause>NULL");
}


int buscarPuntoB(int ID){
    entrenamiento ent;
    float cont;
    FILE * f;
    f = fopen("Dat/entrenamientoC.dat","rb");
    while(fread(&ent, sizeof(entrenamiento),1,f)){
            if(ID == ent.IDUsuario){
                cont+= ent.calorias;
            }
         }
    fclose(f);
    return cont;
}



#endif // PARCIAL_H_INCLUDED
