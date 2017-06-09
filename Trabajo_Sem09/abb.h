/* -*- Mode: C; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2; -*- */
/*
 * abb.h
 * This file is part of ED-2014-01-UNAB
 *
 * Copyright (C) 2014 - Carlos Contreras Bolton
 *
 * ED-2014-01-UNAB is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * ED-2014-01-UNAB is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ED-2014-01-UNAB. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _ABB_H_
#define _ABB_H_

typedef int Info;
typedef struct Nodo {
	Info dato;
	struct Nodo *izq;
	struct Nodo *der;
}Nodo;

/* Funciones de las operaciones */
Nodo *crearNodo(Info dato);
Nodo *buscarMin(Nodo *node);
Nodo *buscarMax(Nodo *node);
Nodo *insertar(Nodo *node, Info dato);
Nodo *eliminar(Nodo *node, Info dato);
Nodo *buscar(Nodo *node, Info dato);
Nodo *eliminarArbol(Nodo *a);
void inorden(Nodo *node);
void preorden(Nodo *node);
void postorden(Nodo *node);
#endif /* _ABB_H_ */
