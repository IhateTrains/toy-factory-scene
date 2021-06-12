#include "Objects.h"
#include "Normal.h"

#include <Windows.h>            // Window defines
#include <gl/GL.h>              // OpenGL
#include <gl/GLU.h>             // GLU library
#include <cmath>				// Define for sqrt


constexpr auto GL_PI = 3.14;

void podloga() {
	glColor3d(1, 1, 1);
	glEnable(GL_TEXTURE_2D); // W³¹cz teksturowanie
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glBegin(GL_QUADS);

	glNormal3d(0, 1, 0);
	int k = 3;
	double f = 50;
	glTexCoord2d(0.0, 0.0); glVertex3d(-k * 128, 0, -k * 128);
	glTexCoord2d(0.0, f); glVertex3d(-k * 128, 0, k * 128);
	glTexCoord2d(f, f); glVertex3d(k * 128, 0, k * 128);
	glTexCoord2d(f, 0.0); glVertex3d(k * 128, 0, -k * 128);

	glEnd();

	glDisable(GL_TEXTURE_2D); // Wy³¹cz teksturowanie
}

void sciany() {

	glDisable(GL_CULL_FACE);
	glPolygonMode(GL_BACK, GL_FILL);

	glColor3d(0.5, 0.5, 0.5);
	glEnable(GL_TEXTURE_2D); // W³¹cz teksturowanie
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	double f = 1;
	glBegin(GL_QUADS);

	glNormal3d(0, 0, 1);
	glTexCoord2d(0.0, 0.0); glVertex3d(-640, 300, -320);
	glTexCoord2d(0.0, f); glVertex3d(-640, 0, -320);
	glTexCoord2d(f, f); glVertex3d(640, 0, -320);
	glTexCoord2d(f, 0.0); glVertex3d(640, 300, -320);




	glEnd();

	glDisable(GL_TEXTURE_2D); // Wy³¹cz teksturowanie


	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_BACK, GL_LINE);
}

void skrzynka(void)
{
	glColor3d(0.8, 0.7, 0.3);


	glEnable(GL_TEXTURE_2D); // W³¹cz teksturowanie

	glBindTexture(GL_TEXTURE_2D, texture[0]);
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

	glDisable(GL_TEXTURE_2D); // Wy³¹cz teksturowanie



	glBegin(GL_QUADS);
	glNormal3d(0, 0, -1);
	glVertex3d(25, 25, -25);
	glVertex3d(25, -25, -25);
	glVertex3d(-25, -25, -25);
	glVertex3d(-25, 25, -25);

	glNormal3d(-1, 0, 0);
	glVertex3d(-25, 25, -25);
	glVertex3d(-25, -25, -25);
	glVertex3d(-25, -25, 25);
	glVertex3d(-25, 25, 25);

	glNormal3d(0, 1, 0);
	glVertex3d(25, 25, 25);
	glVertex3d(25, 25, -25);
	glVertex3d(-25, 25, -25);
	glVertex3d(-25, 25, 25);

	glNormal3d(0, -1, 0);
	glVertex3d(25, -25, 25);
	glVertex3d(-25, -25, 25);
	glVertex3d(-25, -25, -25);
	glVertex3d(25, -25, -25);
	glEnd();
}

