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
                                       "Guardar","Triunfo ", " Baile ","Cumbia","Cielo ","Abuela"," Miopía ",
                                       "Puerro ","Cuello","Pauta","Flauta","Vuela ", "Coima","Prueba ","Caimán",
                                       "Reina","Muerte ", "Ruinas","Ciudad ","Cuidado ","Laurel"
                                      };
        string palabrasHiato[25] = {"Caerse ", "Coerción","Lealtad ","Loable  ",
                                    "Cooperar","Chiita  ", " Saeta ","Teologal","Melodía ","Leer "," Frío ",
                                    "Sabíamos ","Líe","Creer ","Fíen ","Bordear ", "Saúco","Zoológico  "," Período",
                                    "Fealdad","Egoísta  ", "Cambiaría"," Geología ","Abstraer  ","Caer"
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
        cout <<"¿Es Hiato (H) o Diptongo (D)? :"<< endl;
        char opcionDato;
        cin>> opcionDato;

        break;
    }
    case 3: {
        system("cls");
        cout << "Jugar Sinonimos y Antonimos" << endl;

        string palabasSinonimo[20] = {"Abreviar /acortar","Acceder/permitir","Acción / hecho",
                                      "Agradecimiento/gratificación","Baja/ descenso","Balón/pelota","Barrera / muro", "Camarada/compañero",
                                      "Camino / sendero","Débil/frágil", " Diluir/ disolver", "Encontrar/ localizar", "Fabuloso /magnífico", " Factible /posible",
                                      "garantía /respaldo", "Gobernar / dirigir", "Igual / idéntico", "Legítimo /auténtico","Miedo / temor","Temporal / momentáneo"
                                     };

        string palabrasAntonimos[20] = {"Abreviar /alargar","Acceder/ denegar","Acción/ inacción","Agradecimiento / ingratitud","Baja/ aumento",
                                        "Barato/ caro", "Calor /frío"
                                        ,"camarada/enemigo","débil / fuerte","Diluir/ espesar","Eficacia / ineficacia","Encontrar/ perder",
                                        "Igual / diferente","Legítimo / falso","Libertad /esclavitud","Maltratar / proteger"," Miedo / valentía","Nacer/ morir","Nada/ todo",
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
        cout<< "¿Son Sinónimos (S) o Antónimos (A)? :"<<endl;
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
        cout << "¿Desea volver al menu principal? S/N : " << endl;

        archivoJugador.close();
        break;
    }
    }

    return 0;
}

