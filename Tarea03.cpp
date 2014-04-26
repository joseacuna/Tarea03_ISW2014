/* 
 * File:   Tarea03.cpp
 * Author: slenderman
 *
 * Created on 22 de abril de 2014, 08:05 PM
 */

#include <cstdlib>
#include<iostream>
#include<cstring>
#include<ctime>
#include<postgresql/libpq-fe.h>

using namespace std;

/*
 * 
 */

void MostrarDatos(string queryDeSQL){
        PGconn *conexion;
        PGresult *res;
        int i,j;
        conexion= PQsetdbLogin("190.100.160.46","5432",NULL,NULL,"iswdb","isw","isw");
         // comprobamos la conexion
        if (PQstatus(conexion) != CONNECTION_BAD)
            
        {
        cout << "\t\t--------------------------------------" << endl;
        cout << "\t\t|  Conexion al Servidor Establecida  |" << endl;
        cout << "\t\t--------------------------------------" << endl << endl;
        
          res = PQexec( conexion, queryDeSQL.c_str() );
        //res = PQexec( conexion, "select * from prueba" );
          int filas = PQntuples(res);
        int columnas = PQnfields(res);

        if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res))
        {
            for (i=0; i<columnas; i++) {
                cout << PQfname(res,i) << "\t\t|\t\t";
            }
            cout << endl;
                for (i = 0; i <= filas-1; i++)
                  
                {
                for (j = 0; j <= columnas-1; j++)
                        cout<<PQgetvalue(res,i,j)<<"\t\t|\t\t";
                        cout<<endl;

                }
        PQclear(res);
        }
        }

        PQfinish(conexion);

}

int main(int argc, char** argv) {
    
    string queryDeSQL;
        
        //-----------
        

        //conexion a la base de datos
        
        

//        queryDeSQL="SELECT tienda ,SUM(monto) AS Venta FROM ventas GROUP BY tienda;";
//        // comprobamos la conexion
//        if (PQstatus(conexion) != CONNECTION_BAD)
//            
//{
//        cout << "\t\t--------------------------------------" << endl;
//        cout << "\t\t|  Conexion al Servidor Establecida  |" << endl;
//        cout << "\t\t--------------------------------------" << endl << endl;
//        
//          res = PQexec( conexion, queryDeSQL.c_str() );
//        //res = PQexec( conexion, "select * from prueba" );
//          int filas = PQntuples(res);
//        int columnas = PQnfields(res);
//
//        if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res))
//        {
//            for (i=0; i<columnas; i++) {
//                cout << PQfname(res,i) << "\t\t|\t\t";
//            }
//            cout << endl;
//                for (i = 0; i <= filas-1; i++)
//                  
//                {
//                for (j = 0; j <= columnas-1; j++)
//                        cout<<PQgetvalue(res,i,j)<<"\t\t|\t\t";
//                        cout<<endl;
//
//                }
//PQclear(res);
//        }
//}
//
//PQfinish(conexion);
//Entrega La Fecha de Compilacion
cout<<endl;
cout << "Fecha de compilacion: " << __DATE__ << " " << __TIME__ << endl;
return 0;
}

