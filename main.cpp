
#ifndef MAIN_H
#define MAIN_H

#include <freeglut.h>
#include <stdio.h>
#include <glut.h>
#include <math.h>
#include "./grid.h"
#include "./basicObjects.h"
#include "./bobSponge.h"
#include "./controllers.h"
#include "./drawCall.h"
#include "./tickCall.h"
#include "./systemidle.h"

GLfloat g_janela = 10; 								 	// tamanho da janela em pontos
GLfloat CameraFieldOfView = 999; 						// Abertura da janela que o �ngulo permite visualizar
GLfloat CameraNearClipping = (g_janela / 10);				// Dist�ncia do Obs. p/ o plano de recorte pr�ximo
GLfloat CameraFarClipping = 10 * g_janela;   			// Dist�ncia do Obs. p/ o plano de recorte distante (>proximo)

GLbyte g_obs_operacao; 									// 'r'otacao | 't'ranslacao | 'a'prox./afastamento | 'n'ula

// posi��o inicial do Obs. em cada eixo antes das movimenta��o
GLfloat viewport_camera_current_x,
		viewport_camera_current_y,
		viewport_camera_current_z; 			

// posi��o final do Obs. em cada eixo depois das movimenta��o
GLfloat viewport_camera_new_x,
		viewport_camera_new_y,
		viewport_camera_new_z; 	
				
// posi��o inicial antes da rota��o
GLfloat viewport_camera_current_rotation_x,
		viewport_camera_current_rotation_y; 
			
// posi��o final ap�s rota��o
GLfloat viewport_camera_new_rotation_x,
		viewport_camera_new_rotation_y; 
		
GLint g_mouse_x,
	  g_mouse_y;	
	  
int g_idle = 0,
	g_timer = 0,
	g_timer_value = 10,
	screenWidth,
	screenHeigth,
	worldSizeX = 999,
	worldSizeY = 999,
	worldSizeZ = 999,
	worldScaleX = 1,
	worldScaleY = 1, 
	worldScaleZ = 1;
	
int glut_mouse_left_button;

void InicializarVariaveis() {
	screenWidth = glutGet(GLUT_SCREEN_WIDTH); 
	screenHeigth = glutGet(GLUT_SCREEN_HEIGHT);
	glut_mouse_left_button = glutGet(GLUT_SCREEN_WIDTH);   
}

// ---------------------------------------- FREEGLUT ENGINE EVENTS ------------------------------------------------ //

void AsScreenHasChanged ( GLsizei largura, GLsizei altura ) {  
																								
	if (altura == 0) altura = 1;																// a��es quando do redimensionamento da janela
	float aspecto;
	if (largura <= altura) aspecto = altura / largura;
	else aspecto = largura / altura;
	
	glMatrixMode (GL_PROJECTION); 																// Inicializa��o do sistemas de coordenadas	
	glLoadIdentity();
	glViewport (0, 0, largura, altura);
	
	//gluOrtho2D (-g_janela, g_janela, -g_janela, g_janela);
	
	gluPerspective (CameraFieldOfView, aspecto, CameraNearClipping, CameraFarClipping);
	PositionViewportDisplay();
}

// -------------------------------------------- FREEGLUT INICIALIZA��O DE CEN�RIO ---------------------------------- //

void InitializeScene() {
	glClear(GL_COLOR_BUFFER_BIT); //  COR DE FUNDO DA JANELA
	glMatrixMode (GL_MODELVIEW); // Inicializa��o do sistemas de coordenadas
	glLoadIdentity();
	
	InitializeViewportDisplay(); 
	 
	glFlush(); 
}

// ------------------------------------------------ FREEGUT INICIALIZA��O ---------------------------------------------- //
  
int main (int argc, char *argv[]) {	    
											
	glutInit (&argc, argv); 												// INICIALIZA��O DO FREEGLUT
	InicializarVariaveis();													// INICIALIZA VARI�VEIS PARA CONTROLE
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);				// Buffer pra constru��o Imagem | Par. para Remo��o de Superf. Escondidas | Sistema Cor

	glutInitWindowPosition(screenWidth * 0.20, screenHeigth * 0.20);		// Posi��o canto superior esquerdo da janela (x, y)
	glutInitWindowSize(screenWidth * 0.60, screenHeigth * 0.60);			// Inicializa janela e attribui tamanho
	glutCreateWindow("Projeto Bob Esponja");									// Cria janela de atribui nome
	
	// OPERA��ES DE BACKGROUND
	glutDisplayFunc(Draw); 													// Desenhar objetos gr�ficos

	// CONTROLLERS
	glutSpecialFunc(gEspeciais); 											// Tratamento das teclas especiais
	glutMouseFunc(MouseInputController); 									// CONTROLE DE COMPORTAMENTOS DE CLICK DO MOUSE
	glutMouseWheelFunc(MouseScrollController);								// CONTROLE DO MOUSE SCROLL
	glutMotionFunc(MouseMovementController);								// CONTROLE DO MOUSE X e Y
	glutKeyboardFunc(KeyboardController); 									// Tratamento das teclas comuns
	

	glutIdleFunc(AsSystemIdles); 					
	glutTimerFunc(0, AsTickEvent, 0);
	
	// EVENTS
	glutReshapeFunc(AsScreenHasChanged); 									// Controle do redimensionamento da janela
	
	InitializeScene();
	glutMainLoop();
	
	return 0;
}

#endif


