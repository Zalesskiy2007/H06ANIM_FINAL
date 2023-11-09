/* FILE NAME   : main.cpp
 * PROGRAMMER  : MZ2
 * LAST UPDATE : 01.09.2023
 * PURPOSE     : Animation 3D render with OpenGL project.
 *               Main project file.
 */

#include "mzgl.h"
#include <thread>

 /* The main program function.
  * ARGUMENTS:
  *   - handle of application instance:
  *       HINSTANCE hInstance;
  *   - dummy handle of previous application instance (not used):
  *       HINSTANCE hPrevInstance;
  *   - command line string:
  *       CHAR *CmdLine;
  *   - show window command parameter (see SW_***):
  *       INT CmdShow;
  * RETURNS:
  *   (INT) Error level for operation system (0 for success).
  */
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
  CHAR* CmdLine, INT ShowCmd)
{                                        
  SetDbgMemHooks();

  std::thread Second([hInstance](VOID)
      {
          mzgl::anim My1(hInstance);
          My1.CreateWin();
          My1 << "Skybox unit";
          My1 << "Control unit";
          My1 << "Model unit";
          My1 << "Floor unit";
          My1.Run();
      });

  mzgl::anim MyAnim(hInstance);
  MyAnim.CreateWin();

  MyAnim << "Skybox unit";
  MyAnim << "Control unit"; 
  MyAnim << "Test unit";
  MyAnim << "Floor unit";

  MyAnim.Run();

  Second.join();
} /* End of 'WinMain' function */

/* END OF 'main.cpp' FILE */