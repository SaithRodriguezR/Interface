//======================================================================//
//  This software is free: you can redistribute it and/or modify        //
//  it under the terms of the GNU General Public License Version 3,     //
//  as published by the Free Software Foundation.                       //
//  This software is distributed in the hope that it will be useful,    //
//  but WITHOUT ANY WARRANTY; without even the implied warranty of      //
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE..  See the      //
//  GNU General Public License for more details.                        //
//  You should have received a copy of the GNU General Public License   //
//  Version 3 in the file COPYING that came with this distribution.     //
//  If not, see <http://www.gnu.org/licenses/>                          //
//======================================================================//
//                                                                      //
//    Copyright (c) 2015 Carlos Saith Rodriguez Rojas                   //
//    Grupo de Estudio y Desarrollo en Robotica GED                     //             
//    Universidad Santo Tomas - Bogota, Colombia                        //
//    http://www.stoxs.org/                                             //
//    saithrodriguez@stoxs.org                                          //
//                                                                      //
//======================================================================//


Proyecto de hardware y software para emular el puerto paralelo con una conexion USB 1.0

Contenido:
firmware:            Archivo binario para programar el PIC 18F4550
hardware:            Circuito esquematico del puerto
interface(VS2010):   Libreria para C/C++ para el manejo del puerto Version Visual Studio 2010
interface(VS2013):   Libreria para C/C++ para el manejo del puerto Version Visual Studio 2013
GuiaProyectoVS.pdf:  Guia para configurar un proyecto de Microsoft Visual Studio con la libreria del puerto


Documentacion de la libreria para c/c++ interface.h

void openPort() => Abre el recurso del puerto
void closePort() => Cierra el recurso del puerto
void outPort(int port, unsigned char data) => Envia datos por el puerto especificado 
unsigned char inPort(int port) => Recibe datos por el puerto especificado
void testPort() => Realiza un conteo binario en el puerto de datos y refleja el valor del puerto de estados en el puerto de control 
