
#ifndef DRAW_H
#define DRAW_H

// ---------------------------------------- FREEGLUT INICIALIZA��O DE DESENHOS ------------------------------------- //

void GraphicsObjectsRender(void) {
	// OFFSET X / Y / Z
	BasicObjectsDraw(0,20,0);
	BobEsponjaScriptDraw(0,0,0);
}

void Draw() {									
	glEnable (GL_DEPTH_TEST); 										// habilitando buffer de profundidade
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 			// Inicializa��o
	glMatrixMode (GL_MODELVIEW); 									// Muda p/ o sistema de coord. do modelo
	glPushMatrix ();
	
	InitializeGridXY();												// INICIALIZA O GRID DE VISUALIZA��O DO OPERADOR E O GIZMO DE AJUDA VISUAL
	GraphicsObjectsRender();
	
	glPopMatrix ();
	
	glutSwapBuffers (); 											// ATUALIZAR O BUFFER
    PositionViewportDisplay();
}

#endif
