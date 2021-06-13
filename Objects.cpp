#include "Objects.h"
#include "Normal.h"

#include <Windows.h>            // Window defines
#include <gl/GL.h>              // OpenGL
#include <gl/GLU.h>             // GLU library
#include <cmath>				// Define for sqrt


constexpr auto GL_PI = 3.14;
constexpr auto rozmiar_fabryki = 128;

void podloga() {
	glColor3d(1, 1, 1);
	const double k = 3;
	const double f = 30;

	// podloga fabryki
	glEnable(GL_TEXTURE_2D); // W³¹cz teksturowanie
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	glTexCoord2d(0.0, 0.0); glVertex3d(-k * rozmiar_fabryki, 0, -k * rozmiar_fabryki);
	glTexCoord2d(0.0, f); glVertex3d(-k * rozmiar_fabryki, 0, k * rozmiar_fabryki);
	glTexCoord2d(f, f); glVertex3d(k * rozmiar_fabryki, 0, k * rozmiar_fabryki);
	glTexCoord2d(f, 0.0); glVertex3d(k * rozmiar_fabryki, 0, -k * rozmiar_fabryki);
	glEnd();
	glDisable(GL_TEXTURE_2D); // Wy³¹cz teksturowanie

	// trawa
	glEnable(GL_TEXTURE_2D); // W³¹cz teksturowanie
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	glTexCoord2d(0.0, 0.0); glVertex3d(-k * 1024, -1, -k * 1024);
	glTexCoord2d(0.0, f); glVertex3d(-k * 1024, -1, k * 1024);
	glTexCoord2d(f, f); glVertex3d(k * 1024, -1, k * 1024);
	glTexCoord2d(f, 0.0); glVertex3d(k * 1024, -1, -k * 1024);
	glEnd();
	glDisable(GL_TEXTURE_2D); // Wy³¹cz teksturowanie
}

