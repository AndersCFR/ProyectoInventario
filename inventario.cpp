#include<iostream>
#include<string>
#include<stdlib.h>
#include <cstdlib>
#include <ctime> //fecha
#include <locale.h>  //idioma
#include <cstdio>  //conversion

using namespace std;

void encabezado(void);
void piePagina(void);

int main(){
	setlocale(LC_ALL, "spanish");  //habilitando caracteres latinos
	int opcion=0;
	string matrizProductos[100][5]; //codigo, nombre, descripcion, precio, cantidad	
	
	while(opcion!=6){
		system("cls");
		encabezado();
		//int fila=0;
		cout<<"\t<<<<<<<<<Menú Principal>>>>>>>>>\n"<<endl;
		cout<<"[[1]]. Agregar producto\n";
		cout<<"[[2]]. Editar producto\n";
		cout<<"[[3]]. Mostrar Reporte de Ingreso de Productos\n";
		cout<<"[[4]]. Borrar producto\n";
		cout<<"[[5]]. Registrar salida de Productos\n";
		cout<<"[[6]]. Cerrar sesión\n\n";
		cout<<"\nIngrese opcion:";
		//fflush(stdin);
		//getline(cin,opcion);
		cin>>opcion;
			
		switch(opcion){

			case 1:{
						
				string codigo="";
				bool continuarIngreso = true;
				string respuesta="";
				while(continuarIngreso==true){
					int fila=0;
					while(matrizProductos[fila][0].compare("")!=0){fila++;}
					//cout<<"filaaa sss"<<fila<<endl;					
					bool encontrado=false;
					system("cls");
					encabezado();
					cout<<"<<<<<<<<<<<<<<<Agregar Producto>>>>>>>>>>>>>>>>\n\n";
					//cout<<"filaaa"<<fila<<endl;
					cout<<"Digite el codigo: ";
					//fflush(stdin);
					//getline(cin,codigo);				
					cin>>codigo;
					for(int i=0;i<fila;i++){
						if(matrizProductos[i][0].compare(codigo)==0){						
								encontrado=true;
							break;
						}
					}
					if(encontrado==true){
						cout<<"El codigo del producto ingresado ya existe"<<endl;
					}else{
						cout<<"a) Codigo: "<<codigo<<"\n";
						matrizProductos[fila][0]=codigo;
						cout<<"b) Nombre: ";
						//fflush(stdin);
						//getline(cin,matrizProductos[fila][1]);
						cin>>matrizProductos[fila][1];
						cout<<"c) Descripcion: ";
						//fflush(stdin);
						//getline(cin,matrizProductos[fila][2]);
						cin>>matrizProductos[fila][2];
						cout<<"d) Precio: ";
						//fflush(stdin);
						//getline(cin,matrizProductos[fila][3]);
						cin>>matrizProductos[fila][3];
						cout<<"e) Cantidad: ";
						//fflush(stdin);
						//getline(cin,matrizProductos[fila][4]);
						cin>>matrizProductos[fila][4];
						//fila++;
						cout<<"\nEl producto fue ingresado correctamente\n";
					}
					
					cout<<"\n¿Deseas ingresar otro producto?[S/N]:";
					//fflush(stdin);
					//getline(cin,respuesta);
					cin>>respuesta;
					if(respuesta.compare("N")==0){
							continuarIngreso=false;
							piePagina();
							
					}				
					
				}				
				system("pause");
				break;
			}
			
			// Modificación de productos
			
			case 2:{
				int filaModificar=0;
				int fila=0;
				while(matrizProductos[fila][0].compare("")!=0){fila++;}
				string codigo;
				bool continuarEditar = true;
				string respuesta, respuestaConfirmacion;
				while(continuarEditar==true){
					bool encontrado=false;
					system("cls");
					encabezado();
					cout<<"<<<<<<<<<<<<<<Editar producto por codigo>>>>>>>>>>>\n\n";
					cout<<"Digite el codigo: ";
					cin>>codigo;
					
					for(int i=0;i<fila;i++){
						
						if(matrizProductos[i][0].compare(codigo)==0){
								filaModificar=i;
								encontrado=true;
							break;
						}
					}
					if(encontrado==true){		
						string aux[4];
						cout<<"a) Codigo: "<<matrizProductos[filaModificar][0]<<"\n";
						cout<<"b) Nombre: "<<matrizProductos[filaModificar][1]<<"\n";
						cout<<"c) Descripcion: "<<matrizProductos[filaModificar][2]<<"\n";
						cout<<"d) Precio: "<<matrizProductos[filaModificar][3]<<"\n";
						cout<<"e) Cantidad: "<<matrizProductos[filaModificar][4]<<"\n";
						respuesta="";
						cout<<"\nDesea modificar el Nombre del producto?[S/N]: ";
						cin>>respuesta;
						if(respuesta.compare("S")==0){
							cout<<"Nombre del producto: ";
							//fflush(stdin);
							//getline(cin,aux[0]);
							cin>>aux[0];
						}else{
							aux[0]=matrizProductos[filaModificar][1];
						}
						cout<<"\nDesea modificar la Descripcion del producto?[S/N]: ";
						//fflush(stdin);
						//getline(cin,respuesta);
						cin>>respuesta;
					
						if(respuesta.compare("S")==0){							
							cout<<"Descripcion del producto: ";
							//fflush(stdin);
							//getline(cin,aux[1]);
							cin>>aux[1];
						}else{
							aux[1]=matrizProductos[filaModificar][2];
						}
						cout<<"\nDesea modificar el Precio del producto?[S/N]: ";
						//fflush(stdin);
						//getline(cin,respuesta);
						cin>>respuesta;
						if(respuesta.compare("S")==0){							
							cout<<"Precio del producto: ";
							//fflush(stdin);
							//getline(cin,aux[2]);
							cin>>aux[2];
						}else{
							aux[2]=matrizProductos[filaModificar][3];
						}
						cout<<"\nDesea modificar la Cantidad del producto?[S/N]: ";
						//fflush(stdin);
						//getline(cin,respuesta);
						cin>>respuesta;
						if(respuesta.compare("S")==0){							
							cout<<"Cantidad del producto: ";
							//fflush(stdin);
							//getline(cin,aux[3]);
							cin>>aux[3];
						}else{
							aux[3]=matrizProductos[filaModificar][4];
						}
						cout<<">Deseas guardar los cambios?[S/N]: ";
						//fflush(stdin);
						//getline(cin,respuestaConfirmacion);
						cin>>respuestaConfirmacion;
						if(respuestaConfirmacion.compare("S")==0){
							matrizProductos[filaModificar][1]=aux[0];
							matrizProductos[filaModificar][2]=aux[1];
							matrizProductos[filaModificar][3]=aux[2];
							matrizProductos[filaModificar][4]=aux[3];
							cout<<"El producto fue modificado correctamente\n";
						}else{
							cout<<"\nLos cambios no se han guardado\n";
						}
												
					}else{
						cout<<"El codigo del producto no se encuentra almacenado\n";
					}
					
					cout<<"\n>Desea modificar algun otro producto?[S/N]:";
					//fflush(stdin);
					//getline(cin,respuesta);
					cin>>respuesta;
					if(respuesta.compare("N")==0){
							piePagina();
							continuarEditar=false;							
					}										
				}
				system("pause");						
				break;
			}
			
			// Mostar Inventario
			
			case 3:{
					int filaM=0;			
					while(matrizProductos[filaM][0].compare("")!=0){filaM++;}
					system("cls");
					encabezado();
					cout<<"<<<<<<<<<<<<<<Mostrar Reporte de Ingreso de Productos>>>>>>>>>>\n\n";
					cout<<"Código\tNombre\tDescripción\tPrecio($)\tCantidad\n";
					cout<<"-------------------------------------------------------------\n";
					for(int i=0;i<filaM;i++){
						cout<<matrizProductos[i][0]+"\t"+matrizProductos[i][1]+"\t"
						+matrizProductos[i][2]+"\t\t"+matrizProductos[i][3]+"\t\t"+matrizProductos[i][4]+"\n";
					}
						
				piePagina();				
				system("pause");												
				break;
			}
			
			// Eliminación de productos
			case 4:{
				
				int filaEliminar=0;
				int fila=0;
				while(matrizProductos[fila][0].compare("")!=0){fila++;}
				string codigo;
				bool continuarEliminar = true;
				string respuesta, respuestaConfirmacion;
				
				while(continuarEliminar==true){
					bool encontrado=false;
					int cantidadEliminar=0;
					system("cls");
					encabezado();
					cout<<"<<<<<<<<<<<<<Eliminar producto por codigo>>>>>>>>>>\n\n";
					cout<<"Digite el codigo: ";
					//fflush(stdin);
					//getline(cin,codigo);
					cin>>codigo;
					
					for(int i=0;i<fila;i++){
						if(matrizProductos[i][0].compare(codigo)==0){
								filaEliminar=i;
								encontrado=true;
							break;
						}
					}
					
					if(encontrado==true){		
						string aux[4];
						cout<<"a) Codigo: "<<matrizProductos[filaEliminar][0]<<"\n";
						cout<<"b) Nombre: "<<matrizProductos[filaEliminar][1]<<"\n";
						cout<<"c) Descripcion: "<<matrizProductos[filaEliminar][2]<<"\n";
						cout<<"d) Precio: "<<matrizProductos[filaEliminar][3]<<"\n";
						cout<<"e) Cantidad: "<<matrizProductos[filaEliminar][4]<<"\n";
						
						respuesta="";
						cout<<"\nSeguro que desea eliminar este producto?[S/N]: ";
						//fflush(stdin);
						//getline(cin,respuesta);
						cin>>respuesta;
						
						if(respuesta.compare("S")==0){														
							for(int i=filaEliminar; i<fila; i++){
								string aux[5];
								aux[0]=matrizProductos[i+1][0];
								aux[1]=matrizProductos[i+1][1];
								aux[2]=matrizProductos[i+1][2];
								aux[3]=matrizProductos[i+1][3];
								aux[4]=matrizProductos[i+1][4];
								matrizProductos[i][0] = aux[0];
								matrizProductos[i][1] = aux[1];
								matrizProductos[i][2] = aux[2];
								matrizProductos[i][3] = aux[3];
								matrizProductos[i][4] = aux[4];
							}
							cout<<"Producto eliminado con exito!"<<endl;
						}
									
					}else{
						cout<<"\nLo sentimos no encontramos el producto\n";
					}
					
					cout<<"\n>Desea eliminar otro producto?[S/N]:";
					//fflush(stdin);
					//getline(cin,respuestaConfirmacion);	
					cin>>respuestaConfirmacion;
					if(respuestaConfirmacion.compare("N")==0){
							continuarEliminar=false;
							piePagina();
							
					}										
				}					
				system("pause");
				break;
			}
			
			// Retiro de producto de la bodega
			case 5:{				
				int filaModificar=0;
				int fila=0;
				int cantidad=0;
				while(matrizProductos[fila][0].compare("")!=0){fila++;}
				string codigo;
				bool continuarRetiro = true;
				string respuesta, respuestaConfirmacion;
				while(continuarRetiro==true){
					bool encontrado=false;
					system("cls");
					encabezado();
					cout<<"<<<<<<<<<<<Registar la salida de los productos por codigo>>>>>>>>>\n\n";
					cout<<"Digite el codigo: ";
					//fflush(stdin);
					//getline(cin,codigo);
					cin>>codigo;
					
					for(int i=0;i<fila;i++){
						if(matrizProductos[i][0].compare(codigo)==0){
								filaModificar=i;
								encontrado=true;
							break;
						}
					}
					
					if(encontrado==true){		
						string aux[4];
						cout<<"a) Codigo: "<<matrizProductos[filaModificar][0]<<"\n";
						cout<<"b) Nombre: "<<matrizProductos[filaModificar][1]<<"\n";
						cout<<"c) Descripcion: "<<matrizProductos[filaModificar][2]<<"\n";
						cout<<"d) Precio: "<<matrizProductos[filaModificar][3]<<"\n";
						cout<<"e) Cantidad: "<<matrizProductos[filaModificar][4]<<"\n";
						//respuesta="";
						cout<<"\nCuantas unidades se va a retirar?: ";
						//fflush(stdin);
						cin>>cantidad;
						int disponibles = atoi(matrizProductos[filaModificar][4].c_str());
						if(cantidad<=disponibles){
							int aux = (atoi(matrizProductos[filaModificar][4].c_str())-cantidad);							
							char intStr [33];
							string str = string(itoa(aux,intStr,10));														
							matrizProductos[filaModificar][4] = str;
							cout<<"\nSe registro exitosamente el retiro del producto"<<endl;
							cout<<"Quedan "<<aux<<" unidades disponibles en la bodega"<<endl;
						}else{
							cout<<"\nLo sentimos el producto no se puede retirar ya que no hay suficiente stock"<<endl;
						}
														
												
					}else{
						cout<<"Lo sentimos no encontramos el producto\n";
					}
					
					cout<<"\n>Desea retirar otro producto?[S/N]:";
					//fflush(stdin);
					//getline(cin,respuesta);	
					cin>>respuesta;
					if(respuesta.compare("N")==0){
							continuarRetiro=false;
							piePagina();
							
					}										
				}
				system("pause");											
				break;
			}
			
			case 6:{
				system("exit");
				break;
			}
			
			default :{
				cout<<"Opcion no valida, ingrese una opcion correcta"<<endl;
				break;
			}
		}
		
	}
	std::getchar();
	return 0;
}

void encabezado(){
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
	cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>\n";
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>\n";
	cout<<"<<\t\t\tBIENVENIDOS A LA BODEGA\t\t\t>>"<<endl;
	cout<<"<<\t\t\tLOS HERMANOS CAMPOVERDE\t\t\t>>"<<endl;
	cout<<"<<  R.U.C.:09295593001    \tFecha de consulta: "<<
		((now->tm_year + 1900))<<"-"<<(now->tm_mon + 1)<<"-"<<(now->tm_mday)<<"\t>>"<<endl;
	cout<<"<<\t¡Gracias por su compra, te esperamos pronto..!\t\t>>"<<endl;
	cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	
	cout<<"\n\n";
}

void piePagina(){
	cout<<"\n¡Los mejores productos los encuentras aqui.....!\n";
}
