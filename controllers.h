
#ifndef CONTROLLER_H
#define CONTROLLER_H

extern float viewport_camera_current_z;

extern float g_janela;

extern GLbyte g_obs_operacao;

extern float viewport_camera_new_x,
			 viewport_camera_new_y,
			 viewport_camera_new_z;
			 
extern float viewport_camera_new_rotation_x,
			 viewport_camera_new_rotation_y,
			 viewport_camera_new_rotation_z;
			 
extern float viewport_camera_current_x,
			 viewport_camera_current_y,
			 viewport_camera_distanceorigin;
			 
extern float viewport_camera_current_rotation_x,
			 viewport_camera_current_rotation_y,
			 viewport_camera_current_rotation_z; 

extern GLint g_mouse_x,
			 g_mouse_y;

// ---------------------------------------- FREEGLUT KEYBOARD CONTROLLER ------------------------------------------ //

void KeyboardController (unsigned char key, int x, int y) {
	switch (key) {
        case 'w':
        case 'W':
        	printf("pressed key w");
            
            break;
        case 's':
        case 'S':
        	printf("pressed key s");
            break;
        case 'r':
        case 'R':
        	printf("pressed key r");
        	g_obs_operacao = 'r';
        	break;
        case 't':
        case 'T':
        	printf("pressed key t");
        	g_obs_operacao = 't';
        	break;
        case 'a':
        case 'A':
        	printf("pressed key a");
        	g_obs_operacao = 'a';
        	break;
    }
}

void gEspeciais (int tecla, int x, int y) {
	glutPostRedisplay ();
}

// ---------------------------------------- FREEGLUT VIEWPORT CAMERA CONTROLLER ----------------------------------- //

void PositionViewportDisplay (void) {
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glTranslatef ( viewport_camera_new_x, viewport_camera_new_y, viewport_camera_new_z );
	glRotatef ( viewport_camera_new_rotation_x, 1, 0, 0 );
	glRotatef ( viewport_camera_new_rotation_y, 0, 1, 0 );
}

void SaveNewViewportRotation(int botao, int x, int y) {
	g_mouse_x = x;
	g_mouse_y = y;
	
	viewport_camera_current_x = viewport_camera_new_x;
	viewport_camera_current_y = viewport_camera_new_y;
	
	viewport_camera_current_rotation_x = viewport_camera_new_rotation_x;
	viewport_camera_current_rotation_y = viewport_camera_new_rotation_y;	
}

void RotateViewportCamera (int x, int y) {
	float sensor = -3;
	
	viewport_camera_new_rotation_x = viewport_camera_current_rotation_x - (((g_mouse_y - y) / sensor) - 417);
	viewport_camera_new_rotation_y = viewport_camera_current_rotation_y - (((g_mouse_x - x) / sensor) - 422);
}

void InitializeViewportDisplay (void) {
	viewport_camera_new_x = 0;
	viewport_camera_new_y = 0;
	viewport_camera_new_z = -g_janela * 3.5;
	
	RotateViewportCamera(726, 513);
	PositionViewportDisplay();
}

// --------------------------------------------- FREEGLUT MOUSE CONTROLLER ------------------------------------------ //

void MouseMovementController (int x, int y) {
	printf("Mouse ( %d ", x );
	printf("| %d ) \n", y);
	
	if (g_obs_operacao == 'r')
		RotateViewportCamera(x, y);
		PositionViewportDisplay();
		glutPostRedisplay ();
}

void MouseScrollController (int botao, int direcao, int x, int y) {
	if (botao == 0) {
        if (direcao == 1) {
            printf("Mouse scrolled up, Value: %d \n", direcao);
			viewport_camera_current_z = viewport_camera_current_z - direcao; // Move camera forward		
        } 
		
		if (direcao == -1) {
        	printf("Mouse scrolled down, Value: %d \n", direcao);
			viewport_camera_new_z = viewport_camera_current_z + direcao; // Move camera backward			
        }
    }
}

void MouseInputController (int botao, int estado, int x, int y) {
	
	switch(botao) {
		glut_mouse_left_button:
			SaveNewViewportRotation(botao, x, y);
			break;
	}
	
	glutPostRedisplay ();
}

#endif