void sciany() {
	glDisable(GL_CULL_FACE);
	glPolygonMode(GL_BACK, GL_FILL);

	glColor3d(1, 1, 1);
	glEnable(GL_TEXTURE_2D); // W³¹cz teksturowanie
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	const double k = 3;
	const double f = 50;
	glBegin(GL_QUADS);
	// sciana tylna
	glNormal3d(0, 0, 1);
	glTexCoord2d(0.0, 0.0); glVertex3d(-k * rozmiar_fabryki, 300, -k * rozmiar_fabryki);
	glTexCoord2d(0.0, f); glVertex3d(-k * rozmiar_fabryki, 0, -k * rozmiar_fabryki);
	glTexCoord2d(f, f); glVertex3d(k * rozmiar_fabryki, 0, -k * rozmiar_fabryki);
	glTexCoord2d(f, 0.0); glVertex3d(k * rozmiar_fabryki, 300, -k * rozmiar_fabryki);
	// sciana przednia
	glNormal3f(0, 0, -1);
	glTexCoord2d(0.0, 0.0); glVertex3d(k * rozmiar_fabryki, 300, k * rozmiar_fabryki);
	glTexCoord2d(0.0, f); glVertex3d(k * rozmiar_fabryki, 0, k * rozmiar_fabryki);
	glTexCoord2d(f, f); glVertex3d(-k * rozmiar_fabryki, 0, k * rozmiar_fabryki);
	glTexCoord2d(f, 0.0); glVertex3d(-k * rozmiar_fabryki, 300, k * rozmiar_fabryki);
	// sciana lewa z otworem
	glNormal3f(0, 0, 1);
	glTexCoord2d(0.0, 0.0); glVertex3d(-k * rozmiar_fabryki, 300, k * rozmiar_fabryki);
	glTexCoord2d(0.0, f); glVertex3d(-k * rozmiar_fabryki, 0, k * rozmiar_fabryki);
	glTexCoord2d(f, f); glVertex3d(-k * rozmiar_fabryki, 0, 50);
	glTexCoord2d(f, 0.0); glVertex3d(-k * rozmiar_fabryki, 300, 50);
	glNormal3f(0, 0, 1);
	glTexCoord2d(0.0, 0.0); glVertex3d(-k * rozmiar_fabryki, 300, 50);
	glTexCoord2d(0.0, f); glVertex3d(-k * rozmiar_fabryki, 120, 50);
	glTexCoord2d(f, f); glVertex3d(-k * rozmiar_fabryki, 120, 0);
	glTexCoord2d(f, 0.0); glVertex3d(-k * rozmiar_fabryki, 300, 0);
	glNormal3f(0, 0, 1);
	glTexCoord2d(0.0, 0.0); glVertex3d(-k * rozmiar_fabryki, 300, 0);
	glTexCoord2d(0.0, f); glVertex3d(-k * rozmiar_fabryki, 0, 0);
	glTexCoord2d(f, f); glVertex3d(-k * rozmiar_fabryki, 0, -k * rozmiar_fabryki);
	glTexCoord2d(f, 0.0); glVertex3d(-k * rozmiar_fabryki, 300, -k * rozmiar_fabryki);
	
	// sciana prawa z otworem
	glNormal3f(0, 0, 1);
	glTexCoord2d(0.0, 0.0); glVertex3d(k * rozmiar_fabryki, 300, -k * rozmiar_fabryki);
	glTexCoord2d(0.0, f); glVertex3d(k * rozmiar_fabryki, 0, -k * rozmiar_fabryki);
	glTexCoord2d(f, f); glVertex3d(k * rozmiar_fabryki, 0, 0);
	glTexCoord2d(f, 0.0); glVertex3d(k * rozmiar_fabryki, 300, 0);
	glNormal3f(0, 0, 1);
	glTexCoord2d(0.0, 0.0); glVertex3d(k * rozmiar_fabryki, 300, 0);
	glTexCoord2d(0.0, f); glVertex3d(k * rozmiar_fabryki, 120, 0);
	glTexCoord2d(f, f); glVertex3d(k * rozmiar_fabryki, 120, 50);
	glTexCoord2d(f, 0.0); glVertex3d(k * rozmiar_fabryki, 300, 50);
	glNormal3f(0, 0, 1);
	glTexCoord2d(0.0, 0.0); glVertex3d(k * rozmiar_fabryki, 300, 50);
	glTexCoord2d(0.0, f); glVertex3d(k * rozmiar_fabryki, 0, 50);
	glTexCoord2d(f, f); glVertex3d(k * rozmiar_fabryki, 0, k * rozmiar_fabryki);
	glTexCoord2d(f, 0.0); glVertex3d(k * rozmiar_fabryki, 300, k * rozmiar_fabryki);

	glEnd();

	glDisable(GL_TEXTURE_2D); // Wy³¹cz teksturowanie


	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_BACK, GL_LINE);
}

