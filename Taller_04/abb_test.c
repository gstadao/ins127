/* -*- Mode: C; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2; -*- */
/*
 * abb_test.c
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

#include "abb.h"

int main(int argc, char *argv[]) {
	unsigned i, n = 7;
	Nodo *raiz = NULL;
	Info datos[] = {40, 20, 30, 10, 60, 70, 50, 45, 55, 54, 65, 63, 75, 64};
	for(i = 0; i < n; i++) {
		raiz = insertar(raiz, datos[i]);
	}
	preorden(raiz);
	printf("\n");
	inorden(raiz);
	printf("\n");
	postorden(raiz);
	printf("\n");

	raiz = eliminar(raiz, 60);
	raiz = eliminar(raiz, 20);
	preorden(raiz);
	printf("\n");
	Nodo * temp;
	temp = buscarMin(raiz);
	printf("Elemento mínimo es % d.\n",temp->dato);
	temp = buscarMax(raiz);
	printf("Elemento máximo es % d.\n",temp->dato);

	int elemento = 8;
	temp = buscar(raiz, elemento);
	printf("El elemento % d: ",
				 elemento);
	if(temp == NULL)
		printf("no se encontró.\n");
	 else
		printf("se encontró.\n");
	elemento = 50;
	temp = buscar(raiz, elemento);
	printf("El elemento % d: ",
				 elemento);
	if(temp == NULL)
		printf("no se encontró.\n");
	 else
		printf("se encontró.\n");
	eliminarArbol(raiz);
	return 0;
}
