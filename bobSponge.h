
#ifndef BOBSPONGE_H
#define BOBSPONGE_H

#include <freeglut.h>
#include <glut.h>

//	------------------------------------------- LEG SCRIPT -------------------------------------------
	
void drawCylinder(float radius, float height, int sides, float offsetX, float offsetY, float offsetZ) {
	glPushMatrix();
		glColor3f(0.42, 0.18, 0.08);
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 6.25);
		
    	float angleStep = 2.0 * 3.14 / sides;
    
	    glBegin(GL_TRIANGLE_STRIP);
	    
	    for (int i = 0; i <= sides; ++i) {
	    	
	        float angle = i * angleStep;
	        float x = radius * cos(angle);
	        float y = radius * sin(angle);
	        
	        glVertex3f(x, y, height / 2.0);
	        glVertex3f(x, y, -height / 2.0);
	    }
	    
	    glEnd();
	glPopMatrix();
}

void drawCircle(float radius, int sides, float offsetX, float offsetY, float offsetZ, float rotateX, float rotateY, float rotateZ, float colorR, float colorG, float colorB) {
    float angleStep = 2.0 * M_PI / sides;
    
    glPushMatrix();
		glColor3f(colorR, colorG, colorB);
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 0);
	    glRotatef(90.0f, rotateX, rotateY, rotateZ);
	    
	    glBegin(GL_TRIANGLE_FAN);
	    
		    glVertex2f(0.0, 0.0); // Center vertex
		    
		    for (int i = 0; i <= sides; ++i)
		    {
		        float angle = i * angleStep;
		        float x = radius * cos(angle);
		        float y = radius * sin(angle);
		        
		        glVertex2f(x, y);
		    }
	    
	    glEnd();
	glPopMatrix();
}
	
	
void BobSpongeLegScript(float offsetX, float offsetY, float offsetZ) {
	// LEG L
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 7.75);
		glColor3f(1, 0.95, 0.08);
		glScalef(1.0f, 1.0f, 3.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	// SOCK L PART 1
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 3);
		glColor3f(1, 1, 1);
		glScalef(1.0f, 1.0f, 8.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	// SOCK MARK RED L
	glPushMatrix ();

		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 5.25);
		glColor3f(0.89f, 0.21f, 0.12f);
		glScalef(1.0f, 1.0f, 1.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	// SOCK L PART 2
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 5.75);
		glColor3f(1, 1, 1);
		glScalef(1.0f, 1.0f, 1.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	
	// SOCK MARK BLUE L
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 6.25);
		glColor3f(0.05f, 0.30f, 0.60f);
		glScalef(1.0f, 1.0f, 1.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	// SOCK L PART 3
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 6.75);
		glColor3f(1, 1, 1);
		glScalef(1.0f, 1.0f, 1.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	// BOOT L
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -0.5, offsetZ + 0.5);
		glColor3f(0, 0, 0);
		glScalef(2.0f, 6.0f, 2.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -2, offsetZ + 0.5);
		glColor3f(0, 0, 0);
		glScalef(0.7, 1.3, 0.9);
		glutSolidSphere(1, 12, 7);
		
	glPopMatrix ();
	
	// LEG PANTS
	drawCylinder(1.0, 1.0, 12, offsetX, 0, 2);
	
}

