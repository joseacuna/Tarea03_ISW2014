/* 
 * File:   Tarea03.cpp
 * Author: slenderman
 *
 * Created on 22 de abril de 2014, 08:05 PM
 */

#include <cstdlib>
#include<iostream>
#include<cstring>
#include<postgresql/libpq-fe.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
        PGconn *conexion;
        PGresult *res;
        int i,j;
        
        //-----------
        

        //conexion a la base de datos
        conexion= PQsetdbLogin("sebastian.cl","5432",NULL,NULL,"iswdb","isw","isw");
        

        string queryDeSQL="select tienda ,sum(monto) as Venta from ventas group by tienda;";
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
return 0;
}