void dach() {
	glDisable(GL_CULL_FACE);
	glPolygonMode(GL_BACK, GL_FILL);

	glColor3d(1, 1, 1);
	const double k = 3;
	const double f = 5;

	glEnable(GL_TEXTURE_2D); // W³¹cz teksturowanie
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);

	// lewa strona dachu
	float vl[3][3] = {
		{ -k * rozmiar_fabryki, 300, -k * rozmiar_fabryki },
		{ -k * rozmiar_fabryki, 300, k * rozmiar_fabryki },
		{ 0, 500, k * rozmiar_fabryki }
	};
	float norm[3];
	calcNormal(vl, norm);
	glNormal3f(norm[0], norm[1], norm[2]);
	glTexCoord2d(f, 0.0); glVertex3d(-k * rozmiar_fabryki, 300, -k * rozmiar_fabryki);
	glTexCoord2d(0.0, 0.0); glVertex3d(-k * rozmiar_fabryki, 300, k * rozmiar_fabryki);
	glTexCoord2d(0.0, f); glVertex3d(0, 500, k * rozmiar_fabryki);
	glTexCoord2d(f, f); glVertex3d(0, 500, -k * rozmiar_fabryki);

	// prawa strona dachu
	float vr[3][3] = {
		{ 0, 500, -k * rozmiar_fabryki },
		{ 0, 500, k * rozmiar_fabryki },
		{ k * rozmiar_fabryki, 300, k * rozmiar_fabryki }
	};
	calcNormal(vr, norm);
	glNormal3f(norm[0], norm[1], norm[2]);
	glTexCoord2d(f, 0.0); glVertex3d(0, 500, -k * rozmiar_fabryki);
	glTexCoord2d(0.0, 0.0); glVertex3d(0, 500, k * rozmiar_fabryki);
	glTexCoord2d(0.0, f);  glVertex3d(k * rozmiar_fabryki, 300, k * rozmiar_fabryki);
	glTexCoord2d(f, f); glVertex3d(k * rozmiar_fabryki, 300, -k * rozmiar_fabryki);
	glEnd();
	glDisable(GL_TEXTURE_2D); // Wy³¹cz teksturowanie

	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_BACK, GL_LINE);
}



void skrzynka()
{
	glColor3d(0.8, 0.7, 0.3);

	glEnable(GL_TEXTURE_2D); // W³¹cz teksturowanie

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glTexCoord2d(1.0, 1.0); glVertex3d(25, 25, 25);
	glTexCoord2d(0.0, 1.0); glVertex3d(-25, 25, 25);
	glTexCoord2d(0.0, 0.0); glVertex3d(-25, -25, 25);
	glTexCoord2d(1.0, 0.0); glVertex3d(25, -25, 25);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glNormal3d(1, 0, 0);
	glTexCoord2d(1.0, 1.0); glVertex3d(25, 25, 25);
	glTexCoord2d(0.0, 1.0); glVertex3d(25, -25, 25);
	glTexCoord2d(0.0, 0.0); glVertex3d(25, -25, -25);
	glTexCoord2d(1.0, 0.0); glVertex3d(25, 25, -25);
	glEnd();



	glBegin(GL_QUADS);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glNormal3d(0, 0, -1);
	glTexCoord2d(1.0, 1.0); glVertex3d(25, 25, -25);
	glTexCoord2d(0.0, 1.0); glVertex3d(25, -25, -25);
	glTexCoord2d(0.0, 0.0); glVertex3d(-25, -25, -25);
	glTexCoord2d(1.0, 0.0); glVertex3d(-25, 25, -25);

	glNormal3d(-1, 0, 0);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexCoord2d(1.0, 1.0); glVertex3d(-25, 25, -25);
	glTexCoord2d(0.0, 1.0); glVertex3d(-25, -25, -25);
	glTexCoord2d(0.0, 0.0); glVertex3d(-25, -25, 25);
	glTexCoord2d(1.0, 0.0); glVertex3d(-25, 25, 25);

	// wierzch skrzynki
	glColor3d(0.0, 0.0, 0.0);
	glTexCoord2d(1.0, 1.0); glVertex3d(25, 25, 25);
	glTexCoord2d(0.0, 1.0); glVertex3d(25, 25, -25);
	glTexCoord2d(0.0, 0.0); glVertex3d(-25, 25, -25);
	glTexCoord2d(1.0, 0.0); glVertex3d(-25, 25, 25);

	glColor3d(0.8, 0.7, 0.3);
	glNormal3d(0, -1, 0);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexCoord2d(1.0, 1.0); glVertex3d(25, -25, 25);
	glTexCoord2d(0.0, 1.0); glVertex3d(-25, -25, 25);
	glTexCoord2d(0.0, 0.0); glVertex3d(-25, -25, -25);
	glTexCoord2d(1.0, 0.0); glVertex3d(25, -25, -25);

	glDisable(GL_TEXTURE_2D); // Wy³¹cz teksturowanie
	glEnd();
}