// ----------------------------------- DRAW BODY ---------------------------------------------------
void DrawSpongeBobBody(float offsetX, float offsetY, float offsetZ) {
	
	//	PANTS
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -0.5, offsetZ + 0.5);
		glColor3f(0.47, 0.23, 0.08);
		glScalef(2, 1.6f, 0.8f);
		glutSolidCube(3.0f);
		
	glPopMatrix ();
	
	//	SHIRT
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -0.5, offsetZ + 2.3);
		glColor3f(1, 1, 1);
		glScalef(2, 1.6f, 0.4f);
		glutSolidCube(3.0f);
		
	glPopMatrix ();
	
	//	BODY
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -0.5, offsetZ + 6.6);
		glColor3f(1, 0.95, 0.08);
		glScalef(2.1f, 1.7f, 2.5f);
		glutSolidCube(3.0f);
		
	glPopMatrix ();
	
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -0.5, offsetZ + 6.6);
		glColor3f(1, 0.95, 0.08);
		glScalef(2.1f, 1.7f, 2.5f);
		glutSolidCube(3.0f);
		
	glPopMatrix ();
	
	// PANTS MARKS
		glPushMatrix ();
			glTranslatef (offsetX + -2, offsetY + -3, offsetZ + 3.7);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glScalef(1, 1, 1.5);
			glColor3f(0, 0, 0);
			
			glBegin(GL_QUADS);
				glVertex3f(-1.0, 0, 0.0);
				glVertex3f(-1.0, 0, 1.0);
				glVertex3f(-3.0, 0, 0.0);
				glVertex3f(-3.0, 0, 1.0);
			glEnd();
			
		glPopMatrix ();
		
		glPushMatrix ();
			glTranslatef (offsetX + -1.85, offsetY + -3.001, offsetZ + 3.65);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glScalef(0.93, 0.8, 1.3);
			glColor3f(1, 1, 1);
			
			glBegin(GL_QUADS);
				glVertex3f(-1.0, 0, 0.0);
				glVertex3f(-1.0, 0, 1.0);
				glVertex3f(-3.0, 0, 0.0);
				glVertex3f(-3.0, 0, 1.0);
			glEnd();
			
		glPopMatrix ();
		
	// STRIPS FRONT / BACK
	glPushMatrix ();
			glTranslatef (offsetX + -3.55, offsetY + -3, offsetZ + 0.7);
			glScalef(0.65, 1, 0.7);
			glColor3f(0, 0, 0);
			
			glBegin(GL_QUADS);
				glVertex3f(1.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 1.0);
				glVertex3f(1.0, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(3.5, 0.0, 0.0);
				glVertex3f(5.5, 0.0, 0.0);
				glVertex3f(5.5, 0.0, 1.0);
				glVertex3f(3.5, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(6, 0.0, 0.0);
				glVertex3f(8, 0.0, 0.0);
				glVertex3f(8, 0.0, 1.0);
				glVertex3f(6, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(8.5, 0.0, 0.0);
				glVertex3f(10, 0.0, 0.0);
				glVertex3f(10, 0.0, 1.0);
				glVertex3f(8.5, 0.0, 1.0);
			glEnd();
	glPopMatrix ();
	
	glPushMatrix ();
			glTranslatef (offsetX + -3.55, offsetY + 2, offsetZ + 0.7);
			glScalef(0.65, 1, 0.7);
			glColor3f(0, 0, 0);
			
			glBegin(GL_QUADS);
				glVertex3f(1.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 1.0);
				glVertex3f(1.0, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(3.5, 0.0, 0.0);
				glVertex3f(5.5, 0.0, 0.0);
				glVertex3f(5.5, 0.0, 1.0);
				glVertex3f(3.5, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(6, 0.0, 0.0);
				glVertex3f(8, 0.0, 0.0);
				glVertex3f(8, 0.0, 1.0);
				glVertex3f(6, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(8.5, 0.0, 0.0);
				glVertex3f(10, 0.0, 0.0);
				glVertex3f(10, 0.0, 1.0);
				glVertex3f(8.5, 0.0, 1.0);
			glEnd();
	glPopMatrix ();
	
	// STRIP SIDES LEFT
	glPushMatrix ();
		glTranslatef (offsetX + -3.1, offsetY + -4, offsetZ + 0.7);
		glRotatef(90, 0.0, 0.0, 1.0);
		glScalef(0.65, 1, 0.7);
		glColor3f(0, 0, 0);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(3.5, 0.0, 0.0);
			glVertex3f(5.5, 0.0, 0.0);
			glVertex3f(5.5, 0.0, 1.0);
			glVertex3f(3.5, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(6, 0.0, 0.0);
			glVertex3f(8, 0.0, 0.0);
			glVertex3f(8, 0.0, 1.0);
			glVertex3f(6, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(8.5, 0.0, 0.0);
			glVertex3f(9, 0.0, 0.0);
			glVertex3f(9, 0.0, 1.0);
			glVertex3f(8.5, 0.0, 1.0);
		glEnd();
	glPopMatrix ();
	
	// STRIP SIDES RIGHT
	glPushMatrix ();
		glTranslatef (offsetX + 3.1, offsetY + -4, offsetZ + 0.7);
		glRotatef(90, 0.0, 0.0, 1.0);
		glScalef(0.65, 1, 0.7);
		glColor3f(0, 0, 0);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(3.5, 0.0, 0.0);
			glVertex3f(5.5, 0.0, 0.0);
			glVertex3f(5.5, 0.0, 1.0);
			glVertex3f(3.5, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(6, 0.0, 0.0);
			glVertex3f(8, 0.0, 0.0);
			glVertex3f(8, 0.0, 1.0);
			glVertex3f(6, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(8.5, 0.0, 0.0);
			glVertex3f(9, 0.0, 0.0);
			glVertex3f(9, 0.0, 1.0);
			glVertex3f(8.5, 0.0, 1.0);
		glEnd();
	glPopMatrix ();
	
	glPushMatrix ();
		glTranslatef (offsetX + -0.5, offsetY + -3.1, offsetZ + 3.45);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(0.6, 1, 1);
		glColor3f(1, 0, 0);
	
		glBegin(GL_QUADS);
			glVertex3f(1, 0.0, 0);
			glVertex3f(3, 0.0, 0.2);
			glVertex3f(3, 0.0, 0.7);
			glVertex3f(1, 0.0, 1);
		glEnd();
	glPopMatrix ();
	
		glPushMatrix ();
		glTranslatef (offsetX + -0.35, offsetY + -3.1, offsetZ + 2.65);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(1, 1, 0.6);
		glColor3f(1, 0, 0);
	
		glBegin(GL_QUADS);
			glVertex3f(1, 0.0, 0);
			glVertex3f(3, 0.0, 0);
			glVertex3f(3, 0.0, 1);
			glVertex3f(1, 0.0, 1);
		glEnd();
	glPopMatrix ();
}


// ----------------------------------- DRAW EYE SCRIPT -----------------------------------------------

void DrawSpongeBobEyeLashes(float offsetX, float offsetY, float offsetZ) {
		glPushMatrix ();
			glTranslatef (offsetX + -2.4, offsetY + -2.6, offsetZ + 18.5);
			glColor3f(0, 0, 0);
			glScalef(0.3f, 0.3f, 0.3f);
			glRotatef(45, 0.0, 1.0, 0.0);
			
			glBegin(GL_QUADS);
				glVertex3f(1.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 1.0);
				glVertex3f(1.0, 0.0, 1.0);
			glEnd();
		
		glPopMatrix ();
		
		glPushMatrix ();
			glTranslatef (offsetX + -1.4, offsetY + -2.6, offsetZ + 19);
			glColor3f(0, 0, 0);
			glScalef(0.3f, 0.3f, 0.3f);
			glRotatef(90, 0.0, 1.0, 0.0);
			
			glBegin(GL_QUADS);
				glVertex3f(1.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 1.0);
				glVertex3f(1.0, 0.0, 1.0);
			glEnd();
		
		glPopMatrix ();
		
		
		glPushMatrix ();
			glTranslatef (offsetX + -0.9, offsetY + -2.6, offsetZ + 17.7);
			glColor3f(0, 0, 0);
			glScalef(0.3f, 0.3f, 0.3f);
			glRotatef(-45, 0.0, 1.0, 0.0);
			
			glBegin(GL_QUADS);
				glVertex3f(1.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 1.0);
				glVertex3f(1.0, 0.0, 1.0);
			glEnd();
		
		glPopMatrix ();
}

void DrawMouth( float offsetX, float offsetY, float offsetZ ) {
	
	// BELZIER CURVE FOR MOUTH
	glPushMatrix ();
		glTranslatef (offsetX + 0, offsetY + -2.63, offsetZ + 14.5);
		glColor3f(0, 0, 0);
		glScalef(3.5, 3.5, 2.5);
		glRotatef(-90, 1, 0, 0);
	
	    glBegin(GL_LINE_STRIP);
	    glVertex2f(-0.5f, 0.0f); // Starting point
	    
	    // Control point
	    float controlPointX = 0.0f;
	    float controlPointY = 0.5f;
	    
	    // Ending point
	    float endPointX = 0.5f;
	    float endPointY = 0.0f;
	    
	    for (int i = 1; i <= 20; ++i)
	    {
	        float t = static_cast<float>(i) / 20.0f;
	        float oneMinusT = 1.0f - t;
	        
	        float x = oneMinusT * oneMinusT * -0.5f + 2.0f * oneMinusT * t * controlPointX + t * t * endPointX;
	        float y = oneMinusT * oneMinusT * 0.0f + 2.0f * oneMinusT * t * controlPointY + t * t * endPointY;
	        
	        glVertex2f(x, y);
	    }
	    
	    glEnd();
    glPopMatrix ();
    
    // TEETH L 
    glPushMatrix ();
		glTranslatef (offsetX + -2, offsetY + -2.6, offsetZ + 12.9);
		glScalef(0.65, 1, 1);
		glColor3f(0, 0, 0);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
    glPopMatrix ();
    
    glPushMatrix ();
		glTranslatef (offsetX + -1.75, offsetY + -2.61, offsetZ + 13);
		glScalef(0.55, 1, 0.90);
		glColor3f(1, 1, 1);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
    glPopMatrix ();
    
    // TEETH R
    glPushMatrix ();
		glTranslatef (offsetX + -1.3, offsetY + -2.6, offsetZ + 12.9);
		glScalef(0.65, 1, 1);
		glColor3f(0, 0, 0);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
    glPopMatrix ();
    
    glPushMatrix ();
		glTranslatef (offsetX + -1.05, offsetY + -2.61, offsetZ + 13);
		glScalef(0.55, 1, 0.90);
		glColor3f(1, 1, 1);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
    glPopMatrix ();
}

void DrawSpongeBobEye(float offsetX, float offsetY, float offsetZ) {
	// EYES
		// EYE LINE
		drawCircle(1.25, 18, -1.22, -2.6, 17, 1.0f, 0 , 0, 0, 0, 0);
		drawCircle(1.25, 18, 1.22, -2.6, 17, 1.0f, 0 , 0, 0, 0, 0);
		
		// EYE INNER
		drawCircle(1.15, 18, -1.22, -2.61, 17, 1.0f, 0 , 0, 1, 1, 1);
		drawCircle(1.15, 18, 1.22, -2.61, 17, 1.0f, 0 , 0, 1, 1, 1);
		
		// EYE BORDER
		drawCircle(0.65, 18, -1.22, -2.62, 17, 1.0f, 0 , 0, 0, 0, 0);
		drawCircle(0.65, 18, 1.22, -2.62, 17, 1.0f, 0 , 0, 0, 0, 0);
		
		// EYE IRIS
		drawCircle(0.60, 18, -1.22, -2.63, 17, 1.0f, 0 , 0, 0.40, 0.74, 0.88);
		drawCircle(0.60, 18, 1.22, -2.63, 17, 1.0f, 0 , 0, 0.40, 0.74, 0.88);
		
		// EYE INNER
		drawCircle(0.35, 18, -1.22, -2.64, 17, 1.0f, 0 , 0, 0, 0, 0);
		drawCircle(0.35, 18, 1.22, -2.64, 17, 1.0f, 0 , 0, 0, 0, 0);
		
		DrawSpongeBobEyeLashes( 0, 0, 0);
		DrawSpongeBobEyeLashes( 2.5, 0, 0);
}

// ----------------------------------- DRAW ARM SCRIPT -----------------------------------------------

void DrawSpongeBobArmNoAnimation(float offsetX, float offsetY, float offsetZ) {
	// ARM
	glPushMatrix ();
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 11.75);
		glColor3f(1, 0.95, 0.08);
		glScalef(1.0f, 1.0f, 11.0f);
		
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 14);
		glColor3f(1, 1, 1);
		glScalef(2.0f, 2.0f, 2.0f);
		glutSolidSphere(0.5, 12, 7);
		
	glPopMatrix ();
}

float armPositionX = -3.5;
float armPositionY = 0;
float armPositionZ = 11.75;

float armScaleX = 1.0;
float armScaleY = 1.0;
float armScaleZ = 11.0;

float armAnimObjectivePosition = 11.75;
float armAnimObjectiveRotation = 1;

int runningOrBacking = 0;

void DrawSpongeBobArm(float offsetX, float offsetY, float offsetZ) {
	// ARM
	glPushMatrix ();
		glTranslatef (armPositionX, offsetY + armPositionY, offsetZ + armPositionZ);
		glColor3f(1, 0.95, 0.08);
		glScalef(armScaleX, armScaleY, armScaleZ);
		
		glRotatef(armAnimObjectiveRotation, 0, 1, 0);
		
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 14);
		glColor3f(1, 1, 1);
		glScalef(2.0f, 2.0f, 2.0f);
		glutSolidSphere(0.5, 12, 7);
		
	glPopMatrix ();
}

// ----------------------------------- ARM ANIMATION ------------------------------------------------

void AnimateSpongeBobArm() {
	
	if (runningOrBacking == 0) {
		armAnimObjectiveRotation += 1;
		
		if (armAnimObjectiveRotation >= 90) {
			armPositionX -= 0.02;
			armPositionZ += 0.01;
			
			armScaleX -= 0.12;
			armScaleZ += 0.06;
			
			
		} else {
			armScaleX += 0.22;
			armScaleZ -= 0.12;
			
			armPositionX -= 0.01;
			armPositionZ += 0.025;
			
		}
		
		if (armAnimObjectiveRotation >= 135.0) {
			runningOrBacking = 1;
		}
		
	} else {
		armAnimObjectiveRotation -= 1;
		
		if (armAnimObjectiveRotation >= 90) {
			armPositionX += 0.02;
			armPositionZ -= 0.01;
			
			armScaleX += 0.12;
			armScaleZ -= 0.06;
			
			
		} else {
			armScaleX -= 0.22;
			armScaleZ += 0.12;
			
			armPositionX += 0.01;
			armPositionZ -= 0.025;
		}
		
		
		
		if (armAnimObjectiveRotation == 1.0) {
			runningOrBacking = 0;
		}
	}
	
}


// ----------------------------------- BUILD SPONGE BOB SCRIPT ---------------------------------------

void BobEsponjaScriptDraw(float offsetX, float offsetY, float offsetZ) {
	
	glPushMatrix ();
		glTranslatef (offsetX, offsetY, offsetZ + 0.1);
		// DRAW FLOOR
		glBegin(GL_QUADS);
			glColor3f(0.31f, 0.40f, 0.37f);
			glVertex3f(12.0, -12.0, 0.0);
			glVertex3f(-12.0, -12.0, 0.0);
			glVertex3f(-12.0, 12.0, 0.0);
			glVertex3f(12.0, 12.0, 0.0);
		glEnd();
	glPopMatrix ();
	
	BobSpongeLegScript( -1.5, 0, 0);
	BobSpongeLegScript( 1.5, 0, 0);
	DrawSpongeBobBody( 0, 0.5, 9.2);
	DrawSpongeBobArm( -3.5, 0, 0);
	DrawSpongeBobArmNoAnimation(3.5, 0, 0);
	DrawSpongeBobEye(offsetX, offsetY, offsetZ);
	
	DrawMouth(0,0,0);
}













#endif