void walec01(void)
{
	GLUquadricObj* obj;
	obj = gluNewQuadric();
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

void kula(void)
{
	GLUquadricObj* obj;
	obj = gluNewQuadric();
	gluQuadricTexture(obj, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glColor3d(1.0, 0.8, 0.8);
	glEnable(GL_TEXTURE_2D);
	gluSphere(obj, 40, 15, 7);
	glDisable(GL_TEXTURE_2D);
}

void szescian() {
	int a = 20;
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

void prostopadloscian(double dlugosc, double wysokosc, double szerokosc) {
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glVertex3d(dlugosc, 0, szerokosc);
	glVertex3d(dlugosc, wysokosc, szerokosc);
	glVertex3d(0, wysokosc, szerokosc);
	glVertex3d(0, 0, szerokosc);

	glNormal3d(0, 0, -1);
	glVertex3d(0, 0, 0);
	glVertex3d(0, wysokosc, 0);
	glVertex3d(dlugosc, wysokosc, 0);
	glVertex3d(dlugosc, 0, 0);
	glEnd();
	glBegin(GL_QUAD_STRIP);
	glNormal3d(1, 0, 0);
	glVertex3d(dlugosc, wysokosc, 0);
	glVertex3d(dlugosc, wysokosc, szerokosc);
	glVertex3d(dlugosc, 0, 0);
	glVertex3d(dlugosc, 0, szerokosc);

	glNormal3d(0, -1, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, szerokosc);

	glNormal3d(-1, 0, 0);
	glVertex3d(0, wysokosc, 0);
	glVertex3d(0, wysokosc, szerokosc);

	glNormal3d(0, 1, 0);
	glVertex3d(dlugosc, wysokosc, 0);
	glVertex3d(dlugosc, wysokosc, szerokosc);
	glEnd();
}

void walec(double h, double r) {
	double x, y, alpha;
	double rozdzielczosc = 16;
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

void ramie(double r1, double r2, double h, double d) {
	double x, y, alpha;
	double rozdzielczosc = 16;
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
	glNormal3d(norm[0], norm[1], norm[2]);
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

void zabawka() {
	glColor3d(0.1, 0.3, 0.5);
	double dlugoscNogi = 25;

	double wysokoscKorpusu = 30;
	double gruboscKorpusu = 10;
	double szerokoscKorpusu = 35;

	double wysokoscGlowy = 20;
	double szerokoscGlowy = szerokoscKorpusu - 10;

	glPushMatrix();
	// noga robota
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

	glColor3d(0.1, 0.3, 0.5);
	// lewe ramie robota
	glPushMatrix();
	glTranslated(5, dlugoscNogi + wysokoscKorpusu - 10, -10);
	glRotated(rot2, 0, 0, 1);
	ramie(5, 5, 5, 8);
	glTranslated(12, 0, 0);
	glRotated(rot3, 0, 0, 1);
	ramie(5, 5, 5, 8);
	glPopMatrix();

	// prawe ramie robota
	glPushMatrix();
	glTranslated(5, dlugoscNogi + wysokoscKorpusu - 10, -5 + szerokoscKorpusu);
	glRotated(rot2, 0, 0, 1);
	ramie(5, 5, 5, 8);
	glTranslated(12, 0, 0);
	glRotated(rot3, 0, 0, 1);
	ramie(5, 5, 5, 8);
	glPopMatrix();
}

void tasmociag() {
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
		glVertex3d(-1000 + (double)i * 30 + 30 + tasmociagStartPos, 35, 50);
		glVertex3d(-1000 + (double)i * 30 + 30 + tasmociagStartPos, 35, 0);
		glVertex3d(-1000 + (double)i * 30 + tasmociagStartPos, 35, 0);
		glVertex3d(-1000 + (double)i * 30 + tasmociagStartPos, 35, 50);
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
		glVertex3d(-500 + (double)i * 30 - tasmociagStartPos, 5, 50);
		glVertex3d(-500 + (double)i * 30 - tasmociagStartPos, 5, 0);
		glVertex3d(-500 + (double)i * 30 + 30 - tasmociagStartPos, 5, 0);
		glVertex3d(-500 + (double)i * 30 + 30 - tasmociagStartPos, 5, 50);
	}
	glEnd();

	// zabawki
	for (int i = 0; i < 40; i += 2) {
		glPushMatrix();
		glTranslated(-1000 + (double)i * 30 + tasmociagStartPos, 36, 10);
		zabawka();
		glPopMatrix();
	}

	glPolygonMode(GL_BACK, GL_LINE);
	glEnable(GL_CULL_FACE);
}

void robot(double d1, double d2, double d3) {
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

void dwa_roboty() {
	glPushMatrix();
	robot(rot1, rot2, rot3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(100, 0, 0);
	robot(rot1, rot2, rot3);
	glPopMatrix();
}