void walec01()
{
	GLUquadricObj* obj = gluNewQuadric();
	gluQuadricNormals(obj, GLU_SMOOTH);
	glColor3d(1, 0, 0);
	glPushMatrix();
	gluCylinder(obj, 20, 20, 30, 15, 7);
	gluCylinder(obj, 0, 20, 0, 15, 7);
	glTranslated(0, 0, 60);
	glRotated(180.0, 0, 1, 0);
	gluCylinder(obj, 0, 20, 30, 15, 7);
	glPopMatrix();
}

void kula()
{
	GLUquadricObj* obj = gluNewQuadric();
	gluQuadricTexture(obj, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glColor3d(1.0, 0.8, 0.8);
	glEnable(GL_TEXTURE_2D);
	gluSphere(obj, 40, 15, 7);
	glDisable(GL_TEXTURE_2D);
}

void szescian() {
	const int a = 20;
	glColor3d(1, 0.5, 0);
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glVertex3d(a, -a, a);
	glVertex3d(a, a, a);
	glVertex3d(-a, a, a);
	glVertex3d(-a, -a, a);

	glNormal3d(0, 0, -1);
	glVertex3d(-a, -a, -a);
	glVertex3d(-a, a, -a);
	glVertex3d(a, a, -a);
	glVertex3d(a, -a, -a);
	glEnd();
	glBegin(GL_QUAD_STRIP);
	glNormal3d(1, 0, 0);
	glVertex3d(a, a, -a);
	glVertex3d(a, a, a);
	glVertex3d(a, -a, -a);
	glVertex3d(a, -a, a);

	glNormal3d(0, -1, 0);
	glVertex3d(-a, -a, -a);
	glVertex3d(-a, -a, a);

	glNormal3d(-1, 0, 0);
	glVertex3d(-a, a, -a);
	glVertex3d(-a, a, a);

	glNormal3d(0, 1, 0);
	glVertex3d(a, a, -a);
	glVertex3d(a, a, a);
	glEnd();
}

void prostopadloscian(const double dlugosc, const double wysokosc, const double szerokosc) {
	glBegin(GL_QUADS);
	// sciana przednia
	glNormal3d(0, 0, 1);
	glVertex3d(dlugosc, 0, szerokosc);
	glVertex3d(dlugosc, wysokosc, szerokosc);
	glVertex3d(0, wysokosc, szerokosc);
	glVertex3d(0, 0, szerokosc);
	// sciana tylna
	glNormal3d(0, 0, -1);
	glVertex3d(0, 0, 0);
	glVertex3d(0, wysokosc, 0);
	glVertex3d(dlugosc, wysokosc, 0);
	glVertex3d(dlugosc, 0, 0);
	glEnd();
	glBegin(GL_QUAD_STRIP); // TODO: zamieniæ na GL_QUADS
	// sciana prawa
	glNormal3d(1, 0, 0);
	glVertex3d(dlugosc, wysokosc, 0);
	glVertex3d(dlugosc, wysokosc, szerokosc);
	glVertex3d(dlugosc, 0, 0);
	glVertex3d(dlugosc, 0, szerokosc);
	// podstawa dolna
	glNormal3d(0, -1, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, szerokosc);
	// sciana lewa
	glNormal3d(-1, 0, 0);
	glVertex3d(0, wysokosc, 0);
	glVertex3d(0, wysokosc, szerokosc);
	// podstawa gorna
	glNormal3d(0, 1, 0);
	glVertex3d(dlugosc, wysokosc, 0);
	glVertex3d(dlugosc, wysokosc, szerokosc);
	glEnd();
}

void walec(const double h, const double r) {
	double x, y, alpha;
	const double rozdzielczosc = 16;
	//dolna podstawa
	glBegin(GL_TRIANGLE_FAN);
	glNormal3d(0, 0, -1);
	glVertex3d(0, 0, 0);
	for (alpha = 0.0; alpha <= 2 * GL_PI; alpha += GL_PI / rozdzielczosc) {
		x = r * sin(alpha);
		y = r * cos(alpha);
		glVertex3d(x, y, 0);
	}
	glEnd();

	// sciana boczna
	glBegin(GL_QUAD_STRIP);
	for (alpha = 0.0; alpha <= 2 * GL_PI; alpha += GL_PI / rozdzielczosc) {
		x = r * sin(alpha);
		y = r * cos(alpha);
		glNormal3d(sin(alpha), cos(alpha), 0.0);
		glVertex3d(x, y, 0);
		glVertex3d(x, y, h);
	}
	glEnd();

	// podstawa gorna
	glBegin(GL_TRIANGLE_FAN);
	glNormal3d(0, 0, 1);
	glVertex3d(0, 0, h);
	for (alpha = 0.0; alpha >= -(2 * GL_PI); alpha -= GL_PI / rozdzielczosc) {
		x = r * sin(alpha);
		y = r * cos(alpha);
		glVertex3d(x, y, h);
	}
	glEnd();
}

void ramie(const double r1, const double r2, const double h, const double d) {
	double x, y, alpha;
	const double rozdzielczosc = 16;
	// PIERWSZY POLWALEC
	//dolna podstawa
	glBegin(GL_TRIANGLE_FAN);
	glNormal3d(0, 0, -1);
	glVertex3d(0, 0, 0);
	for (alpha = GL_PI; alpha <= 2 * GL_PI; alpha += GL_PI / rozdzielczosc) {
		x = r1 * sin(alpha);
		y = r1 * cos(alpha);
		glVertex3d(x, y, 0);
	}
	glEnd();
	// sciana boczna
	glBegin(GL_QUAD_STRIP);
	for (alpha = GL_PI; alpha <= 2 * GL_PI; alpha += GL_PI / rozdzielczosc) {
		x = r1 * sin(alpha);
		y = r1 * cos(alpha);
		glNormal3d(sin(alpha), cos(alpha), 0.0);
		glVertex3d(x, y, 0);
		glVertex3d(x, y, h);
	}
	glEnd();
	// podstawa gorna
	glBegin(GL_TRIANGLE_FAN);
	glNormal3d(0, 0, 1);
	glVertex3d(0, 0, h);
	for (alpha = 0.0; alpha >= -GL_PI; alpha -= GL_PI / rozdzielczosc) {
		x = r1 * sin(alpha);
		y = r1 * cos(alpha);
		glVertex3d(x, y, h);
	}
	glEnd();

	// DRUGI POLWALEC
	//dolna podstawa
	glBegin(GL_TRIANGLE_FAN);
	glNormal3d(0, 0, -1);
	glVertex3d(d, 0, 0);
	for (alpha = 0; alpha <= GL_PI; alpha += GL_PI / rozdzielczosc) {
		x = r2 * sin(alpha) + d;
		y = r2 * cos(alpha);
		glVertex3d(x, y, 0);
	}
	glEnd();
	// sciana boczna
	glBegin(GL_QUAD_STRIP);
	for (alpha = 0; alpha <= GL_PI; alpha += GL_PI / rozdzielczosc) {
		x = r2 * sin(alpha) + d;
		y = r2 * cos(alpha);
		glNormal3d(sin(alpha), cos(alpha), 0.0);
		glVertex3d(x, y, 0);
		glVertex3d(x, y, h);
	}
	glEnd();
	// podstawa gorna
	glBegin(GL_TRIANGLE_FAN);
	glNormal3d(0, 0, 1);
	glVertex3d(d, 0, h);
	for (alpha = -GL_PI; alpha >= -2 * GL_PI; alpha -= GL_PI / rozdzielczosc) {
		x = r2 * sin(alpha) + d;
		y = r2 * cos(alpha);
		glVertex3d(x, y, h);
	}
	glEnd();

	// wielok¹ty miêdzy pó³walcami

	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glVertex3d(d, r2, h);
	glVertex3d(0, r1, h);
	glVertex3d(0, -r1, h);
	glVertex3d(d, -r2, h);

	float v[3][3] = {
		{ d, -r2, h },
		{ 0, -r1, h },
		{ 0, -r1, 0 }
	};
	float norm[3];
	calcNormal(v, norm);
	glNormal3f(norm[0], norm[1], norm[2]);
	glVertex3d(d, -r2, h);
	glVertex3d(0, -r1, h);
	glVertex3d(0, -r1, 0);
	glVertex3d(d, -r2, 0);

	glNormal3d(0, 0, -1);
	glVertex3d(d, -r2, 0);
	glVertex3d(0, -r1, 0);
	glVertex3d(0, r1, 0);
	glVertex3d(d, r2, 0);

	float v2[3][3] = {
		{ d, r2, 0 },
		{ 0, r1, 0 },
		{ 0, r1, h }
	};
	calcNormal(v2, norm);
	glNormal3d(norm[0], norm[1], norm[2]);
	glVertex3d(d, r2, 0);
	glVertex3d(0, r1, 0);
	glVertex3d(0, r1, h);
	glVertex3d(d, r2, h);
	glEnd();
}

void zabawka(const bool glowa = true, const bool rece = true) {
	glColor3d(0.1, 0.3, 0.5);
	const double dlugoscNogi = 25;

	const double wysokoscKorpusu = 30;
	const double gruboscKorpusu = 10;
	const double szerokoscKorpusu = 35;

	const double wysokoscGlowy = 20;
	const double szerokoscGlowy = szerokoscKorpusu - 10;

	// noga robota
	glPushMatrix();
	glTranslated(1, 0, 0);
	prostopadloscian(8, dlugoscNogi, 10);
	glPopMatrix();

	// noga robota
	glPushMatrix();
	glTranslated(1, 0, 15);
	prostopadloscian(8, dlugoscNogi, 10);
	glPopMatrix();

	// korpus robota
	glPushMatrix();
	glTranslated(0, dlugoscNogi, -5);
	prostopadloscian(gruboscKorpusu, wysokoscKorpusu, szerokoscKorpusu);
	glPopMatrix();

	if (glowa) {
		// glowa robota
		glPushMatrix();

		glTranslated(0, dlugoscNogi + wysokoscKorpusu, 0);
		prostopadloscian(gruboscKorpusu, wysokoscGlowy, szerokoscGlowy);
		// lewe oko
		glPushMatrix();
		glColor3d(1, 0, 0);
		glTranslated(gruboscKorpusu, wysokoscGlowy - 8, 6);
		glRotated(90, 0, 1, 0);
		walec(1, 3);
		glPopMatrix();
		// prawe oko
		glPushMatrix();
		glColor3d(1, 0, 0);
		glTranslated(gruboscKorpusu, wysokoscGlowy - 8, szerokoscGlowy - 6);
		glRotated(90, 0, 1, 0);
		walec(1, 3);
		glPopMatrix();

		glPopMatrix();
	}

	if (rece) {
		glColor3d(0.1, 0.3, 0.5);
		// lewe ramie robota
		glPushMatrix();
		glTranslated(5, dlugoscNogi + wysokoscKorpusu - 10, -10);
		glRotated(rotA, 0, 0, 1);
		ramie(5, 5, 5, 8);
		glTranslated(12, 0, 0);
		glRotated(rotB, 0, 0, 1);
		ramie(5, 5, 5, 8);
		glPopMatrix();

		// prawe ramie robota
		glPushMatrix();
		glTranslated(5, dlugoscNogi + wysokoscKorpusu - 10, -5 + szerokoscKorpusu);
		glRotated(rotA, 0, 0, 1);
		ramie(5, 5, 5, 8);
		glTranslated(12, 0, 0);
		glRotated(rotB, 0, 0, 1);
		ramie(5, 5, 5, 8);
		glPopMatrix();
	}
}

void tasmociag() {
	double szerokoscTasmociagu = 50;

	glDisable(GL_CULL_FACE);
	glPolygonMode(GL_BACK, GL_FILL);

	// gora
	glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);

	for (int i = 0; i < 40; ++i) {
		if (i % 2 == 0) {
			glColor3d(0, 0, 0);
		}
		else {
			glColor3d(0.2, 0.2, 0.2);
		}
		glVertex3d(-500 + static_cast<double>(i) * 30 + 30 + tasmociagStartPos, 35, szerokoscTasmociagu);
		glVertex3d(-500 + static_cast<double>(i) * 30 + 30 + tasmociagStartPos, 35, 0);
		glVertex3d(-500 + static_cast<double>(i) * 30 + tasmociagStartPos, 35, 0);
		glVertex3d(-500 + static_cast<double>(i) * 30 + tasmociagStartPos, 35, szerokoscTasmociagu);
	}
	glEnd();

	// dol
	glBegin(GL_QUADS);
	glNormal3d(0, -1, 0);

	for (int i = 0; i < 40; ++i) {
		if (i % 2 == 0) {
			glColor3d(0, 0, 0);
		}
		else {
			glColor3d(0.2, 0.2, 0.2);
		}
		glVertex3d(-500 + static_cast<double>(i) * 30 - tasmociagStartPos, 5, szerokoscTasmociagu);
		glVertex3d(-500 + static_cast<double>(i) * 30 - tasmociagStartPos, 5, 0);
		glVertex3d(-500 + static_cast<double>(i) * 30 + 30 - tasmociagStartPos, 5, 0);
		glVertex3d(-500 + static_cast<double>(i) * 30 + 30 - tasmociagStartPos, 5, szerokoscTasmociagu);
	}
	glEnd();

	// zabawki
	for (int i = 0; i < 40; i += 2) {
		glPushMatrix();
		glTranslated(-500 + static_cast<double>(i) * 30 + tasmociagStartPos, 36, 12.5);
		if (i > 10) {
			zabawka(true, true);
		}
		else {
			zabawka(false, false);
		}
		glPopMatrix();
	}

	glPolygonMode(GL_BACK, GL_LINE);
	glEnable(GL_CULL_FACE);
}

