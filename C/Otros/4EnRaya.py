#! usr/bin/env python

import sys
import random

#print "|_||_||_||_||_||_||_||_|";
#print "|_||_||_||_||_||_||_||_|";
#print "|_||_||_||_||_||o||_||_|";
#print "|_||_||_||o||o||x||_||_|";
#print "|_||_||_||o||x||x||o||_|";
#print "|_||_||o||x||x||x||o||_|";

fila1=['|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|']
fila2=['|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|']
fila3=['|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|']
fila4=['|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|']
fila5=['|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|']
fila6=['|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|']
fila7=['|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|']
fila8=['|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|']
fila9=['|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|','|_|']
maximofila = len(fila1)

tablero = [fila1,fila2,fila3,fila4,fila5,fila6,fila7,fila8,fila9]
maximotablero = len(tablero)

for i in xrange(0,maximotablero):
	for x in xrange(0,maximofila):
		sys.stdout.write(tablero[i][x])
	print ''

nombre=raw_input('Selecciona el jugador X o O');

#print "Eres el jugador "+ nombre