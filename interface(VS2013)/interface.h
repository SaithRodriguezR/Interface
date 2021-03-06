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
#include "hidapi/hidapi.h"

#ifndef WINDOWS_H
#include <windows.h>
#endif

#ifndef STDIO_H
#include <stdio.h>
#endif

#ifndef CONIO_H
#include <conio.h>
#endif


hid_device *device;

void openPort()
{
	device = hid_open(0x1234, 0x0001, NULL);
	if(device == NULL)
		printf("Error: No se pudo abrir el puerto\n");
}

void closePort()
{
	if(device != NULL)
		hid_close(device);
}

void outPort(int port, unsigned char data)
{
	if(device != NULL)
	{
		unsigned char buffer[3];
		buffer[0] = 0;
		buffer[1] = port & 0xFF;
		buffer[2] = data;
		hid_write(device, buffer, 3);
	}
}

unsigned char inPort(int port)
{
	if(device != NULL)
	{
		hid_set_nonblocking(device, 1);
		unsigned char bufferTx[3], bufferRx[2];
		bufferTx[0] = 0;
		bufferTx[1] = port & 0xFF;
		bufferTx[2] = 0;
		hid_write(device, bufferTx, 3);
		Sleep(10);
		if(hid_read(device, bufferRx, sizeof(bufferRx)) == 2)
			return bufferRx[0];
	}
	return 0;
}

void testPort()
{
	openPort();
	unsigned char i=0;
	printf("Prueba del puerto en curso...\nPresione una tecla para terminar");
	while(!kbhit())
	{
		outPort(0x378, i);
		i++;
		unsigned char data = ((inPort(0x379)^0x80)>>4)&0x0F;
		outPort(0x37A, data^0x0B );
		Sleep(100);
	}
}
