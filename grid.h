
extern int worldSizeY,
			worldSizeX,
			worldSizeZ,
			worldScaleX,
			worldScaleY,
			worldScaleZ;

void InitializeGridXY() {
	
	// -------- DRAW GRID -------- //
	
	// DRAW GRID PARTS FOR THE X AXIS
	glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINES);
	    for (int i = -worldSizeY; i <= worldSizeX; ++i) {
	        glVertex2f(i, -100);
	        glVertex2f(i, 100);
	    }
    glEnd();

    // DRAW GRID PARTS FOR THE Y AXIS
    glBegin(GL_LINES);
	    for (int i = -worldSizeX; i <= worldSizeY; ++i) {
	        glVertex2f(-100, i);
	        glVertex2f(100, i);
	    }
    glEnd();
    
    // ---------- DRAW GIZMO --------- //
    
    // PAINT X COLUMN
    glColor3f(0.96f, 0.13f, 0.04f); 
    glBegin(GL_LINES);
	    for (int i = 0; i <= worldSizeX; ++i) {
			glVertex3f(i, 0, 0.1);
		    glVertex3f(i + worldScaleX, 0, 0.1);
		}
    glEnd();
    
    // PAINT Y COLUMN
    glColor3f(0.37f, 0.96f, 0.25f); 
    glBegin(GL_LINES);
	    for (int i = 0; i <= worldSizeY; ++i) {
		    glVertex3f(0, i, 0.1);
		    glVertex3f(0, i + worldScaleY, 0.1);
		}
    glEnd();
    
    // PAINT Z COLUMN
    glColor3f(0.04f, 0.25f, 0.96f); 
    glBegin(GL_LINES);
	    for (int i = 0; i <= worldSizeY; ++i) {
		    glVertex3f(0, 0, i);
		    glVertex3f(0, 0, i + worldScaleZ);
		}
    glEnd();
    
    return;
}
