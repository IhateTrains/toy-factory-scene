#pragma once

extern unsigned int texture[5];
extern int tasmociagStartPos;
extern double rot1, rot2, rot3;
extern double rotA, rotB;


void trawa();
void podloga();
void sciany();
void dach();
void okna();


void skrzynka();

void kula();




void szescian();

void prostopadloscian(double dlugosc, double wysokosc, double szerokosc);

void walec(double h, double r);

void ramie(double r1, double r2, double h, double d);


void zabawka(const bool glowa, const bool rece);


void tasmociag();


void robot(double d1, double d2, double d3, const bool zReka, const double rotacjaReki);

void dwa_roboty();

void ur16e(double d1, double d2, double d3, const bool zReka, const double rotacjaReki);
