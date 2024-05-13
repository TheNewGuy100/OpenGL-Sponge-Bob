

#ifndef TICKCALL_H
#define TICKCALL_H

void AsTickEvent (int valor) {

	
	AnimateSpongeBobArm();
	
	
	
	glutPostRedisplay();
	glutTimerFunc(16, AsTickEvent, 0); // 16ms ˜ 60fps
}

#endif
