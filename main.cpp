#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>
using namespace std;
using std::ofstream;

int main()
{
    string Jugadores = " ";
    int opcion;
    string palabraElegida = " ";
    ofstream archivoJugador("Informacion.txt", ios::out);

    if (!archivoJugador)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit (1);
    }
    cout << "Menu Principal" << endl;

    cout << "1.Ingresar jugadores" << endl;

    cout << "2.Jugar hiatos y diptongos"<< endl;

    cout << "3.Jugar antonimos y sinonimos"<< endl;

    cout << "4.Reporte de jugadores"<< endl;

    cout << "5. Los 10 mejores jugadores"<< endl;

    cout << "6.Salir del programa"<< endl;

    cout << "Ingrese una opcion";
    cin >> opcion;

    int cedula;
    string nombre;
    double puntaje;
    int posicionPalabra;
    switch (opcion)

    {
    case 1: {
        system("cls");
        cout << "Ingresar Jugadores" << endl;
        cout <<  "Numero de cedula: " << endl;
        cin >> cedula;
        cout <<  "Nombre del Jugador: " << endl;
        cin >> nombre;
        cout <<  "Para dejar de ingresar datos digite N, de lo contrario siga ingresando. " << endl;
        while (cedula != 0 && nombre != "N")
        {
            archivoJugador << cedula << setw(5) << nombre << setw(5) << endl;
            cout <<  "Numero de cedula: " << endl;
            cin >> cedula;
            cout <<  "Nombre del Jugador: " << endl;
            cin >> nombre;
            cout <<  "Para dejar de ingresar datos digite N, de lo contrario siga ingresando. " << endl;
        }
        break;
    }
    case 2: {
        system("cls");
        cout << "Jugar Hiatos y Diptongos";
        string palabrasDiptongo[25] = {"Paisaje ", "Peine","Cambio","Cueva ",
                                       "Guardar","Triunfo ", " Baile ","Cumbia","Cielo ","Abuela"," Miop�a ",
                                       "Puerro ","Cuello","Pauta","Flauta","Vuela ", "Coima","Prueba ","Caim�n",
                                       "Reina","Muerte ", "Ruinas","Ciudad ","Cuidado ","Laurel"
                                      };
        string palabrasHiato[25] = {"Caerse ", "Coerci�n","Lealtad ","Loable  ",
                                    "Cooperar","Chiita  ", " Saeta ","Teologal","Melod�a ","Leer "," Fr�o ",
                                    "Sab�amos ","L�e","Creer ","F�en ","Bordear ", "Sa�co","Zool�gico  "," Per�odo",
                                    "Fealdad","Ego�sta  ", "Cambiar�a"," Geolog�a ","Abstraer  ","Caer"
                                   };
        string palabrasDiptongoHiato[50];
        //Copiando los elementos de palabrasDiptongo a palabras
        for(int i=0; i < 25; i++)
        {
            palabrasDiptongoHiato[i] = palabrasDiptongo [i];
        }
        //Copiando los elementros de palabrasHiato a palabras
        for(int i=25; i<50; i++)
        {
            palabrasDiptongoHiato[i] = palabrasHiato[i-25];
        }

        //Mostrar el nuevo vector
        for(int i=0; i<50; i++)
        {
            printf("%s\n",palabrasDiptongoHiato[i]);
        }

        //Semilla generadora
        srand(time(NULL));

        posicionPalabra = rand() % 50;

        palabraElegida = palabrasDiptongoHiato[posicionPalabra];
        system("cls");

        cout << palabraElegida << endl ;
        cout <<"�Es Hiato (H) o Diptongo (D)? :"<< endl;
        char opcionDato;
        cin>> opcionDato;

        break;
    }
    case 3: {
        system("cls");
        cout << "Jugar Sinonimos y Antonimos" << endl;

        string palabasSinonimo[20] = {"Abreviar /acortar","Acceder/permitir","Acci�n / hecho",
                                      "Agradecimiento/gratificaci�n","Baja/ descenso","Bal�n/pelota","Barrera / muro", "Camarada/compa�ero",
                                      "Camino / sendero","D�bil/fr�gil", " Diluir/ disolver", "Encontrar/ localizar", "Fabuloso /magn�fico", " Factible /posible",
                                      "garant�a /respaldo", "Gobernar / dirigir", "Igual / id�ntico", "Leg�timo /aut�ntico","Miedo / temor","Temporal / moment�neo"
                                     };

        string palabrasAntonimos[20] = {"Abreviar /alargar","Acceder/ denegar","Acci�n/ inacci�n","Agradecimiento / ingratitud","Baja/ aumento",
                                        "Barato/ caro", "Calor /fr�o"
                                        ,"camarada/enemigo","d�bil / fuerte","Diluir/ espesar","Eficacia / ineficacia","Encontrar/ perder",
                                        "Igual / diferente","Leg�timo / falso","Libertad /esclavitud","Maltratar / proteger"," Miedo / valent�a","Nacer/ morir","Nada/ todo",
                                        "Similar/ distinto"
                                       };

        string palabrasSinonimoAntonimos[40];
        //Copiando los elementos de palabrasSinonimo a palabrasSinonimoAntonimos
        for(int i=0; i < 20; i++)
        {
            palabrasSinonimoAntonimos[i] = palabasSinonimo[i];
        }
        //Copiando los elementros de palabrasAntonimos a palabrasSinonimoAntonimos
        for(int i=20; i < 40; i++)
        {
            palabrasSinonimoAntonimos[i] = palabrasAntonimos[i-20];
        }
        /* Mostrar el nuevo vector
        for(int i=0; i<40; i++)
        {
            cout << " | " << palabrasSinonimoAntonimos[i] << " | " << endl;
            //printf("%s\n", palabrasSinonimoAntonimos[i]);
        }
        */
        //Semilla generadora
        srand(time(NULL));

        posicionPalabra = rand() % 40;

        palabraElegida = palabrasSinonimoAntonimos[posicionPalabra];
        //system("cls");

        cout<< "Las palabras son: " << palabrasSinonimoAntonimos[posicionPalabra]<< endl;
        cout<< "�Son Sin�nimos (S) o Ant�nimos (A)? :"<<endl;
        char datoSinonimo = 'S';
        char datoAntonimo = 'A';
        char opcionDato = ' ';
        char band = 'F';
        int  i = 0;
        cin>> opcionDato;
//        while ((band == 'F')&& (i<20)){
//            if(palabasSinonimo[i] == datoSinonimo){
//                bandera = 'V';
//            }
//            i++;
//        }
//        if(band == 'V'){
//            printf("Es correcto");
//        }else{
//            printf("Incorrecto!");
//        }

//        while((datoSinonimo == 'S')&& (i<20)){
//            if(palabasSinonimo[i] == opcionDato)
//            {
//                datoSinonimo = 'V';
//            }
//            i++;
//        }
//        if (datoSinonimo == 'S'){
//            cout<<"Es correcto";
//        }
//        else if(datoSinonimo == 'N'){
//            cout<<"Es incorrecto!";
//        }

        break;
    }

    case 4: {
        system("cls");
        cout << "Reporte de jugadores";
        cout << "Numero de cedula: " << endl;
        cout << "Nombre del Jugador: " << endl;
        cout << "�Desea volver al menu principal? S/N : " << endl;

        archivoJugador.close();
        break;
    }
    }

    return 0;
}

