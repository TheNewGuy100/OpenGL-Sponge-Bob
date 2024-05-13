
#include "./main.cpp"
#include "./colorPicker.h"


void BasicObjectsDraw(float offsetX, float offsetY, float offsetZ) {
	
	glColor3f(red, green, blue);
 	glPushMatrix ();
 		glTranslatef (offsetX + 5, offsetY + 0, offsetZ + 5);
 		glutSolidSphere (2, 10, 7);
	glPopMatrix ();
	
	UpdateColorPick();
	
	glColor3f(red, green, blue);
	glPushMatrix ();
		glTranslatef (offsetX + 10, offsetY + 0, offsetZ + 3);
		glutSolidCone (2, 5, 10, 7);
	glPopMatrix ();
	
	UpdateColorPick();
	
	glColor3f(red, green, blue);
	glPushMatrix ();
		glTranslatef (offsetX + 15, offsetY + 0, offsetZ + 5);
		glutSolidOctahedron();
	glPopMatrix ();
	
	UpdateColorPick();
	
	glColor3f(red, green, blue);
	glPushMatrix();
		glTranslatef (offsetX + 0, offsetY + -5, offsetZ + 5);
		glRotatef(90, 0.0f, 1.0f, 0.0f);
		glRotatef(90, 0.0f, 0.0f, 1.0f);
		glutSolidTetrahedron ();
	glPopMatrix ();	
	
	UpdateColorPick();	
	
	glColor3f(red, green, blue);
	glPushMatrix ();
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 10);
		glRotatef(90, 1.0f, 0.0f, 0.0f);
		glutSolidTorus (1, 3, 5, 10);
	glPopMatrix ();
	
	UpdateColorPick();
	
	glColor3f(red, green, blue);
	glPushMatrix ();
		glTranslatef (offsetX + -5, offsetY + 0, offsetZ + 5);
		glutSolidIcosahedron();
	glPopMatrix ();
	
	UpdateColorPick();
	
	glColor3f(red, green, blue);
	glPushMatrix ();
		glTranslatef (offsetX + -10, offsetY + 0, offsetZ + 5);
		glutSolidCube(2);
	glPopMatrix ();
	
	UpdateColorPick();
	
	glColor3f(red, green, blue);
	glPushMatrix ();
		glTranslatef (offsetX + -15, offsetY + 0, offsetZ + 5);
		glutSolidDodecahedron();
	glPopMatrix ();
}