void robot(const double d1, const double d2, const double d3) {
	glColor3d(1, 0.5, 0);

	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glTranslated(0, 0, -50);

	walec(5, 30);

	glTranslated(0, 0, 5);
	walec(40, 10);

	// i
	glTranslated(0, 0, 40);
	glRotated(d1, 0, 0, 1);
	walec(40, 10);
	// l
	glTranslated(0, 0, 40);
	glRotated(90, 0, 1, 0);
	glTranslated(0, 0, -20);
	// m
	walec(40, 10);
	// n
	glTranslated(0, 0, +40);
	glRotated(90 + d2, 0, 0, 1);
	ramie(15, 10, 5, 30);
	// o
	glTranslated(30, 0, -5);
	glRotated(d3, 0, 0, 1);
	ramie(15, 10, 5, 30);

	glPopMatrix();
}

void ur16e() {
	double rotacjaDolu = 5;

	glPushMatrix();

	glRotated(-90, 1, 0, 0);
	walec(5, 12);
	glTranslated(0, 0, 5);
	glRotated(rotacjaDolu, 0, 0, 1);
	walec(30, 10);

	/*glTranslated(0, 30, 0);
	glRotated(90, 1, 0, 0);
	walec(40, 10);
	glTranslated(0, 30, 0);
	glRotated(90, 1, 0, 0);
	walec(90, 10);
	*/
	glPopMatrix();
}

void dwa_roboty() {
	glPushMatrix();
	robot(rot1, rot2, rot3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(100, 0, 0);
	robot(rot1, rot2, rot3);
	glPopMatrix();
}
